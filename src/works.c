#include <stdio.h>

int n;
int k;
int A[100000];
int p (int m){// means if they want to create m cm's spear, how many (spear) spear can they create.
  int singleworktime = 0,people=1;
  for (int i=0;i<n;i++){
    if (m-singleworktime>=A[i]){
      singleworktime+=A[i];
    }
    else if (m>=A[i]){
      singleworktime=A[i];
      people++;
    }
    else{
      return 0;
    }
    
    }
    return (people<=k);
}

  
 



int main(){
  int i, lb=0, ub=10000;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  while (ub-lb>1){
      int mid = (ub+lb)/2;
      if (p(mid)){
        ub = mid;
      }else{
        lb = mid;
      }
    }
    printf("%d\n", ub);

  return 0;
}


