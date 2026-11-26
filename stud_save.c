#include "student.h"

void stud_save(void)
{
    FILE *fp;
    struct student *temp;

    fp = fopen("student.dat", "w");

    if(fp == NULL)
    {
        printf("Unable to open file for saving!\n");
        return;
    }

    temp = head;

    while(temp != NULL)
    {
        fprintf(fp, "%d %s %.2f\n",
                temp->rollno,
                temp->name,
                temp->percentage);

        temp = temp->next;
    }

    fclose(fp);

    printf("Student records saved successfully!\n");
}
