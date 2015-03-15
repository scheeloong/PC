//----------------------------------------------------------------------
// Table of Contents
/* //
1. Mark And Toys
2. Flowers
3. Two Arrays
4. Priyanka and Toys
5. Jim And The Orders

// Time Complexity, T(n) = O(n)
// Space Complexity, S(n) = O(n)


// TODO: Re-order later with decreasing difficulty so can learn hard ones first during revision.
// TODO: Add the simplification of problems to Interview Practice folder.
// TODO: Add the time and space complexity to all below as well as the reduction problems to what you're actually solving.
// */
//----------------------------------------------------------------------

//----------------------------------------------------------------------
/*
// 1 Mark And Toys
// Time Complexity, T(n) = O(n)
// Space Complexity, S(n) = O(n)

#include <iostream>
using namespace std;

#include <algorithm>

int main(void)
{
    long long int N, K;
    cin >> N >> K;
    long long int a[N];
    for(int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    int itemCount = 0;
    sort(&a[0], &a[0]+N);
    int i = 0;
    while(K >= 0 && i < N)
    {
        K -= a[i];
        itemCount++;
        i++;
    }
    if (K<0)
    {
        itemCount--; // do not include last item deducted
    }
    cout << itemCount << endl;
    return 0;
}
// */
//----------------------------------------------------------------------
/*
// 2 Flowers
// Time Complexity, T(n) = O(n)
// Space Complexity, S(n) = O(n)
#include <algorithm> // for sort() , reverse()
#include <iostream>
using namespace std;

int main(void)
{
    int N, K;
    cin >> N >> K;
    int a[N];
    for(int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    sort(&a[0], &a[0] + N);
    reverse(&a[0], &a[0] + N); // sort in descending order
    int j = 0;
    int minCost = 0;
    // need buy all flowers
    for(int i = 0 ; i < N; i++)
    {
        minCost += ((i/K) + 1)*a[i];
    }
    cout << minCost << endl;
    return 0;
}
// */
//----------------------------------------------------------------------
/*
// 3 Two Arrays
// Time Complexity, T(n) = O(nlgn)
// Space Complexity, S(n) = O(n)

#include <algorithm>
#include <iostream>
using namespace std;

int main(void)
{
    int T, N, K;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        cin >> N >> K;
        int a[N];
        int b[N];
        for(int j = 0; j < N; j++)
        {
            cin >> a[j];
        }
        for(int j = 0; j < N; j++)
        {
            cin >> b[j];
        }
        sort(&a[0], &a[0] + N);
        sort(&b[0], &b[0] + N);
        reverse(&b[0], &b[0] + N);
        bool NO = false;
        for(int j = 0; j < N; j++)
        {
            if (a[j] + b[j] < K)
            {
                cout << "NO" << endl;
                NO = true;
                break;
            }
        }
        if(!NO)
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}
// */
//----------------------------------------------------------------------
/*
// 4 Priyanka and Toys
// Time Complexity, T(n) = O(nlgn)
// Space Complexity, S(n) = O(n)
#include <algorithm>
#include <iostream>
using namespace std;

int main(void)
{
    unsigned int N;
    cin >> N;
    unsigned int a[N];
    for(unsigned int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    sort(&a[0] , &a[0] + N);
    unsigned int numUnits = 1;
    unsigned int currWeight = a[0];

    for(unsigned int i = 1; i < N; i++)
    {
        if (a[i] > currWeight + 4)
        {
            numUnits++;
            currWeight = a[i];
        }
    }
    cout << numUnits << endl;
    return 0;
}
// */
//----------------------------------------------------------------------
/*
// 5 Jim And The Orders
// Time Complexity, T(n) = O(nlgn) // sort()
// Space Complexity, S(n) = O(n) // bst with duplicated keys

#include <map> // BST, which includes multimap!
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    unsigned int N;
    cin >> N;
    unsigned long int duration[N];
    unsigned long int temp;
    // Note: Need use multimap as keys are not unique!
    multimap<unsigned long int, unsigned long int> timeDurationPairs;

    for(unsigned int i = 0; i < N; i++)
    {
        cin >> temp >> duration[i];
        duration[i] += temp;
        timeDurationPairs.insert( pair<unsigned long int , unsigned long int> (duration[i],i+1));
    }
    sort(&duration[0], &duration[0] + N);
    unsigned int currOrderTime  = 0;

    for(auto i = timeDurationPairs.begin() ; i != timeDurationPairs.end(); i++)
    {
        cout << (*i).second << " ";
    }
    cout << endl;
    return 0;
}
// */
//----------------------------------------------------------------------
