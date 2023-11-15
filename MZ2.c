#include <stdio.h>
int main()
{
	int n1, n2, N, X;
	scanf("%d", &X);
	scanf("%d", &N);
    scanf("%d", &n2);
    N--;
    
	for (int i = 0; i < N; i++)
	{
	    scanf("%d", &n1);
	    if ((long long)n2 + n1 == X)
	        {
	            printf("%d" " " "%d", n2, n1);
	            return 0;
	        }
	    n2 = n1;
	}
	printf("0 0");
    return 0;
}