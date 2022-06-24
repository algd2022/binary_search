#include <stdio.h>

int n;
int k;
int A[100000];

//各人がx時間までの時間で働いたときに
//k人以内で収まるなら1を、収まらないなら0を返す
int p(int x){
  int cnt = 0;
  int s = 0;

  for(int i = 0; i < n; i++){
    if(A[i] > x) return 0;
    if(s + A[i] > x){
      cnt++;
      s = A[i];
    }
    else{
      s += A[i];
    }
  }

  if(cnt+1 <= k) return 1;
  else return 0;
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
    int mid = lb + (ub - lb)/2;
    if(p(mid)) ub = mid;
    else lb = mid;
  }

  printf("%d\n", ub);
  return 0;
}
