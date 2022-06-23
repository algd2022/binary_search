#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  unsigned int i, s;
  s = 0;
  for(i = 1; i <= n; i++){
    s = s + A[i - 1] /m;
  }
  return  s >= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1e9 + 1; /*1e9の長さの槍はギリギリ作れちゃう*/
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
