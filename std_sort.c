#include "student.h"

void sort_records(SLL **head)
{
    char choice;
    struct student *i, *j;
    int temp_roll;
    float temp_percentage;
    char temp_name[50];

    if (*head == 0)
    {
        printf("No records found \n");
        return;
    }
    printf("R/r : sort with rollno\n");
    printf("N/n : Sort with name\n");
    printf("P/p : Sort with percentage\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);

    if (choice != 'n' && choice != 'N' &&
        choice != 'p' && choice != 'P'&& choice != 'R' && choice != 'r')
    {
        printf("Invalid sorting choice.\n");
        return;
    }

    
    for (i = *head; i; i = i->next)
    {
        for (j = i->next; j; j = j->next)
        {
            int swap = 0;

            if (choice == 'n' || choice == 'N')
            {
                if (strcmp(i->name, j->name) > 0)
                    swap = 1;
            }
	    else if(choice=='r'||choice=='R')
	    {
	    if(i->rollno < j->rollno)
		    swap=1;
	    }
            else
            {
                if (i->percentage < j->percentage)
                    swap = 1;
            }

            if (swap)
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

    printf("Records sorted successfully.\n");
}
