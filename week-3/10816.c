#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int*) a - *(int*)b;
}

int lower_bound(int arr[], int n, int x) {
    int left=0, right = n;

    while(left <right) {
        int mid = (left+right)/2;
        
        if(arr[mid] < x) left = mid+1;
        else right = mid;
    }

    return left;
}

int upper_bound(int arr[], int n, int x) {
    int left=0, right = n;

    while(left <right) {
        int mid = (left+right)/2;
        
        if(arr[mid] <= x) left = mid+1;
        else right = mid;
    }

    return left;
}

int main() {
    int n;
    scanf("%d", &n);
    int card[n];
    for(int i=0;i<n;i++) scanf("%d", &card[i]);
    qsort(card, n, sizeof(int), compare);

    int m;
    scanf("%d", &m);
    int arr[m];
    for(int i=0;i<m;i++) scanf("%d", &arr[i]);

    for(int i=0;i<m;i++) {
        printf("%d ", upper_bound(card, n, arr[i]) - lower_bound(card, n, arr[i]));
    }
    return 0;
}
