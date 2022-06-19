#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x,int n,int k,int A[]){
  int i;
  int work=0,people=1;
  for(i=0;i<n;i++){
    if(A[i]>x) return 0;/*max(A)>xだと配分は不可能*/
    work+=A[i];
    if(work>x){
      people+=1;
      work=A[i];
    }
  }
  return people<=k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  /*
  lb:一番仕事量の多い人の仕事量がxでは配分できないこと(prople>k or max(A)>x)
  がわかっている最大の数
  ub:一番仕事量の多い人の仕事量がxで配分できること(people<=k)
  がわかっている最小の数
  */
  lb=0,ub=1000000000;
  while(ub-lb>1){
    int mid=(ub+lb)/2;
    if(p(mid,n,k,A)) ub=mid;
    else lb=mid;
  }
  printf("%d",ub);
  return 0;
}
