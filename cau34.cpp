/*
Cài đặt thuật toán kiểm tra số nguyên tố Fermat. Trong trường hợp số nào thì thuật toán 
cho kết quả kiểm tra sai.
*/
#include<stdio.h>
#include<math.h>
#include<windows.h>
#include<time.h>

//Ham tinh a^b mod n
int power(int a, int b, int n)
{
    int res = 1;
    while(b>0)
    {
        if(b&1) // kiểm tra bit cuối
            res = (res*a) % n;
        a = (a*a) % n; // dịch bit 
        b >>= 1;
    }
    return res;
}
 void fermat (int n,int t){
     //Tính a^(n-1) mod n
    int kq;
    for(int i=0; i<t; i++)
    {
        //chọn ngẫu nhiên số a
        int a=0, ran;
        while(a>=0)
        {
            ran = rand();
            if((ran>=2)&&(ran<=(n-2)))
                break;
        }
         a=ran;
        //tinh a^(n-1) mod n
        kq = power(a,n-1,n);
        if(kq!=1)
        {
            kq=0;
            break;
        }
    }
    if(kq==1){
     printf("%d la so nguyen to\n",n);
    }
    else{
         printf("%d la hop so\n",n);
    }
 }
int main()
{
    int n,t;
    srand((unsigned int)time(NULL));
    label:
        printf("Moi nhap n: ");
        scanf("%d",&n);
    if((n<3)&&(n%2==0))
    {
        printf("khong thoa man, moi nhap lai n");
        goto label;
    }

    printf("Nhap so lan kiem tra: ");
    scanf("%d",&t);
    fermat(n,t);
   
    system("pause");
}
