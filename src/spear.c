#include <stdio.h>

int n;
int k;
int A[100000];

int isOk(int A[], int n, int k, int x){
  int spears = 0;//長さをxにするとき作れる槍の総数
  for(int i = 0; i < n; i++){
    int S = A[i] / x;//1本の木から作れる槍の数
    spears += S;
  }
  return spears >= k;//槍がk本以上作れるならOK
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1e9 + 1;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(isOk(A, n, k, mid)){
      lb = mid;
    }else{
      ub = mid;
    }
  }
  printf("%d\n", lb);
  return 0;
}
