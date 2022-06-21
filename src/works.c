#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){//1人がする仕事量の最大値をx以下にできるか
  int works = 0;
  int workers = 1;
  for(int i = 0; i < n; i++){
    if(A[i] > x) return 0;//そもそも仕事量xを超える仕事があるのならNG
    works += A[i];
    if(works > x){
      workers += 1;
      works = A[i];
    }
  }
  return workers <= k;//必要な人数がk人以下ならOK
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1e9;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)){
      ub = mid;
    }else{
      lb = mid;
    }
  }
  printf("%d\n", ub);
  return 0;
}
