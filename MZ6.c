#include <stdio.h>

struct s1 {short v1;
	double v2;
	char v3;;}
;

struct s2 {short v1;
	char v3;
	double v2;}
;


size_t compactify(void *ptr, size_t size){
	 int i = 0;
	 short c_short;
	 double c_double;
	 char c_char;

	struct s1 *ptr1 = (struct s1 *)(ptr);
	struct s2 *ptr2 = (struct s2 *)(ptr);


	while (i < size / (sizeof(struct s1))){
			
			c_short = (ptr1[i].v1);
			c_double = (ptr1[i].v2);
			c_char = (ptr1[i].v3);
			
			ptr2[i].v1 = c_short;
			ptr2[i].v2 = c_double;
			ptr2[i].v3 = c_char;

			i++;
	}
	return sizeof(struct s2) * i;

			
}


