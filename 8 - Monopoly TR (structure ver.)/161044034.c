#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define cleaner(); printf("\e[1;1H\e[2J"); // to cleaning terminal

typedef enum {noone, cap, car} Player_type;
typedef enum {start, property, tax, punish, fortune} block_type;

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
	struct block *next;
};
struct fortune_card{
	int number;
	char *name;
};

void init_the_board(struct block *board);
void show_board(struct block *board, struct player player_one, struct player player_two);
void show_properties(struct block *board);
void buy_property(struct block *current_block, struct player *current_player);
void sell_property(struct block *board, struct player *current_player);
void gameplay(struct block *board, struct player player_one, struct player player_two);

int main(){
	
	srand(time(NULL));
	struct block *board = malloc(sizeof(struct block));
	struct block *head = malloc(sizeof(struct block));
	struct player player_one;
	struct player player_two;
	
	head = board;
	
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
	
	init_the_board(board);
	board = head;
	gameplay(board, player_one, player_two);
	for (int i = 0; i < 24; ++i)
	{
		free(board);
		board = board->next;
	}
	return 0;
}
void init_the_board(struct block *board){	//created detail and long to be understandable and interchangable.	
	
	board->block_id = 0;
	board->name = "Start";
	board->price = 0;
	board->rent = 0;
	board->rent_1 = 0;
	board->rent_2 = 0;
	board->rent_3 = 0;
	board->house_price = 0;
	board->owner.type = noone;
	board->house_count = 0;
	board->type = start;
	board->next = (struct block *) malloc(sizeof(struct block));

	board = board->next;

	board->block_id = 1;
	board->name = "Esenyurt";
	board->price = 16000;
	board->rent = 800;
	board->rent_1 = 4000;
	board->rent_2 = 9000;
	board->rent_3 = 25000;
	board->house_price = 10000;
	board->owner.type = noone;
	board->house_count = 0;
	board->type = property;
	board->next = (struct block *) malloc(sizeof(struct block));

	board = board->next;

	board->block_id = 2;
	board->name = "Car Park";
	board->price = 1500;
	board->rent = 0;
	board->rent_1 = 0;
	board->rent_2 = 0;
	board->rent_3 = 0;
	board->house_price = 0;
	board->owner.type = noone;
	board->house_count = 0;
	board->type = tax;
	board->next = (struct block *) malloc(sizeof(struct block));

	board = board->next;

	board->block_id = 3;
	board->name = "Fortune Card";
	board->price = 0;
	board->rent = 0;
	board->rent_1 = 0;
	board->rent_2 = 0;
	board->rent_3 = 0;
	board->house_price = 0;
	board->owner.type = noone;
	board->house_count = 0;
	board->type = fortune;
	board->next = (struct block *) malloc(sizeof(struct block));

	board = board->next;
	
	board->block_id = 4;
	board->name = "Tuzla";
	board->price = 16500;
	board->rent = 850;
	board->rent_1 = 4250;
	board->rent_2 = 9500;
	board->rent_3 = 26000;
	board->house_price = 12000;
	board->owner.type = noone;
	board->house_count = 0;
	board->type = property;
	board->next = (struct block *) malloc(sizeof(struct block));

	board = board->next;
	
	board->block_id = 5;
	board->name = "Arnavutkoy";
	board->price = 17000;
	board->rent = 875;
	board->rent_1 = 4500;
	board->rent_2 = 10000;
	board->rent_3 = 28000;
	board->house_price = 12000;
	board->owner.type = noone;
	board->house_count = 0;
	board->type = property;
	board->next = (struct block *) malloc(sizeof(struct block));

	board = board->next;

	board->block_id = 6;
	board->name = "Wait 2 Turn";
	board->price = 0;
	board->rent = 2;
	board->rent_1 = 0;
	board->rent_2 = 0;
	board->rent_3 = 0;
	board->house_price = 0;
	board->owner.type = noone;
	board->house_count = 0;
	board->type = punish;
	board->next = (struct block *) malloc(sizeof(struct block));

	board = board->next;

	board->block_id = 7;
	board->name = "Catalca";
	board->price = 20000;
	board->rent = 1000;
	board->rent_1 = 5000;
	board->rent_2 = 12000;
	board->rent_3 = 30000;
	board->house_price = 13000;
	board->owner.type = noone;
	board->house_count = 0;
	board->type = property;
	board->next = (struct block *) malloc(sizeof(struct block));

	board = board->next;

	board->block_id = 8;
	board->name = "Beykoz";
	board->price = 23000;
	board->rent = 1100;
	board->rent_1 = 5500;
	board->rent_2 = 12500;
	board->rent_3 = 33000;
	board->house_price = 13000;
	board->owner.type = noone;
	board->house_count = 0;
	board->type = property;
	board->next = (struct block *) malloc(sizeof(struct block));

	board = board->next;

	board->block_id = 9;
	board->name = "Fortune Card";
	board->price = 0;
	board->rent = 0;
	board->rent_1 = 0;
	board->rent_2 = 0;
	board->rent_3 = 0;
	board->house_price = 0;
	board->owner.type = noone;
	board->house_count = 0;
	board->type = fortune;
	board->next = (struct block *) malloc(sizeof(struct block));

	board = board->next;

	board->block_id = 10;
	board->name = "Car Fix";
	board->price = 1750;
	board->rent=  0;
	board->rent_1 = 0;
	board->rent_2 = 0;
	board->rent_3 = 8;
	board->house_price = 8;
	board->owner.type = noone;
	board->house_count = 0;
	board->type = tax;
	board->next = (struct block *) malloc(sizeof(struct block));

	board = board->next;

	board->block_id = 11;
	board->name = "Maltepe";
	board->price = 30000;
	board->rent = 1350;
	board->rent_1 = 7000;
	board->rent_2 = 15000;
	board->rent_3 = 40000;
	board->house_price = 15000;
	board->owner.type = noone;
	board->house_count = 0;
	board->type = property;
	board->next = (struct block *) malloc(sizeof(struct block));

	board = board->next;

	board->block_id = 12;
	board->name = "Bills";
	board->price = 2000;
	board->rent = 0;
	board->rent_1 = 0;
	board->rent_2 = 0;
	board->rent_3 = 0;
	board->house_price = 0;
	board->owner.type = noone;
	board->house_count = 0;
	board->type = tax;
	board->next = (struct block *) malloc(sizeof(struct block));

	board = board->next;

	board->block_id = 13;
	board->name = "Sisli";
	board->price = 33000;
	board->rent = 1500;
	board->rent_1 = 8000;
	board->rent_2 = 16000;
	board->rent_3 = 42000;
	board->house_price = 16000;
	board->owner.type = noone;
	board->house_count = 0;
	board->type = property;
	board->next = (struct block *) malloc(sizeof(struct block));

	board = board->next;

	board->block_id = 14;
	board->name = "Oil";
	board->price = 2250;
	board->rent = 0;
	board->rent_1 = 0; 
	board->rent_2 = 0;
	board->rent_3 = 0;
	board->house_price = 0;
	board->owner.type = noone;
	board->house_count = 0;
	board->type = tax;
	board->next = (struct block *) malloc(sizeof(struct block));

	board = board->next;

	board->block_id = 15;
	board->name = "Fortune Card";
	board->price = 0;
	board->rent = 0;
	board->rent_1 = 0;
	board->rent_2 = 0;
	board->rent_3 = 0;
	board->house_price = 0;
	board->owner.type = noone;
	board->house_count = 0;
	board->type = fortune;
	board->next = (struct block *) malloc(sizeof(struct block));

	board = board->next;

	board->block_id = 16;
	board->name = "Atasehir";
	board->price = 35000;
	board->rent = 1600;
	board->rent_1 =8500;
	board->rent_2 = 17000;
	board->rent_3 = 45000;
	board->house_price = 17000;
	board->owner.type = noone;
	board->house_count = 0;
	board->type = property;
	board->next = (struct block *) malloc(sizeof(struct block));

	board = board->next;

	board->block_id = 17;
	board->name = "Sariyer";
	board->price = 40000;
	board->rent = 1750;
	board->rent_1 = 9500;
	board->rent_2 = 19000;
	board->rent_3 = 48000;
	board->house_price = 19000;
	board->owner.type = noone;
	board->house_count = 0;
	board->type = property;
	board->next = (struct block *) malloc(sizeof(struct block));

	board = board->next;

	board->block_id = 18;
	board->name = "Wait 1 Turn";
	board->price = 0;
	board->rent = 1;
	board->rent_1 = 0;
	board->rent_2 = 0;
	board->rent_3 = 0;
	board->house_price = 0;
	board->owner.type = noone;
	board->house_count = 0;
	board->type = punish;
	board->next = (struct block *) malloc(sizeof(struct block));

	board = board->next;

	board->block_id = 19;
	board->name = "Kadikoy";
	board->price = 43000;
	board->rent = 1900;
	board->rent_1 = 11000;
	board->rent_2 = 21500;
	board->rent_3 = 55000;
	board->house_price = 23000;
	board->owner.type = noone;
	board->house_count = 0;
	board->type = property;
	board->next = (struct block *) malloc(sizeof(struct block));

	board = board->next;

	board->block_id = 20;
	board->name = "Besiktas";
	board->price = 60000;
	board->rent = 2500;
	board->rent_1 = 15000;
	board->rent_2 = 28000;
	board->rent_3 = 60000;
	board->house_price = 30000;
	board->owner.type = noone;
	board->house_count = 0;
	board->type = property;
	board->next = (struct block *) malloc(sizeof(struct block));

	board = board->next;

	board->block_id = 21;
	board->name = "Fortune Card";
	board->price = 0;
	board->rent = 0;
	board->rent_1 = 0;
	board->rent_2 = 0;
	board->rent_3 = 0;
	board->house_price = 0;
	board->owner.type = noone;
	board->house_count = 0;
	board->type = fortune;
	board->next = (struct block *) malloc(sizeof(struct block));

	board = board->next;

	board->block_id = 22;
	board->name = "Vocation";
	board->price = 5000;
	board->rent = 0;
	board->rent_1 = 0;
	board->rent_2 = 0;
	board->rent_3 = 0;
	board->house_price = 0;
	board->owner.type = noone;
	board->house_count = 0;
	board->type = tax;
	board->next = (struct block *) malloc(sizeof(struct block));

	board = board->next;

	board->block_id = 23;
	board->name = "Bebek";
	board->price = 70000;
	board->rent = 3500;
	board->rent_1 = 20000;
	board->rent_2 = 35500;
	board->rent_3 = 65500;
	board->house_price = 35000;
	board->owner.type = noone;
	board->house_count = 0;
	board->type = property;
	board->next = NULL;
}
void show_board(struct block *board, struct player player_one, struct player player_two){		//it can be resolution problem because it is made using tabs(\t).
	cleaner();
	struct block *head = malloc(sizeof(struct block)); 
	struct block *middle = malloc(sizeof(struct block));
	int i=0,space_flag=0,count=0;
	
	printf("\t\t\t\t\t\t\t\t\t***	MONOPOLY ISTANBUL	***\n\n");
	printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	head = board;
	for (i=0;i<7;i++)
	{
        if (strlen(board->name)<8)
		    printf("|\t%s\t\t",board->name);
        else
            printf("|\t%s\t",board->name);
        board = board->next;
	}
	printf("|\n");
	board = head;
	for (i=0;i<7;i++)
	{
		if (board->type==property || board->type==tax)
		    printf("|\t%d$ \t\t",board->price);
		else if (strlen(board->name)<8)
            printf("|\t     \t\t");
        else
            printf("|\t\t \t");
        board = board->next;
	}
    printf("|\n");
    board = head;
    for (i=0;i<7;i++)
    {
        space_flag=0;
        printf("|\t");
        if (i==player_one.current_block_id && i==player_two.current_block_id)
        {
            printf("%s, %s \t",player_one.name,player_two.name);
            space_flag=1;
        }
        else {
            if (i == player_one.current_block_id) {
                printf("%s \t\t", player_one.name);
                space_flag = 1;
            }
            if (i == player_two.current_block_id) {
                printf("%s \t\t", player_two.name);
                space_flag = 1;
            }
        }
        if (space_flag==0) {
            if (strlen(board->name)<8)
                printf("     \t\t");
            else
                printf(" \t\t");
        }
        board = board->next;
    }
    printf("|\n");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    middle = board;
    
    for (i=0; i < 5; i++)
    {	board = head;
    	for (int k = 0; k < 23-i; ++k){
    		board = board->next;
    	} 
        
        if (strlen(board->name)<8)
            printf("|\t%s\t\t|",board->name);
        else
            printf("|\t%s\t|",board->name);
        
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");

        if (strlen(middle->name)<8)
            printf("|\t%s\t\t|",middle->name);
        else
            printf("|\t%s\t|",middle->name);
        
        printf("\n");
  
        if (board->type==property || board->type==tax)
            printf("|\t%d$ \t\t|",board->price);
        else if (strlen(board->name)<8)
            printf("|\t     \t|");
        else
            printf("|\t\t \t|");

        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");

        if (middle->type==property || middle->type==tax)
            printf("|\t%d$ \t\t",middle->price);
        else if (strlen(middle->name)<8)
            printf("|\t     \t");
        else
            printf("|\t\t \t");

        printf("|\n");

        space_flag=0;
        printf("|\t");

        if (23-i==player_one.current_block_id && 23-i==player_two.current_block_id)
        {
            printf("%s, %s \t|",player_one.name,player_two.name);
            space_flag=1;
        }
        else {
            if (23 - i == player_one.current_block_id) {
                printf("%s \t\t|", player_one.name);
                space_flag = 1;
            }
            if (23 - i == player_two.current_block_id) {
                printf("%s \t\t|", player_two.name);
                space_flag = 1;
            }
        }
        if (space_flag==0) {
            if (strlen(board->name)<8)
                printf("\t\t|");
            else
                printf("    \t\t|");
        }

        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
        
        space_flag=0;
        printf("|\t");
        if (7+i==player_one.current_block_id && 7+i==player_two.current_block_id)
        {
            printf("%s, %s \t",player_one.name,player_two.name);
            space_flag=1;
        }
        else {

            if (7+i==player_one.current_block_id)
            {
                printf("%s \t\t",player_one.name);
                space_flag=1;
            }
            if (7+i==player_two.current_block_id)
            {
                printf("%s \t\t",player_two.name);
                space_flag=1;
            }
        }

        if (space_flag==0) {
            if (strlen(middle->name)<8)
                printf("\t\t");
            else
                printf("    \t\t");
        }

        printf("|\n");
        if (i!=4) {
            printf("-------------------------");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
            printf("-------------------------");
            printf("\n");
        }
        middle = middle->next;
    }
    
    //bottom row
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    for (i=18;i>=12;i--)
    {	board = head;
    	for (int k = 0; k < i; ++k) board = board->next;
        if (strlen(board->name)<8)
            printf("|\t%s\t\t",board->name);
        else
            printf("|\t%s\t",board->name);
    }
    printf("|\n");
    
    for (i=18;i>=12;i--)
    {	board = head;
    	for (int k = 0; k < i; ++k) board = board->next;
        if (board->type==property || board->type==tax)
            printf("|\t%d$ \t\t",board->price);
        else if (strlen(board->name)<8)
            printf("|\t     \t\t");
        else
            printf("|\t\t \t");
    }
    printf("|\n");
    
    for (i=18;i>=12;i--)
    {	board = head;
    	for (int k = 0; k < i; ++k) board = board->next;
        space_flag=0;
        printf("|\t");
        if (i==player_one.current_block_id && i==player_two.current_block_id)
        {
            printf("%s, %s \t",player_one.name,player_two.name);
            space_flag=1;
        }
        else {
            if (i == player_one.current_block_id) {
                printf("%s \t\t", player_one.name);
                space_flag = 1;
            }
            if (i == player_two.current_block_id) {
                printf("%s \t\t", player_two.name);
                space_flag = 1;
            }
        }
        if (space_flag==0) {
            if (strlen(board->name)<8)
                printf("     \t\t");
            else
                printf(" \t\t");
        }
    }
    printf("|\n");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}
void show_properties(struct block *board){
	cleaner();
	int exit_flag=0,i,choice;
	struct block *head = malloc(sizeof(struct block));
	head = board;
    while (exit_flag==0)
    {	board = head;

        printf("Please select a property to see details:\n");
        for (i = 0; i < 24; ++i) {
            if (board->type == property)
                printf("%d -\t%s \n",board->block_id, board->name);
            if(board->next != NULL) board = board->next;
        }
        board = head;
        printf("0 -\tExit\n");
        scanf("%d",&choice);
        getchar();
        cleaner();
        if (choice==0)
            exit_flag=1;
        else {
        	while (board->block_id != choice && (choice > 0 && choice < 24)){
        			board = board->next;
        	}
            if (choice > 0 && choice < 24 && board->type == property) {
                printf("\n---------------------------------\n");
                if (strlen(board->name) < 8)
                    printf("|\t\t%s\t\t|\n", board->name);
                else
                    printf("|\t    %s\t\t|\n", board->name);
                printf("---------------------------------\n");
                printf("|\tRent \t\t%d$\t|\n", board->rent);
                printf("|\tRent 1 H \t%d$\t|\n", board->rent_1);
                printf("|\tRent 2 H \t%d$\t|\n", board->rent_2);
                printf("|\tRent 3 H \t%d$\t|\n", board->rent_3);
                printf("---------------------------------\n");
                printf("|\tHouse Price \t%d$\t|\n", board->house_price);
                printf("|\tHouse count \t%d\t|\n", board->house_count);
                printf("---------------------------------\n\n\n");
            } else printf("\nWrong choice! Please try again.\n\n");
        }
    }
}
void buy_property(struct block *current_block, struct player *current_player){
	char answer ;
	int how,yn=rand()%2;
	if(current_player->type == cap){
		printf("Your account: %d$\n\n",current_player->account );
		printf("Do you want to buy property of %s ? (Y/N): ",current_block->name);
		scanf(" %c",&answer);
	}
	else{
		if(yn == 0) answer = 'n';
		else{
			answer = 'y';
			printf("Pc bought this property..\n\n");
		}
	}
	if(answer == 'Y' || answer == 'y'){
		printf("Purchase succesful..\n\n");
		current_player->account -= current_block->price;
		current_block->owner.type = current_player->type;
		for (int i = 0; i < 11; ++i)
		{
			if(current_player->owned_block_ids[i] == -1){
				current_player->owned_block_ids[i] = current_block->block_id;
				break;
			}
		}
		if(current_player->account > current_block->house_price){
			if(current_player->type == cap){
				printf("\nDo you want to build house ? (Y/N): ");
				scanf(" %c",&answer);
			}
			else{
				yn = rand()%2;
				if(yn == 0) answer = 'n';
				else{
					answer = 'y';
					printf("Pc bought house..\n\n");
				} 
			}
			while(answer == 'Y' || answer == 'y'){
				if(current_player->type == cap){
					printf("Price of a house at %s: %d$\n",current_block->name,current_block->house_price );
					printf("\nHow many houses do you want to build? (1/2/3): ");
					scanf(" %d",&how);
					getchar();
				}
				else how = rand()%3+1;
				if(how == 1 && current_player->account > current_block->house_price){
					current_player->account -= current_block->house_price;
					current_block->house_count = 1;
					answer = 'n';
				}
				else if(how == 2 && current_player->account > 2*current_block->house_price){
					current_player->account -= 2*current_block->house_price;
					current_block->house_count = 2;
					answer = 'n';
				}
				else if(how ==3 && current_player->account > 3*current_block->house_price){
					current_player->account -= 3*current_block->house_price;
					current_block->house_count = 3;
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
			printf("\nPlease press enter to end the process..");
			getchar();	
		}
	}
}
void sell_property(struct block *board, struct player *current_player){
	struct block *head = malloc(sizeof(struct block));;
	head = board;
	char answer;
	int how;
	int flag=0;
	
	if(current_player->type == cap){
		printf("\n%s properties: \n\n",current_player->name);
		for (int i = 0; i < 11; ++i){	
			for (int k = 0; k < current_player->owned_block_ids[i]; ++k) board = board->next;
			if(current_player->owned_block_ids[i] != -1){
				printf("%d - %s\n",board->block_id,board->name);
				flag++;
			}
			board = head;
		}
	}
	if(flag > 0){
		if(current_player->type == cap){
			printf("\nDo you want to sell half of the value? (Y/N): ");
			scanf(" %c",&answer);
		}
		else answer = 'y';
		while(answer == 'Y' || answer == 'y'){
			if(current_player->type == cap){
				printf("\nEnter the block ID : ");
				scanf("%d",&how);
			}
			else how = rand()%11;
			for (int i = 0; i < 11; ++i){
				for (int k = 0; k < how; ++k) board = board->next;
				if(current_player->owned_block_ids[i] == how){
					current_player->account += (board->house_price*board->house_count)/2;
					current_player->account += (board->price)/2;
					current_player->owned_block_ids[i] = -1;
					board->owner.type = noone;
					answer = 'n';
					printf("Sales succesful..\n");
					board = head;
				}
			}
			if(answer != 'n' && current_player->type == cap){
				printf("\nYou entered wrong ID ! Try Again !\n");
			}
		}
	}
	else {
		printf("You have no deeds ! Enter to return to game..");
		getchar();
	}
}
void gameplay(struct block *board, struct player player_one, struct player player_two){		//the menu embedded in gameplay function.
	int choice=0, type=0, endgame = 0, turn=0;
	struct block *p1 = malloc(sizeof(struct block));
	struct block *p2 = malloc(sizeof(struct block));
	struct fortune_card card1,card2,card3,card4,card5;
	p1 = board;
	p2 = board;

	card1.name = "Free House";
	card1.number = 1;
	
	card2.name = "Time Travel";
	card2.number = 2;

	card3.name = "Garnishment";
	card3.number = 3;

	card4.name = "Generosity";
	card4.number = 4;

	card5.name = "Treasure Hunter";
	card5.number = 5;

	show_board(board, player_one, player_two);

	while(endgame == 0)		//Start of while loop.
	{	p1 = board;
		p2 = board;
		show_board(board, player_one, player_two);
		if(turn%2 == 0) printf("Turn of the %s (User) ..\n",player_one.name);
		else if(turn%2 == 1) printf("Turn of the %s (Pc) ..\n",player_two.name);
		choice=0;
		
		printf("\n");
		
		if(turn%2 == 0){
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
		}
		else{
			choice = 1;
			printf("Please press enter to see move of PC..");
			getchar();
		}

		switch(choice){	
			case 1: {		//Roll the dice
				int deed=0,dice,card;
				if(turn%2 == 0 && player_one.turn_to_wait == 0){		//if player is not punished.
					dice = random()%6+1;
					player_one.current_block_id += dice;	//dice are discarded, randomly.
					printf("\n\nUser rolled the dice: %d , press enter..",dice);
					getchar();
					if(player_one.current_block_id > 23){		//if he return a full lap.
						player_one.account += 10000;		//increases his money 10000$.
						player_one.current_block_id %= 24;	
					}
					for (int i = 0; i < player_one.current_block_id; ++i) p1 = p1->next;
					if(p1->type == tax){		//if the block is tax
						player_one.account -= p1->price;		//tax price is paid from the account.
					}
					else if(p1->type == fortune){
						card = rand()%4+2;
						if(card == card2.number){
							dice = rand()%6+1;
							printf("\n%s Dice: %d\n\n",card2.name,dice);
							if(dice < 4){
								player_one.current_block_id += 2;
								printf("You went forward two block.. Press enter..");
								getchar();
							}
							else{
								player_one.current_block_id -= 2;
								printf("You came back two block.. Press enter..");
								getchar();
							}
						}
						if(card == card3.number){
							printf("\n%s\n\n",card3.name);
							printf("You paid 5000$ to the bank..\n");
							player_one.account -= 5000;
						}
						else if(card == card4.number){
							printf("\n%s\n\n",card4.name);
							printf("You paid 10000$ to the Pc..\n" );
							player_one.account -= 10000;
							player_two.account += 10000;
						}
						else if(card == card5.number){
							printf("\n%s\n\n",card5.name);
							printf("You taked 10000$ from the bank..\n" );
							player_one.account += 20000;
						}
						printf("\nPress enter to return to menu..");
						getchar();

					}
					else if(p1->type == property){		//if the block is property
						if(p1->owner.type == noone && player_one.account >= p1->price){		//if player want to buy
							show_board(board, player_one, player_two);
							buy_property(p1,&player_one);
						}
						else if(p1->owner.type == player_two.type ){		//if block is the other player's block.
							if(p1->house_count > 0){
								if(p1->house_count == 1) player_one.account -= p1->rent_1;
								else if(p1->house_count == 2) player_one.account -= p1->rent_2;
								else if(p1->house_count == 3) player_one.account -= p1->rent_3;
							}
							else player_one.account -= p1->rent;
						}
					}
					else if(p1->type == punish){		//if the block is punish
						player_one.turn_to_wait = p1->rent;
					}
					while(player_one.account <= 0){		//if player account less than zero
						for (int i = 0; i < 11; ++i)
						{
							if(player_one.owned_block_ids[i] != -1) deed++;
						}
						if(deed > 0){		//if player has deeds
							show_board(board, player_one, player_two);
							printf("If you don't sell a property, you will go bankrupt !\n");
							sell_property(p1,&player_one);
							deed = 0;
						}
						else if(player_one.account <= 0){	//if player has no deed and his account is zero, game over
							show_board(board, player_one, player_two);
							printf("%s(USER) WENT BUNKRUPT !\n\n%s(PC) WON THE GAME, CONGRATULATIONS :)\n\n",player_one.name,player_two.name);
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
					dice = random()%6+1;
					player_two.current_block_id += dice;		//dice are discarded, randomly.
					printf("\n\nPc Account: %d\n\nComputer rolled the dice: %d , press enter..",player_two.account,dice);
					getchar();
					if(player_two.current_block_id > 23){		//if he return a full lap.
						player_two.account += 10000;		//increases his money 10000$.
						player_two.current_block_id %= 24;
					}
					for (int i = 0; i < player_two.current_block_id; ++i) p2 = p2->next;
					if (p2->type == tax){		//if the block is tax
						player_two.account -= p2->price;		//tax price is paid from the account.
					}
					else if(p2->type == fortune){
						card = rand()%4+2;
						if(card == card2.number){
							dice = rand()%6+1;
							printf("\n%s Dice: %d\n\n",card2.name,dice);
							if(dice < 4){
								player_two.current_block_id += 2;
								printf("PC went forward two block.. Press enter..");
								getchar();
							}
							else{
								player_two.current_block_id -= 2;
								printf("PC came back two block.. Press enter..");
								getchar();
							}
						}
						else if(card == card3.number){
							printf("\n%s\n\n",card3.name);
							printf("You paid 5000$ to the bank..\n");
							player_two.account -= 5000;
						}
						else if(card == card4.number){
							printf("\n%s\n\n",card4.name);
							printf("You paid 10000$ to the Pc..\n" );
							player_two.account -= 10000;
							player_one.account += 10000;
						}
						else if(card == card5.number){
							printf("\n%s\n\n",card5.name);
							printf("You taked 10000$ from the bank..\n" );
							player_two.account += 20000;
						}
						printf("\nPress enter to return to menu..");
						getchar();

					}
					else if(p2->type == property){		//if the block is property
						if(p2->owner.type == noone && player_two.account >= p2->price){		//if player want to buy
							show_board(board, player_one, player_two);
							buy_property(p2,&player_two);	
						}
						else if(p2->owner.type == player_one.type ){		//if block is the other player's block.
							if(p2->house_count > 0){
								if(p2->house_count == 1) player_two.account -= p2->rent_1;
								else if(p2->house_count == 2) player_two.account -= p2->rent_2;
								else if(p2->house_count == 3) player_two.account -= p2->rent_3;
							}
							else player_two.account -= p2->rent;
						}
					}
					else if(p2->type == punish){		//if the block is punish
						player_two.turn_to_wait = p2->rent;
					}
					while(player_two.account <= 0){		//if player account less than zero
						for (int i = 0; i < 11; ++i)
						{	
							if(player_two.owned_block_ids[i] != -1) deed++;
						}
						if(deed > 0){		//if player has deeds
							show_board(board, player_one, player_two);
							printf("If you don't sell a property, you will go bankrupt !\n");
							sell_property(p2,&player_two);
							deed = 0;
						}
						else if(player_two.account <= 0){		//if player has no deed and his account is zero, game over
							show_board(board, player_one, player_two);
							printf("%s(PC) WENT BUNKRUPT !\n\n	%s(USER) WON THE GAME, CONGRATULATIONS :)\n\n",player_two.name,player_one.name);
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
					for (int i = 0; i < 11; ++i){
						p1 = board;
						for (int k = 0; k < player_one.owned_block_ids[i]; ++k) p1 = p1->next;
						if(player_one.owned_block_ids[i] != -1) printf("%d - %s\n",p1->block_id,p1->name );
					}
				}
				else {
					printf("%s properties: \n\n",player_two.name);
					for (int i = 0; i < 11 ; ++i){
						p2 = board;
						for (int k = 0; k < player_two.owned_block_ids[i]; ++k) p2 = p2->next;
						if(player_two.owned_block_ids[i] != -1) printf("%d - %s\n",p2->block_id,p2->name );
					}
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

				if(turn%2 == 0 && p1->owner.type == noone && player_one.account > p1->price){
					if(p1->type == property){
						//buy_property(p1,&player_one);
					}
					else {
						printf("\nThis block is not for sale !\n");
						printf("\nPlease press enter to return to game..");
						getchar();
					}
				}
				else if(turn%2 == 1 && p2->owner.type == noone && player_two.account > p2->price){
					if(p2->type == property){
						//buy_property(p2,&player_two);
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
				for (int i = 0; i < player_one.current_block_id; ++i) p1 = p1->next;	
				for (int i = 0; i < player_two.current_block_id; ++i) p2 = p2->next;	
				if(turn%2 == 0 && p1->owner.type == player_one.type){
					if(p1->house_count == 3) printf("You already have 3 houses !\n");
					else if(p1->house_count < 3){
						printf("House Count: %d\n\nDo you want to buy house ? (Y/N): ",p1->house_count);
						scanf(" %c",&answer);
						if(answer == 'Y' || answer == 'y'){
							printf("\nHow many houses do you want to buy : ");
							scanf(" %d",&how);
							getchar();
							if(how == 1 && player_one.account > p1->house_price){
								p1->house_count +=1;
								player_one.account -= p1->house_price;
								//answer = 'n';
							}
							else if(how == 2 && player_one.account > 2*p1->house_price
								&& p1->house_count < 2){
								p1->house_count +=2;
								player_one.account -= 2*p1->house_price;
								//answer = 'n';
							}
							else if(how == 3 && player_one.account > 3*p1->house_price
								&& p1->house_count < 1){
								p1->house_count +=3;
								player_one.account -= 3*p1->house_price;
								//answer = 'n';
							}
							else{
								printf("\nWarning: Check your account and try again !\n");
								//answer = 'n';
							} 
						}
					}
				}
				else if(turn%2 == 1 && p2->owner.type == player_two.type){
					if(p2->house_count == 3) printf("You already have 3 houses !\n");
					else if(p2->house_count < 3){
						printf("House Count: %d\n\nDo you want to buy house ? (Y/N): ",p2->house_count);
						scanf(" %c",&answer);
						if(answer == 'Y' || answer == 'y'){
							printf("\nHow many houses do you want to buy : ");
							scanf(" %d",&how);
							getchar();
							if(how == 1 && player_two.account > p2->house_price){
								p2->house_count +=1;
								player_two.account -= p2->house_price;
								//answer = 'n';
							}
							else if(how == 2 && player_two.account > 2*p2->house_price
								&& p2->house_count < 2){
								p2->house_count +=2;
								player_two.account -= 2*p2->house_price;
								//answer = 'n';
							}
							else if(how == 3 && player_two.account > 3*p2->house_price
								&& p2->house_count < 1){
								p2->house_count +=3;
								player_two.account -= 3*p2->house_price;
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
} //Last line.