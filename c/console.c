#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "checkout.h"

int main()
{
    char *sep = ",";
    char *word, *brkt;
    char input[1024];

    while(fgets(input, 1023, stdin) != NULL)
    {
        input[strlen(input) - 1] = '\0';
        for (word = strtok_r(input, sep, &brkt);
        word;
        word = strtok_r(NULL, sep, &brkt))
        {
            process(word);
        }
    }
    return 0;
}

