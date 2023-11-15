#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define S 21
#define T 16
#define D 11

enum optypes {ADD = 32, SUB = 34, MUL = 24, DIV = 26, ADDI = 536870912, ANDI = 805306368, ORI  = 872415232};
enum masks {NUM_MASK = 65535};
int read_reg(long int *reg)
{
    char s;
    scanf("%c", &s);
    if (s == '$') ungetc(s, stdin);
    if (scanf(" $%ld", reg) != 1){
        return -1;
    }


    if ((*reg < 0) || (*reg >= 31)){
        return -2;
    }
    return 0;
}


int main()
{
	char command[6], c;
	int optype;
	long int r1, r2, r3 = 0;
	long int* regs[] = {&r1, &r2, &r3};
	if (scanf("%5s", command) == -1) {printf("Unknown error"); return 0;};
	if (strcmp(command, "add") == 0) optype = ADD;
	else if (strcmp(command, "addi") == 0) optype = ADDI;
	else if (strcmp(command, "andi") == 0) optype = ANDI;
	else if (strcmp(command, "ori") == 0) optype = ORI;
	else if (strcmp(command, "sub") == 0) optype = SUB;
	else if (strcmp(command, "mult") == 0) optype = MUL;
	else if (strcmp(command, "div") == 0) optype = DIV;
	else {printf("Wrong command"); return 0;};

	int opcount;
	if ((optype == ADD) || (optype == SUB)) opcount = 3; else opcount = 2;
	for (int i = 0; i < opcount; i++){
		switch (read_reg(regs[i])){
			case -1:
				printf("Wrong format");
				return 0;
			case -2:
				printf("Wrong value");
				return 0;
			}
	};

	long int num;    
	if ((optype == ADDI)||(optype == ANDI) || (optype == ORI)){
		char s;
   		scanf("%c", &s);
 
		if (scanf("%ld", &num) != 1) {
			printf ("Wrong format");
			return 0;
		}
		if (optype == ADDI){
		       if((num < -32768) || (num > 32767)){
				printf("Wrong value");
		 		return 0;
		       };
		     	if (num < 0) num = num & NUM_MASK;
		}
	 	else{
			if((num < 0) || (num > 65535)){
				printf("Wrong value");
		 		return 0;
			}
		};
	};

	if (scanf(" %c", &c) == 1) {
		printf("Wrong format"); return 0;
	};

//VYVOD
		unsigned long int mask = 2147483648, rez = 0;

	switch(optype){	
      		 case ADD: 
		 case SUB: 
	  	 	rez  = optype + (r1 << D) + (r2 << S) + (r3 << T);
           		 break;

       		 case MUL: 
		 case DIV:
           	 	rez = optype  + (r1 << S) + (r2 << T);
           	 	break;

		 case ORI:
		 case ANDI:
           	 	rez = optype  + (r1 << T) + (r2 << S) + num;
          	 	break;	

       		 case ADDI:
           	 	rez = optype + (r1 << T) + (r2 << S) + num;
            		 break;
       	}



	printf("%ld\n", rez);
    	for(int i = 1; i <= sizeof(long int) * 4; i++) {
		if (mask & rez) printf("1"); 
			else printf("0");

        	if ((i % 8 == 0) && (i != sizeof(long int) * 4)) printf(" ");
        	mask >>= 1;
    }
    return 0;


}
