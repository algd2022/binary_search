#include <stdio.h>

int n;
int k;
int A[100000];

unsigned int can_cut(int x) {
    int i, sum = 0;
    // sum's max: 2e9 s.t. all A[i] = 1e9 and x = 5e8(initial) -> int
    for (i = 0; i < n; i++) {
        sum = sum + A[i] / x;  // round down division
    }
    if (sum >= k) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int i, lb, ub;
    scanf("%d%d", &n, &k);
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    lb = 0;
    ub = 1000000001;

    while (ub - lb > 1) {
        int mid = (lb + ub) / 2;  // will not become 0
        // printf("%d\n", mid);
        if (can_cut(mid)) {
            lb = mid;
        } else {
            ub = mid;
        }
    }

    printf("%d\n", lb);

    return 0;
}
