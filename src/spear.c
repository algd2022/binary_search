#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
    int n = 0||1;
    int i;
    int m;
    for (i = 0; i < m; i++){
        n = n + (A[i] + x - 1);
}

    return k<= x;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

    lb = 0;
    ub = A[i] + 1;
        while (ub -lb > 1) {
            int mid = (ub + lb) / 2;
            if (p(mid)){lb = mid;
                
            }
            else {ub = mid;
                
            }
            }

  return 0;
}
