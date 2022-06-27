#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  return A[m] >= k;
}

int main(){
  int lb, ub;
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0 - 1; //答えとしてありえる最小値は0
  ub = n; //答えとしてあり得る最大値はn
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)){
      ub = mid;
    }
    else {
      lb = mid;
    }
  }
  printf("%d\n", ub);
  return 0;
}