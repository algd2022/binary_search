#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x) {
    int i;
    int sum = 0;
    for (i = 1; i < n + 1; i++) {
        sum += (A[i] + x - 1) / x;
    }
    if (sum <= k) return 1;
    else return 0;
}

int main() {
    int i, lb, ub;
    scanf("%d%d", &n, &k);
    for (i = 1; i < n + 1; i++) {
        scanf("%d", &A[i]);
    }
    lb = 0 ;          //�S���������S��1���n�����ꍇ���l�����,p(1)==1�ƂȂ�\��������ƕ�����. 
    ub = 1000000000;    //n==k����a[i]=10^9�̏ꍇ���l�����,p(999999999)==0�ƂȂ�\��������ƕ�����.
    while (ub - lb > 1) {
        int mid = (lb + ub) / 2;
        if (p(mid) ==1)  ub = mid;
        else lb = mid;
    }
    printf("%d\n", ub);
    return 0;


}
