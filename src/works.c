#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int sum = 0, cnt = 1;
  for(int i = 0; i < n; i++){
    if(A[i] > m){
      return 0;
    }
    else if(sum + A[i] <= m){
      sum += A[i];
    }
    else {
      sum = A[i];
      cnt++;
    }
  }
  if(cnt <= k) return 1;
  else return 0;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1000000000;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)){
      ub = mid;
    }
    else {
      lb = mid;
    }
  }
  printf("%d\n",ub);
  return 0;
}
