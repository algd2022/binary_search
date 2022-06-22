#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int count = 0;
  for(int i=0;i < n;i++){
    count += A[i] / m;
  }
  return count < k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  lb = 0;
  ub = 1000000001;
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid))ub = mid;
    else lb = mid;
  }
  printf("%d\n",lb);
  return 0;

}
