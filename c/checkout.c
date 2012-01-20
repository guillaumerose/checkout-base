#include "checkout.h"

int total = 0;
int etat[] = {0, 0, 0, 0, 0};

void process(char *chaine) {
    int index = indexPour(chaine);
    if (index < 0) {
        return;
    }

    etat[index]++;
    total = total + prixPour(index) + reductionPour(etat, index) + reductionGlobalePour(etat, index);
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
        return 200;
    else if(i == CERISES)
        return 75;

    return 0;
}

#define REDUCTION(frequence, article, montant) if (index == article \
    && etat[article] > 0 \
    && etat[article] % frequence == 0) { \
    return -montant; \
}

int reductionPour(int etat[], int index) {
    REDUCTION(2, CERISES, 20);
    REDUCTION(2, BANANES, prixPour(BANANES));
    REDUCTION(3, APPLES, prixPour(APPLES));
    REDUCTION(2, MELE, prixPour(MELE) / 2);
    return 0;
}

int reductionGlobalePour(int etat[], int index) {
    int pommes = etat[POMMES] + etat[APPLES] + etat[MELE];
    int fruits = nombreFruits(etat);

    if ((index == POMMES || index == APPLES || index == MELE) && pommes > 0 && pommes % 4 == 0) {
        return -100;
    }
    if (fruits > 0 && fruits % 5 == 0) {
        return -200;
    }
    return 0;
}

int nombreFruits(int etat[]) {
    int resultat = 0;
    int j;
    for(j = 0; j < 5; ++j)
    {
        resultat += etat[j];
    }
    return resultat;
}