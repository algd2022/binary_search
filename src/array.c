#include <stdio.h>

int n;
int k;
int A[100000];


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = -1; //lbはA[lb] < x がわかっている最大の整数
  ub = n; //ubはA[ub] >=x がわかっている最小の整数
  while(ub - lb > 1){ 
    int mid = (lb + ub) / 2;
    if(A[mid] >= k) ub = mid; //真ん中の値をkと比較して、lbまたはubをmidまで寄せる
    else lb = mid;
  }
  printf("%d\n",ub);
  return 0;
}
