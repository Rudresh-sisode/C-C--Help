#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
	int ID;
	char NAME[12];
	int AVG;
	struct student *NEXT;
};
struct student *FIRST;
struct student *LAST;
void insert(char name[],int Id,int Avg)
{
	 unsigned int n = strlen(name);
	struct student *PTR=(struct student*)malloc(sizeof(struct student));
	for(int i=0;i<n;i++)
	PTR->NAME[i]=name[i];
	PTR->ID=Id;
	PTR->AVG=Avg;
	if(FIRST==NULL)
	{
		FIRST=LAST=PTR;
		PTR->NEXT=NULL;
		printf("\nFirst Time Allocation");
	}
	else
	{
		LAST->NEXT=PTR;
		PTR->NEXT=NULL;
		LAST=PTR;
		printf("\n Further Allocation");
	}
	
}
void print()
{
	struct student *PTR;
if(FIRST==NULL)
{printf("\a ");printf("\nsorry no record");}
	if(FIRST==LAST)
		printf("\nyour values are %s , %d , %d",FIRST->NAME,FIRST->ID,FIRST->AVG);
	
	for(PTR=FIRST;PTR!=LAST;PTR=PTR->NEXT)
		printf("\nyour values are %s , %d , %d",FIRST->NAME,FIRST->ID,FIRST->AVG);
		printf("\n your values asre %s, %d , %d",LAST->NAME,LAST->ID,LAST->AVG);
		
}
int main(void)
{
	int choice;
	int id,avg;
	char name[12];
	while(1)
	{
	printf("\n Enter your name\t");
	scanf("%s",&name);
	printf("\n Enter your ID\t");
	scanf("%d",&id);
	printf("\n Enter your Marks\t");
	scanf("%d",&avg);
	insert(name,id,avg);
	print();
	}
	return 0;
	
}
