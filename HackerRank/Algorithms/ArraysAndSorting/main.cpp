//-------------------------------------------------------------
/*
// Table Of Contents

1. Intro To Tutorial Challenges
2. Insertion Sort Part 1
3. Insertion Sort Part 2
4. Insertion Sort Advanced Analysis // (HARD!!!)
5. Running Time Of Algorithms
6. Correctness And The Loop Invariant
7. Quick Sort 1 Partition
8. Quick Sort 2 Sorting
9. Quick Sort In-Place
10. Running Time Of Quick Sort
11. Counting Sort 1
12. Counting Sort 2
13. Counting Sort 3
14. The Full Counting Sort


// Time Complexity, T(n) = O(n)
// Space Complexity, S(n) = O(n)

*/

//-------------------------------------------------------------
// TODO: 15 Closest Numbers

#include <queue>

#include <iostream>
using namespace std;

int main(void)
{
    queue<long long int> answerPairs; // a queue of pairs of integers to compare
    unsigned long int N;
    cin N;
    long long int values[N];
    long long int minDifference = 20000001; // max for this problem instance
    for(unsigned long int i = 0; i < N; i++)
    {
        cin >> values[i];
    }
    // Problem: Easy to find pairs, but need create new struct of pairs to output them in ascending order
    // from this struct, need overload comparison functions and etc.
    // TODO:
}

//-------------------------------------------------------------
/* //
// 1 Intro To Tutorial Challenges
// Time Complexity, T(n) = O(n)
// Space Complexity, S(n) = O(n)
#include <iostream>
using namespace std;

int main(void)
{
    int value;
    int N;
    cin >> value >> N;
    int a[N];
    int index = -1;
    for(int i = 0; i < N; i++)
    {
        cin >> a[i];
        if(index == -1 && a[i] == value)
        {
            index = i;
        }
    }
    cout << index << endl;
    return 0;
}
// */
//-------------------------------------------------------------
/*
// 2 Insertion Sort Part 1
// Time Complexity, T(n) = O(n)
// Space Complexity, S(n) = O(n)
#include <iostream>
using namespace std;

void print(int* a, int n);

int main(void)
{
    int N;
    cin >> N;
    int a[N];
    for(int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    int value = a[N-1];
    int i = 0;
    for(i = N-2; i >= 0; i--)
    {
        if(value < a[i])
        {
            // Swap
            a[i+1] = a[i];
            print(a, N);
        }
        else
        {
            a[i+1] = value;
            break;
        }
    }
    if(i < 0)
    {
        a[0] = value;
    }
    print(a,N);
    return 0;
}
void print(int* a, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " " ;
    }
    cout << endl;
    return;
}
// */
//-------------------------------------------------------------
/* //
// 3 Insertion Sort Part 2
// Time Complexity, T(n) = O(n^2)
// Space Complexity, S(n) = O(n)
#include <iostream>
using namespace std;

void swap(int* a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void print(int* a, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " " ;
    }
    cout << endl;
    return;
}

int main(void)
{
    int N;
    cin >> N;
    int a[N];
    for(int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i < N; i++)
    {
        int j = i;
        while(j > 0 && a[j] < a[j-1])
        {
            swap(&a[j], &a[j-1]);
            j--;
        }
        print(a, N);
    }
    return 0;
}
// */
//-------------------------------------------------------------
/*
// 4 Insertion Sort Advanced Analysis
// Time Complexity, T(n) = O(nlgn)
// Space Complexity, S(n) = O(nlgn)
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

template <class X>
unsigned long long int mergesort(X a[], int n);

template <class X>
unsigned long long int mergesort(X a[], int n)
{
    unsigned long long int countInversion = 0;
    if (n==1)
    {
        return 0 ;
    }
    int q, p;
    q = n/2;
    p = n/2;
    //if(n % 2 == 1) p++; // increment by 1
    if(n & 0x1) p++; // increment by 1
        // note: doing and operator is much faster in hardware than calculating the mod (%)
    X b[q];
    X c[p];
    int i = 0;
    for (i = 0; i < q; i++)
    {
        b[i] = a[i];
    }
    int k = 0;

    for (int j = q; j < n; j++)
    {
        c[k] = a[j];
        k++;
    }
    countInversion += mergesort(b, i);
    countInversion += mergesort(c, k);
    int r, s, t;
    t = 0; r = 0; s = 0;
    while( (r!=q) && (s!= p))
    {
        if (b[r] <= c[s])
        {
            a[t] = b[r];
            r++;
        }
        else
        {
            if(r!= q)
            {
                countInversion += q-r; // number to pass through
            }
            a[t] = c[s];
            s++;
        }
        t++;
    }
    if ( r==q)
    {
        while(s!=p)
        {
            a[t] = c[s];
            s++;
            t++;
        }
    }
    else
    {
        while(r != q)
        {
            a[t] = b[r];
            r++;
            t++;
        }
    }
    return countInversion;
}


int main(void)
{
    int T, N;
    cin >> T;
    for(int k = 0; k < T; k++)
    {
        cin >> N;
        int a[N];
        for(int i = 0 ; i < N; i++)
        {
            cin >> a[i];
        }
        unsigned long long int countSwap = 0;
        countSwap = mergesort(a, N);
        cout << countSwap << endl;
    }
    return 0;
}
// */
//-------------------------------------------------------------
/* //
// 5 Running Time Of Algorithms
// Time Complexity, T(n) = O(n^2)
// Space Complexity, S(n) = O(n)
#include <iostream>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    int a[N];
    unsigned long int countSwap = 0;
    for(int i = 0; i < N; i++)
    {
        cin >> a[i];
        for (int j = i-1; j >= 0 ; j --)
        {
            if(a[i] < a[j])
            {
                countSwap++;
            }
        }
    }
    cout << countSwap << endl;
    return 0;
}
// */
//-------------------------------------------------------------
/*
// 6 Correctness And The Loop Invariant
// Time Complexity, T(n) = O(n^2)
// Space Complexity, S(n) = O(n)
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

void insertionSort(int N, int arr[])
{
    int i,j;
    int value;
    for(i=1;i<N;i++)
    {
        value=arr[i];
        j=i-1;
        while(j>=0 && value<arr[j]) // error was here whereby j>0 which is wrong and corrected to be j>=0
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=value;
    }
    for(j=0;j<N;j++)
    {
        printf("%d",arr[j]);
        printf(" ");
    }
}
int main(void)
{
    int N;
    scanf("%d", &N);
    int arr[N], i;
    for(i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    insertionSort(N, arr);
    return 0;
}
// */
//-------------------------------------------------------------
/*
// 7 Quick Sort 1 Partition
// Time Complexity, T(n) = O(n)
// Space Complexity, S(n) = O(n)

#include <queue>

#include <iostream>
using namespace std;

int main(void)
{
    int N, p;
    int temp;
    queue<int> small;
    queue<int> large;

    cin >> N >> p;
    for(int i = 1; i < N; i++)
    {
        cin >> temp;
        if (temp <= p)
        {
            small.push(temp);
        }
        else
        {
            large.push(temp);
        }
    }

    while(!small.empty())
    {
        cout << small.front() << " ";
        small.pop();
    }

    cout << p << " ";

    while(!large.empty())
    {
        cout << large.front() << " ";
        large.pop();
    }
    cout << endl;
    return 0;
}
// */
//-------------------------------------------------------------
/*
// 8 QuickSort 2 Sorting
// Time Complexity, T(n) = O(n^2)
// Space Complexity, S(n) = O(n^2)
#include <queue>
#include <vector>
#include <algorithm> // partition() , size()

#include <iostream>
using namespace std;
void partitionQuickSort (vector<int> &a);
int main(void)
{
    int N, p;
    int temp;
    vector<int> a;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }
    partitionQuickSort(a);
}

// return by reference
void partitionQuickSort (vector<int> &a)
{
    int n = a.size();
    if (n == 1) return;
    vector<int> small;
    vector<int> large;
    int pivot = a[0];
    for(int i = 1; i < n; i++)
    {
        if (a[i] < pivot)
        {
            small.push_back(a[i]);
        }
        else
        {
            large.push_back(a[i]);
        }
    }
    if(small.size() > 0)
    {
        partitionQuickSort(small);
    }
    if(large.size() > 0)
    {
        partitionQuickSort(large);
    }
    int k = 0;
    for(k = 0 ; k < small.size(); k++)
    {
        a[k] = small[k];
    }
    a[k] = pivot;
    k++;
    for(int j = k; j < large.size() + k; j++)
    {
        a[j] = large[j-k];
    }

    for(int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return;
}
// */
//-------------------------------------------------------------
/*
// 9 Quicksort In-Place
// Time Complexity, T(n) = O(n^2)
// Space Complexity, S(n) = O(1)
// Similar to code in interview success but with printing array each iteration.

#include <iostream>
using namespace std;

void swapQuickSort(int *p, int l, int r);
int quickSort(int *p, int l, int r, int n);

int main(void)
{
    int N;
    cin >> N;
    int a[N];
    for(int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    quickSort(a, 0, N-1, N);
    return 0;
}

void swapQuickSort(int *p, int l, int r)
{
    int temp = p[l];
    p[l] = p[r];
    p[r] = temp;
    return;
}

// Note: l >= r for this to work
int quickSort(int *p, int l, int r, int N)
{
    int n = r-l;
    if (n <= 0) return -1; // stop the recursion
    // Partition into 2 sub problems
    int pivot = r;
    int left = l;
    int right = l;
    for(right = l; right<pivot; right++)
    {
        if (p[right] < p[pivot])
        {
            swapQuickSort(p, left, right);
            left++;
        }
    }
    swapQuickSort(p, left, pivot);

    for(int i = 0; i < N; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
    quickSort(p, l, left-1, N);
    quickSort(p,left+1, pivot, N);
    return 0;
}
// */
//-------------------------------------------------------------
/*
// 10 Running Time Of Quick Sort
// Time Complexity, T(n) = O(n^2) // quick sort
// Space Complexity, S(n) = O(n) // from merge sort
// Similar to code in interview success but with printing array each iteration.

#include <iostream>
using namespace std;

void swapQuickSort(int *p, int l, int r);
int quickSort(int *p, int l, int r, int n);

template <class X>
unsigned long long int mergesort(X a[], int n);

int main(void)
{
    int N;
    cin >> N;
    int a1[N];
    int a2[N];
    for(int i = 0; i < N; i++)
    {
        cin >> a1[i];
        a2[i] = a1[i];
    }

    int countQuickSort = quickSort(a1, 0, N-1, N);
    int countInsertionSort = mergesort(a2, N);
    cout << countInsertionSort - countQuickSort << endl;
    return 0;
}

void swapQuickSort(int *p, int l, int r)
{
    int temp = p[l];
    p[l] = p[r];
    p[r] = temp;
    return;
}

// Note: l >= r for this to work
int quickSort(int *p, int l, int r, int N)
{
    int n = r-l;
    if (n <= 0) return 0; // no swap if only 1 element
    int countSwap = 0;
    // Partition into 2 sub problems
    int pivot = r;
    int left = l;
    int right = l;
    for(right = l; right<pivot; right++)
    {
        if (p[right] < p[pivot])
        {
            countSwap++;
            swapQuickSort(p, left, right);
            left++;
        }
    }
    countSwap++;
    swapQuickSort(p, left, pivot);
    countSwap += quickSort(p, l, left-1, N);
    countSwap += quickSort(p,left+1, pivot, N);
    return countSwap;
}

template <class X>
unsigned long long int mergesort(X a[], int n)
{
    unsigned long long int countInversion = 0;
    if (n==1)
    {
        return 0 ;
    }
    int q, p;
    q = n/2;
    p = n/2;
    //if(n % 2 == 1) p++; // increment by 1
    if(n & 0x1) p++; // increment by 1
        // note: doing and operator is much faster in hardware than calculating the mod (%)
    X b[q];
    X c[p];
    int i = 0;
    for (i = 0; i < q; i++)
    {
        b[i] = a[i];
    }
    int k = 0;

    for (int j = q; j < n; j++)
    {
        c[k] = a[j];
        k++;
    }
    countInversion += mergesort(b, i);
    countInversion += mergesort(c, k);
    int r, s, t;
    t = 0; r = 0; s = 0;
    while( (r!=q) && (s!= p))
    {
        if (b[r] <= c[s])
        {
            a[t] = b[r];
            r++;
        }
        else
        {
            if(r!= q)
            {
                countInversion += q-r; // number to pass through
            }
            a[t] = c[s];
            s++;
        }
        t++;
    }
    if ( r==q)
    {
        while(s!=p)
        {
            a[t] = c[s];
            s++;
            t++;
        }
    }
    else
    {
        while(r != q)
        {
            a[t] = b[r];
            r++;
            t++;
        }
    }
    return countInversion;
}
// */
//-------------------------------------------------------------
/*
// 11 Counting Sort 1
// Time Complexity, T(n) = O(n)
// Space Complexity, S(n) = O(n)

#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    unsigned long int numAppear[100];
    unsigned long int N = 0;
    int temp = 0;
    memset(numAppear, 0, sizeof(numAppear)); // initialize all to 0
    cin >> N;
    for(unsigned long int i = 0; i < N; i++)
    {
        cin >> temp;
        numAppear[temp]++;
    }
    for(int i = 0 ; i < 100; i++)
    {
        cout << numAppear[i] << " ";
    }
    cout << endl;
    return 0;
}
// */
//-------------------------------------------------------------
/*
// 12 Counting Sort 2
// Time Complexity, T(n) = O(n) (Amortized Analysis) note: Will only have at most n numbers to print
// Space Complexity, S(n) = O(n)

#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    unsigned long int numAppear[100];
    unsigned long int N = 0;
    int temp = 0;
    memset(numAppear, 0, sizeof(numAppear)); // initialize all to 0
    cin >> N;
    for(unsigned long int i = 0; i < N; i++)
    {
        cin >> temp;
        numAppear[temp]++;
    }
    // will only have at most N numbers to print at bottom
    for(int i = 0 ; i < 100; i++)
    {
        for(unsigned long int j = 0; j < numAppear[i]; j++)
        {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
// */
//-------------------------------------------------------------
/* //
// 13 Counting Sort 3
// Time Complexity, T(n) = O(n)
// Space Complexity, S(n) = O(n)

#include <cstring>
#include <string>
#include <iostream>
using namespace std;

int main(void)
{
    unsigned long int numAppear[100];
    unsigned long int N = 0;
    int temp = 0;
    string temp2;
    memset(numAppear, 0, sizeof(numAppear)); // initialize all to 0
    cin >> N;
    for(unsigned long int i = 0; i < N; i++)
    {
        cin >> temp >> temp2;
        numAppear[temp]++;
    }
    unsigned long int cumulativeSum = 0;
    for(int i = 0 ; i < 100; i++)
    {
        cumulativeSum += numAppear[i];
        cout << cumulativeSum << " ";
    }
    cout << endl;
    return 0;
}
// */
//-------------------------------------------------------------
/*
// 14 The Full Counting Sort
// Requirement: All numbers are integers in range 0 to k
// Time Complexity: O(k+n)
// Space Complexity: O(k+n)

#include <stdio.h>
#include <stdlib.h> // for malloc
#include <time.h> // for time()
#include <iostream>
#include <cmath>
#include <cstring>
#include <string> // for temporary cin
using namespace std;

// #define DEBUG 1

void countingSort(int* p,char** pString, int n, int k);

int main(void)
{
    int n = 0;
    int k = 100; // max range of integer values
    int i = 0;
    time_t t;
    cin >> n;
    int *p = (int *) malloc(sizeof(int) * n);
    char ** pString = (char **) malloc(sizeof(char*) * n);
    string tempInput;
    for(i = 0; i < n; i++)
    {
        pString[i] = (char *) malloc(sizeof(char) * 11);
        cin >> p[i] >> pString[i];
        if(i < n/2)
        {
            pString[i] = "-";  // change to dashes instead
        }
    }
#if DEBUG
    cout << "Before Sorting" << endl;
    for(i = 0; i < n; i++)
    {
        cout<< p[i] <<"+" << pString[i] <<" ";
    }
    cout << endl;
cout <<" HERE! " << endl;
#endif
    countingSort(p,pString, n, k);

#if DEBUG
    cout << "After Sorting" << endl;
    for(i = 0; i < n; i++)
    {
        cout<< p[i] <<"+" << pString[i] <<" ";
    }
    cout << endl;
cout <<" ACTUAL OUTPUT" << endl;
#endif
    for(i = 0; i < n; i++)
    {
        cout<< pString[i] <<" ";
    }
    cout << endl;
}

void countingSort(int* p,char** pString, int n, int k)
{
    int *q;
    int *sorted;
    char** sortedPstring;
    sorted = (int*) malloc(sizeof(int) * (n+1));
    sortedPstring = (char **) malloc(sizeof(char*) * (n+1));
    for(int i = 0 ; i < n+1; i++)
    {
        sortedPstring[i] = (char *) malloc(sizeof(char)*(11));
    }

    q = (int*) malloc(sizeof(int) * (k+1));
    int i = 0;
    // initialize count of all numbers to 0
    for (i = 0; i <= k; i++)
    {
        q[i] = 0;
    }
    // initialize the sorted for all numbers to 0
    for (i = 0; i < n; i++)
    {
        sorted[i] = 0;
    }
    // Store all values
    for(i = 0; i< n; i++)
    {
        q[p[i]]++; // increment that value
    }
    for(i = 1; i<= k; i++)
    {
        q[i] = q[i] + q[i-1]; // Make it cumulative
    }
    // Sort it
    for(i = n-1; i>= 0; i--) // Note: need start from n-1 to 0 to ensure stability
    {
        sorted[q[p[i]]] = p[i]; // start from last value of p , store that point into sorted
        sortedPstring[q[p[i]]] = pString[i];
        q[p[i]]--;
    }

    // Finally, copy sorted back to original array
    for (i = 0; i < n; i++)
    {
        pString[i] = sortedPstring[i+1];
        p[i] = sorted[i+1]; // note: sorted starts from 1 to N including N, it doesn't contain anything at 0.
    }
    return;
}
// */
//-------------------------------------------------------------
