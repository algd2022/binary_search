#include <stdio.h>

int binary_search(int a[], int x, int l, int r){
    int m;
    m = (l + r) / 2;
    if (a[m]==x) 
        return m;
    else if (l>r)
        return m+1;
    else if (a[m]<x)
        return binary_search(a,x,m+1,r);
    else 
        return binary_search(a, x, l,m-1);
    }

int main(){
  int i, lb, ub,n,k;
  scanf("%d %d", &n, &k);
  int A[100000];
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

    lb = 0;
    ub = n - 1;
    printf("%u", binary_search(A, k, lb, ub));
    return 0;
}