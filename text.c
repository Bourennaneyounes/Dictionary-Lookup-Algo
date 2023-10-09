#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"text.h"
char* Allouer_Chaine(int Taille)
{
    char* S;
    S = (char*)malloc(sizeof(char)*Taille);
    if(!S)
    {
        printf("ERREUR DU MALLOC");
        exit(EXIT_FAILURE);
    }
    return S;
}
text creer()
{
    text t;
    t.cpt = 16;
    t.lg = 0;
    t.chaine = Allouer_Chaine(t.cpt);
    return t;
}
void Liberer(text* t)
{
    free(t->chaine);
    t->lg = 0;
    t->cpt = 0;
}
int Taille(text t)
{
    int l;
    l = strlen(t.chaine);
    return l;
}
int Capacite(text t)
{
    int cap;
    cap = strlen(t.chaine)+1;
    return cap;
}
void Modifier_Capacite(text* t,int Min)
{
    char* tmp;
    if(t->cpt <= Min)
    {
        tmp = Allouer_Chaine(strlen(t->chaine)+1);
        strcpy(tmp,t->chaine);
        Liberer(t);
        t->chaine = Allouer_Chaine(Min+1);
        strcpy(t->chaine,tmp);
        t->cpt = Min +1;
        t->lg = strlen(tmp);
    }
}
void Ajouer_Car(text* t, char C)
{
    if(t->lg == t->cpt-1)
    {
        Modifier_Capacite(t,t->cpt+1);
    }
    strcat(t->chaine,&C);
    t->lg++;
}
void Ajouter_Chaine(text* t, char* str)
{
    if((t->lg+strlen(str)) >= t->cpt+1)
    {
        Modifier_Capacite(t,t->lg+strlen(str)+1);
    }
    strcat(t->chaine,str);
   t->lg=strlen(t->chaine);
}
int position(text* t , char* str)
{
	char* tmp=strstr(t->chaine,str);
	if(tmp!=NULL)
	{
		return (tmp-t->chaine);
	}
	return -1;
}
int Detrminer_Pos(text t, char* str)
{
    char* tr=NULL;
    int i = t.lg-strlen(str)+1;
    while(!tr&&i>=0)
    {
        tr=strstr(t.chaine+i,str);
        i--;
    }
        return tr-t.chaine;
}

void Insirer_Chaine(text* t, char* str, int Debut)
{
    char* tmp=(char*)malloc(sizeof(char));
    if((t->lg+strlen(str)) >= t->cpt+1)
    {
        Modifier_Capacite(t,t->lg+strlen(str)+1);
    }
	strncpy(tmp,t->chaine,Debut);
	strcat(tmp,str);
	strcat(tmp,t->chaine+Debut);
	strcpy(t->chaine,tmp);
}

void modifiercapacite2(text* t , int Min)
{
	char* tmp;
    if(t->cpt <= Min)
    {
        tmp = Allouer_Chaine(strlen(t->chaine)+1);
        strcpy(tmp,t->chaine);
        Liberer(t);
        t->chaine = Allouer_Chaine(Min*2);
        strcpy(t->chaine,tmp);
        t->cpt = Min*2;
        t->lg = strlen(tmp);
    }
}
