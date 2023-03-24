#include <stdio.h>
#include <math.h>

int isPrime(int n) {
    if (n < 2) {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int isPalindrome(int n) {
    int rev = 0, temp = n;
    while (temp != 0) {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }
    return n == rev;
}

int main() {
    int p, q, count = 0;

    FILE *fin = fopen("NUMBER.INP", "r");
    fscanf(fin, "%d %d", &p, &q);
    fclose(fin);

    for (int i = p; i <= q; i++) {
        if (isPrime(i) && isPalindrome(i)) {
            count++;
        }
    }

    FILE *fout = fopen("NUMBER.OUT", "w");
    fprintf(fout, "%d", count);
    fclose(fout);

    return 0;
}
