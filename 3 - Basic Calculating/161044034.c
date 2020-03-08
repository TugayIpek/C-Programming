#include <stdio.h>
#define cleaner(); printf("\e[1;1H\e[2J");

void menu();		//General menu function.

void op_menu();		//Menu function of simple calculator.
int doit(int fun(int num1, int num2),int n1,int n2);		//Used to send to operators and numbers.
int add(int number1,int number2);		//Addition function.
int sub(int number1,int number2);		//Substraction function.
int mul(int number1,int number2);		//Multiplication function.
int div(int number1,int number2);		//Division function.
int power(int number1,int number2);		//Power function.
int mod(int number1,int number2);		//Modul function.

int take_grades(int [] );		//Used to take homework & lab grades. 
int take_exam_grades(int[]);		//Used to take exam grades.
double calculate_homework(int[]);		//Calculates avarage of homework grades.
double calculate_lab(int[]);		//Calculates avarage of lab grades.
double calculate_all(int ,int[], int);		////Calculates avarage of all grades.

int main()		//Start of main function.
{
	menu();	
	return 0;
}		//End of menu function.
void menu()		//Start of general menu function.
{	
	int choice=0;

	while(choice!=4)		//Start of while loop.
	{	
		choice=0;
		printf("\n\t***** MENU *****\n");
		printf("1) Simple Calculator Program\n");
		printf("2) Weighted Grade Calculation\n");
		printf("3) Draw Shape (Parallelogram)\n");
		printf("4) Exit\n");
		printf("\nChoice: ");
		scanf("%d",&choice);
		getchar();
		switch(choice){		//Start of switch-case.
			case 1: {		//Start of simple calculator program.
				op_menu(); break;
			}		//End of simple calculator program.
			case 2: {		//Start of weighted grade calculator. 
				cleaner();
				
				printf("	  // Welcome To The Weighted Grade Calculation Program \\\\\n");
				printf("	>>Grades must be between -300 and 100. (Limits included.)<<\n\n");
				int homework[10], lab[10], exam[2];
				int h_avarage=0, l_avarage=0;
				double wa_avarage=0;
				
				h_avarage=calculate_homework(homework);
				l_avarage=calculate_lab(lab);
				take_exam_grades(exam);
				wa_avarage=calculate_all(h_avarage, exam, l_avarage);
				printf("\nWeighted Avarage = %0.2f\n",wa_avarage ); //Prints weighted grade.
				printf("\nPress enter twice to return to menu..\n");
				getchar();	getchar(); getchar();
				cleaner();  break;
			}		//End of weighted grade calculator.
			case 3: {		//Start of draw shape.
				cleaner();
				
				printf("		^^ Welcome To The Draw Shape Program ^^\n\n");
				int height=0,space=0,star=0;
				
				while(height<1) {		//Start of while loop.
					printf("Please enter a height of shape: ");
					scanf("%d",&height);
					if (height<1) { 
						printf("\nWarning: Height must be greater than '0' !\n\n"); 
						getchar();
					}
				}		//End of while loop.
				space=height-1;

				for (int i = 0; i < height; i++){		//Start of for loop.
					
					for (int k = 0; k < space; k++){
						printf(" ");
					}
					printf("/");
					space--;
					for (int k = 0; k < star ; k++){
						printf("*");
					}
					printf("\\\n");
					star+=2;
				}
				star-=2;
				space++;
				for (int i = 0; i < height; i++){
					
					for (int k = 0; k < space; k++){
						printf(" ");
					}
					printf("\\");
					space++;
					for (int k = 0; k < star ; k++){
						printf("*");
					}
					printf("/\n");
					star-=2;
				}		//End of for loop.
				printf("\nPress enter twice to return to menu..\n");
				getchar();	getchar(); getchar();
				cleaner();  break;
			}		//End of draw shape.
			case 4: {		//This case just for exit.
				printf("\nExiting..\n"); break;		
			}
				default: 	//Used to warning for invalid choice in general menu function.
					cleaner();
					printf("\nThis is an invalid choice. Try again!\n");  break; 
		}		//End of switch-case.

	}		//End of while loop.
}		//End of menu function.
void op_menu(){		//Start of op_menu function.
	cleaner();
	
	char sign=0;
	int result=0;
	
	printf("\t\t#### Welcome to Simple Calculator ####\n\n");		
	printf("Addition      : +				|Sample: + 10 2\n");
	printf("Substraction  : -		        	|	 12\n");
	printf("Multiplication: *		        	|	 ** 8 2\n");
	printf("Division      : /		        	|	 64\n");
	printf("Power         : **		        	|	 %% 3\n");
	printf("Modulo        : %%		        	|	 1\n");
	printf("Exit          : E/e 		        	|	 e\n");
	printf("(Invalid Type): If operation is invalid, program returns the previous result. \n");
	printf("\nPress E/e and enter to exit..\n\n");

	while (sign!='e' && sign!='E'){		//Start of while loop.
		char sign2=0,control=0;
		int number1=0,number2=0,num1=0,num2=0;
		int check=0,s1_check=0,s2_check=0;
		sign=0;		
		while(check==0){		//Start of while inside while loop.
			s1_check=0;
			s2_check=0;
			sign=0;
			sign2=0;
			scanf(" %c%c",&sign,&sign2);
			if(sign=='+' || sign=='-' || sign=='*' || sign=='/' || sign=='%' || sign=='e' || sign=='E') s1_check=1;		//Checks entered operators.
			if (sign2==' ' || sign2=='\n' || sign2=='*') s2_check=1;		//Checks power operation case.
			if(s1_check==1 && s2_check==1) check=1;		//If both of them true, it works.
			else {  	//If not, it gives warning.
				printf("%d		(Invalid Type)\n",result); 
				check=0;
				sign=0;
				sign2=0;	
			}
		}		//End of while inside while loop.
		if(sign!='e' && sign!='E'){		//Checks take of second number. 
			scanf(" %d%c",&num1,&control);
			if (control==' ')	scanf("%d",&num2); 
			else if(control=='\n');
			else { control==0; getchar();}
		}
		if (control==' '){		//If it was taked.
			number1=num1;
			number2=num2;
		}
		else {		//If it wasn't taked.
			number1=result;
			number2=num1;
		}
		if(sign=='+'){
			result=doit(add,number1,number2);
			printf("%d\n",result );
		}
		else if(sign=='-'){
			result=doit(sub,number1,number2);
			printf("%d\n",result );
		}
		else if(sign=='*' && sign2=='*'){
			result=doit(power,number1,number2);
			printf("%d\n",result );
		}
		else if(sign=='*'){
			result=doit(mul,number1,number2);
			printf("%d\n",result );
		}
		else if(sign=='/'){
			result=doit(div,number1,number2);
			printf("%d\n",result );
		}
		else if(sign=='%'){
			result=doit(mod,number1,number2);
			printf("%d\n",result );
		}
	}		//End of while loop.
	cleaner();
}		//End of op_menu function.
int doit(int fun(int num1,int num2),int n1,int n2){		// Start of doit function.
	int result=0;
	result=fun(n1, n2);
return result;
}		//End of doit function.
int add(int number1,int number2){	// Start of add function.
	return number1+number2; 
}			//End of add function.
int sub(int number1,int number2){		//Start of sub function.
	return number1-number2; 
}		//End of sub function.
int mul(int number1,int number2){		//Start of mul function.
	return number1*number2; 
}		//End of mul function.
int div(int number1,int number2){		//Start of div function.
	if(number2==0) { printf("Undefined !\n"); return number1; }
	else return number1/number2;
}		//End of div function.
int power(int number1,int number2){		//Start of power function.
	int result=1;
	for (int i = 0; i < number2; i++)
	{
		result=number1*result;
	}
	return result;
}		//End of power function.
int mod(int number1,int number2){		//Start of mod function.
	if(number2==0) { printf("Undefined !\n"); return number1; }
	else return number1%number2;
}		//End of mod function.
int take_grades(int grade[] ){		//Start of take grades function.
	for (int i = 0; i < 10; i++){		//Start of for loop.
		grade[i]=101;	
		while(grade[i]<-300 || grade[i]>100){		//Start of while loop.
			printf("%d.Grade : ",i+1);
			scanf("%d",&grade[i]);
			if (grade[i]<-300 || grade[i]>100) {
				printf("\nTry Again. (Between -300 and 100) \n\n");
				getchar();		
			}
		}		//End of while loop.
	}		//End of for loop.
}		//End of take grades function.
int take_exam_grades(int exam[]){		//Start of take exam grades function.
	exam[0]=101;
	exam[1]=101;
	printf("\nPlease enter exam grades (2): \n\n");
	while(exam[0]<-300 || exam[0]>100){		//Start of while loop.
		printf("Midterm : ");
		scanf("%d",&exam[0]);
		if (exam[0]<-300 || exam[0]>100) {
			printf("\nTry Again. (Between -300 and 100) \n\n");
			getchar();		
		}	
	}		//End of while loop.
	while(exam[1]<-300 || exam[1]>100){		//Start of while loop.
		printf("Final	: ");
		scanf("%d",&exam[1]);
		if (exam[1]<-300 || exam[1]>100) {
			printf("\nTry Again. (Between -300 and 100) \n\n");
			getchar();		
		}
	}		//End of while loop.
}		//End of take exam grades function.
double calculate_homework(int homework[]){		//Start of calculate homework function.
	double avarage=0;
	printf("Please enter homework grades (10): \n\n");
	take_grades(homework);
	for (int i = 0; i < 10; ++i)	{	avarage+=homework[i];	}		//For loop.
	avarage=(avarage/10)*10/100;	
	return avarage;
}		//End of calculate homework function.
double calculate_lab(int lab[]){		//Start of calculate lab function.
	double avarage=0;
	printf("\nPlease enter lab grades (10): \n\n");
	take_grades(lab);
	for (int i = 0; i < 10 ; ++i)	{	avarage+=lab[i]; 	}
	avarage=(avarage/10)*20/100;
	return avarage;
}		//End of calculate lab function.
double calculate_all(int h_avarage,int exam[],int l_avarage){		//Start of calculate all function.
	return (exam[0]*0.3)+(exam[1]*0.4)+l_avarage+h_avarage;
}		//End of calculate all function.