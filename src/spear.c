#include <stdio.h>

int n;
int k;
int A[100000];



int main() {
    int i, lb, ub;
    scanf("%d%d", &n, &k);
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    lb = 0;
    ub = 100000000 - 1;
    while(ub - lb > 1){
        int num = 0;
        int mid = (lb + ub + 1) / 2;
        for(i = 0; i < n; ++i){
            num += A[i] / mid;
        }
        if(k <= num){
            lb = mid;
        }
        else{
            ub = mid;
        }
    }
    printf("%d\n", lb);
    return 0;
}