#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 20+1
#define MAX_NIZ 30

struct pacijent_st{
    char ime[MAX_STRING];
    char prezime[MAX_STRING];
    double holesterol;
    int krvni_pritisak;
    double secer_u_krvi;
};

struct analiza_st{
    char upozorenje;
    char ime[MAX_STRING];
    char prezime[MAX_STRING];
};


FILE *safe_fopen(char *name, char *mode);
int ucitaj_pacijente(FILE *in,struct pacijent_st pacijenti[]);
void ispisi_analizu(FILE *out, struct analiza_st analiza[],int n);
void obrada(char *vrednost,struct pacijent_st pacijenti[],struct analiza_st analiza[],int n);



int main(int num_args, char **args) {
    if(num_args != 4) {
        printf("USAGE: %s pacijenti.txt analiza.txt", args[0]);
        exit(1);
    }

    char *vrednost = args[1];
    FILE *in = safe_fopen(args[2],"r");
    FILE *out = safe_fopen(args[3],"w");

    struct pacijent_st pacijenti[MAX_NIZ];
    struct analiza_st analiza[MAX_NIZ];

    int n = ucitaj_pacijente(in,pacijenti);
    obrada(vrednost,pacijenti,analiza,n);
    ispisi_analizu(out,analiza,n);

    fclose(in);
    fclose(out);
    return 0;
}

FILE *safe_fopen(char *name, char *mode) {
    FILE *pf = fopen(name, mode);
    if(pf == NULL) {
        printf("File '%s' could not be opened!\n", name);
        exit(EXIT_FAILURE);
    }
    return pf;
}

int ucitaj_pacijente(FILE *in,struct pacijent_st pacijenti[]){
    int n = 0;

    while(
        fscanf(
            in,"%s %s %lf %d %lf",
            pacijenti[n].ime,
            pacijenti[n].prezime,
            &pacijenti[n].holesterol,
            &pacijenti[n].krvni_pritisak,
            &pacijenti[n].secer_u_krvi
            ) != EOF
    ) n++;

    return n;
}

void ispisi_analizu(FILE *out, struct analiza_st analiza[],int n){
    int i=0;
    for(i = 0; i < n; i++){
        fprintf(
            out,"%c %s %s\n",
            analiza[i].upozorenje,
            analiza[i].ime,
            analiza[i].prezime
            );
    }
}

void obrada(char *vrednost,struct pacijent_st pacijenti[],struct analiza_st analiza[],int n)
{
    int i=0;

    for(i=0;i<n;i++){
        strcpy(analiza[i].ime,pacijenti[i].ime);
        strcpy(analiza[i].prezime,pacijenti[i].prezime);
        if(strcmp(vrednost,"pritisak")==0){
            analiza[i].upozorenje = (pacijenti[i].krvni_pritisak  >= 90 && pacijenti[i].krvni_pritisak < 120) ? '-': '+' ;
        }
        else if(strcmp(vrednost,"holesterol")==0){
            analiza[i].upozorenje = (pacijenti[i].holesterol < 5.2) ? '-': '+' ;

        }
        else if(strcmp(vrednost,"holesterol")==0){
            analiza[i].upozorenje = (pacijenti[i].secer_u_krvi >= 3.9 && pacijenti[i].secer_u_krvi < 5.6) ? '-': '+' ;

        }
        else{
            puts("Navedena vrednost nije moguce obraditi!\n");
            break;
        }
    }
}
