#include <stdio.h>
#include <ctype.h>

enum Operations {MULTI = '*', ADD = '+'};
int main()
{
    long long int rez, c1, b, c;
    char op, var, var1, a;
    if (scanf("%lld", &b)) {
        scanf("%c %c = %lld\n", &op, &var, &c);
    }
    else scanf("%c %c %lld = %lld\n", &var, &op, &b, &c);

    switch(op)
    {
        case MULTI:
            rez = (long long int) (c / b);
            break;
        case ADD:
            rez = (long long int) (c - b);
            break;
    }
//    обработка 2 строки
    if (scanf(" %c", &var1) < 1) {
        printf("INPUT ERROR\n");
        return 0;
    }

    if (var1 <= '9') {
        printf("PRESENTATION ERROR\n");
        return 0;
    }

    if (var1 != var) {
        printf("INCORRECT SYMBOL\n");
        return 0;
    }

    a = getchar();

    if ((a != ' ') && (a != '=')) {
        printf("INCORRECT SYMBOL\n");
        return 0;
    }

    while (a == ' ') {
        a = getchar();
    }

    if (a != '=') {
        printf("NO EQUAL SIGN\n");
        return 0;
    }

    if ((scanf("%lld", &c1) < 1)) {
        printf("NO ANSWER\n");
        return 0;
    }
    if (rez == c1) {
        printf("YES\n");
        return 0;
    }
    else {
        printf("NO\n");
        return 0;
    }




    return 0;
}
