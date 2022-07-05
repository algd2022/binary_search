#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int n;
int k;
int A[100000];

bool can(int x) {
    int sum = 0;
    for (int j = 0; j < n; j++) {
        sum += A[j] / x;
    }
    if (sum >= k) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int i, lb = 0, ub = pow(10, 9)+1, mid;
    scanf("%d%d", &n, &k);
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    while (ub - lb > 1) {
        mid = (ub + lb) / 2;
        if (can(mid)) {
            lb = mid;
        } else {
            ub = mid;
        }
    }
    printf("%d\n", lb);
    return 0;
}
