#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <gtk/gtk.h>

#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char gender;
    int age;
    int priority;
} Patient;

typedef struct {
    Patient patient;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

bool isQueueEmpty(Queue* queue) {
    return (queue->front == NULL);
}

void enqueue(Queue* queue, Patient patient) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->patient = patient;
    newNode->next = NULL;

    if (isQueueEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

Patient dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        Patient emptyPatient;
        strcpy(emptyPatient.name, "Empty");
        emptyPatient.gender = ' ';
        emptyPatient.age = 0;
        emptyPatient.priority = 0;
        return emptyPatient;
    }

    Node* temp = queue->front;
    Patient dequeuedPatient = temp->patient;
    queue->front = queue->front->next;

    if (queue->front == NULL)
        queue->rear = NULL;

    free(temp);
    return dequeuedPatient;
}

void displayPatientDetails(Patient patient) {
    printf("Name: %s\n", patient.name);
    printf("Gender: %c\n", patient.gender);
    printf("Age: %d\n", patient.age);
    printf("Priority: %d\n", patient.priority);
    printf("-----------------------------\n");
}

void displayQueue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    Node* current = queue->front;
    while (current != NULL) {
        displayPatientDetails(current->patient);
        current = current->next;
    }
}

// Callback function for the "Add Patient" button
void on_add_button_clicked(GtkButton* button, GtkEntry* name_entry, GtkEntry* gender_entry,
                           GtkSpinButton* age_spin, GtkSpinButton* priority_spin, GtkTextView* text_view) {
    const gchar* name = gtk_entry_get_text(name_entry);
    gchar gender = gtk_entry_get_text(gender_entry)[0];
    gint age = gtk_spin_button_get_value_as_int(age_spin);
    gint priority = gtk_spin_button_get_value_as_int(priority_spin);

    // Create a new patient
    Patient newPatient;
    strcpy(newPatient.name, name);
    newPatient.gender = gender;
    newPatient.age = age;
    newPatient.priority = priority;

    // Add the patient to the appropriate queue
    switch (newPatient.priority) {
        case 1:
            enqueue(icuQueue, newPatient);
            break;
        case 2:
            enqueue(semiIcuQueue, newPatient);
            break;
        case 3:
            enqueue(generalWardQueue, newPatient);
            break;
        default:
            g_print("Invalid priority level.\n");
            return;
    }

    // Display the updated queues in the text view
    GtkTextBuffer* buffer = gtk_text_view_get_buffer(text_view);
    gtk_text_buffer_set_text(buffer, "", -1);  // Clear the text view

    GtkTextIter iter;
    GtkTextMark* mark = gtk_text_buffer_get_insert(buffer);
    gtk_text_buffer_get_iter_at_mark(buffer, &iter, mark);

    // Display ICU Queue
    gtk_text_buffer_insert(buffer, &iter, "ICU Queue:\n", -1);
    displayQueue(icuQueue, buffer, &iter);

    // Display Semi ICU Queue
    gtk_text_buffer_insert(buffer, &iter, "\nSemi ICU Queue:\n", -1);
    displayQueue(semiIcuQueue, buffer, &iter);

    // Display General Ward Queue
    gtk_text_buffer_insert(buffer, &iter, "\nGeneral Ward Queue:\n", -1);
    displayQueue(generalWardQueue, buffer, &iter);
}

// Display the patient details in the text view
void displayQueue(Queue* queue, GtkTextBuffer* buffer, GtkTextIter* iter) {
    if (isQueueEmpty(queue)) {
        gtk_text_buffer_insert(buffer, iter, "Queue is empty.\n", -1);
        return;
    }

    Node* current = queue->front;
    while (current != NULL) {
        gchar* patientDetails = g_strdup_printf("Name: %s\nGender: %c\nAge: %d\nPriority: %d\n\n",
                                                current->patient.name, current->patient.gender,
                                                current->patient.age, current->patient.priority);
        gtk_text_buffer_insert(buffer, iter, patientDetails, -1);
        g_free(patientDetails);

        current = current->next;
    }
}

int main(int argc, char** argv) {
    // Initialize GTK
    gtk_init(&argc, &argv);

    // Create the main window
    GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Patient Bed Assignment");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    // Create a vertical box container
    GtkWidget* vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Create input fields for patient details
    GtkWidget* name_label = gtk_label_new("Name:");
    GtkWidget* name_entry = gtk_entry_new();
    GtkWidget* gender_label = gtk_label_new("Gender (M/F):");
    GtkWidget* gender_entry = gtk_entry_new();
    GtkWidget* age_label = gtk_label_new("Age:");
    GtkWidget* age_spin = gtk_spin_button_new_with_range(0, 150, 1);
    GtkWidget* priority_label = gtk_label_new("Priority (1-3, 1 being high):");
    GtkWidget* priority_spin = gtk_spin_button_new_with_range(1, 3, 1);

    // Create the "Add Patient" button
    GtkWidget* add_button = gtk_button_new_with_label("Add Patient");
    g_signal_connect(G_OBJECT(add_button), "clicked", G_CALLBACK(on_add_button_clicked),
                     name_entry, gender_entry, age_spin, priority_spin, text_view);

    // Create a text view to display the patient queues
    GtkWidget* text_view = gtk_text_view_new();
    gtk_text_view_set_editable(GTK_TEXT_VIEW(text_view), FALSE);
    gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(text_view), FALSE);

    // Create a scrollable window for the text view
    GtkWidget* scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(scrolled_window), text_view);

    // Add the widgets to the vertical box container
    gtk_box_pack_start(GTK_BOX(vbox), name_label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), name_entry, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), gender_label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), gender_entry, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), age_label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), age_spin, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), priority_label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), priority_spin, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), add_button, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), scrolled_window, TRUE, TRUE, 0);

    // Show all the widgets
    gtk_widget_show_all(window);

    // Run the GTK main loop
    gtk_main();

    return 0;
}

