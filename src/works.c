#include <stdio.h>

int n;
int k;
int A[100000];




int main() {
    int i;
    scanf("%d%d", &n, &k);
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    int x = A[n-1];
    while (1) {
        int s = 1;
            int t = 0;
        for (t = 0; t < n - 1; t++) {
            if (A[t] + A[ t + 1 ] <= x) {
                A[t + 1] = A[t] + A[t + 1];
            }
            else {
                s = s + 1;
            }

        }

        printf("s=%d\n", s);

        if (s <= k) {
            break;
        }
        else {
            x = x + 1;
        }
    }



    printf("%d\n", x);

    return 0;
}
