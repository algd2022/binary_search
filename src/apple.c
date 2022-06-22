#include <stdio.h>

int n;
int k;
int A[100000];

int sum(int a[],int x, int n){
    int sum = 0,i;
    for(i=0;i<n;i++){
        sum += (a[i] + x-1)/x;
    }
    return sum;
}


int main(){
    int i, lb, ub;
    scanf("%d%d", &n, &k);
    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    lb=0;
    ub=1000000000;
    while(ub - lb > 1){
        int mid = (lb + ub)/2;
        if(k >= sum(A,mid,n)) ub = mid;
        else lb = mid;
    }
    printf("\n%d\n",ub);

  return 0;
}
