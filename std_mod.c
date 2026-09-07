#include "student.h"

void modify_node(SLL *p)
{

    printf("Current details:\n");
    print_one_record(p);

    printf("Enter updated name: ");
    scanf(" %s", p->name);

    do
    {
        printf("Enter updated percentage (0.00 - 100.00): ");
        scanf("%f", &p->percentage);

        if (p->percentage < 0.0 || p->percentage > 100.0)
            printf("Percentage must be between 0 and 100.\n");

    } while (p->percentage < 0.0f || p->percentage > 100.0f);

    printf("Record modified successfully.\n");
}

void modify_record(SLL *head)
{
    char choice;
    int rollno;
    char name[50];
    float percentage;
    struct student *temp;
    int count = 0;

    if (head == 0)
    {
        printf("No student records available.\n");
        return;
    }

    printf("Enter which record to search for modification\n");
    printf("R/r : Search by roll number\n");
    printf("N/n : Search by name\n");
    printf("P/p : Search by percentage\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);

    if (choice == 'r' || choice == 'R')
    {
        printf("Enter roll number: ");
        scanf("%d", &rollno);

        temp = head;
        while (temp)
        {
            if (temp->rollno == rollno)
            {
                modify_node(temp);
                return;
            }
            temp = temp->next;
        }

        printf("Record not found.\n");
    }
    else if (choice == 'n' || choice == 'N')
    {
        printf("Enter name: ");
        scanf(" %s", name);

        temp = head;
        while (temp)
        {
            if (strcmp(temp->name, name) == 0)
            {
                print_one_record(temp);
                count++;
            }
            temp = temp->next;
        }

        if (count == 0)
        {
            printf("Record not found.\n");
            return;
        }

        printf("Enter roll number of the record to modify: ");
        scanf("%d", &rollno);

        temp = head;
        while (temp)
        {
            if (temp->rollno == rollno &&
                strcmp(temp->name, name) == 0)
            {
                modify_node(temp);
                return;
            }
            temp = temp->next;
        }

        printf("Selected record not found.\n");
    }
    else if (choice == 'p' || choice == 'P')
    {
        printf("Enter percentage: ");
        scanf("%f", &percentage);

        temp = head;
        while (temp)
        {
            if (temp->percentage == percentage)
            {
                print_one_record(temp);
                count++;
            }
            temp = temp->next;
        }

        if (count == 0)
        {
            printf("Record not found.\n");
            return;
        }

        printf("Enter roll number of the record to modify: ");
        scanf("%d", &rollno);

        temp = head;
        while (temp)
        {
            if (temp->rollno == rollno &&
                temp->percentage == percentage)
            {
                modify_node(temp);
                return;
            }
            temp = temp->next;
        }

        printf("Selected record not found.\n");
    }
    else
        printf("Invalid choice.\n");
}
