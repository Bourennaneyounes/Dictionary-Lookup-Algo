#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"chaine.h"
void strinsert(char* M , char* T , int i)
{
	char* tmp=(char*)malloc(sizeof(char));
	strncpy(tmp,M,i);
	strcat(tmp,T);
	strcat(tmp,M+i);
	strcpy(M,tmp);
}

void strninsert(char* M , char* T , int i , int n)
{

	char* tmp = (char*)malloc(sizeof(char));

	strncpy(tmp,T,n);
	strinsert(M,tmp,i);
}
char* alphabet(char* s)
{
    char* T=NULL;
    int lg;
    lg = strlen(s);
    T = (char*)malloc(sizeof(char)*(lg+1));
    char C;
    int i,j;
    strcpy(T,s);


    for(i=0;i<lg;i++)
    {
        for(C=97;C<123;C++)
        {
            if(T[i]==C)
            {
                T[i] = T[i] -32;
            }
        }
    }
    i=0;
    while(i<lg-1)
    {
        j=i+1;
        while(j<lg)
        {
            if(T[i]<=T[j])
            {
                j = j + 1;
            }else
            {

                C = T[i];
                T[i] = T[j];
                T[j] = C;
                j = j + 1;
            }
        }
        i = i + 1;
    }
    return T;
}

int freqchar(char* M , char c)
{
	int i,cpt,lg;
	lg=strlen(M);
	cpt=0;
	for(i=0;i<lg;i++)
	{
		if(M[i]==c)
		{
			cpt++;
		}
	}
	return cpt;
}
freq* frequences(char* S)
{
    int i, j;
   int nb = 0;
    i=0;

   while(S[i]!='\0')
   {

    nb = nb + 1;
    i = i + freqchar(S,S[i]);
   }
    freq* tab=(freq*)malloc(sizeof(freq)*(nb+2));
    char* M;
    M = (char*)malloc(sizeof(char)*(strlen(S)+1));
    M = alphabet(S);
    i=0;
    j=0;
    while(i<strlen(S))
    {
   tab[j].c = M[i];
   tab[j].occ = freqchar(M,M[i]);
   j = j + 1;
   i = i + freqchar(M,M[i]);


    }
    tab[j].c='\0';
return tab;

}

int anagramme(char* s1 , char* s2)
{
	int i;
	int lg;

	if(strlen(s1)!=strlen(s2))
	{
		return 0;
	}
	else
	{
		lg=strlen(s1);
	    freq* t1=frequences(s1);
	    freq* t2=frequences(s2);
	    for(i=0;i<lg;i++)
	    {
	    	if(t1[i].c!=t2[i].c)
	    	{
	    		return 0;
	    	}
	    	if(t1[i].occ!=t2[i].occ)
	    	{
	    		return 0;
	    	}
	    }
	    return 1;
	}

}


int mirroire(char* s1 , char* s2)
{
	int lg,i,j,vrai;
	if(strlen(s1)!=strlen(s2))
	{
		return 0;
	}
	lg=strlen(s1);
	i=0;
	j=lg;
	vrai=1;
	while(i<=lg && j>=0 && vrai==1)
	{
		if(s1[i]!=s2[j])
		{
			vrai=0;
		}
		j--;
		i++;
	}
	return vrai;
}
int Palindrome(char* S1)
{
    char* S2=NULL;
    int i;
    S2=(char*)malloc(sizeof(char)*strlen(S1));
    i=strlen(S1);
    while(i>=0)
    {
        S2[strlen(S1)-i]=S1[i];
        i--;
    }/*
    for(i=strlen(S1);i>=0;i--)
    {
        S2[i]=S1[strlen(S1)-i];
    }*/
    printf("dododo");
    printf("\n%s\n", S2);
    return mirroire(S1,S2);

}

char* strnchr(char* s , char p , int n)
{
	int i,lg,cpt;
	char* trv;
	trv=(char*)malloc(sizeof(char));
	lg=strlen(s);
	if(freqchar(s , p)==0)
	{
		return NULL;
	}
	i=0;
	cpt=0;
	while(cpt<n && i<=lg)
	{
		if(s[i]==p)
		{
			cpt++;
		}
		i++;
	}
	if(cpt<n)
	{
		return NULL;
	}
	strcpy(trv, &s[i-1]);
	return trv;
}


char* strnstr(char* s , char* p , int n)
{
    int cpt;
	char* trv;
	char* tmp;
	trv=(char*)malloc(sizeof(char));
	tmp=(char*)malloc(sizeof(char));

	if(strstr(s , p)==NULL)
	{
		return NULL;
	}
	cpt=0;
	strcpy(trv,s);
	while(cpt<n)
	{
		strcpy(tmp,strstr(trv,p));
		strcpy(trv,tmp);
		cpt++;
	}
	return trv;
}


char* strrstr(char* s , char* p)
{
	char* trv;
	trv=(char*)malloc(sizeof(char)*(strlen(s)+1));
	strcpy(trv , s);
	while(strstr(trv , p)!=NULL)
	{
		trv = strstr(trv , p);
	}
	return trv;
}


void strndel(char* s , int n , int i)
{

	char* tmp=NULL;
	tmp=(char*)malloc(sizeof(char)*(strlen(s)-n));
	strncpy(tmp , s , i);
	strcat(tmp , &s[(i+n)]);
	strcpy(s , tmp);

}
int Sous_Fichier(FILE* F1,FILE* F2)
{
    char* s1;
    char* s2;
    s1 = (char*)malloc(sizeof(char)*20);
    s2 = (char*)malloc(sizeof(char)*20);
    int vrai;
    vrai = 1;
    while(!feof(F2)&&vrai==1)
    {
      fscanf(F2,"%s", s2);
      printf("\n%s\n", s2);
      fscanf(F1,"%s", s1);
      printf("\n%s\n", s1);
      s2 = strstr(s2,s1);
            if(s2==NULL)
                  {
                      vrai = 0;
                  }
    }
return vrai;
}
