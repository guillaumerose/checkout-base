#include "checkout.h"

void process(char *chaine) {
	while(*chaine != '\0') {
		*chaine = toupper(*chaine);
		chaine++;
	}
}