#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "project_header.c"

int main()
{

    Patient *queue = NULL;
    Patient *queue1 = NULL;

    struct Department departments[8];

    // Initialize the departments
    strcpy(departments[0].name, "Orthopedic");
    departments[0].size = 0;

    strcpy(departments[1].name, "General Medicine");
    departments[1].size = 0;

    strcpy(departments[2].name, "General Surgery");
    departments[2].size = 0;

    strcpy(departments[3].name, "Radiology");
    departments[3].size = 0;

    strcpy(departments[4].name, "Nephrology");
    departments[4].size = 0;

    strcpy(departments[5].name, "Cardiology");
    departments[5].size = 0;

    strcpy(departments[6].name, "Urology");
    departments[6].size = 0;

    strcpy(departments[7].name, "Ophthalmology");
    departments[7].size = 0;

    // Insert doctors into the departments
    insertDoctor(&departments[7], (struct Doctor){"Dr. John Smith", 5});
    insertDoctor(&departments[7], (struct Doctor){"Dr. Sarah Johnson", 3});
    insertDoctor(&departments[7], (struct Doctor){"Dr. Michael Brown", 7});
    insertDoctor(&departments[7], (struct Doctor){"Dr. Emily Davis", 10});
    insertDoctor(&departments[7], (struct Doctor){"Dr. David Wilson", 1});
    insertDoctor(&departments[7], (struct Doctor){"Dr. Jessica Anderson", 4});
    insertDoctor(&departments[7], (struct Doctor){"Dr. Christopher Thompson", 6});
    insertDoctor(&departments[7], (struct Doctor){"Dr. Olivia Martinez", 3});
    insertDoctor(&departments[7], (struct Doctor){"Dr. Matthew Taylor", 5});
    insertDoctor(&departments[7], (struct Doctor){"Dr. Sophia Lee", 3});

    insertDoctor(&departments[0], (struct Doctor){"Dr. John Smith", 5});
    insertDoctor(&departments[0], (struct Doctor){"Dr. Sarah Johnson", 3});
    insertDoctor(&departments[0], (struct Doctor){"Dr. Michael Brown", 7});
    insertDoctor(&departments[0], (struct Doctor){"Dr. Emily Davis", 10});
    insertDoctor(&departments[0], (struct Doctor){"Dr. David Wilson", 1});
    insertDoctor(&departments[0], (struct Doctor){"Dr. Jessica Anderson", 4});
    insertDoctor(&departments[0], (struct Doctor){"Dr. Christopher Thompson", 6});
    insertDoctor(&departments[0], (struct Doctor){"Dr. Olivia Martinez", 3});
    insertDoctor(&departments[0], (struct Doctor){"Dr. Matthew Taylor", 5});
    insertDoctor(&departments[0], (struct Doctor){"Dr. Sophia Lee", 3});

    insertDoctor(&departments[1], (struct Doctor){"Dr. Rajesh Gupta", 10});
    insertDoctor(&departments[1], (struct Doctor){"Dr. Shalini Patel", 7});
    insertDoctor(&departments[1], (struct Doctor){"Dr. Sanjay Sharma", 1});
    insertDoctor(&departments[1], (struct Doctor){"Dr. Neha Kapoor", 5});
    insertDoctor(&departments[1], (struct Doctor){"Dr. Ravi Verma", 10});
    insertDoctor(&departments[1], (struct Doctor){"Dr. Sunita Singh", 2});
    insertDoctor(&departments[1], (struct Doctor){"Dr. Vikram Shah", 11});
    insertDoctor(&departments[1], (struct Doctor){"Dr. Pooja Reddy", 7});
    insertDoctor(&departments[1], (struct Doctor){"Dr. Ajay Kumar", 4});
    insertDoctor(&departments[1], (struct Doctor){"Dr. Rekha Desai", 6});

    insertDoctor(&departments[2], (struct Doctor){"Dr. Rajesh Kuma", 15});
    insertDoctor(&departments[2], (struct Doctor){"Dr. Priya Gupta", 9});
    insertDoctor(&departments[2], (struct Doctor){"Dr. Sanjay Sharma", 1});
    insertDoctor(&departments[2], (struct Doctor){"Dr. Nisha Patel", 8});
    insertDoctor(&departments[2], (struct Doctor){"Dr. Ravi Verma", 2});
    insertDoctor(&departments[2], (struct Doctor){"Dr. Pooja Singh", 5});
    insertDoctor(&departments[2], (struct Doctor){"Dr. Manish Joshi", 4});
    insertDoctor(&departments[2], (struct Doctor){"Dr. Neha Kapoor", 3});
    insertDoctor(&departments[2], (struct Doctor){"Dr. Anil Patel", 11});
    insertDoctor(&departments[2], (struct Doctor){"Dr. Meera Sharma", 9});

    insertDoctor(&departments[3], (struct Doctor){"Dr. Ajay Gupta", 4});
    insertDoctor(&departments[3], (struct Doctor){"Dr. Smita Desai", 6});
    insertDoctor(&departments[3], (struct Doctor){"Dr. Sunil Chawla", 9});
    insertDoctor(&departments[3], (struct Doctor){"Dr. Sneha Verma", 10});
    insertDoctor(&departments[3], (struct Doctor){"Dr. Deepak Singh", 6});
    insertDoctor(&departments[3], (struct Doctor){"Dr. Reena Sharma", 3});
    insertDoctor(&departments[3], (struct Doctor){"Dr. Anuj Shah", 1});
    insertDoctor(&departments[3], (struct Doctor){"Dr. Sunita Reddy", 2});
    insertDoctor(&departments[3], (struct Doctor){"Dr. Sameer Jain", 5});
    insertDoctor(&departments[3], (struct Doctor){"Dr. Aarti Khanna", 3});

    insertDoctor(&departments[4], (struct Doctor){"Dr. Prakash Mehta", 10});
    insertDoctor(&departments[4], (struct Doctor){"Dr. Swati Patel", 3});
    insertDoctor(&departments[4], (struct Doctor){"Dr. Karan Gupta", 8});
    insertDoctor(&departments[4], (struct Doctor){"Dr. Naina Singh", 3});
    insertDoctor(&departments[4], (struct Doctor){"Dr. Vikram Kapoor", 9});
    insertDoctor(&departments[4], (struct Doctor){"Dr. Shilpa Deshmukh", 7});
    insertDoctor(&departments[4], (struct Doctor){"Dr. Harish Reddy", 1});
    insertDoctor(&departments[4], (struct Doctor){"Dr. Juhi Shah", 2});

    insertDoctor(&departments[5], (struct Doctor){"Dr. Anand Kumar", 6});
    insertDoctor(&departments[5], (struct Doctor){"Dr. Ritu Choudhary", 3});
    insertDoctor(&departments[5], (struct Doctor){"Dr. Rohit Kapoor", 9});
    insertDoctor(&departments[5], (struct Doctor){"Dr. Puja Sharma", 8});
    insertDoctor(&departments[5], (struct Doctor){"Dr. Arjun Patel", 4});
    insertDoctor(&departments[5], (struct Doctor){"Dr. Roshni Gupta", 2});
    insertDoctor(&departments[5], (struct Doctor){"Dr. Rakesh Verma", 1});
    insertDoctor(&departments[5], (struct Doctor){"Dr. Alisha Singh", 7});

    insertDoctor(&departments[6], (struct Doctor){"Dr. Vinay Shah", 5});
    insertDoctor(&departments[6], (struct Doctor){"Dr. Nisha Mathur", 3});
    insertDoctor(&departments[6], (struct Doctor){"Dr. Prashant Sharma", 4});
    insertDoctor(&departments[6], (struct Doctor){"Dr. Geeta Mishra", 10});
    insertDoctor(&departments[6], (struct Doctor){"Dr. Rajeev Kumar", 11});
    insertDoctor(&departments[6], (struct Doctor){"Dr. Seema Sharma", 2});
    insertDoctor(&departments[6], (struct Doctor){"Dr. Vikas Patel", 1});
    insertDoctor(&departments[6], (struct Doctor){"Dr. Divya Singh", 4});

    int departmentIndex;
    if (departmentIndex < 0 || departmentIndex >= 8)
    {
        printf("Invalid department index.\n");
        return 0;
    }
   int g;
    printf("Do you want to see list of doctors in the hospital  ?\nPress 1 for yes\nPress 2 for no ");
    scanf("%d", &g);
    printf("\n");

    if (g == 1)
    {
        printf("Enter the department index (0-8) to to view doctors in a department: ");
        printf("\n");
        printf("Orthopedic - 0\nGeneral Medicine - 1\nGeneral Surgery - 2\nRadiology - 3\nNephrology - 4\nCardiology - 5\nUrologyc - 6\nOpthomolgy - 8\nall -8\n");
        printf("\n");
        printf("Enter your response: ");
        printf("\n");
        scanf("%d", &departmentIndex);
        if (departmentIndex < 8)
        {
            displayDepartment(&departments[departmentIndex]);
        }
        else if (departmentIndex == 8)
        {
            for (int i = 0; i < 8; i++)
            {
                displayDepartment(&departments[i]);
                printf("\n");
            }
        }
        else
        {
            printf("Invalid department index.\n");
            return 0;
        }
    }
    
    else{
        printf("please provide a valid input :");
    }
    

        FILE *file;
        file = fopen("Patients.csv", "r");
        if (file == NULL)
        {
            printf("Error opening file.\n");
            return 1;
        }

        char line[200];
        while (fgets(line, sizeof(line), file))
        {

            char name[100];
            int priority;
            char category[100];
            char gender[100];
            int age;
            struct patient *next;

            char *token = strtok(line, ",");

            char *arr[500];
            int j = 0;
            while (token != NULL)
            {
                arr[j] = token;
                // printf(" %s\n", token);
                token = strtok(NULL, ",");
                j++;
            }

            strcpy(name, arr[0]);
            priority = atoi(arr[4]);
            strcpy(gender, arr[2]);
            strcpy(category, arr[3]);
            age = atoi(arr[1]);

            enqueue(&queue, name, priority, category, gender, age);
            enqueue(&queue1, name, priority, category, gender, age);
        }
        // queue1 = queue;
        fclose(file);
        printf("\n");
        int c;
        printf("do you want to see all patients in priority queue?\nPress 1 for Yes \nPress 2 for No");
        scanf("%d", &c);
        if (c == 1)
        {
            displayQueue(queue);
        }
        else
        {
            printf("please provide valid input!!");
        }

        fclose(file);
    

    printf("\n");

    Patient *dequeuedPatient;
    Patient *dequeuedPatient1;
    struct Doctor deletedDoctor;
    struct Doctor deletedDoctor1;
    struct Doctor deletedDoctor2;
    struct Doctor deletedDoctor3;
    struct Doctor deletedDoctor4;
    struct Doctor deletedDoctor5;
    struct Doctor deletedDoctor6;
    struct Doctor deletedDoctor7;

    int u;
    int b = 0;
    printf("Enter the number of patient once handled by the program :");
    scanf("%d", &u);
    printf("\n");
    printf("Here is the list of patients,topmost patient has highest priority");

    printf("\n");
    for (int p = u; p > 0; p--)
    {
        dequeuedPatient1 = dequeue(&queue1);
        printf("priority patient: %s\tGender :%s\tAge : %d\t Department :  %s\t Priority number :%d\n", dequeuedPatient1->name, dequeuedPatient1->gender, dequeuedPatient1->age, dequeuedPatient1->category, dequeuedPatient1->priority);
    }
    printf("\n");

    int k;
    printf("do you want assign most experience doctor avialable in the department \nhighest priority patient?\nPress 1 for Yes \nPress 2 for No");
    scanf("%d", &k);
    printf("\n");
    if (k == 1)
    {
        for (int p = u; p > 0; p--)
        {
            dequeuedPatient = dequeue(&queue);

            if ((strcmp(departments[0].name, dequeuedPatient->category)) == 0)
            {
                departmentIndex = 0;
                deletedDoctor = deleteDoctor(&departments[departmentIndex]);
                printf("priority patient: %s\tGender :%s\tAge : %d\t Department :  %s\t Priority number :%d\n", dequeuedPatient->name, dequeuedPatient->gender, dequeuedPatient->age, dequeuedPatient->category, dequeuedPatient->priority);

                printf("Choosing doctor with highest prioirty in the hospiatl at agive instance:");
                printf("\n");
                printf("Seleted Doctor - Name: %s, Department: %s, Experience: %d\n",
                       deletedDoctor.name, departments[departmentIndex].name, deletedDoctor.experience);

                printf("\n");
                printf("\n");
            }
            if ((strcmp(departments[1].name, dequeuedPatient->category)) == 0)
            {
                departmentIndex = 1;
                deletedDoctor1 = deleteDoctor(&departments[departmentIndex]);
                printf("priority patient: %s\tGender :%s\tAge : %d\t Department :  %s\t Priority number :%d\n", dequeuedPatient->name, dequeuedPatient->gender, dequeuedPatient->age, dequeuedPatient->category, dequeuedPatient->priority);

                printf("Choosing doctor with highest prioirty in the hospiatl at agive instance:");
                printf("\n");
                printf("Seleted Doctor - Name: %s, Department: %s, Experience: %d\n",
                       deletedDoctor1.name, departments[departmentIndex].name, deletedDoctor1.experience);

                printf("\n");
                printf("\n");
            }
            else if ((strcmp(departments[2].name, dequeuedPatient->category)) == 0)
            {
                departmentIndex = 2;
                deletedDoctor2 = deleteDoctor(&departments[departmentIndex]);
                printf("priority patient: %s\tGender :%s\tAge : %d\t Department :  %s\t Priority number :%d\n", dequeuedPatient->name, dequeuedPatient->gender, dequeuedPatient->age, dequeuedPatient->category, dequeuedPatient->priority);

                printf("Choosing doctor with highest prioirty in the hospiatl at agive instance:");
                printf("\n");
                printf("Seleted Doctor - Name: %s, Department: %s, Experience: %d\n",
                       deletedDoctor2.name, departments[departmentIndex].name, deletedDoctor2.experience);

                printf("\n");
                printf("\n");
            }
            else if ((strcmp(departments[3].name, dequeuedPatient->category)) == 0)
            {
                departmentIndex = 3;
                deletedDoctor3 = deleteDoctor(&departments[departmentIndex]);
                printf("priority patient: %s\tGender :%s\tAge : %d\t Department :  %s\t Priority number :%d\n", dequeuedPatient->name, dequeuedPatient->gender, dequeuedPatient->age, dequeuedPatient->category, dequeuedPatient->priority);

                printf("Choosing doctor with highest prioirty in the hospiatl at agive instance:");
                printf("\n");
                printf("Seleted Doctor - Name: %s, Department: %s, Experience: %d\n",
                       deletedDoctor3.name, departments[departmentIndex].name, deletedDoctor3.experience);

                printf("\n");
                printf("\n");
            }
            else if ((strcmp(departments[4].name, dequeuedPatient->category)) == 0)
            {
                departmentIndex = 4;
                deletedDoctor4 = deleteDoctor(&departments[departmentIndex]);
                printf("priority patient: %s\tGender :%s\tAge : %d\t Department :  %s\t Priority number :%d\n", dequeuedPatient->name, dequeuedPatient->gender, dequeuedPatient->age, dequeuedPatient->category, dequeuedPatient->priority);

                printf("Choosing doctor with highest prioirty in the hospiatl at agive instance:");
                printf("\n");
                printf("Seleted Doctor - Name: %s, Department: %s, Experience: %d\n",
                       deletedDoctor4.name, departments[departmentIndex].name, deletedDoctor4.experience);

                printf("\n");
                printf("\n");
            }
            else if ((strcmp(departments[5].name, dequeuedPatient->category)) == 0)
            {
                departmentIndex = 5;
                deletedDoctor5 = deleteDoctor(&departments[departmentIndex]);
                printf("priority patient: %s\tGender :%s\tAge : %d\t Department :  %s\t Priority number :%d\n", dequeuedPatient->name, dequeuedPatient->gender, dequeuedPatient->age, dequeuedPatient->category, dequeuedPatient->priority);

                printf("Choosing doctor with highest prioirty in the hospiatl at agive instance:");
                printf("\n");
                printf("Seleted Doctor - Name: %s, Department: %s, Experience: %d\n",
                       deletedDoctor5.name, departments[departmentIndex].name, deletedDoctor5.experience);

                printf("\n");
                printf("\n");
            }
            else if ((strcmp(departments[6].name, dequeuedPatient->category)) == 0)
            {

                departmentIndex = 6;
                deletedDoctor6 = deleteDoctor(&departments[departmentIndex]);
                printf("priority patient: %s\tGender :%s\tAge : %d\t Department :  %s\t Priority number :%d\n", dequeuedPatient->name, dequeuedPatient->gender, dequeuedPatient->age, dequeuedPatient->category, dequeuedPatient->priority);

                printf("Choosing doctor with highest prioirty in the hospiatl at agive instance:");
                printf("\n");
                printf("Seleted Doctor - Name: %s, Department: %s, Experience: %d\n",
                       deletedDoctor6.name, departments[departmentIndex].name, deletedDoctor6.experience);

                printf("\n");
                printf("\n");
            }
            else if ((strcmp(departments[7].name, dequeuedPatient->category)) == 0)
            {
                departmentIndex = 7;
                deletedDoctor6 = deleteDoctor(&departments[departmentIndex]);
                printf("priority patient: %s\tGender :%s\tAge : %d\t Department :  %s\t Priority number :%d\n", dequeuedPatient->name, dequeuedPatient->gender, dequeuedPatient->age, dequeuedPatient->category, dequeuedPatient->priority);

                printf("Choosing doctor with highest prioirty in the hospiatl at agive instance:");
                printf("\n");
                printf("Seleted Doctor - Name: %s, Department: %s, Experience: %d\n",
                       deletedDoctor7.name, departments[departmentIndex].name, deletedDoctor7.experience);

                printf("\n");
                printf("\n");
            }

            else
            {
                // 2  printf("patient not found");
            }
        }
    }
    else
    {
        printf("please provide a valid input!");
    }

    return 0;
}
