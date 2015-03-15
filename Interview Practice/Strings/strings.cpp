//----------------------------------------------------------------------------------------
/*
Table of Contents

1. Reverse a string In-Place

2. Determine if every character in string is unique

3. Determine if every character in string is unique using Bit Manipulation (only from 'a' to 'z')

4. Remove Duplicated characters of strings in place, T(n) = O(n^2), S(n) = O(1)

// Time Complexity, T(n) = O(n)
// Space Complexity, S(n) = O(1)
//----------------------------------------------------------------------------------------

TODO:

0. Implement compression of a string,
e.g. : aaabbbbbcccdeeefaabc

char* compress(char* inputStr);
// Note: You made the mistake of using arrays of characters and integers instead of outputting char *!!
// should have done: a3b5c3d1e3f1a2b1c1 instead!


0. Reading an input string of arbitrary size.
// Refer to hackerrank problem 6 "Alternating Characters" for solution. But code yourself first that was from online

0. A sentence has additional spaces between words, remove the additional spaces in place
eg: "hi  i     am paul" -> "hi i am paul"
Hint: 2 pointers, 1 to point to replace, one to search for more

1. Longest Common Substring Using Dynamic Programming
Note: This requires you to implement nested for loops in the form of a recursion
Which is a new skill to learn!

3. Longest Common Substring Using Suffix Trees for > 2 strings

4. Exact Matching using Suffix Trees (location of each substring)

5. Dictionary (Check if a string is found in the dictionary)

6. Finding all maximal palindromes in a String. (longest palindrome in a string)
a) Hint: Manacher algorithm T(n) = O(n), S(n) = O(n) // fastest
b) Dynamic Programming T(n) = O(n^2), S(n) = O(n^2)
c) Dynamic Programming noting mirros center T(n) = O(n^2), S(n) = O(1) // least space


7. Longest Increasing Subsequence

8. Longest Duplicated substring in a string.


9. Implement strspn function

10. Reverse a Sentence (Bloomberg Round 1)

11.

*/

//----------------------------------------------------------------------------------------
/*
// 1 Reverse a string in place
// Takes O(n) time
#include <stdio.h>
#include <string.h>
void reverseStr(char* word);

int main(void)
{
    char word[80] = "abcdefg";
    printf("%s\n", word);
    reverseStr(word);
    printf("%s\n", word);
    return 0;
}

void reverseStr(char* word)
{
    int n = strlen(word) - 1;
    int i = 0;
    for (i = 0; i < n; i++)
    {
        char temp = word[n];
        word[n] = word[i];
        word[i] = temp;
        n--;
    }
    return;
}

// Untested
void reverseStrMethod2(char* word)
{
    int n = strlen(word);
    int i = 0;
    for (i = 0; i < n/2; i++)
    {
        char temp = word[n-1-i];
        word[n-1-i] = word[i];
        word[i] = temp;
    }
    return;
}
*/
//----------------------------------------------------------------------------------------
/*
// 2 Determine if every character in a string is unique ( can be any character in ASCII)
// Below takes O(n) time
// Put into array, increment when found string, if that increment is > 1, that means string not unique.

// If can't use extra space, can
// 1. Loop through one by one and compare => O(n^2)
// 2. Destroy the string, sort it, and it takes O(nlgn + n) = O(nlgn)
            // nlgn to sort, n to loop and compare

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#define ASCII_LEN 128

bool uniqueStr(const char* word);

bool uniqueStr(const char* word)
{
    if (word == NULL)
        return true;
    int n = strlen(word);
    int table[ASCII_LEN];
    //int index[n];
    int i =  0;
    int j = 0;
    for (i = 0; i < ASCII_LEN; i++)
    {
        table[i] = 0;
    }
    for (j = 0; j < n; j++)
    {
        int value = word[j];
        table[value]++;
        if (table[value] > 1)
            return false;
    }
    return true;
}


int main(void)
{
    char* str1 = "abc";
    char* str2 = "abca";
    assert(uniqueStr(str1));
    assert(!uniqueStr(str2));
    return 0;
}

/* //
// Approach 2 using STL
#include <string>
#include <unordered_map>
#include <cstring>
#include <iostream>
using namespace std;
int main(void)
{
    string uniqueStr;
    cin >> uniqueStr;
    const char* temp = uniqueStr.c_str();
    unordered_map<char, int> table;
    int n = uniqueStr.size();
    for(int i = 0; i < n; i++)
    {
        table[temp[i]]++;
        if(table[temp[i]] > 1)
        {
            cout << " Not UNIQUE" << endl;
            return 0;
        }
    }
    cout << "UNIQUE" << endl;
    return 0;
}

// */
//----------------------------------------------------------------------------------------
/*
// 3 Determine if every character in a string is unique
// Simplification: only characters 'a' to 'z'
/ Takes O(n) time and saves a tonne of space but only works of from 'a' to 'z'

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
bool uniqueStr(const char* word);

int main(void)
{
    char* str1 = "abc";
    char* str2 = "abca";
  //  uniqueStr(str1);
  //  uniqueStr(str2);
    assert(uniqueStr(str1));
    assert(!uniqueStr(str2));
    return 0;
}

bool uniqueStr(const char* word)
{
    int n = strlen(word);
    unsigned int storage = 0;
    int i = 0;
    for (i = 0; i < n ; i++)
    {
        unsigned int shift = word[i] - 'a';
        unsigned int compare = 1 << shift;
        if (storage&compare)
        {
            printf(" I am false\n");
            return false;
        }
        storage |= compare;
    }
    printf("TRUE\n");
    return true;
}
*/
//----------------------------------------------------------------------------------------
/*
// 4. Remove Duplicated characters of strings in place
// Time Complexity, T(n) = O(n^2)
// Space Complexity, S(n) = O(1)

#include <string>
#include <iostream>
using namespace std;
int main(void)
{
    string duplicatedString;
    cin >> duplicatedString;

    int tail = 1;
    for(int i = 1; i < duplicatedString.size(); i++)
    {
        bool exists = false;
        for(int j = 0; j < tail; j++)
        {
            if(duplicatedString[i] == duplicatedString[j])
            {
                exists = true;
                break;
            }
        }
        if(!exists)
        {
            duplicatedString[tail] = duplicatedString[i];
            tail++;
        }
    }
    duplicatedString = duplicatedString.substr(0,tail);
    cout << duplicatedString;
    return 0;
}
// */
//----------------------------------------------------------------------------------------
