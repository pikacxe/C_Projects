#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NAZIV_IGRA 11
#define NAZIV_ZANR 9
#define NAZIV_PLATFORMA 9


typedef struct igra_st{
    char naziv[NAZIV_IGRA];
    char zanr[NAZIV_ZANR];
    char platforma[NAZIV_PLATFORMA];
    double cena_igre;
    struct igra_st* next;
}IGRA;


FILE* safe_open(char name[], char mode[]){
    FILE* fp = fopen(name,mode);
    if(!fp){
        printf("Nemoguce otvoriti file: %s\n",name);
        exit(EXIT_FAILURE);
    }
    return fp;
}

IGRA* create_new_element(char naziv[],char zanr[],char platforma[], double cena){
    IGRA* new = (IGRA*) malloc(sizeof(IGRA));
    if(!new){
        puts("Not enough RAM!\n");
        exit(EXIT_FAILURE);
    }

    strcpy(new->naziv,naziv);
    strcpy(new->platforma,platforma);
    strcpy(new->zanr,zanr);
    new->cena_igre = cena;
    
    new->next = NULL;
    
    return new;
}

void add(IGRA** head,IGRA* new){
    if(*head==NULL){
        *head = new;
        return;
    }
    add(&((*head)->next),new);
}

void read_from_file(FILE* in,IGRA** head){
    char naziv[NAZIV_IGRA];
    char zanr[NAZIV_ZANR];
    char platforma[NAZIV_PLATFORMA];
    double cena;
    while(
        fscanf(in,"%s %s %s %lf",
        naziv,
        zanr,platforma,&cena)!=EOF
    ){
        IGRA* new = create_new_element(naziv,zanr,platforma,cena);
        add(head,new);
    }
}


void safe_list_to_file(FILE* out,IGRA* head){
    while(head !=NULL){
        fprintf(out,"%-10s %-8s %-8s %5.2lf\n",
        head->naziv,head->zanr,head->platforma,head->cena_igre);
        head = head->next;
    }

}

IGRA* find_best(IGRA* head, char platforma[], char zanr[]){
    IGRA* best= NULL;
    while(head != NULL){
        if(strcmp(head->platforma,platforma)==0 && strcmp(head->zanr,zanr)==0){
            if(best == NULL){
                best = head;
            }
            else if(best->cena_igre > head->cena_igre){
                best = head;
            }
        }
        head = head->next;
    }


    return best;
}

void write_best(FILE* out, IGRA* best){
    fprintf(out,"%-10s %-8s %-8s %5.2lf\n",
        best->naziv,best->zanr,best->platforma,best->cena_igre);
        best = best->next;
}

void destroy_list(IGRA** head){
    if(*head !=NULL){
        destroy_list((&(*head)->next));
        free(*head);
        *head = NULL;
    }
}



int main(int br_args,char **args){
    if(br_args != 5){
        puts("Pogresan poziv programa\nPrimer poziva: ./program PC Sandbox igra.txt analiza.txt");
        exit(EXIT_FAILURE);
    }
char *platforma = args[1];
char *zanr = args[2];

FILE* in = safe_open(args[3],"r");
FILE* out = safe_open(args[4],"w");
IGRA* list = NULL;
read_from_file(in,&list);
safe_list_to_file(out,list);
IGRA* best = find_best(list,platforma,zanr);
if(best == NULL){
    fprintf(out,"\nZa %s platformu ne postoje '%s' igre!\n",platforma,zanr);
}
else{
    fprintf(out,"\nNajpovoljnija '%s' igra za %s platformu je:\n",zanr,platforma);
    write_best(out,best);
}

fclose(in);
fclose(out);
destroy_list(&list);

    return 0;
}
