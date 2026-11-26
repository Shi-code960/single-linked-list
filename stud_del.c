#include "student.h"

void stud_del(void)
{
    struct student *temp, *prev;
    char choice, name[50];
    int roll, found = 0, selected_roll;

    if(head == NULL)
    {
        printf("Student list is empty!\n");
        return;
    }

    printf("\nR/r : Enter roll number to delete\n");
    printf("N/n : Enter name to delete\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);

    /* Delete by roll number */
    if(choice == 'R' || choice == 'r')
    {
        printf("Enter roll number to delete: ");
        scanf("%d", &roll);

        temp = head;
        prev = NULL;

        while(temp != NULL && temp->rollno != roll)
        {
            prev = temp;
            temp = temp->next;
        }

        if(temp == NULL)
        {
            printf("Roll number %d not found!\n", roll);
            return;
        }

        /* Unlink the node */
        if(prev == NULL)
        {
            head = temp->next;
        }
        else
        {
            prev->next = temp->next;
        }

        free(temp);

        printf("Record deleted successfully!\n");
    }

    /* Delete by name */
    else if(choice == 'N' || choice == 'n')
    {
        printf("Enter student name to delete: ");
        scanf(" %49[^\n]", name);

        temp = head;

        printf("\nMatching records:\n");
        printf("-----------------------------------\n");
        printf("Roll No\tName\n");
        printf("-----------------------------------\n");

        /* Display all matching names */
        while(temp != NULL)
        {
            if(strcmp(temp->name, name) == 0)
            {
                printf("%d\t%s\n", temp->rollno, temp->name);
                found = 1;
            }

            temp = temp->next;
        }

        if(found == 0)
        {
            printf("Name not found!\n");
            return;
        }

        /* Select roll number for deletion */
        printf("\nEnter roll number to delete: ");
        scanf("%d", &selected_roll);

        temp = head;
        prev = NULL;

        /* Search selected roll number */
        while(temp != NULL && temp->rollno != selected_roll)
        {
            prev = temp;
            temp = temp->next;
        }

        if(temp == NULL || strcmp(temp->name, name) != 0)
        {
            printf("Invalid roll number selection!\n");
            return;
        }

        /* Unlink the selected node */
        if(prev == NULL)
        {
            head = temp->next;
        }
        else
        {
            prev->next = temp->next;
        }

        free(temp);

        printf("Record deleted successfully!\n");
    }
    else
    {
        printf("Invalid choice!\n");
    }
}
