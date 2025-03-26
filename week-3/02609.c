//최대공약수와 최소공배수
//https://www.acmicpc.net/problem/2609
#include <stdio.h>

int gcd(int a, int b){
	if( b == 0) return a;
	else {
		return gcd(b, a%b);
	}
}

int main() {
	int a,b;
	scanf("%d %d", &a, &b);

	int gcd_num = gcd(a, b);

	printf("%d\n%d", gcd_num, a*b/gcd_num);
	return 0;
}
