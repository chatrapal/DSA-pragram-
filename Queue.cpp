#include <stdio.h>
#include<stdlib.h>

void PUSH(void);
void POP(void);
void Read(void);
struct node
{
	int value;
	struct node *next;
};

typedef struct node stack;
stack *head=NULL;
stack *ptr=NULL;
stack *temp=NULL;
stack *temp1=NULL;
int conti=2;
int ch;
int main(void)
{
	while(conti==2)
	{
		printf("Press:\nFor PUSH:0\nFor POP:1\nFor Read:2\n");
		scanf(" %d",&ch);
		switch(ch)
		{
			case 0:
				PUSH();
				break;
			case 1:
				POP();
				break;
			case 2:
				Read();
				break;
			default:
				printf("Wrong input\n");
				break;
		}
		printf("\nPress to for continue:2\n");
		scanf(" %d",&conti);
	}
}
void PUSH(void)
{
	int n=0;
	int again=0;
	ptr=(stack*)malloc(sizeof(stack));
	printf("Enter number\n");
	scanf(" %d",&n);
	ptr->value=n;
	ptr->next=head;
	head=ptr;	
}
void POP(void)
{
	if(head==NULL)
	{	
		printf("PLease first insert atleast one node\n");
	}
	else
	{
		temp = head;
		temp1=head;
		temp1=temp1->next;
		while((temp->next!=NULL)&&(temp1->next!=NULL))
		{
			temp=temp->next;
			temp1=temp1->next;
		}
		temp->next=NULL;
	}
}
void Read(void)
{
	temp=head;
	if(temp==NULL)
	{
		printf("No node is present right now\n");
	}
	else
	{
		while(temp->next!=NULL)
		{
			printf(" %d",temp->value);
			temp=temp->next;
		}
		printf(" %d",temp->value);
	}
}
