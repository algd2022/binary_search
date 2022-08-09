#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
  int sum = 0;
 for(int i=0; i<n; i++){
    sum = sum + (A[i]+x-1)/x; //切り上げ
  }
  return sum <= k; //kで持って帰れるなら1で持って帰れないなら0
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 1e9;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if( p(mid)) ub = mid;
    else lb = mid;
  }

  printf("%d\n", ub);
  return 0;
  }