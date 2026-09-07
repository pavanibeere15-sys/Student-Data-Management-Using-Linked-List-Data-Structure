#include "student.h"


void print_one_record(SLL *p)
{
    printf("%-8d %-30s %8.2f\n",
           p->rollno, p->name, p->percentage);
}

void show_records(SLL *head)
{
    if (head == NULL)
    {
        printf("No student records available.\n");
        return;
    }

    printf("------------------------------------------------------------\n");
    printf("%-8s %-30s %8s\n", "Roll No.", "Name", "Percentage");
    printf("------------------------------------------------------------\n");

    while (head)
    {
       // print_one_record(head);
       printf("%-8d %-30s %8.2f\n",head->rollno,head->name,head->percentage);
        head = head->next;
    }

    printf("------------------------------------------------------------\n");
}
