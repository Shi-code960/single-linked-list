#include "student.h"

void stud_mod(void)
{
    struct student *temp;
    char choice, name[50];
    int roll, found = 0, selected_roll;
    float percentage;

    if(head == NULL)
    {
        printf("Student list is empty!\n");
        return;
    }

    printf("\nEnter which record to search for modification\n");
    printf("R/r : Search by roll number\n");
    printf("N/n : Search by name\n");
    printf("P/p : Search by percentage\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);

    /* Search by roll number */
    if(choice == 'R' || choice == 'r')
    {
        printf("Enter roll number: ");
        scanf("%d", &roll);

        temp = head;

        while(temp != NULL)
        {
            if(temp->rollno == roll)
            {
                found = 1;
                break;
            }
            temp = temp->next;
        }

        if(found == 0)
        {
            printf("Roll number not found!\n");
            return;
        }
    }

    /* Search by name */
    else if(choice == 'N' || choice == 'n')
    {
        printf("Enter student name: ");
        scanf(" %49[^\n]", name);

        temp = head;

        printf("\nMatching records:\n");
        printf("------------------------------------------\n");
        printf("Roll No.\tName\t\tPercentage\n");
        printf("------------------------------------------\n");

        while(temp != NULL)
        {
            if(strcmp(temp->name, name) == 0)
            {
                printf("%d\t\t%s\t\t%.2f\n",
                       temp->rollno, temp->name, temp->percentage);
                found = 1;
            }
            temp = temp->next;
        }

        if(found == 0)
        {
            printf("Name not found!\n");
            return;
        }

        printf("\nEnter roll number of the record to modify: ");
        scanf("%d", &selected_roll);

        temp = head;
        found = 0;

        while(temp != NULL)
        {
            if(temp->rollno == selected_roll &&
               strcmp(temp->name, name) == 0)
            {
                found = 1;
                break;
            }
            temp = temp->next;
        }

        if(found == 0)
        {
            printf("Invalid roll number selection!\n");
            return;
        }
    }

    /* Search by percentage */
    else if(choice == 'P' || choice == 'p')
    {
        printf("Enter percentage: ");
        scanf("%f", &percentage);

        temp = head;

        printf("\nMatching records:\n");
        printf("------------------------------------------\n");
        printf("Roll No.\tName\t\tPercentage\n");
        printf("------------------------------------------\n");

        while(temp != NULL)
        {
            if(temp->percentage >= percentage - 0.001 &&
               temp->percentage <= percentage + 0.001)
            {
                printf("%d\t\t%s\t\t%.2f\n",
                       temp->rollno, temp->name, temp->percentage);
                found = 1;
            }
            temp = temp->next;
        }

        if(found == 0)
        {
            printf("Percentage not found!\n");
            return;
        }

        printf("\nEnter roll number of the record to modify: ");
        scanf("%d", &selected_roll);

        temp = head;
        found = 0;

        while(temp != NULL)
        {
            if(temp->rollno == selected_roll &&
               temp->percentage >= percentage - 0.001 &&
               temp->percentage <= percentage + 0.001)
            {
                found = 1;
                break;
            }
            temp = temp->next;
        }

        if(found == 0)
        {
            printf("Invalid roll number selection!\n");
            return;
        }
    }

    else
    {
        printf("Invalid choice!\n");
        return;
    }

    /* Display current record and modify */
    printf("\nCurrent student details:\n");
    printf("Roll number : %d\n", temp->rollno);
    printf("Name        : %s\n", temp->name);
    printf("Percentage  : %.2f\n", temp->percentage);

    printf("\nEnter updated name: ");
    scanf(" %49[^\n]", temp->name);

    printf("Enter updated percentage: ");
    scanf("%f", &temp->percentage);

    printf("\nRecord modified successfully!\n");
}

