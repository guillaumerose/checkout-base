#include "stdio.h"
#include "stdlib.h"

#include "checkout.h"

int main()
{
	char input[1024];
	while(fgets(input, 1023, stdin) != NULL)
	{
        process(input);
		printf("Output : %s", input);
	}
    return 0;
}
