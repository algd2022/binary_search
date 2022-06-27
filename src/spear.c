#include <stdio.h>

int n;
int k;
int A[100000];


int main() {
    int i, lb, ub;
    lb = 0;
    ub = 1e9;
    scanf("%d%d", &n, &k);
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    while (ub-lb>1) {
        int B = 0;
        int mid = (lb + ub) / 2;
        for (i = 0; i < n; i++) {
            B = B + A[i] / mid;
        }
        if (B<k) {
            ub = mid;
        }
        else {
            lb = mid;
        }
        
    }
    printf("%d\n", lb);

    
    return 0;
}