#include <stdio.h>

int n;
int k;
int A[100000];

unsigned int check(int bag_size){
  int sum = 0;
  for(int i = 0; i < n; i++){
    sum += (A[i] + bag_size - 1) / bag_size;
  }
  if(sum <= k) return 1;
  else return 0;
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
    int mid = (lb + ub) / 2;
    if(check(mid)) ub = mid;
    else lb = mid;
  }

  printf("%d\n", ub);

  return 0;
}
