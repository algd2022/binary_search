#include <stdio.h>

int n;
int k;
int A[100000];


int p(int x) {
    int sum = 0;

    //あるxについて作成可能なやりの数を計算
    for (int i = 0; i < n; i++) {
        sum += A[i] / x;
    }

    if (sum >= k) {
        return 1;
    }
    else {
        return 0;
    }
}

int main(){
    int i, lb = 0, ub = 0;

    //項数n　と　要素k　の入力
    scanf("%d%d", &n, &k);

    //数列A[i]を入力
    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
        if (ub < A[i])ub = A[i];
    }
    ub++;

    int mid = 0;

    while (ub - lb > 1) {
        mid = (ub + lb) / 2;
        if (p(mid)) {
            printf("mid=%d,p=1\n", mid);
            lb = mid;
        }
        else {
            ub = mid;
            printf("mid=%d,p=0\n", mid);
        }
    }

    printf("%d\n", lb);
    return 0;
}
