#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int i, l;
  l = 0;
  for(i = 0;i < n; i++){
    l += (A[i] / m);
    if(A[i] % m > 0){
      l += 1;
    } 
    if(l > k) return 0;
  }
  return 1;
}

int main(){
  int i, lb, ub;
  lb = 0;
  ub = 1000000000;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)){
      ub = mid;
    }
    else{
      lb = mid;
    }
  }

  printf("%d", ub);

  return 0;
}