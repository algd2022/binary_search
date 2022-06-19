#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
    int sum = 0;
    for(int i = 0;i < n;++i){
      sum += A[i]/m;
    }
    if(sum >= k) return 1;
    else return 0;
}


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  //lbか答え
  lb = 0;
  ub = 1e9+1;
  while(ub -lb > 1){
    int mid = (ub - lb)/2 + lb;
    if(p(mid)) lb = mid;
    else ub = mid;
  }

  printf("%d\n", lb);
  return 0;
}
