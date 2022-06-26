#include <stdio.h>

int n;
int k;
int A[100000];
int p(int x) {
  int i, cnt = x, man = 1;
  for (i = 0; i < n; i++) {
    if(cnt >= A[i]){
      cnt -= A[i];
    }else{
      man++;
      cnt = x - A[i];
      if(cnt < 0){
        return 0;
      }
    }
  }
  return man <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1000000000;
  while (ub - lb > 1) {
    int mid = (ub + lb) / 2;
    if (p(mid)) {
      ub = mid;
    }
    else {
      lb = mid;
    }
  }
  printf("%d\n", ub);

  return 0;
}
