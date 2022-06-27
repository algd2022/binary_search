#include <stdio.h>

int n;
int k;
int A[100000];
int  sum_bag ;

int p( int m){
 int i;
 sum_bag=0;
 for(i = 0; i < k; i++){
    sum_bag +=  (A[i] + m - 1) / m;
   }
  return sum_bag <= k;
}
int main(){
  int i, lb, ub,max_a;
  max_a = 0;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
    if(A[i] > max_a){
       max_a= A[i];
    }
  }
  lb = 0;
  ub = max_a;

  while(ub - lb >1){
    int mid = (lb + ub ) / 2;
    if (p(mid)){
      ub = mid ;
  }
    else{
      lb = mid;
  }

   }
  printf("%d\n", ub);
  return 0;
}
