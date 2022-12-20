#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>


double hash(char* str, int * list);

int main()
{
    char str[] = "hash";
    int hashlist[] = {13,27};
    double degrees = hash(str,hashlist);
    printf("%lf\n",degrees);
    return 0;
}

double hash(char* str, int * list)
{
    unsigned long long int val= 0;
    for(int i = 0; str[i]!=0; i++)
    {
        val+= str[i]*list[0];
        val*= str[i]*list[1];
    }
    double degrees = ((double)val/(double)ULLONG_MAX) *360;
    return degrees;
}