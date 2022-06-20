#include <stdio.h>

int n;
int k;
int A[100000];

int p(unsigned int x){
  int i;
  long long int sum;
  sum = 0;
  for(i = 0; i < n; i++){
    sum += A[i] / x;
  }
  return sum >= k;
}


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 1000000001;
  ub = 0;
  while(lb - ub > 1) {
    int mid = (lb + ub) / 2;
    if(p(mid)) ub = mid;
    else lb = mid;
  }

  printf("%d\n", ub);


  return 0;
}
