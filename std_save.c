#include "student.h"

void save_records(SLL *head)
{

	if(head==0)
	{
		printf("no records found\n");
		return;
	}
	FILE *fp;
	fp=fopen("student.dat","w");
	while(head)
	{
		fprintf(fp,"%d %s %f\n",head->rollno,head->name,head->percentage);
		head=head->next;
	}

	fclose(fp);
	printf("Records saved successfully to student.dat.\n");
}

void load_records(SLL **head)
{

	SLL *new,*last;
	FILE *fp;
	fp=fopen("student.dat","r");
	if(fp==0)
	{
		printf("no records found\n");
		return;
	}
	while(1)
	{
		new=malloc(sizeof(SLL));
		if(fscanf(fp,"%d %s %f",&new->rollno,new->name,&new->percentage)==-1)
			break;
		new->next=0;
		if(*head==0)
			*head=new;
		else{
			last=*head;
			while(last->next)
				last=last->next;
			last->next=new;
		}
	}
	fclose(fp);
}
