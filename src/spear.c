#include <stdio.h>

int n;
int k;
int A[100000];


int main(){
    int i, lb, ub, num, max, sum;
    max = 0;
    sum = 0;
    scanf("%d%d", &n, &k);
    for(i = 0; i < n; i++){
        scanf("%d", &num);
        A[i] = num;
        sum = sum + num;
        if(num > max){
            max = num;
        }
    }
    lb = max/k;
    ub = sum/k + 1;
    while(ub - lb > 1){
        int mid = (lb + ub)/2;
        int spears;
        int j;
        spears = 0;
        for(j = 0; j < n; j++){
            spears = spears + A[j]/mid;
        }
        if(spears > k){
            lb = mid;
        }
        else{
            ub = mid;
        }
    }
    printf("\n%d",lb);
    return 0;
}
