#include <stdio.h>

int n;
int k;
int A[100000];

int p(int A[], unsigned int x){
      int t = 0;
      int i = 0;
      for(i = 0; i < n; i++){
          t += (A[i] + x - 1)/x; /*Ø‚èã‚°‚ÌŒvZ‚ğ‚µ‚ÄŠei‚É‚Â‚¢‚Ä˜a‚ğ‚Æ‚é*/
      }
      return t <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
    }

    lb = 0;
    ub = 1e9; /*‚Ç‚¿‚ç‚àA“ü—Í§–ñ‚æ‚è*/
    
    while(ub -lb > 1){
        int mid = (ub + lb)/2;

        if (p(A, mid)) ub = mid;
        else lb = mid;
    }
    printf("%d\n", ub);

  return 0;
}



