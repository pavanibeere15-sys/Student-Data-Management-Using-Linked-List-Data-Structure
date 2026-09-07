#include "student.h"

void delete_by_roll(SLL **head)
{
	SLL *del=*head,*prev;

	if(*head==0)
	{
		printf("no records found\n");
		return;
	}

	int rollno;
	printf("enter rollno to delete\n");
	scanf("%d",&rollno);
	while(del)
	{
		if(del->rollno==rollno)
		{
			if(del==*head)
				*head=del->next;
			else
				prev->next=del->next;
			free(del);
			printf("record deleted successfully\n");
			return;
		}
		prev=del;
		del=del->next;
	}
	printf("Roll no not found\n");
}


void delete_by_name(SLL **head)
{
	if(*head==0)
	{
		printf("no records found\n");
		return;
	}
	char name[30];
	printf("enter name to delete:\n");
	scanf("%s",name);
	SLL *del=*head,*prev;
	while(del)
	{
		if(strcmp(name,del->name)==0)
		{
			if(del==*head)
				*head=del->next;
			else
				prev->next=del->next;
			free(del);
			printf("record deleted successfully\n");
			return;
		}
		prev=del;
		del=del->next;
	}
	printf("name not found");
}
void delete_record(SLL **head)
{
	char choice;
	int rollno;
	if (*head == NULL)
	{
		printf("No student records available.\n");
		return;
	}

	printf("R/r : Enter roll number to delete\n");
	printf("N/n : Enter name to delete\n");
	printf("Enter your choice: ");
	scanf(" %c", &choice);

	if (choice == 'r' || choice == 'R')
	{
		delete_by_roll(head);
	}

	else if(choice=='n'||choice=='N')
	{
		delete_by_name(head);
	}

	else
		printf("Invalid choice.\n");
}
