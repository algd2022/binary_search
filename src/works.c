
#include <stdio.h>
int n;
int k;
int A[100000];
int p(int m){
    int work=0;
    int people=1;
    for(int i=0;i<n;i++){
        if(work+A[i]<=m){
            work+=A[i];
        }
        else if(A[i]<=m){
            people+=1;
            work=A[i];
        }
        else{
            return 0;
        }
    }
    return people<=k;
}
int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb=0;
  ub=1000000000;
  while ( ub - lb > 1) {
      int mid = ( lb + ub ) / 2;
      if( p (mid)){
       ub = mid ;
       }
      else {
       lb = mid ;
      }
    }
  printf("\n%d\n",ub);

  return 0;
  }