#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20

typedef struct bst
{
	int value;
	struct bst *right, *left;
}bst;
typedef struct queue
{
	int value;
	struct queue *next;
}queue;
typedef struct stack
{
	int value;
	struct stack *next;
}stack;

void fill_structures(stack **stack_, queue **queue_, bst **bst_, int data[20]);
void ordered_print(stack* stack_, queue* queue_, bst* bst_);
void search(stack* stack_, queue* queue_, bst* bst_, int val_to_search);
void special_traverse(stack* stack_, queue* queue_, bst* bst_);
// Helper functions //
bst *add_to_bst(bst *node_b, int value);
stack *stack_order(stack *stack_);
queue *queue_copy(queue *queue_);
queue *queue_order(queue *queue_);
void print_stack(stack *stack_);
void print_queue(queue* queue_);
void print_bst(bst* bst_);

int main(){

	int data[20]={5, 2, 7, 8, 11, 3, 21, 7, 6, 15, 19, 35, 24, 1, 8, 12, 17, 8, 23, 4};
	
	bst *bst_;
	queue *queue_;
	stack *stack_;
	
	fill_structures(&stack_, &queue_, &bst_, data);
	ordered_print(stack_, queue_, bst_);
	search(stack_, queue_, bst_, 5);
	special_traverse(stack_, queue_, bst_);
return 0;
}

void fill_structures(stack **stack_, queue **queue_, bst **bst_, int data[]){
	clock_t start_s = 0, end_s = 0;
	clock_t start_q = 0, end_q = 0;
	clock_t start_b = 0, end_b = 0;
	double total_s = 0, total_q = 0, total_b = 0;
	int i = 0;

	start_s = clock();
// START FILL STACK //
	*stack_ = NULL;
	stack *node_s;
	
	for (i = 0; i < SIZE; ++i){
		node_s = malloc(sizeof(stack));
		node_s->value = data[i];
		node_s->next = *stack_;
		*stack_ = node_s;
	}
// END FILL STACK //
	end_s = clock();
	total_s =(double)(end_s - start_s)/CLOCKS_PER_SEC*1000;

	start_q = clock();
// START FILL QUEUE //
	queue *node_q = malloc(sizeof(queue));
	*queue_ = node_q;

	for (i = 0; i < SIZE; ++i){
			node_q->value = data[i];
		if(i != SIZE-1){
			node_q->next = malloc(sizeof(queue));
			node_q = node_q->next;
		}	
	}
// END FILL QUEUE //
	end_q = clock();
	total_q =(double)(end_q - start_q)/CLOCKS_PER_SEC*1000;
	
	start_b = clock();
//START FILL  BST //
	*bst_ = NULL;

	*bst_ = add_to_bst(*bst_ , data[0]);
	for (i = 1; i < SIZE; ++i)
		add_to_bst(*bst_ , data[i]);
//END FILL BST //
	end_b = clock();
	total_b =(double)(end_b - start_b)/CLOCKS_PER_SEC*1000;
	
	printf("\n\t\t>>    FILL STRUCTURES    <<\n\n");
	printf("-----------------------------------\n");
	printf("Structures\tStack\tQueue\tBST\n\n");
	printf("Exec. Time\t%.3f\t%.3f\t%.3f\n",total_s,total_q,total_b);
	printf("-----------------------------------\n");
}

void ordered_print(stack* stack_, queue* queue_, bst* bst_){
	clock_t start_s_order = 0, start_q_order = 0;
	clock_t start_s_print = 0, start_q_print = 0, start_b_print = 0;
	clock_t end_s_order = 0, end_q_order = 0;
	clock_t end_s_print = 0, end_q_print = 0, end_b_print = 0;

	double total_s_order = 0, total_q_order = 0, total_b_order = 0;
	double total_s_print = 0, total_q_print = 0, total_b_print = 0;
	
	printf("\n\t\t>>    ORDER AND PRINT    <<\n\n");
// START STACK ORDER //
	start_s_order = clock();

	stack_ = stack_order(stack_);

	end_s_order = clock();
	total_s_order =(double)(end_s_order - start_s_order)/CLOCKS_PER_SEC*1000;
// END STACK ORDER //

// START STACK PRINT //
	start_s_print = clock();

	printf("STACK : ");
	print_stack(stack_);

	end_s_print = clock();
	total_s_print = (double)(end_s_print - start_s_print)/CLOCKS_PER_SEC*1000;
// END STACK PRINT //

// COPY QUEUE //
	queue *head = queue_copy(queue_);
	queue_ = head;
// COPY QUEUE //

// START QUEUE ORDER //
	start_q_order = clock();
	
	queue_ = queue_order(queue_);

	end_q_order = clock();
	total_q_order =(double)(end_q_order - start_q_order)/CLOCKS_PER_SEC*1000;
// END QUEUE ORDER //

// START QUEUE PRINT //
	start_q_print = clock();

	printf("QUEUE : ");
	print_queue(queue_);

	end_q_print = clock();
	total_q_print =(double)(end_q_print - start_q_print)/CLOCKS_PER_SEC*1000;
// END QUEUE PRINT //

/* BST is already placed in order*/ total_b_order = 0;
	
// START BST PRINT //
	start_b_print = clock();

	printf("BST   : ");
	print_bst(bst_);
	printf("\n");

	end_b_print = clock();
	total_b_print =(double)(end_b_print - start_b_print)/CLOCKS_PER_SEC*1000;
// END BST PRINT //
	
	printf("\n-----------------------------------\n");
	printf("Structures\tStack\tQueue\tBST\n\n");
	printf("Order Time\t%.3f\t%.3f\t%.3f\n",total_s_order,total_q_order,total_b_order );
	printf("-----------------------------------\n");
	printf("Structures\tStack\tQueue\tBST\n\n");
	printf("Print Time\t%.3f\t%.3f\t%.3f\n",total_s_print,total_q_print,total_b_print );
	printf("-----------------------------------\n");
}

void search(stack* stack_, queue* queue_, bst* bst_, int val_to_search){
	int flag = 0,step = 0,count = 0;
	clock_t start_s_search = 0, start_q_search = 0, start_b_search = 0;
	clock_t end_s_search = 0, end_q_search = 0, end_b_search = 0;

	double total_s_search = 0, total_q_search = 0, total_b_search = 0;
	printf("\n\t\t>>	  SEARCH 	<<\n\n");
	printf("Searched value is : %d\n\n",val_to_search );

// START SEARCH STACK //
	start_s_search = clock();
	
	printf("**STACK SEARCH\n\n");
	while(flag == 0){
		if(stack_->value == val_to_search){
			count++;
			printf("%d. result founded on %d. step.\n",count,step );
			if(stack_->next != NULL){
				stack_ = stack_->next;
				step++;	
			}
			else flag = 1; 
		} 
		else{ 
			if(stack_->next != NULL){
				stack_ = stack_->next;
				step++;
			}
			else {
				if(count == 0) printf("Stack: No such element found !\n");
				flag = 1;
			}
		}	
	}

	end_s_search = clock();
	total_s_search =(double)(end_s_search - start_s_search)/CLOCKS_PER_SEC*1000;
// END SEARCH STACK //
	
	flag = 0; step = 0; count = 0;

// START SEARCH QUEUE //
	start_q_search = clock();

	printf("\n**QUEUE SEARCH\n\n");
	while(flag == 0){
		if(queue_->value == val_to_search){
			count++;
			printf("%d. result founded on %d. step.\n",count,step );
			if(queue_->next != NULL){
				queue_ = queue_->next;
				step++;	
			}
			else flag = 1;
		}
		else{
			if(queue_->next != NULL){
				queue_ = queue_->next;
				step++;
			}
			else {
				if(count == 0) printf("Queue: No such element found !\n");
				flag = 1;
			}
		} 
	}
	
	end_q_search = clock();
	total_q_search = (double)(end_q_search - start_q_search)/CLOCKS_PER_SEC*1000;
// END SEARCH QUEUE //

	flag = 0; step = 0; count = 0;

//START SEARCH BST //
	start_b_search = clock();

	printf("\n**BST SEARCH\n\n");
	while (flag == 0){
		if(bst_->value == val_to_search){
			printf("1 result founded on %d. step.\n",step );
			flag = 1;	
		}
		else{
			if(bst_->value > val_to_search && bst_->left != NULL ){
				bst_ = bst_->left;
				step++;
			} 
			else if(bst_->value <= val_to_search && bst_->right != NULL ) {
				bst_ = bst_->right;
				step++;
			}
			else{
				printf("BST: No such element found !\n");
				flag = 1;
			}
		} 	
	}
	
	end_b_search = clock();
	total_b_search =(double)(end_b_search - start_b_search)/CLOCKS_PER_SEC*1000;
// END SEARCH BST //
	
	printf("\n-----------------------------------\n");
	printf("Structures\tStack\tQueue\tBST\n\n");
	printf("Search Time\t%.3f\t%.3f\t%.3f\n",total_s_search,total_q_search,total_b_search);
	printf("-----------------------------------\n");
}
void special_traverse(stack* stack_, queue* queue_, bst* bst_){
	int head = 0, till = SIZE-1;

	clock_t start_s_st = 0, start_q_st = 0, start_b_st = 0;
	clock_t end_s_st = 0, end_q_st = 0, end_b_st = 0;

	double total_s_st = 0, total_q_st = 0, total_b_st = 0;
	printf("\n\t\t>>    SPECIAL TRAVERSE   <<\n\n");
	
// START ST STACK //
	start_s_st = clock();

	printf("\nSTACK ->    First Version : ");
	print_stack(stack_);
	stack *top_s = stack_order(stack_);
	stack_ = top_s;
	printf("STACK -> Special Traverse : ");
	while(head < till){
		for(int i = 0; i < head; ++i)
			stack_ = stack_->next;
			
			printf("%d ",stack_->value );
			head++;
			stack_ = top_s;
		for(int i = 0; i < till; ++i)
			stack_ = stack_->next;

			printf("%d ",stack_->value );
			till--;
			stack_ = top_s;	
	}
	stack_ = top_s;

	end_s_st = clock();
	total_s_st =(double)(end_s_st - start_s_st)/CLOCKS_PER_SEC*1000;
// END ST STACK //

	head = 0; till = SIZE-1;

// START ST QUEUE //

	start_q_st = clock();

	printf("\n\nQUEUE ->    First Version : ");
	print_queue(queue_);
	queue *top_q = queue_order(queue_);
	queue_ = top_q;
	printf("QUEUE -> Special Traverse : ");
	while(head < till){
		for(int i = 0; i < head; ++i)
			queue_ = queue_->next;
			
			printf("%d ",queue_->value );
			head++;
			queue_ = top_q;
		for(int i = 0; i < till; ++i)
			queue_ = queue_->next;

			printf("%d ",queue_->value );
			till--;
			queue_ = top_q;	
	}
	queue_ = top_q;

	end_q_st = clock();
	total_q_st =(double)(end_q_st - start_q_st)/CLOCKS_PER_SEC*1000;
// END ST QUEUE //

	
// START ST BST //

	start_b_st = clock();

	printf("\n\nBST ->    First Version : ");
	print_bst(bst_);
	bst *top_b = bst_;
	printf("\nBST -> Special Traverse : ");
	//for (int i = 0; i < 10; ++i)
	while(bst_ != NULL)
	{	
		if(bst_ != NULL && bst_->right != NULL){
			while(bst_->right->right != NULL){
				bst_ = bst_->right;
			}
			printf("%d ",bst_->right->value);
			bst_->right = bst_->right->left;
			bst_ = top_b;
		}
		else if(bst_ != NULL && bst_->right == NULL){
			printf("%d ",bst_->value );
			bst_ = bst_->left;
			top_b = bst_;	
		}
		if(bst_ != NULL && bst_->left != NULL ){
			while(bst_->left->left != NULL){
				bst_ = bst_->left;
			}
			printf("%d ",bst_->left->value);
			bst_->left = bst_->left->right;
			bst_ = top_b;
		}
		else if(bst_ != NULL && bst_->left == NULL){
			printf("%d ",bst_->value );
			bst_ = bst_->right;
			top_b = bst_;	
		}
	}
	
	end_b_st = clock();
	total_b_st =(double)(end_b_st - start_b_st)/CLOCKS_PER_SEC*1000;
// END ST BST //

	printf("\n-----------------------------------\n");
	printf("Structures\tStack\tQueue\tBST\n\n");
	printf("Spe. Trav.\t%.3f\t%.3f\t%.3f\n",total_s_st,total_q_st,total_b_st);
	printf("-----------------------------------\n");
	
}
bst *add_to_bst(bst *node_b, int value){
	if (node_b == NULL){
			node_b = malloc(sizeof(bst));
			node_b->value = value;
			node_b->left = NULL;
			node_b->right = NULL;
	}
	else{
		if (node_b->value > value){
			node_b->left = add_to_bst(node_b->left,value);
		}
		else if(node_b->value < value){
			node_b->right = add_to_bst(node_b->right,value);
		}
		else;
	}
	return 	node_b;
}
stack *stack_order(stack *stack_){
	stack *node_s;
	stack *order_s = NULL;
	stack *copy = malloc(sizeof(stack));
	stack *back = malloc(sizeof(stack));

	while(stack_ != NULL){
		node_s = stack_;
		*copy = *stack_;
		stack_ = stack_->next;
		node_s = NULL;
		free(node_s);
		while(order_s != NULL && copy->value < order_s->value){
			*back = *order_s;
			order_s = order_s->next;
			stack *new_s = malloc(sizeof(stack));
			new_s->value = back->value;
			new_s->next = stack_;
			stack_ = new_s;
		}
		stack *new_o = malloc(sizeof(stack));
		*new_o = *copy;
		new_o->next = order_s;
		order_s = new_o;
	}
	back = NULL;
	copy = NULL;
	free(back);
	free(copy);
	return order_s;
}
queue *queue_copy(queue *queue_){
	int i = 0;
	queue *node = malloc(sizeof(queue));
	queue *head = node;
	for (i = 0; i < SIZE; ++i){
			node->value = queue_->value;
			queue_ = queue_->next;
		if(i != SIZE-1){
			node->next = malloc(sizeof(queue));
			node = node->next;
		}	
	}
	return head;
}
queue *queue_order(queue *queue_){
	int i = 0,k = 0;
	queue *temp_q = malloc(sizeof(queue));
	queue *head = queue_;
	for (i = 0; i < SIZE-1; ++i){
		queue_ = head;
		for (k = 0; k < SIZE-1; ++k){	
			if (queue_->value < queue_->next->value){
				temp_q->value = queue_->value;
				queue_->value = queue_->next->value;
				queue_->next->value = temp_q->value;
			}
			queue_ = queue_->next;
		}
	}
	return head;
}
void print_stack(stack* stack_){
	while(stack_ != NULL){
		printf("%d ",stack_->value );
		stack_ = stack_->next;
	}
	printf("\n");
}
void print_queue(queue* queue_){
	while(queue_ != NULL){
		printf("%d ",queue_->value );
		queue_ = queue_->next;
	}
	printf("\n");
}
void print_bst(bst* bst_){
	if (bst_ != NULL){
		print_bst(bst_->right);
		printf("%d ",bst_->value );
		print_bst(bst_->left);
	}
}
