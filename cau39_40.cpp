/*
Cho mảng A nhập từ bàn phím gồm các số nguyên dương. Hãy viết chương trình tìm các 
cặp số (i,j) trong mảng A sao cho ước chung lớn nhất của chúng là một số nguyên tố.
*/
#include<stdio.h>
#include<math.h>
#include<time.h>
 void nhapmang(int A[],int n){
    for(int i = 0; i < n ; i++){
        printf("A[%d] :",i);
        scanf("%d",&A[i]);
    }
 }
 bool is_prime(int n)
{
    if(n<2)
        return 0;
    for(int i=2; i <= sqrt(n); i++)
        if(n % i ==0)
            return false;
    return true;
}
 int gcd(int a, int b)
{
    while(b>0)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}
 int solution (int A[],int n){
    int count = 0 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; j < n ; j++){
            if(is_prime(gcd(A[i],A[j]))){
                count++;
                     printf("(%d,%d) co gcd bang %d la snt\n",A[i],A[j],gcd(A[i],A[j]));
            }
        }
    }
    return count;
 }

 int main(){
    int n;
    printf("nhap do dai cua mang :");
   label:scanf("%d",&n);
    if(n <=1 ){
        printf("yeu cau nhap lai :");
        goto label;
    }
    int A[n];
    nhapmang(A,n);
    int result =solution(A,n);
    printf("so cap (i,j) co UCLN la SNT trong mang A la %d",result);
    return 0;
 }