#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#define MIN 1		//You can change the minimum limit for Lucky Number Game.
#define MAX 1024	//You can change the maximum limit for Lucky Number Game.
#define TRIAL 10	//You can change trial for Lucky Number Game.
					//IF YOU DO NOT WANT TO SEE THE LUCKY NUMBER, YOU CAN DEACTIVATE PRINT FUNCTION IN LINE 45.
void menu();		//Like a control panel of user and all operations are done here.
int make_a_guess(int trial, int min, int max);		//Make a guesses for guessing game. 
void show_scores(int score_human, int score_program);		//Saves score and shows for guessing game.
void draw_hourglass (int height);		//Draws a hourglass known its height.
void draw_mountain_road (int length, int max_radius);		//Draws mountain road with half circle.

int main()		//Start of main function.
{	
	srand(time(NULL));
	menu();
return 0;
}		//End of main function.
void menu()		//Start of menu function.
{	
	int choice=0;
	int score_program=0,score_human=0;
	
	while(choice!=4)		//Start of while loop.
	{	
		choice=0;
		printf("\n***** MENU *****\n");
		printf("1. Play Lucky Number\n");
		printf("2. Draw Hourglass\n");
		printf("3. Draw Mountain Road\n");
		printf("4. Exit\n");
		printf("Choice: ");
		scanf("%d",&choice);
		getchar();
		switch(choice){
			case 1: {		//Start of lucky number game.
				system("clear");
				int LN=0,GN=0,distance=0,counter=0;		
				int min  = MIN;
				int max  = MAX;
				int trial= 1;
				int constant=trial+1;
				LN=(rand()%(max-(min-1)))+min;		//The program assign a random value in the range (min,max) for LN (Lucky Number).
				printf("Trial: %d  Lucy Number: %d\n",TRIAL,LN );		//If you don't want to see Lucy Number, you can deactivate this line.
				while(GN!=LN && trial!=TRIAL+1){
					GN=make_a_guess(trial,min,max);		//Values are sent to function and function returns GN (Guess Number).
					if (GN<LN && GN>min)	{ min=GN; }
					else if (LN<GN && GN<max)	{ max=GN; }
					distance=abs(LN-GN);		//The absolute value of the difference between LN and GN.
					if((GN<min || GN>max) && trial!=TRIAL)	printf("\033[1;31mTry again!\033[0m (Entered value is not in range.)");		//Warning for wrong value.
					else{		//The distance is calculated very special formulas. 
						while(distance>=1){
							distance=distance/2;
							counter++;
						}
					printf("Distance: %d",counter );
					counter=0;
					}
					trial++;
				}	
				if(GN==LN){		//If lucky number is guessed correctly, human score increases.
					printf(". You win!\n");
					score_human++;
				}
				else {		//If is not guessed correctly, program score increases.
					printf(". Program won!\n");
					score_program++;
				}
				show_scores(score_human,score_program);	break;	//The scores are written and after that the game ends.	 
			}		//End of lucky number game.
			case 2: {		//Start of draw hourglass.
				system("clear");
				int height=0;
				while((height%2)==0 && height>=0){		//Start of while loop.
					printf("\nPlease enter a odd number for height = ");
					scanf("%d",&height);
					getchar();
					printf("\n");
					if ((height%2)==0 || height<0){		//This condition ensures that the height is an positive odd number.
						printf("\033[1;31mWarning:\033[0m Height of the hourglass must be positive odd number!\n");		//Warning for wrong value.
						height=0;
					}
				}		//End of while loop.		
				draw_hourglass(height); break;		//Entered height is sent to the function and after that the draw ends.
			}		//End of draw hourglass.
			case 3: {		//Start of draw mountain road.
				system("clear");
				int length=0, max_radius=-1;
				while(length<=0 || max_radius<0 ){		//Start of while loop.
					printf("\nPlease enter a length greater than zero.	  (N) = ");
					scanf("%d", &length);
					printf("\nPlease enter a maximum radius. (Zero is included) (R) = ");
					scanf("%d", &max_radius);
					getchar();
					if (length<=0 || max_radius<0 )		//This condition ensures that the length is greater than zero and max radius is pozitive.
					{
						printf("\n\n\033[1;31mWarning:\033[0m N must be bigger than 0 and R must be positive integer!\n");		//Warning for wrong values.
					}
				}	//End of while loop.
				printf("\n");
				draw_mountain_road(length,max_radius); break;	//Entered length and max radius are sent to the function and after that the draw ends.
			}	//End of draw mountain road.
			case 4: {  
				system("clear");
				printf("\nExiting..\n"); break;		//This case just for exit.
			}
				default: 
					printf("\nThis is an invalid choice. Try again!\n");  break;		//If entered value for menu is wrong, this warning appears on the display. 
		}
	}		//End of while loop.
}		//End of menu function.
int make_a_guess (int trial, int min, int max)		//Start of make a guess function.
{
	int GN=0;
	printf("\n(Trial: %d) Make a guess between %d and %d: ",trial,min,max);	//It updates range for user convenince and prints trial.
	scanf("%d",&GN);		//Takes guess number from user.
	getchar();	
return GN;
}		//End of make a guess function.
void show_scores(int score_human, int score_program)		//Start of show scores function.
{
	printf("Your Score: %d Program Score: %d\n",score_human,score_program);		//Prints scores for "Play Lucky Number" game.
}		//End of show scores function.
void draw_hourglass (int height)		//Start of draw hourglass function.
{	
	int size=height;
	for (int i = 0; i < (height/2)+1; i++){		//Start of for loop.
		for (int k = 0; k < i; k++)
		{
			printf(" ");
		}
		for (int k = 0 ; k < size ; k++)
		{
			printf("*");
		}
		printf("\n");
		size-=2;
	}
		size=3;
	for (int i = 0 ; i < (height/2); i++){
		for (int k = 1 ; k < (height/2)-i; k++)
		{
			printf(" ");
		}
		for (int k = 0 ; k < size ; k++)
		{
			printf("*");
		}
		printf("\n");
		size+=2;
	}		//End of for loop.
}		//End of draw hourglass function.
void draw_mountain_road (int length, int max_radius)		//Start of draw mountain road function.
{
	int radius=0,control=0,again=-2;
	for (int i = 0; i < length; i++)	//Start of for loop.
	{
		radius=(rand()%(max_radius+1));
		if(i==0) { control=radius; }
		if(i==again+1 && radius==0 && i%2==1) control--;	//Align the lines if the previously radius is zero.
		if(i==again+1 && radius==0 && i%2==0) control++;	//Align the lines if the previously radius is zero.
		if(radius==0) again=i;
		if ((i%2)==0)		//Draws curves facing right.
		{	
			for (int i = 0; i < radius; i++){
				for (int k = 0; k < control+max_radius+1 ; k++) { printf(" "); }
				printf("/\n");
				control--;
			}
			for (int k = 0;  k < control+max_radius+1 ; k++) { printf(" "); }
			printf("|    R%d = %d\n",i+1,radius);
			control++;
			for (int i = 0 ; i < radius ; i++){
				for (int k = 0 ; k < control+max_radius+1; k++) { printf(" "); }
				printf("\\\n");
				control++;
			}
		}		
		else 		//Draws curves facing left.
		{	
			for (int i = 0; i < radius; i++){
				for (int k = control+max_radius+1;  k > 0 ; k--) { printf(" "); }
				printf("\\\n");
				control++;
			}
			for (int k = control+max_radius+1;  k > 0 ; k--) { printf(" "); }
			printf("|    R%d = %d\n",i+1,radius);
			control--;
			for (int i = 0 ; i < radius ; i++){
				for (int k = 0 ; k < control+max_radius+1; k++) { printf(" "); }
				printf("/\n");
				control--;
			}
		}
	}		//End of for loop. 
}		//End of draw mountain road function.
//LAST LINE.