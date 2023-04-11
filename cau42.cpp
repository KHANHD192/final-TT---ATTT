/*
Viết chương trình sinh ra 2 số nguyên tố 0<p,q<1000 và kiểm tra với với số 0<a<100 thì 
liệt kê những số a thoả mãn: ap mod q là số nguyên tố.
*/
#include<stdio.h>
#include<math.h>
#include<windows.h>
#include<time.h>

int is_Prime(int n)
{
    if(n<2)
        return 0;
    for(int i=2; i<= sqrt(n); i++)
        if(n%i==0)
            return 0;
    return 1;
}

int power(int a, int b, int n)
{
    int res=1;
    while(b>0)
    {
        if(b&1)
            res = (res*a) % n;
        a = (a*a) % n;
        b >>= 1;
    }
    return res;
}

int main()
{
    int p, q, i=0;
    srand((unsigned int)time(NULL));
    while(i==0)
    {
        p =(int)(rand()*(999-1+1.0)/(1.0+RAND_MAX));
        if(is_Prime(p))
            break;
    }
    while(i==0)
    {
        q =(int)(rand()*(999-1+1.0)/(1.0+RAND_MAX));
        if(is_Prime(q))
            break;
    }
    printf("Hai so p,q la: p = %d, q= %d\n",p,q);
    printf("Ket qua la: \n");
    for(int a=1; a<100; a++)
        if(is_Prime(power(a,p,q)))
            printf("%d ",a);
    printf("\n");
    system("pause");
}
