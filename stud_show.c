#include "student.h"

void stud_show(void)
{
    struct student *temp;

    if(head == NULL)
    {
        printf("No student records available.\n");
        return;
    }

    temp = head;

    printf("--------------------------------------------------\n");
    printf("Roll No. Name Percentage \n");
    printf("--------------------------------------------------\n");

    while(temp != NULL)
    {
        printf("%d\t %s\t %.2f\t\n",temp->rollno,temp->name,temp->percentage);
        temp = temp->next;
    }

    printf("--------------------------------------------------\n");
}
