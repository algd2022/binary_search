#include <stdio.h>

int n;
int k;
int A[100000];

int p(long long int m){
  int s=0;
  int i=0;
  for(i=0;i<n;i++){
    s += A[i]/m ;
  }
  return s >= k;
}

int main(){
  int i;
  long long int  lb, ub;/*ubの初期値を(1e14)+1としたため、long long intを使用*/
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

lb = 0;/*n=1,A[0]=1,槍を一本も作れない場合もある*/
ub = (1e14)+1; /*n=1e5,k=1,任意のiについてA[i]=1e9の時、p(1e14)=1であるが、p(1e14+1)=0である*/
      
    while(ub - lb > 1){
      long long int mid =(lb + ub)/2;
        if(p(mid)){
            lb = mid;
        }
        else{
          ub = mid;
        }
    }
      
      printf("%lld\n" , lb);
  return 0;
}
