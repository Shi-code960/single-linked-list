
#include "student.h"

struct student *head = NULL;

int main()
{
    char choice;
  //  int exit_choice;

//    stud_load();

    while(1)
    {
        printf("\n******** STUDENT RECORD MENU ********\n");
        printf("a/A : Add new record\n");
        printf("d/D : Delete a record\n");
        printf("s/S : Show the list\n");
        printf("m/M : Modify a record\n");
        printf("v/V : Save records\n");
        printf("e/E : Exit\n");
        printf("t/T : Sort the list\n");
        printf("l/L : Delete all the records\n");
        printf("r/R : Reverse the list\n");

        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch(choice)
        {
            case 'a':
            case 'A':
                stud_add();
                break;

            case 'd':
            case 'D':
                stud_del();
                break;

            case 's':
            case 'S':
                stud_show();
                break;

            case 'm':
            case 'M':
                stud_mod();
                break;

            case 'v':
            case 'V':
                stud_save();
                break;
case 'l':
case 'L':
{
    struct student *temp;

    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    printf("All records deleted successfully!\n");
    break;
}
case 'r':
case 'R':
{
    struct student *prev = NULL;
    struct student *current = head;
    struct student *nextnode;

    while(current != NULL)
    {
        nextnode = current->next;
        current->next = prev;
        prev = current;
        current = nextnode;
    }

    head = prev;

    printf("List reversed successfully!\n");
    break;
}
case 't':
case 'T':
{
    struct student *i, *j;
    int sort_choice;
    int temp_roll;
    char temp_name[50];
    float temp_percentage;

    if(head == NULL || head->next == NULL)
    {
        printf("Not enough records to sort!\n");
        break;
    }

    printf("\n1. Sort by name\n");
    printf("2. Sort by percentage\n");
    printf("Enter your choice: ");
    scanf("%d", &sort_choice);

    for(i = head; i->next != NULL; i = i->next)
    {
        for(j = i->next; j != NULL; j = j->next)
        {
            if((sort_choice == 1 && strcmp(i->name, j->name) > 0) ||
               (sort_choice == 2 && i->percentage > j->percentage))
            {
                temp_roll = i->rollno;
                i->rollno = j->rollno;
                j->rollno = temp_roll;

                strcpy(temp_name, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, temp_name);

                temp_percentage = i->percentage;
                i->percentage = j->percentage;
                j->percentage = temp_percentage;
            }
        }
    }

    if(sort_choice == 1 || sort_choice == 2)
        printf("Records sorted successfully!\n");
    else
        printf("Invalid sorting choice!\n");

    break;
}
case 'e':
case 'E':
{
    char exit_option;

    printf("\nS/s : Save and exit\n");
    printf("E/e : Exit without saving\n");
    printf("Enter your choice: ");
    scanf(" %c", &exit_option);
switch(exit_option)
    {
        case 's':
        case 'S':
            stud_save();
           // printf("Saved and exited successfully.\n");
            exit(0);
            //return 0;
break;
        case 'e':
        case 'E':
            //printf("Exited without saving.\n");
            exit(0);
           // return 0;
break;
        default:
            printf("Invalid exit choice!\n");
            break;
    }
 }   
 
default:
printf("unknown choice\n");
break;
    }
}
}

