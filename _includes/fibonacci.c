#include <stdio.h>
#include <string.h>

void mul_2x2_2x2 (int* lhs, int* rhs, int* prod)
{
    prod [0] = lhs [0] * rhs [0] + lhs [1] * rhs [2];
    prod [1] = lhs [0] * rhs [1] + lhs [1] * rhs [3];
    prod [2] = lhs [2] * rhs [0] + lhs [3] * rhs [2];
    prod [3] = lhs [2] * rhs [1] + lhs [3] * rhs [3];
}

void matrix_power (int* base, int n, int* result)
{
    int tmp [2][4];

    if (1 == n)
        memcpy (result, base, sizeof (int) * 4);
    else {
        matrix_power (base, n / 2, tmp [0]);

        if (n % 2) {
            mul_2x2_2x2 (tmp [0], tmp [0], tmp [1]);
            mul_2x2_2x2 (base, tmp [1], result);
        }
        else
            mul_2x2_2x2 (tmp [0], tmp [0], result);
    }
}

int fibonacci (int n)
{
    int unit [4] = {0, 1, 1, 1};
    int m [4];

    if (0 == n || 1 == n)
        return n;

    matrix_power (unit, n, m);

    return m [1];
}

int main (int argc, char* argv [])
{
    for (int n; EOF != scanf ("%d", &n); )
        printf ("fib(%d) = %d\n", n, fibonacci (n));

    return 0;
}
