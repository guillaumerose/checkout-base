#include "checkout.h"

#define POMMES 0
#define BANANES 1
#define CERISES 2

int total = 0;
int etat[] = {0, 0, 0};

void process(char *chaine) {
    int index = indexPour(chaine);
    if (index < 0) {
        return;
    }

    etat[index]++;
    total = total + prixPour(index) + reductionPour(etat);
    printf("> %i\n", total);
}

int indexPour(char *chaine) {
	if (strcmp(chaine, "Pommes\n") == 0)
        return POMMES;
    else if(strcmp(chaine, "Bananes\n") == 0)
        return BANANES;
    else if(strcmp(chaine, "Cerises\n") == 0)
        return CERISES;

    return -1;
}

int prixPour(int i) {
	if (i == POMMES)
        return 100;
    else if(i == BANANES)
        return 150;
    else if(i == CERISES)
        return 75;

    return 0;
}

int reductionPour(int etat[]) {
    if (etat[CERISES] > 0 && etat[CERISES] % 2 == 0) {
        return -30;
    }
    return 0;
}
