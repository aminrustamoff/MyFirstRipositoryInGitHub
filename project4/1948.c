#include <stdio.h>

int is_prime(int num) {
    if (num <= 1) return 0;
    if (num <= 3) return 1;
    if ((num % 2 == 0) || (num % 3 == 0)) return 0; 
    for (int i = 5; i * i <= num; i += 6) {
        if ((num % i == 0) || (num % (i + 2) == 0)) return 0;
    }
    return 1;

int largest_prime_divisor(int num) {
    int divisor = num;
   
    for (int i = 2; i * i <= num; i++) {
        if (is_prime(i) && (num % i == 0)) {
            divisor = i;
        }
    }
    return divisor;
}

int main() {
    int a;
    if (scanf("%d", &a) != 1) {
        printf("n/a\n");
        return 1;
    }
    if (a <= 1) {
        printf("n/a\n");
        return 1;
    }
    int largest_divisor = largest_prime_divisor(a);
    if (largest_divisor == a) {
        printf("%d\n", a);
    } else {
        printf("%d %d\n", a, largest_divisor);
    }
    return main();
}
