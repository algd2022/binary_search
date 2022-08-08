#include <stdio.h>

int n;
int k;
int A[100000];

int can_carry(int x)
{
    int nessesary_bagnumber = 0;
    int i = 0;
    while (i < n) {
        nessesary_bagnumber += (A[i] + x - 1) / x;
        i++;
    }
    if (nessesary_bagnumber <= k) {
        return 1;
    } else {
        return 0;
    }

}
int main()
{
    int i, lb, ub;
    scanf("%d%d", &n, &k);
    for(i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    lb = 0;
    ub = 1000000001;
    while (ub - lb > 1) {
        int mid = (lb + ub) / 2;
        if (can_carry(mid) == 1) {
            ub = mid;
        } else {
            lb = mid;
        }
    }
    printf("%d\n", ub);
    return 0;
}
