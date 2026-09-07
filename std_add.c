#include "student.h"

int roll_exists(SLL *head, int rollno)
{
	while (head)
	{
		if (head->rollno == rollno)
			return 1;
		head = head->next;
	}
	return 0;
}

int new_roll(SLL *head)
{
	int roll = 1;

	while (roll_exists(head, roll))
		roll++;

	return roll;
}

void add_record(SLL **head)
{
	SLL *new = malloc(sizeof(SLL));
	SLL *pos;

	if (new == 0)
	{
		printf("Memory allocation failed.\n");
		return;
	}

	new->rollno = new_roll(*head);

	do
	{
		printf("Enter student name: ");
		scanf(" %s", new->name);

		if (strlen(new->name) == 0)
			printf("Name should not be empty.\n");
		else
			break;
	} while (1);

	do
	{
		printf("Enter percentage (0.00 - 100.00): ");
		scanf("%f", &new->percentage);

		if (new->percentage < 0.0 || new->percentage > 100.0)
			printf("Percentage must be between 0 and 100.\n");

	} while (new->percentage < 0.0 || new->percentage > 100.0);

	if((*head==0)||(new->rollno<(*head)->rollno))
	{
		new->next=*head;
		*head=new;
	}
	else
	{
		pos=*head;
		while((pos->next)&&(new->rollno > pos->next->rollno))
			pos=pos->next;
		new->next=pos->next;
		pos->next=new;
	}

	printf("Record added successfully. Roll number = %d\n", new->rollno);
}


    
