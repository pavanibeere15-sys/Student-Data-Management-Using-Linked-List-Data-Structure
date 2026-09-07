#include "student.h"

int main()
{
    SLL *head = 0;
    char choice, subchoice;

    load_records(&head);

    while (1)
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

        switch (choice)
        {
            case 'a':
            case 'A':
                add_record(&head);
                break;

            case 'd':
            case 'D':
                delete_record(&head);
                break;

            case 's':
            case 'S':
                show_records(head);
                break;

            case 'm':
            case 'M':
                modify_record(head);
                break;

            case 'v':
            case 'V':
                save_records(head);
                break;

            case 't':
            case 'T':
                sort_records(&head);
                
                break;

            case 'l':
            case 'L':
                delete_all(&head);
                break;

            case 'r':
            case 'R':
                reverse_list(&head);
                break;

            case 'e':
            case 'E':
                printf("\nS/s : Save and exit\n");
                printf("E/e : Exit without saving\n");
                printf("Enter your choice: ");
                scanf(" %c", &subchoice);

                if (subchoice == 's' || subchoice == 'S')
                    save_records(head);
                else if (subchoice == 'e' || subchoice == 'E')
                {
                    delete_all(&head);
		    printf("program terminated\n");
                 
                }

                    exit(0);
            default:
                printf("Invalid menu choice.\n");
        }
    }
}
