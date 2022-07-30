#include <stdio.h>

int n;
int k;
int A[100000];

int canFinish(int x){
    int need_num = 1;
    int rest = x;
    for(int i=0; i<n; i++){
        if(A[i]>x) return 0;
        if(rest>=A[i]){
            rest-=A[i];
        }
        else{
            need_num++;
            rest = x-A[i];
        }
    }
    if(need_num<=k) return 1;
    else return 0;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

    lb = 0;
    ub = 1000000000;

    while(ub-lb>1){
        int mid = (lb+ub)/2;
        if(canFinish(mid)==1){
            ub = mid;
        }
        else{
            lb = mid;
        }
    }

    printf("%d\n", ub);

  return 0;
}
