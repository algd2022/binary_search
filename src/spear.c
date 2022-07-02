#include <stdio.h>

int n;
int k;
int A[100000];

int can_make(int x)
{
    int makeable_spear_number = 0;
    int i = 0;
    while (i < n) {
        makeable_spear_number += A[i] / x;
        i++;
    }
    if (makeable_spear_number >= k) {
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
    ub = 1000000000;
    while (ub - lb > 1) {
        int mid = (lb + ub) / 2;
        if (can_make(mid) == 1) {
            lb = mid;
        } else {
            ub = mid;
        }
    }
    printf("%d\n", lb);
    return 0;
}
