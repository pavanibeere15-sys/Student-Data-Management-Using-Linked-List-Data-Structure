#include "student.h"

void delete_all(SLL **head)
{
    SLL *del=*head;
      
    if(*head==0)
    {
    printf("no records found\n");
    return;
    }
    while (del)
    {
        *head=del->next;
        free(del);
	del=*head;
    }

    printf("All records deleted from memory.\n");
}
