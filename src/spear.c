#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
  long long int cnt = 0;
  for (int i = 0; i < n; i++){
    cnt += A[i] / x;
  }
  return cnt >= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 1;
  ub = 1e9+1;
  while (ub - lb > 1){
    int mid = (ub + lb) / 2;
    if (p(mid)){
      lb = mid;
    }else{
      ub = mid;
    }
  }
  if (lb == 1 && !p(lb)){
    printf("%d\n", lb-1);
  }else{
    printf("%d\n", lb);
  }

  return 0;
}
