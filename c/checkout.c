#include "checkout.h"

int total = 0;
int etat[] = {0, 0, 0, 0, 0};

void process(char *chaine) {
    int index = indexPour(chaine);
    if (index < 0) {
        return;
    }

    total = total + prixPour(index) + reductionPour(etat, index);
    printf("> %i\n", total);
}

int indexPour(char *chaine) {
	if (strcmp(chaine, "Pommes") == 0)
        return POMMES;
    else if(strcmp(chaine, "Apples") == 0)
        return APPLES;
    else if(strcmp(chaine, "Mele") == 0)
        return MELE;
    else if(strcmp(chaine, "Bananes") == 0)
        return BANANES;
    else if(strcmp(chaine, "Cerises") == 0)
        return CERISES;

    return -1;
}

int prixPour(int i) {
	if (i == POMMES || i == APPLES || i == MELE)
        return 100;
    else if(i == BANANES)
        return 150;
    else if(i == CERISES)
        return 75;

    return 0;
}

int reductionPour(int etat[], int index) {
    etat[index]++;
    if (index == CERISES
        && etat[CERISES] > 0
        && etat[CERISES] % 2 == 0) {
        return -20;
    }
    if (index == BANANES
        && etat[BANANES] > 0
        && etat[BANANES] % 2 == 0) {
        return -150;
    }
    if (index == APPLES
        && etat[APPLES] > 0
        && etat[APPLES] % 3 == 0) {
        return -100;
    }
    if (index == MELE
        && etat[MELE] > 0
        && etat[MELE] % 2 == 0) {
        return -100;
    }
    return 0;
}
