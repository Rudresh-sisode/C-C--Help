#include<stdio.h>
#include<stdlib.h>
struct node
{
	int Info;
	struct node *Next;
};
struct node *first=NULL;
struct node *last=NULL;
void insert(int);
void delete(int);
void print(void);
struct node *search(int);

int main(void)
{
	int num1,num2,choice;
	struct node *location;
	
	while(1)
	{
		
	printf("\nselect an option\n");
	printf("\n 1--insert");
	printf("\n 2--delete");
	printf("\n 3--search");
	printf("\n 4--print");
	printf("\n 5--exit");
	
	printf("\nEnter your choice");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
		{
			printf("enter the element to be insert\n");
			scanf("%d",&num1);
			insert(num1);
			
			printf("%d successfully inserted",num1);
			break;
		}
		case 2:
		{
			printf("\nenter the number to be deleted from the list ");
			scanf("%d",&num1);
			delete(num1);
			printf("\n %d is successfully deleted",num1);
			break;
		}
		case 4:
		{
			print();
			break;
		}
		default:
		{
			printf("sorry boss ");
			break;
		}
		
	}
	}
	return 0;
}
void insert(int value)
{
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	
	ptr->Info=value;
	
	if(first==NULL)
	{
		first=last=ptr;
		ptr->Next=NULL;
	}
	else
	{
		last->Next=ptr;
		ptr->Next=NULL;
		last=ptr;
	}
}
void delete(int value)
{
	struct node *Loc,*Temp;
	int i;
	i=value;
	
	Loc=search(i);
	if(Loc==NULL)
		return;//turn(-9999);
	
	if(Loc==first)
	{
		if(first==last)
			first=last=NULL;
		else
		first=first->Next;
		return;//return(value);
	}
	for(Temp=first;Temp->Next!=Loc;Temp=Temp->Next)
		;
	Temp->Next=Loc->Next;
	
	
}
struct node *search(int value)
{
	struct node *ptr;
	
	if(first==NULL)
	return(NULL);
	
	for(ptr=first;ptr!=last;ptr=ptr->Next)
		if(ptr->Info==value)
			return(ptr);
		
		if(last->Info==value)
		{
			return(last);
		}
		else
		{
			return(NULL);
		}
}
void print()
{
	struct node *ptr;
	if(first==NULL)
	{
		printf("\nempty list");
	}
	
	for(ptr=first;ptr!=last;ptr=ptr->Next)
		printf("\t %d",ptr->Info);
		printf("\t %d",last->Info);
}