#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x) {
    int sum = 0, job = 0;

    //1人x以下の仕事量をしたときに必要な人数を計算
    for (int i = 0; i < n; i++) {

        if (A[i] > x)return 0;

        job += A[i];

        if (job > x) {
            sum++;
            job = A[i];
        }
    }
    sum++;

    if (sum <= k) {
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

    //数列を入力
    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
        ub += A[i];
        if (lb < A[i]) lb = A[i];
    }
    lb--;

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
