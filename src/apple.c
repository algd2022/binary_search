#include <stdio.h>

int n;
int k;
int A[100000];

int isOk(int A[], int n, int k, int x){
  int bags = 0;//容量がx個のとき,必要なバッグの総数
  for(int i = 0; i < n; i++){
    int B = (A[i] - 1) / x + 1;
    bags += B;
  }
  return bags <= k;//バッグがk個以下ならOK
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1e9+1;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(isOk(A, n, k, mid)){
      ub = mid;
    }else{
      lb = mid;
    }
  }
  printf("%d\n", ub);

  return 0;
}
