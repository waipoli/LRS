#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)

typedef long long ll;

struct Point {
    double x;
    double y;
};

double dist(struct Point A, struct Point B)
{
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}

ll area(struct Point A, struct Point B, struct Point C)
{
    return (B.x-A.x)*(B.y+A.y)+(C.x-B.x)*(C.y+B.y)+(A.x-C.x)*(A.y+C.y);
}


int diag(struct Point A, struct Point B, struct Point C, struct Point D)
{
    return (area(A, B, C) * area(A, B, D) <=0 && area(C, D, A) * area(C, D, B) <= 0) ;
}

int lines(struct Point A, struct Point B, struct Point C, struct Point D)
{
    return (area(A, B, C) == 0 && area(A, B, D) == 0);
}

double solve(struct Point A, struct Point B, struct Point C, struct Point D)
{
    if (lines(A, B, C, D))
    {
        double d1 = dist(A, B) + dist(A, C) + dist(A, D);
        double d2 = dist(B, A) + dist(B, C) + dist(B, D);
        double d3 = dist(C, A) + dist(C, B) + dist(C, D);
        double d4 = dist(D, A) + dist(D, B) + dist(D, C);
        return min(min(d1, d2), min(d3, d4));
    }
    if (diag(A, B, C, D))
    {
        return dist(A, B) + dist(C, D);
    }
    if (diag(A, C, B, D))
    {
        return dist(A, C) + dist(B, D);
    }
    if (diag(A, D, B, C))
    {
        return dist(A, D) + dist(B, C);
    }
    double d1 = dist(A, B) + dist(A, C) + dist(A, D);
    double d2 = dist(B, A) + dist(B, C) + dist(B, D);
    double d3 = dist(C, A) + dist(C, B) + dist(C, D);
    double d4 = dist(D, A) + dist(D, B) + dist(D, C);
    return min(min(d1, d2), min(d3, d4));
}

struct Point A, B, C, D;

int main()
{
    int tests;
    scanf("%d", &tests);
    for (int i = 0; i < tests; i++)
    {
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y, &D.x, &D.y);
        //printf("--> s(%lf, %lf, %lf, %lf, %lf, %lf) = %lld s(%lf, %lf, %lf, %lf, %lf, %lf) = %lld \n", A.x, A.y, B.x, B.y, C.x, C.y, area(A, B, C), A.x, A.y, B.x, B.y, D.x, D.y, area(A, B, D) );
        printf("%.7lf\n", solve(A, B, C, D));
    }

    return 0;
}
