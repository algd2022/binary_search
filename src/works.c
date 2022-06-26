#include <stdio.h>

int n;
int k;
int A[100000];

int can_distribute(int max_work_amount)
{
    int i = 0;
    int human = 1;
    int human_work = 0;
    while (i < n) {
        if (max_work_amount < A[i]) {
            return 0;
        }
        if (human_work + A[i] > max_work_amount) {
            human++;
            human_work = 0;
        } else {
            human_work += A[i];
        }
        i++;
    }
    return(human <= k);
}
int main()
{
    int i, lb, ub;
    scanf("%d%d", &n, &k);
    for(i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    lb = 0;
    ub = 100000000;
    while (ub - lb > 1) {
        printf("%d,%d\n", lb, ub);
        int mid = (lb + ub) / 2;
        if (can_distribute(mid) == 1) {
            ub = mid;
        } else {
            lb = mid;
        }
    }
    printf("%d,%d\n",lb,ub);
    return 0;
}