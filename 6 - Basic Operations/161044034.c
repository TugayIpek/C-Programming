#include <stdio.h>
#define SIZE 300	// to changes size of sort array and string array (part 2 && part 5)
#define cleaner(); printf("\e[1;1H\e[2J"); // to cleaning terminal

void menu();	//general menu
void sort(int array[],int low,int mid,int high);	// helper function for merge_sort
int power(int base,int exp);		// helper function for common
void take_elements(int arr[],int max,int min);	//helper function for merge_sort
void array_print(int arr[],int max,int min);	//helper function for merge_sort

int common(int num1, int num2, int i);	//part 1
void merge_sort(int array[],int low, int high);	//part 2
int calc_formula(int number);	//part 3
int is_fit(int number, int *digit, int count);	//part 4
void capital(char str[] );	//part 5

int main(){	// start of main
	
	cleaner();
	menu();
return 0;
}	//end of main
void menu(){	// to choose part
	int choice=0;
	
	while(choice!=6)		//Start of while loop.
	{	
		choice=0;
		printf("/-------------------------- MENU -----------------------\\\n|\t\t\t\t\t\t\t|\n|\t\t\t\t\t\t\t|");
		printf("\n");
		printf("|1) Finding The Great Common Divisor 	(PART 1)\t|\n");
		printf("|2) Array Sorting Program 		(PART 2)\t|\n");
		printf("|3) Calculation With Segmented Function (PART 3)\t|\n");
		printf("|4) Equality of Number to Itself 	(PART 4)\t|\n");
		printf("|5) Finding First Capital Letter 	(PART 5)\t|\n");
		printf("|6) Exit\t\t\t\t\t\t|\n");
		printf("\\-------------------------------------------------------/\n");
		printf("\nChoice: ");
		scanf("%d",&choice);
		getchar();

		switch(choice){		//Start of switch-case.
			case 1: {		//Start of GCD process
				cleaner();
				int num1=0,num2=0,GCD=2;
				printf("Please enter two positive numbers: ");
				scanf("%d %d",&num1,&num2);		// takes two number from user
				if (num1<0) num1=num1*-1;
				if (num2<0) num2=num2*-1;
				
					GCD=common(num1,num2,GCD);		//sends common function
					
				printf("\nGreat Common Divisor of %d and %d = %d\n",num1,num2,GCD );	//prints GCD
				printf("\nPress enter to return to menu..\n");
				getchar();	getchar();
				cleaner();  break;
			}		//End of GCD process
			case 2: {		//Start of Sorting process
				cleaner();
				int max=0,min=0;
				int arr[SIZE];
				printf("Enter the length of the list: ");
				scanf("%d",&max);		// takes array size from user
				printf("\nEnter the elements of list: \n\n");
				take_elements(arr,max,min);	// takes elements for array

					merge_sort(arr,min, max-1);	// sends sort function 

				printf("\nSorted array is: ");
				array_print(arr,max,min);	// prints array
				printf("\n\nPress enter to return to menu..\n");
				getchar();	getchar(); 
				cleaner();  break;
			}		//End of Sorting process
			case 3: {		//Start of using formula
				cleaner();
				int number=0;
				printf("Please enter a number: ");
				scanf("%d",&number);	// takes number from user
				if (number<0) number=number*-1;
				printf("\n");
					
					calc_formula(number);	// calculates and prints number according to given formula
				
				printf("\n\nPress enter to return to menu..\n");
				getchar();	getchar(); 
				cleaner();  break;
			}		//End of using formula
			case 4: {		//Start , is number fit to itself
				cleaner();
				int number=0, count = 0, digit=0,result=0;
				printf("Example=> If (Digit: 3) && XYZ == X³ + Y³ + Z³ , it prints 'Equal'\n");
				printf("If it is not equal, it prints 'Not Equal'\n\n");
				printf("Please enter a number: ");
				scanf("%d",&number);	// takes number from user
				printf("\n");
				
					result = is_fit(number, &digit, count);		// checks number for fit or not according to given equality and prints result ("Equal" or "Not Equal")
				
				printf("\nPress enter to return to menu..\n");
				getchar();	getchar(); 
				cleaner();  break;	
			}		// End , is number fit to itself
			case 5:{	// Start of finding capital letter process
				cleaner();
				char str[SIZE];
				for (int i = 0; i < SIZE; ++i)
				{
					str[i]=0;
				}
				printf("Please enter a string (without white space): ");
				scanf(" %[^\n]s",str);		// takes a string until it enters
				
					capital(str);		// finds first capital letter

				printf("\nPress enter to return to menu..\n");
				getchar();	getchar(); 
				cleaner();  break;
			}	// End of finding capital letter process
			case 6:{ 	// this part just for exit from program
				printf("\nExiting..\n");
				break;
			}
				default: 	//Used to warning for invalid choice in general menu function.
					cleaner();
					printf("\nThis is an invalid choice. Try again!\n");  break; 
		}		//End of switch-case.
	}		//End of while loop.
}
int common(int num1, int num2, int i){	// start of part 1
	int GCD=1;

	if(num1==1 || num2==1)	return GCD;	// if num1 or num2 is 1, it returns multipication of common elements
	else if(num1%i==0 && num2%i==0)	 GCD=i*common((num1/i),(num2/i),i);		// finds common divisors of num1 and num2 
	else if(num1%i==0)	common((num1/i),num2,i);	// if divisor not common for n2 and n1, it just divides n1 and calls "common" again  
	else if(num2%i==0)	common(num1,(num2/i),i);	// if divisor not common for n2 and n1, it just divides n2 and calls "common" again
	else common(num1,num2,i+1);	// if divisor not available for both of them, it just increases divisor and calls "common" again
}	// end of part 1
void merge_sort(int arr[],int min, int max){	// start of part 2
   int mid;
   if( min != max )
   {
      mid = (min+max)/2;	// finds half of the array size
      merge_sort(arr,min , mid );	// continues until one element remains for left side of array
      merge_sort(arr,mid+1, max );	// continues until one element remains for right side of array
      sort(arr, min, mid, max );	// sends array, head, middle, end to the sort function
   }
}	// end of part 2
int calc_formula(int number){	// start of part 3
	printf("%d ",number ); 
	if(number < 0){	// if number smaller than zero, it works
		printf("is negative number !");
		return 0;
	}
	if(number==1 || number==0) return 0;	// if number is one or zero, process ends
	else if(number%2==0)	calc_formula(number/2);	// if number % 2 is zero, it makes operations according to formula and calls calc formula again
	else calc_formula(3*number+1); 	//if number % 2 is zero, it makes operations according to formula and calls calc formula again
}	// end of part 3
int is_fit(int number, int *digit, int count){	// start of part 4
	int res=0, temp=0, new=0;

	if(number>0)	// continous until number is zero
	{	
		count++;	// to controls the end, count increases until end of process
		(*digit)++;	// digit counter
		temp = (number / 10);	// continous divides to 10 until number is zero
		temp = number - (temp * 10);	// fins value of each digit and assign to the temp
		new = (number / 10);	// finds the rest
		res = res + is_fit(new, digit, count) + power(temp, *digit);	// sends all of them to is_fit function again	
		count--;	// if number is zero, count starts decreasing until it's zero

		if(count == 0){	// when count is zero it works
			if(res == number){	// if operation result equal to number, prints equal to screen
				printf("Equal\n");
				return 1;	// returns 1 because they are equal
			}
			else {	// if it is not equal, prints not equal to screen
				printf("Not Equal\n");
				return 0;	//returns 0 because they are not equal
			}
		}
		else{	//if count is not zero,it returns the sum if the process continous 
			return res;
		}
	}
	else if(count == 0){	// if taked number is zero or smaller than zero prints not equal to screen
		printf("Not Equal\n");
		return 0;
	}
}	// end of part 4
void capital(char str[]){		// start of part 5
	
	if(str[0] < 123 && str[0] > 96) { 	// if element is small letter, it passes to the next element 
		capital(str+1);
	}
	else if(str[0] > 64 && str[0] < 91) {	// if element is capital letter , prints to screen
		printf("\nFirst Capital Letter: %c\n",str[0] ); 
	}
	else if (!(str[0] < 123 && str[0] > 96) && !(str[0] > 64 && str[0] < 91) && str[0]!=0){	// if a non-letter character is entered, gives warning and continous to check process
		printf("\nYou entered unexpected character : '%c'\n",str[0] );
		capital(str+1);
	} 
	else printf("\nCapital letter not found !\n");	// if any capital letter is not entered, prints to screen 
}	// end of part 5
int power(int base,int exp){	//helper function 1 (part 1)
	int result=1;
	if(exp!=0)	result = base * power(base,(exp-1));
	return result;
}
void take_elements(int arr[],int max,int min){	//helper function 2 (part 2)
	if(min<max){
		scanf("%d",&arr[min]);
		take_elements(arr,max,min+1);
	}
}
void array_print(int arr[],int max,int min){	//helper function 3 (part 2)
	if(min<max){
		printf("%d ",arr[min] );
		array_print(arr,max,min+1);
	}
}
void sort(int arr[],int min,int mid,int max )	//helper function 4 (part 2)
{
   int temp[SIZE];
   int i = min;
   int j = mid +1 ;
   int k = min ;

   while( (i <= mid) && (j <=max) )	// if the elements of both sides are not finished
   {
      if(arr[i] <= arr[j]){	// if the left-side element equal or smaler than the right-side element
         temp[k++] = arr[i++] ;	// sends to sorting array
      }
      else{	// if it is not
         temp[k++] = arr[j++] ; // sends the other element to sorting array
      }
   }
   while( i <= mid ){	// if the elements of left side is not finihed
      temp[k++]=arr[i++];	//sends elements of left side to sorting array
   }
   while( j <= max ){	// if the elements of right side is not finihed
      temp[k++]=arr[j++];	// sends elements of right side to sorting array
   }
   for(i= min; i <= max ; i++){	// sends all elements of sorted array to defined array by user  
      arr[i]=temp[i];
   }
   
}
