#include <stdio.h>
#include <math.h>

double getFactorial(int a, double res)
{
    if (a > 1)
        return getFactorial(a - 1, res * a);
    return res;
}

int getByIteration(double x, double e, int n, double sum)
{
    for (; !(fabs(sin(x) - sum) < e); n++)
    {
        sum += pow(-1, n - 1) * pow(x, 2 * n - 1) / getFactorial(2 * n - 1, 1.);
    }

    printf("\n\nIteration: \nsin x = %lf \nexpression = %lf\n\n", sin(x), sum);
    return n;
}

int getByRecursion(double x, double e, int n, double sum)
{
    if (fabs(sin(x) - sum) < e)
    {
        printf("\nRecursion: \nsin x = %lf \nexpression = %lf\n\n", sin(x), sum);
        return n;
    }

    n++;
    sum += pow(-1, n - 1) * pow(x, 2 * n - 1) / getFactorial(2 * n - 1, 1.);
    return getByRecursion(x, e, n, sum);
}


int main()
{
    double x, e;
    printf("Enter x:\nx = ");
    scanf("%lf.20", &x);
    printf("Enter e:\ne = ");
    scanf("%lf", &e);
    printf("n = %d", getByRecursion(x, e, 1., x));
    printf("n = %d", getByIteration(x, e, 2., x) - 1);
    return 0;
}
