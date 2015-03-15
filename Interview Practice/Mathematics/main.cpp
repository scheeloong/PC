//
//----------------------------------------------------------------------------------------
/*  //
Table of Contents

1. Calculate pow(double, int n), where n can be (-), 0 , (+)  T(n) = O(logN), S(n) = O(logN)

//----------------------------------------------------------------------------------------
TODO:
0. Calculate pow(double, int n), where n can be (-), 0 , (+)  T(n) = O(logN), S(n) = O(1) Hint: Dynamic Programming

1. Create rand()
2. Create 16by 9 => 16by10 or 16 by 8 cannot, 17by9 or 15by 9 cannot, returns true if 16b9 and false otherwise

3. Generate prime numbers up to N efficiently: Sieve of Eratosthenes
4. Look up sorting integers in O(logN) time on some Youtube MIT video on advanced data structures


// */
//----------------------------------------------------------------------------------------
/* //
// 1. Implement pow(double, int)
// Time Complexity: O(logN)
// Space Complexity: O(1)
// Calculate pow(double, int n), where n can be (-), 0 , (+)  T(n) = O(logN), S(n) = O(logN)
#include <math.h>
#include <iostream>
using namespace std;

double power(double a, int n);

int main(void)
{
    int k = 3;
    double m = 4.0;
    double result = power(m, k);
    cout << result << endl;
    k = -3;
    m = 2.0;
    result = power(m, k);
    cout << result << endl;
}

double power(double a, int n)
{
    if ((n == 0) || (a == 1))
        return 1;
    if (n > 0)
    {
        double b = power(a, floor(n/2));
        if (n%2 == 0)
        {
            return b*b;
        }
        else
        {
            return b*b*a;
        }
    }
    else
    {
        double b = power(a, -floor(n/2));
        if (n%2 == 0)
        {
            return 1.0/(b*b);
        }
        else
        {
            return 1.0/(b*b*a);
        }
    }
}
// */
//----------------------------------------------------------------------------------------
