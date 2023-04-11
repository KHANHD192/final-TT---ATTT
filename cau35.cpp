/*
Cài đặt thuật toán kiểm tra số nguyên tố Miller-Rabin in ra kết luận về 1 số nguyên 
dương N nhập vào từ bàn phím với xác suất kết luận tương ứng sau thuật toán.
*/
#include<time.h>
#include<stdio.h>
#include<math.h>
#include<windows.h>

//Ham tinh a^b mod n
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
void miller_rabin(int n,int t ,int r ,int s){
     int kq;
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
    if(kq==1) printf("%d la so nguyen to\n",n);
    else printf("%d la hop so\n",n);
}
int main()
{
    int n,i,t;
    int r,s;
    srand((unsigned int)time(NULL));
    label:
       printf("Moi nhap n: ");
       scanf("%d",&n);
    if((n<2) || (n%2==0))
    {
        printf("n khong thoa man\n");
        goto label;
    }

    printf("Nhap so lan kiem tra: ");
    scanf("%d",&t);

    sclipN(n,&r,&s); //Ph�n t�ch n-1= r * 2^s
    miller_rabin(n,t,r,s);
   
    system("pause");
}
