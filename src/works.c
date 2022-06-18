#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int i, np ,s;
  np =1;
  s =0;
  for(i = 0;i < n; i++){
    if(A[i]>m) return 0;
    else if(s +A[i] <= m){
      s = s+A[i];
    }else{
      np++;
      s =A[i];
    }
  }
  return np <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;   /*　x =0の場合、常にp(0)=0,なおp(1)はn=k,A[i]=1で1*/
  ub = 1e9; /*n = 1e5で、A[i]=1e4 のとき、k=1で、p(1e9) =1であり、x =1e9であれば、np =1で"np <=　k"でつねにp(1e9)=1*/
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)) ub = mid;
    else lb = mid;
  }
  printf ("%d\n", ub );
  return 0;
}
