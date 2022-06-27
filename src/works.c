#include <stdio.h>

int n;
int k;
int A[100000];

unsigned int max(int a, int b){
  if(a>=b) return a;
  else return b;
}

unsigned int check(int ones_work){
  int memo = ones_work, cnt = 0;
  for(int i = 0; i < k; i++){
    memo = ones_work;
    while(1){
      if(cnt >= n){
        break;
      }
      if(A[cnt] <= memo){
        memo -= A[cnt];
        cnt += 1;
      }
      else{
        break;
      } 
    }
  }
  if(cnt >= n) return 1;
  else return 0;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);

  int ones_work = 0;
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
    ones_work = max(ones_work, A[i]);
  }

  lb = 0;
  ub = ones_work + 1;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(check(mid)) ub = mid;
    else lb = mid;
  }

  printf("%d\n", ub);

  return 0;
}
