#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Dicho.h"
char* EXTRAIRE_MOT(FILE* F1)
{
    int i;
    char c;
    char* s=NULL;

    s = (char*)calloc(20,sizeof(char));

    c = fgetc(F1);

    i=0;

    while(c!=',')
    {
        s[i] = c;
        i++;
        c = fgetc(F1);
    }

return s;
}

long Mellieu(FILE* F1,int DEBUT, int FIN)
{
    int M;
    //char* tmp=NULL;
    //tmp = (char*)malloc(sizeof(char)*1000);
    M = (DEBUT + FIN)/2;
    fseek(F1,M,SEEK_SET);
   //fgets(tmp,1000,F1);

return ftell(F1);
}
long EXISTE(char *Mot, FILE *F1)
{
   char* S=NULL;
   char* tmp=NULL;
   int debut,fin;


   S=(char*)malloc(sizeof(char)*20);

   fseek(F1,0,SEEK_END);
   fin= ftell(F1);

   fseek(F1,0,SEEK_SET);
   debut=ftell(F1);

   tmp=malloc(sizeof(char)*1000);


   rewind(F1);
  fgets(tmp,1000,F1);


      if(strcmp(EXTRAIRE_MOT(F1),Mot)==0) // Le cas du premir mot du fichier
              {
                fseek(F1,-(strlen(Mot)+1),SEEK_CUR);
                return ftell(F1);
               }

   rewind(F1);

    int    nb = 0;
     while(!feof(F1))//NOMBRE DE MOT
    {
        nb = nb + 1;
        fgets(tmp,1000,F1);

    }

   // printf("\nNOMBRE DE MOT : %d\n", nb);
    rewind(F1);
    Mellieu(F1,debut,fin);
    fgets(tmp,1000,F1);
    S=EXTRAIRE_MOT(F1);

   while((debut <= fin)&&(nb>1))
    {
       if(strcmp(S,Mot)<0)
        {
           //printf("Le mot est en BAS ! \n");
           debut=(debut+fin)/2;
           Mellieu(F1,debut,fin);
           fgets(tmp,1000,F1);
           S=EXTRAIRE_MOT(F1);
           //printf("\n DEBUT : %d et Fin : %d et Milieu : %ld \n ",debut,fin,mil);
        }

        if(strcmp(S,Mot)>0)
         {
            //printf("Le mot est en HAUT ! \n");
            fin=(fin+debut)/2;
            Mellieu(F1,debut,fin);
            fgets(tmp,1000,F1);
            S=EXTRAIRE_MOT(F1);
           // printf("\n DEBUT : %d et Fin : %d et Milieu : %ld \n ",debut,fin,mil);
         }

         if(strcmp(S,Mot)==0)
          {
              // printf("\n Mot trouvé ! \n ");
               fseek(F1,-(strlen(Mot)+1),SEEK_CUR);
               return ftell(F1);
          }
          nb = nb/2;
          //printf("\nNOMBRE DE MOT : %d\n", nb);

    }
   return -1;
}
char* TROUVE_MOT(char* Mot, FILE* F1)
{

  char* s=NULL;
  s=(char*)malloc(sizeof(char)*1000);

  if( EXISTE(Mot,F1)==-1)
  {
      printf("\nMOT :  %s  N'EXISTE PAS\n", Mot);
  }
  else
    {

        printf("\nMOT :  %s  EXISTE \n", Mot);
        fgets(s,1000,F1);
        printf("\n%s\n", s);
  }
  return s;
}
FILE* MOT_HORS_DECO(FILE *T,FILE* F1)
{
  FILE* F2 = NULL;
    char* s=NULL;
   s = (char*)malloc(sizeof(char)*1000);
    F2 = fopen("C:/Users/younes/Desktop/isil/File.txt", "w");
if (F2 != NULL)
{

    char*    mot=NULL;
    mot=(char*)calloc(20,sizeof(char));


    while(!feof(T))
    {

 mot=EXTRAIRE_MOT(T);
    if(EXISTE(mot,F1)==-1)
    {
        fputs(mot,F2);
        printf("\n%s\n", mot);
        fputs("\n",F2);
    }

    fgets(s,1000,T);

    }
fclose(F2);
}else
{
printf("erreur dans l'ouverture fe fichier");
}
return F2;

}
