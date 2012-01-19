#include "checkout.h"

int acc = 0;
void process(char *chaine) {
    acc = acc + priceOf(chaine);
    printf("> %i\n", acc);
}

int priceOf(char *chaine) {
	if (strcmp(chaine, "Pommes\n") == 0)
        return 100;
    else if(strcmp(chaine, "Bananes\n") == 0)
        return 150;
    else if(strcmp(chaine, "Cerises\n") == 0)
        return 75;

    return 0;
}