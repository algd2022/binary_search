#include <stdio.h>
int n;
int k;
int A[100000];


int people(int a[],int x, int n){
    int i,w=0,p=0;
    for(i=0;i<n;i++){
        w += a[i];
        if(w > x){
            p++;
            w = a[i];
        }
        if(x<a[i]) return n+1;
    }
    return p+1;
}
int main(void) {
    int i, lb, ub;
    scanf("%d%d", &n, &k);
    for(i = 0; i < n; i++){
      scanf("%d", &A[i]);
    }
    
    lb =0;
    ub = 1000000000;
    while(ub - lb > 1){
        int mid = (lb + ub)/2;
        if(people(A,mid,n) <= k) ub = mid;
        else lb = mid;
    }
    printf("\n%d\n",ub);
    return 0;
}
