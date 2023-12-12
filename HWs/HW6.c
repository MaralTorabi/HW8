#include <stdio.h>
#include <math.h>
double* solver (double a, double b, double c , int *p)
{
    double x[2]; 
    double* q=x;
    if ((b*b - 4*a*c) >= 0)
    {
        x[0]=(double)((-b + sqrt(b*b - 4*a*c))/(2*a));
        x[1]=(double)((-b - sqrt(b*b - 4*a*c))/(2*a));
        if (x[0] != x[1])
        {  
            *p=2;
            return q;
        }
        else
        {
            *p=1;
            return q;
        }
    }
    else 
        return 0;    
}
int main()
{
    double a, b, c; 
    int t;
    int *p=&t; 
    printf("Please enter 3 numbers: ");
    scanf("%lf%lf%lf", &a, &b, &c);
    if (a==0 && b==0)
    {
        printf("Error, wrong entry.");
        return 0;
    }  
    if (solver(a,b,c,p)==0)
        printf("This equation has no real roots.");
    else 
    {
        if (t==2)
        {
            printf("The number of roots: %d", t);
            printf("\nx1= %lf , x2=%lf", *solver(a,b,c,p), *(solver(a,b,c,p)+1));
        }
        else if (t==1)
        {
            printf("The number of roots: %d", t); 
            printf("\nx= %lf", *(solver(a,b,c,p)+1));
        }
    }
    return 0;
}