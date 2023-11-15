#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *create_str(char *str)
{
    char *symb;
    int i = 0, j = 0, counter = 0, shift = 1, size = strlen(str);
    char c;
    symb=(char *)malloc(strlen(str)*sizeof(char));
    while (!((c = *(str+counter)) == '\0'))
    {
        symb[i] = c;
        shift = 1;
        counter ++;
        if (isalpha(c))
        {
            if (isupper(c))
            {
                shift = c -'A' + 1;
            }
            else
            {
                shift = c -'a' + 1;
            }
        }
        if (shift + i >= size)
        {
            char *buf;
            size *= 2;
            buf = (char *)realloc(symb, size*sizeof(char));
            if (!buf)
			{
				printf("Error:can't allocate more memory\n");
				size /= 2;
				break;
			}
			else
				symb = buf;

        }

        for (j = 1; j < shift; j++)
        {
            *(symb+i+j)=c;
        }
        i += shift;
    };
    return symb;

};


int main(){
    char *first;
    char c ='*';
    int count = 0, size = 8;
    first = (char*)malloc(2 *sizeof(char));
    *first = '*';
    while (!(((c = getchar()) == '\n') || c == EOF))
    {
        first[count++] = c;
        if (count == size)
        {
            char *buf;
            size *= 2;
            buf = (char*)realloc(first, size*sizeof(char));
	    if (!buf)
			{
				printf("Error:can't allocate more memory\n");
				size /= 2;
				break;
			}
			else
				first  = buf;
        };
    };
    if (*first == '*') return 0;
    char* helpme = create_str(first);
    printf("%s", helpme);
    
    free(first);
    return 0;
}
