#include <stdio.h>

int n;
int k;
int A[100000];

//槍の長さlのとき，作ることのできる槍の本数sumが，ほしい槍の本数kよりも大きいか否かを答える．
//足りているとき0,足りないとき1を返す．lの関数として単調非減少である．
int p(int l){
  int sum=0;
  for(int i=0; i<n; i++){
    sum += A[i]/l;
  }
  if(sum>=k){
    return 0;
  }else{
    return 1;
  }
}


//求めたいのはp(l)=0なる最大のl，すなわち(p(l)=1なる最小のl)-1である．
//よってarray.cやapple.cのように
//lb=(lの取りうる最小値)-1
//ub=(lの取りうる最大値)
//とおいて，ub-1=lbを返せばよい．
int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i=0; i<n; i++){
    scanf("%d", &A[i]);
  }
  
  lb = 0;
  ub = 1e9;
  while(ub-lb>1){
    int mid = (lb+ub)/2;
    if(p(mid)){
      ub = mid;
    }else{
      lb = mid;
    }
  }
  
  printf("%d\n",lb);
  return 0;
}
