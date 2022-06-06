#include <stdio.h>
#define MODULUS 10007
int getSecret(int n);
int gcd(int a, int b);

int main(){
	int n;
	scanf("%d", &n);
	printf("%d", getSecret(n));
	return 0;
}

int getSecret(int n)
{
    int digit = 0, process, tmp, base = 1, left_part, right_part;
    int a[10];
    int sum;
    process = n;
    digit = 0;
    while (process > 0) {
        process /= 10;
        digit += 1;
    }
    if (digit == 1)
        return n;
    else {
        if (digit % 2 == 0){
            for (int i = 0; i < (digit / 2); i++)
                base *= 10;
            left_part = n / base ;
            right_part = n % base;
        }
        else {
            for (int i = 0; i <= ( digit / 2 ); i++)
                base *= 10;
            left_part = n / base;
            right_part = n % base;
        }
        if (left_part > right_part) {
            sum = (n % 10007) + (getSecret(gcd(left_part, right_part)) % 10007);
            return sum ;
        }
        else{
            sum = (n % 10007) + (getSecret(gcd(left_part, right_part)) % 10007);
            return sum;
        }

    }

}

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    else if (b == 0)
        return a;
    else if (a == b)
        return a;
    else {
        int tmp;
        while (b > 0){
            tmp = a % b;
            a = b;
            b = tmp;
        }
        return a;
    }

}