/* 8.1 配列の二分探索 */

#include <stdio.h>

int n; //配列の要素数
int k; //比較対象
int A[100000];

int main(){
    //ub, lb, A[]の設定
    int i, lb = -1, ub;
    scanf("%d%d\n", &n, &k);
    ub = n;                     
    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    //binary search
    while(ub - lb > 1){
        int mid = (lb + ub) / 2;
        if(A[mid] >= k){
            ub = mid;
        }else{
            lb = mid;
        }
    }

    //answer = ub
    printf("%d\n", ub);
    return 0;
}