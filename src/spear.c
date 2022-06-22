#include <stdio.h>

int n;
int k;
int A[100000];

int p(int A[], unsigned int x){
    int t = 0;
    int i = 0;
    for (i = 0; i < n; i++){
        t += A[i] / x;  /*Ø‚èÌ‚Ä‚ÌŒvZ‚ğ‚µ‚Ä˜a‚ğ‚Æ‚é*/
    }
    return t < k;

}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 1e9 + 1;  /*1e9‚Ì’·‚³‚Ì‘„‚Íì‚ê‚é‚Ì‚ÅAì‚ê‚È‚¢‚à‚Ì‚Ì‚¤‚¿Å¬‚Ì’·‚³*/

  while(ub - lb > 1){
        int mid = (ub + lb)/2;

        if(p(A, mid)) ub = mid;
        else lb = mid;
  }
  printf("%d\n", lb);

  return 0;
}

