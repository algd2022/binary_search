#include <stdio.h>

int n;
int k;
int A[100000];

/* p determines whether k or less people can do x or less works */
int p(int x) {
    int numP = 1;  // the number of people needed
    int works = 0; // sum of a work

    for (int i = 0; i < n; i++) {
        // if A[i] > x, it's impossible to give works!
        if (A[i] > x)
            return 0;

        // give a man works until that exceed x
        if (works + A[i] <= x) {
            works += A[i];
        }
        // if works exceed x, give other man works
        else {
            numP++;
            works = A[i];
        }
    }

    return numP <= k;
}

int main() {
    int i, lb, ub;
    scanf("%d%d", &n, &k);
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    lb = 0;
    ub = 1000000000; // = 10^9, if all works are 10^4 and need 10^5 hours

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
