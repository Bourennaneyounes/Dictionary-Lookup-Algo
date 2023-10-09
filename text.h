#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED
typedef struct text text;
struct text
{
char* chaine;
int lg, cpt;
};
char* Allouer_Chaine(int Taille);
text creer();
void Liberer(text* t);
int Taille(text t);
int Capacite(text t);
void Modifier_Capacite(text* t,int Min);
void Ajouer_Car(text* t, char C);
void Ajouter_Chaine(text* t, char* str);
int position(text* t , char* str);
int Detrminer_Pos(text t, char* str);
void Insirer_Chaine(text* t, char* str, int Debut);
void modifiercapacite2(text* t , int Min);

#endif // TEXT_H_INCLUDED
