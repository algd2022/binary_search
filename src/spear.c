#include <stdio.h>

int n;
int k;
int A[100000];
int p(int m){
    return m<k;
}
int sum(int A[],int x){
    int b=0;
    for(int i=0;i<n;i++){
       b+=A[i]/x;
    }
    return b;
}
int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb=0;
  ub=1000000001;
  while ( ub - lb > 1) {
      int mid = ( lb + ub ) / 2;
      if( p (sum(A,mid))){
       ub = mid ;
       }
      else {
       lb = mid ;
      }
    }
  printf("\n%d\n",lb);

  return 0;
  }