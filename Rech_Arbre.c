#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Rech_Arbre.h"
Dict* CreerTable_DeDict(FILE* f,long nb)
{
	Dict* D;
	int i=0,j;
	char c;
	D=(Dict*)malloc(nb*sizeof(Dict));
	if(!feof(f))
	{
	    for(i=0;i<=nb-1;i++)
	    {
	    	D[i].Mot=(char*)malloc(50*sizeof(char));
	    	D[i].Def=(char*)malloc(8922*sizeof(char));
	    	c=fgetc(f);
	    	j=0;
	    	do
	    	{
	    		D[i].Mot[j]=c;
	    		j++;
	    		c=fgetc(f);
			}while(c!=',');
			fgets(D[i].Def,1000,f);
		}
	}
	return D;
}
arbre Creer_Noeud(char* mot,char* def)
{
	arbre a;
	a=(arbre)malloc(sizeof(noeud));
	a->Mot=mot;
	a->Def=def;
	a->fg=NULL;
	a->fd=NULL;
	return a;
}
int vide(arbre a)
{
	if(a==NULL)
	return 1;
	else return 0;
}
arbre creation_arbre(Dict* D, int deb, int fin)
{
    arbre a;
    int M;
    if (deb > fin)
      return NULL;
    M=(deb+fin)/2;
    a=Creer_Noeud(D[M].Mot,D[M].Def);
    a->fg=creation_arbre(D,deb, M-1);
    a->fd=creation_arbre(D,M+1,fin);

    return a;
}
void affichage(arbre a)
{
	if(!vide(a))
	{
		affichage(a->fg);
		puts(a->Mot);
		puts(a->Def);
		affichage(a->fd);
	}
}



arbre ExisteArbr(char* mot,arbre a)
{

      if(vide(a))
      {
      	return NULL;
	  }
	  else
	  {
	  	if(strcmp(mot,a->Mot)==0)
	  	{
	  		return(a);
		  }
		  else{
		  	     if(strcmp(mot,a->Mot)<0)
		  	      {
		  	    	return ExisteArbr(mot,a->fg);
				  }
				  else
				  {
				  	return ExisteArbr(mot,a->fd);
				  }
		      }
	  }
}

char* TrouveMotArbr(char* mot,arbre a)
{
	char*ch=NULL;
	arbre A;
	A=ExisteArbr(mot,a);
	if(A!=NULL)
	{
		ch=(char*)malloc(sizeof(char));
		ch=A->Mot;
		strcat(ch,A->Def);
		puts(ch);
		return ch;
	}
	else printf("votre mot %s n'est pas trouve il n'existe pas\n",mot);
return ch;
}
void MotsHorsArbre(arbre a1,arbre a)
{
    arbre A;
    if(!vide(a1))
	{
      A=ExisteArbr(a1->Mot,a);
  	  if(A==NULL)
      {
  	    puts(a1->Mot);
  	    puts(a1->Def);
      }
	  MotsHorsArbre(a1->fg,a);
	  MotsHorsArbre(a1->fd,a);
    }

}
