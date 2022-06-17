#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int s=0;
  int i=0;
  for(i=0;i<n;i++){
    s += A[i]/m ;
  }
  return s >= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

lb = 0;/*n=1,k=2,A[0]=1など,槍を1m以上作れない場合もある*/
ub = (1e9)+1; /*k=1,任意のiについてA[i]=1e9の時、p(1e9)=1であるが、p(1e9+1)=0である*/
      
    while(ub - lb > 1){
      int mid =(lb + ub)/2;
        if(p(mid)){
            lb = mid;
        }
        else{
            ub = mid;
        }
    }
      
      printf("%d\n" , lb);
  return 0;
}
