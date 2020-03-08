#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define PI 3
#define SQUARE 1
#define RECTANGULAR 2
#define CIRCULAR 3
#define Red 0 
#define Yellow 1 
#define Blue 2 
#define Black 3
#define White 4

double CreateBody (int shape);		//The function where the body size(area) of the pokemon is calculated.
int SetColor (int color);		//The function that determines the color according to the entered value.
double LoadMoves(int,double);		//The function where the body move(perimeter) of the pokemon is calculated.
int SetAttackPower(int lower_bound, int upper_bound);		// Assigns a random attack power in the boundary ranges.
void ShowPokemon(int shape, double body_size, int color, double move_length, int attack_power);		//Pokemon is drawn using the entered data.
void Color_Print(int color);		//Written to be used for in the "ShowPokemon" function.(Functionality was aimed.)

int main ()		//Start of the main function.
{	int shape, color, attack_power;	
 	double size_of_body, move_length;
	shape = CIRCULAR ;		//You can choose the shape of Pokemon(SQUARE, RECTANGULAR or CIRCULAR).
	size_of_body = CreateBody (shape); 
	color = 798 ;		//You can enter a number from 0 to 1000 for color.
	color = SetColor(color);
	move_length = LoadMoves(shape, size_of_body);
	attack_power = SetAttackPower(0, 150);		//You can enter lower bound and upper bound.
	ShowPokemon(shape, size_of_body, color, move_length, attack_power);
}		// End of the main function.
double CreateBody (int shape)		//Start of the CreatBody function.
{	double body_size;
	int edge=0;
	
	if (shape==SQUARE)
	{	printf("\nPlease enter a positive number for the edge of square: ");
		scanf("%d", &edge);
		body_size=(edge*edge);
	}
	else if (shape==RECTANGULAR)
	{	printf("\nPlease enter a positive number for the edge of rectangular: ");
		scanf("%d", &edge);
		body_size=edge*5;
	}
	else if (shape==CIRCULAR)
	{	printf("\nPlease enter a positive number for the radius: ");
		scanf("%d", &edge);
		body_size=PI*edge*edge;
	}
	if(edge<=0)	
	{	printf("\n\033[1;31mERROR: \033[0m PLEASE TRY AGAIN ! (Entered value must be positive integer)\n");	//Checks that the input is positive integer.
		getchar();
		CreateBody(shape);
	}
	else return body_size;
}		//End of the CreatBody function.
int SetColor (int color)		//Start of the SetColor function.
{	if(color>=0 && color<=1000)	return (color%5); 
	else return 1;
}		//End of the SetColor function.

double LoadMoves(int shape, double body_size)		// Start of the LoadMoves function.
{	double move_length;
	if (shape==SQUARE)	move_length=sqrt(body_size)*4;
	if (shape==RECTANGULAR)	move_length=((body_size/5)*2) + 10;
	if (shape==CIRCULAR)	move_length=sqrt(body_size/PI)*PI*2;
	return move_length;
}		//End of the LoadMoves function.
int SetAttackPower(int lower_bound, int upper_bound)		//Start of the SetAttackPower function.
{	srand(time(NULL));
	return (lower_bound+(rand()%(upper_bound-lower_bound)));
}		//End of the SetAttackPower function.
void ShowPokemon(int shape, double body_size, int color, double move_length, int attack_power)		//Start of the ShowPokemon function.
{	int edge;
	int k,i,s,d=2;
	printf("\n");
	if (shape==SQUARE)	//If shape is square, it used the edge value and draws The Square Pokemon.
	{	edge=sqrt(body_size);
		for (int i=0; i<edge;i++)		//Start of loop(which draws square).
		{	for (int k=0; k<edge; k++)  printf("X "); 
			printf("\n");
		}		//End of loop.
		printf("\nName: Square Pokémon\n");
		printf("Size: %.0f\n", body_size );
		Color_Print(color);
		printf("Move: %.0f\n", move_length);
	}
	else if (shape==RECTANGULAR)		//If shape is rectangular, it used the edge value and draws The Rectangular Pokemon.
	{	edge=(body_size/5);
		for (int i=0; i<5;i++)		//Start of loop (which draws rectangular).
		{	for (int k=0; k<edge; k++)  printf("X");	
			printf("\n");
		}		//End of loop.
		printf("\nName: Rectangular Pokémon\n");
		printf("Size: %.0f\n", body_size );
		Color_Print(color);
		printf("Move: %.0f\n", move_length);
	}
	else if (shape==CIRCULAR)		//If shape is circular, it used the radius value and draws The Circular Pokemon.
	{	edge=sqrt(body_size/PI);	
		if ((edge%2)==1)		//If radius is odd, it works.
		{	for (i = (edge-1)/2; i >=0 ; i--)		//Start of loop (which draws circular for odd numbers).
			{	
				for (k =i-1; k >= 0 ; k--)  printf("\t"); 
				if (i==(edge-1)/2) printf("X\n");
				if(i<(edge-1)/2)
				{	printf("X");
					for (s =1 ; s <= d ; s++)  printf("\t"); 
					d=d+2;
					printf("X\n");
				}
			}
			d=d-4;
			for (i = 0; i <=(edge/2)-1 ; i++)
			{	for (k =0; k <=i  ; k++)  printf("\t"); 
				if (i==(edge/2)-1) printf("X\n\n");
				if(i<(edge/2)-1)
				{	printf("X");
					for (s =1 ; s <= d ; s++)  printf("\t"); 
					d=d-2;
					printf("X\n");
				}
			}		//End of loop (which draws circular for odd numbers).
		}		//End for odd radius.	
		else if((edge%2)==0)		//If radius is even, it works.
		{	d=1;
			for (i = edge/2; i >=0 ; i--)		//Start of loop (which draws circular for even numbers).
			{	
				if (i==(edge/2))
				{	for(k=(edge/2)-1; k>0; k--)  printf("\t"); 
						printf("    X");
				}
				for (k =i-1; k >= 0 ; k--)  printf("\t"); 
				if (i==edge/2) printf("\n");
				if(i<edge/2)
				{	printf("X");
					for (s =1 ; s <= d ; s++)  printf("\t"); 
					d=d+2;
					printf("X\n");
				}
			}
			d=d-4;
			for (i = 0; i <=(edge/2)-1 ; i++)
			{
				if (i==(edge/2)-1)
					{	for(k=(edge/2)-1; k>0; k--) printf("\t");
						printf("    X\n");
					}
				for (k =0; k <=i  ; k++) printf("\t");
				
				if (i==(edge/2)-1) printf("\n");
				if(i<(edge/2)-1)
				{	printf("X");
					for (s =1 ; s <= d ; s++) printf("\t");
					d=d-2;
					printf("X\n");
				}	
			}		//End of loop which draws circular for even numbers.
		}		//End for even radius.
		printf("Name: Circular Pokémon\n");	
		printf("Size: %.2f\n", body_size );
		Color_Print(color); 
		printf("Move: %.2f\n", move_length);
	}	
		printf("Attack Power: %d\n", attack_power );
}		//End of the ShowPokemon function.
void Color_Print(int color)		//Start of the Color_Print function.
{
			if	(color==Red) printf("Color: Red\n");
		else if (color==Yellow) printf("Color: Yellow\n");
		else if (color==Blue) printf("Color: Blue\n"  );
		else if (color==Black) printf("Color: Black\n" );
		else if (color==White) printf("Color: White\n");
}		//End of the Color_Print function.
