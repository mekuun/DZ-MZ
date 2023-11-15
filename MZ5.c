#include<stdio.h>
#include<string.h>
#include<stdlib.h>



int main(int argc, char **argv)
{
	int length;
	char *p = NULL;
	double sum, numb;
	char symb;


	
	for (int i = 1; i < argc; i++)	{
		if(sscanf(argv[i], "%lf%c", &numb, &symb) == 0 ||sscanf(argv[i], "%lf%c", &numb, &symb) == 2) {
			length += strlen(argv[i]);
		}
	}
	p = (char*)malloc(sizeof(char) * (length + 1));
	if (!p){
		printf("Stop!!!! Memory error!!!\n");
		return 1;
	}


	for (int i = 1; i < argc; i++)
	{
		if(sscanf(argv[i], "%lf%c", &numb, &symb) == 0 ||sscanf(argv[i], "%lf%c", &numb, &symb) == 2){ 	
			strcat(p, argv[i]);
		}
		
		else{
			sum += atof(argv[i]);
		}
	}

	printf("%lf\n", sum);
	printf("%s\n", p);
	free(p);

	return 0;
}

