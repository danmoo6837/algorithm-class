#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    while(b != 0) {
        int temp =b;
        b=a%b;
        a=temp;
    }
    return a;
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        long long hap=0;
        scanf("%d", &n);
        int *arr = (int *)malloc(n*sizeof(int));
        for(int i =0;i<n;i++) scanf("%d", &arr[i]);

        for(int i=0;i<n-1;i++){
            for(int k=i+1;k<n;k++) {
                hap += gcd(arr[i], arr[k]);
            }
        }

        printf("%lld\n", hap);
        free(arr);
    }
    
    return 0;
}
