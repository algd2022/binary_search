#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x) {
    int s = 0;
    if (x == 0) return 1;
    for (int i = 0; i < n; i++) {
        s += A[i] / x;
    }
    if (s >= k) return 1;
    else return 0;
}


int main() {
    int i, lb, ub;
    scanf("%d%d", &n, &k);
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    lb = -1; ub = 1000000001;
    while (ub - lb > 1) {
        int mid = (lb + ub) / 2;
        if (p(mid) == 0) ub = mid;
        else lb = mid;
    }
    printf("%d\n", lb);
    return 0;
}