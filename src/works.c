#include <stdio.h>

int n;
int k;
int A[100000];

// can allocate (max work: x hours) ? 1 : 0
unsigned int can_alloc(int x) {
    int i, alloc = 0, man = 1;
    for (i = 0; i < n; i++) {
        if (alloc + A[i] > x) {
            if (A[i] > x) {  // Amax > x
                return 0;
            }
            // new man works from i-hour
            man++;
            alloc = A[i];
        } else {
            // continue working
            alloc = alloc + A[i];
        }
    }
    if (man <= k) {
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
        if (can_alloc(mid)) {
            ub = mid;
        } else {
            lb = mid;
        }
    }

    printf("%d\n", ub);

    return 0;
}
