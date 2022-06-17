#include <stdio.h>

int n;
int k;
int A[100000];
int p(int x){
  int i =0;
  double s =0;
  while(i<n){
    s = s +(A[i])/x;
    i++;
  }
  return (long long int) s >= k;
}/*単調減少関数となる(111..10..000)*/


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;   /*　x =0の場合、常にp(0)=1*/
  ub = 1e9+1; /*k = 1  の時、A[i] の最大値がの取りうる最大値xとなるが、 A[i]は1e9まで取りうる。よって、p(x)=0と確実になるxは1e9より大きい物、よって、1e9+1となる。*/
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)) lb = mid;
    else ub = mid;
  }
  printf ("%d\n", lb );
  return 0;
}
