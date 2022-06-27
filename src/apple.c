#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int i;
  int sum = 0;
  for (i = 0; i < n; i++){
    sum = sum +  (A[i] + m - 1) / m;
  }
  return sum <=k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0; /*1個以上収穫するから*/
  ub = 1000000000; /*入力制約より*/
  while(ub - lb > 1) {
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


