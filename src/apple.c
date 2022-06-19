#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x,int n,int k,int A[]){
  int i,sum=0;
  /*
  sum:パックに入るリンゴの数がxのときに必要なパックの数
  */
  for(i=0;i<n;i++){
    sum+=(A[i]+x-1)/x;
  }
  return sum<=k;
}



int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  /*
  ub:全員がリンゴを持って帰れること(sum<=k)がわかっている最小のパックに入るリンゴの数
  lb:全員がリンゴを持って帰れないこと(sum>k)がわかっている最大のパックに入るリンゴの数
  */
  lb=0,ub=1000000000;
  while(ub-lb>1){
    int mid=(ub+lb)/2;
    if (p(mid,n,k,A)) ub=mid;
    else lb=mid;
  }
  printf("%d",ub);
  return 0;
}
