#include <stdio.h>
#include <math.h>

struct point {
    int x;
    int y;
};

int main()
{
    int a, b, c;
    printf("type in a:");
    scanf("%d", &a);
    printf("type in b:");
    scanf("%d", &b);
    printf("type in c:");
    scanf("%d", &c);
    
    struct point ptarray[11];
    int i=0;
    for(int x=-5; x<=5; x++)
    {
        struct point pt = {.x=x, .y=(a*(x*x)+(b*x)+c) };
        ptarray[i]=pt;
        i++;
    }
    
    for(int j=0; j<11; j++)
    {
    printf("%d %d\n", ptarray[j].x, ptarray[j].y);
    }
    
    return 0;
}

