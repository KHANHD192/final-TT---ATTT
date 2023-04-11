/*
Cho p=2147483647; W=8. Với t là độ dài từ của p,
hãy nhập các giá trị a, b  [0, 2^Wt) từ bàn phím và AD thuật toán cộng chính xác bội
để thực hiện tính giá trị c, với c = a + b mod 2^Wt.
*/

#include <stdio.h>
#include <math.h>

void chuyenSoNguyenLon(int arr[100], long long int p, int W, long long int num, int t)
{
    for (int i = t - 1; i >= 0; i--)
    {
        int z = pow(2, W * i);
        arr[i] = num / z;
        num %= z;
    }
}

int main()
{
    int W, m, t, e, h, arr[100], brr[100], c[100];
    long long int p, a, b;

    W = 8;
    p = 2147483647;
    m = (log2(p));
    t = ceil((double)m / W);

    printf("Nhap a, b: ");
    scanf("%lld%lld", &a, &b);

    chuyenSoNguyenLon(arr, p, W, a, t);
    chuyenSoNguyenLon(brr, p, W, b, t);

    e = 0;
    for (int i = 0; i < t; i++)
    {
        c[i] = arr[i] + brr[i] + e;
        h = pow(2, W);
        if (c[i] >= h)
        {
            e = 1;
            c[i] %= h;
        }
        else
        {
            e = 0;
            c[i] %= h;
        }
    }

    printf("C = A + B = (%d, [", e);
    for (int i = t - 1; i >= 0; i--)
    {
        printf("%d", c[i]);
        if (i != 0)
        {
            printf("   ");
        }
        else
        {
            printf("])");
        }
    }

    long long int res = 0;
    for (int i = t - 1; i >= 0; i--)
    {
        res += pow(2, i * W) * c[i];
    }
    printf("\nC = %lld", res);

    return 0;
}
