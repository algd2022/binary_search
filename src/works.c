#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int i, j, l, a;
  j = 0;
  l = 0;
  a = 0;
  for(i = 0; i < k - 1; i++){
    a = A[l];
    if(a > m) return a <= m;
    for(j = l; ((j < n - k + i) && (a <= m)); j++){
      a = a + A[j + 1];
    }
    if((j == n - k + i) && (a <= m)){ 
      j = j + 1;
    }
    l = j;
  }
  a = A[l];
  for(i = l; i < n - 1; i++){
    a = a + A[i + 1];
  }
  return a <= m;
}


/* pの計算量はO(n) */

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 10000 * (n - k + 1);
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)){
      ub = mid;
    }
    else{
      lb = mid;
    }
  }
  printf("%d\n", ub);
  return 0;
}
