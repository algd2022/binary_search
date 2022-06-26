#include <stdio.h>

int n;
int k;
int A[100000];

//p�͒P���񌸏��ł���
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
    // lb�͍ő�l,ub�͍ŏ��l��I��.

    lb = 0 ;          // x=0�̂Ƃ�,���͐�����Œ�1�͎��n����Ă���̂ŕK��p=0�ƂȂ�.
                      // ���,x=1�̂Ƃ�,�S���������S�����傤��1���n�����ꍇ���l�����,p=0�ƂȂ�Ȃ��ꍇ������ƕ�����.
                      // �����,�ő�l�Ƃ���lb=0��I��.

    ub = 1000000000;   // x=10^9�̂Ƃ�, ���͐�����A[i]<=10^9�ł���.�o�b�O�͐l�����ȏ゠��̂ŕK��p=1�ƂȂ�.
                       // ���,x=10^9-1�̂Ƃ�,n=k����a[i]=10^9�̏ꍇ���l�����,p=1�ƂȂ�Ȃ��ꍇ������ƕ�����.
                       // �����,�ŏ��l�Ƃ���ub=10^9��I��.
    while (ub - lb > 1) {
        int mid = (lb + ub) / 2;
        if (p(mid) ==1)  ub = mid;
        else lb = mid;
    }
    printf("%d\n", ub);
    return 0;

}
