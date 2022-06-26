#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x) {
    int i;
    int sum = 0;
    for (i = 1; i < n + 1; i++) {
        sum += (A[i] + x - 1) / x;
    }
    if (sum <= k) return 1;
    else return 0;
}

int main() {
    int i, lb, ub;
    scanf("%d%d", &n, &k);
    for (i = 1; i < n + 1; i++) {
        scanf("%d", &A[i]);
    }
    lb = 0 ;          //全員がリンゴを1個収穫した場合を考えると,p(1)==1となる可能性があると分かる. 
    ub = 1000000000;    //n==kかつa[i]=10^9の場合を考えれば,p(999999999)==0となる可能性があると分かる.
    while (ub - lb > 1) {
        int mid = (lb + ub) / 2;
        if (p(mid) ==1)  ub = mid;
        else lb = mid;
    }
    printf("%d\n", ub);
    return 0;


}
