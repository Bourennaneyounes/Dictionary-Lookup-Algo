#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"chaine.h"
#include"Prefix_Suffixe.h"
void tous_prefix(char* s)
{
	char* pre=NULL;
    int lg=strlen(s);
	pre = (char*)calloc(lg,sizeof(char));
	int i;
	for(i=1;i<=lg;i++)
	{
		strncpy(pre,s,i);
		printf("\n%s\n", pre);
	}
	free(pre);
}

int min(int a , int b)
{
	if(a<b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
char* plulongpre(char* s1 , char* s2)
{
    int i=0;
    int j=1;
    char* tmp=NULL;
    tmp = (char*)calloc(min(strlen(s1),strlen(s2)),sizeof(char));
	while(i<min(strlen(s1),strlen(s2))&&j==1)
	{
		if(s1[i]==s2[i])
		{
			tmp[i]=s1[i];
			i++;
		}
		else
		{
			j=0;
		}
	}
	return tmp;
}


int estprefixde(char* s,char* p)
{
	return(strlen(plulongpre(s , p))==strlen(p));
}


int nbrcommun(char* m , int n , int r)
{
	int cpt,i;
	char* s;
	cpt = 0;
	for(i=1;i<=n;i++)
	{
	    printf("\nDONNER LA %d EME CHAINE  : \n");
		s=(char*)malloc(sizeof(char));
		scanf("%s",s);
		if(strlen(plulongpre(m , s))>=r)
		{
			cpt++;

		}
	}
	return cpt;
}

suffixe* extrairesuffixes(char* s)
{
	int lg=strlen(s);

	suffixe* tab=(suffixe*)malloc(lg*sizeof(suffixe));

	int i;
	for(i=0;i<lg;i++)
	{
		tab[i].suf=(char*)malloc(sizeof(char)*lg);
        strcpy(tab[i].suf, s+i);
        tab[i].id=i;
	}
	return tab;
}


int* occurrences(char* p , char* s)
{
	suffixe* tab=extrairesuffixes(s);
	int lg=strlen(s);

	int* t=(int*)malloc(lg*sizeof(int));
	int i;
	int j=0;
	for(i=0;i<lg;i++)
	{
		if(estprefixde(tab[i].suf , p)==1)
		{
			t[j]=tab[i].id;
			printf("\n%d\n", t[j]);
			j++;

		}
	}

	return t;
}
