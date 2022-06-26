#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int S = 0;
  for (int i = 0; i < n;i++){
      S +=  A[i] / m;
    }
  return S < k;
  }
int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0 ;
  ub = n*1000000000+1;
  while(ub - lb>1){
  int mid = (lb + ub) / 2;
  if (p(mid)){
      ub = mid;
    }
    else {
        lb = mid;
    }
  }
  printf("%d\n", lb);


  return 0;
}
