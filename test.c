#include <stdio.h>
#include <stdbool.h>
int main() {
    int i=0;
    int sum = 0;
    bool h = (i-=1000);
    while(h)
    {
        printf("%d",i);
        h = (i-=1000);
    }
    printf("sum\n");
    printf("%d", sum);
    return 0;
}
