#include <stdio.h>

int n;
int k;
int A[100000];


int main(){
    int i, /*lb = 0,*/ ub = 0;

    //項数n　と　要素k　の入力
    printf("input 'n' 'k'\n");
    scanf("%d%d", &n, &k);

    for(i = 0; i < n; i++){
        printf("input number %d/%d :", i + 1, n);
        scanf("%d", &A[i]);
        if (ub < A[i])ub = A[i];
    }
    
    printf("input finished\n");

    int x = ub, sum = 0;
    int m = 0;

    i = 0;
    for(int j = 0 ; j < k; j++){
        //i = 0;
        sum = 0;

        printf("j:%d,x:%d\n",j, x);

        while (sum < n) {
            sum += A[i];

            printf("i:%d,j:%d,sum:%d,k:%d\n", i, j, sum, k);

            m += 1;
            if (m > 10) {
                printf("over");
                break;
            }
            i += 1;
            if (i >= n)break;
        }

        if (x < sum)x = sum;
    }

    printf("Answer:%d\n", x);
    return 0;
}
