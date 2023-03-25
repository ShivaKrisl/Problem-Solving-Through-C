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
#include "question.h"//question paper file
#define N 10//no.of questions in quiz is 10
void marks_display(void);
	struct kid{        //structure definition 
	char name[50];
	int age;
	float height;
	int marks;
   }*ptr;               // structure variable declaration[here variable is pointer]
int main()
{
	extern char q[12][1000];
	int i,j,n,m,score=0,k,t=0,temp[50],l,choice,age_search,*ap[50],*app;
	float *hp[50],*hpp,height_search;
	char option,*tp[50],*tpp,select,try_s,kidname[50];
	printf("ASSUMING IN EACH FLAT THERE IS A KID LIVING\n");
	printf("enter no.of floors(>=5):");
	scanf("%d",&n);
	if(n<5)
	{
		printf("\n floors did not match with the given condition");
		exit(0);
	}
	printf("\nenter no.of flats in each floor(>=5):");
	scanf("%d",&m);
	if(m<5)
	{
		printf("\n flats did not match with the given condition");
		exit(0);
	}
	l=n*m;
	ptr=(struct kid *)calloc(l,sizeof(struct kid));
	if(ptr==NULL)
	{
		printf("\n Insufficient memory allocated:");
		exit(0);
	}
	printf("enter details of %d kids in terms of:\n1.name\n2.age\n3.height:",n*m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)//m=5,n=5
		{
			printf("\n\n enter [%d]floor-[%d]flat kid details:\n",i+1,j+1);
			printf("name=");
			scanf("%s",(ptr+(i*m+j))->name);
			printf(" age=");
			scanf("%d",&(ptr+(i*m+j))->age);
			printf("height[in inches]=");
			scanf("%f",&(ptr+(i*m+j))->height);
			(ptr+(i*m+j))->marks=0;
		}
	}
	printf("\n ******//%d KIDS DETAILS ARE//*****",l);
	printf("\n--------------------------------------");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("\n [%d]floor-[%d]flat kid details are:\n",i+1,j+1);
			printf("Name=%s,\nAge=%d, \nHeight=%2f",(ptr+(i*m+j))->name,(ptr+(i*m+j))->age,(ptr+(i*m+j))->height);
		    printf("\n---------------------------------------");
		}
	}
	printf("\n_________________________________________________________________\n");
	printf("___________________________________________________________________");
    for(i=0;i<n;i++)
    {
    	for(j=0;j<m;j++)
    	{
    		//score=0;
    		printf("\n\n///******exam for kid[%s] has started******///\n\n",(ptr+(i*m+j))->name);
    		for(k=0;k<N;k++)//to repeat qsns
    		{
    			printf("%s\n",q[k]);
	           printf("choose option:");
               scanf(" %c",&option);
	           if(option==ans[k])
	           (ptr+(i*m+j))->marks++;
			}
			//(ptr+(i*m+j))->marks=score;
			//printf("\n%d",score);
			printf("------------------------------------------------------------------\n");
			printf("-->%s has secured %d marks\n",(ptr+(i*m+j))->name,(ptr+(i*m+j))->marks);
			printf("------------------------------------------------------------------");
		}
	}
	printf("\n_________________________________________________________________________");
	printf("\n                            /////*****SCORE BOARD*****/////          ");
	k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++,k++)
		{
			temp[k]=(ptr+(i*m+j))->marks;
			tp[k]=((ptr+(i*m+j))->name);
			ap[k]=&((ptr+(i*m+j))->age);
			hp[k]=&((ptr+(i*m+j))->height);
			printf("\n                            %s has secured %d marks",tp[k],temp[k]);
		}
	}
	//marks wise selection	
    printf("\n _________________________________________________________________________");
	printf("\n Want to search no.of persons scored in each mark, enter y or Y to start marks based searching:");
	scanf(" %c",&select);
	if(select=='y'||select=='Y')
	{
		do
		{
		marks_display();
		printf("\n make your choice:-");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
				printf("\n kids who scored 0 marks are:\n");
				for(i=0;i<n;i++)
				{
					for(j=0;j<m;j++)
					{
						if((ptr+(i*m+j))->marks==0)
						{
						printf("\n from %d floor and %d flat\n",i+1,j+1);
						printf("name=%s\n ",(ptr+(i*m+j))->name);
						printf("age=%d\n",(ptr+(i*m+j))->age);
						printf("height=%f\n",(ptr+(i*m+j))->height);
						printf("*********************************\n");
					   }
				    }
				}
				break;
			case 1:
				printf("\n kids who scored 1 marks are:\n");
				for(i=0;i<n;i++)
				{
					for(j=0;j<m;j++)
					{
						if((ptr+(i*m+j))->marks==1)
						{
						printf("\n from %d floor and %d flat\n",i+1,j+1);
						printf("name=%s\n ",(ptr+(i*m+j))->name);
						printf("age=%d\n",(ptr+(i*m+j))->age);
						printf("height=%f\n",(ptr+(i*m+j))->height);
						printf("*********************************\n");
						}
					}
				}
				break;
			case 2:
				printf("\n kids who scored 2 marks are:\n");
				for(i=0;i<n;i++)
				{
					for(j=0;j<m;j++)
					{
						if((ptr+(i*m+j))->marks==2)
						{
						printf("\n from %d floor and %d flat\n",i+1,j+1);
						printf("name=%s\n ",(ptr+(i*m+j))->name);
						printf("age=%d\n",(ptr+(i*m+j))->age);
						printf("height=%f\n",(ptr+(i*m+j))->height);
						printf("*********************************\n");
						}
					}
				}
				break;
			case 3:
				printf("\n kids who scored 3 marks are:\n");
				for(i=0;i<n;i++)
				{
					for(j=0;j<m;j++)
					{
						if((ptr+(i*m+j))->marks==3)
						{
						printf("\n from %d floor and %d flat\n",i+1,j+1);
						printf("name=%s\n ",(ptr+(i*m+j))->name);
						printf("age=%d\n",(ptr+(i*m+j))->age);
						printf("height=%f\n",(ptr+(i*m+j))->height);
						printf("*********************************\n");
						}
					}
				}
				break;
			case 4:
			    printf("\n kids who scored 4 marks are:\n");
				for(i=0;i<n;i++)
				{
					for(j=0;j<m;j++)
					{
						if((ptr+(i*m+j))->marks==4)
						{
						printf("\n from %d floor and %d flat\n",i+1,j+1);
						printf("name=%s\n ",(ptr+(i*m+j))->name);
						printf("age=%d\n",(ptr+(i*m+j))->age);
						printf("height=%f\n",(ptr+(i*m+j))->height);
						printf("*********************************\n");
						}
					}
				}
				break;
			case 5:
				printf("\n kids who scored 5 marks are:\n");
				for(i=0;i<n;i++)
				{
					for(j=0;j<m;j++)
					{
						if((ptr+(i*m+j))->marks==5)
						{
						printf("\n from %d floor and %d flat\n",i+1,j+1);
						printf("name=%s\n ",(ptr+(i*m+j))->name);
						printf("age=%d\n",(ptr+(i*m+j))->age);
						printf("height=%f\n",(ptr+(i*m+j))->height);
						printf("*********************************\n");
						}
					}
				}
				break;
	         case 6:
	         	printf("\n kids who scored 6 marks are:\n");
				for(i=0;i<n;i++)
				{
					for(j=0;j<m;j++)
					{
						if((ptr+(i*m+j))->marks==6)
						{
						printf("\n from %d floor and %d flat\n",i+1,j+1);
						printf("name=%s\n ",(ptr+(i*m+j))->name);
						printf("age=%d\n",(ptr+(i*m+j))->age);
						printf("height=%f\n",(ptr+(i*m+j))->height);
						printf("*********************************\n");
						}
					}
				}
				break;
			case 7:
				printf("\n kids who scored 7 marks are:\n");
				for(i=0;i<n;i++)
				{
					for(j=0;j<m;j++)
					{
						if((ptr+(i*m+j))->marks==7)
						{
						printf("\n from %d floor and %d flat\n",i+1,j+1);
						printf("name=%s\n ",(ptr+(i*m+j))->name);
						printf("age=%d\n",(ptr+(i*m+j))->age);
						printf("height=%f\n",(ptr+(i*m+j))->height);
						printf("*********************************\n");
						}
					}
				}
				break;
		    case 8:
		    	printf("\n kids who scored 8 marks are:\n");
				for(i=0;i<n;i++)
				{
					for(j=0;j<m;j++)
					{
						if((ptr+(i*m+j))->marks==8)
						{
						printf("\n from %d floor and %d flat\n",i+1,j+1);
						printf("name=%s\n ",(ptr+(i*m+j))->name);
						printf("age=%d\n",(ptr+(i*m+j))->age);
						printf("height=%f\n",(ptr+(i*m+j))->height);
						printf("*********************************\n");
						}
					}
				}
				break;
			case 9:
				printf("\n kids who scored 9 marks are:\n");
				for(i=0;i<n;i++)
				{
					for(j=0;j<m;j++)
					{
						if((ptr+(i*m+j))->marks==9)
						{
						printf("\n from %d floor and %d flat\n",i+1,j+1);
						printf("name=%s\n ",(ptr+(i*m+j))->name);
						printf("age=%d\n",(ptr+(i*m+j))->age);
						printf("height=%f\n",(ptr+(i*m+j))->height);
						printf("*********************************\n");
						}
					}
				}
				break;
			case 10:
				printf("\n kids who scored 10 marks are:\n");
				for(i=0;i<n;i++)
				{
					for(j=0;j<m;j++)
					{
						if((ptr+(i*m+j))->marks==10)
					    {
					    printf("\n from %d floor and %d flat\n",i+1,j+1);
						printf("name=%s\n ",(ptr+(i*m+j))->name);
						printf("age=%d\n",(ptr+(i*m+j))->age);
						printf("height=%f\n",(ptr+(i*m+j))->height);
						printf("*********************************\n");
						}
					}
				}
				break;
			default:
				printf("\n sorry incorrect option selected\n please select from above options");
				break;
		}
		printf("\n Wanna try again? enter y to Y to select again:-");
	    scanf(" %c",&try_s);
	}while(try_s=='y'||try_s=='Y');
     }
     printf("\n want to search details of kid using name? enter y or Y to begin name-wise search:");
     scanf(" %c",&select);
     if(select=='y'||select=='Y')
   {
     do
     {
     	printf("\n enter the kid name you want to search:");
     	scanf(" %s",kidname);
     	for(i=0;i<n;i++)
     	{
     		for(j=0;j<m;j++)
     		{
     			if(strcmp(kidname,(ptr+(i*m+j))->name)==0)
     			{
     				printf("_______________________________\n");
     				printf("kid details found");
     				printf("\n kid details are:\n");
     				printf("name=%s\n",(ptr+(i*m+j))->name);
     				printf("age=%d\n",(ptr+(i*m+j))->age);
     				printf("height=%f\n",(ptr+(i*m+j))->height);
     				printf("%s is living in %d floor and %d flat\n",(ptr+(i*m+j))->name,i+1,j+1);
     				printf("_________________________________\n");
				 }
				 else
				 printf("\n %s details not found in %d floor and %d flat\n",kidname,i+1,j+1);
			 }
		 }
     	printf("\n wanna try again? enter y or Y to search again:");
     	scanf(" %c",&try_s);
	 }while(try_s=='y'||try_s=='Y');
    }
    //height wise searching
    printf("\n want to know details of kids by heights enter y|Y to search by height:");
    scanf(" %c",&select);
    if(select=='y'||select=='Y')
    {
    do{
    	printf("\n enter the height:");
    	scanf("%f",&height_search);
    	for(i=0;i<n;i++)
    	{
    		for(j=0;j<m;j++)
    		{
    			if((ptr+(i*m+j))->height==height_search)
    			{
    				printf("\n--------------------------------------------");
    				printf("\n kid is found in %d floor %d flat",i+1,j+1);
    				printf("\n kid details are:");
    				printf("\n name=%s",(ptr+(i*m+j))->name);
    				printf("\n age=%d",(ptr+(i*m+j))->age);
    				printf("\n height=%f",(ptr+(i*m+j))->height);
    				printf("\n marks=%d",(ptr+(i*m+j))->marks);
    				printf("\n---------------------------------------------");
				}
				else
				printf("\n kid with height %f is not found in %d floor and %d flat\n",height_search,i+1,j+1);
			}
		}
		printf("\n wanna try again?enter y|Y to try again:");
		scanf(" %c",&try_s);
	}while(try_s=='y'||try_s=='Y');
   }
	//age wise searching
	printf("\n want to know details of kids by ages enter y|Y to search by age:");
	scanf(" %c",&select);
	if(select=='y'||select=='Y')
	{
	do{
		printf("\n enter age want to search:");
		scanf("%d",&age_search);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
			  	if((ptr+(i*m+j))->age==age_search)
    			{
    				printf("\n--------------------------------------------");
    				printf("\n kid is found in %d floor %d flat",i+1,j+1);
    				printf("\n kid details are:");
    				printf("\n name=%s",(ptr+(i*m+j))->name);
    				printf("\n age=%d",(ptr+(i*m+j))->age);
    				printf("\n height=%f",(ptr+(i*m+j))->height);
    				printf("\n marks=%d",(ptr+(i*m+j))->marks);
    				printf("\n---------------------------------------------");
				}
				else
				printf("\n kid with age=%d is not found in %d floor and %d flat\n",age_search,i+1,j+1);	
			}
		}
		printf("\n wanna try again?enter y|Y to search again:");
		scanf(" %c",&try_s);
	}while(try_s=='y'||try_s=='Y');
   }
	//starting marks sorting mechanism in descending order
	for(i=0;i<l-1;i++)
	{
		for(j=i+1;j<l;j++)
		{
			if(temp[i]<temp[j])
			{
				t=temp[i];//marks swap
				tpp=tp[i];//name swap
				hpp=hp[i];//height swapping
				app=ap[i];
				temp[i]=temp[j];
				tp[i]=tp[j];
				hp[i]=hp[j];
				ap[i]=ap[j];
				temp[j]=t;
				tp[j]=tpp;
				hp[j]=hpp;
				ap[j]=app;
			}
		}
	}
   //printf("\n______________________________________________________________________________________");
	//printf("\n                               ///*****SCORE BOARD AFTER SORTING MARKS*****///:");
	/*for(i=0;i<l;i++)
	{
		printf("\n                                 name=%s, age=%d,height=%f marks secured %d ",tp[i],*ap[i],*hp[i],temp[i]);
		
     }*/
     //if marks same consider heights
     printf("\n__________________________________________________________________________________________");
	printf("\n                               ///*****SCORE BOARD AFTER SORTING*****///:");
		for(i=0;i<l;i++)
    {
    	for(j=i+1;j<l;j++)
    	{
    	if(temp[i]==temp[j])
    	{
    		if(*hp[i]<*hp[j])
    		{
    			//heights swapping
    			hpp=hp[i];
    			hp[i]=hp[j];
    			hp[j]=hpp;
    			//name swapping
    			tpp=tp[i];
    			tp[i]=tp[j];
    			tp[j]=tpp;
    			//age swapping
    			app=ap[i];
    			ap[i]=ap[j];
    			ap[j]=app;
			}
			else if(*hp[i]==*hp[j])
			{
				if(*ap[i]<*ap[j])
				{
				//heights swapping
    		/*	hpp=hp[i];
    			hp[i]=hp[i+1];
    			hp[i+1]=hpp;*/
    			//name swapping
    			tpp=tp[i];
    			tp[i]=tp[j];
    			tp[j]=tpp;
    			//age swapping
    			app=ap[i];
    			ap[i]=ap[j];
    			ap[j]=app;
    		  }
			}
		}
	   }
    	printf("\n                             name=%s age=%d, height=%f and marks=%d",tp[i],*ap[i],*hp[i],temp[i]);
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
  for(i=0;i<11;i++)
  {
  	printf("\n name =%s, age=%d, height=%f and marks secured=%d",tp[i],*ap[i],*hp[i],temp[i]);
  }
  free(ptr);
  ptr=NULL;
	return 0;
}
void marks_display()
{
	printf("\n 1. press 0 to display details of kids who scored 0 marks");
	printf("\n 2. press 1 to display details of kids who scored 1 marks");
	printf("\n 3. press 2 to display details of kids who scored 2 marks");
	printf("\n 4. press 3 to display details of kids who scored 3 marks");
	printf("\n 5. press 4 to display details of kids who scored 4 marks");
	printf("\n 6. press 5 to display details of kids who scored 5 marks");
	printf("\n 7. press 6 to display details of kids who scored 6 marks");
	printf("\n 8. press 7 to display details of kids who scored 7 marks");
	printf("\n 9. press 8 to display details of kids who scored 8 marks");
	printf("\n 10. press 9 to display details of kids who scored 9 marks");
	printf("\n 11. press 10 to display details of kids who scored 10 marks");
}
