#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct flotte{
    char Immatriculation[10];
    char Categorie[20];
    int Anciennete;
    float Kilometrage;
    float conso;
    int Entretien;
    int Etat;

}voiture;


int lirecsv(voiture tab[]){
    int nbvoiture = 0;
    FILE *jsp = fopen( "flotte50.csv", "r" );
    char ligne[200];
    if(jsp!=NULL){
        fgets(ligne,200,jsp);
        while(fgets(ligne,200,jsp) != NULL){
            char *morceau = strtok(ligne,",");
            strcpy(tab[nbvoiture].Immatriculation,morceau);
            morceau = strtok(NULL, ",");
            strcpy(tab[nbvoiture].Categorie,morceau);
            morceau = strtok(NULL, ",");
            tab[nbvoiture].Anciennete = atoi(morceau);
            morceau = strtok(NULL, ",");
            tab[nbvoiture].Kilometrage = atof(morceau);
            morceau = strtok(NULL, ",");
            tab[nbvoiture].conso = atof(morceau); 
            morceau = strtok(NULL, ",");
            tab[nbvoiture].Entretien = atoi(morceau);
            morceau = strtok(NULL, ",");
            tab[nbvoiture].Etat = atoi(morceau);
            nbvoiture++;

    
    
        }


    fclose(jsp);
    }



return nbvoiture;
}
void afficherFlotte(voiture tab[],int nbvoiture){
    printf("%-21s%-16s%-13s%-14s%-9s%-12s%-7s\n","Immatriculation","Categorie","Anciennete","Kilometrage","conso","Entretien","Etat");
    for(int i=0;i<nbvoiture;i++){
        printf("%-19s|",tab[i].Immatriculation);
        printf(" %-14s|",tab[i].Categorie);
        printf(" %-11d |",tab[i].Anciennete);
        printf(" %-12.1f|",tab[i].Kilometrage);
        printf(" %-7.1f|",tab[i].conso);
        printf(" %-10d|",tab[i].Entretien);
        printf(" %-5d\n",tab[i].Etat);




    }





}
void afficherligne(voiture v){
    printf("%-19s| %-14s| %-11d | %-12.1f| %-7.1f| %-10d| %-5d\n",
           v.Immatriculation, v.Categorie, v.Anciennete,
           v.Kilometrage, v.conso, v.Entretien, v.Etat);
}

void recherche(voiture tab[],int nbvoiture){
    char categoriecible[20];
    int trouve=0;
    printf("Entre la catégorie recherché");
    scanf("%s",&categoriecible);
    for(int i=0;i<nbvoiture;i++){
        if(strcmp(tab[i].Categorie, categoriecible)==0){
            afficherligne(tab[i]);
            trouve = 1;

        }
    }

}


int main(){
    voiture tab[100];
    int nb=lirecsv(tab);
    afficherFlotte(tab,nb);



    return 0;
}