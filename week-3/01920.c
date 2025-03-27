#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
	int num1 = *(int *)a;
	int num2 = *(int*)b;
	if(num1>num2) return 1;
	if(num1 <num2) return -1;
	return 0;
}

int binary_search(int arr[], int len, int x) {
	int left=0, right = len-1;
	while(left<=right) {
		int mid = left+(right-left) /2;
		if(arr[mid] == x) return 1;
		else if(arr[mid] < x) left = mid + 1;
		else right = mid - 1;
	}
	return 0;
}

int main() {
	int n, m;
	scanf("%d", &n);
	int arr[n];
	for(int i=0;i<n;i++) scanf("%d", &arr[i]);

	scanf("%d", &m);
	int su[m];
	for(int i=0;i<m;i++) scanf("%d", &su[i]);

	qsort(arr, n, sizeof(int), compare);

	for(int i=0;i<m;i++){
		printf("%d\n", binary_search(arr, n, su[i]));
	}
	return 0;
}
