/*
phan tich
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int is_Prime(int n)
{
    if(n<2)
        return 0;
    for(int i=2; i<= sqrt(n); i++)
        if(n%i==0)
            return 0;
    return 1;
}

void findPrimeSum(int n, int m, int *primes, int index, int sum)
{
    if(m==0)
    {
        if(sum==n)
        {
            printf("Ket qua la: \n");
            for(int i=0; i<index; i++)
                printf("%d ", primes[i]);
            printf("\n");
        }
        return;
    }
    for(int i=2; i<=n; i++)
    {
        if(is_Prime(i))
        {
            if((index==0)|| i > primes[index-1])
            {
                primes[index] = i;
                findPrimeSum(n,m-1,primes,index+1,sum+i);
            }
        }
    }
}

int main()
{
    int n,m;
    printf("Moi nhap N: ");
    scanf("%d",&n);
    printf("Moi nhap M: ");
    scanf("%d", &m);
    int *primes = (int*) malloc (m * sizeof(int));
    findPrimeSum(n,m,primes,0,0);
    free(primes);
    system("pause");
}
