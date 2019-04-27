#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int trial=1;
int guess(int arr[],int M,int N)
{
	if(M>N)
		return -1;
	int i=0, x=0,new=0,pos=-1,ran=0; char ch;
	int memory[(N-M)+1];
	if(trial>8)
		return 1;
	else
	{	
	do
	{
		srand(time(NULL)); 
		if(M==N)
			ran=M;
		else
			ran = M+(rand()%((N+1)-M));new=1;
		for(i=0;i<pos;i++)
		{	
			if(ran==memory[i])
			new=0; break;
		}
    }while(new==0);
    pos++;
    memory[pos]=ran;
	printf("\nTrial #%d",trial);
	printf("\nMy guess : %d",ran);
	trial++;
		do
		{   x=0;
			printf("\nIs the number you picked equal to %d ? (Enter 1) ",ran);
			printf("\nIs the number you picked greater than %d ? (Enter 2)  ",ran);
			printf("\nIs the number you picked less than %d ? (Enter 3)  \n",ran);
			scanf(" %c",&ch);
			fflush(stdin);
			if(ch=='1')
				return 0;
			else if(ch=='2')
				return guess(arr,ran+1,N);
			else if(ch=='3')
				return guess(arr,M,ran-1);
			else
			    {
			    	printf("\nWrong Choice! Try again");
				 	x=1;
				}
		}while(x!=0);
	}
	
}

void main()
{
	int M=0,N=99;
	int arr[100];
	int i=0,n=0,result=0,x=0;
	printf("Welcome!\n");	
	printf("\nNow think of any number between 0 and 99. Shh! DON'T TELL ME!");
	printf("\n\nPress any key to continue . . .");
	getch();
	printf("\n\nGood! Now I'll try to guess the number within 8 tries\n");
	result=guess(arr,M,N);
	if(result==1)
		printf("\n\n8 tries already?! My bad!");
	else if(result==0)
		printf("\nWoohoo! I win!");
	else if(result == -1)
		printf("\nI have a feeling you're lying. Not Cool! ");
	printf("\nThank you for playing\n\nPress any key to exit . . .");
	getch();		
}
