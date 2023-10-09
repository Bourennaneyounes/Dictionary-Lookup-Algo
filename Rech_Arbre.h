#ifndef RECH_ARBRE_H_INCLUDED
#define RECH_ARBRE_H_INCLUDED
typedef struct Dict
{
    char* Mot,*Def;
}Dict;
typedef struct noeud* arbre;
typedef struct noeud
{
	char* Mot;
	char* Def;
	arbre fg,fd;
}noeud;
arbre Creer_Noeud(char* mot,char* def);
int vide(arbre a);
arbre creation_arbre(Dict* D, int deb, int fin);
void affichage(arbre a);
arbre ExisteArbr(char* mot,arbre a);
char* TrouveMotArbr(char* mot,arbre a);
void MotsHorsArbre(arbre a1,arbre a);
Dict* CreerTable_DeDict(FILE* f,long nb);




#endif // RECH_ARBRE_H_INCLUDED
