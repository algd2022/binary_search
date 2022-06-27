#include <stdio.h>

int n;
int k;
int A[100000];


int main(){
    //項数n　と　要素k　の入力
    printf("input 'n' 'k':\n");
    scanf("%d%d", &n, &k);

    //kの入力制約
    int lb = -1, ub = n;
    int i;

    for (i = 0; i < n; i++) {
        printf("input number %d/%d :", i + 1, n);
        scanf("%d", &A[i]);
    }

    printf("input finished\n");

    int mid;
    int m=0;

    while (ub - lb > 1) {
        m += 1;

        mid = (ub + lb) / 2;
        //printf("mid = %d\n", mid);

        if (A[mid] >= k) {
            ub = mid;
        }
        else {
            lb = mid;
        };

        if (m > 20)break;
    }

    printf("Answer:%d\n", ub);
  return 0;
}
