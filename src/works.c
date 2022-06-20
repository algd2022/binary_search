#include <stdio.h>

int n;
int k;
int A[100000];

int possible(int x){
  int sum = 0, cnt = 0;
  for(int i = 0; i < n; i++){
    if(A[i] > x) return 0;
    if(sum + A[i] > x){
      ++cnt;
      sum = A[i];
    }else{
      sum += A[i];
    }
  }
  return cnt + 1 <= k;

}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = (int)1e9;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(possible(mid)){
      ub = mid;
    }else{
      lb = mid;
    }
  }
  printf("%d\n",ub);


  return 0;
}
