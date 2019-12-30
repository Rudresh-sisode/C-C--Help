#include<stdio.h>
#include<stdlib.h>
struct node
{
	int INFO;
	struct node *NEXT;
};
void insert(int);
void view();
int delete(int);
struct node *search(int);
struct node *FIRST=NULL;
struct node *LAST=NULL;
int main(void)
{
	int num,num2,choice;
	struct node *LOCATION;
	while(1)
	{
		printf("\nenter your choices");
		printf("\n 1 : Insert\n 2 : Delete\n 3 : Print\n 4 : Search\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				printf("\n Enter the Element to be inserted\t");
				scanf("%d",&num);
				insert(num);
				 
				break;
			}
			case 2:
			{
				printf("\nEnter the element to be Deleted from the list\t");
				scanf("%d",&num);
				num2=delete(num);
				printf("\n %d has successfully deleted !",num2);
				break;
			}
			case 3:
			{
				printf("\n Your listed is\n");
				view();
				break;
			}
			case 4:
			{
				printf("\nEnter the Element to be search !\n");
				scanf("%d",&num);
				LOCATION=search(num);
				printf("\nyour %d Element found at before %d this Element",num,(LOCATION->NEXT)->INFO);
				break;
			}
			default:
			{
				system("exit");
				break;
			}
			
		}
	}
	return 0;
}
void insert(int value)
{
	struct node *PTR=(struct node *)malloc(sizeof(struct node));
	
	PTR->INFO=value;
	
	if(FIRST==NULL)
	{
		FIRST=LAST=PTR;
		PTR->NEXT=FIRST;
	}
	else
	{
		LAST->NEXT=PTR;
		PTR->NEXT=FIRST;
		LAST=PTR;
		printf("\nelement pass");
	}
}
int delete(int value)
{
	struct node *LOC,*TEMP;
	int i;
	i=value;
	LOC=search(i);
	
	if(LOC==NULL)
		return (-9999);
	
	if(LOC==FIRST)
	{
		if(FIRST==LAST){
		FIRST=LAST=NULL;
		}
		else
		{
			FIRST=FIRST->NEXT;
			LAST->NEXT=FIRST;
		}
		return(value);
	}
	for(TEMP=FIRST;TEMP->NEXT!=LOC;TEMP=TEMP->NEXT)
		;
	if(LOC==LAST)
	{
		LAST=TEMP;
		TEMP->NEXT=FIRST;
	}
	else
		TEMP->NEXT=LOC->NEXT;
	return(LOC->INFO);
}
struct node *search(int value)
{
	struct node *PTR;
	if(FIRST==NULL)
		return(NULL);
	
	if(FIRST==LAST && FIRST->INFO==value)
		return FIRST;
	
	for(PTR=FIRST;PTR!=LAST;PTR=PTR->NEXT)
	if(PTR->INFO==value)
		return PTR;
	
	if(LAST->INFO==value)
		return(LAST);
	else
		return(NULL);
}
void view()
{
	struct node *PTR;
	if(FIRST==NULL)
	{
		printf("\nliked list is empty");
		return;
	}
	printf("\n your linked list\n");
	if(FIRST==LAST)
	{
		printf("\t%d",FIRST->INFO);
		return;
	}
	
	for(PTR=FIRST;PTR!=LAST;PTR=PTR->NEXT)
	{
		printf("\n \t %d",PTR->INFO);
	}
	printf("\n \t %d",LAST->INFO);
}
