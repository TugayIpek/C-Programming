#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define cleaner(); printf("\e[1;1H\e[2J"); // to cleaning terminal

typedef enum {noone, cap, car} Player_type;
typedef enum {start, property, tax, punish} block_type;

struct player{
	Player_type type;
	int current_block_id;
	int owned_block_ids[11];
	int account;
	int turn_to_wait;
	char *name;
};
struct block{
	int block_id;
	char *name;
	int price;
	int rent;
	int rent_1;
	int rent_2;
	int rent_3;
	int house_price;
	int house_count;
	struct player owner;
	block_type type;
};

void init_the_board(struct block board[20]);
void show_board(struct block board[20], struct player player_one, struct player player_two);
void show_properties(struct block board[20]);
void buy_property(struct block *current_block, struct player *current_player);
void sell_property(struct block board[20], struct player *current_player);
void gameplay(struct block board[20], struct player player_one, struct player player_two);

int main(){
	
	srand(time(NULL));
	struct block board[20];
	struct player player_one;
	struct player player_two;

	init_the_board(board);
	gameplay(board, player_one, player_two);

	return 0;
}
void init_the_board(struct block board[20]){	//created detail and long to be understandable and interchangable.

	board[0].block_id = 0;
	board[0].name = "Start";
	board[0].price = 0;
	board[0].rent = 0;
	board[0].rent_1 = 0;
	board[0].rent_2 = 0;
	board[0].rent_3 = 0;
	board[0].house_price = 0;
	board[0].owner.type = noone;
	board[0].house_count = 0;
	board[0].type = start;

	board[1].block_id = 1;
	board[1].name = "Esenyurt";
	board[1].price = 16000;
	board[1].rent = 800;
	board[1].rent_1 = 4000;
	board[1].rent_2 = 9000;
	board[1].rent_3 = 25000;
	board[1].house_price = 10000;
	board[1].owner.type = noone;
	board[1].house_count = 0;
	board[1].type = property;

	board[2].block_id = 2;
	board[2].name = "Car Park";
	board[2].price = 1500;
	board[2].rent = 0;
	board[2].rent_1 = 0;
	board[2].rent_2 = 0;
	board[2].rent_3 = 0;
	board[2].house_price = 0;
	board[2].owner.type = noone;
	board[2].house_count = 0;
	board[2].type = tax;

	board[3].block_id = 3;
	board[3].name = "Tuzla";
	board[3].price = 16500;
	board[3].rent = 850;
	board[3].rent_1 = 4250;
	board[3].rent_2 = 9500;
	board[3].rent_3 = 26000;
	board[3].house_price = 12000;
	board[3].owner.type = noone;
	board[3].house_count = 0;
	board[3].type = property;

	board[4].block_id = 4;
	board[4].name = "Arnavutkoy";
	board[4].price = 17000;
	board[4].rent = 875;
	board[4].rent_1 = 4500;
	board[4].rent_2 = 10000;
	board[4].rent_3 = 28000;
	board[4].house_price = 12000;
	board[4].owner.type = noone;
	board[4].house_count = 0;
	board[4].type = property;

	board[5].block_id = 5;
	board[5].name = "Wait 2 Turn";
	board[5].price = 0;
	board[5].rent = 2;
	board[5].rent_1 = 0;
	board[5].rent_2 = 0;
	board[5].rent_3 = 0;
	board[5].house_price = 0;
	board[5].owner.type = noone;
	board[5].house_count = 0;
	board[5].type = punish;

	board[6].block_id = 6;
	board[6].name = "Catalca";
	board[6].price = 20000;
	board[6].rent = 1000;
	board[6].rent_1 = 5000;
	board[6].rent_2 = 12000;
	board[6].rent_3 = 30000;
	board[6].house_price = 13000;
	board[6].owner.type = noone;
	board[6].house_count = 0;
	board[6].type = property;

	board[7].block_id = 7;
	board[7].name = "Beykoz";
	board[7].price = 23000;
	board[7].rent = 1100;
	board[7].rent_1 = 5500;
	board[7].rent_2 = 12500;
	board[7].rent_3 = 33000;
	board[7].house_price = 13000;
	board[7].owner.type = noone;
	board[7].house_count = 0;
	board[7].type = property;

	board[8].block_id = 8;
	board[8].name = "Car Fix";
	board[8].price = 1750;
	board[8].rent=  0;
	board[8].rent_1 = 0;
	board[8].rent_2 = 0;
	board[8].rent_3 = 8;
	board[8].house_price = 8;
	board[8].owner.type = noone;
	board[8].house_count = 0;
	board[8].type = tax;

	board[9].block_id = 9;
	board[9].name = "Maltepe";
	board[9].price = 30000;
	board[9].rent = 1350;
	board[9].rent_1 = 7000;
	board[9].rent_2 = 15000;
	board[9].rent_3 = 40000;
	board[9].house_price = 15000;
	board[9].owner.type = noone;
	board[9].house_count = 0;
	board[9].type = property;

	board[10].block_id = 10;
	board[10].name = "Bills";
	board[10].price = 2000;
	board[10].rent = 0;
	board[10].rent_1 = 0;
	board[10].rent_2 = 0;
	board[10].rent_3 = 0;
	board[10].house_price = 0;
	board[10].owner.type = noone;
	board[10].house_count = 0;
	board[10].type = tax;

	board[11].block_id = 11;
	board[11].name = "Sisli";
	board[11].price = 33000;
	board[11].rent = 1500;
	board[11].rent_1 = 8000;
	board[11].rent_2 = 16000;
	board[11].rent_3 = 42000;
	board[11].house_price = 16000;
	board[11].owner.type = noone;
	board[11].house_count = 0;
	board[11].type = property;

	board[12].block_id = 12;
	board[12].name = "Oil";
	board[12].price = 2250;
	board[12].rent = 0;
	board[12].rent_1 = 0; 
	board[12].rent_2 = 0;
	board[12].rent_3 = 0;
	board[12].house_price = 0;
	board[12].owner.type = noone;
	board[12].house_count = 0;
	board[12].type = tax;

	board[13].block_id = 13;
	board[13].name = "Atasehir";
	board[13].price = 35000;
	board[13].rent = 1600;
	board[13].rent_1 =8500;
	board[13].rent_2 = 17000;
	board[13].rent_3 = 45000;
	board[13].house_price = 17000;
	board[13].owner.type = noone;
	board[13].house_count = 0;
	board[13].type = property;

	board[14].block_id = 14;
	board[14].name = "Sariyer";
	board[14].price = 40000;
	board[14].rent = 1750;
	board[14].rent_1 = 9500;
	board[14].rent_2 = 19000;
	board[14].rent_3 = 48000;
	board[14].house_price = 19000;
	board[14].owner.type = noone;
	board[14].house_count = 0;
	board[14].type = property;

	board[15].block_id = 15;
	board[15].name = "Wait 1 Turn";
	board[15].price = 0;
	board[15].rent = 1;
	board[15].rent_1 = 0;
	board[15].rent_2 = 0;
	board[15].rent_3 = 0;
	board[15].house_price = 0;
	board[15].owner.type = noone;
	board[15].house_count = 0;
	board[15].type = punish;

	board[16].block_id = 16;
	board[16].name = "Kadikoy";
	board[16].price = 43000;
	board[16].rent = 1900;
	board[16].rent_1 = 11000;
	board[16].rent_2 = 21500;
	board[16].rent_3 = 55000;
	board[16].house_price = 23000;
	board[16].owner.type = noone;
	board[16].house_count = 0;
	board[16].type = property;

	board[17].block_id = 17;
	board[17].name = "Besiktas";
	board[17].price = 60000;
	board[17].rent = 2500;
	board[17].rent_1 = 15000;
	board[17].rent_2 = 28000;
	board[17].rent_3 = 60000;
	board[17].house_price = 30000;
	board[17].owner.type = noone;
	board[17].house_count = 0;
	board[17].type = property;

	board[18].block_id = 18;
	board[18].name = "Vocation";
	board[18].price = 5000;
	board[18].rent = 0;
	board[18].rent_1 = 0;
	board[18].rent_2 = 0;
	board[18].rent_3 = 0;
	board[18].house_price = 0;
	board[18].owner.type = noone;
	board[18].house_count = 0;
	board[18].type = tax;

	board[19].block_id = 19;
	board[19].name = "Bebek";
	board[19].price = 70000;
	board[19].rent = 3500;
	board[19].rent_1 = 20000;
	board[19].rent_2 = 35500;
	board[19].rent_3 = 65500;
	board[19].house_price = 35000;
	board[19].owner.type = noone;
	board[19].house_count = 0;
	board[19].type = property;
}
void show_board(struct block board[20], struct player player_one, struct player player_two){		//it can be resolution problem because it is made using tabs(\t).
	cleaner();
	int count = 0;
	printf("\t\t\t\t\t\t\t***	MONOPOLY ISTANBUL	***\n\n");
	printf("\n-");
	for (int j = 0; j < 6; ++j)
	{
		if(j == 0)		// prints the top of the board
		{	
			for (int k = 0; k < 6; ++k)
				printf("------------------------");
		
			printf("\n|");
			for (int i = 0; i < 6; ++i)
			{
				printf("\t%-16s|",board[i].name);
			}
			printf("\n|");
			for (int l = 0; l < 6; ++l)
			{
				if(board[l].type == property || board[l].type == tax) 
					printf("\t%d$\t\t|",board[l].price );
				else printf("\t%-16s|","" );
			}
			printf("\n|");
			for (int t = 0; t < 6; ++t)
			{
				if( player_one.current_block_id == t && player_two.current_block_id == t){
					printf("\t%s /",player_one.name);
					printf(" %s\t|",player_two.name);
				}
				else if(player_one.current_block_id == t){
					printf("\t%-16s|",player_one.name );
				}
				else if(player_two.current_block_id == t){
					printf("\t%-16s|",player_two.name );
				}
				else printf("\t\t\t|");
			}	
			printf("\n");
			for (int k = 0; k < 6; ++k)
				printf("------------------------");
			printf("-\n");
		}
		else if(j == 5){		// prints the bottom of the board
			printf("-");
			for (int k = 15; k > 9; --k)
				printf("------------------------");
		
			printf("\n|");
			for (int i = 15; i > 9; --i)
			{
				printf("\t%-16s|",board[i].name);
			}
			printf("\n|");
			for (int l = 15; l > 9; --l)
			{
				if(board[l].type == property || board[l].type == tax) 
					printf("\t%d$\t\t|",board[l].price );
				else printf("\t%-16s|","" );
			}
			printf("\n|");
			for (int t = 15; t > 9; --t)
			{
				if( player_one.current_block_id == t && player_two.current_block_id == t){
					printf("\t%s /",player_one.name);
					printf(" %s\t|",player_two.name);
				}
				else if(player_one.current_block_id == t){
					printf("\t%-16s|",player_one.name);
				}
				else if(player_two.current_block_id == t){
					printf("\t%-16s|",player_two.name);
				}
				else printf("\t\t\t|");
			}	
			printf("\n");
			for (int k = 15; k > 9; --k)
				printf("------------------------");
			printf("-\n");
		}
		else{		// prints the middle of the board
			printf("|\t%-16s|",board[19-count].name);
			printf("\t\t\t\t\t\t\t\t\t\t\t\t");
			printf("|\t%-16s|\n|",board[6+count].name);
			if(board[19-count].type == property || board[19-count].type == tax) 
				printf("\t%d$\t\t|",board[19-count].price );
			else printf("\t%-16s|","" );
			printf("\t\t\t\t\t\t\t\t\t\t\t\t|");
			if(board[6+count].type == property || board[6+count].type == tax) 
				printf("\t%d$\t\t|\n|",board[6+count].price );
			else printf("\t%-16s|\n|","" );

			if(player_one.current_block_id == 19-count && player_two.current_block_id == 19-count){
				printf("\t%s /",player_one.name);
				printf(" %s\t|",player_two.name);
				printf("\t\t\t\t\t\t\t\t\t\t\t\t|\t\t\t|\n");
			}
			else if(player_one.current_block_id == 6+count && player_two.current_block_id == 6+count){
				printf("\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t");
				printf("|\t%s /",player_one.name);
				printf(" %s\t|\n",player_two.name);
			}
			else if (player_one.current_block_id == 19-count && player_two.current_block_id == 6+count){
				printf("\t%s\t\t|",player_one.name);
				printf("\t\t\t\t\t\t\t\t\t\t\t\t");
				printf("|\t%s\t\t|\n",player_two.name);
			}
			else if (player_one.current_block_id == 6+count && player_two.current_block_id == 19-count){
				printf("\t%s\t\t|",player_one.name);
				printf("\t\t\t\t\t\t\t\t\t\t\t\t");
				printf("|\t%s\t\t|\n",player_two.name);	
			}
			else{
				if(player_one.current_block_id == 19-count){
					printf("\t%s\t\t|",player_one.name);
					printf("\t\t\t\t\t\t\t\t\t\t\t\t|\t\t\t|\n");
				}
				if(player_one.current_block_id == 6+count ){
					printf("\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t|");
					printf("\t%s\t\t|\n",player_one.name);
					
				}
				if(player_two.current_block_id == 19-count ){
					printf("\t%s\t\t|",player_two.name);
					printf("\t\t\t\t\t\t\t\t\t\t\t\t|\t\t\t|\n");
				}
				if(player_two.current_block_id == 6+count){
					printf("\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t|");
					printf("\t%s\t\t|\n",player_two.name);
				}
			}
			if(player_one.current_block_id != 19-count &&
				player_one.current_block_id != 6+count &&
				player_two.current_block_id != 19-count &&
				player_two.current_block_id != 6+count ){
					printf("\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t|\t\t\t|\n");
				}
			count++;
			if(count != 4){
				printf("-------------------------");
				printf("\t\t\t\t\t\t\t\t\t\t\t\t");
				printf("-------------------------\n");
			}		
		}
	}
	printf("\n");
}
void show_properties(struct block board[20]){
	int choice = 1;
	cleaner();
	while(choice != 0){
		printf("\nPlease select property to see details:\n");
		printf("1 -	%s\n",board[1].name );
		printf("4 -	%s\n",board[4].name );
		printf("6 -	%s\n",board[6].name );
		printf("7 -	%s\n",board[7].name );
		printf("9 -	%s\n",board[9].name );
		printf("11 -	%s\n",board[11].name );
		printf("13 -	%s\n",board[13].name );
		printf("14 -	%s\n",board[14].name );
		printf("17 -	%s\n",board[17].name );
		printf("19 -	%s\n",board[19].name );
		printf("0 -	Exit\n");
		printf("Choice: ");
		scanf(" %d",&choice);
		getchar();
		cleaner();
		if(choice<=19 && choice>=0 && choice !=0 && choice !=2 && choice !=3 && choice !=5 
			&& choice !=8 && choice !=10 && choice !=12 && choice !=15 && choice !=18 && choice != 16){
			printf("---------------------------------\n");
			printf("|\t    %s\t\t|\n",board[choice].name );
			printf("---------------------------------\n");
			printf("|\tRent\t\t%d$\t|\n",board[choice].rent);
			printf("|\tRent 1H\t\t%d$\t|\n",board[choice].rent_1);
			printf("|\tRent 2H\t\t%d$\t|\n",board[choice].rent_2);
			printf("|\tRent 3H\t\t%d$\t|\n",board[choice].rent_3);
			printf("---------------------------------\n");
			printf("|\tHouse Price\t%d$\t|\n",board[choice].house_price);
			printf("---------------------------------\n\n");
		}
		else if(choice != 0){
			printf("You made a wrong choice ! Try Again !\n\n");
		}
	}
}
void buy_property(struct block *current_block, struct player *current_player){
	char answer;
	int how;
	printf("Your account: %d$\n\n",(*current_player).account );
	printf("Do you want to buy property of %s ? (Y/N): ",(*current_block).name);
	scanf(" %c",&answer);
	if(answer == 'Y' || answer == 'y'){
		printf("Purchase succesful..\n");
		(*current_player).account -= (*current_block).price;
		(*current_block).owner.type = (*current_player).type;
		for (int i = 0; i < 11; ++i)
		{
			if((*current_player).owned_block_ids[i] == -1){
				(*current_player).owned_block_ids[i] = (*current_block).block_id;
				break;
			}
		}
		if((*current_player).account > (*current_block).house_price){
			printf("\nDo you want to build house ? (Y/N): ");
			scanf(" %c",&answer);
			while(answer == 'Y' || answer == 'y'){
				printf("Price of a house at %s: %d$\n",(*current_block).name,(*current_block).house_price );
				printf("\nHow many houses do you want to build? (1/2/3): ");
				scanf(" %d",&how);
				getchar();
				if(how == 1 && (*current_player).account > (*current_block).house_price){
					(*current_player).account -= (*current_block).house_price;
					(*current_block).house_count = 1;
					answer = 'n';
				}
				else if(how == 2 && (*current_player).account > 2*(*current_block).house_price){
					(*current_player).account -= 2*(*current_block).house_price;
					(*current_block).house_count = 2;
					answer = 'n';
				}
				else if(how ==3 && (*current_player).account > 3*(*current_block).house_price){
					(*current_player).account -= 3*(*current_block).house_price;
					(*current_block).house_count = 3;
					answer = 'n';
				}
				else if(how < 1 || how > 3){
					printf("\nYou can build min. 1 or max. 3 house !\n");
					answer = 'y';
				}
				else{
					printf("\nYou don't have enough money for %d houses !\n",how);
					answer = 'y';
				}
			}
		}
		printf("\nPlease press enter to end the process..");
		getchar();
	}
}
void sell_property(struct block board[20], struct player *current_player){
	char answer;
	int how;
	int flag=0;
	printf("\n%s properties: \n\n",(*current_player).name);
	for (int i = 0; i < 11; ++i)
		if((*current_player).owned_block_ids[i] != -1){
			printf("%d - %s\n",board[(*current_player).owned_block_ids[i]].block_id,board[(*current_player).owned_block_ids[i]].name);
			flag++;
		}
	if(flag > 0){
		printf("\nDo you want to sell half of the value? (Y/N): ");
		scanf(" %c",&answer);
		while(answer == 'Y' || answer == 'y'){
			printf("\nEnter the block ID : ");
			scanf("%d",&how);
			for (int i = 0; i < 11; ++i){
				if((*current_player).owned_block_ids[i] == how){
					(*current_player).account += (board[how].house_price*board[how].house_count)/2;
					(*current_player).account += (board[how].price)/2;
					(*current_player).owned_block_ids[i] = -1;
					board[how].owner.type = noone;
					answer = 'n';
					printf("Sales succesful..\n");
				}
			}
			if(answer != 'n')
				printf("\nYou entered wrong ID ! Try Again !\n");
		}
	}
	else{
		printf("You have no deeds ! Enter to return to game..");
		getchar();
	}
}
void gameplay(struct block board[20], struct player player_one, struct player player_two){		//the menu embedded in gameplay function.
	int choice=0, type=0, endgame = 0, turn=random()%2+1;
	
	show_board(board, player_one, player_two);
	
	player_one.current_block_id = 0;
	player_one.account = 100000;
	player_one.turn_to_wait = 0;
	player_one.type = cap;
	player_one.name = "Cap";
	for (int i = 0; i < 11; ++i) player_one.owned_block_ids[i] = -1;

	player_two.current_block_id = 0;
	player_two.account = 100000;
	player_two.turn_to_wait = 0;
	player_two.type = car;
	player_two.name = "Car";
	for (int i = 0; i < 11; ++i) player_two.owned_block_ids[i] = -1; 
	
	while(endgame == 0)		//Start of while loop.
	{	
		show_board(board, player_one, player_two);
		if(turn%2 == 0) printf("Turn of the %s ..\n",player_one.name);
		else if(turn%2 == 1) printf("Turn of the %s ..\n",player_two.name);
		choice=0;
		printf("\n");
		printf("1 - Roll the dice\n");
		printf("2 - Show my account\n");
		printf("3 - Show my properties\n");
		printf("4 - Show property deeds\n");
		printf("5 - Buy property\n");
		printf("6 - Buy house\n");
		printf("7 - Sell property\n");
		printf("Please select an option to continue: ");
		scanf("%d",&choice);
		getchar();

		switch(choice){	
			case 1: {		//Roll the dice
				int deed=0;
				if(turn%2 == 0 && player_one.turn_to_wait == 0){		//if player is not punished.
					player_one.current_block_id += random()%6+1;	//dice are discarded, randomly.
					if(player_one.current_block_id > 19){		//if he return a full lap.
						player_one.account += 10000;		//increases his money 10000$.
						player_one.current_block_id %= 20;	
					}
					if(board[player_one.current_block_id].type == tax){		//if the block is tax
						player_one.account -= board[player_one.current_block_id].price;		//tax price is paid from the account.
					}
					else if(board[player_one.current_block_id].type == property){		//if the block is property
						if(board[player_one.current_block_id].owner.type == noone && player_one.account >= board[player_one.current_block_id].price){		//if player want to buy
							show_board(board, player_one, player_two);
							buy_property(&board[player_one.current_block_id],&player_one);
						}
						else if(board[player_one.current_block_id].owner.type == player_two.type ){		//if block is the other player's block.
							if(board[player_one.current_block_id].house_count > 0){
								if(board[player_one.current_block_id].house_count == 1) player_one.account -= board[player_one.current_block_id].rent_1;
								else if(board[player_one.current_block_id].house_count == 2) player_one.account -= board[player_one.current_block_id].rent_2;
								else if(board[player_one.current_block_id].house_count == 3) player_one.account -= board[player_one.current_block_id].rent_3;
							}
							else player_one.account -= board[player_one.current_block_id].rent;
						}
					}
					else if(board[player_one.current_block_id].type == punish){		//if the block is punish
						player_one.turn_to_wait = board[player_one.current_block_id].rent;
					}
					while(player_one.account < 0){		//if player account less than zero
						for (int i = 0; i < 11; ++i)
						{
							if(player_one.owned_block_ids[i] != -1) deed++;
						}
						if(deed > 0){		//if player has deeds
							show_board(board, player_one, player_two);
							printf("If you don't sell a property, you will go bankrupt !\n");
							sell_property(board,&player_one);
							deed = 0;
						}
						else if(player_one.account < 0){	//if player has no deed and his account is zero, game over
							show_board(board, player_one, player_two);
							printf("%s WENT BUNKRUPT !\n\n%s WON THE GAME, CONGRATULATIONS :)\n\n",player_one.name,player_two.name);
							player_one.account = 1;
							endgame = 1;
						} 
					}
					if(player_two.turn_to_wait > 0){		//if the other player is punished
						player_two.turn_to_wait--;
						if(player_one.turn_to_wait <= player_two.turn_to_wait) turn++; 
						else{			//if both of them are punished
							player_one.turn_to_wait = 0;
							player_two.turn_to_wait = 0;
						}
					}
					turn++;
				}
				else if(turn%2 == 1 && player_two.turn_to_wait == 0) {		//if player is not punished.
					player_two.current_block_id += random()%6+1;		//dice are discarded, randomly.
					if(player_two.current_block_id > 19){		//if he return a full lap.
						player_two.account += 10000;		//increases his money 10000$.
						player_two.current_block_id %= 20;
					}
					if (board[player_two.current_block_id].type == tax){		//if the block is tax
						player_two.account -= board[player_two.current_block_id].price;		//tax price is paid from the account.
					}
					else if(board[player_two.current_block_id].type == property){		//if the block is property
						if(board[player_two.current_block_id].owner.type == noone && player_two.account >= board[player_two.current_block_id].price){		//if player want to buy
							show_board(board, player_one, player_two);
							buy_property(&board[player_two.current_block_id],&player_two);
						}
						else if(board[player_two.current_block_id].owner.type == player_one.type ){		//if block is the other player's block.
							if(board[player_two.current_block_id].house_count > 0){
								if(board[player_two.current_block_id].house_count == 1) player_two.account -= board[player_two.current_block_id].rent_1;
								else if(board[player_two.current_block_id].house_count == 2) player_two.account -= board[player_two.current_block_id].rent_2;
								else if(board[player_two.current_block_id].house_count == 3) player_two.account -= board[player_two.current_block_id].rent_3;
							}
							else player_two.account -= board[player_two.current_block_id].rent;
						}
					}
					else if(board[player_two.current_block_id].type == punish){		//if the block is punish
						player_two.turn_to_wait = board[player_two.current_block_id].rent;
					}
					while(player_two.account < 0){		//if player account less than zero
						for (int i = 0; i < 11; ++i)
						{
							if(player_two.owned_block_ids[i] != -1) deed++;
						}
						if(deed > 0){		//if player has deeds
							show_board(board, player_one, player_two);
							printf("If you don't sell a property, you will go bankrupt !\n");
							sell_property(board,&player_two);
							deed = 0;
						}
						else if(player_two.account < 0){		//if player has no deed and his account is zero, game over
							show_board(board, player_one, player_two);
							printf("%s WENT BUNKRUPT !\n\n	%sWON THE GAME, CONGRATULATIONS :)\n\n",player_two.name,player_one.name);
							player_two.account = 1;
							endgame = 1;
						}
					}	 
					if(player_one.turn_to_wait > 0){		//if the other player is punished
						player_one.turn_to_wait--;
						if(player_two.turn_to_wait <= player_one.turn_to_wait) turn++;
						else{			//if both of them are punished
							player_one.turn_to_wait = 0;
							player_two.turn_to_wait = 0;
						}
					}
					turn++;
				}
				break;
			}	//End of roll the dice
			case 2: {	//show my account
				show_board(board, player_one, player_two);
				if(turn%2 == 0){
					printf("\n%s account : %d$\n",player_one.name,player_one.account);
				}
				else {
					printf("\n%s account : %d$\n",player_two.name,player_two.account);
				}
				printf("\nPlease press enter to return to game..");
				getchar();
				break;
			}		//end show my account
			case 3: {		//show my properties
				show_board(board, player_one, player_two);
				if(turn%2 == 0){
					printf("%s properties: \n\n",player_one.name);
					for (int i = 0; i < 11; ++i)
						if(player_one.owned_block_ids[i] != -1) printf("%d - %s\n",board[player_one.owned_block_ids[i]].block_id,board[player_one.owned_block_ids[i]].name );
				}
				else {
					printf("%s properties: \n\n",player_two.name);
					for (int i = 0; i < 11 ; ++i)
						if(player_two.owned_block_ids[i] != -1) printf("%d - %s\n",board[player_two.owned_block_ids[i]].block_id,board[player_two.owned_block_ids[i]].name );
				}
				printf("\nPlease press enter to return to game..");
				getchar();
				break;
			}		//end show my properties
			case 4: {		//show all properties
				show_properties(board);
				break;
			}		//end show all properties
			case 5: {		//special cases for buy properties
				show_board(board, player_one, player_two);	
				if(turn%2 == 0 && board[player_one.current_block_id].owner.type == noone && player_one.account > board[player_one.current_block_id].price){
					if(board[player_one.current_block_id].type == property){
						buy_property(&board[player_one.current_block_id],&player_one);
					}
					else {
						printf("\nThis block is not for sale !\n");
						printf("\nPlease press enter to return to game..");
						getchar();
					}
				}
				else if(turn%2 == 1 && board[player_two.current_block_id].owner.type == noone && player_two.account > board[player_two.current_block_id].price){
					if(board[player_two.current_block_id].type == property){
						buy_property(&board[player_two.current_block_id],&player_two);
					}
					else {
						printf("\nThis block is not for sale !\n");
						printf("\nPlease press enter to return to game..");
						getchar();
					}
				}
				else{
					printf("\nWarning: This deed is sold ! !\n");
					printf("\nPlease press enter to return to game..");
					getchar();
				} 
				break;
			}		//end of buy properties
			case 6: {		//buy house
				char answer=0;		//answer of yes/no question
				int how=0;		//number of house
				show_board(board, player_one, player_two);		
				if(turn%2 == 0 && board[player_one.current_block_id].owner.type == player_one.type){
					if(board[player_one.current_block_id].house_count == 3) printf("You already have 3 houses !\n");
					else if(board[player_one.current_block_id].house_count < 3){
						printf("House Count: %d\n\nDo you want to buy house ? (Y/N): ",board[player_one.current_block_id].house_count);
						scanf(" %c",&answer);
						if(answer == 'Y' || answer == 'y'){
							printf("\nHow many houses do you want to buy : ");
							scanf(" %d",&how);
							getchar();
							if(how == 1 && player_one.account > board[player_one.current_block_id].house_price){
								board[player_one.current_block_id].house_count +=1;
								player_one.account -= board[player_one.current_block_id].house_price;
								//answer = 'n';
							}
							else if(how == 2 && player_one.account > 2*board[player_one.current_block_id].house_price
								&& board[player_one.current_block_id].house_count < 2){
								board[player_one.current_block_id].house_count +=2;
								player_one.account -= 2*board[player_one.current_block_id].house_price;
								//answer = 'n';
							}
							else if(how == 3 && player_one.account > 3*board[player_one.current_block_id].house_price
								&& board[player_one.current_block_id].house_count < 1){
								board[player_one.current_block_id].house_count +=3;
								player_one.account -= 3*board[player_one.current_block_id].house_price;
								//answer = 'n';
							}
							else{
								printf("\nWarning: Check your account and try again !\n");
								//answer = 'n';
							} 
						}
					}
				}
				else if(turn%2 == 1 && board[player_two.current_block_id].owner.type == player_two.type){
					if(board[player_two.current_block_id].house_count == 3) printf("You already have 3 houses !\n");
					else if(board[player_two.current_block_id].house_count < 3){
						printf("House Count: %d\n\nDo you want to buy house ? (Y/N): ",board[player_two.current_block_id].house_count);
						scanf(" %c",&answer);
						if(answer == 'Y' || answer == 'y'){
							printf("\nHow many houses do you want to buy : ");
							scanf(" %d",&how);
							getchar();
							if(how == 1 && player_two.account > board[player_two.current_block_id].house_price){
								board[player_two.current_block_id].house_count +=1;
								player_two.account -= board[player_two.current_block_id].house_price;
								//answer = 'n';
							}
							else if(how == 2 && player_two.account > 2*board[player_two.current_block_id].house_price
								&& board[player_two.current_block_id].house_count < 2){
								board[player_two.current_block_id].house_count +=2;
								player_two.account -= 2*board[player_two.current_block_id].house_price;
								//answer = 'n';
							}
							else if(how == 3 && player_two.account > 3*board[player_two.current_block_id].house_price
								&& board[player_two.current_block_id].house_count < 1){
								board[player_two.current_block_id].house_count +=3;
								player_two.account -= 3*board[player_two.current_block_id].house_price;
								//answer = 'n';
							}
							else{
								printf("\nWarning: Check your account and try again !\n");
								//answer = 'n';
							} 
						}
					}
				}
				else printf("The deed of this block is not yours !\n");
				printf("\nPlease press enter to end the process..\n");
				getchar();
				break;
			}		//end of buy house
			case 7: {		//special cases for sell properties
				int deeds=0;		//number of deeds
				char exit='Y';		//condition of exit
				if(turn%2 == 0){
					while(exit == 'y' || exit == 'Y'){
						show_board(board, player_one, player_two);
						printf("You can sell as many deeds as you want.\n\n");
						sell_property(board,&player_one);
						for (int i = 0; i < 11; ++i)
							if(player_one.owned_block_ids[i] != -1) deeds++;
						if(deeds != 0) {
							printf("\nWant to sell another one? (Y/N): ");
							scanf(" %c",&exit);
						}
						else exit = 'n';
						deeds = 0;
					}	
				}
				else{
					while(exit == 'y' || exit == 'Y'){
						show_board(board, player_one, player_two);
						printf("You can sell as many deeds as you want.\n\n");
						sell_property(board,&player_two);
						for (int i = 0; i < 11; ++i)
							if(player_two.owned_block_ids[i] != -1) deeds++;
						if(deeds != 0) {
							printf("\nWant to sell another one? (Y/N): ");
							scanf(" %c",&exit);
						}
						else exit = 'n';
						deeds = 0;
					}
				}
				break;
			}		//end of sell properties
				default: 
					break; 
		}		//End of switch-case.
	}		//End of while loop.
}	//Last line of code.