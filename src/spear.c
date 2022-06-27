#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
  int total = 0;
  int i;
  for(i = 1; i <= n; i++){
    total = total + A[i] / x;
  }
  if(total >= k){
	return 1;
  }
  else{
	return 0;
  }
}
int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1000000001;
// 槍の長さは10^9で頭打ち
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)){
	lb = mid;
    }
    else{
	ub = mid;
    }
  }
  printf("%d\n", lb);
  return 0;
}
