#include <stdio.h>
#include <stdlib.h>

void loop(float x, float y)
{
    float temp=x;
    int count=1;
    for (;x<=y;x+=temp)
    {
        printf("Current loop %d \n", count);
        count++;
    }
}

void checkint()
{
    float x=0.1+0.1+0.1;
    float y=0.3;
    if(x==y)
    {
        printf("Is True \n");
    }
    else
    {
        printf("Is False \n");
        printf("x=%f", x);
        printf("y=%f", y);
    }
    if(x==0.3)
    {
        printf("Is True");
    }
    else
    {
        printf("Is False \n");
        printf("x=%f", x);
        //printf("y=%f", y);
    }
}

int main()
{
    float loopstart=1.0;
    float target=10.0;
    for(int i=0;i<40;i++)
    {
        printf("i=%d \n",i);
        printf("initial=%f \n",loopstart);
        printf("final=%f \n",target);
        loop(loopstart, target);
        loopstart/=10.0;
        target/=10.0;
    }
    checkint();
    return 0;
    
}
//prints only 9 lines at i=38, going from 10^-39 to 10^38