#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define MAX_GRAD 2+1
#define MAX_GORIVO 10+1

typedef struct gorivo_st
{
    char grad[MAX_GRAD];
    char tip[MAX_GORIVO];
    double cena;
    struct gorivo_st* next;
}GORIVO;
typedef char string20[20];

FILE* safe_open(char *name,char *mode){
    FILE* fp = fopen(name,mode);
    if(!fp){
        puts("Nemoguce otvoriti file!");
        exit(EXIT_FAILURE);
    }
    return fp;
}

GORIVO* create_element(char grad[],char tip[],double cena){
    GORIVO* new = (GORIVO*) malloc(sizeof(GORIVO));
    if(!new){
        puts("Please download more RAM!");
        exit(EXIT_FAILURE);
    }
    strcpy(new->grad,grad);
    strcpy(new->tip,tip);
    new->cena = cena;
    new->next = NULL;
    return new;
}

void add(GORIVO** head,GORIVO* new){
    if(*head == NULL){
        *head = new;
        return;
    }
    add(&((*head)->next),new);
}

void read_list_from_file(FILE* in,GORIVO** head){
    char tmp_grad[MAX_GRAD];
    char tmp_gorivo[MAX_GORIVO];
    double tmp_cena;
    while(fscanf(in,"%s %s %lf",
        tmp_grad,tmp_gorivo,&tmp_cena) != EOF
    ){
        GORIVO* new = create_element(tmp_grad,tmp_gorivo,tmp_cena);
        add(head,new);
    }
}

double obrada(GORIVO* head,char gorivo[]){
    double sum = 0;
    int n = 0;
    while(head != NULL){
        if(strcmp(head->tip, gorivo) == 0){
            sum+= head->cena;
            n++;
        }
        head = head->next;
    }
    if(n == 0){
        return 0;
    }
    return sum/n;
}

void write_list_to_file(FILE* out,GORIVO* head){
    while(head != NULL){
        fprintf(out,"%6.2lf %s %s\n",
        head->cena,head->grad,head->tip);
        head = head->next;
    }
}


void destroy_list(GORIVO** head){
    if(*head != NULL){
        destroy_list(&((*head)->next));
        free(*head);
        *head = NULL;
    }
}


int main(int br_args, char** args){
    if(br_args != 4){
        puts("[Error] Usage: ./gorivo benzin cene.txt izvestaj.txt");
        exit(EXIT_FAILURE);
    }
    GORIVO* list= NULL;
    FILE* in = safe_open(args[2],"r");
    FILE* out = safe_open(args[3],"w");

    read_list_from_file(in,&list);
    write_list_to_file(out,list);
    double avg = obrada(list,args[1]);
    if(avg == 0){
        fprintf(out,"\n\nNOT FOUND!\n");
    }
    else{
        fprintf(out,"\n\nAVG = %.2lf\n",avg);
    }

    fclose(in);
    fclose(out);
    destroy_list(&list);
    return 0;
}