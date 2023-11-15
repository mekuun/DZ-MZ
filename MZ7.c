#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char **argv){
	FILE *fin, *fout;
	char curr;
	int symbs = 0, words = 0, strs = 0, last, empty = 0, currI;
	int flag = 0;
	if (argc != 3){
		return 1;
	}

	fin = fopen(argv[1], "r");
	if (!fin){
		return 1;
	}

	fout = fopen(argv[2], "w");
	if (!fout){
		return 1;
	}

	
	while ((currI = fgetc(fin)) != EOF){
		curr = currI;
		printf("KKKK: %c",curr);
		empty = 1;
		symbs++;
		if ((curr == ' ')&(flag)){
			words++;
			flag = 0;
			}
			
		else if (curr == '\n'){
			if (flag) words++;
			flag = 0;
			strs++;
		}
			
		else if ((curr == '\n')||(curr == ' ')) flag = 1;	
		last = curr;
		}	
	
	if (empty && (last != ' ') && (last != '\n')) words++;

	fprintf(fout,"%d %d %d", strs, words, symbs);
	fclose(fin);
	fclose(fout);
	

			
			
return 0;
}

	
