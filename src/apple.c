#include <stdio.h>

int n;
int k;
int A[100000];

int p(int bagapple){
  int bagsum = 0,i;
  for(i = 0;i < n;i++){
    bagsum += (A[i] + bagapple - 1)/bagapple;
  }
  return bagsum <= k;
}

int main(){
  int i, lb, ub;
  printf("n? k?\n");
  scanf("%d%d", &n, &k);
  printf("A[i]?\n");
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1000000000;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)) ub = mid;
    else lb = mid;
  }
  printf("x = %d\n",ub);
  return 0;
}
