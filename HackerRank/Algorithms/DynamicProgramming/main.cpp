//----------------------------------------------------------------------
// Table of Contents
/* //
1. The Longest Common Subsequence

2. The Maximum Subarray

// TODO: Re-order later with decreasing difficulty so can learn hard ones first during revision.
// TODO: Add the simplification of problems to Interview Practice folder.
// TODO: Add the time and space complexity to all below as well as the reduction problems to what you're actually solving.
// */
//----------------------------------------------------------------------


//----------------------------------------------------------------------

//----------------------------------------------------------------------
/*
// 1 The Longest Common Subsequence
// Longest Common Subsequence
// Approach 1: Dynamic Programming
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
//----------------------------------------------------------------------
/*
// 2 The Maximum Subarray
// Maximum Subarray Problem using Kadane's Algorithm
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
    int T = 0;
    int N = 0;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        int * a;
        a = (int*) malloc(sizeof(int) * N);
        for(int j = 0; j < N; j++)
        {
            cin >> a[j];
        }
        int k,l;
        int maximum = maxSubArray(a, N, k, l);
      //  cout<<"Start: "<< k<<" to End: " << l <<" is maximum: "<< maximum << endl;
        int contiguousSum = 0;
        int nonContiguousSum = 0;
        bool noPositive = true;
        for(int j = 0; j < k ; j++)
        {
            if(a[j] >= 0)
            {
                nonContiguousSum += a[j];
                noPositive = false;
            }
        }
        for(int j = k; j <= l; j++)
        {
            if(a[j] >= 0)
            {
                nonContiguousSum += a[j];
                noPositive = false;
            }
            contiguousSum += a[j];
        }
        for(int j = l+1; j < N; j++)
        {
             if(a[j] >= 0)
            {
                nonContiguousSum += a[j];
                noPositive = false;
            }
        }
        if (noPositive)
        {
            nonContiguousSum = contiguousSum;
        }
        cout << contiguousSum << " " << nonContiguousSum << endl;
    }
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
//----------------------------------------------------------------------
