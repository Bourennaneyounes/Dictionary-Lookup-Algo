#ifndef FREQ_H_INCLUDED
#define FREQ_H_INCLUDED
text* remplir();
void affichtext(text* t);





typedef struct listfreq listfreq;
struct listfreq
{
	char* mot;
	int freq;
	listfreq* suivant;
};
typedef struct dictcontext dictcontext;
struct dictcontext
{
	char* mot;
	listfreq* tete;
};
typedef struct listemots listemots;
struct listemots
{
	char* mot;
	listemots* suivant;
};

listemots* motsde(text* t);
listfreq* frequencesde(text* t);
listfreq* contexte(text* t , char* mot);
dictcontext* creerdictcontext(text* t);
char* maxcontexte(dictcontext* d , char* m);



#endif // FREQ_H_INCLUDED
