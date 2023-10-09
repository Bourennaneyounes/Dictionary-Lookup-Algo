#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Dicho_MAT.h"
long Millieu_TAB(char** DICO, int DEBUT, int FIN)
{
	long m;
	m=(DEBUT+FIN)/2;
	return m;

}
long EXISTE_TAB(char* mot , char** DICO)
{
    int i;
    char* ch=NULL;
    	ch=(char*)calloc(20,sizeof(char));
    	for(i=0;i<20;i++)
        {
            ch[i]='\0';
        }
	int debut=0;
	int fin=0;
	long m;

	while(DICO[fin]!=NULL)
	{
		fin++;
	}
	fin--;

	char* s=(char*)calloc(1000,sizeof(char));

   while(fin-debut>1)
    {
        m=Millieu_TAB(DICO,debut,fin);
	strcpy(s,DICO[m]);
for(i=0;i<20;i++)
        {
            ch[i]='\0';
        }
    	i=0;
    	    	while(s[i]!=',')
    	{
    		ch[i]=s[i];

    		i++;
		}


        if(strcmp(ch , mot)<0)
		{

			debut=m;

		}
    	if(strcmp(ch , mot)>0)
    	{

    		fin=m;

		}

		if(strcmp(ch , mot)==0)
		{

			return m;
		}

	}

	strcpy(s,DICO[debut]);
   for(i=0;i<20;i++)
        {
            ch[i]='\0';
        }
	    	i=0;
    	    	while(s[i]!=',')
    	{
    		ch[i]=s[i];

    		i++;
		}
	if(strcmp(ch,mot)==0)
    {
        printf("\nmoot touve\n");
			return debut;
    }
        strcpy(s,DICO[fin]);
    for(i=0;i<20;i++)
        {
            ch[i]='\0';
        }
    	i=0;
    	    	while(s[i]!=',')
    	{
    		ch[i]=s[i];

    		i++;
		}
		if(strcmp(ch,mot)==0)
    {

			return fin;
    }


	return -1;

}
char* TROUVE_MOT_TAB(char* mot, char** DICO)
{

  char* s=NULL;
  s=(char*)malloc(sizeof(char)*1000);

  if( EXISTE_TAB(mot,DICO)==-1)
  {
      printf("\nMOT :  %s  N'EXISTE PAS\n", mot);
  }
  else
    {

        printf("\nMOT :  %s  EXISTE \n", mot);

        printf("\n%s\n", DICO[EXISTE_TAB(mot,DICO)]);
  }
  return s;

}
char** MOTS_HORS_DICO_TAB(char** FI , char** DICO,int nbl2)
{

	long i,j;
	int nb;
	nb=nbl2;

	char** DECO3 = NULL;
DECO3 = (char**)malloc(sizeof(char*)*nb);
j=0;

int k;
char* mot=NULL;
    mot=(char*)calloc(20,sizeof(char));
	for(i=0;i<nb;i++)
	{



    for(k=0;k<20;k++)
        {
            mot[k]='\0';
        }
      k=0;
while(FI[i][k]!=',')
{

    mot[k]=FI[i][k];
    k++;
}

		if(EXISTE_TAB(mot , DICO)==-1)
		{

        DECO3[j]=(char*)malloc(20*sizeof(char));
		strcpy(DECO3[j] , mot);
		puts(DECO3[j]);


j++;
	    }

	}
	return DECO3;

}

