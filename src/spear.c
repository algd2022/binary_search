#include <stdio.h>

int n;
int k;
int A[100000];


int main(){
    int i, lb = 1, ub = 1000;

    //項数n　と　要素k　の入力
    printf("input 'n' 'k'\n");
    scanf("%d%d", &n, &k);

    for(i = 0; i < n; i++){
        printf("input number %d/%d :", i + 1, n);
        scanf("%d", &A[i]);
        if (ub > A[i])ub = A[i];
    }
    printf("lb=%d,ub=%d\n", lb, ub);
    printf("input finished\n");
    

    int m = 0, x = ub,sum =0;

    while (ub - lb > 1) {
        m += 1;
        x = (ub + lb) / 2;
        sum = 0;

        //本数を計算、sum<kの時不十分なのでxを小さく(ubを小さく)する。

        for (i = 0; i < n; i++) {
            sum += (A[i] + x - 1) / x;
        }
        if (sum < k)ub = x;
        else lb = x;

        printf("lb:%d,ub:%d,sum:%d\n", lb, ub, sum);

        m += 1;
        if (m > 100) {
            printf("over");
            break;
        }
    }

    printf("Answer:%d\n", ub);
      return 0;
}
