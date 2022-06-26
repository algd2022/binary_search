#include <stdio.h>

int n;
int k;
int A[100000];

unsigned int p(int x){
  unsigned int sum, count;
  sum = 0;
  count = 1;
  for(int i=0; i<n; i++){
    sum = sum + A[i];
    if(sum > x){
      if(A[i] > x) return 0;
      sum = A[i];
      count++;
    }
  }
  return count <= k; 
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
    if(p(mid)) ub = mid;
    else lb = mid;
  }
  printf("%d\n",ub);

  return 0;
}
