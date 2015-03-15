Table of Contents

1. Fibonacci Sequence (Bottom Up)

2. Rod Cutting Problem (Top Down with Memoization)

3. Rod Cutting Problem (Bottom Up)

4. Longest Common Subsequence Between Two Strings (Bottom Up)

/*
5. TODO: Maximum Subarray() (using dynamic instead of kadane's algorithm

6. TODO: Longest Common Substring Between Two Strings (Bottom Up)

7. TODO: Josephus Problem
*/

//----------------------------------------------------------------------------------------------------
/* //
// 1 Fibonacci Sequence (Bottom Up)
// Time Complexity: O(n)
// Space Complexity, S(n) = O(n)

#include <iostream>
#include <stdlib.h>

using namespace std;

int fibonacci(int n, int* p);
int main(void)
{
    int i = 0;
    int n = 10;
    int *p;
    p = (int *) malloc(sizeof(int) * (n+1));
    for (i = 0; i < n; i++)
    {
        p[i] = -1; // initialize with negative numbers
    }
    for(i = 0; i < n; i++)
    {
        int j = fibonacci(i, p);
        cout << "Fibonacci for " << i << " is: " << j << endl;
    }
}

int fibonacci(int n, int* p)
{
    p[0] = 1;
    p[1] = 1;
    if (n <= 1)
    {
        return 1;
    }
    int i = 0;
    for(i = 2; i <= n; i++)
    {
        p[i] = p[i-1] + p[i-2];
    }
    return p[n] ;
}
// */

//----------------------------------------------------------------------------------------------------
/* //
// 2 Rod Cutting Problem ( Dynamic Programming)
// Top-Down with memoization
// Given a rod of length n, and a price for rod of length 1, 2, ... n.
// Determine how to cut the rod to maximize total price.
// Note: There are 2^n - 1 combinations of possible answers since
//       For every i > 1, you can decide if you wanna cut, or not cut.
//  Which means trying everything out will be an exponential time
// Method 1: Top-Down with memoization
// Time Complexity: O(n^2) , using dynamic programming
// Space Complexity: O(n)
// Note: Use dynamic programming and print the final solution, not just the optimal value
// TODO: Have not printed the final solution
#include <iostream>
#include <stdlib.h>
#include <limits.h>

using namespace std;
int cut_rod(int *p , int n, int *s, int *r);
int main(void)
{
    int *p; // prices
    int *s; // list of cuts for printing
    int *r; // current list from solution
    int n = 10;
    p = (int *) malloc(sizeof(int) * (n+1));
    s = (int *) malloc(sizeof(int) * (n+1));
    r = (int *) malloc(sizeof(int) * (n+1));
    p[0] = 0;
    p[1] = 1;
    p[2] = 5;
    p[3] = 8;
    p[4] = 9;
    p[5] = 10;
    p[6] = 17;
    p[7] = 17;
    p[8] = 20;
    p[9] = 24;
    p[10]= 30;
    int  i = 0;
    for ( i = 0; i <= n; i++)
    {
        r[i] = -1;
    }
    for (i =0 ; i <= n; i++)
    {
        int k = cut_rod(p, i, s, r);
        cout << "Optimal value for " << i << " is " << k << endl;
    }

    return 0;
}

int cut_rod(int *p , int n, int *s, int *r)
{
    if (n == 0)
    {
        r[0] = 0;// COMMENT THIS OUT FOR PURELY RECURSIVE WITHOUT MEMOIZATION
        p[0] = 0;
        return 0;
    }
    if (r[n] >= 0) return r[n];// COMMENT THIS OUT FOR PURELY RECURSIVE WITHOUT MEMOIZATION
    int i = 0;
    int q = INT_MIN;
    for (i = 1; i <= n; i++)
    {
                // max(whatever stored before, p[i] + r[n-i]
                // You can use p[i] cause you know that you are accounting for all cases of
                // the piece of each length from 1 all the way up to n.
                // this means you would have accounted for all cases.
        // Refer to pg 362/1292 of actual textbook from CLRS 3rd ed, it doesn't provide the proof
        // but it says you can prove it.
        q = max(q, p[i] + cut_rod(p, n-i, s, r));
    //    q = max(q, cut_rod(p, i, s, r) + cut_rod(p, n-i, s, r)); // NOTE: This is wrong and causes segfault.
    //    cout << "q is " << q << endl;
    }
    r[n] = q;  // COMMENT THIS OUT FOR PURELY RECURSIVE WITHOUT MEMOIZATION
    return q;
}
// */
//----------------------------------------------------------------------------------------------------
/* //
// 3 Rod Cutting Problem ( Dynamic Programming)
// Bottom Up Approach
// Given a rod of length n, and a price for rod of length 1, 2, ... n.
// Determine how to cut the rod to maximize total price.
// Note: There are 2^n - 1 combinations of possible answers since
//       For every i > 1, you can decide if you wanna cut, or not cut.
//  Which means trying everything out will be an exponential time
// Method 2: Bottom Up Approach
// Time Complexity: O(n^2) , using dynamic programming
// Space Complexity: O(n)
// Note: Use dynamic programming and print the final solution, not just the optimal value
#include <iostream>
#include <stdlib.h>
#include <limits.h>

using namespace std;
int cut_rod(int *p , int n, int *s, int *r);
int main(void)
{
    int *p; // prices
    int *s; // list of cuts for printing
    int *r; // current list from solution
    int n = 10;
    p = (int *) malloc(sizeof(int) * (n+1));
    s = (int *) malloc(sizeof(int) * (n+1));
    r = (int *) malloc(sizeof(int) * (n+1));
    p[0] = 0;
    p[1] = 1;
    p[2] = 5;
    p[3] = 8;
    p[4] = 9;
    p[5] = 10;
    p[6] = 17;
    p[7] = 17;
    p[8] = 20;
    p[9] = 24;
    p[10]= 30;
    int  i = 0;
    for ( i = 0; i <= n; i++)
    {
        r[i] = -1;
    }
    for (i =0 ; i <= n; i++)
    {
        int k = cut_rod(p, i, s, r);
        cout << "Optimal value for " << i << " is " << k << endl;
    }

    return 0;
}

int cut_rod(int *p , int n, int *s, int *r)
{
    r[0] = 0;
    p[0] = 0;
    if (n == 0)
    {
        return 0;
    }
    int i = 0;
    int j = 0;
    for (i = 1; i <= n; i++)
    {
        int q = INT_MIN;
        for (j = 1; j <= i; j++)
        {
            // max(whatever stored before, p[i] + r[n-i]
            // You can use p[i] cause you know that you are accounting for all cases of
            // the piece of each length from 1 all the way up to n.
            // this means you would have accounted for all cases.
            // Refer to pg 362/1292 of actual textbook from CLRS 3rd ed, it doesn't provide the proof
            // but it says you can prove it.
            int oldq = q;
            q = max(q, p[j] + r[i-j]); // note: NO recursion
            if (oldq != q)
            {
                s[i] = j;
            }
        }
        r[i] = q;

    //    q = max(q, cut_rod(p, i, s, r) + cut_rod(p, n-i, s, r)); // NOTE: This is wrong and causes segfault.
    //    cout << "q is " << q << endl;
    }
    int l = n;
    cout <<"Arrangement for " << n << " is: " <<endl;
    while ( l > 0)
    {
        cout << "r[" << s[l] << "] ";
        l = l - s[l];
    }
    cout << endl;
    return r[n];
}
// */
//-----------------------------------------------------------------------------------------------
/*
// 4 Longest Common Subsequence Between Two Strings
// Approach 1: Dynamic Programming (Bottom Up)
// Time Complexity, T(n,m) = O(nm)
// Space Complexity, S(n,m) = O(nm)

#include <cstdlib>
#include <iostream>
using namespace std;

void printLCS(int** C, char** direction, int* x,  int i , int j);

int main(void)
{
    int N, M;
    cin >> N >> M;
    int x[N];
    int y[M];
    // Create a 2D array to store values
    int** C;
    char** direction; // for backtracing which path was taken later
        // '0' => backtrack [i-1][j]
        // '1' => backtrack [i][j-1]
        // '2' => backtrack [i-1][j-1]
    C = (int **) malloc(sizeof(int *) * (N+1));
    direction = (char **) malloc(sizeof(char *) * (N+1));

    for (int i = 0; i <= N; i++)
    {
        C[i] = (int *) malloc(sizeof(int) * (M+1));
        direction[i] = (char *) malloc(sizeof(char) * (M+1));
    }

    for(int i = 0; i <= N; i++)
    {
        if(i != N)
        {
            cin >> x[i];
        }
        C[i][0] = 0;
        direction[i][0] = '0';
    }

    for(int i = 0; i <= M; i++)
    {
        if(i != M)
        {
            cin >> y[i];
        }
        C[0][i] = 0;
    }

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            if(x[i-1] == y[j-1])
            {
                C[i][j] = C[i-1][j-1] + 1;// add one to number of common subsequence in this path
                direction[i][j] = '2';
            }
            else
            {
                if(C[i-1][j] >= C[i][j-1])
                {
                    C[i][j] = C[i-1][j];
                    direction[i][j] = '0';
                }
                else
                {
                    C[i][j] = C[i][j-1];
                    direction[i][j] = '1';
                }
            }
        }
    }

    printLCS(C, direction, x, N, M);
    cout << endl;
    // Done finding longest subsequence
    // now print out solution recursively
}

void printLCS(int** C, char** direction, int* x,  int i , int j)
{
    if(i == 0 || j == 0)
    {
        return;
    }
    if (direction[i][j] == '2')
    {
        printLCS(C, direction, x, i-1, j-1);
        cout << x[i-1] << " ";
    }
    else if(direction[i][j] == '0')
    {
        printLCS(C, direction, x, i-1, j);
    }
    else
    {
        printLCS(C, direction, x, i, j-1);
    }
    return;
}
// */
//-----------------------------------------------------------------------------------------------
