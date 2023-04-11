/*
Viết chương trình tìm các số nguyên tố từ một mảng sinh ngẫu nhiên có kích thước N, 
với N nhập vào từ bàn phím
*/
#include<stdio.h>
#include<math.h>
#include<windows.h>
#include<time.h>

int is_prime(int n)
{
    if(n<2)
        return 0;
    for(int i=2; i <= sqrt(n); i++)
        if(n % i ==0)
            return 0;
    return 1;
}

void hamSinhMang(int a[], int n)
{
    for(int i=0; i<n; i++)
    {
        a[i] = rand();
    }
}

void inMang(int a[], int n)
{
    for(int i=0; i<n; i++)
        printf("%d ", a[i]);
}

int main()
{
    int n;
    printf("Moi nhap n: ");
    scanf("%d", &n);
    int a[n];
    srand((unsigned int)time(NULL));
    hamSinhMang(a,n);
    printf("Mang da sinh ngau nhien la: \n");
    inMang(a,n);
    printf("\nCac so nguyen to trong mang la: \n");
    for(int i=0; i<n; i++)
        if(is_prime(a[i]))
            printf("%d ", a[i]);
    printf("\n");
   return 0;
}
