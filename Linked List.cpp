#include<stdio.h>
#include<stdlib.h>
void insertion_at_begning(void);
void intersion_at_end(void);
void read(void);
void delete_from_nth_place(int);
void deleteAll(void);
struct node
{
	int value;
	struct node *next;
};
struct node *head=NULL;
struct node *ptr=NULL;
struct node *temp=NULL;
struct node *temp1=NULL;
int n;	
int again=0;
int conti=2;
char ch;
int place=0;

int main(void)
{
	while(conti==2)
	{
		printf("Press character for following number:\nInsertion at beginning:B\nInsertion at end:E\nRead:R\nDelete from speficic position:D\nDelete complete node or linked list:A\n");
		scanf(" %c",&ch);
		switch(ch)
		{
			case 'B':
				insertion_at_begning();
				break;
			case 'E':
				intersion_at_end();
				break;
			case 'R':
				read();
				break;
			case 'D':
				printf("Enter the place from where you want to delete");
				scanf(" %d",&place);
				delete_from_nth_place(place);
				break;
			case 'A':
				deleteAll();
				break;
			default:
				printf("Wrong Input\n");
				break;

		}
		printf("\ncontinue press-2:\n");
		scanf(" %d",&conti);
	}
}


void insertion_at_begning()
{
	do
	{
		ptr = (struct node*)malloc(sizeof(struct node));
		printf("Enter number\n");
		scanf(" %d",&n);
		ptr->value=n;
		ptr->next=head;
		head = ptr;
		printf("Do you want to continue press 1\n");
		scanf(" %d",&again);	
	}
		while(again==1);
}

void intersion_at_end()
{
	do
	{
	
		ptr = (struct node*)malloc(sizeof(struct node));
		temp=head;
		if(head==NULL)
		{
			head=ptr;
			printf("Enter number\n");
			scanf(" %d",&n);	
			ptr->value=n;
			ptr->next=NULL;
		}
		else
		{
			while(temp->next!=NULL)
			{
				temp = temp->next;
			}
			printf("Enter number\n");
			scanf(" %d",&n);
			temp->next=ptr;
			ptr->value=n;
			ptr->next=NULL;	
		}
		printf("Do you want to continue press 1\n");
		scanf(" %d",&again);
	}
	while(again==1);
		
}
void read()
{
	if(temp=NULL)
	{
		printf("Linked List is empty");
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			printf(" %d",temp->value);
			temp=temp->next;
		}
		printf(" %d",temp->value);
	}
}
void delete_from_nth_place(int pos)
{
	int i=0;
	temp=head;
	temp1=head;
	temp1=temp1->next;
	while(++i<pos)
	{
		temp=temp->next;
		temp1=temp1->next;
	}
	temp->next=temp1->next;	
}
void deleteAll()
{
	head=NULL;
	free(ptr);
}
