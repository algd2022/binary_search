#include <stdio.h>

int n;
int k;
int A[100000];


int main(){
    int i, lb, ub, num, sum, max;
    sum = 0;
    max = 0;
    scanf("%d%d", &n, &k);
    for(i = 0; i < n; i++){
        scanf("%d", &num);
        A[i] = num;
        sum = sum + num;
        if(num > max){
            max = num;
        }
    }
    lb = sum/k;
    ub = max + 1;
    while(ub - lb > 1){
        unsigned int mid = (lb + ub)/2;
        int bags = 0;
        int j;
        for(j = 0; j < n; j++){
            bags = bags + (A[j] - 1)/mid + 1;
        }
        if(bags > k){
            lb = mid;
        }
        else{
            ub = mid;
        }
    }
    printf("\n%d",ub);
    return 0;
}
