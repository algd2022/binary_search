#include <stdio.h>

int n;
int k;
int A[100000];


int p(int x) {
    //あるxに対して必要な鞄の数
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += (A[i] + x - 1) / x;
    }

    if (sum <= k) {
        return 1;
    }
    else {
        return 0;
    }
}

int main(){
    //項数n　と　要素k　の入力
    scanf("%d%d", &n, &k);

    //kの入力制約
    int lb=0, ub=1;
    
    //数列A[i]を入力
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
        if (ub < A[i])ub = A[i];
    }

    int mid = 1;

    while (ub - lb > 1) {
        mid = (ub + lb) / 2;
        if (p(mid)) {
            ub = mid;
        }
        else {
            lb = mid;
        }
    }
    
    printf("%d\n", ub);
    return 0;
}

