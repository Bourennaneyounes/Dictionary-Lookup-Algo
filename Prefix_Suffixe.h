#ifndef PREFIX_SUFFIXE_H_INCLUDED
#define PREFIX_SUFFIXE_H_INCLUDED

typedef struct suffixe suffixe;
struct suffixe
{
	int id;
	char* suf;
};

void tous_prefix(char* s);
int min(int a , int b);
char* plulongpre(char* s1 , char* s2);
int estprefixde(char* s,char* p);
int nbrcommun(char* m , int n , int r);
suffixe* extrairesuffixes(char* s);
int* occurrences(char* p , char* s);

#endif // PREFIX_SUFFIXE_H_INCLUDED
