#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IME 20+1
#define MAX_VRSTA 20+1
#define MAX_SIMBOL 2+1


typedef struct element_st{
    char hemijski_simbol[MAX_SIMBOL];
    char ime[MAX_IME];
    unsigned atomska_tezina;
    char vrsta[MAX_VRSTA];
    struct element_st* next;
}ELEMENT;



FILE* safe_open(char name[],char mode[]){
    FILE* fp = fopen(name,mode);
    if(!fp){
        puts("Could not open file!");
        exit(EXIT_FAILURE);
    }
    return fp;
}

ELEMENT* create_new_element(char simbol[],char ime[],int tezina,char vrsta[]){
    ELEMENT* new = (ELEMENT*) malloc(sizeof(ELEMENT));
    if(!new){
        puts("Not enough ram!");
        exit(EXIT_FAILURE);
    }
    strcpy(new->ime,ime);
    strcpy(new->hemijski_simbol,simbol);
    strcpy(new->vrsta,vrsta);
    new->atomska_tezina = tezina;
    new->next = NULL;
    return new;
}

void add(ELEMENT** head,ELEMENT* new){
    if(*head == NULL){
        *head = new;
        return;
    }
    add(&((*head)->next),new);
}

void print_list(ELEMENT* head){
    if(head == NULL){
        puts("Lista je prazna!");
        return;
    }
    printf("%-2s %s %3u %s\n",head->hemijski_simbol,head->ime,head->atomska_tezina,head->vrsta);
    if(head->next == NULL){
        return;
    }
    print_list(head->next);

}


void ucitaj_podatke(FILE* in,ELEMENT** head){
    char tmp_simbol[MAX_SIMBOL];
    char tmp_ime[MAX_IME];
    char tmp_vrsta[MAX_VRSTA];
    unsigned tmp_tezina;

    while( fscanf(in,"%s %s %u %s",
        tmp_simbol,tmp_ime,&tmp_tezina,tmp_vrsta
    ) != EOF){
        ELEMENT*  new= create_new_element(tmp_simbol,tmp_ime,tmp_tezina,tmp_vrsta);
        add(head,new);
    }

}

ELEMENT* obrada(ELEMENT* head,char vrsta[]){
    ELEMENT* max = NULL;
    while(head != NULL){
        if(strcmp(head->vrsta,vrsta)==0){
            if(max == NULL){
                max = head;
            }
            else if(max->atomska_tezina < head->atomska_tezina){
                max = head;
            }
        }
        head= head->next;
    }
    return max;
}

void write_list_to_file(FILE* out,ELEMENT* head){
    while(head != NULL){
        fprintf(out,"%-2s %3u %s\n",
        head->hemijski_simbol,
        head->atomska_tezina,
        head->vrsta);
        head = head->next;
    }
}

void destroy_list(ELEMENT** head){
    if(*head != NULL){
        destroy_list(&((*head)->next));
        free(*head);
        *head = NULL;
    }
}


int main(int br_args, char** args){
    if(br_args != 4){
        puts("[EROR] Usage: ./najtezi metal uzorak_vino.txt analiza.txt");
        exit(EXIT_FAILURE);
    }
    char* metal = args[1];
    FILE* in = safe_open(args[2],"r");
    FILE* out = safe_open(args[3],"w");
    ELEMENT* list = NULL;
    ucitaj_podatke(in,&list);
    write_list_to_file(out,list);
    ELEMENT* najtezi = obrada(list,metal);
    if(!najtezi){
        fprintf(out,"\n\nU uzorku nije pronadjen nijedan %s!\n",metal);
    }
    else{
        fprintf(out,"\n\nNajtezi metal je %s (%s), atomska tezina je %u\n",
        najtezi->ime,najtezi->hemijski_simbol,najtezi->atomska_tezina);
    }

    fclose(in);
    fclose(out);
    destroy_list(&list);

    return 0;
}