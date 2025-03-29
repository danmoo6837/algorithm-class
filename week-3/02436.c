#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int g, l;
    scanf("%d %d", &g, &l);

    long long m = l / g;  
    int a = g, b = l; 
    int min_sum = a + b;

    for (int i = 1; i * i <= m; i++) {
        if (m % i == 0) {
            int x = i, y = m / i;

            if (gcd(x, y) == 1) { 
                int new_a = g * x, new_b = g * y;

                if (new_a + new_b < min_sum) {
                    a = new_a;
                    b = new_b;
                    min_sum = new_a + new_b;
                }
            }
        }
    }

    printf("%d %d\n", a, b);
    return 0;
}
