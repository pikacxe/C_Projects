#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NAZIV 10+1
#define VRSTA 20+1

typedef struct restoran_st{
	char naziv[NAZIV];
	char vrsta[VRSTA];
	double ocena;
	struct restoran_st* next;
}RESTORAN;

FILE* safe_open(char name[], char mode[]){
	FILE* fp = fopen(name,mode);
	if(!fp){
	puts("File could not be opened!");
	exit(EXIT_FAILURE);
	}
	return fp;
}


void add(RESTORAN** head, RESTORAN* new){
	if(*head == NULL){
	*head = new;
	return;
	}
	add(&((*head)->next),new);
}

RESTORAN* create_new_element(char naziv[], char vrsta[], double ocena){
	RESTORAN* new = (RESTORAN*) malloc(sizeof(RESTORAN));
	if(!new){
	puts("Please donwload more RAM!");
	exit(EXIT_FAILURE);
	}
	strcpy(new->naziv,naziv);
	strcpy(new->vrsta,vrsta);
	new->ocena = ocena;
	new->next = NULL;
	
	return new;
}


void read_list_from_file(FILE* in, RESTORAN** head){
	char tmp_naziv[NAZIV];
	char tmp_vrsta[VRSTA];
	double tmp_ocena;
	
	while( fscanf(in,"%s %s %lf",
		tmp_naziv,tmp_vrsta,&tmp_ocena) != EOF){
		RESTORAN* new = create_new_element(tmp_naziv,tmp_vrsta,tmp_ocena);
		add(head,new);
		}
}

void write_one_to_file(FILE* out, RESTORAN* one){

	fprintf(out,"%3.1f %-10s %s\n",one->ocena,one->naziv,one->vrsta);
}

void write_list_to_file(FILE* out, RESTORAN* head){
	while(head!= NULL){
	 //fprintf(out,"%3.1f %-10s %s\n",head->ocena,head->naziv,head->vrsta);
	 write_one_to_file(out,head);
	 head = head->next;
	}

}

RESTORAN* find_best(RESTORAN* head, char* restoran){
	RESTORAN* best = NULL;
	while(head != NULL){
	 if(strcmp(head->vrsta, restoran)==0){
	 	if(best == NULL){
	 	best = head;
	 	}
	 	else if(best->ocena < head->ocena){
	 		best = head;
	 	}
	 
	 }
	 head = head->next;
	}
	return best;
}

void destroy_list(RESTORAN** head){
	if(*head != NULL){
		destroy_list(&((*head)->next));
		free(*head);
		*head = NULL;
	}
}

int main(int br_args, char** args){

if(br_args != 4){
	puts("Wrong usage! ./restorani italijanski novi-sad.txt izvestaj.txt");
	exit(EXIT_FAILURE);
}

char* restoran = args[1];

FILE* in = safe_open(args[2],"r");
FILE* out = safe_open(args[3],"w");
RESTORAN* list = NULL;
read_list_from_file(in,&list);
RESTORAN* best = find_best(list,restoran);
write_list_to_file(out,list);
if(best){
	fprintf(out,"\n\n Najbolje ocenjen %s restoran u gradu je:\n",restoran);
	write_one_to_file(out,best);

}
else{
	fprintf(out,"\n\n U gradu ne postoji %s restoran!\n",restoran);

}


fclose(in);
fclose(out);
destroy_list(&list);
return 0;
}



