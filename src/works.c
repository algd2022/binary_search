#include <stdio.h>

int n;
int k;
int A[100000];

// 全員の仕事量がそれぞれm以下となるように仕事を配分したとき,
// 必要な人員数がk以下ならば1を,kより大きいならば0を返すような関数p(m)を定義する.
// p(m)は単調非減少関数

int p(int m) {
    int i;
    int workers = 1;
    int works = 0;

    for (i = 1; i < n + 1; i++) {
        if (works + A[i] <= m) { works += A[i]; } // 仕事量A[i]を追加しても,その人の仕事量がmを超えないならば,A[i]を追加する.
        else if (A[i] > m) { return 0; }      // これを記述しないと,A[i] > mとなるような仕事があった場合,workersが永遠に増えてしまう.
        else if (works + A[i] > m) {  // 仕事量A[i]を追加したとき,その人の仕事量がmを超えるならば,その人には割り当てず,
            workers++;                // 次の人を呼び(人員を増やし),                                   
            works = A[i];             // その人に仕事量A[i]を与える.
        }
    }
    if (workers <= k) return 1;
    else return 0;
}

int main() {
    int i, lb, ub;
    scanf("%d%d", &n, &k);
    for (i = 1; i < n + 1; i++) {
        scanf("%d", &A[i]);
    }
    // 最適化のため,lbは最大値,ubは最小値を選ぶ.
    lb = 0;           // m=0のとき必ずp=0となる.
                      // 一方,m=1はn=kの場合にp=0とならない.
                      // よって,最大値としてlb=0を選ぶ.     

    ub = 1000000000;    // m=10^9のとき,必ずp=1となる.
                        // 一方,m=10^9-1のとき,A[i]=10^4,n=10^5,k=1のような場合にp=1とならない.
                        // よって,最小値としてub=10^9を選ぶ.

    while (ub - lb > 1) {
        int mid = (lb + ub) / 2;
        if (p(mid) == 1)  ub = mid;
        else lb = mid;
    }
    printf("%d\n", ub);
    return 0;


}