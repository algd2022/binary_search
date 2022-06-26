#include <stdio.h>

int n;
int k;
int A[100000];

//それぞれの木において長さxの槍を作る.
//できた槍の本数の合計がk以上なら0,k未満なら1を返すような関数pを,次に定義する.
//p(x)は単調非減少関数

int p(int x) {
    int i;
    int sum = 0;
    for (i = 1; i < n + 1; i++) {
        sum += A[i] / x;
    }
    if (sum >= k) return 0; //単調非減少にするため
    else return 1;
}

int main() {
    int i, lb, ub;
    scanf("%d%d", &n, &k);
    for (i = 1; i < n + 1; i++) {
        scanf("%d", &A[i]);
    }
    // 最適化のため,lbは最大値,ubは最小値を選ぶ.
    lb = 0 ;          // x=0のときsum=∞ となり,必ずp(0)=0となる.
                      // 一方,x=1はn=1かつa[1]=1かつk=10^5のような場合にp=0とならない.
                      // よって,最大値としてlb=0を選ぶ.

    ub = 1000000001;  // x=10^9+1のとき,木の長さが制約内である限り,槍は1本もできない.よって,必ずp(10^9+1)=1.
                      // 一方,x=10^9のとき,A[i]=10^9,k=1のような場合にp=1とならない.
                      // よって,最小値としてub=10^9+1を選ぶ.

    while (ub - lb > 1) {
        int mid = (lb + ub) / 2;
        if (p(mid) == 1)  ub = mid;
        else lb = mid;
    }
    printf("%d\n", lb);
    return 0;


}
