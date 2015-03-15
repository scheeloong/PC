// Interview Practice
// This file is like a rough paper
// 1. To practce previous programming questions
// 2. To practice new programming questions before documenting into other files
//-----------------------------------------------------------------------------------------------]




//-----------------------------------------------------------------------------------------------
// For Interviews online, you need to be able to code it.
// Thus, you need to use Standard Template Library as copying pasting your own previous code is not acceptable
// Therefore, need use C++'s STL

// Need to know how to

// stable_sort()
// reverse() // to sort in reverse order
// binary search()
// work with hash tables, stack, queue, linked list, binary tree, heap
// i) Insert
// ii) Delete
// iii) Traverse
// iv) Search
// v) Max? Min?
//

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


//-----------------------------------------------------------------------------------------------
// Longest Common Substring
// Approach 1: Dynamic Programming
// Time Complexity, T(n,m) = O(nm)
// Space Complexity, S(n,m) = S(nm)

//------------------------------------------------------------------------------------------------
/*
Add to numerical methods or mathematics
#include <iostream>
using namespace std;
#include <stdio.h>
double sqrtEstimate(double no)
{
    #define PRECISION 0.00001
    double l = 1, h = no, m = 0;
    while(h - l > PRECISION)
        {
        m = l + (h - l) / 2;
        if(m * m - no > PRECISION)
            h = m;
        else
            l = m;
    }
    return m;
}
int main(void)
{
    double a = sqrtH(9);
    cout << a << endl;
        return 0;
}
*/

/*

1. Find largest gap between 2 numbers in an unsorted array
where index of max is greater than min.
2.Find average of an array after removing min and max
-Loop and add and keep track of min and max
-deduct both and divide by n-2

3. Find number of zeroes in a number factorial
4. Reverse a string in place in C

5. Default constructor
6. Catching and Exception
7. *string  (*string+4 ) and type
8. Validate if tree is a binary search tree
- inorder traversal and make sure never decreases
9. Check if 2 tree are the same by
in order traversal and making sure
each value outputted is the same, need termination.
10.

Array and Linked List
1. Find Nth Element of LinkedList
2. Check if an array of int contains
2 numbers that sum equal to target number
Pointers and Strings in C
4. add last n elements for new fibonacci instead of 2
6. Josephus problem
7. Find all anagrams of a given word
8. Reverse a linked list
9.
Constructor, Destructor, Multithreading
C++ questions!
10. An array,
loop through it and tell when to buy and
sell for largest profit,
buy has to come before sell
11. Detect when 2 singly linked list converge
12.
Difference between
const char *
&
char* const

13. Rotate string by k elements
to right in place
14. Longest palindrome in string
15.
Given 2 large numbers
that cannot be stored in 64 bit,
how to calculate final product?
16.
print 2d matrix spirally

*/

// Let N = range of values given
// N = R-L+1
// then, total possible combinations is N choose 2 + N
// Example, N = 6 => N choose 2 + N = 15 + 6 = 21
// + N cause every value can be with itself

// Note: Can eliminate the N since a number XOR itself is always 0
// thus, initialize max to 0 and if a value is same with itself, don't bother comparing


 // */
//----------------------------------------------------------------------------------------

/*
// Low Level Programming
int main(void)
{
    unsigned short i, j;  // short makes it 16 bits
    i = 13;
    j = i << 2; // shift bits of i to left by 2 appending 0
    j = i >> 2; // shift bits of i to right by 2

    // If only manipulate 1 variable
    i <<= 2; // shift bits of i to left by 2
    i >>= 2; // fhits bits of i to right by 2
    j = ~i; // bitwise NOT
    j = i ^ i; // xor
    j = i | i; // or
    j = i & i; // bitwise and
    struct file
    {
        unsigned int day: 5;            // 5 bits for day
        unsigned int month: 4;          // 4 bits for month
        unsigned int year: 7;           // 7 bits for year e
    };
    // Note: i << 2 + 1 means i << (2+1)
}
*/

//----------------------------------------------------------------------------------------

/*
int main(void)
{
    // haha
//    int 100_bottles;
    int _100_bottles;
    int one_hundred_bottles;
    int bottles_by_the_hundred;
    return 0;
}
*/
//----------------------------------------------------------------------------------------
void swap(int ab[], int a, int b)
{
    int temp = ab[a];
    ab[a] = ab[b];
    ab[b] = temp;
}
// */

//----------------------------------------------------------------------------------------
// Practice 4: Template




//----------------------------------------------------------------------
 //
/*
// Type of Interview Questions
// 1. OOP Design Principles (Amazon, Bloomberg)
    // - need know how to implement OOP!!!!!
    // e.g. Garbage Collection Analysis!!
        // Just define a baseclass that keeps track of number of objects created (it has to be static)
        // Then, each time create or destroy, we incremement and decrement the reference counter!
        // Note: All the childs' constructor and destructor must call this super class to do reference counting.
        // Then, can easily keep track of which objects are not freed from memory.

// 2. Algorithms (All Companies)
    // - all the usual algorithms questions
// 3. C++ Language Specific (Bloomberg)
    // - what does static, const, volatile, virtual, mutable, explicit, friend  keywords do?
    // - Perform multiple inheritance, its problems, and when it is used?
    // - Perform operator overloading
    // - Implement copy constructor
    // - What are the constructors initialize if none is defined by user?
    // - Reference vs Pointers


1) Object Oriented Design Principles
//----------------------------------------------------------------------
DESIGN PROCESS
//----------------------------------------------------------------------
QUESTIONS, THINK, DO, TEST

//----------------------------------------------------------------------
A) QUESTIONS
//----------------------------------------------------------------------
// What extra/specific functionalities?
// What is the problem I am trying to solve?
// What do I need to implement

//----------------------------------------------------------------------
B) THINK
//----------------------------------------------------------------------
// What is general? What is specific?  (general=> base class, specific => child class
// Is A? Has A?
// Design Top-Down approach!

// Run through list of design principles to see which fit:
    // - Singleton
    // - Observer (with Subscribers)
    // - Factory (which class to instantiate objects)
    // - Strategy (methods that are shared across many class and can be changed)
    // - Iterator

//----------------------------------------------------------------------
C) DO
//----------------------------------------------------------------------
// Just write out method prototypes and class prototypes first before implementing anything!
//      It is impossible to implementing everything in that 45 minutes of interview


2) Algorithms & Data Structures
//----------------------------------------------------------------------
DESIGN PROCESS
//----------------------------------------------------------------------
QUESTIONS, THINK, DO, TEST
QUESTIONS
- Clarify with example problem and the final solution
- Clarify with function prototype, Clarify Return Value!! (IBM Round 1 compress string)
- Clarify what it is used for.
- For programming competitions: Read the question properly!
THINK => TEST_CASES, DESIGN, COMPLEXITY
- Come up with test cases, does it work for +, -, 0? (VERY IMPORTANT STEP)
- Come up with a solution, test for complexity
- Come up with a better solution, test for complexity and compare
- Can you do this recursively? Can you do this iteratively?
- Check solution with all the test cases
DO
- Implement solution
TEST
- Check solution again
//----------------------------------------------------------------------
A) QUESTIONS
//----------------------------------------------------------------------

1. Is there a maximum limit to the sequence?
- If there is, can do logN solution by always looking at middle element and dividing by 2
- If the number is too large but less than 2^64, use unsigned long long int instead of just int

2. How large are the values?
- If anything more than x (determine later)
use unsigned long long int so that computation is correct for large values

Refer to below for exact value ranges
http://www.cplusplus.com/reference/climits/


3. Will the integers ever be negative?
If it doesn't , use unsigned int!

4. If given multiple input values, what happens if the input were given the same values?
(e.g. for questions that relies on combination and permutation of inputs)

5. If given a binary number as an input (string), will the binary ever be more than 64 bits?

//----------------------------------------------------------------------
B) THINK
//----------------------------------------------------------------------
1. Integer Handling
- Works with positive numbers?
- Works with negative numbers?
- Works with 1 digit?
- Works with 0?
- Works with multiple digits? unsigned

2. Array Handling
- Does sorting help make the algorithm better?

3. Bit Manipulation
- If I have a Bit Manipulation algorithm, does it require more than 32/64 bits?
    If it does, I cannot use bit manipulation.
- Is the signed bit important ? Yes => 32 bits only, No => declare unsigned => 64 bits
- Can result be larger than what 32(signed)/64(unsigned) bits can hold?
//----------------------------------------------------------------------
C) DO
//----------------------------------------------------------------------
- Don't assume your variables / arrays are initialize to 0 , initialize them yourself!
- For loop iterator, (i or j etc.) must be same type as condition being compared to (N)
    // if N is unsigned int, for loop i has to be unsigned int as well
- If adding contiguously,
    // e.g. 1 2 3 4 5 => 1 3 6 10 15
    // instead of for looping and adding, just add each next one with the new value read with previous
    // for loop => O(n^2), add previous => O(n)
- When working with unsigned, the value can never be < 0!! So cannot terminate when j < 0 cause j will never be < 0!!
    // also careful with starting loops with N-2, cause if N is 1 then value will be 1-2 = very large (+) number!
// */
//----------------------------------------------------------------------
/* //
// Ways to Become the Best Programmer
1. Understand, Augment, Create algorithms & data structures
2. Code on paper (from memory => Memorize syntax)
3. Solve programming challenges within 30 minutes
4. Fix other people's bugs (Stack Overflow -> Use it like piazza)
5. Create new algorithms to solve problems.
6. Solve problems flexible (time & space tradeoffs)
7. Contribute to open source (code daily)
8. Write test cases for own code (C: Check, Java: Junit)
9. Write test cases within development code using compiler primitives (e.g. #ifdef DEBUG assert(i == 1); #endif)
10. Code for fun! (code sudoku game, payment at restaurants)
11. Use debugger (C: GDB, C: Valgrind)
12. Use Software Tools (Compilation, Documentation, Source Control) (C: Makefile, C: Doxygen, GIT, Subversion)
13. Code modularity & portability (Classes, Helpfer Functions, Templates, Function pointers, Variable argument)
14. Hack into programs (e.g. Try to hack into Diablo)
15. Combine multiple languages together (Matlab, C++, JAVA, C, Android)
16. Profile code for speed & space optimality
17. Find out things about system (ECE344 Bonus Assignment)
18. Ability to reduce problems to existing ones ( Max consecutive words -> Max substring , Reverse Words -> Reverse strings)
19. Ace Programming Interviews (speak out loudly)
20. Parallelize code (Threads, Processes, Scheduling)
21. Throw and Exception Handling
22. Analyze how many time you would hit a function and reconsider if need to put inside while loop
23. Perform garbage collection analysis the right way.
24. Master OOP Design patterns
25. Join hackathons and business plans, join hackerrank competitions!
26. Focus on graphical user interface designs to make work a marketable product.
27. Read and perform code reviews on stack exchange.
http://codereview.stackexchange.com/
28. Master OOP with Design Patterns and understand all Design Patterns that exists.
29. Follow GitHub Users with lots of followers for a specific technology/language.


// */
//----------------------------------------------------------------------
//

/*

// Using GDB on terminal
Commandsxs
print j  // print variable j
watch z // break when variable z changes value
watch (z > 28) // break when variable z is more than 28
                // note: Watching local variable is canceled as soon as variable goes out of scope
                // Thus, will normally only watch global variables or local variables in main()
up // brings you to function that called this function
down // brings you to function that is called
     // Changing stack frames will change the value of the local variable at that frame
backtrace // shows entire collection of stack currently in existence
help breakpoints // access documentation of gdb's commands such as breakpoints

// Using compilation on terminal
gcc -g -Wall -o programName main.c // Note: -g command is needed to store symbol table used during gdb sessions


// */
//----------------------------------------------------------------------

/*
//----------------------------------------------------------------------
// Lessons Learnt
//----------------------------------------------------------------------
//----------------------------------------------------------------------
// Note:
This file is where you code things temporarily again from whatever you have coded before

1. Can only use sizeof(ab)/sizeof(ab[0]) when ab is a variable, NOT a parameter

int main(void)
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(a)/ sizeof(a[0]) ; // correct this gives you 10,
    someFunction(a);

}

// inside someFunction();
someFunction(int a[])
{
    //WRONG!!!!!!!!! CAN'T USE SIZEOF from AN ARRAY PARAMETER
    int n = sizeof(a)/ sizeof(a[0]) ;
}

Solution:
// inside main
someFunction(a, sizeof(a)/sizeof(a[0]));
someFunction(int a[], int n)
{

}
//----------------------------------------------------------------------
Notes:
1. Remember to write: using namespace std; // with #include <iostream>
2. Remember to check for correct output in main() after calling the function!
3. It's swap(arrayVar, j, j+1) NOT swap(arrayVar, arrayVar[j], arrayVar[j+1])
4. if define, int main(void), always remember to return 0!! or any integer
5. In forloop, it's (int j = 0; j< something; j++) NOT (int j = 0; something; j++)!!!
6. When have nested for loops and while loops, make sure remember to close and open curly braces properly!
7. set an entire array to 0 using  memset(arrayName,0,sizeof(arrayName)); // to set an array to 0
    // memset() is defined in <string.h>
*/

//----------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------
/* //
// Bloomberg Interview Round 1

Ahmed Bloomberg  (Indian??)

#include <string.h>  // for strlen(), strcpy()
#include <stdlib.h> //
#include <iostream>
using namespace std;

int main() {
    return 0;
}

// Returns number of words allocated
// Parameters:
//      @)
// Assume strArray is allocated
int seperateString(char* string, char** strArray)
{
    int n = strlen(string);
    // Allocating memory for strArray Maximum of n/2 words
    // Maximum number of words is n/2 " a b c "
    strArray = malloc(sizeof(char*) * (n/2)); // to point to each word
    int count = 0;  // number of words in string
    // To check for last word without spaces
    bool haveWord = false; // new character part of a word that is not saved yet
    int i = 0;
    // Get rid of initial spaces in beginning
    while(string[i] == ' ')
    {
        i++; // go to the first word and skip all the initial spaces
    }

    string = &string[i]; // repoint string to after spaces
    for( ; i < n; i++)
    {
        // " abc  "
        // one space
        if(string[i] == ' ')
        {
            string[i] = '/0'; // close this into a word

            // Get the length of the word just made
            int lenWord = strlen(string); // this will be a shorter length due to closing string

            strArray[count] = (char *)  malloc(sizeof(char) * lenWord);
            strcpy(strArray[count], string);
            string = &string[i+1]; // point it to the next word

            // "quick     brown"
            while(string[i] == ' ')
            {
                i++; // go to the next word and skip all the spaces
            }
            string = &string[i]; // repoint string to after spaces
            count++; // increment number of words
            haveWord = false;
        }
        // Case where it is not a space
        else
        {
            haveWord = true;

        }
    }
    // " hello   "
    // " hello'\0'    "
    // "  hello"

    // To handle case for final word " hello"
    if(haveWord) // string[n] will already be '\0' by definition of the string
    {
        int lenWord = strlen(string); // this will be a shorter length due to closing string
        strArray[count] = (char *)  malloc(sizeof(char) * lenWord);
        strcpy(strArray[count], string);
        count++;

    }
    return count;
}

void reverseSentence(char* string)
{
    char** strArray;


    // Returns number of words that was separated
    int n = seperateString(string, strArray);
    for(int i = 0; i < n/2; i++)
    {
        // Swap it
        swap(strArray[i], strArray[n-i-1]);
    }
    // It just basically merges all the array of strings
    // into a single string, separated by a " "
    mergeString(strArray, string);
    // Separate and swap
    // T(n) = O(n + k ) = O(n) , n = length of string
                                // k = number of words in string
    // merging takes
    // T(n) = O(n);
    // S(n) = O(n);

    // " a boy is good "
    // " " -> delimiter
    // "a" "boy" "is" "good"
    // "good"

}

//Examples
//" the quick      brown fox jumps over the lazy dog " becomes "dog lazy the over jumps fox brown quick the".
//"hello world" becomes "world hello".
//“ Hi! ” is trimmed to “Hi!”.
//“” stays as “”.


//---------------------------------------------------------------------------------------------------
// */

