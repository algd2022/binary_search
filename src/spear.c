#include <stdio.h>

int n;
int k;
int A[100000];

int canSpear(int);

int main() {
    int i, lb, ub;
    scanf("%d%d", &n, &k);
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    lb = 0;
    ub = 1000000000;
    int ans;
    while (lb != ub) {
        int cen = (lb + ub + 1) / 2;
        if (canSpear(cen) == 1)lb = cen;
        else ub = cen - 1;
    }
    ans = ub;
    printf("%d\n", ans);
    return 0;
}

int canSpear(int x) {
    int make = 0, i, ret;
    if (x == 0)ret = 1;
    else {
        for (i = 0;i < n;i++) {
            make += A[i] / x;
        }
        if (make >= k)ret = 1;
        else ret = 0;
    }
    return ret;
}