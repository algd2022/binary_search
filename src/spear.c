#include <stdio.h>

int n;
int k;
int A[100000];

int sum(int a[],int x,int n){
    int i,sum=0;
    
    for(i=0;i<n;i++){
        sum += a[i]/x;
    }
    
    return sum;
}
int main(){
    int i, lb, ub;
    scanf("%d%d", &n, &k);
    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    lb = 999999999;
    ub = 1;
    while(lb - ub > 1){
        int mid = (lb + ub)/2;
        if(k <= sum(A,mid,n)) ub = mid;
        else lb = mid;
    }
    printf("\n%d\n",ub);


    return 0;
}
