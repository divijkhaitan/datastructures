#include <stdio.h>
#include <stdlib.h>

void matmult(int row_a,int col_a,int row_b, int col_b)
{
    int a[row_a][col_a];
    int b[row_b][col_b];
    int c[row_a][col_b];
    for(int i=0;i<row_a;i++)
    {
        for (int j = 0; j < col_a; j++)
        {
            printf("Enter the entry at index %d, %d of the first array", i+1,j+1);
            scanf("%d", &(a[i][j]));
        }
        
    }
    for(int i=0;i<row_a;i++)
    {
        for (int j = 0; j < col_b; j++)
        {
            printf("Enter the entry at index %d, %d of the second array", i+1,j+1);
            scanf("%d", &(b[i][j]));
        }
        
    }
    for(int i=0;i<row_a;i++)
    {
        for (int j = 0; j < col_b; j++)
        {
            c[i][j]=0;
            for(int k=0; k<row_b;k++)
            {
                c[i][j]+=a[i][k]+b[k][j];
            }
        }
    }
    for(int i=0;i<row_a;i++)
    {
        for (int j = 0; j < col_b; j++)
        {
            printf("%d", c[i][j]);
        }
        printf("\n");
    }
    
}

int main()
{
    printf("Enter Dimensions of first matrix");
    int rowsize_a;
    int colsize_a;
    scanf("%d",&(rowsize_a));
    scanf("%d",&(colsize_a));
    printf("Enter Dimensions of second matrix");
    int rowsize_b;
    int colsize_b;
    scanf("%d",&(rowsize_b));
    scanf("%d",&(colsize_b));

    if(colsize_a==rowsize_b)
    {
        matmult(rowsize_a,colsize_a,rowsize_b,colsize_b);
    }
    else
    {
        printf("The given sizes are not compatible for matrix multiplication");
    }
    return 0;
}
