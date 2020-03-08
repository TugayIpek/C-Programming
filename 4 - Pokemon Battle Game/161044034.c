#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define cleaner(); printf("\e[1;1H\e[2J");		//For clean to terminal.           
typedef enum {quadratic,linear}attack_type;		//Attack types of Pokemons.
typedef enum {Charmande, Pikachu, Squirtle, Bulbasaur, Pidgeotto, Ratata, Mug, Caterpie, Zubat, Krabby}pokemon;		//Names of Pokemons.

void menu();		//General menu function.
void pokedex(char Pokemon_name[][11], int range[], attack_type type[], int attack_power[], int stamina[]);		//For to user to learn qualifications of Pokemons.
void oaks_laboratory(char Pokemon_name[][11], pokemon Pokemons[], pokemon *my_Pokemons);		//For create a Pokemon pocket.
void show_Pokemons(char Pokemon_name[][11], pokemon Pokemons[], int pokemon_count);			//To show all Pokemons.
void catch_a_pokemon(char Pokemon_name[][11], pokemon Pokemons[], pokemon *my_pocket);		//To catch Pokemon and put in pocket.
void release_a_pokemon(char Pokemon_name[][11], pokemon Pokemons[], pokemon *my_pocket);		//To release Pokemons from pocket.
void battle(char Pokemon_name[][11], int range[], attack_type type[], int attack_power[], int stamina[], pokemon user_Pokemons[]);		//To battle in the area.
void show_area (char Pokemon_name[][11],int area[8][8],int pokemon_staminas_view[8][8]);		//To show the battle.

int compare(char Pokemon_name[][11],char Name[]);		//Auxilary function to pokedex function.

int main()		//Start of main.
{
	srand(time(NULL));		//To create random number.
	cleaner();	
	menu();

	return 0;
}		//End of main.
void menu()		//Start of menu.
{
	char Pokemon_name[10][11]={
			{"Charmander"},
			{"Pikachu"},
			{"Squirtle"},
			{"Bulbasaur"},
			{"Pidgeotto"},
			{"Ratata"},
			{"Mug"},
			{"Caterpie"},
			{"Zubat"},
			{"Krabby"},
		};
	
	attack_type type[10]={
					quadratic,
					linear,
					linear,
					linear,
					quadratic,
					linear,
					quadratic,
					quadratic,
					quadratic,
					linear
				};
	int range[10]={1,3,4,3,2,2,1,2,3,2};
	int attack_power[10]={500,350,300,400,250,250,350,200,350,300};
	int stamina[10]={2200,1500,1700,2500,1900,2500,3000,1200,1250,2600};
	pokemon Pokemons[4];		//Keeps Pokemons.
	pokemon my_Pokemons=0;		//Keeps Pokemons number.
	pokemon user_Pokemons[4];	//Changable Pokemon array.
	
	int choice=0;

	while(choice!=4)		//Start of while loop.
	{	
		choice=0;
		printf("\nPlease select an option to continue:\n\n");
		printf("1) Open Pokedex\n");
		printf("2) Go to Oak's Laboratory\n");
		printf("3) Enter the tournament\n");
		printf("4) Exit\n");
		printf("\nYour Selection: ");
		scanf("%d",&choice);
		getchar();
		switch(choice){		//Start of switch-case.
			case 1: {		//Start of pokedex.	
				cleaner();
				pokedex(Pokemon_name, range, type, attack_power, stamina);
				cleaner();  break;
			}		//End of pokedex.
			case 2: {		//Start of Oak's laboratory. 
				cleaner();
				oaks_laboratory(Pokemon_name, Pokemons, &my_Pokemons);
				cleaner();  break;
			}		//End of Oak's laboratory.
			case 3: {		//Start of battle.
				cleaner();
				if(my_Pokemons!=4) printf("You must have four Pokémons !\n");
				else{
					for (int i = 0; i < 4; ++i) user_Pokemons[i]=Pokemons[i];
					battle(Pokemon_name, range, type, attack_power, stamina,user_Pokemons);
					printf("\nPress enter to return to menu..\n");
					getchar(); 
					cleaner();
				}  break;
			}		//End of battle.
			case 4: {		//This case just for exit.
				printf("\nExiting..\n"); break;		
			}
				default: 	//Used to warning for invalid choice in general menu function.
					cleaner();
					printf("\nThis is an invalid choice. Try again!\n");  break; 
		}		//End of switch-case.
	}		//End of while loop.
}
void oaks_laboratory(char Pokemon_name[][11], pokemon Pokemons[], pokemon *my_Pokemons){		//Start of Oak's labrotory.
	int pokemon_count=0;		//To use in show_pokemons function. Keeps Pokemon number.
	pokemon my_pocket=*my_Pokemons;	
	int choice=0;

	while(choice!=5)		//Start of while loop.
	{	
		choice=0;
		printf("\nWelcome to Laboratory of Professor Oak. How can I help you?\n");
		printf("  1) Show Pokémons\n");
		printf("  2) Catch a Pokémon\n");
		printf("  3) Release a Pokémon\n");
		printf("  4) Show my pocket\n");
		printf("  5) Back\n");
		printf("\nYour Selection: ");
		scanf("%d",&choice);
		getchar();
		switch(choice){		//Start of switch-case.
			case 1: {		//Start of show pokemons.
				cleaner();
				pokemon_count=10;
				show_Pokemons(Pokemon_name, Pokemons, pokemon_count);
				break;
			}		//End of show_pokemons.
			case 2: {		//Start of catch a pokemon.
				cleaner();
				pokemon_count=10;
				if(my_pocket==4) printf("\nYou can not catch more Pokémon !\n");
				else {
					show_Pokemons(Pokemon_name, Pokemons, pokemon_count);
					catch_a_pokemon(Pokemon_name, Pokemons, &my_pocket);
					cleaner();
				}	break;
			}		//End of catch a pokemon.
			case 3: {		//Start of release a pokemon.
				cleaner();
				pokemon_count=my_pocket;
				if(my_pocket==0) printf("You have not any Pokémon !\n");
				else {
					show_Pokemons(Pokemon_name, Pokemons, pokemon_count);
					release_a_pokemon(Pokemon_name, Pokemons, &my_pocket);
					cleaner();
				}	break;
			}		//End of release a pokemon.
			case 4: {		//Start of show pocket.
				cleaner();
				pokemon_count=my_pocket;
				if(my_pocket==0) printf("You have not any Pokémon !\n");
				else {
					show_Pokemons(Pokemon_name, Pokemons, pokemon_count);
				}	break;
			}		//End of show pocket.
			case 5: {		//This case for swap and exit.
				*my_Pokemons=my_pocket;	break;		
			}
				default: 	//Used to warning for invalid choice in general menu function.
					cleaner();
					printf("\nThis is an invalid choice. Try again!\n");  break; 
		}		//End of switch-case.
	}		//End of while loop.
}		//End od Oak's labarotory.
void pokedex(char Pokemon_name[][11], int range[], attack_type type[], int attack_power[], int stamina[])		//Start of pokedex.
{
	char Name[11],Exit[2][11]={{"exit"},{"Exit"}};		//Exit array.
	int check=-1,exit=-1;
	while(exit==-1){	//Start of while loop.
		printf("\nPlease type name of the Pokémon (type exit to close Pokedex): \n\n");
		scanf("%s",Name);
		check=compare(Pokemon_name,Name);
		exit=compare(Exit,Name);
		cleaner();
		if (check==-1) {	//If entered wrong name.
			printf("\nThere is no such Pokemon. Try Again !\n");	
		}
		else{		//If entered a right name.
			printf("\nName     : %s\n",Pokemon_name[check] );
			if (type[check]==quadratic) printf("A. Type  : Quadratic\n");
			else if (type[check]==linear) printf("A. Type  : Linear\n");
			printf("Range    : %d block\n",range[check] );
			printf("A. Power : %d\n",attack_power[check] );
			printf("Stamina  : %d\n",stamina[check] );
		}
	}	//End of while loop.
}		//End of pokedex.
void show_Pokemons(char Pokemon_name[][11], pokemon Pokemons[], int pokemon_count)	//Start of show pokemons.
{	printf("\n");
	if(pokemon_count==10){
		for (int i = 0; i < 10; ++i)	printf("%d - %s\n",i,Pokemon_name[i]);
	}
	else {
		printf("Your pocket:\n\n");
		for (int i = 0; i < pokemon_count ;  ++i)	printf("%d - %s\n",i,Pokemon_name[Pokemons[i]] );		
	}
}	//End of show pokemons.
void catch_a_pokemon(char Pokemon_name[][11], pokemon Pokemons[], pokemon *my_pocket)		//Start of catch a pokemon.
{	int choice=-1;
	
	while(choice<0 || choice>9){	//Start of while loop for catch a pokemon.
		printf("\nCatch a Pokémon: ");
		scanf("%d",&choice);
		getchar();
		if(*my_pocket==1 && Pokemons[0]==choice) choice=-1;
		else if(*my_pocket==2 && (Pokemons[0]==choice || Pokemons[1]==choice)) choice=-1;
		else if(*my_pocket==3 && (Pokemons[0]==choice || Pokemons[1]==choice || Pokemons[2]==choice)) choice=-1;
		if (choice<0 || choice>9) printf("\nYou can not catch this Pokemon. Try Again !\n");
	}	//End of while loop.
	Pokemons[*my_pocket]=choice;
	*my_pocket+=1;
}		//End of catch a pokemon.
void release_a_pokemon(char Pokemon_name[][11], pokemon Pokemons[], pokemon *my_pocket)		//Start of release a pokemon
{	int choice=-1;

	while(choice<0 || choice>=*my_pocket){		//Start of while loop for release a pokemon.
		printf("\nRelease a Pokémon: ");
		scanf("%d",&choice);
		getchar();
		if (choice<0 || choice>=*my_pocket) printf("\nInvalid value. Try Again !\n");
		else {
			for (int i = 0; i < 4; ++i){
				if(i>=choice)	Pokemons[i]=Pokemons[i+1];
			}
		}
	}	//End of while loop.
	*my_pocket-=1;
}		//End of release pokemon.
void battle(char Pokemon_name[][11], int range[], attack_type type[], int attack_power[], int stamina[], pokemon user_Pokemons[])		//Start of battle.
{	int area[8][8], pokemon_staminas_view[8][8];
	int x=0, y=0, over=4,choose=0,live=4,flag=0,p=0;
	pokemon pc_Pokemons[4];
	int user_coordinates[4][2], pc_coordinates[4][2];		//To keep coordinates of user and pc.
	
	printf("			RULES OF TOURNAMENT\n\n");
	printf("1) The board has a size of 8x8 between the coordinates [0 0] and [7 7].\n");
	printf("2) You can only move linearly and 0,1 or 2 blocks. \n");
	printf("3) 'x' is horizontal and 'y' is vertical movement.\n");
	printf("4) Example of entering coordinates for from (0 0) to (0 2) is below:\n\n");
	printf("=>	Enter started/new coordinates of Pokémon (0 0): 0 2\n");
	
	printf("\nGame was started..\n\n");

	for (int i = 0; i < 8; ++i)		//To fill area and stamina arrays.
	{	for (int l = 0; l < 8; ++l)
		{
			area[i][l]=-1;
			pokemon_staminas_view[i][l]=-1;
		}
	}
	for (int i = 0; i < 4; ++i)		//To place the pokemons of user.
	{	
		printf("\nEnter started coordinates of %s: ",Pokemon_name[user_Pokemons[i]]);
		scanf("%d %d",&x,&y);
		getchar();
		user_coordinates[i][0]=x;
		user_coordinates[i][1]=y;
		if((x<0 || x>7) || (y<0 || y>1)){
			printf("\nWrong started coordinate! Try again !\n");
			i--;	
		}
		else if(area[y][x]!=-1){
			printf("\nThis coordinate is fill. Try again !\n\n");
			i--;
		}		
		else {
			area[y][x]=user_Pokemons[i];
			pokemon_staminas_view[y][x]=stamina[user_Pokemons[i]];
		}
	}
	for (int i = 0; i < 4; ++i)		//To place the pokemons of pc.
	{	
		pc_Pokemons[i]=rand()%10;
		x=rand()%8;
		y=rand()%2+6;
		pc_coordinates[i][0]=x;
		pc_coordinates[i][1]=y;
		if(i>0 && pc_Pokemons[i]==pc_Pokemons[i-1])	i--;
		else if(i>1 && pc_Pokemons[i]==pc_Pokemons[i-2])	i--;
		else if(i>2 && pc_Pokemons[i]==pc_Pokemons[i-3])	i--;
		else if(area[y][x]!=-1)	i--;		
		else {
			area[y][x]=pc_Pokemons[i];
			pokemon_staminas_view[y][x]=stamina[pc_Pokemons[i]];
		}
	}
	cleaner();
	show_area (Pokemon_name, area, pokemon_staminas_view);
	while(over!=0 && live!=0)		//Start of while loop. It won't stop until anyone wins.
	{
		x=0; y=0;
		for (int i = 0; i < 2; ++i)		//To each movement.
		{	
			if(i==0 && live!=0)		//Start of movement of user.
			{	
				for (int k = 0; k < live; ++k) printf(" %d - %s	(%d %d)	H: %d\n",k,Pokemon_name[user_Pokemons[k]],user_coordinates[k][0],user_coordinates[k][1],pokemon_staminas_view[user_coordinates[k][1]][user_coordinates[k][0]]);
				flag=1;
				while(flag==1)
				{	
					flag=0;
					printf("\nChose a Pokémon: ");
					scanf("%d",&choose);
					getchar();
					if(choose<0 || choose>=live)  { printf("\nYou have %d Pokémons. Try again !\n",live); flag=1;}
				}
				flag=1;
				while(flag==1)
				{	
					flag=0;
					printf("\nEnter new coordinates of %s(%d %d): ",Pokemon_name[user_Pokemons[choose]],user_coordinates[choose][0],user_coordinates[choose][1]);
					scanf("%d %d",&x,&y);
					getchar();
					if((x<0 || x>7) || (y<0 || y>7)) { printf("Coordinates must be defined in board ! Try again !\n"); flag=1; }
					else if(abs(user_coordinates[choose][0]-x)>0 && abs(user_coordinates[choose][1]-y)>0){
						printf("\nYou can move just linear ! \n"); 
						flag=1;
					}
					else if(abs(user_coordinates[choose][0]-x)>2 || abs(user_coordinates[choose][1]-y)>2) { 
						printf("\nYou can move two blocks maximum ! \n"); 
						flag=1;
					}
					else if(area[y][x]!=-1 && !(user_coordinates[choose][0]==x && user_coordinates[choose][1]==y)){
						printf("\nYou can not move there ! \n");
						flag=1;
					}
					else if(!(user_coordinates[choose][0]==x && user_coordinates[choose][1]==y)){
						area[y][x]=user_Pokemons[choose];
						pokemon_staminas_view[y][x]=pokemon_staminas_view[user_coordinates[choose][1]][user_coordinates[choose][0]];
						area[user_coordinates[choose][1]][user_coordinates[choose][0]]=-1;
						pokemon_staminas_view[user_coordinates[choose][1]][user_coordinates[choose][0]]=-1;
						user_coordinates[choose][0]=x;
						user_coordinates[choose][1]=y;

					}
				}
				cleaner();
				
				if(type[user_Pokemons[choose]]==1){
					p=-1;
					for (int k = 0; k < over; ++k)
					{
						if (abs(user_coordinates[choose][0]-pc_coordinates[k][0])<=range[user_Pokemons[choose]] && abs(user_coordinates[choose][1]-pc_coordinates[k][1])==0){
							pokemon_staminas_view[pc_coordinates[k][1]][pc_coordinates[k][0]]-=attack_power[user_Pokemons[choose]];
							p=k;
							printf("\n(USER ATTACK) -> %s to %s\n\n",Pokemon_name[user_Pokemons[choose]],Pokemon_name[pc_Pokemons[p]]);
							break;
						}
						else if(abs(user_coordinates[choose][1]-pc_coordinates[k][1])<=range[user_Pokemons[choose]] && abs(user_coordinates[choose][0]-pc_coordinates[k][0])==0){
							pokemon_staminas_view[pc_coordinates[k][1]][pc_coordinates[k][0]]-=attack_power[user_Pokemons[choose]];
							p=k;
							printf("\n(USER ATTACK) -> %s to %s\n\n",Pokemon_name[user_Pokemons[choose]],Pokemon_name[pc_Pokemons[p]]);
							break;
						}
					}
					if(p!=-1 && pokemon_staminas_view[pc_coordinates[p][1]][pc_coordinates[p][0]]<=0){
						area[pc_coordinates[p][1]][pc_coordinates[p][0]]=-1;
						pokemon_staminas_view[pc_coordinates[p][1]][pc_coordinates[p][0]]=-1;
						for (int l = 0; l < over; ++l){
							if(l>=p){
								pc_Pokemons[l]=pc_Pokemons[l+1];
								pc_coordinates[l][0]=pc_coordinates[l+1][0];
								pc_coordinates[l][1]=pc_coordinates[l+1][1];
							}
						}
						over--;
					}
				}
				else if(type[user_Pokemons[choose]]==0){
					
					for (int k = 0; k < over; ++k)
					{	
						p=-1;
						if (abs(user_coordinates[choose][0]-pc_coordinates[k][0])<=range[user_Pokemons[choose]] && abs(user_coordinates[choose][1]-pc_coordinates[k][1])==0){
							pokemon_staminas_view[pc_coordinates[k][1]][pc_coordinates[k][0]]-=attack_power[user_Pokemons[choose]];
							p=k;
							printf("\n(USER ATTACK) -> %s to %s\n\n",Pokemon_name[user_Pokemons[choose]],Pokemon_name[pc_Pokemons[p]]);
						}
						else if(abs(user_coordinates[choose][1]-pc_coordinates[k][1])<=range[user_Pokemons[choose]] && abs(user_coordinates[choose][0]-pc_coordinates[k][0])==0){
							pokemon_staminas_view[pc_coordinates[k][1]][pc_coordinates[k][0]]-=attack_power[user_Pokemons[choose]];
							p=k;
							printf("\n(USER ATTACK) -> %s to %s\n\n",Pokemon_name[user_Pokemons[choose]],Pokemon_name[pc_Pokemons[p]]);
						}
						
						if(p!=-1 && pokemon_staminas_view[pc_coordinates[p][1]][pc_coordinates[p][0]]<=0){
						area[pc_coordinates[p][1]][pc_coordinates[p][0]]=-1;
						pokemon_staminas_view[pc_coordinates[p][1]][pc_coordinates[p][0]]=-1;
						for (int l = 0; l < over; ++l){
							if(l>=p){
								pc_Pokemons[l]=pc_Pokemons[l+1];
								pc_coordinates[l][0]=pc_coordinates[l+1][0];
								pc_coordinates[l][1]=pc_coordinates[l+1][1];
							}
						}
						over--;
						}
					}
				}	
				show_area (Pokemon_name, area, pokemon_staminas_view);
				printf("Press enter to see to move of AI ..\n");
				getchar();
			}		//End of movement of user.
			if (i==1 && over!=0)		//Start of movement of AI.
			{	
				flag=1;
				choose=rand()%over;
				while(flag==1){	
					flag=0;
					x=rand()%8;
					y=rand()%8;
	
					if((x<0 || x>7) || (y<0 || y>7))  flag=1; 
					else if(abs(pc_coordinates[choose][0]-x)>0 && abs(pc_coordinates[choose][1]-y)>0){ 
						flag=1;
					}
					else if(abs(pc_coordinates[choose][0]-x)>2 || abs(pc_coordinates[choose][1]-y)>2) { 
						flag=1;
					}
					else if(area[y][x]!=-1 && !(pc_coordinates[choose][0]==x && pc_coordinates[choose][1]==y)){
						flag=1;
					}
					else if(!(pc_coordinates[choose][0]==x && pc_coordinates[choose][1]==y)){
						area[y][x]=pc_Pokemons[choose];
						pokemon_staminas_view[y][x]=pokemon_staminas_view[pc_coordinates[choose][1]][pc_coordinates[choose][0]];
						area[pc_coordinates[choose][1]][pc_coordinates[choose][0]]=-1;
						pokemon_staminas_view[pc_coordinates[choose][1]][pc_coordinates[choose][0]]=-1;
						pc_coordinates[choose][0]=x;
						pc_coordinates[choose][1]=y;
					}
				}
				cleaner();
				
				if(type[pc_Pokemons[choose]]==1){
					p=-1;
					for (int k = 0; k < live; ++k)
					{
						if (abs(pc_coordinates[choose][0]-user_coordinates[k][0])<=range[pc_Pokemons[choose]] && abs(pc_coordinates[choose][1]-user_coordinates[k][1])==0){
							pokemon_staminas_view[user_coordinates[k][1]][user_coordinates[k][0]]-=attack_power[pc_Pokemons[choose]];
							p=k;
							printf("\n(AI ATTACK) -> %s to %s\n\n",Pokemon_name[pc_Pokemons[choose]],Pokemon_name[user_Pokemons[p]]);
							break;
						}
						else if(abs(pc_coordinates[choose][1]-user_coordinates[k][1])<=range[pc_Pokemons[choose]] && abs(pc_coordinates[choose][0]-user_coordinates[k][0])==0){
							pokemon_staminas_view[user_coordinates[k][1]][user_coordinates[k][0]]-=attack_power[pc_Pokemons[choose]];
							p=k;
							printf("\n(AI ATTACK) -> %s to %s\n\n",Pokemon_name[pc_Pokemons[choose]],Pokemon_name[user_Pokemons[p]]);
							break;
						}
					}
					if(p!=-1 && pokemon_staminas_view[user_coordinates[p][1]][user_coordinates[p][0]]<=0){
						area[user_coordinates[p][1]][user_coordinates[p][0]]=-1;
						pokemon_staminas_view[user_coordinates[p][1]][user_coordinates[p][0]]=-1;
						for (int l = 0; l < live; ++l){
							if(l>=p){
								user_Pokemons[l]=user_Pokemons[l+1];
								user_coordinates[l][0]=user_coordinates[l+1][0];
								user_coordinates[l][1]=user_coordinates[l+1][1];
							}
						}
						live--;
					}	
				}
				else if(type[pc_Pokemons[choose]]==0){
					
					for (int k = 0; k < live; ++k)
					{	
						p=-1;
						if (abs(pc_coordinates[choose][0]-user_coordinates[k][0])<=range[pc_Pokemons[choose]] && abs(pc_coordinates[choose][1]-user_coordinates[k][1])==0){
							pokemon_staminas_view[user_coordinates[k][1]][user_coordinates[k][0]]-=attack_power[pc_Pokemons[choose]];
							p=k;
							printf("\n(AI ATTACK) -> %s to %s\n\n",Pokemon_name[pc_Pokemons[choose]],Pokemon_name[user_Pokemons[p]]);
						}
						else if(abs(pc_coordinates[choose][1]-user_coordinates[k][1])<=range[pc_Pokemons[choose]] && abs(pc_coordinates[choose][0]-user_coordinates[k][0])==0){
							pokemon_staminas_view[user_coordinates[k][1]][user_coordinates[k][0]]-=attack_power[pc_Pokemons[choose]];
							p=k;
							printf("\n(AI ATTACK) -> %s to %s\n\n",Pokemon_name[pc_Pokemons[choose]],Pokemon_name[user_Pokemons[p]]);
						}
						
						if(p!=-1 && pokemon_staminas_view[user_coordinates[p][1]][user_coordinates[p][0]]<=0){
						area[user_coordinates[p][1]][user_coordinates[p][0]]=-1;
						pokemon_staminas_view[user_coordinates[p][1]][user_coordinates[p][0]]=-1;
						for (int l = 0; l < live; ++l){
							if(l>=p){
								user_Pokemons[l]=user_Pokemons[l+1];
								user_coordinates[l][0]=user_coordinates[l+1][0];
								user_coordinates[l][1]=user_coordinates[l+1][1];
							}
						}
						live--;
						}
					}
				}				
				show_area (Pokemon_name, area, pokemon_staminas_view);
			}		//End of movement of AI.
		}	
	}
	if(over==0) printf("\nYOU WIN !\n");
	else if(live==0) printf("\nAI WIN !\n");
}
void show_area (char Pokemon_name[][11],int area[8][8],int pokemon_staminas_view[8][8])		//Start of show area.
{	
	printf("\n");
	for (int j = 0; j < 8; ++j)
	{
		for (int k = 0; k < 8; ++k)
		{
			printf("|");
			if(area[j][k]==-1) printf("      ");
			else printf("  %.2s  ",Pokemon_name[area[j][k]]);
		}
		printf("|\n");
		for (int k = 0; k < 8; ++k)
		{
			printf("|");
			if(area[j][k]==-1) printf("      ");
			else printf("(%4d)",pokemon_staminas_view[j][k]);
		}
		printf("|\n");
		if(j!=7){
			for (int k = 0; k < 8; ++k)
			{
				printf("-------");
			}
			printf("-\n");
		}
	}
	printf("\n");
}		//End of show area.
int compare(char Pokemon_name[][11],char Name[])		//Start of compare.
{	
	int i=0, k=0, flag=1,a=0;
	
	for (k = 0; k < 10; k++){	
		while(flag==1 && (Name[i]!='\0' || Pokemon_name[k][i]!='\0')){
			if(Pokemon_name[k][i]==Name[i]) {  i++; } 
			else flag=0;
			a++;
		}
		i=0;
		if(flag==1) return k;
		else flag=1;
	}
	return -1;
}		//End of compare.
