#include <stdio.h>

int n;
int k;
int A[100000];

int canApple(int);

int main() {
    int i, lb, ub;
    scanf("%d%d", &n, &k);
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    lb = 1;
    ub = 1000000000;
    int ans;
    while (lb != ub) {
        int cen = (lb + ub) / 2;
        if (canApple(cen)==0)lb = cen + 1;
        else ub = cen;
    }
    ans = ub;
    printf("%d\n", ans);
    return 0;
}

int canApple(int x) {
    int need = 0, i, ret;
    for (i = 0;i < n;i++) {
        need += A[i] / x;
        if (A[i] % x != 0)need++;
    }
    if (need <= k)ret = 1;
    else ret = 0;
    return ret;
}