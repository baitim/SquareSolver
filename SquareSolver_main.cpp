#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include <math.h>
#define eps 1e-6

void input_coefficients(double* a, double* b, double* c);

int sol(double a, double b, double c, double* D);

bool is_double_equal(double x, double y);

int main (void) {
    double a = 0, b = 0, c = 0;
    printf ("Enter the coefficients for the quadratic equation a*x^2 + b*x + c = 0 separated by a space\n");

    input_coefficients(&a, &b, &c);

    double D;
    int roots = sol(a, b, c, &D);
    if (roots >= 0 and roots <= 2)
        printf ("Total roots: %d\n", roots);
    double x, x1, x2;
    double Dsqrt = sqrt(D);

    switch (roots) {
        case 0: // 0 ������, ��������� ���������� ��� a = 0, b = 0, c != 0
            break;
        case 1: // 1 ������, ��������� ����������
            x = (-b+Dsqrt)/2/a;
            printf ("x = %lf\n", x);
            break;
        case 2: // 2 �����, ��������� ����������
            x1 = (-b-Dsqrt)/2/a;
            x2 = (-b+Dsqrt)/2/a;
            printf ("x1 = %lf  x2 = %lf\n", x1, x2);
            break;
        case 3: // 1 ������, ��������� ��������
            printf ("The equation is not square, the root = %lf\n", -c/b);
        case 4: // ����������� ����� ������
            printf ("The equation is not square, infinitely many roots");
    }
    return 0;
}

void input_coefficients(double* a, double* b, double* c) {
    while (true) {
        int count_input = scanf ("%lf%lf%lf", a, b, c);
        if (count_input != 3 or count_input == EOF) {
            printf ("incorrect input, input: 0 - to exit, another integer - to continue\n");
            while (getchar() != '\n');
            int x;
            scanf ("%d", &x);
            if (x == 0) exit(0);
        }
        else
            break;
    }
}

int sol(double a, double b, double c, double* D) {
    if (is_double_equal(a, 0)) {
        if (b != 0) return 3;
        if (b == 0) {
            if (c == 0) return 4;
            if (c != 0) return 0;
        }
    }
    *D = b*b - 4*a*c;
    if (*D < 0) return 0;
    if (is_double_equal(*D, 0)) return 1;
    if (*D > 0) return 2;
}

bool is_double_equal(double x, double y) {
    if (abs(x-y) <= eps) return true;
    else return false;
}
