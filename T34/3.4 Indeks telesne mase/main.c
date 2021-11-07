#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pacijent_st {
    char ime[21];
    char prezime[21];
    unsigned int masa;
    double visina;
}pacijent;

typedef struct analiza_st{
    char ime[21];
    char prezime[21];
    double bmi;
    char dijagnoza[31];
}analiza;

FILE *safe_fopen(char *name, char *mode);
void obrada(pacijent pacijenti[],analiza analize[],int n);
int ucitaj_podatke(FILE *in,pacijent pacijenti[]);
void ispisi_podatke(FILE *out,analiza analize[],int n);

int main(int num_args, char **args) {
    if(num_args != 3) {
        printf("USAGE: %s in.txt out.txt", args[0]);
        exit(1);
    }

    FILE *in = safe_fopen(args[1],"r");
    FILE *out = safe_fopen(args[2],"w");

    pacijent pacijenti[30];
    analiza analize[30];
    int n = ucitaj_podatke(in,pacijenti);
    obrada(pacijenti,analize,n);
    ispisi_podatke(out,analize,n);

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

int ucitaj_podatke(FILE *in,pacijent pacijenti[]){
    int n = 0;
    while(fscanf(in,
    "%s %s %u %lf",
    pacijenti[n].ime,
    pacijenti[n].prezime,
    &pacijenti[n].masa,
    &pacijenti[n].visina
    ) != EOF){
        n++;
    }
    return n;
}
void ispisi_podatke(FILE *out,analiza analize[],int n){
    int i;
    for(i=0;i<n;i++){
        fprintf(out,
        "%s %s %7.2lf %s\n",
        analize[i].ime,
        analize[i].prezime,
        analize[i].bmi,
        analize[i].dijagnoza);
    }
}

void obrada(pacijent pacijenti[],analiza analize[],int n){
    int i;
    for(i=0;i<n;i++){
        strcpy(analize[i].ime,pacijenti[i].ime);
        strcpy(analize[i].prezime,pacijenti[i].prezime);
        analize[i].bmi = (double)pacijenti[i].masa / (pacijenti[i].visina*pacijenti[i].visina);
        if(analize[i].bmi<18.5){
            strcpy(analize[i].dijagnoza,"Pothranjenost");
        }
    else if(analize[i].bmi<25.0){
            strcpy(analize[i].dijagnoza,"Idealna tezina");
        }
    else if(analize[i].bmi<30.0){
            strcpy(analize[i].dijagnoza,"Prekomerna tezina");
        }
    else if(analize[i].bmi >=30.0){
            strcpy(analize[i].dijagnoza,"Gojaznost");
        }
    }
}