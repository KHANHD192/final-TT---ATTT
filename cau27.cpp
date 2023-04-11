/*
Viết chương trình in ra các cặp số (a,b) thoả mãn điều kiện 0<a,b<1000, sao cho ước 
chung lớn nhất của 2 số đó là một số nguyên tố.
*/
#include<stdio.h>
#include<math.h>

int gcd(int a, int b){
    int A, B, r;
    A = a;
    B = b;
    while(B > 0){
        r = A % B;
        A = B;
        B = r;
    }
    int d = A;
    return d;
}

int kiem_tra_ngto(int n){
    if(n < 2){
        return 0;
    }else{
        int count = 0;
        for(int i = 2; i <= sqrt(n); i++){
            if(n % i == 0){
            count++;
            }
        }

        if(count == 0){
        return 1;
        }else{
        return 0;
        }
    }

}

int kiem_tra(int A, int B){
    int k = gcd(A, B);
    if(kiem_tra_ngto(k)==1){
        return 1;
    }
    return 0;
}

int main(){
    int a, b;
    do
    {
        do
        {
            printf("Nhap a: ");
             scanf("%d", &a);
            printf("\nNhap b: ");
             scanf("%d", &b);
        } while (a>=b);
        
    } while (a<=0 && a>=1000 && b<=0 && b>=1000);

    
    printf("\nCac cap so thoa man de bai la: ");
    for(int i = a; i <= b; i++){
        for(int j = i + 1; j <= b; j++){
            if(kiem_tra(i,j)==1){
                printf("(%d, %d)  ", i, j);
            }
        }
    }
    
}