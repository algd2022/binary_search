#include <stdio.h>

int n;
int k;
int A[100000];

int p(unsigned int x){
  int i;
  int now,cnt;
  now = 0;
  cnt = 1;
  for(i = 0; i < n; i++){
    if(A[i] > x) return 0;
    if(now + A[i] > x){
      cnt++;
      now = A[i];
    }
    else now += A[i];
  }
  return k >= cnt;

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
    int mid = (lb+ub) / 2;
    if(p(mid)) ub = mid;
    else lb = mid;
  }

  printf("%d\n", ub);

  return 0;
}
