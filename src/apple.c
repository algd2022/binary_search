#include <stdio.h>

int n;
int k;
int A[100000];

int p(int bag_accept);

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
    if(p(mid)){
      ub = mid;
    }
    else{
      lb = mid;
    }
  }

  printf("%d\n", ub);

  return 0;
}

int p(int bag_accept){
  int i, bag_sum;

  bag_sum = 0;
  for(i = 0; i < n; i++){
    bag_sum += (A[i] + bag_accept - 1) / bag_accept;
  }

  if(bag_sum <= k) return 1;
  else return 0;
}