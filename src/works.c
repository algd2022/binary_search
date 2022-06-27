#include <stdio.h>

int n;
int k;
int A[100000];


int p(int x) /*最も仕事をした人の仕事量がxであったとき、仕事(sumで表す)をした人の数(personで表す)がk人より少ないという条件が存在するか否かを判定する関数*/
{
  int person=1;
  int sum=0;
  
  for(int i=0;i<n;i++){
    if(A[i]>x){
      return 0;
    }
    else{
      sum+=A[i];
      if(sum>x){
        person+=1;
        sum=A[i];
      }
    }  
  }
  if(person<=k){
    return 1;
  }
  else{
    return 0;
  }
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb=0;
  ub=1e9;  /*一人がする最大の仕事量は10^9*/

  while(ub-lb>1){
    int mid=(lb+ub)/2;
    
    if(p(mid)){
      ub=mid;
    }
    else{
      lb=mid;
    }
  }

  printf("%d\n",ub);
  return 0;
}
