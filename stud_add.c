#include "student.h"

void stud_add(void)
{
    struct student *newnode, *temp;
    int roll = 1;

    /* Find the smallest unused roll number */
    while(1)
    {
        temp = head;

        while(temp != NULL)
        {
            if(temp->rollno == roll)
                break;

            temp = temp->next;
        }

        if(temp == NULL)
            break;

        roll++;
    }

    /* Allocate memory dynamically */
    newnode = malloc(sizeof(struct student));

    if(newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    /* Assign unique roll number */
    newnode->rollno = roll;

    /* Read student details */
    printf("Enter student name: ");
    scanf(" %49[^\n]", newnode->name);

    printf("Enter percentage: ");
    scanf("%f", &newnode->percentage);

    newnode->next = NULL;

    /* Insert node into linked list */
    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }

    printf("\nStudent added successfully!\n");
    printf("Assigned roll number: %d\n", roll);
}
