#include <stdio.h>

int n;
int k;
int A[100000];

//それぞれの木において長さmの槍を作る.
//できた槍の本数の合計がk以上なら0,k未満なら1を返すような関数pを,次に定義する.
//p(m)は単調非減少関数

int p(int m) {
    int i;
    int sum = 0;
    for (i = 0; i < n ; i++) {
        sum += A[i] / m;
    }
    if (sum >= k) return 0; //単調非減少にするため
    else return 1;
}

int main() {
    int i, lb, ub;
    scanf("%d%d", &n, &k);
    for (i = 0; i < n ; i++) {
        scanf("%d", &A[i]);
    }
    // 最適化のため,lbは最大値,ubは最小値を選ぶ.
    lb = 0 ;          // m=0のときsum=∞ となり,必ずp=0となる.
                      // 一方,m=1はn=1かつA[1]=1かつk=2のような場合にp=0とならない.
                      // よって,最大値としてlb=0を選ぶ.

    ub = 1000000001;  // m=10^9+1のとき,木の長さが制約内である限り,槍は1本もできない.よって,必ずp=1.
                      // 一方,m=10^9のとき,A[i]=10^9,k=1のような場合に槍を創ることができ,p=1とならない.
                      // よって,最小値としてub=10^9+1を選ぶ.

    while (ub - lb > 1) {
        int mid = (lb + ub) / 2;
        if (p(mid) == 1)  ub = mid;
        else lb = mid;
    }
    printf("%d\n", lb); 
    return 0;


}
