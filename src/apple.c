#include <stdio.h>

int n;
int k;
int A[100000];

/* p determines whether all people can take home an apple when the number of
 apples allowed in the bag is x */
int p(int x) {
    int sum = 0; // the number of bags needed

    // calculate sum
    for (int i = 0; i < n; i++) {
        sum += (A[i] + x - 1) / x;
    }

    return sum <= k;
}

int main() {
    int i, lb, ub;
    scanf("%d%d", &n, &k);
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    lb = 0;
    ub = 1000000000; // = 10^9, max number of apples per 1 person

    // binery search
    while (ub - lb > 1) {
        int mid = (lb + ub) / 2;
        if (p(mid)) {
            ub = mid;
        } else {
            lb = mid;
        }
    }

    printf("%d\n", ub);
    return 0;
}
