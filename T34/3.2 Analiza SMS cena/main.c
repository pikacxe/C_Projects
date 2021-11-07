#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


struct paket_st
{
   char provajder[21];
   char naziv_paketa[21];
   int pretplata;
   int mesecno_poruka;
   double cena_poruke; 
};

struct cene_st{
  double cena_paketa;
  char provajder[21];
  char naziv_paketa[21];  
};


FILE *safe_fopen(char *name, char *mode) {
    FILE *pf = fopen(name, mode);
    if(pf == NULL) {
        printf("File %s could not be opened!\n", name);
        exit(EXIT_FAILURE);
    }
    return pf;
}

int ucitaj_podatke(FILE *in,struct paket_st podaci[]){
    int br=0;
    while(fscanf(in,"%s %s %d %d %lf",
    podaci[br].provajder,
    podaci[br].naziv_paketa,
    &podaci[br].pretplata,
    &podaci[br].mesecno_poruka,
    &podaci[br].cena_poruke) != EOF){
        br++;
    }
    return br;
}

void ispisi_podatke(struct cene_st podaci[],FILE *out,int n){
    int i;
    for(i=0;i<n;i++){
        fprintf(out,
        "%7.2lf %s %s\n",
        podaci[i].cena_paketa,
        podaci[i].provajder,
        podaci[i].naziv_paketa);
    }

}

void obrada(struct paket_st in[],struct cene_st out[],int n,int poruke){
    int i,pom;
    for(i=0;i<n;i++){
        strcpy(out[i].naziv_paketa,in[i].naziv_paketa);
        strcpy(out[i].provajder,in[i].provajder);
        pom = poruke - in[i].mesecno_poruka;
        out[i].cena_paketa = pom > 0 ?
         (abs(pom) * in[i].cena_poruke+in[i].pretplata):
                                        in[i].pretplata;
    }

}

int main(int num_args, char **args) {
    if(num_args != 4) {
        printf("USAGE: %s number in.txt out.txt", args[0]);
        exit(1);
    }
    int poruke = atoi(args[1]);
    FILE *in = safe_fopen(args[2],"r");
    FILE *out = safe_fopen(args[3],"w");
    struct paket_st podaci[30];
    struct cene_st  cene[30];
    int n = ucitaj_podatke(in,podaci);
    obrada(podaci,cene,n,poruke);
    ispisi_podatke(cene,out,n);
    fclose(in);
    fclose(out);
    return 0;
}
