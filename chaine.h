#ifndef CHAINE_H_INCLUDED
#define CHAINE_H_INCLUDED
#include"text.h"
typedef struct freq freq ;
struct freq
{
	char c;
	int occ;
};
void affichtab(freq* tab);
void strinsert(char* m , char* t , int i);
void strninsert(char* m , char* t , int i , int n);
char* alphabet(char* s);
int freqchar(char* m , char c);
freq* frequences(char* s);
int anagramme(char* s1 , char* s2);
int mirroire(char* s1 , char* s2);
int Palindrome(char* S1);
char* strnchr(char* s , char p , int n);
char* strnstr(char* s , char* p , int n);
char* strrstr(char* s , char* p);
void strndel(char* s , int n , int i);
int Sous_Fichier(FILE* F1,FILE* F2);


#endif // CHAINE_H_INCLUDED
