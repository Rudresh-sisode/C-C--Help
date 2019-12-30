#include<stdio.h>
#include<stdlib.h>
struct node
{
	int Info;
	struct node *NEXT;
};
struct node *FIRST=NULL;
struct node *LAST=NULL;
void insert(int);
int delete(int);
void view();
struct node *search(int);
int main(void)
{
	int choice;
	int num;
	while(1)
	{
		printf("\nenter the choice\t");
		scanf("%d",&choice);
		
		
		switch(choice)
		{
			case 1:
			{
				printf("\nenter the element to be inserted into linked list\t");
				scanf("%d",&num);
				insert(num);
				break;
			}
			case 2:
			{
				printf("\nYour list is ");
				view();
				break;
			}
			case 3:
			{
				view();
				printf("\nenter the element to be deleted from the list\t");
				scanf("%d",&num);
				int c=delete(num);
				printf("\n%d is successfully deleted from the list\n",c);
				break;
			}
			default:printf("sorry not found");break;
		}
	}
	
	
	return 0;
}
void insert(int v)
{
	struct node *PTR=(struct node *)malloc(sizeof(struct node));
	
	PTR->Info=v;
	
	if(FIRST==NULL)
	{
		FIRST=LAST=PTR;
		PTR->NEXT=NULL;
	}
	else
	{
		LAST->NEXT=PTR;
		PTR->NEXT=NULL;
		LAST=PTR;
	}
}
struct node *search(int value)
{
	struct node *PTR;
	
	if(FIRST==NULL)
	return(NULL);
	
	for(PTR=FIRST;PTR!=LAST;PTR=PTR->NEXT)
		if(PTR->Info==value)
			return(PTR);
		
		if(LAST->Info==value)
		{
			return(LAST);
		}
		else
		{
			return(NULL);
		}
}
int delete(int value)
{
	struct node *Loc,*Temp;
	int i;
	i=value;
	
	Loc=search(i);
	if(Loc==NULL)
		return(-9999);
	
	if(Loc==FIRST)
	{
		if(FIRST==LAST)
			FIRST=LAST=NULL;
		else
		FIRST=FIRST->NEXT;
		return(value);
	}
	else
	{
		Temp=Loc->NEXT;
		Loc=Temp;
		return(value);
	}
	if(Loc==LAST)
	{
		LAST->NEXT=NULL;
		return(value);
	}
	
}
void view()
{
	struct node *PTR;
	if(FIRST==NULL)
	{
		printf("\n\tempty list");
		return;
	}
	
	printf("\nlisted element");
	if(FIRST==LAST)
	{
		printf("\n\t%d",FIRST->Info);
		return;
	}
	for(PTR=FIRST;PTR!=LAST;PTR=PTR->NEXT)
		printf("\n %d",PTR->Info);
		printf("\n %d",LAST->Info);

}