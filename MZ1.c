#include <stdio.h>
int main()
{
	int a, b, count, count_save;
	scanf("%d", &b);
	count_save = count = 1;
	

	while (scanf("%d", &a) == 1)
	{
		if (b <= a)
		{
			count++;
		}
		else
		{
			count_save = count_save < count?count:count_save;
			count = 1;
		}	
		b = a;
	}
	count_save = count_save < count?count:count_save;
    
    printf("%d", count_save);
    return 0;
}