//----------------------------------------------------------------------
// Table of Contents
/* //
1. Solve Me First
2. Find Digits
3. Is Fibo
4. Utopian Tree
5. Maximizing XOR
6. Alternating Characters
7. The Love Letter Mystery
8. Angry Children
9. Flipping Bits
10. Halloween Party
11. Game Of Thrones I
12. Lonely Integer
13. Manasa And Stones
14. ACM ICPC Team
15. Chocolate Feast
16. Sherlock And Squares
17. Filling Jars
18. Sherlock And The Beast => permutation of 2 numbers to get the desired sum where prefer more smaller numbers.
19. Sherlock And GCD => GCD algorithm
20. Angry Professor
21. Two Strings

// Time Complexity, T(n) = O(n)
// Space Complexity, S(n) = O(n)

// TODO: Re-order later with decreasing difficulty so can learn hard ones first during revision.
// TODO: Add the simplification of problems to Interview Practice folder.
// TODO: Add the time and space complexity to all below as well as the reduction problems to what you're actually solving.
e.g.
// */
//----------------------------------------------------------------------

/*
// 1 Solve Me First
#include <stdio.h>
int main() {
  int a,b;
  scanf("%d %d",&a,&b);
  a += b;
  printf("%d",a);
  return 0;
}
// */
//----------------------------------------------------------------------
/*
// 2 Find Digits
#include <stdio.h>
int main(void)
{
    int T; // number of test cases
    scanf("%d", &T);
    int i = 0;
    for(i = 0; i < T; i++)
    {
        int N, temp;
        int count = 0;
        int divisor = 1;
        scanf("%d", &N);
        while(1)
        {
            temp = N/divisor;
            if(temp == 0) break;
            temp = temp%10;
            if (temp != 0 && (N%temp  == 0)) count++;
            divisor *= 10;
        }
        printf("%d\n", count);
    }
    return 0;
}
// */
//----------------------------------------------------------------------
/*
// 3 Is Fibo
 #include<stdio.h>

 // Find out if num is a fibonacci number
int fib(unsigned long long N)
{
    unsigned long long i=1 ,j=1 ,curr=1;
    if(N == 0) return 1; // it is a fibonacci number
    while(1)
    {
        i = curr;
        curr = curr + j;
        j= i;
        if(curr==N)
        return 1;
        if(curr>N)
        return 0;
    }
}

int main()
{
    unsigned T;
    scanf("%u",&T);
    while(T--)
    {
        unsigned long long int answer=0;
        unsigned long long num;
        scanf("%llu",&num);
        if(num == 0 || num ==1)
        {
            printf("IsFibo\n");
        }
        else
        {
            answer = fib(num);
            if(answer==1)
            {
                printf("IsFibo\n");
            }
            else
            {
                printf("IsNotFibo\n");
            }
        }
    }
    return 0;
}
// */
//----------------------------------------------------------------------
/*
// 4 Utopian Tree
#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int height = 0;
        for (int i = 0; i <= n ; i++)
        {
            if ((i %2) == 0)
                height++;
            else
                height *=2;
        }
        cout << height << endl;
    }
}
// */
//----------------------------------------------------------------------
/*
// 5 Maximizing XOR

#include <stdio.h>
#include <iostream>
using namespace std;

int main(void)
{
    int L = 0, R = 0;
    cin >> L >> R;
    int i, j;
    int maximum = 0;
    for(i = L; i < R; i++)
    {
        for(j = i+1; j<=R; j++)
        {
            int temp = i ^ j;
            if (temp > maximum)
                maximum = temp;
        }
    }
    cout << maximum;
    return 0;
}
// */
//----------------------------------------------------------------------
/*
// 6 Alternating Characters
#include <string.h>
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

char *inputString(FILE* fp, size_t size)
{
//The size is extended by the input with the value of the provisional
    char *str;
    int ch;
    size_t len = 0;
    str = (char *) realloc(NULL, sizeof(char)*size);//size is start size
    if(!str)return str;
    while(EOF!=(ch=fgetc(fp)) && ch != '\n')
    {
        str[len++]=ch;
        if(len==size){
            str = (char *) realloc(str, sizeof(char)*(size+=16));
            if(!str)return str;
        }
    }
    str[len++]='\0';

    return (char *) realloc(str, sizeof(char)*len);
}


int main(void)
{
    int numTest;
    cin >> numTest;
    int i = 0;
    char* inputStr;
    inputStr = inputString(stdin, 10);
    for(i = 0; i < numTest; i++)
    {
        int minDeletion = 0;
        //scanf("%s", inputStr);
        inputStr = inputString(stdin, 10);
        int length = strlen(inputStr);
        char letter = inputStr[0]; // 'A' or 'B'
        for(int i = 1; i < length; i++)
        {
            if (inputStr[i] == letter)
            {
                minDeletion++;
            }
            else
            {
                letter = inputStr[i];
            }
        }
        cout << minDeletion << endl;
    }
    return 0;
}
// */
//----------------------------------------------------------------------
/*
// 7 The Love Letter Mystery
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

char *inputString(FILE* fp, size_t size)
{
//The size is extended by the input with the value of the provisional
    char *str;
    int ch;
    size_t len = 0;
    str = (char *) realloc(NULL, sizeof(char)*size);//size is start size
    if(!str)return str;
    while(EOF!=(ch=fgetc(fp)) && ch != '\n')
    {
        str[len++]=ch;
        if(len==size){
            str = (char *) realloc(str, sizeof(char)*(size+=16));
            if(!str)return str;
        }
    }
    str[len++]='\0';

    return (char *) realloc(str, sizeof(char)*len);
}

int main(void)
{
    int numTest;
    cin >> numTest;
    int i = 0;
    int count = 0;
    char* inputStr;
    inputStr = inputString(stdin, 10);
    for(i = 0; i < numTest; i++)
    {
        inputStr = inputString(stdin, 10);
        int length = strlen(inputStr);
        int j = 0;
        for(j = 0; j < length/2; j++)
        {
            count += abs(inputStr[j] - inputStr[length-j-1]);
        }
        cout << count << endl;
        count = 0; // reinitialize
    }
    return 0;
}
// */
//----------------------------------------------------------------------
/*
// 8 Angry Children
#include <iostream>
using namespace std;


template <class X>
void mergesort(X a[], int n);


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
    if(n % 2 == 1) p++; // increment by 1
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
    mergesort(b, i);
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

int main(void)
{
    int N, K;
    cin >> N >> K ;
    int values[N];
    int i = 0;
    for(i = 0; i < N; i++)
    {
        cin >> values[i];
    }

    mergesort(values, N);
    int minValue = values[K-1] - values[0];
    for(int i = 0; (i + (K-1)) < N; i++)
    {
        if ((values[i+K-1] - values[i])  < minValue)
        {
            minValue = values[i+K-1] - values[i];
        }
    }
    cout << minValue << endl;
    return 0;
}
// */
//----------------------------------------------------------------------
/*
// 9 Flipping Bits
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;


int main()
{
    // Enter your code here. Read input from STDIN. Print output to STDOUT
    int T;
    unsigned int value;
    cin >> T;
    int i = 0;
    for ( i = 0; i < T; i++)
    {
        cin >> value;
        value = value ^ (0xFFFFFFFF);  // xor with 1
        cout  << value << endl;
    }
    return 0;
}
// */
//----------------------------------------------------------------------
/*
// 10 Halloween Party
#include <iostream>
using namespace std;

int main()
{
    int T;
    unsigned long long int K;
    unsigned long long int half;
    cin >> T;
    int i= 0;
    for(i = 0; i < T; i++)
    {
        cin >> K;
        half = K/2;
        if (K&0x1)
        {
            half = half * (half + 1);
        }
        else
        {
            half = half * half;
        }
        cout << half << endl;
    }
}
// */
//----------------------------------------------------------------------
/*
// 11 Game Of Thrones I
#include <iostream>
#include <stdio.h>
using namespace std;

// 'a' = 97
// 'z' = 122

int main(void)
{
    char inputStr[100000] = "";
    // Get the input String
    scanf("%s", inputStr);
    int arrayOfSmallAlphabets[26]; // 26 alphabets in total
    int i = 0;
    int numericRepresentation = 0;
    int numOdd = 0; // can be at most 1

    for (i = 0; i < 26; i++)
    {
        arrayOfSmallAlphabets[i] = 0; // initialize all to 0
    }
    i = 0;
    while(inputStr[i] != '\0')
    {
        numericRepresentation = inputStr[i];
        arrayOfSmallAlphabets[numericRepresentation-97]++;
        i++;
    }
    // Loop through all characters and make sure at most 1 is odd number of them
    for (i = 0; i < 26; i++)
    {
        if(arrayOfSmallAlphabets[i]&0x1)
        {
            numOdd++;
            if (numOdd > 1)
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES"<< endl;
    return 0;
}
// */
//----------------------------------------------------------------------
/*
// 12 Lonely Integer
#include <iostream>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    int i = 0;
    int arrayOf100[101];
    for(i = 0; i < 101; i++)
    {
        arrayOf100[i] = 0; // initialize
    }

    int givenValues[N];

    for(i = 0; i < N; i++)
    {
        cin >> givenValues[i];
        arrayOf100[givenValues[i]]++;
    }

    for(i = 0; i < N; i++)
    {
        if(arrayOf100[givenValues[i]] == 1)
        {
            cout << givenValues[i] << endl;
            return 0;
        }
    }
    // should never be here
    return 0;
}
// */
//----------------------------------------------------------------------
/*
// 13 Manasa And Stones
#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
    return;
}

int main(void)
{
    int T;
    cin >> T;
    int i = 0, j = 0;
    int n = 0;
    int a = 0;
    int b = 0;
    for (i = 0; i < T; i++)
    {
        cin >> n >> a >> b;
        if ( a > b)
        {
            swap(&a,&b);
        }
        // Corner Case if a == b
        if (a == b)
        {
            int sum = a*(n-1);
            cout << sum << endl;
            continue;
        }
        // here, guaranteed a < b
        for(j = n-1; j >= 0; j--)
        {
            int sum = a*j + b*(n-1-j);
            cout << sum;
            if (j != 0)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}
// */
//----------------------------------------------------------------------
/*
// 14 ACM ICPC Team
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int N; // number of people
    int M; // number of topics

    cin >> N >> M;
    // Initialize the string for each array
    string lines[N];
    // Read each line as a string
    int i = 0, j = 0, k = 0;
    getline(cin,lines[0]); // remove the first line with newline
    // Read each line as a string and convert them into their binary equivalents
    char* temp;
    for (i = 0; i < N; i++)
    {
        getline(cin,lines[i]);
    }
    string combined; // stores the combination

    int numMax = 0; // initialize numMax to 0
    int maxValue = 0; // initialize the max value to 0
    i = 0; j = 0; k = 0;
    int numOnes = 0;
    for (i = 0; i < N - 1; i++)
    {
        for (j = i+1; j < N; j++)
        {
            // Or both values
            for(k = 0; k < M; k++)
            {
                if (lines[i][k] == '1' || lines[j][k] == '1' )
                {
                   combined.replace(k, k, "1");
                   numOnes++; // increment here so dont have to loop twice
                }
                else
                {
                    combined.replace(k, k, "0");
                }
            }
            // Note: You had a countOnes here before which does not make it more asymptotic
            // but you had to do twice the number of passes which is too slow
            // Thus, lesson learn is always execute as much as you can in the for loop itself
            // for faster execution.
            // count number of ones
            if (numOnes >= maxValue)
            {
                if (numOnes == maxValue)
                {
                    numMax++;
                }
                else
                {
                    numMax = 1; // initialize numMax to 1
                    maxValue = numOnes;
                }
            }
            numOnes = 0; // reinitialize
        }
    }
    cout << maxValue << endl << numMax << endl;

    return 0;
}
// */
//----------------------------------------------------------------------
/*
// 15 Chocolate Feast
#include <iostream>
using namespace std;

int main(void)
{
    int T, N, C, M;
    cin >> T;
    int i = 0;
    for(i = 0; i < T; i++)
    {
        // N = Money available,, C = cost, M = number needed before can get 1 free
        cin >> N >> C >> M;
        int amountBought = N/C; // get numChocolate
        int originalAmountBought = amountBought;
        int freebies = originalAmountBought/M; // use wrappers to get new chocolates
        amountBought += freebies; // add new chocolates
        freebies += (originalAmountBought%M); // add unused wrappers with new wrappers

        while (freebies >= M)
        {
            int newChocolates = freebies / M;
            amountBought += newChocolates;
            // get new number of wrappers available
            freebies = newChocolates + freebies%M;
        }
        cout << amountBought << endl;
    }
}
//*/
//----------------------------------------------------------------------
/*
// 16 Sherlock And Squares
#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    int T;
    cin >> T;
    int i = 0;
    int lb, ub; // lower bound and upper bound
    for(i = 0; i < T; i++)
    {
        cin >> lb >> ub;
        int minSqrt = ceil(sqrt(lb));
        int maxSqrt = sqrt(ub); // floor
        cout << (maxSqrt - minSqrt) + 1 << endl;
    }
}
// */
//----------------------------------------------------------------------
/*
// 17 Filling Jars
#include <iostream>
using namespace std;
// Note:  must use unsigned long long int for this problem.
int main(void)
{
    unsigned long long int N, M;
    cin >> N >> M;
    int i = 0;
    unsigned long long int total = 0;
    unsigned long long int lb, ub, cost;
    for(i = 0; i < M; i++)
    {
        cin >> lb >> ub >> cost;
        total += ((ub-lb)+1) * cost;
    }
    cout << total/N << endl;
}
//----------------------------------------------------------------------
/*
// 18 Sherlock And The Beast
#include <iostream>
using namespace std;

int main(void)
{
    int T, N;
    cin >> T;
    int i = 0;
    for(i = 0; i < T; i++)
    {
        cin >> N;
        int numOf5 = 0;
        int numOf3 = N/3;
        int remainder = N%3;
        // note: Remainder has to be less than 3 here
        while(remainder != 0 & numOf3 >= 0)
        {
            numOf3--;
            remainder += 3;
            if(remainder % 5 == 0)
            {
                numOf5 = remainder/5;
                remainder = 0;
            }
        }
        if (numOf3 < 0)
        {
            cout << -1;
        }
        else
        {
            int j = 0;
            for(j = 0 ; j < numOf3; j++)
            {
                cout << 555;
            }
            for(j = 0; j < numOf5; j++)
            {
                cout << 33333;
            }
        }
        cout <<endl;
    }
}
// */
//----------------------------------------------------------------------
/*
// 19 Sherlock And GCD
// Easy: basically need to solve for gdc = hcf of all the numbers and true if it exists and false otherwise.

#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}
// Based on Euclid's algorithm
int gcd(int a, int b)
{
    int temp;
    if (a > b)
    {
        swap(&a, &b);
    }
    // assume a <= b always
    while (a != 0)
    {
        temp = a; // save the current lowest
        a = b%a;  // get the new lowest
        b = temp; // restore the previous lowest
    }
    return b; // return the lowest that resulted in the mod to be 0
}

int main(void)
{
    int T, N;
    cin >> T;
    int i = 0;
    for(i = 0; i < T; i++)
    {
        cin >> N;
        int values[N];
        int j = 0 ;
        cin >> values[0];
        int gcdValue = values[0];
        for (j = 1; j < N; j++)
        {
            cin >> values[j];
            gcdValue = gcd(values[j],gcdValue);
            if (gcdValue == 1)
            {
                cout << "YES" << endl;
                // flush everything on current line
                // Note: Need to add j++ at beginning of for loop to iterate to next iteration.
                for (j++ ; j < N; j++)
                {
                    cin >> values[j];
                    // will break here
                }
            }
        }
        if (gcdValue != 1)
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
// */
//----------------------------------------------------------------------
/*
// 20 Angry Professor
// Time Complexity, T(n) = O(n)
// Space Complexity, S(n) = O(1)

#include <iostream>
using namespace std;

int main(void)
{
    int T, N, K;
    cin >> T;
    for(int i = 0; i < T ; i++)
    {
        cin >> N >> K;
        unsigned int count = 0;
        int temp;
        for(int i = 0; i < N; i++)
        {
            cin >> temp;
            // If arrive before class starts
            if (temp <= 0)
            {
                // Increase number of students present in class
                count++;
            }
        }
        // If less than K students present, cancel time of start of class
        if(count < K) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
// */
//----------------------------------------------------------------------
/*
// 21 Two Strings
// Time Complexity, T(n) = O(n)
// Space Complexity, S(n) = O(n)
#include <string>
#include <cstring> // for memset
#include <iostream>
using namespace std;

int main(void)
{
    unsigned int T;
    cin >> T;

    // note: Only lower case letters considered
    // 'a' = 97
    string temp1, temp2;
    for(unsigned int i = 0; i < T; i++)
    {
        int letters[26]; // 26 alphabets
        memset(letters,0,sizeof(letters)); // to set an array to 0
        int k = 0;
        bool found = false;
        cin >> temp1 >> temp2;
        for(int i = 0 ; i < temp1.length() ; i++)
        {
            k = temp1[i] - 97;
            letters[k]++;
        }
        for(int i = 0 ; i < temp2.length() ; i++)
        {
            k = temp2[i] - 97;
            if(letters[k] > 0)
            {
                cout << "YES" << endl;
                found = true;
                break;
            }
        }
        if(!found) cout <<"NO" << endl;
    }
}
// */
//----------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------
// FIXME:
//------------------------------------------------------------------------------------------------------------------
// 3 Is Fibo
// Problem is that Fibonacci number overflows when it gets too large for the function below
/*
// Failed Attempt:
#include <stdio.h>
#include <stdlib.h>

#include <math.h>

#define DEBUG 1

// Problem: Value is too high and overflows from fibonacci
// Note: Starts from 0,1,1,2,3,5,8,13 where n = 0 => 0
unsigned long long int fib(int n)
{
    unsigned long long  x = 0;
    x = (1.0/(double)(sqrt(5))) * (pow(((1.0+sqrt(5))/(double)2), n) - pow(((1.0-sqrt(5))/(double)2),n));
    return x;
}

unsigned long long int  power(unsigned long long int base, unsigned long long int exponent)
{
    unsigned long long int n = exponent;
    unsigned long long int a = base;
    if ((n == 0) || (a == 1))
        return 1;
  //  if (n > 0)
    unsigned long long int   b = power(a, floor(n/2));
    if (n%2 == 0)
    {
        return b*b;
    }
    else
    {
        return b*b*a;
    }
}

// n:    0,1,2,3,4,5,6,7, 8
// need: 0,1,1,2,3,5,8,13,21
int main(void)
{
     unsigned long long int limit = power(10,10);
#ifdef DEBUG

       printf("limit %llu \n", limit);
#endif
    unsigned long long int  tail =  limit;
    unsigned long long int  head = 0;
    int T, N;
    scanf("%d", &T);
    int i = 0;
    for(i = 0; i < T; i++)
    {
        scanf("%d", &N);
        // Corner case
        if(N == 0)
        {
            printf("IsFibo\n");
            continue; // move to next iteration
        }
#ifdef DEBUG
        printf("Head: %llu  Tail: %llu  \n", head, tail);
#endif
        while(head < tail)
        {
            unsigned long long int  middle = (head+tail)/2;
            unsigned long long int  value = fib(middle);
            if (value == N)
            {
                printf("IsFibo\n");
                // Make sure head wasn't equal to tail
                head = 0;
                tail = limit;
                break;
            }
            // note: value == 0 to handle overflow of fibonacci
            else if (value > N || value == 0)
            {
                tail = middle;
            }
            else // value < N
            {
                head = middle + 1;
            }
#ifdef DEBUG
            printf("Head: %llu  Tail: %llu Middle: %llu  Value: %llu \n", head, tail, middle, value);
#endif
        }
        if (head >= tail)
        {
            // this means value was not found
            printf("IsNotFibo\n");

        }
        // Re-initialize
        tail =  limit;
        head = 0;
    }
    return 0;
}
*/
//------------------------------------------------------------------------------------------------------------------
/*
// THIS DOESNT WORK CAUSE 64 BITS LIMITATIONS
// 14 ACM ICPC Team TODO: Doesnt work on large inputs
// Note: Below doesnt work for M > 64.
// Thus, need to recode it using arrays.
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

// This function counts number of bit-1 in integer k for for numBits's LSB
int countOnes(unsigned long long int k, int numBits)
{
    int i = 0;
    int count = 0;
    int temp = k;
    for(i = 0; i < numBits; i++)
    {
    //    cout << "temp is " << temp << endl;
        if (temp & 0x1)
        {
            count++;
        }
        temp = temp >> 1; // right shift by 1
    }
    return count;
}

int main(void)
{
    int N; // number of people
    int M; // number of topics

    cin >> N >> M;
    // Initialize the string for each array
    unsigned long long int data[N]; // initialize the data for each person and their topics
    string lines[N];
    // Read each line as a string
    int i = 0, j = 0;
    getline(cin,lines[0]); // remove the first line with newline
    // Read each line as a string and convert them into their binary equivalents
    char* temp;
    for (i = 0; i < N; i++)
    {
        getline(cin,lines[i]);
        // convert into base 2
        unsigned long long int  n = (unsigned long long int ) strtol(lines[i].c_str(), &temp, 2);  // string.c_str() = convert it into the C-string equivalent
        data[i] = n; // represent it as an integer
    }
    // now compare every two values and keep track of number of maximum

    int numMax = 0; // initialize numMax to 0
    int maxValue = 0; // initialize the max value to 0
    i = 0;
    j = 0;
    for (i = 0; i < N - 1; i++)
    {
        for (j = i+1; j < N; j++)
        {
            unsigned long long int combined = data[i] | data[j]; // or both values

            // count number of ones
            int numOnes = countOnes(combined, M);
          //  cout << "data 1 " << data[i] << " data 2 " << data[j] << " combined " << combined <<  " numOnes " << numOnes << endl;

            if (numOnes >= maxValue)
            {
                if (numOnes == maxValue)
                {
                    numMax++;
                }
                else
                {
                    numMax = 1; // initialize numMax to 1
                    maxValue = numOnes;
                }
            }
        }
    }
    cout << maxValue << endl << numMax << endl;
    return 0;
}
*/
