#include<stdio.h>
#include<string.h>

#define SIZE 9999												//Max. column and line size of the input file.

	typedef struct identity{	//Start of struct.

		char ID[50];
		char name[50];
		char surname[50];
		char mail[50];

	}identity;					//End of struct.

	struct identity person[SIZE];								

	void decode(char *line,int counter);
	void ID_order(identity person[SIZE],int counter);
	void name_order(identity person[SIZE],int counter);
	void surname_order(identity person[SIZE],int counter);
	void mail_order(identity person[SIZE],int counter);
	void sort(int i, int j);
	
	int main(){		//Start of main function. (Which contains read, decode, create functions.)

		int  counter=0,i=0;
		char *c,line[SIZE],metric;
		FILE *fp;
		FILE *fp2;
		
		fp=fopen("hw4_disordered_people.txt","r");				//Where the input file should be declared.
        fp2=fopen("orderedFile.txt","a"); 						//Output file.
		
		printf("Please choose a sort metric:\n\n");				
		printf("*Enter for ID => 'I' or 'i'\n");	
		printf("*Enter for Name => 'N' or 'n'\n");
		printf("*Enter for Surname => 'S' or 's'\n");
		printf("*Enter for Mail => 'M' or 'm'\n\n");
		printf("Your choice is : ");
		scanf("%c", &metric);
			
		do{														//Start of "do while" loop.
			c=fgets(line,SIZE,fp);								//It takes each line separately. 
			decode(line,counter);								//It sends to "decode" function and it decodes line.
			counter++;
		}
		
		while(c!=NULL);{ 										
			fclose(fp);
		}														//End of "do while" loop.
		counter--;
		
		if(metric=='I' || metric=='i'){							
			fprintf(fp2,"\n%-40s%-40s%-40s%-40s\n\n","ID","NAME","SURNAME","MAIL");
			ID_order(person,counter);
			printf("\nSuccesful, an output named orderedFile.txt was created and sorted by ID.\n");
			for(i=0; i<counter; i++){
				fprintf(fp2,"%-40s",person[i].ID);
				fprintf(fp2,"%-40s",person[i].name);
				fprintf(fp2,"%-40s",person[i].surname);	
				fprintf(fp2,"%-40s",person[i].mail);	
				fprintf(fp2,"\n");			
			}
		}		
		else if(metric=='N' || metric=='n'){
			fprintf(fp2,"\n%-40s%-40s%-40s%-40s\n\n","NAME","ID","SURNAME","MAIL");
			name_order(person,counter);
			printf("\nSuccesful, an output named orderedFile.txt was created and sorted by name.\n");
			for(i=0; i<counter; i++){																
				fprintf(fp2,"%-40s",person[i].name);
				fprintf(fp2,"%-40s",person[i].ID);
				fprintf(fp2,"%-40s",person[i].surname);
				fprintf(fp2,"%-40s",person[i].mail);	
				fprintf(fp2,"\n");
			}
		}		
		else if(metric=='S' || metric=='s'){
			fprintf(fp2,"\n%-40s%-40s%-40s%-40s\n\n","SURNAME","ID","NAME","MAIL");
			surname_order(person,counter);
			printf("\nSuccesful, an output named orderedFile.txt was created and sorted by surname.\n");
			for(i=0; i<counter; i++){																
				fprintf(fp2,"%-40s",person[i].surname);
				fprintf(fp2,"%-40s",person[i].ID);
				fprintf(fp2,"%-40s",person[i].name);
				fprintf(fp2,"%-40s",person[i].mail);	
				fprintf(fp2,"\n");				
			}		
		}		
		else if(metric=='M' || metric=='m'){
			fprintf(fp2,"\n%-40s%-40s%-40s%-40s\n\n","MAIL","ID","NAME","SURNAME");	
			mail_order(person,counter);
			printf("\nSuccesful, an output named orderedFile.txt was created and sorted by mail.\n");
			for(i=0; i<counter; i++){																
				fprintf(fp2,"%-40s",person[i].mail);
				fprintf(fp2,"%-40s",person[i].ID);
				fprintf(fp2,"%-40s",person[i].name);
				fprintf(fp2,"%-40s",person[i].surname);	
				fprintf(fp2,"\n");
			}		
		}
		else printf("\nERROR : An unexpected value was entered !\nThe output named orderedFile.txt was created but left blank !\n");
			
		fclose(fp2);
		
		return 0;
	} //End of the main function.

	void decode(char *line,int counter){	//Start of decode function.(Takes the line array and current element information.)

		int flag=0,first=0,search=0,i,j,size=0,line_count=0;
		char control[50];
		
		while(line[search]!=' ')  search++;						//To find the first object that counts up to the space character.
		while(line[line_count]!='\n')  line_count++;			//Founds line size.
		
		while(search<=line_count){	//Start of while loop of decode process.
			
			for(i=0;i<50;i++){
			 	control[i]=0;
			}
			 
			for(i=0,j=first;j<search;i++,j++){					//Send the first object in the line to the control array. 
				control[i]=line[j];								//"j=first" keeps location which the first character of the object.
			}
			
			size=search-first;
			
			for(i=0;i<size;i++){								//Checks control array that object is mail or not.
				if(control[i]=='@'){
					flag=1;
					strncpy(person[counter].mail,control,size);							
				}
			}
			
			if (flag!=1){										//Checks control array that object is ID or not.
				if(control[0]>='0' && control[0]<='9'){
					strncpy(person[counter].ID,control,size);
				}
				
				else if(control[1]>='A' && control[1]<='Z'){	//Checks control array that object is surname or not.
					if(person[counter].surname[0]<='A'){	
						strncpy(person[counter].surname,control,size);
					}	
					else {										//Checks second surname.
						strcat(person[counter].surname," ");						
						strcat(person[counter].surname,control);
					}  
				}

				else{											//Checks control array that object is name or not.				
					if(person[counter].name[1]<='a'){
						strncpy(person[counter].name,control,size);
					}
					else{										//Checks second name.
						strcat(person[counter].name," ");						
						strcat(person[counter].name,control);						
					}	
				}
			}
			first=search+1;
			search++;
			while(line[search]!=' ' && line[search]!='\n')  search++;
			flag=0;	
		}	//End of while loop of decode process.																								
	}   //End of decode function.														
	
	void ID_order(identity person[SIZE],int counter){	//Start of the ID_order function.		
		
		int i=0,j=0;
		
		for(j=0; j<counter; j++){
			
			for(i=j+1 ;i<counter ; i++){					
	      		
	           if( strcmp(person[j].ID,person[i].ID) > 0 ) sort(i,j);      			      	
			}
		}
	}	//End of the ID_order function.		
	
	void name_order(identity person[SIZE],int counter){	//Start of the name_order function.
		
		int i=0,j=0;
		
		for(j=0; j<counter; j++){
			
			for(i=j+1 ;i<counter ; i++){	
							
	           if( strcmp(person[j].name,person[i].name) > 0 ) sort(i,j);	           		
			}
		}
	}	//End of the name_order function.	
	
	void surname_order(identity person[SIZE],int counter){	//Start of the surname_order function.
		
		int i=0,j=0;
		
		for(j=0; j<counter; j++){
			
			for(i=j+1 ;i<counter ; i++){					
	      		
	           if( strcmp(person[j].surname,person[i].surname) > 0 ) sort(i,j);	           			           		
			}
		}
	}	//End of the surname_order function.	
	
	void mail_order(identity person[SIZE],int counter){	//Start of the mail_order function.
		
		int i=0,j=0;
		
		for(j=0; j<counter; j++){
			
			for(i=j+1 ;i<counter ; i++){					
	      		
	           if( strcmp(person[j].mail,person[i].mail) > 0 ) sort(i,j);			
			}
		}
	}	//End of the mail_order function.	
	void sort(int i, int j){	//Start of the sort function.
				
		char temp[50];
				
		strcpy(temp,person[j].ID);
   		strcpy(person[j].ID,person[i].ID);
   		strcpy(person[i].ID,temp);
   		
   		strcpy(temp,person[j].name);
   		strcpy(person[j].name,person[i].name);
   		strcpy(person[i].name,temp);
   		
   		strcpy(temp,person[j].surname);
   		strcpy(person[j].surname,person[i].surname);
   		strcpy(person[i].surname,temp);
   		
   		strcpy(temp,person[j].mail);
   		strcpy(person[j].mail,person[i].mail);
   		strcpy(person[i].mail,temp);		
	}	//End of the sort function.
