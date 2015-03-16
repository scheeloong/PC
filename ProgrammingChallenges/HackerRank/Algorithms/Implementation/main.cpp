//----------------------------------------------------------------------
// Table of Contents
/* //
1. Service Lane
2. Cut The Sticks
3. Sherlock And Array
4. Sherlock and Queries
    // Redo this, this is pretty brilliant
5. Cavity Map

TODO: 6 AntiPalindromic Strings
    // SUPER HARD

// Time Complexity, T(n) = O(n)
// Space Complexity, S(n) = O(n)

// TODO: Re-order later with decreasing difficulty so can learn hard ones first during revision.
// TODO: Add the simplification of problems to Interview Practice folder.
// TODO: Add the time and space complexity to all below as well as the reduction problems to what you're actually solving.
// */
//----------------------------------------------------------------------
// TODO: 6 AntiPalindromic Strings
// Time Complexity, T(n,m) = O(max(n,m))
// Space Complexity, S(n,m) = O(1)

// PROBLEM!!!!
// Your algorithm doesnt work cause it's not as simple as you think
// N = 4, M = 2 =>
// ABAB is 1, BABA is 1
// if M = 3, and N = 6
// ABCABC is 1, ABCABA is 1

// note: no factorial() function in <cmath>
#include <iostream>
using namespace std;

unsigned long long int factorial(unsigned int N)
{
    if (N == 0) return 1;
    unsigned long long int result = 1;
    for(auto i = N; i > 0; i--)
    {
        result *= i;
    }
    return result;
}

int main(void)
{
    unsigned long long int T, N, M, answer;
    cin >> T;
    for(unsigned int i = 0; i < T; i++)
    {
        cin >> N >> M;
        if (N <= M)
            answer = factorial(M)/ (factorial(M-N));
        else
            answer = 0; // cannot construct any string less than size given
        cout << answer%1000000007 << endl;
    }
}
// */
//----------------------------------------------------------------------
/*
// 1 Service Lane

#include <cstdio>
#include <iostream>
using namespace std;

int main(void)
{
    unsigned int N;
    unsigned int T;
    int i = 0;
    cin >> N >> T;
    int width[N];
    int iteration[N];
    int curr = 0; // initialize current to 0 ;
    cin >> width[0];
    curr = width[0];
    iteration[0] = 0; // index of how long current lasts

    for(i = 1; i < N; i++)
    {
        cin >> width[i];
        if (width[i] == curr)
        {
            // Get when this value lasts until
            iteration[i] = iteration[i-1];
        }
        else
        {
            curr = width[i];
            iteration[i] = i; // start a new iteration
        }
    }
    // Here, done reading problem, now iterate through all test cases
    // and output

    int lb, ub;
    int j = ub;
    for (i = 0; i < T; i++)
    {
        cin >> lb >> ub;
        int minValue = 3; // initialize current minimum to be 3
        for( j = ub; j >= lb; j--)
        {
            if (width[j] == 1)
            {
                minValue = width[j];
                break; // get out of for loop
            }
            else
            {
                if(minValue > width[j])
                {
                    minValue = width[j]; // updae min value
                }
                // jump to closest continuation of iteration
                j = iteration[j]; // update j to same value and j-- above will handle putting it at proper spot
            }
        }
        cout  << minValue << endl;
    }
    return 0;
}
// */
//----------------------------------------------------------------------
/* //
// 2 Cut The Sticks
// Time Complexity, T(n) = O(nlgn) // sort()
// Space Complexity, S(n) = O(n)
#include <algorithm>
#include <iostream>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    int a[N];
    for(int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    sort(&a[0], &a[0] + N);
    int currDeduct = 0;
    for(int i = 0; i < N; i++)
    {
        if(a[i] > currDeduct)
        {
            cout << N-i << endl;
            currDeduct = a[i];
        }
    }
}
// */
//----------------------------------------------------------------------
/*
// 3 Sherlock And Array
// Time Complexity, T(n) = O(n)
// Space Complexity, S(n) = O(n)
#include <iostream>
using namespace std;

int main(void)
{
    unsigned int T, N;
    cin >> T;
    for(unsigned int i = 0; i < T; i++)
    {
        cin >> N;
        unsigned long long int LeftSum[N], RightSum[N], a[N];
        for(unsigned int j = 0; j < N; j++)
        {
            LeftSum[j] = 0;
            RightSum[j] = 0;
        }
        cin >> a[0];
        LeftSum[0] = a[0];
        for(unsigned int j = 1; j < N; j++)
        {
            cin >> a[j];
            LeftSum[j] += a[j] + LeftSum[j-1];
        }
        RightSum[N-1] = a[N-1];
        // corner case
        if (N == 1)
        {
            cout << "YES" << endl;
            continue;
        }
         // only works with N > 1, cause N=1 => j = 1-2 => very larg value
        for(unsigned int j = N-2; j > 0; j--)
        {
            RightSum[j] += a[j] + RightSum[j+1];
        }

        RightSum[0] += a[0] + RightSum[1]; // only works with N > 1
        bool found = false;
        for(unsigned int j = 1; j < N-1; j++)
        {
            if(LeftSum[j-1] == RightSum[j+1])
            {
                cout << "YES" << endl;
                found = true;
                break;
            }
        }
        if (!found) cout << "NO" << endl;
    }
}
// */
//----------------------------------------------------------------------
/*
// 4 Sherlock And Queries

#include <iostream>
#include <map>

#define ll long long
#define miterator map<int, int>::iterator

#define MOD 1000000007
#define MAXN 100000
#define MAXM 100000

using namespace std;

int A[MAXN], B[MAXM], C[MAXM];

map<int, int> factor;

inline int modMult(int a, int b) {
  return (a * (ll) b) % MOD;
}

int main() {
  int n, m; cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> A[i];
  for(int i = 0; i < m; i++) cin >> B[i];
  for(int i = 0; i < m; i++) cin >> C[i];

  for(int i = 0; i < m; i++) {
    int old = factor.count(B[i]) ? factor[B[i]] : 1;
    factor[B[i]] = modMult(old, C[i]);
  }

  for(miterator it = factor.begin(); it != factor.end(); it++) {
    int step = it->first;
    for(int i = step - 1; i < n; i += step) {
      A[i] = modMult(A[i], it->second);
    }
  }

  cout << A[0];
  for(int i = 1; i < n; i++) {
    cout << " " << A[i];
  }
  cout << endl;

  return 0;
}
// */
//----------------------------------------------------------------------
/* //
// 5 Cavity Map
// Time Complexity, T(n) = O(n^2)
// Space Complexity, S(n) = O(n^2)
#include <cstdio>
#include <iostream>
using namespace std;

// Only need test left right up and down with strictly lower value

int main(void)
{
    int N;
    cin >> N;
    int a[N][N];
    int b[N][N];

    // Switch to next row
    for(int i = 0; i < N; i++)
    {
        // Row entries for row I
        for (int j = 0; j < N; j++)
        {
           scanf("%1d", &a[i][j]);
           b[i][j] = 0;
        }
    }

    if(N > 2)
    {
         // Handle everything in the center
        for(int i = 1; i < N-1; i++)
        {
            for(int j = 1; j < N-1; j++)
            {

                if(a[i-1][j] < a[i][j] && a[i][j-1] < a[i][j] && a[i][j+1] < a[i][j] && a[i+1][j] < a[i][j])
                {
                    b[i][j] = -1;
                }
            }
        }
    }

    // Output results
    for(int i = 0; i < N; i++)
    {
        // Row entries for row I
        for (int j = 0; j < N; j++)
        {
           if(b[i][j] == -1)
           {
               cout <<'X';
           }
           else
           {
               cout << a[i][j];
           }
        }
        cout << endl;
    }
}
// */
//----------------------------------------------------------------------
// FIXME
//----------------------------------------------------------------------
/*
// FIXME: Your implementation is too slow!!!!!
// 4 Sherlock And Queries
// Time Complexity, T(n,m) = O(max(n,m))
// Space Complexity, S(n,m) = O(n+m)

#include <iostream>
using namespace std;
int main(void)
{
    unsigned long long int N, M;
    cin >> N >> M;
    unsigned long long int A[N], B[M], C[M];
    for(unsigned long long int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for(unsigned long long int i = 0; i < M; i++)
    {
        cin >> B[i];
    }
    for(unsigned long long int i = 0; i < M; i++)
    {
        cin >> C[i];
    }
    for (unsigned long long int i = 0; i < M; i++)
    {
        unsigned long long int temp = B[i];
        unsigned long long int temp2 = C[i];

        for(unsigned long long int j = temp - 1 ; j < N; j += temp)
        {
            A[j] *=  temp2;
            if (A[j] >= 1000000007)
                A[j] = A[j] % 1000000007;
        }
    }
    for(unsigned long long int i = 0; i < N; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}
// */
//----------------------------------------------------------------------
// Cavity Map Wrong Implementation
    // No handling of borders!
    /*
    // Handle upper left case
    if (a[1][0] <= a[0][0] && a[0][1] <= a[0][0] && a[1][1] <= a[0][0])
    {
        b[0][0] = -1;
    }
    // Handle upper right case
    if(a[0][N-2]<= a[0][N-1] && a[1][N-2] <= a[0][N-1] && a[1][N-1] <= a[0][N-1])
    {
        b[0][N-1] = -1;
    }
    // Handle bottom left case
    if (a[N-2][0] <= a[N-1][0] && a[N-2][1] <= a[N-1][0] && a[N-1][1] <= a[N-1][0])
    {
        b[N-1][0] = -1;
    }
    // Handle bottom right case
    if (a[N-2][N-2] <= a[N-1][N-1] && a[N-2][N-1] <= a[N-1][N-1] && a[N-1][N-2] <= a[N-1][N-1])
    {
        b[N-1][N-1] = -1;
    }
    // Handle the four borders  for N > 2
    for(int i = 1; i < N-1; i++)
    {
        // Handle top row
        if (a[0][i-1] <= a[0][i] && a[0][i+1] <= a[0][i]  && a[1][i] <= a[0][i] && a[1][i+1] <= a[0][i] && a[1][i-1] <= a[0][i])
        {
            b[0][i] = -1;
        }
        // Handle bottom row
        if (a[N-1][i-1] <= a[N-1][i] && a[N-1][i+1] <= a[N-1][i]  && a[N-2][i] <= a[N-1][i] && a[N-2][i+1] <= a[N-1][i] && a[N-2][i-1] <= a[N-1][i])
        {
            b[N-1][i] = -1;
        }
        // Handle left column
        if (a[i-1][0] <= a[i][0] && a[i+1][0] <= a[i][0]  && a[i][1] <= a[i][0] && a[i-1][1] <= a[i][0] && a[i+1][1] <= a[i][0])
        {
            b[i][0] = -1;
        }
        // Handle right column
        if (a[i-1][N-1] <= a[i][N-1] && a[i+1][N-1] <= a[i][N-1]  && a[i][N-2] <= a[i][N-1] && a[i-1][N-2] <= a[i][N-1] && a[i+1][N-2] <= a[i][N-1])
        {
            b[i][N-1] = -1;
        }
    }
       //             if(a[i-1][j-1] <= a[i][j] && a[i-1][j] <= a[i][j] && a[i-1][j+1] <= a[i][j]
     //              && a[i][j-1] <= a[i][j] && a[i][j+1] <= a[i][j]
      //             && a[i+1][j-1] <= a[i][j] && a[i+1][j] <= a[i][j] && a[i+1][j+1] <= a[i][j])
    */
//----------------------------------------------------------------------
