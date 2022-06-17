#include <stdio.h>

int n;
int k;
int A[100000];

// all people can carry by k bags (x apple per bag) ? 1 : 0
unsigned int can_carry(int x) {
    int i, sum = 0;
    // sum's max: 2e9 s.t. all A[i] = 1e9 and x = 5e8(initial) -> int
    for (i = 0; i < n; i++) {
        sum = sum + (A[i] + x - 1) / x;  // round up division
    }
    if (sum > k) {
        return 0;
    } else {
        return 1;
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
        if (can_carry(mid)) {
            ub = mid;
        } else {
            lb = mid;
        }
    }

    printf("%d\n", ub);

    return 0;
}
