#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"chaine.h"
#include"text.h"
#include"Prefix_Suffixe.h"
#include"Dicho.h"
#include"Dicho_MAT.h"
#include"Rech_Arbre.h"
#include"FREQ.h"
void MENU()
{
    int choix=0;
    printf("________________________________________________________________________________");
    printf("|                     ****CHOISIR UN DES CHOIX :                               | \n");
    printf("|          ****1 - POUR MANIPULER LES PREFIXE ET SUFFIXES DE CHAINE CARECTERE :|\n");
    printf("|          ****2 - POUR MANIPULER UN DICTIONAIRE PAR LES FICHIER :             |\n");
    printf("|          ****3 - POUR MANIPULER UN DICTIONAIRE PAR UN MATRICE :              |\n");
    printf("|          ****4 - POUR MANIPULER UN DICTIONAIRE PAR UN ARBRE BINAIRE :        |\n");
    printf("|          ****5 - POUR MANIPULER LES CHAINES DE CARACTERE :                   |\n");
    printf("|          ****6 - POUR MANIPULER LES CONTEXTE PAR LISTE CHINEE :              |\n");
    printf("|______________________________________________________________________________|\n\n\n");
    do {scanf("%d", &choix);}while(choix>6||choix<1);
    switch(choix)
    {
     case 1 :{ int i=0;
                printf("________________________________________________________________________________");
                printf("|                     ****CHOISIR UN DES CHOIX :                               |\n");
                printf("|    ****1 - POUR MANIPULER LES PREFIXE DE CHAINE CARECTERE :                  |\n");
                printf("|     ****2 - POUR MANIPULER LES SUFFIXES DE CHAINE CARECTERE :                |\n");
                printf("|______________________________________________________________________________|\n\n");
                do{scanf("%d", &i);}while(i>2||i<1);
                if(i==1)
                { int j=0;
                 printf("________________________________________________________________________________");
                  printf("              ****CHOISIR UN DES FONCTION : \n");
                  printf("\n\n****1 - POUR AFFICHER LES PREFIXE DE CHAINE CARECTERE : \n");
                  printf("\n\n****2 - POUR AFFICHER LE PLUS LONG PREFIXE COMMUN A DEUX CHAINE CARECTERE S1 ET S2 : \n");
                  printf("\n\n****3 - POUR VERIFIER SI UNE CHAINE CARECTERE P EST UN PREFIXE DE UNE CHAINE CARECTERE S : \n");
                  printf("\n\n****4 - POUR COMPTER ET AFFICHER NOMBRE DE MOTS \nQUI ONT UN DEBUT COMMUN AVEC UN MOT M DE PLUS DE R CARECTERE DONNEE : \n");
                  printf("________________________________________________________________________________\n\n");
                  do {scanf("%d", &j);}while(j>4||j<1);
                  switch(j)
                  {
                      case 1:{
                          char* s=NULL;
                          printf("\n**** DONNER LA CHAINE  S : \n");
                          s  = (char*)malloc(sizeof(char)*255);
                          scanf(" %s", s);
                          tous_prefix(s);

                             };break;

                      case 2:{
                          char* s=NULL;
                          printf("\n**** DONNER LA CHAINE  S1 : \n");
                          s = (char*)malloc(sizeof(char)*255);
                          scanf(" %s", s);

                          char* t=NULL;
                          printf("\n**** DONNER LA CHAINE  S2 : \n");
                          t = (char*)malloc(sizeof(char)*255);
                          scanf(" %s", t);

                          char* loo=NULL;

                          loo = plulongpre(s,t);
                          printf("\nLE PLUS LONG PREFIXE EN COMMUN : %s\n", loo);


                             };break;
                      case 3:{
                               char* s=NULL;

                              printf("\n**** DONNER LA CHAINE  S : \n");
                              s = (char*)malloc(sizeof(char)*255);
                              scanf(" %s", s);

                              char* t=NULL;

                              printf("\n**** DONNER LA CHAINE  P : \n");
                               t = (char*)malloc(sizeof(char)*255);
                              scanf(" %s", t);
                              int E;
                              E=estprefixde(s,t);
                              if(E==0)
                              {
                                  printf("\n*** LA CHAINE P : %s N EST PAS UNE PREFIXE POUR LA CHAINE S : %s \n", t, s);

                              }else
                              {
                                  printf("\n*** LA CHAINE P : %s  EST UNE PREFIXE POUR LA CHAINE S : %s \n", t, s);

                              }

                             };break;
                      case 4:{
                              char* s=NULL;
                              printf("\n**** DONNER LA CHAINE  S : \n");
                              s = (char*)malloc(sizeof(char)*255);
                              scanf(" %s", s);
                              int n,r;
                              printf("\n****ENTRE NOMBRE DE MOT DONNEE :\n");
                              scanf("%d", &n);
                              printf("\n****ENTRE NOMBRE DE CARECTERE A COMPARER :\n");
                              scanf("%d", &r);
                              int cp;
                              cp = nbrcommun(s,n,r);
                              printf("\n**** NOMBRE DE MOTS QUI ONT UN DEBUT COMMUN AVEC   %s   EST  :  %d  \n", s, cp);

                              };break;
                  }
                }else
                {int j=0;
                printf("________________________________________________________________________________");
                  printf("\n           ****CHOISIR UN DES FONCTION : \n");
                  printf("\n\n****1 - POUR AFFICHER L ENSEMBLE DES SUFFIXES D UN CHAINE CARECTERE S : \n");
                  printf("\n\n****2 - POUR AFFICHER TOUS LES POSITIONS DE DEBUT DE TOUTES LES OCCURRENCES DE  CHAINE P DANS UN CHAINE S : \n");
                printf("________________________________________________________________________________\n\n");
                 do {scanf("%d", &j);}while(j>2||j<1);
                    if(j==1)
                    {
                        char* s=NULL;

                       printf("\n**** DONNER LA CHAINE  S : \n");
                        s = (char*)malloc(sizeof(char)*255);
                        scanf(" %s", s);
                        suffixe* t=NULL;
                         int k;
                         t=extrairesuffixes(s);
                        for(k=0;k<strlen(s);k++)
                        {
                               printf("\n**LE %d EME SUFFIX EST  : %s\n", t[k].id+1, t[k].suf);

                         }
                    }else
                    {
                         char* s=NULL;

                         printf("\n**** DONNER LA CHAINE  S : \n");
                         s = (char*)malloc(sizeof(char)*255);
                         //scanf(" %s", s);
                         scanf("%[^\n]",s);
                         char* t=NULL;
                         printf("\n**** DONNER LA CHAINE  P : \n");
                         t = (char*)malloc(sizeof(char)*255);
                         scanf(" %s", t);



                         occurrences(t,s);


                    }
                }
            };break;
      case 2:
            {    int i=0;
                 printf("_____________________________________________________________________________");
                 printf("|              ****CHOISIR UN DES FONCTION :                                |\n");
                 printf("|\n****1 - POUR VERIFIER SI UN FIFCHIER F1 EST SOUS FICHIER DU FICHIER F2 : |\n");
                 printf("|\n****2 - POUR RECHERCHER UN MOT DANS UN DICTIONAIRE :                     |\n");
                 printf("|\n****3 - POUR TROUVER TOUS LES MOTS QUI NE SONT PAS DANS DICTIONAIRE  :   |\n");
                 printf("|___________________________________________________________________________|\n\n");
                do{scanf("%d", &i);}while(i>3||i<1);
                switch(i)
                {
                    case 1:
                        {
    FILE* F1 = NULL;
    FILE* F2 = NULL;
    F1 = fopen("C:/Users/younes/Desktop/projet tp/exo/dos/F1.txt", "w");
    F2 = fopen("C:/Users/younes/Desktop/projet tp/exo/dos/F2.txt", "w");
    char* s=NULL;

    int n, i;
    int so;

if (F1 != NULL)
{
if(F2 !=NULL)
{
    printf("**DONNER NOMBRE DE MOT : \n");
    scanf(" %d", &n);
     for(i=0;i<n;i++)
      {
        if(i==n-1)
        {
             printf("DONNER LA %d EME CHAINE  S2 : \n", i);
               s = (char*)malloc(sizeof(char)*255);
               scanf(" %s", s);
           fprintf(F2,"%s", s);
      }else
      {


             printf("DONNER LA %d EME CHAINE S2 : \n", i);
               s = (char*)malloc(sizeof(char)*255);
               scanf(" %s", s);
           fprintf(F2,"%s ", s);
      }
      }
      fclose(F2);
      for(i=0;i<n;i++)
      {

       if(i==n-1)
       {

             printf("DONNER LA %d EME CHAINE S1 : \n", i);
               s = (char*)malloc(sizeof(char)*255);
               scanf(" %s", s);
           fprintf(F1,"%s", s);
       }else
       {

             printf("DONNER LA %d EME CHAINE S1 : \n", i);
               s = (char*)malloc(sizeof(char)*255);
               scanf(" %s", s);
           fprintf(F1,"%s ", s);
       }
}
fclose(F1);
}else
{
    printf("Impossible d'ouvrir le fichier F2.txt");
}


}
else
{

printf("Impossible d'ouvrir le fichier F1.txt");
}

F1 = fopen("C:/Users/younes/Desktop/projet tp/exo/dos/F1.txt", "r");
F2 = fopen("C:/Users/younes/Desktop/projet tp/exo/dos/F2.txt", "r");
so = Sous_Fichier(F1,F2);
if(so==1)
{
    printf("\n*****F1 EST UN SOUS FICHIER DE F2*****\n");
}else
{
    printf("\n*****F1 N EST PAS UN SOUS FICHIER DE F2*****\n");
}
printf("%d", so);
fclose(F1);
fclose(F2);


                        };break;
                    case 2:
                        {
    FILE* F1 = NULL;
    F1 = fopen("C:/Users/younes/Desktop/projet tp/exo/dictionnaire.txt", "r");
if (F1 != NULL)
{
  char* MOT=NULL;
  MOT = (char*)malloc(20*sizeof(char));
  printf("\n**ENTRER MOT : \n");
  scanf(" %s", MOT);
  TROUVE_MOT(MOT,F1);
fclose(F1);
}else
{
printf("erreur dans l'ouverture fe fichier");
}

                        };break;
                    case 3:
                        {

    FILE* F1 = NULL;
    FILE* T=NULL;
    F1 = fopen("C:/Users/younes/Desktop/projet tp/exo/dictionnaire.txt", "r");
    T=fopen("C:/Users/younes/Desktop/isil/File.txt", "r");

if ((F1 != NULL)&&(T!=NULL))
{
MOT_HORS_DECO(T,F1);

fclose(F1);
fclose(T);

}else
{
printf("erreur dans l'ouverture fe fichier");
}

                        };break;
                }



                };break;
    case 3:
        {
            int i=0;
                 printf("______________________________________________________________________________");
                 printf("|\n               ****CHOISIR UN DES FONCTION :                                  |\n");
                 printf("|\n    ****1 - POUR RECHERCHER UN MOT DANS UN DICTIONAIRE :                    |\n");
                 printf("|\n     ****2 - POUR TROUVER TOUS LES MOTS QUI NE SONT PAS DANS DICTIONAIRE  :  |\n");
                 printf("|_____________________________________________________________________________|\n\n");
                do{scanf("%d", &i);}while(i>2||i<1);

                    if(i==1)
                    {

                          FILE* F1 = NULL;
                         char* s=NULL;
                         s = (char*)malloc(sizeof(char)*1000);

                         F1 = fopen("C:/Users/younes/Desktop/isil/dictionnaire.txt", "r");

                         if (F1 != NULL)
                              {
                                 int i;

                                 i=0;
                                 int nbl=0;
                                 while(!feof(F1))
                                  {
                                      nbl = nbl + 1;

                                      fgets(s,1000,F1);

                                    }
                               char** DICO = NULL;
                               DICO = (char**)malloc(sizeof(char*)*nbl);

                               rewind(F1);

                              for(i=0;i<nbl;i++)
                                 {

                                   fgets(s,1000,F1);
                                   DICO[i]=(char*)malloc(sizeof(char)*1000);
                                   strcpy(DICO[i],s);
                                  }

                                   fclose(F1);

                                 char* ch=NULL;
                                 ch=(char*)calloc(20,sizeof(char));
                                 printf("\n**ENTRER MOT : \n");
                                 scanf("%s", ch);

                                 TROUVE_MOT_TAB(ch,DICO);


}else
{
printf("erreur dans l'ouverture fe fichier");
}


                    }else
                    {   FILE* F1 = NULL;
                        char* s=NULL;
                         s = (char*)malloc(sizeof(char)*1000);

                           F1 = fopen("C:/Users/younes/Desktop/projet tp/exo/dictionnaire.txt", "r");

                            FILE* T = NULL;
                            char* t=NULL;
                           t = (char*)malloc(sizeof(char)*1000);

                           T = fopen("C:/Users/younes/Desktop/isil/File.txt", "r");

                           if ((F1 != NULL)&&(T!=NULL))
                             {
                               int i;

                                 i=0;
                              int nbl=0;
                          while(!feof(F1))
                             {
                                nbl = nbl + 1;

                                fgets(s,1000,F1);

                               }
                               char** DICO = NULL;
                                DICO = (char**)malloc(sizeof(char*)*nbl);

                                rewind(F1);

                                 for(i=0;i<nbl;i++)
                                   {

                                      fgets(s,1000,F1);
                                      DICO[i]=(char*)malloc(sizeof(char)*1000);
                                      strcpy(DICO[i],s);
                                       }
                                    int j;
                                    j=0;
                                    int nbl2=0;
                                 while(!feof(T))
                                    {
                                      nbl2 = nbl2 + 1;

                                   fgets(t,1000,T);

                                        }

                                         char** DICO2 = NULL;
                                           DICO2 = (char**)malloc(sizeof(char*)*nbl2);

                                         rewind(T);

                                        for(j=0;j<nbl2;j++)
                                          {

                                           fgets(t,20,T);
                                            DICO2[j]=(char*)malloc(sizeof(char)*20);
                                               strcpy(DICO2[j],t);
                                              }

                                             fclose(F1);
                                             fclose(T);


                                        MOTS_HORS_DICO_TAB(DICO2,DICO,nbl2);
}else
{
printf("erreur dans l'ouverture fe fichier");
}


                    }

        };break;
    case 4:
        {
            int i=0;
                 printf("______________________________________________________________________________");
                 printf("|\n               ****CHOISIR UN DES FONCTION :                                  |\n");
                 printf("|\n    ****1 - POUR RECHERCHER UN MOT DANS UN DICTIONAIRE :                    |\n");
                 printf("|\n     ****2 - POUR TROUVER TOUS LES MOTS QUI NE SONT PAS DANS DICTIONAIRE  :  |\n");
                 printf("|_____________________________________________________________________________|\n\n");
                do{scanf("%d", &i);}while(i>2||i<1);
                if(i==1)
                {
    FILE*F=NULL;
	Dict* Di;
	arbre A;
	long i;
	char* s=NULL;
	s=(char*)malloc(sizeof(char)*1000);
	F=fopen("C:/Users/younes/Desktop/projet tp/exo/dictionnaire.txt", "r");
	 i=0;
                                 while(!feof(F))
                                  {
                                      i = i + 1;

                                      fgets(s,1000,F);

                                    }

	rewind(F);
	Di=CreerTable_DeDict(F,i);
	A=creation_arbre(Di,0,i);
	 char* MOT=NULL;
  MOT = (char*)malloc(20*sizeof(char));
  printf("\n**ENTRER MOT : \n");
  scanf(" %s", MOT);
	TrouveMotArbr(MOT,A);




                }else
                { FILE*F,*F1;
	Dict* Di,*d1;
	arbre A,a;
	long i,j;
	char* s=NULL;
	s=(char*)malloc(sizeof(char)*1000);
	F=fopen("C:/Users/younes/Desktop/projet tp/exo/dictionnaire.txt", "r");
	F1=fopen("exemple.txt","r");
	 i=0;
                                 while(!feof(F))
                                  {
                                      i = i + 1;

                                      fgets(s,1000,F);

                                    }

	rewind(F);
	j=0;
                                 while(!feof(F1))
                                  {
                                      j = j + 1;

                                      fgets(s,1000,F1);

                                    }

	rewind(F1);
	Di=CreerTable_DeDict(F,i);
	d1=CreerTable_DeDict(F1,j);
	A=creation_arbre(Di,0,i);
	a=creation_arbre(d1,0,j-1);
	MotsHorsArbre(a,A);





                }


        };break;


        case 5:{

        	int choix2;
	do
	{   printf("_____________________________________________________________________________");
		printf("   |                   Choisir une operation :                                 |\n");
		printf("|     1-inserer un mot dans un autre mot                                    |\n");
		printf("|     2-inserer les n premiers caracteres d un mot dans un autre mot        |\n");
		printf("|     3-ordoner les caracteres dans l ordre lexographique                   |\n");
		printf("|     4-donner le nombre d occurences d un caractere dans un mot            |\n");
		printf("|     5-donner le nombre d occurences de chanque caractere dans un mot      |\n");
		printf("|     6-verifier si deux mots sont anagrammes                               |\n");
		printf("|     7-verifier si deux mots sont mirroires                                |\n");
		printf("|     8-verifier si deux mots sont palindromme                              |\n");
		printf("|     9-supprimer des caracteres a partir d une position donnee             |\n");
		printf("|     autre-retourner au menu principal                                     |\n");
		printf("|___________________________________________________________________________|\n\n");
		scanf("%d",&choix2);
		switch(choix2)
		{

			case 1 :
			{
				char* m=(char*)malloc(255*sizeof(char));
            	char* t=(char*)malloc(255*sizeof(char));
            	printf("donner la 1ere chaine : \n");
            	scanf("%s",m);
            	printf("donner la 2eme chaine : \n");
            	scanf("%s",t);
            	printf("donner la position : \n");
            	int i;
            	scanf("%d",&i);
            	strinsert(m , t , i);
            	printf("%s\n",m);
            	printf("\n");
			}	break;
			case 2 :
			{
            	printf("donner la 1er chaine : \n");
            	char* m1=(char*)malloc(255*sizeof(char));
            	scanf("%s",m1);
            	printf("donner la 2eme chaine t : \n");
            	char* t1=(char*)malloc(255*sizeof(char));
            	scanf("%s",t1);
            	printf("donner le nombre de characteres : \n");
            	int n,i;
            	scanf("%d",&n);
            	printf("donner la position : \n");
            	scanf("%d",&i);
            	strninsert(m1 , t1 , i ,n);
            	printf("%s\n",m1);
            	printf("\n");
			}	break;
			case 3 :
			{
				printf("donner la chaine : \n");
				char* m=(char*)malloc(255*sizeof(char));
            	scanf("%s",m);
            	printf("la chaine ordonee :  ");
                printf("%s\n",alphabet(m));
                printf("\n");
			}	break;
			case 4 :
			{

	            printf("donner la chaine : \n");
                char* m=(char*)malloc(255*sizeof(char));
            	scanf("%s",m);
            	printf("donner le caractere : \n");
				char c;
	            scanf("%c",&c);
            	printf("le nombre d occurences est : ");
                printf("%d \n",freqchar(m , c));
                printf("\n");
			}	break;
			case 5 :
			{
				printf("donner la chaine : \n");
				char* m=(char*)malloc(255*sizeof(char));
            	scanf("%s",m);
            	freq* fr=frequences(m);
            	printf("le nombre d occurences de chaque caractere :\n");
            	int i;
            	for(i=0;i<strlen(alphabet(m));i++)
            	{
            		printf("%c %d\n",fr[i].c ,fr[i].occ);
				}
				printf("\n");
			}	break;
			case 6 :
			{
				printf("donner la 1ere chaine : \n");
				char* s1=(char*)malloc(255*sizeof(char));
            	scanf("%s",s1);
            	printf("donner la 2eme chaine : \n");
            	char* s2=(char*)malloc(255*sizeof(char));
            	scanf("%s",s2);
            	if(anagramme(s1,s2)==1)
            	{
            		printf("les deux chaines sont anagrammes\n");
				}
				else
				{
					printf("les deux chaines ne sont pas anagrammes\n");
				}
				printf("\n");
			}	break;
			case 7 :
			{
				printf("donner la 1ere chaine : \n");
				char* s1=(char*)malloc(255*sizeof(char));
            	scanf("%s",s1);
            	printf("donner la 2eme chaine : \n");
            	char* s2=(char*)malloc(255*sizeof(char));
            	scanf("%s",s2);
            	if(mirroire(s1,s2)==1)
            	{
            		printf("les deux chaines sont mirroires\n");
				}
				else
				{
					printf("les deux chaines ne sont pas mirroires\n");
				}
				printf("\n");
			}	break;
			case 8 :
		    {
				printf("donner la chaine : \n");
				char* s1=(char*)malloc(255*sizeof(char));
            	scanf("%s",s1);
            	if(Palindrome(s1)==1)
            	{
            		printf("la chaine est palindromme\n");
				}
				else
				{
					printf("la chaine n est pas palindromme\n");
				}
				printf("\n");
			}	break;
			case 9 :
			{
				printf("donner la chaine : \n");
				char* s1=(char*)malloc(255*sizeof(char));
            	scanf("%s",s1);
            	printf("donner le nombre de caracteres a suprimer :\n");
            	int n;
            	scanf("%d",&n);
            	printf("donner la position du 1er caractere a suprimer :\n");
            	int i;
            	scanf("%d",&i);
            	printf("la chaine apres la supression : ");
            	strndel(s1,n,i);
            	printf("%s\n",s1);
            	printf("\n");
			}	break;

		}

    }while(choix2<10);

  }break;
  case 6:{
  	int choix3;
  	do
  	{
  		printf("choisir l operation : \n");
  		printf("1-afficher la liste des mots d un text  \n");
  		printf("2-afficher la liste des frequences des mots de d un text \n");
  		printf("3-afficher la liste des contextes d un mot \n");
  		printf("4-donner le mot le plus frequent dans un contexte \n");
  		printf("autre-quitter le programme \n");
  		scanf("%d",&choix3);
  		switch(choix3)
  		{
  			case 1:{
  				text* t=remplir();
  				affichtext(t);
  				listemots* tete=motsde(t);
  				listemots* c=tete;
  				while(c!=NULL);
  				{
  					printf(">%s\n",c->mot);
  					c=c->suivant;
				}
				break;
			  }
			  case 2:{
			  	text* t=remplir();
			  	affichtext(t);
			  	listfreq* tete=frequencesde(t);
			  	listfreq* c=tete;
  				while(c!=NULL);
  				{
  					printf("%s ----> %d\n",c->mot,c->freq);
  					c=c->suivant;
  			    }
				break;
			  }
			  case 3:{
			  	text* t=remplir();
			  	affichtext(t);
			  	printf("donner le mot : \n");
			  	char* mot=(char*)malloc(255*sizeof(char));
			  	scanf("%s",mot);
			  	listfreq* tete=contexte(t , mot);
			  	listfreq* c=tete;
  				while(c!=NULL);
  				{
  					printf("%s ----> %d\n",c->mot,c->freq);
  					c=c->suivant;
  			    }

				break;
			  }
			  case 4:{
			  	text* t=remplir();
			  	affichtext(t);
			  	dictcontext* d=creerdictcontext(t);
			  	printf("donner un mot : \n");
			  	char* m=(char*)malloc(255*sizeof(char));
			  	scanf("%s",m);
			  	printf("%s",maxcontexte(d,m));
				break;
			  }
		  }
	}while(choix3<5 && choix3>0);
	break;
  }
}
}

