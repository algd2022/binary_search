#include <stdio.h>

int n;
int k;
int A[100000];

unsigned int max(int a, int b){
  if(a>=b) return a;
  else return b;
}

unsigned int check(int log_size){
  int sum = 0;
  for(int i = 0; i < n; i++){
    sum += (A[i] / log_size);
  }
  if(sum >= k) return 1;
  else return 0;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  int max_log = 0;
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
    max_log = max(max_log, A[i]);
  }

  lb = 0;
  ub = max_log + 1;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(check(mid)) lb = mid;
    else ub = mid;
  }

  printf("%d\n", lb);

  return 0;
}
