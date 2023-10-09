#ifndef DICHO_MAT_H_INCLUDED
#define DICHO_MAT_H_INCLUDED
long Millieu_TAB(char** DICO, int DEBUT, int FIN);
long EXISTE_TAB(char* mot , char** DICO);
char* TROUVE_MOT_TAB(char* mot, char** DICO);
char** MOTS_HORS_DICO_TAB(char** FI , char** DICO,int nbl2);


#endif // DICHO_MAT_H_INCLUDED
