#include<stdio.h>
#include<stdlib.h>
struct student
{
	char name[100];
	int roll;
	struct student *next;
	struct student *prev;
};
struct student *head,*tail;
void create();
void display();
main()
{
	head=tail=NULL;
	int ch;
	while(1)
	{
		printf("Enter 1 to create 2 to display 3 to exit:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				create();
				break;
			case 2:
				display();
				break;
			case 3:
				exit(1);
			
		}
			
	}
}
void create()
{
	struct student *temp=(struct student*)malloc(sizeof(struct student));
	fflush(stdin);
	printf("Enter the name of the student:");
	gets(temp->name);
	printf("Enter the roll no. of the student:");
	scanf("%d",&temp->roll);
	temp->next=NULL;
	temp->prev=NULL;
	if(head==NULL)
	{
	head=tail=temp;
	tail->next=head;
}
	else
	{
		tail->next=temp;
		temp->prev=tail;
		tail=temp;
		tail->next=head;
	}
}
void display()
{
	struct student *t=head;
	if(head==NULL)
	printf("Empty list\n");
	else
	{
	while(t->next!=head)
	{
		printf("The name of the student is-");
		puts(t->name);
		printf("\nThe roll no. of the student is:");
		printf("%d\n",t->roll);
		t=t->next;
	}
	printf("The name of the student is-");
	puts(t->name);
	printf("\nThe roll no. of the student is:");
	printf("%d\n",t->roll);
}
}
