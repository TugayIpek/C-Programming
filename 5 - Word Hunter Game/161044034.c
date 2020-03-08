#include<stdio.h>
#include<stdlib.h>

#define DICT_SIZE 15
#define WORD_LEN 10
#define LINE_LEN 18
#define cleaner(); printf("\e[1;1H\e[2J");		//to clean terminal.

int get_line_size(char *line) {
	char *ch_iter = line; // so as not to lose beginning of line
	int counter = 0;
	// go until you see new line or null char
	while(*ch_iter != '\n' && *ch_iter != '\0') {
		ch_iter++; // next char
		counter++; // increment counter
	}
	return counter;
}
void copy_string(char *source, char *destination) {
	// get iterators over original pointers
	char *src_iter = source;
	char *dst_iter = destination;
	// until null char
	while (*src_iter != '\0') {
		// copy pointers
		*dst_iter = *src_iter;
		// advance to next char
		src_iter++;
		dst_iter++;
   }
   // terminate string
   *dst_iter = '\0';
}
void remove_newline(char *line) {
	char *ch_iter = line;
	// go until you see new line
	while(*ch_iter != '\n') {
		ch_iter++; // next char
	}
	*ch_iter = '\0'; // overwrite new line
}
void print_dictionary(char *dict[]) {		//to print dictionary
	int i;
	for(i = 0 ; i < DICT_SIZE ; i++) {
		printf("%s\n", dict[i]);
	}
}
void print_coord(int coord[DICT_SIZE][4]) {		//to print coord array
	int i, j;
	for(i = 0 ; i < DICT_SIZE ; i++) {
		for(j = 0 ; j < 4 ; j++) {
			printf("%d ", coord[i][j]);
		}
		printf("\n");
	}
}
int len_str(char str[]){		//to find the length of string
	int i=0;
	while(str[i]!='\r' && str[i]!='\0' ) { i++; }	//go until you see \r char or null char
	return i;
}
int cmp_arr(char arr1[], char arr2[]){		//to compare the arrays
	int i=0;
	while(arr1[i]!='\0' || arr2[i]!='\0'){		//go until you see \r char or null char
		if(arr1[i]==arr2[i]) i++;
		else return 0;
	}
	return 1;
}
int cmp_str(char str1[], char *str2[]){		//to compare the strings
	int i,check=0;
	for (int k = 0; k < DICT_SIZE; ++k)		//compares the entered word with all words in dictionary
	{	i=0; check=0;
		while(str1[i]!='\0' || str2[k][i]!='\r'){		//go until you see \r char or null char
			if(str1[i]==str2[k][i]) i++;
			else { check=1; break;}			//exit if any matches 
		}
		if(check==0) return 1;
	}
	return 0;	
}
int direct_fill(int array[][4],int i){		//to find directions of words in dictionary
	int direction=0;

	if(array[i][0]-array[i][2]==0) {
		if (array[i][1]-array[i][3]<0)	direction=2;	
		else if (array[i][1]-array[i][3]>0)	direction=8;	
			 
	}
	else if(array[i][0]-array[i][2]<0){
		if (array[i][1]-array[i][3]==0)	direction=6;	
		else if (array[i][1]-array[i][3]<0)	direction=3;
		else if (array[i][1]-array[i][3]>0)	direction=9;	
	}
	else if(array[i][0]-array[i][2]>0){
		if (array[i][1]-array[i][3]==0)	direction=4;	
		else if (array[i][1]-array[i][3]<0)	direction=1;
		else if (array[i][1]-array[i][3]>0)	direction=7;
	}
	return direction;
}
void filling(char *dict[], int coord[][4],char board[][DICT_SIZE]){		//to filling board with words and random char
	int length=0,direction=0,i=0;
	for (int i = 0; i < DICT_SIZE; ++i)
	{
		for (int j = 0; j < DICT_SIZE; ++j)	board[i][j]=rand()%26+97;	//to filling rondom char to board
	}
	for (int y = 0; y < DICT_SIZE; ++y)		//to filling words to board
	{
		length=len_str(dict[y]);		//to calculate length of words
		direction=direct_fill(coord,y);			//to find direction of words
		i=0;
		while(i<length){
			if 		(direction==1)	board[coord[y][0]-i][coord[y][1]+i]=dict[y][i];
			else if (direction==2)	board[coord[y][0]][coord[y][1]+i]=dict[y][i];
			else if (direction==3)	board[coord[y][0]+i][coord[y][1]+i]=dict[y][i];
			else if (direction==4)	board[coord[y][0]-i][coord[y][1]]=dict[y][i];
			else if (direction==6)	board[coord[y][0]+i][coord[y][1]]=dict[y][i];			
			else if (direction==7)	board[coord[y][0]-i][coord[y][1]-i]=dict[y][i];			
			else if (direction==8)	board[coord[y][0]][coord[y][1]-i]=dict[y][i];		
			else if (direction==9)	board[coord[y][0]+i][coord[y][1]-i]=dict[y][i];
			i++;
		}
	}
}
void print_board(char board[][DICT_SIZE]){		//to print the board
	cleaner();
	printf("\t\t\tThe Word Hunter Game\n\n	");
	for (int i = 0; i < DICT_SIZE; ++i) { printf("%-2d  ",i ); }		
	printf("\n\n\n");
	for (int i = 0; i < DICT_SIZE; ++i)
	{	printf("%d	",i);
		for (int j = 0; j < DICT_SIZE; ++j)
		{
			printf("%c   ",board[i][j]);
		}
		printf("\n\n");
	}
	printf("\n>>To exit the game, type 'exit game'\n");
}
void find_word(char board[][DICT_SIZE], char *dict[]){		//if player enter correct word, it works 
	char word[DICT_SIZE];
	char exit[DICT_SIZE]="exit game";		//to exit array
	int x=0,y=0,len_word=0;
	int check=0,direction=-1,same=0,k=0;
	int control[16];
	print_board(board);
	while(check<DICT_SIZE){		//check end situation of puzzle
		k=0; direction=-1; same=0;
		printf("\n\nNumber of words found: %d\n\n",check);
		for (int i = 0; i < 16; ++i) control[i]=0;
		for (int i = 0; i < DICT_SIZE; ++i) word[i]=0;
		while(cmp_str(word,dict)==0 && cmp_arr(word,exit)!=1){		//check word in the dictionary
			printf("Please enter the word: ");
			scanf(" %[^\n]s ",word);		//go until you see new line
			if(cmp_str(word,dict)==0 && cmp_arr(word,exit)!=1) printf("\nEntered word does not exist in puzzle !\n\n");
		}
		if(cmp_arr(word,exit)==1) break;		//if player types "exit game", it exits
		printf("\nPlease enter the coordinate (x,y):");
		scanf("%d %d",&x,&y );		
		len_word=len_str(word);		//to find length of entered word
		
		for (int i = 0; i < len_word; ++i)		//check each char for eight direction with coordinate of first char
		{
			if(board[x-i][y+i]==word[i] || board[x-i][y+i]==word[i]-32)		control[0]+=1;
			if(board[x][y+i]==word[i]	|| board[x][y+i]==word[i]-32)		control[1]+=1;
			if(board[x+i][y+i]==word[i] || board[x+i][y+i]==word[i]-32) 	control[2]+=1;
			if(board[x-i][y]==word[i]	|| board[x-i][y]==word[i]-32 )		control[3]+=1;
			if(board[x+i][y]==word[i]	|| board[x+i][y]==word[i]-32)		control[4]+=1;
			if(board[x-i][y-i]==word[i]	|| board[x-i][y-i]==word[i]-32)		control[5]+=1;
			if(board[x][y-i]==word[i]	|| board[x][y-i]==word[i]-32)		control[6]+=1;
			if(board[x+i][y-i]==word[i]	|| board[x+i][y-i]==word[i]-32)		control[7]+=1;
			
		}
		for (int l = len_word-1; 0 <= l; --l)		//check each char for eight direction with coordinate of last char
		{
			if(board[x-l][y+l]==word[len_word-1-l]	|| board[x-l][y+l]==word[len_word-1-l]-32) 		control[15]+=1;
			if(board[x][y+l]==word[len_word-1-l]	|| board[x][y+l]==word[len_word-1-l]-32)		control[14]+=1;
			if(board[x+l][y+l]==word[len_word-1-l]	|| board[x+l][y+l]==word[len_word-1-l]-32) 		control[13]+=1;
			if(board[x-l][y]==word[len_word-1-l]	|| board[x-l][y]==word[len_word-1-l]-32)		control[12]+=1;
			if(board[x+l][y]==word[len_word-1-l]	|| board[x+l][y]==word[len_word-1-l]-32)		control[11]+=1;
			if(board[x-l][y-l]==word[len_word-1-l]	|| board[x-l][y-l]==word[len_word-1-l]-32)		control[10]+=1;
			if(board[x][y-l]==word[len_word-1-l]	|| board[x][y-l]==word[len_word-1-l]-32)		control[9]+=1;
			if(board[x+l][y-l]==word[len_word-1-l]	|| board[x+l][y-l]==word[len_word-1-l]-32)		control[8]+=1;
		}
		for (int i = 0; i < 16; ++i)		//find direction from inside control array
		{	printf("%d,",control[i] );
			if (control[i]==len_word){
				direction=i;
			}
		}
		if(direction!=-1){		//making the word uppercase, if user finds the word
			while(k<len_word){
				if 		((direction==0 || direction==15) && board[x-k][y+k]>=97) 	board[x-k][y+k]-=32;
				else if ((direction==1 || direction==14) && board[x][y+k]>=97)		board[x][y+k]-=32;
				else if ((direction==2 || direction==13) && board[x+k][y+k]>=97)	board[x+k][y+k]-=32;
				else if ((direction==3 || direction==12) && board[x-k][y]>=97)		board[x-k][y]-=32;
				else if ((direction==4 || direction==11) && board[x+k][y]>=97)		board[x+k][y]-=32;
				else if ((direction==5 || direction==10) && board[x-k][y-k]>=97)	board[x-k][y-k]-=32;			
				else if ((direction==6 || direction==9) && board[x][y-k]>=97)		board[x][y-k]-=32;		
				else if ((direction==7 || direction==8) && board[x+k][y-k]>=97)		board[x+k][y-k]-=32;
				else same++;
			k++;
			}
		}
		if(same!=k) check++;
		print_board(board);		//print the board
		if (direction==-1 ){
			printf("Entered coordinate is wrong !\n");
			if(same!=k) check--;
		}
		
		if (check==15)		//if user has found all of the words, it works and game finished
		{
			printf("\t\tCONGRATULATIONS! YOU HAVE FOUND ALL THE WORDS.\n\t\t\t   YOU ARE A WORD HUNTER.\n");
			printf("\n\nPlease press enter to exit..\n");
			getchar();
			getchar();
		}
	}
}
int main(){		//start of main loop
	char *dict[DICT_SIZE];
    int coord[DICT_SIZE][4];   
    char line[LINE_LEN];
    char board[DICT_SIZE][DICT_SIZE];
	FILE *fp = fopen("word_hunter.dat", "r");
	
	int line_counter = 0;
	int dict_counter = 0;
	while(fgets(line, LINE_LEN, fp) != NULL) {
		if(line_counter%5 == 0) {
			dict[dict_counter] = (char*) malloc(sizeof(char) * get_line_size(line));
			remove_newline(line);
			copy_string(line, dict[dict_counter]);
		} else if (line_counter%5 == 1){
			coord[dict_counter][0] = atoi(line);
		} else if (line_counter%5 == 2){			
			coord[dict_counter][1] = atoi(line);		
		} else if (line_counter%5 == 3){
			coord[dict_counter][2] = atoi(line);
		} else if (line_counter%5 == 4){
			coord[dict_counter][3] = atoi(line);
			dict_counter++;
		}
		line_counter++;
	}
	
	fclose(fp);
	filling(dict,coord,board);
	find_word(board,dict);
	printf("\nExiting..\n");
		
	return 0;
}	//end of main function
