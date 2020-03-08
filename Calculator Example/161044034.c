/* THIS PROGRAM SOME MATHMATICAL OPERATIONS DEMONSTRATION PURPOSES */
/* GTU RULEZ */
#include<stdio.h>
#include <math.h>
#define TRUE 1
#define FALSE 0


int PrintSelection(int selection){
 printf("Selected Menu item is:");
 printf("%d\n",selection);
 return 1;
 
}

int DisplayMenu(){
 int selection;
 printf("\e[2J"); // Clears screen.
 
 printf("%s","\e[5;31;47mWELCOME TO ADDING PROGRAM\e[0m\n");
 printf("%s","(1) Add two numbers\n");
 printf("%s","(2) Sort an array\n");
 printf("%s","(3) Subtract two numbers\n");
 printf("%s","(4) Divide numbers\n");
 printf("%s","(5) Summarize numbers with words\n");
 printf("%s","(6) Exponent two numbers x to the y\n");
 printf("%s","(0) Quit\n");
 printf("Selection:");	
 scanf("%d",&selection);
 PrintSelection(selection);
 return selection;
}

int main(){
int number1, number2;
int sum,subt,res;										//"sum"=summation, "subt"=subtraction, "res"=result.
float div;												//"div"=division.
int copy_number,val=0,dig=1;							//"val"=step value,"dig"=number of digits.
char wanttoexit = FALSE;
char c;
int choice;
int i,j,k;												//Used for variable in "loops".
int myArray[100];
int max=-1;												//Counts size of array in for "Choice 2" and number of digits for "Choice 5".										
int temp;												//Used for swap operation in "Choice 2".

// Main loop.
while(wanttoexit == FALSE){

	// Display menu and get result.
	choice = DisplayMenu();
	
	
	if(choice == 1){
		printf("%s","PLEASE  ENTER FIRST NUMBER\n");
		scanf("%d",&number1);   						// Takes first number from user.
		printf("%s","PLEASE  ENTER SECOND NUMBER\n");
		scanf("%d",&number2);							// Takes second number from user.
		sum = number1 + number2;						// Calculates the total results.
		printf("The result is: ");
		printf("%d\n",sum);								//Print the result on the screen.
		c=getchar();
		c=getchar();
	}
	if(choice == 2){
		printf("%s","Enter numbers for array and '0' for end:\n");
		for(i=0;i<100;i++){								//Loop which takes numbers from user for array.
			scanf("%d",&number1);
			if(number1 == 0) break;						//Exits from loop when entered '0'.
			myArray[i] = number1;
			max = i ;									
		}
				
		printf("\nNumbers are entered.. \n");
		printf("Now sorting.. ");
		if(max<0)
			printf("\n\n\033[22;31mERROR\033[0m : You have not entered any number.\n");
	    for(i=0;i<=max;i++){							//Sort loop.
	       for(j=0;j<max; j++){
	           if(myArray[j] > myArray[j+1]){			//Applies swap to consecutive elements of the array.
	           		temp = myArray[j];
	           		myArray[j]= myArray[j+1];
	           		myArray[j+1]=temp;
	           }
		    }
		}
		if(max>=0){
		printf("Finished..\n{");
	    for(i=0;i<=max;i++){							//Prints the sequential array.
	      printf(" %d ",myArray[i]);
	    }
	      printf("} are the sorted numbers.\n");
	    }
	    max=-1;
	    c=getchar();
		c=getchar();
	}	
	if(choice == 3){
		printf("%s","PLEASE  ENTER FIRST NUMBER\n");
		scanf("%d",&number1);							// Takes first number from user.
		printf("%s","PLEASE  ENTER SECOND NUMBER\n");
		scanf("%d",&number2);							// Takes second number from user.
		subt = number1 - number2;						//Calculates the subtract.
		printf("The result is: ");
		printf("%d\n",subt);							//Print the result on the screen.
		c=getchar();
		c=getchar();
	}
	if(choice == 4){
		printf("%s","PLEASE  ENTER DIVIDEND NUMBER\n");
		scanf("%d",&number1);							// Takes first number from user.
		printf("%s","PLEASE  ENTER DIVISOR NUMBER\n");
		scanf("%d",&number2);							// Takes second number from user.
		if(number2!=0){
			div = (float)number1 / number2;					//Calculates the divide.
			printf("The result is: ");
			printf("%f\n",div);								//Print the result on the screen.
		}
		else
			printf("\n\033[22;31mERROR\033[0m : It is undefined!\n");
		c=getchar();
		c=getchar();
	}
	if(choice == 5){
		printf("%s","PLEASE  ENTER THE NUMBER\n");	
		scanf("%d",&number1);							//Takes a number from user.
		printf("The result is : ");	
		printf("%d = ",number1);
		copy_number=number1;							//Copies this number.
		max=0;											
		
		if (number1>9){									//Calculates number of digits.
			for(i=0;i<100;i++){
				copy_number/=10;
				max=i;
				if(copy_number<1) break;			
			}
		}
		else if(number1<0)
			printf(" \n\n\033[22;31mERROR\033[0m : Operation failed because of entered negative number!\n");										
		while(max!=0){									//Loop for calculates next number of digits in each steps.
			for(k=0;k<max;k++)
				dig=dig*10;
			while(dig<=number1){
				number1=number1-dig;
				val++;
			}				
			printf("%dx%d + ",val,dig);					//Prints to summerize of numbers to the screen. 
			val=0;
			dig=1;	
			max--;	
		}			
		if(number1>=0)
			printf("%d\n",number1);
		c=getchar();
		c=getchar();
	}
	if(choice == 6){
		printf("%s","PLEASE  ENTER BASE NUMBER\n");
		scanf("%d",&number1);							//Takes first number from user for base number.
		printf("%s","PLEASE  ENTER EXPONENT NUMBER\n");
		scanf("%d",&number2);							//Takes second number from user for exponent number.
		res=1;
		if(number1==0 && number2==0)					//This step for 0th exponent of 0.
			printf("\033[22;31mERROR\033[0m : It is indefinite!");
		else{
			if(number2<0){								//This part for negative exponent.
				if(number1!=0){
					number2*=-1;
					for(i=0;i<number2;i++){				//Loop for calculates result.
					res = res*number1;
				}
					printf("The result is: ");
					printf("1/%d\n",res);				//Print the result on the screen.
				}
				else
					printf("The result is: 0 ");		//0th exponent of non-zero numbers.						
			}	
			else{ 
				for(i=0;i<number2;i++){					//Loop for calculates result.
				res = res*number1;
			}
				printf("The result is: ");
				printf("%d\n",res);						//Print the result on the screen.
			}
		}
		c=getchar();
		c=getchar();
	}

	if(choice == 0){									//If 0 is entered choice, the program ends.
		wanttoexit = TRUE;
		printf("Exiting...\n");
	}
} // End of while.

}
