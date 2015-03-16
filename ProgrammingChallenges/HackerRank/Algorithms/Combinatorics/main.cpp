//----------------------------------------------------------------------
// Table of Contents
// 1. Handshake
// 2. Connecting Towns

// Time Complexity , T(n) = O(n)
// Space Complexity, S(n) = O(n)
/* //
// TODO: Re-order later with decreasing difficulty so can learn hard ones first during revision.
// TODO: Add the simplification of problems to Interview Practice folder.
// TODO: Add the time and space complexity to all below as well as the reduction problems to what you're actually solving.
// */
//----------------------------------------------------------------------
/*
// 1 Handshake
// Time Complexity , T(n) = O(1)
// Space Complexity, S(n) = O(1)
#include <iostream>
using namespace std;

int main(void)
{
    int T;
    cin >> T;
    unsigned long long int N;

    for(size_t i = 0; i < T; i++)
    {
        cin >> N;
        cout << ((N*(N-1))/2) << endl;
    }
    return 0;
}
// */
//----------------------------------------------------------------------
/*
// 2 Connecting Towns
// Time Complexity , T(n) = O(n)
// Space Complexity, S(n) = O(1)

#include<iostream>
using namespace std;

int main()
{
    unsigned int T, N;
    cin >> T;
    for(unsigned int i = 0; i < T; i++)
    {
        cin >> N;
        unsigned int answer = 1;
        unsigned int temp;
        for(unsigned int j = 0; j < N-1; j++)
        {
            cin >> temp;
            answer = (answer * temp)%1234567;
        }
        cout << answer << endl;
    }
    return 0;
}
// */
//----------------------------------------------------------------------
//----------------------------------------------------------------------
// TO FIX
//----------------------------------------------------------------------
/*
// TODO: Picking Cards
// Problems:
// 1. Wrong Output
// 2. Too Slow
// Time Complexity, T(n) = O(n^2)
// Space Complexity, S(n) = O(n)

#include <algorithm> // for sort()
#include <iostream>
using namespace std;

int main(void)
{
    int T, N;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        cin >> N;
        int a[N];
        for(int j = 0; j < N; j++)
        {
            cin >> a[j];
        }
        sort(&a[0], &a[0]+N);
        int b[N];
        int c[N]; // c[i] = number of elemnts in b[i]
        int lenB = 0; // assume N > 0 , lenB = number of elements in the compressed array
        b[0] = a[0];
        c[0] = 1;

        for(int j = 1; j < N; j++)
        {
            if(a[j] != a[j-1])
            {
                lenB++;
                b[lenB] = a[j];
                c[lenB] = 1;
            }
            else
            {
                c[lenB]++; // increment number of elements in b[lenB]
            }
        }
        long long int numPermutation = 1;
        int startIndex = 0;
        // Need fill every space available
        int smallestAvailableIndex = -1;
        for(int j = 0; j < N; j++)
        {
            long long int sum = 0;
            for(int k = startIndex; k <= lenB; k++)
            {
                // Only add if b[k] is <= current place holder j
                if(b[k] <= j)
                {
                    if(c[k] > 0)
                    {
                        sum += c[k];
                        if(smallestAvailableIndex == -1)
                        {
                            smallestAvailableIndex = k;
                        }
                    }
                    else
                    {
                        startIndex++; // never bother going to previous index again
                    }
                }
                else
                {
                    break; // break to next iteration as no more to add.
                }
            }
            if(smallestAvailableIndex != -1)
            {
                c[smallestAvailableIndex]--;
                smallestAvailableIndex = -1; // reset

            }
            numPermutation *= sum;
        }
        cout << numPermutation << endl;
    }
    return 0;
}
*/
//----------------------------------------------------------------------
