#include <stdio.h>

int n;
int k;
int A[100000];
int p(int x){
  int i =0;
  int s =0;
  while(i<n){
    s = s +(A[i]+x-1)/x;
    i++;
  }
  return (long long int) s <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;   /*　x =0の場合、常にp(0)=0,なおp(1)はA[i]の和がk以下の場合に、p(1)=1*/
  ub = 1e9; /*n = k の時、A[i] の最大値がxとなるが、 A[i]は高々1e9であるため、xは1e9以上であれば、必ず、p(1e9)=1となる。*/
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)) ub = mid;
    else lb = mid;
  }
  printf ("%d\n", ub );
  return 0;
}
