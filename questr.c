/*PROBLEM STATEMENT:
There is an apartment with n no.of floors and m no.of flats in each floor. 
Assuming in each flat there is one kid living.
There is a trainer who wants to train the kids in various games.
Develop a c-application to read and store details of each kid in terms of his
NAME, AGE, HEIGHT and MARKS secured in quiz exam.
Where in the quiz exam is conducted by the trainer.
The marks of all the kids are sorted in descending order so that first 11 members
from them will form a group and given training in cricket.
Other kids will be trained in any other games.
CONSTRAINTS:
1.n>=5 and m>=5 [should be read dynamically from the user]
2.if marks secured by any of two kids are same then their ages and heights are taken into consideration.
3.Quiz exam is conducted for 10 marks where it comprises of 10 questions each carrying 1 mark.
4.For each correct answer the kid gets 1 mark else 0 marks will be awarded.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "question.h"
#pragma pack(1)
#define N 10
int i,j,l;
	struct kid{
	char name[50];
	int age;
	int floor;
	int flat;
	int height;
	int marks;
   }*ptr;
void search_name(char *,struct kid *);
void search_age(int *,struct kid *);
void search_height(int *,struct kid *);
void marks_display(struct kid *);
int main()
{
	extern char q[12][1000];
	int n,m,k,t,a;
	int kidage,kidheight,score;
	char option,tpp[50],select,search1;
	printf("enter no.of floors(>=5):");
	scanf("%d",&n);
/*	if(n<5)
	{
		printf("\n floors did not meet the given constraint:");
		exit(0);
	}*/
	printf("\nenter no.of flats in each floor(>=5):");
	scanf("%d",&m);
/*	if(m<5)
	{
		printf("\n flats did not meet the given constraint:");
		exit(0);
	}*/
	l=n*m;
	//printf("\n %d",l);
	ptr=(struct kid *)calloc(l,sizeof(struct kid));
	struct kid tptr[l];
	struct kid temp_s;
	printf("enter details of %d kids in terms of:\n1.name\n2.age\n3.height:",l);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			(ptr+(i*m+j))->floor=i+1;
			(ptr+(i*m+j))->flat=j+1;
			printf("\n enter [%d]floor [%d]flat kid details:\n",(ptr+(i*m+j))->floor,(ptr+(i*m+j))->flat);
			scanf("%s\n%d\n%d",(ptr+(i*m+j))->name,&(ptr+(i*m+j))->age,&(ptr+(i*m+j))->height);
			(ptr+(i*m+j))->marks=0;
		}
	}
	k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++,k++)
		{
			strcpy((tptr[k].name),((ptr+(i*m+j))->name));
			tptr[k].floor=(ptr+(i*m+j))->floor;
			tptr[k].flat=(ptr+(i*m+j))->flat;
			tptr[k].age=(ptr+(i*m+j))->age;
			tptr[k].height=(ptr+(i*m+j))->height;
			tptr[k].marks=(ptr+(i*m+j))->marks;
			printf("\n [%d]floor-[%d]flat kid details are:\n",tptr[k].floor,tptr[k].flat);
			printf("Name=%s,\nAge=%d,\nHeight=%d",tptr[k].name,tptr[k].age,tptr[k].height);
		}
		printf("\n");
	}
	a=0;
    for(i=0;i<n;i++)
    {
    	for(j=0;j<m;j++,a++)
    	{
    		printf("\n\nexam for kid[%s] has started\n\n",tptr[a].name);
    		for(k=0;k<N;k++)
    		{
    			printf("%s\n",q[k]);
	           printf("choose option:");
               scanf(" %c",&option);
	           if(option==ans[k])
	          (ptr+(i*m+j))->marks++;
			}
			tptr[a].marks=(ptr+(i*m+j))->marks;
			printf("%s has secured %d marks\n",tptr[a].name,tptr[a].marks);
		}
	}
	//sorting mechs
	for(i=0;i<l;i++)
	{
		for(j=i+1;j<l;j++)
		{
			if(tptr[i].marks<tptr[j].marks)
			{
				temp_s=tptr[i];
				tptr[i]=tptr[j];
				tptr[j]=temp_s;
			}
		}
	}
	//after sorting
	printf("\n after sorting:\n");
	for(i=0;i<l;i++)
	{
		printf("name=%s,age=%d,height=%d,marks=%d\n",tptr[i].name,tptr[i].age,tptr[i].height,tptr[i].marks);
	}
	for(i=0;i<l;i++)
	{
		for(j=i+1;j<l;j++)
		{
			if(tptr[i].marks==tptr[j].marks)//if marks same 
			{
				if(tptr[i].height<tptr[j].height)//consider heights
				{
				temp_s=tptr[i];
				tptr[i]=tptr[j];
				tptr[j]=temp_s;
				}
			    else if(tptr[i].height==tptr[j].height)//even heights are same
			    {
			    	if(tptr[i].age<tptr[j].age)//consider age
			    	{
	    			   temp_s=tptr[i];
		        	   tptr[i]=tptr[j];
				       tptr[j]=temp_s;
					}
				}
			}
		}
	}
	printf("\n_______________________________________________________________________________________________________________");
  //starting selection mechanism
  printf("\n///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
  printf("\n *****   *      *******   *********  *******    **********      *         *******          ********     *******      *******");
  printf("\n *       *         *      *             *       *         *     *         *                *      *     *       *    *");
  printf("\n *       *         *      *             *       *         *     *         *                *      *     *      *     *");
  printf("\n *****   *         *      *   *****     *       *********       *         *******          ********     ******       *******");
  printf("\n *       *         *      *       *     *       *        *      *         *                *      *     *  *         *");
  printf("\n *       *         *      *       *     *       *         *     *         *                *      *     *    *       *");
  printf("\n *****   *****  *******   *********  *******    *********       ******    *******          *      *     *      *     *******\n");
  printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
  printf("\nKIDS ELIGIBLE TO PLAY CRICKET ARE:\n");
  printf("-------------------------------------------------------------------\n");
	for(i=0;i<l;i++)
	{   printf("\n***************************************************************************************\n");
		printf("\n from floor %d and flat %d\n",tptr[i].floor,tptr[i].flat);
		printf("name=%s\nage=%d\nheight=%d\nmarks=%d",tptr[i].name,tptr[i].age,tptr[i].height,tptr[i].marks);
		printf("\n***************************************************************************************");
	}
	//name wise search
	printf("\n want to search kid details based on name\n enter y or y to begin name wise search:");
	scanf(" %c",&select);
	if(select=='y'||select=='Y')
	{
		do
		{
			printf("\n enter kid name to search:");
			scanf(" %s",tpp);
			//printf("%s",tpp);
			search_name(tpp,tptr);//function call
			printf("\n wanna try again?\nenter y to Y to retry:");
			scanf(" %c",&search1);
		}while(search1=='y'||search1=='Y');
	}
	//age wise
	printf("\n want to search kid details based on age\n enter y or y to begin age wise search:");
	scanf(" %c",&select);
	if(select=='y'||select=='Y')
	{
		do
		{
			printf("\n enter kid age to search:");
			scanf("%d",&kidage);
			search_age(&kidage,tptr);//function call
			printf("\n wanna try again?\nenter y to Y to retry:");
			scanf(" %c",&search1);
		}while(search1=='y'||search1=='Y');
	}
	//height wise
	printf("\n want to search kid details based on height\n enter y or y to begin height wise search:");
	scanf(" %c",&select);
	if(select=='y'||select=='Y')
	{
		do
		{
			printf("\n enter kid height to search:");
			scanf("%d",&kidheight);
			//printf("%s",tpp);
			search_height(&kidheight,tptr);//function call
			printf("\n wanna try again?\nenter y to Y to retry:");
			scanf(" %c",&search1);
		}while(search1=='y'||search1=='Y');
	}
	//marks wise
	printf("\n want to search kid details based on marks\n enter y or y to begin marks wise search:");
	scanf(" %c",&select);
	if(select=='y'||select=='Y')
	{
		do
		{
			marks_display(tptr);
			printf("\n wanna try again?\nenter y to Y to retry:");
			scanf(" %c",&search1);
		}while(search1=='y'||search1=='Y');
	}
return 0;
}
void search_name(char *str,struct kid *temp)
{ 
   for(i=0;i<l;i++)
   {
   	 if(strcmp(str,(temp+i)->name)==0)
   	 {
   	 	printf("\n kid is found. Details are:\n");
   	 	printf("name=%s,age=%d,height=%d,marks=%d",(temp+i)->name,(temp+i)->age,(temp+i)->height,(temp+i)->marks);
   	 	printf("\n%s is in %d floor %d flat",(temp+i)->name,(temp+i)->floor,(temp+i)->flat);
     }
     else
     	printf("\n %s is not found in %d floor %d flat",str,(temp+i)->floor,(temp+i)->flat);
   }
}
void search_age(int *ap,struct kid *temp)
{
	for(i=0;i<l;i++)
	{
		if(*ap==(temp+i)->age)
		{
		printf("\n kid is found. Details are:\n");
   	 	printf("name=%s,age=%d,height=%d,marks=%d",(temp+i)->name,(temp+i)->age,(temp+i)->height,(temp+i)->marks);
   	 	printf("\n%s is in %d floor %d flat",(temp+i)->name,(temp+i)->floor,(temp+i)->flat);
		}
		else
		   printf("\n %d age is not found in %d floor %d flat",*ap,(temp+i)->floor,(temp+i)->flat);
	}
}
void search_height(int *hp,struct kid *temp)
{
	for(i=0;i<l;i++)
	{
		if(*hp==(temp+i)->height)
		{
		printf("\n kid is found. Details are:\n");
   	 	printf("name=%s,age=%d,height=%d,marks=%d",(temp+i)->name,(temp+i)->age,(temp+i)->height,(temp+i)->marks);
   	 	printf("\n%s is in %d floor %d flat",(temp+i)->name,(temp+i)->floor,(temp+i)->flat);
		}
		else
		   printf("\n %d height is not found in %d floor %d flat",*hp,(temp+i)->floor,(temp+i)->flat);
	}
}
void marks_display(struct kid *temp)
{
	int choice;
	printf("\n press 0 to display kids details who scored 0 marks");
	printf("\n press 1 to display kids details who scored 1 marks");
	printf("\n press 2 to display kids details who scored 2 marks");
	printf("\n press 3 to display kids details who scored 3 marks");
	printf("\n press 4 to display kids details who scored 4 marks");
	printf("\n press 5 to display kids details who scored 5 marks");
	printf("\n press 6 to display kids details who scored 6 marks");
	printf("\n press 7 to display kids details who scored 7 marks");
	printf("\n press 8 to display kids details who scored 8 marks");
	printf("\n press 9 to display kids details who scored 9 marks");
	printf("\n press 10 to display kids details who scored 10 marks");
	printf("\n please! make your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 0:
			printf("\n kids who scored 0 marks are:");
			for(i=0;i<l;i++)
			{
				if((temp+i)->marks==0)
				{
					printf("\n from %d floor %d flat:",(temp+i)->floor,(temp+i)->flat);
					printf("\n name=%s\tage=%d\theight=%d",(temp+i)->name,(temp+i)->age,(temp+i)->height);
				}
			}
			break;
		case 1:
			printf("\n kids who scored 1 marks are:");
			for(i=0;i<l;i++)
			{
				if((temp+i)->marks==1)
				{
					printf("\n from %d floor %d flat:",(temp+i)->floor,(temp+i)->flat);
					printf("\n name=%s\tage=%d\theight=%d",(temp+i)->name,(temp+i)->age,(temp+i)->height);
				}
			}
			break;
		case 2:
			printf("\n kids who scored 2 marks are:");
			for(i=0;i<l;i++)
			{
				if((temp+i)->marks==2)
				{
					printf("\n from %d floor %d flat:",(temp+i)->floor,(temp+i)->flat);
					printf("\n name=%s\tage=%d\theight=%d",(temp+i)->name,(temp+i)->age,(temp+i)->height);
				}
			}
			break;
		case 3:
			printf("\n kids who scored 1 marks are:");
			for(i=0;i<l;i++)
			{
				if((temp+i)->marks==3)
				{
					printf("\n from %d floor %d flat:",(temp+i)->floor,(temp+i)->flat);
					printf("\n name=%s\tage=%d\theight=%d",(temp+i)->name,(temp+i)->age,(temp+i)->height);
				}
			}
			break;
		case 4:
			printf("\n kids who scored 1 marks are:");
			for(i=0;i<l;i++)
			{
				if((temp+i)->marks==4)
				{
					printf("\n from %d floor %d flat:",(temp+i)->floor,(temp+i)->flat);
					printf("\n name=%s\tage=%d\theight=%d",(temp+i)->name,(temp+i)->age,(temp+i)->height);
				}
			}
			break;
		case 5:
			printf("\n kids who scored 5 marks are:");
			for(i=0;i<l;i++)
			{
				if((temp+i)->marks==5)
				{
					printf("\n from %d floor %d flat:",(temp+i)->floor,(temp+i)->flat);
					printf("\n name=%s\tage=%d\theight=%d",(temp+i)->name,(temp+i)->age,(temp+i)->height);
				}
			}
			break;
		case 6:
			printf("\n kids who scored 6 marks are:");
			for(i=0;i<l;i++)
			{
				if((temp+i)->marks==6)
				{
					printf("\n from %d floor %d flat:",(temp+i)->floor,(temp+i)->flat);
					printf("\n name=%s\tage=%d\theight=%d",(temp+i)->name,(temp+i)->age,(temp+i)->height);
				}
			}
			break;
		case 7:
			printf("\n kids who scored 7 marks are:");
			for(i=0;i<l;i++)
			{
				if((temp+i)->marks==7)
				{
					printf("\n from %d floor %d flat:",(temp+i)->floor,(temp+i)->flat);
					printf("\n name=%s\tage=%d\theight=%d",(temp+i)->name,(temp+i)->age,(temp+i)->height);
				}
			}
			break;
		case 8:
			printf("\n kids who scored 8 marks are:");
			for(i=0;i<l;i++)
			{
				if((temp+i)->marks==8)
				{
					printf("\n from %d floor %d flat:",(temp+i)->floor,(temp+i)->flat);
					printf("\n name=%s\tage=%d\theight=%d",(temp+i)->name,(temp+i)->age,(temp+i)->height);
				}
			}
			break;
		case 9:
			printf("\n kids who scored 9 marks are:");
			for(i=0;i<l;i++)
			{
				if((temp+i)->marks==9)
				{
					printf("\n from %d floor %d flat:",(temp+i)->floor,(temp+i)->flat);
					printf("\n name=%s\tage=%d\theight=%d",(temp+i)->name,(temp+i)->age,(temp+i)->height);
				}
			}
			break;
		case 10:
			printf("\n kids who scored 10 marks are:");
			for(i=0;i<l;i++)
			{
				if((temp+i)->marks==10)
				{
					printf("\n from %d floor %d flat:",(temp+i)->floor,(temp+i)->flat);
					printf("\n name=%s\tage=%d\theight=%d",(temp+i)->name,(temp+i)->age,(temp+i)->height);
				}
			}
			break;
		default:
			printf("\n sorry menu out of bound\n please select from the top menu only");
			break;
	}
}
