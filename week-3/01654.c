#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;
    if(num1 > num2) return 1;
    if(num1 < num2) return -1;
    return 0;
}

int binary_search(int arr[], int k, int n) {
    long long left=1, right = arr[k-1], mid, result;

    while(left <= right) {
        int cnt=0;
        mid = (left + right)/2;

        for(int i=0;i<k;i++) {
            cnt += arr[i]/mid;
        }
    
        if(cnt >= n) {
            result = mid;
            left = mid+1;
        }
        else right = mid-1;
    
    }
    
    return result;
}

int main() {
    int k, n;
    scanf("%d %d", &k, &n);
    int lan[k];
    for(int i=0;i<k;i++) scanf("%d", &lan[i]);
    qsort(lan, k, sizeof(int), compare);

    printf("%d", binary_search(lan,k, n));

    return 0;
}
