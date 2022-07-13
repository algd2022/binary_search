#include <stdio.h>

int n;
int k;
int A[100000];

int canWork(int);

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
        if (canWork(cen) == 0)lb = cen + 1;
        else ub = cen;
    }
    ans = ub;
    printf("%d\n", ans);
    return 0;
}

int canWork(int x) {
    int need = 1, i, ret, tmp=x;
    for (i = 0;i < n;i++) {
        if (tmp >= A[i])tmp -= A[i];
        else {
            need++;
            tmp = x;
            if (tmp >= A[i])tmp -= A[i];
            else return 0;
        }
    }
    if (need <= k)ret = 1;
    else ret = 0;
    return ret;
}