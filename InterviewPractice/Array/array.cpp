//
//----------------------------------------------------------------------------------------
/* //
Table of Contents
1. Maximum Subarray Problem using Kadane's Algorithm

// TODO: Sorted Shifted Array, find the amount array is shifted by
// TODO:  Sorted shifted array, search for an element
// TODO: Find the only singular integer in an array of pairs of integers
// TODO: Array with n distinct elements and local minimums, find one local min in O(logN)
e.g. 10, 6, 4, 3, 12, 19, 18, 20, 17 has 3 local mins at : 3, 18, 17
Easy, just prove that if A[n-1] < A[n] , there must exist local min in A[1] -> A[n-1]
Similarly for A[n-1] < A[n-2] => There must exist local min in A[n-1] -> A[n]
note: Always check for A[n-1] itself being local min as base case cause
 you must always set top or bottom to not include it. If not may end up with infinite
 loop in certain cases. basically must always exclude the middle element that you checked itself
 so that don't end up checking it again in any way.

// TODO: 2. Merge two equally sized integer arrays, the first one   having the capacity to accommodate the result.
            Hint: Merge from end to first so won't overwrite non-merge values

// TODO 3.   Implement a method for a Fibonacci sequence where instead of adding the last 2 elemenT's you add the last n elements. For n=3. 1 1 1 3 5 9...
// */
//----------------------------------------------------------------------------------------
/* //
// 1 Maximum Subarray Problem using Kadane's Algorithm
// Time Complexity = O(n)
// Space Complexity = O(1)
#include <stdlib.h> // for rand()
#include <time.h>
#include <limits.h> // INT_MAX
#include <iostream>
using namespace std;

int maxSubArray(int* a, int N, int &startIndex, int &endIndex);

int main(void)
{
    int N = 10;
    int * a;
    a = (int*) malloc(sizeof(int) * N);
    int i = 0;
    srand (time(NULL));
    for(i = 0; i < N; i++)
    {
        a[i] = rand()%20;
        if((rand()%20) > 10)
        {
            a[i] *= -1;
        }
    }
    for(i = 0; i < N; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    int k,l;
    int maximum = maxSubArray(a, N, k, l);
    cout<<"Start: "<< k<<" to End: " << l <<" is maximum: "<< maximum << endl;
}

int maxSubArray(int* a, int N, int &startIndex, int &endIndex)
{
    startIndex = 0;
    endIndex = 0;
    int currStartIndex = 0;
    int currEndIndex = 0;
    int i = 0;
    int cumulativeSum = -1*INT_MAX;
    int maxSum = cumulativeSum;
    for(i = 0; i < N; i++)
    {
        if(cumulativeSum < 0)
        {
            cumulativeSum = a[i];
            currStartIndex = i;
            currEndIndex = i;
        }
        else
        {
            cumulativeSum += a[i];
            currEndIndex = i;
        }
        if (cumulativeSum >= maxSum)
        {
            maxSum = cumulativeSum;
            startIndex = currStartIndex;
            endIndex = currEndIndex;
        }
    }
    return maxSum;
}
// */


