#include <stdio.h>

int n;
int k;
int A[100000];


int p(int x) {
    int S = 0;
    for (int i = 0; i < n; i++)
    {
        S = S + (A[i] + x - 1) / x;
        
    }

    if(S <= k)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int main() {
    int i, lb, ub;
    scanf("%d%d", &n, &k);
    lb = 0;
    ub = 1000000000;
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    while (ub - lb > 1) {
        int mid = (lb + ub) / 2;
        if (p(mid)) {
            ub = mid;
         }
        else 
        {
            lb = mid;
        }
    }

    printf("%d", ub);

    return 0;
}