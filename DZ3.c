#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int numbers(char *str){
	int  count = 0, i = 0, start = -1, j = 0, cflag = 1;
	char curw[7] = "      ";
	char curs;

	while(str[count] != '\0'){
		curs = str[count];
		if ((curs != ' ')&&(curs != ',')){
			if(start == -1) start = count;
			curw[i] = curs;
			i ++;
		}
		else {
			count++;
			continue;
		}

		if ((i == 6) || (str[count + 1] == ',') || (str[count +1]  == ' ') || (str[count + 1] == '\n') || str[count + 1] == '\0'){
			curw[i] = '\0';
			if ((strcmp(curw, "0") == 0) || (strcmp(curw, "zero") == 0)) str[start] = '0';
			else if ((strcmp(curw, "1") == 0) || (strcmp(curw, "one") == 0)) str[start] = '1';
			else if ((strcmp(curw, "2") == 0) || (strcmp(curw, "two") == 0)) str[start] = '2';
			else if ((strcmp(curw, "3") == 0) || (strcmp(curw, "three") == 0)) str[start] = '3';
			else if ((strcmp(curw, "4") == 0) || (strcmp(curw, "four") == 0)) str[start] = '4';
			else if ((strcmp(curw, "5") == 0) || (strcmp(curw, "five") == 0)) str[start] = '5';
			else if ((strcmp(curw, "6") == 0) || (strcmp(curw, "six") == 0)) str[start] = '6';
			else if ((strcmp(curw, "7") == 0) || (strcmp(curw, "seven") == 0)) str[start] = '7';
			else if ((strcmp(curw, "8") == 0) || (strcmp(curw, "eight") == 0)) str[start] = '8';
			else if ((strcmp(curw, "9") == 0) || (strcmp(curw, "nine") == 0)) str[start] = '9';
			else cflag = 0;

			
			for (j = cflag; (str[start + j] != ',') && (str[start + j] != '\0') && (str[start + 1] != '\n'); j++) str[start + j] = ' ';
			if (str[start + j] != '\0') str[start + j] = ' ';
			cflag = 1;
			start = -1;
			i = 0;
			memset(curw, '\0', sizeof(curw));

			}
		count++;
	}
	start = count = 0;
	
	while (str[count] != '\0'){
		if (str[count] == ' ') {
			count ++;
			continue;
		}
		curs = str[count];
		str[count] = ' ';
		str[start] = curs;
		start += 2;
		count++;
	}
	start -= 1;
	str[start] = '\0';


return 0;
}



int main() {
	char *str;
	str = (char*)malloc(2 * sizeof(char));
	if (!str) {
		fprintf(stderr, "Memory error!!");
		return 0;
	}
	int c, i;
	long int n = 2;
	c = getchar();
	i = 0;
	while (c != EOF) {
		if ((i+1) >= n - 1) {
			n *= 2;
			str = (char *)realloc(str, n * sizeof(char));
			if (!str) {
				fprintf(stderr, "Memory error!!");
				return 0;
			}
		}
		str[i] = c;
		i++;
		c = getchar();
	}
	str[i] = '\0';
	numbers(str);
	printf("%s\n", str);
	return 0;
}

