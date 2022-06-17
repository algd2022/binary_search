#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int i;
  int koutai = 0;/*仕事する人数は"シフトの交代+1"で表せる*/
  int shigotoryo = 0;
  for(i=0; i<n; i++){
    if(A[i] > m){
        koutai = k+1;
        break;/*この操作によって、確実にA[i]>midを含むときのp(mid)をfalse(すなわち0)にできる。*/
      }
    if(A[i] + shigotoryo > m){
      koutai++;
      shigotoryo = A[i];
    }
    else{
      shigotoryo += A[i];
    }
  }
  return koutai+1 <= k;/*先述の理由から、に1を加える*/
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0; /*n=k=A[0]=1の時など、x=1を取り得る*/
  ub = 1e9;  /*n=1e5,任意のiについてA[i]=1e4,k=1の時、x=1e9で成立*/
      
    while(ub - lb > 1){
      int mid =(lb + ub)/2;
      if(p(mid)){
        ub = mid;
      }
      else{
        lb = mid;
      }    
    }
      
      printf("%d\n" , ub);

  return 0;
}
