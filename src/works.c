#include <stdio.h>

int n;
int k;
int A[100000];

int possible(int x){
  int prev = 0, cnt = 1;
  for(int i = 0; i < n; i++){
    if(A[i] > x) return 0;
    if(prev + A[i] > x){
      ++cnt;
      prev = A[i];
    }else{
      prev += A[i];
    }
  }
  return cnt <= k;

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
