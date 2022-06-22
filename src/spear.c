#include <stdio.h>

int n;
int k;
int A[100000];

/* p determines whether it is possible to create k spears */
int p(int x) {
    int sum = 0; // the number of spear created

    // calculate sum
    for (int i = 0; i < n; i++) {
        sum += A[i] / x;
    }

    return sum >= k;
}

int main() {
    int i, lb, ub;
    scanf("%d%d", &n, &k);
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    lb = 0;
    ub = 1000000000; // = 10^9, max length of wood

    // binery search
    while (ub - lb > 1) {
        int mid = (lb + ub) / 2;
        if (p(mid)) {
            lb = mid;
        } else {
            ub = mid;
        }
    }

    printf("%d\n", lb);
    return 0;
}
