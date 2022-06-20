#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
  int sum = 0;//sumはx個のりんごを入れることができるバッグの必要な数
  for(int i=0; i<n; i++){
    sum += (A[i]+x-1)/x;
  }
  return sum <= k;
}



int main(){
  int i, lb, ub;

  scanf("%d%d", &n, &k);
  for(i=0; i<n; i++){
    scanf("%d", &A[i]);
  }

  //A[i]=1 (for all i) のときバッグには1つ入ればよく，
  //これがxが取りうる最小値である．したがってlb=min(x)-1=0．
  //xが最大となるのは，各人が最大個数収穫して，
  //かつバッグが一人一個しか配られなかった場合(k=n)である．
  //よってub=max(a_i)=1e9

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
  printf("%d\n",ub);
  return 0;
}
