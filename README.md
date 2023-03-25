# Problem-Solving-Through-C

PROBLEM STATEMENT:
 There is an apartment with n-number of floors and m-number of flats in 
each floor. Assuming in each flat there is one kid living. There is a trainer who 
wants to train the kids in various games.
Develop a c-application to read and store details of each kid in terms of his 
NAME, AGE, HEIGHT and MARKS secured in quiz exam. Where in the quiz exam 
is conducted by the trainer. The marks of all the kids are sorted in descending 
order so that first 11 members from them will form a group and given training 
in cricket. Other kids will be trained in any other games.
CONSTRAINTS:
1. n>=5 and m>=5 [should be read dynamically from the user]
2. if marks secured by any of two kids are same then their ages and 
heights are taken into consideration.
3. Quiz exam is conducted for 10 marks where it comprises of 10 
questions each carrying 1 mark.
4. For each correct answer the kid gets 1 mark else 0 marks will be 
awarded.

MODULES AND MECHANISMS USED:
1. User-defined Header file inclusion:
 Here the questions for Quiz examination along with their answers are 
stored in user defined header file [named as “question.h”] so that questions 
will be displayed one after another for all kids.
2. Read/ Input:
In this module all the kids’ detail from n floors and m flats are taken in 
terms of their Names, Ages and Heights using Structures. And for each 
question the option is stored which in turn verifies with the actual answer 
and marks will be awarded according to it. Each kid net marks are stored in 
one more element of a structure, so that it would become easy to compare 
the marks of all kids.
3. Sorting mechanism
All the marks of kids are sorted in descending order so that it would be 
easy for the trainer to select top 11 members to play cricket.
 In order to sort marks, we need to create one more temporary 1D array 
since we have used pointer to represent kids details so that while sorting 
the original pointer respective will not changes.
 The mechanism that Is used by us to sort marks in descending order is 
“BUBBLE SORT MECHANISM”. This is one of the most powerful sorting 
techniques where elements are compared with their next iteration values 
and sorted accordingly. Advantage of this technique is that the last element 
will get automatically sorted.
PSP Course Project report A.Y. 2021-2022
Page 6
In order to use this mechanism, we need to maintain two loops [placing one 
loop in another loop] where the outer loop (say i as loop variable) runs 
from first field to last but one[n-1] field and inner loop (say j) runs from 
current i value to n fields. these two elements are compared using If control 
statement in every successive iteration and are sorted accordingly. 
 4. Swapping:
In the process of sorting, if the control statement condition result 
comes out to be true the respective marks are swapped using third 
variable. While swapping the marks their respective name address , 
height address and age address are also swapped which can be used 
during selection and printing. 
5. Selection Mechanism:
Once the marks fields are sorted best of them are taken out and given 
practice in cricket. In addition to marks sorting, we make use of 
another 3 array of pointers which stores respective names of kids, 
heights of kids and ages of kids. While marks are being swapping 
simultaneously, we swap their respective name address, height 
address and age address so that highest marks scored kid name, his 
age and height and marks are printed.
6. Searching: 
 Searching is done based on user requirement. User can search 
details of kids by entering marks, entering name, entering height, and 
age.
Do while loop is used so that user can search the kids details as many 
times he wants. 
PSP Course Project report A.Y. 2021-2022
Page 7
7. Print:
 In this module the details of kids are printed immediately after 
reading all kids details. After completion of quiz by each kid his/her 
result is printed immediately along with complete score board of all 
kids are also displayed.
Searching results are displayed immediately after initiating the 
search. Here user can search as many times he wants. The searching 
will be in each flat to avoid naming, age and height conflictions. Since, 
kids can have same name, age and height so that searching results 
will be printed from flat.
Finally, all the eligible kids’ details are printed so that the trainer can 
give cricket training only to those kids in a week
