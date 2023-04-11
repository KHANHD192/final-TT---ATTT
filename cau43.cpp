/*
Cho N nhập vào từ bàn phím (0<N<1000), sinh một số nguyên tố p<100. Hãy viết 
chương trình tìm tất cả các số nguyên a<N sao cho ap mod N là số nguyên tố.
*/
#include<stdio.h>
#include<math.h>
#include<time.h>

bool is_Prime(int n)
{
    if(n<2)
        return 0;
    for(int i=2; i<= sqrt(n); i++)
        if(n%i==0)
            return false;
    return true;
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
void solution(int n ){
    srand((unsigned int)time(NULL));
    int p;
    bool flag =true;
    srand((unsigned int)time(NULL));
    while(flag)
    {
        p =(int)(rand()*(99-1+1.0)/(1.0+RAND_MAX));
        if(is_Prime(p))
            break;
    }
    printf("P = %d\n",p);
    printf(" cac so sao cho ap mod N la snt.\n");
    for(int a = 1 ; a < n ; a++){
         if(is_Prime(power(a,p,n))){
                     printf("%d ",a);
         }
    }

}
int main (){
    int n;
   j: printf("nhap n :");
    scanf("%d",&n);
    if(n < 0 || n > 1000){
        printf("sai yeu cau ! nhap lai :");
        goto j;
    }
    solution(n);
    return 0;
}