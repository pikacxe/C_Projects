#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct meso_st{
    char oznaka_grada[3];
    char vrsta_mesa[21];
    double cena_mesa;
    struct meso_st *next;
}MESO;

FILE * safe_open(char *name,char *mode){
    FILE *in = fopen(name,mode);
    if(in == NULL){
        puts("[GRESKA] Nemoguce otvoriti file!");
        exit(EXIT_FAILURE);
    }
}

void add_tolist(MESO** head, MESO* new){
    if(*head == NULL){
        *head = new;
        return;
    }
    add_tolist(&((*head)->next),new);
}

MESO* create_new_element(char oznaka_grada[],char vrsta_mesa[], double cena_mesa){
    MESO* new = (MESO*) malloc(sizeof(MESO));
    if(new == NULL){
        puts("Please download more ram");
        exit(EXIT_FAILURE);
    }
    strcpy(new->oznaka_grada,oznaka_grada);
    strcpy(new->vrsta_mesa,vrsta_mesa);
    new->cena_mesa = cena_mesa;
    new->next = NULL;
    return new;
}

void ucitaj_podatke(FILE* in,MESO** head){
    char tmp_oznaka[3],tmp_vrsta[21];
    double tmp_cena;
    while(
        fscanf(in,"%s %s %lf",
        tmp_oznaka,tmp_vrsta,&tmp_cena) != EOF
    ){
        MESO* new = create_new_element(tmp_oznaka,tmp_vrsta,tmp_cena);
        add_tolist(head,new);
    }
}


MESO* obrada(MESO* head,char vrsta_mesa[]){
    if(head == NULL){
        puts("Lista je prazna");
        return;
    }
    MESO* min=NULL;
    while(head != NULL){
        if(!(strcmp(head->vrsta_mesa,vrsta_mesa))){
            if(min == NULL){
                min = head;
            }
            else if(min->cena_mesa > head->cena_mesa){
                min = head;
            }
        }
        head= head->next;
    }

    return min;

}

void write_list_tofile(FILE* out,MESO* list){
    while(list !=NULL){
        fprintf(out,"%7.2lf %s %s\n",
        list->cena_mesa,list->vrsta_mesa,list->oznaka_grada);
        list= list->next;
    }
}

void write_one_tofile(FILE* out,MESO* one){
    fprintf(out,"  %7.2lf %s %s",one->cena_mesa,one->vrsta_mesa,one->oznaka_grada);
}

void destroy_list(MESO **head) {
    if(*head != NULL) {
        destroy_list(&((*head)->next));
        free(*head);
        *head = NULL;
    }
}

int main(int br_args,char **args){
    if(br_args != 4){
        puts("Pogresan poziv programa! \n Usage: ./program tip_mesa ulaz.txt izlaz.txt");
        exit(EXIT_FAILURE);
    }
    char *tip_mesa = args[1];
    MESO *meso=NULL;
    FILE *in = safe_open(args[2],"r");
    ucitaj_podatke(in,&meso);
    FILE *out = safe_open(args[3],"w");
    MESO * best = obrada(meso,tip_mesa);
    write_list_tofile(out,meso);
    if(!best){
        fprintf(out, "\nNigde nema '%s'!\n", tip_mesa);
    }
    else{
        fprintf(out, "\nNajpovoljnija '%s' je:\n",tip_mesa);
        write_one_tofile(out,best);
    }
    fclose(in);
    fclose(out);
    destroy_list(&meso);

}