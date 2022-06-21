#include <stdio.h>

int n;
int k;
int A[100000];


int main() {
    int i, lb, ub;
    scanf("%d%d", &n, &k);
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    lb = 0;
    ub = n - 1;
    int ans;
    if (A[n - 1] < k)ans = n;
    else {
        while (lb != ub) {
            int cen = (lb + ub) / 2;
            if (A[cen] < k)lb = cen + 1;
            else ub = cen;
        }
        ans = ub;
    }
    printf("%d\n", ans);
    return 0;
}