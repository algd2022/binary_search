#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x) {
    int i;
    int sum = 0;
    for (i = 1; i < n + 1; i++) {
        sum += (A[i] + x - 1) / x;
    }
    if (sum <= k) return 1;
    else return 0;
}

int main() {
    int i, lb, ub;
    scanf("%d%d", &n, &k);
    for (i = 1; i < n + 1; i++) {
        scanf("%d", &A[i]);
    }
    lb = 0 ;          //‘Sˆõ‚ªƒŠƒ“ƒS‚ğ1ŒÂûŠn‚µ‚½ê‡‚ğl‚¦‚é‚Æ,p(1)==1‚Æ‚È‚é‰Â”\«‚ª‚ ‚é‚Æ•ª‚©‚é. 
    ub = 1000000000;    //n==k‚©‚Âa[i]=10^9‚Ìê‡‚ğl‚¦‚ê‚Î,p(999999999)==0‚Æ‚È‚é‰Â”\«‚ª‚ ‚é‚Æ•ª‚©‚é.
    while (ub - lb > 1) {
        int mid = (lb + ub) / 2;
        if (p(mid) ==1)  ub = mid;
        else lb = mid;
    }
    printf("%d\n", ub);
    return 0;


}
