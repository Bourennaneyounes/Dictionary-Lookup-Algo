#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"chaine.h"
#include"text.h"
#include"Prefix_Suffixe.h"
#include"FREQ.h"
listemots* motsde(text* t)
{
	listemots* tete=NULL;
	listemots* c=NULL;
	listemots* pre=NULL;
	long i=0;
	long j;
	while(t->chaine[i]!='\0')
	{
		j=0;
		char* s=(char*)malloc(255*sizeof(char));
		while((t->chaine[i]!=' ')&&(t->chaine[i]!='\0'))
		{
			s[j]=t->chaine[i];
			i++;
			j++;
		}

		c=(listemots*)malloc(sizeof(listemots));
		c->mot=(char*)malloc(255*sizeof(char));
		strcpy(c->mot,s);
		c->suivant=NULL;
		if(tete==NULL)
		{
			tete=c;
		}
		else
		{
			pre->suivant=c;
		}
		pre=c;

		i++;
	}
	return tete;
}


listfreq* frequencesde(text* t)
{
	listfreq* tete=NULL;
	listfreq* clf=NULL;
	listfreq* pre=NULL;
    listemots* lm=motsde(t);
    listemots* clm=lm;
    while(clm!=NULL)
    {
    	int existe=-1;
    	listfreq* ccc=tete;
	    while(ccc!=NULL)
	    {
		    if(strcmp(ccc->mot ,clm->mot)==0)
		    {
			existe=1;
		    }
		    ccc=ccc->suivant;
	    }
    	if(existe==1)
    	{
    		clf=tete;
    		while(strcmp(clf->mot , clm->mot)!=0)
    		{
    			clf=clf->suivant;
			}
			clf->freq++;
		}
		else
		{
			clf=(listfreq*)malloc(sizeof(listfreq));
			clf->mot=(char*)malloc(255*sizeof(char));
			strcpy(clf->mot , clm->mot);
			clf->freq=1;
			clf->suivant=NULL;
			if(tete==NULL)
			{
				tete=clf;
			}
			else
			{
				pre->suivant=clf;
			}
			pre=clf;
		}
    	clm=clm->suivant;
	}
    clf=tete;
	listfreq* hlp=NULL;
	listfreq* tmp=NULL;
	char* s=NULL;
	int i;
	while(clf->suivant!=NULL)
	{
		hlp=clf->suivant;
		while(hlp!=NULL)
		{
			if(clf->freq>hlp->freq)
			{
				s=(char*)malloc(255*sizeof(char));
			    strcpy(s , clf->mot);
			    strcpy(clf->mot , hlp->mot);
			    strcpy(hlp->mot , s);
			    i=clf->freq;
			    clf->freq=hlp->freq;
			    hlp->freq=i;
			}
			hlp=hlp->suivant;
		}
		clf=clf->suivant;
	}
    return(tete);
}


listfreq* contexte(text* t , char* mot)
{
	listemots* clm=motsde(t);
	listemots* tete1=NULL;
	listemots* c1=NULL;
	listemots* pre1=NULL;
	while(clm!=NULL)
	{
		if(strcmp(clm->mot , mot)==0)
		{
			c1=(listemots*)malloc(sizeof(listemots));
			c1->mot=(char*)malloc(255*sizeof(char));
			strcpy(c1->mot , clm->suivant->mot);
			c1->suivant=NULL;
			if(tete1==NULL)
			{
				tete1=c1;
			}
			else
			{
				pre1->suivant=c1;
			}
			pre1=c1;
		}
		clm=clm->suivant;
	}
	listfreq* tete2=NULL;
	listfreq* clf2=NULL;
	listfreq* pre2=NULL;
	c1=tete1;
    while(c1!=NULL)
    {
    	int existe=-1;
    	listfreq* ccc=tete2;
	    while(ccc!=NULL)
	    {
		    if(strcmp(ccc->mot ,c1->mot)==0)
		    {
			existe=1;
		    }
		    ccc=ccc->suivant;
	    }
    	if(existe==1)
    	{
    		clf2=tete2;
    		while(strcmp(clf2->mot , c1->mot)!=0)
    		{
    			clf2=clf2->suivant;
			}
			clf2->freq++;
		}
		else
		{
			clf2=(listfreq*)malloc(sizeof(listfreq));
			clf2->mot=(char*)malloc(255*sizeof(char));
			strcpy(clf2->mot , c1->mot);
			clf2->freq=1;
			clf2->suivant=NULL;
			if(tete2==NULL)
			{
				tete2=clf2;
			}
			else
			{
				pre2->suivant=clf2;
			}
			pre2=clf2;
		}

    	c1=c1->suivant;
	}
    clf2=tete2;
	listfreq* hlp=NULL;
	listfreq* tmp=NULL;
	char* s=NULL;
	int i;
	while(clf2->suivant!=NULL)
	{
		hlp=clf2->suivant;
		while(hlp!=NULL)
		{
			if(clf2->freq<hlp->freq)
			{
				s=(char*)malloc(255*sizeof(char));
			    strcpy(s , clf2->mot);
			    strcpy(clf2->mot , hlp->mot);
			    strcpy(hlp->mot , s);
			    i=clf2->freq;
			    clf2->freq=hlp->freq;
			    hlp->freq=i;
			}
			hlp=hlp->suivant;
		}
		clf2=clf2->suivant;
	}

	return tete2;
}




dictcontext* creerdictcontext(text* t)
{
	listfreq* lf=frequencesde(t);
	listfreq* clf=lf;
	int i;
	int cpt=0;
	while(clf!=NULL)
	{
		cpt++;
		clf=clf->suivant;
	}
	listfreq* c=frequencesde(t);
	dictcontext* d=(dictcontext*)malloc((cpt)*sizeof(dictcontext));
	for(i=0;i<cpt;i++)
	{
		d[i].mot=(char*)malloc(255*sizeof(char));
		strcpy(d[i].mot,c->mot);
		d[i].tete=contexte(t,d[i].mot);
		c=c->suivant;
	}

	return (d);
}

char* maxcontexte(dictcontext* d , char* m)
{
	int i=0;
	while(strcmp(d[i].mot , m)!=0)
	{
		i++;
	}
	char* ch=(char*)malloc(255*sizeof(char));
	strcpy(ch , d[i].tete->mot);
	return ch;
}

void affichtext(text* t)
{
	printf("la chaine : %s\n",t->chaine);
	printf("la longeur : %d\n",t->lg);
	printf("la capacite : %d\n",t->cpt);
}


text* remplir()
{
	text* t;
	char* s=NULL;
	char* tmp=(char*)malloc(255*sizeof(char));
	int n;
	long i;
	long lg=0;
	t=(text*)malloc(sizeof(text));
	tmp[0]='\0';
	printf("saisir les mots de texte un par un \n");
	printf("donner le nombre de mots : \n");
	scanf("%d",&n);
	printf("donner la chaine : \n");
	long j=0;
	for(i=1;i<=n;i++)
	{
		s=(char*)malloc(255*sizeof(char));
		for(j=0;j<255;j++)
		{
			s[j]='\0';
		}
		scanf("%s",s);
		s[strlen(s)]=' ';
		s[strlen(s)]='\0';
		lg=lg+strlen(s);
		strcat(tmp , s);
	}

    t->lg=lg;
    t->chaine=(char*)malloc(lg*sizeof(char));
    strcpy(t->chaine , tmp);
    t->cpt=lg;
	return t;
}
