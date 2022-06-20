#include <stdio.h>

int n;
int k;
int A[100000];


int main(){
    int i, lb, ub;
    scanf("%d%d", &n, &k);
    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    lb = -1;
    ub = n;
    while(ub - lb > 1){
        unsigned int mid = (lb + ub)/2;
        if(A[mid] < k){
            lb = mid;
        }
        else {
            ub = mid;
        }
    }
    printf("\n%d",ub);
    return 0;
}
