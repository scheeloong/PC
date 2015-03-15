//
/*
Table of Contents
1. BubbleSort

2. MergeSort

3. QuickSort

4. Randomized Quicksort

5. Counting Sort

6. Radix Sort

7. Binary Search
*/
//----------------------------------------------------------------------------------------
// TODO: Insertion Sort
// TODO: Selection Sort

//----------------------------------------------------------------------------------------
/* //
// 1 Bubble sort
#include <stdlib.h>
#include <stdio.h>

// NOTE: PRINTF for double is "%f" NOT "%d"

void swap(double &a, double &b)
{
    double temp = a;
    a = b;
    b = temp; // b = temp NOT b = a!!
    return;
}

void bubblesort(double * array, int n)
{
    if ((array == NULL) || (n<=1))
        return;
    int i = 0;
    int j = 0;
    for ( i = n-1; i>= 0; i--)
    {
        for(j = 0; j < i; j++)
        {
            if (array[j] > array[j+1])
            {
                printf("\n %f %f \n",array[j], array[j+1] );
                swap(array[j], array[j+1]);
                printf(" \n %f %f \n",array[j], array[j+1] );

            }
            // else do nothing
        }
    }
}

int main(void)
{
    double * haha;
    haha = (double *) malloc(sizeof(double) * 4);
    haha[0] = 3.3;
    haha[1] =5.6;
    haha[2] = 4.7;
    haha[3] = 2.0;
    int i = 0;

    for(i = 0; i < 4; i++)
    {
        printf("%f ", haha[i]);
    }
    bubblesort(haha, 4);
    for(i = 0; i < 4; i++)
    {
        printf("%f ", haha[i]);
    }
    printf("\n");
}
// */
//----------------------------------------------------------------------------------------
/*
// Practice 2: Template Bubble Sort
//Time Complexity:
//O(n^2)
//Space Complexity:
//O(1)

#include <iostream>
using namespace std;

template <class X>
void bubblesort(X ab[], int n);

template <class X>
void swap(X ab[], int a, int b);
int main(void)
{
    int ab[5] = {2,1,4,3,5};
    bubblesort(ab, sizeof(ab)/sizeof(ab[0]));
    for (int i = 0; i < 5; i++)
    {
        cout << ab[i] << endl;
    }
    return 0;
}

template <class X>
void bubblesort(X ab[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if (ab[j] > ab[j+1])
            {
                swap(ab, j, j+1);
            }
        }
    }
}

template <class X>
void swap(X ab[], int a, int b)
{
    X temp = ab[a];
    ab[a] = ab[b];
    ab[b] = temp;
}
// */
//----------------------------------------------------------------------------------------
/* //
// 2 Template Merge Sort
// OMG, it works perfectly on first trial!!
// only 1 mistake of not closing curly braces properly due to nested else and for =D =D =D
// Note: Update: Fixed small mistake that q is either n/2 or n/2+1 depending on whether n is odd or even
//      This was updated on 6th February 2015

// Time Complexity:Xilinx's Vivado HLS 2.
// a[n] = 2a[n/2] + n + n  = 2a[n/2] + 2n
// From Master's Thm. Case 2
// This is O(nlgn)

// Space Complexity:
// Space Complexity, S(n) = O(3n) = O(n) as explained by myself here.
// http://stackoverflow.com/questions/10342890/merge-sort-time-and-space-complexity/28641693#28641693
// These calculations below is false unless the code executes in parallel. Sequential code would only
// take O(3n) as explained above.
// n * (n/2)+(n/2) * (n/4)+(n/4)+(n/4)+(n/4) * ... * (1)*n  = n+n+...+n = n(logn)
// Space complexity is also O(nlgn)


#include <iostream>
using namespace std;

template <class X>
void mergesort(X a[], int n);

int main(void)
{
    int ab[5] = {4,3,2,6,9};
    mergesort(ab, 5);
    for (int i = 0; i < 5; i++)
    {
        cout <<ab[i] <<endl;
    }
    return 0;
}

template <class X>
void mergesort(X a[], int n)
{
    if (n==1)
    {
        return;
    }
    int q, p;
    q = n/2;
    p = n/2;
    //if(n % 2 == 1) p++; // increment by 1
    if(n & 0x1) p++; // increment by 1
        // note: doing and operator is much faster in hardware than calculating the mod (%)
    X b[q];
    int i = 0;
    for (i = 0; i < q; i++)
    {
        b[i] = a[i];
    }
    mergesort(b, i);
    // do mergesort here to save space
    // http://stackoverflow.com/questions/10342890/merge-sort-time-and-space-complexity/28641693#28641693

    // After returning from previous mergesort only do you create the next array.
    X c[p];
    int k = 0;
    for (int j = q; j < n; j++)
    {
        c[k] = a[j];
        k++;
    }
    mergesort(c, k);
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
    return;
}
// */
//----------------------------------------------------------------------------------------
/* //
// 3 QuickSort (A stable sort)
// Time Complexity: O(n^2) worst case, O(nlgn) Average case (or as long as constant partition ratio)
// Space Complexity: O(1) note: sorts in place
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void swapQuickSort(int *p, int l, int r);
int quickSort(int *p, int l, int r);

int main(void)
{
    int n = 5;
    int *p = (int*) malloc(sizeof(int)*n);
    p[0] = 5;
    p[1] = 4;
    p[2] = 3;
    p[3] = 2;
    p[4] = 1;
    int i = 0;
    cout <<"Before Sorting"<<endl;
    for(i = 0; i < n; i++)
    {
        cout<< p[i] << " ";
    }
    cout << endl;
    quickSort(p, 0, n-1);
    cout <<"After Sorting"<<endl;
    for(i = 0; i < n; i++)
    {
        cout<< p[i] << " ";
    }
    cout << endl;
}

// Note: l >= r for this to work
int quickSort(int *p, int l, int r)
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
    quickSort(p, l, left-1);
    quickSort(p,left+1, pivot);
    return 0;
}

void swapQuickSort(int *p, int l, int r)
{
    int temp = p[l];
    p[l] = p[r];
    p[r] = temp;
    return;
}
// */
//----------------------------------------------------------------------------------------------------
/* //
// 4 Randomized QuickSort (A stable sort) (higher chance to get average case than worst case)
// Time Complexity: O(n^2l) worst case, O(nlgn) Average case (or as long as constant partition ratio)
// Space Complexity: O(1) note: sorts in place
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // to initalize random with time()

using namespace std;

void swapRandomizedQuickSort(int *p, int l, int r);
int randomizedQuickSort(int *p, int l, int r);

int main(void)
{
    int n = 5;
    int *p = (int*) malloc(sizeof(int)*n);
    p[0] = 5;
    p[1] = 4;
    p[2] = 3;
    p[3] = 2;
    p[4] = 1;
    int i = 0;
    cout <<"Before Sorting"<<endl;
    for(i = 0; i < n; i++)
    {
        cout<< p[i] << " ";
    }
    cout << endl;
    randomizedQuickSort(p, 0, n-1);
    cout <<"After Sorting"<<endl;
    for(i = 0; i < n; i++)
    {
        cout<< p[i] << " ";
    }
    cout << endl;
}

// Note: l >= r for this to work
int randomizedQuickSort(int *p, int l, int r)
{
    int n = r-l;
    if (n <= 0) return -1; // stop the recursion
    // Partition into 2 sub problems
    time_t t;
    srand((unsigned) time(&t));
    int pivot = (rand() % (r+1-l)) + l; // anywhere from l to  r
    swapRandomizedQuickSort(p, pivot, r); // swap value to right
    pivot = r; // use new pivot
    int left = l;
    int right = l;
    for(right = l; right<pivot; right++)
    {
        if (p[right] < p[pivot])
        {
            swapRandomizedQuickSort(p, left, right);
            left++;
        }
    }
    swapRandomizedQuickSort(p, left, pivot);
    randomizedQuickSort(p, l, left-1);
    randomizedQuickSort(p,left+1, pivot);
    return 0;
}

void swapRandomizedQuickSort(int *p, int l, int r)
{
    int temp = p[l];
    p[l] = p[r];
    p[r] = temp;
    return;
}
// */
//----------------------------------------------------------------------------------------------------
/* //
// 5 Counting Sort (A stable sort)
// Requirement: All numbers are integers in range 0 to k
// Time Complexity: O(k+n)
// Space Complexity: O(k+n)

#include <stdio.h>
#include <stdlib.h> // for malloc
#include <time.h> // for time()
#include <iostream>
#include <cmath>
using namespace std;

void countingSort(int* p, int n, int k);

int main(void)
{
    int n = 8;
    int k = 20; // max range of integer values
    int *p = (int *) malloc(sizeof(int) * n);
    int i = 0;
    time_t t;
    srand((unsigned) time(&t)); // initialize random number genrator
    for(i = 0; i < n; i++)
    {
        p[i] = rand() %k;
    }

    cout << "Before Sorting" << endl;
    for(i = 0; i < n; i++)
    {
        cout<< p[i] <<" ";
    }
    cout << endl;
    countingSort(p, n, k);
    cout << "After Sorting" << endl;
    for(i = 0; i < n; i++)
    {
        cout<< p[i] <<" ";
    }
    cout << endl;
}

void countingSort(int* p, int n, int k)
{
    int *q;
    int *sorted;
    sorted = (int*) malloc(sizeof(int) * (n+1));

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
        q[p[i]]--;
    }

    // Finally, copy sorted back to original array
    for (i = 0; i < n; i++)
    {
        p[i] = sorted[i+1]; // note: sorted starts from 1 to N including N, it doesn't contain anything at 0.
    }
    return;
}
// */
//----------------------------------------------------------------------------------------------------
/* //
// 6 Radix Sort
// Counting Sort (A stable sort)
// Requirement: All numbers are integers in range 0 to k
// Time Complexity: O(d(k+n))
// Space Complexity: O(k+n)

#include <stdio.h>
#include <stdlib.h> // for malloc
#include <time.h> // for time()
#include <iostream>
#include <cmath>
using namespace std;

void countingSortForRadixSort(int* p, int n, int k, int d);
void radixSort(int* p, int n, int k, int d);


int main(void)
{
    int n = 8;
    int k = 10; // max range of integer values ( 0 to k-1)
    int *p = (int *) malloc(sizeof(int) * n);
    int d = 5; // max number of digits for each value
    int i = 0;
    time_t t;
    srand((unsigned) time(&t)); // initialize random number genrator
    int powerfactor = 1;
    for (i = 0; i < d; i++)
    {
        powerfactor *= 10;
    }
    for(i = 0; i < n; i++)
    {
        p[i] = rand() % powerfactor;
    }

    cout << "Before Sorting" << endl;
    for(i = 0; i < n; i++)
    {
        cout<< p[i] <<" ";
    }
    cout << endl;
    radixSort(p, n, k, d);
    cout << "After Sorting" << endl;
    for(i = 0; i < n; i++)
    {
        cout<< p[i] <<" ";
    }
    cout << endl;
    free(p);
}

void radixSort(int* p, int n, int k, int d)
{
    int i = 0;
    cout<<endl;
    for(i = 1; i <= d; i++)
    {
        countingSortForRadixSort(p, n, k, i);
        // For debugging
        int j = 0;
        cout <<"Step " << i <<":"<<endl;
        for(j = 0; j < n; j++)
        {
            cout<< p[j] <<" ";
        }
        cout << endl;
    }
    cout<<endl;
}


void countingSortForRadixSort(int* p, int n, int k, int d)
{
    int *q;
    int *sorted;
    sorted = (int*) malloc(sizeof(int) * (n+1));

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
    int powerFactor = 1;
    double shift = 10.0;
    for (i = 0; i < d; i++)
    {
        powerFactor*=10;
        shift *= 0.1;
    }
//cout << "powerFactor" << powerFactor << " shift" << shift << endl;
    // Store all values
    for(i = 0; i< n; i++)
    {
//int op = p[i] %powerFactor;
//cout << " pi is " << p[i] << " op is " << op << " after shifting is " << (p[i]%powerFactor)*shift << endl;
        int m = floor((p[i]%powerFactor)*shift);
//cout << "m is " << m << endl;
        q[m]++; // increment that value
    }
    for(i = 1; i<= k; i++)
    {
        q[i] = q[i] + q[i-1]; // Make it cumulative
    }
    // Sort it
    for(i = n-1; i>= 0; i--) // Note: need start from n-1 to 0 to ensure stability which is needed for radix sort
    {
        int m = floor((p[i]%powerFactor)*shift);
        sorted[q[m]] = p[i]; // start from last value of p , store that point into sorted
        q[m]--;
    }

    // Finally, copy sorted back to original array
    for (i = 0; i < n; i++)
    {
        p[i] = sorted[i+1]; // note: sorted starts from 1 to N including N, it doesn't contain anything at 0.
    }
    free(sorted);
    free(q);
    return;
}
// */
//----------------------------------------------------------------------------------------------------
/* //
// 7 Binary Search

template <class X>
int binarySearch(X a[], X element, int n);


// returns index of found element or -1 if not found
// a[] contains sorted array to be search
// element is the element being looked for
// n is the total number of elements in sorted array
template <class X>
int binarySearch(X a[], X element, int n)
{
    int first = 0;
    int last = n -1;
    while (first != last)
    {
        if (element <= a[(first+last)/2])
        {
            last  = (first+last)/2 ;
        }
        else // element >= a[(first+last)/2]
        {
            first = (first+last)/2 +  1;
        }
    }
    // Here, either the value is found or it doesn't exist
    if(element == a[first])
    {
        return first;
    }
    else
    {
        return -1;
    }
}
// */
