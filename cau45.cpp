/*
Viết chương trình sinh một mảng số nguyên tố A gồm N phần tử (N nhập từ bàn phím) 
sử dụng kiểm tra Miller-Rabin. In ra mảng và tính khoảng cách nhỏ nhất giữa 2 số bất kỳ trong 
mảng.
*/
#include<stdio.h>
#include<math.h>
#include<windows.h>
#include<time.h>

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
void sclipN(int n,int *r,int *s){
     
    *s=0;
    *r = n-1;
    while(*r>0)
    {
        if(*r % 2 == 1) break;
        *r = *r/2;
        *s++;
    }
}
int miller_rabin(int n){
     int kq;
     int t = 10 ;
     int r ,s ;
    sclipN(n,&r,&s);
    for(int i=0; i<t; i++)
    {
        //Chon ngau nhien 1 so a
        int a=0, ran;
        while(a >= 0)
        {
            ran=rand();
            if((ran>=2) && (ran <= (n-2)))
                break;
        }
        a = ran;
        //T�nh y = a^r mod n
        int y= power(a,r,n), j=0;
        if((y!=1)&&(y!=n-1))
        {
            j=1;
            while((j<=(s-1))&&(y!=(n-1))) // n-1 la  -1 + mod n , khi am , va chay j 
            {
                y=(y*y)%n;
                if(y==1) // ==1 la bang chung cho hop so , 
                {
                    kq=0;
                    break;
                }
                j++;
            }
            if(y!=(n-1)) // hop so
            {
                kq=0;
                break;
            }
            // neu chua bi dinh test_case tren thi no la snt
            else kq=1;
        }
        else kq=1;
    }
    if(kq==1) {
        return 1;
    }
    else return 0;
}
int sinhNguyenTo()
{
    int p, i=0;
    while(i==0)
    {
       p= (int)(rand()*(9999 - 1 + 1.0)/(1.0+RAND_MAX));
       if(miller_rabin(p))
            break;
    }
    return p;
}
void findMin(int a[],int n){
    int min= abs(a[1]-a[0]);
    for(int i=0; i<n; i++)
        for(int j = i+1; j<n; j++)
    {
        if(abs(a[i]-a[j])< min)
            min = abs(a[i]-a[j]);
    }
    printf("Khoang cach nho nhat giua 2 so bat ki trong mang la: %d\n",min);
}
int main()
{
    int n;
    printf("Nhap so phan tu mang A: ");
    scanf("%d",&n);
    int a[n];
    srand((unsigned int)time(NULL));
    for(int i=0; i<n; i++)
        a[i] = sinhNguyenTo();
    printf("Mang nguyen to vua sinh la: \n");
    for(int i=0; i<n; i++)
        printf("%d ",a[i]);
    printf("\n");
    findMin(a,n);
    
    return 0;
}
