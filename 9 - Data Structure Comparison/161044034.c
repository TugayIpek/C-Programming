#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 30 	// size of the strings to be entered
#define cleaner(); printf("\e[1;1H\e[2J"); 	// to cleaning terminal

struct person
{
	char name[SIZE];
	char surname[SIZE]; 
	char musical_Work[SIZE];
	int age;
	struct person *next;
}*top;

void menu();	// general menu
void addNode (char name[], char surname[], char musical_Work[], int age);	// adds a new node to stack
void deleteNode ();	// deletes the last added node
void Sort_Alphabetically();	// sorts alphabetically
void Sort_Increasingly();	// sorts increasingly
void print_stack(struct person *head);	// prints all nodes in stack
void free_top();	// cleans the ram when the program stops

int main()		//Start of main function
{	
	top = NULL;
	menu();	
	free_top();
return 0;
}	//End of main function.

void menu()		//Start of menu function.
{	cleaner();
	char name[SIZE], surname[SIZE], musical_Work[SIZE];
	int age;
	int choice = 0;
	
	while(choice!=5)		//Start of while loop.
	{	
		choice=0;
		printf("\n****MENU****\n");
		printf("   1- Add a Person to the Stack\n");
		printf("   2- Pop a Person from the Stack\n");
		printf("   3- Sort Alphabetical Order\n");
		printf("   4- Sort Age in Increasing Order\n");
		printf("   5- Exit menu\n");
		printf("\n************\n");
		printf("Select your Choice: ");
		scanf("%d",&choice);
		getchar();
		switch(choice){
			case 1: {	// addition case
				printf("\nName: ");
				scanf(" %[^\n]s",name);
				printf("Surname: ");
				scanf(" %[^\n]s",surname);
				printf("Creation: ");
				scanf(" %[^\n]s",musical_Work);
				printf("Age: ");
				scanf(" %d",&age);
				cleaner();
				addNode(name, surname, musical_Work, age);
				print_stack(top);
				break;	 
			}		
			case 2: {	// delete case
				cleaner();
				deleteNode();
				print_stack(top);
				break;		
			}		
			case 3: {	// sort alphabetically case
				cleaner();
				Sort_Alphabetically();
				print_stack(top);		
				break;	
			}
			case 4: {	// sort increasingly case
				cleaner();
				Sort_Increasingly();
				print_stack(top);		
				break;	
			}
			case 5: {  // exit case
				cleaner();
				printf("Exiting..\n"); 
				break;		
			}
			default: {
				printf("\nThis is an invalid choice. Try again!\n");  
				break;		
			}	//If entered value is wrong, this warning appears on the display. 
		}
	}		//End of while loop.
}		//End of menu function.
void addNode (char name[], char surname[], char musical_Work[], int age){	
	struct person *node = malloc(sizeof(struct person));	// takes new adress for a node
	
	strcpy(node->name,name);
	strcpy(node->surname,surname);
	strcpy(node->musical_Work,musical_Work);
	node->age = age;
	node->next = top;
	top = node;	// the address which points to top changes
}
void deleteNode (){
	struct person *node = top;	// top copied
	
	if(top != NULL){	// until the top be empty
		top = top->next;	// top points next address
		node = NULL;	// previous address of the top empties
		free(node);	// and free
	}
	else{	// if top is empty
		printf("\n\033[1;31mWARNING: \033[0mThe Stack is already empty !\n");
	}
}
void Sort_Alphabetically(){
	struct person *node;
	struct person *ordered = NULL;
	struct person *copy = malloc(sizeof(struct person));
	struct person *back = malloc(sizeof(struct person));
	
	while(top != NULL){
		node = top;			//	this process actually
		*copy = *top;		// delete a node operation
		top = top->next;	// from the top stack
		node = NULL;		//	and deleted node is copied
		free(node);
		while(ordered != NULL && strcmp(copy->name,ordered->name) > 0){	// if copied name is not great from the last node of ordered
			*back = *ordered;											// all elemets of ordered, is sended to top again
			ordered = ordered->next;
			addNode(back->name,back->surname,back->musical_Work,back->age);
		}
		struct person *new = malloc(sizeof(struct person));	
		*new = *copy;			//	this process add a node operation
		new->next = ordered;	// to the ordered stack
		ordered = new;	
	}
	free(back);
	free(copy);
	top = ordered;	// all ordered elements is sended to top
	if(top == NULL)
		printf("\n\033[1;31mWARNING: \033[0mThe Stack is empty. You can not sorting !\n");
}
void Sort_Increasingly(){
	struct person *node;
	struct person *ordered = NULL;
	struct person *copy = malloc(sizeof(struct person));
	struct person *back = malloc(sizeof(struct person));
	
	while(top != NULL){
		node = top;			//	this process actually
		*copy = *top;		// delete a node operation
		top = top->next;	// from the top stack
		node = NULL;		//	and deleted node is copied
		free(node);
		while(ordered != NULL && copy->age > ordered->age){	// if copied age is not great from the last node of ordered
			*back = *ordered;								// all elemets of ordered, is sended to top again
			ordered = ordered->next;
			addNode(back->name,back->surname,back->musical_Work,back->age);
		}
		struct person *new = malloc(sizeof(struct person));
		*new = *copy;			//	this process add a node operation
		new->next = ordered;	// to the ordered stack
		ordered = new;
	}
	free(back);
	free(copy);
	top = ordered;	// all ordered elements is sended to top
	if(top == NULL)
		printf("\n\033[1;31mWARNING: \033[0mThe Stack is empty. You can not sorting !\n");
}
void print_stack(struct person *head){
	int i = 1;
	if(head != NULL) 
		printf("----------------\n");
	while(head != NULL){
		printf("%d)%s\n",i,head->name );
		printf("%s\n",head->surname );
		printf("%s\n",head->musical_Work );
		printf("%d\n",head->age );
		printf("----------------\n");
		head = head->next;
		i++;
	}
}
void free_top(){
	struct person *node = top;
	while(top != NULL){
		top = top->next;
		node = NULL;
		free(node);
	}
}
