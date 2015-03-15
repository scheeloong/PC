//
//----------------------------------------------------------------------------------------
/* //
Table of Contents

1. Introduction to Stacks with C++ Standard Template Library
2.

TODO:
1. Find out if the braces, brackets open and close properly (Cast Software Interview)
2. Implement 3 stacks in one array
3. Implement to add more stacks when 1 stack is filled as well as add rollover
    // rollever => If delete from lower stacks, need shift all elements from upper stacks down
4. Code Tower of Hanoi solution using stacks
5. Stack that has the ability to return min. element (Bloomberg 2nd round)
note: Your solution was not the best, the best it to have a 2nd array for mins
and whenever you pop a value that is the same as the current min, you pop the min as well
or when you add a value lower than current min, you push to the 2nd array's min.
6. Implement a queue using 2 stacks
7.


// */
//----------------------------------------------------------------------------------------
// 1. Introduction to Stacks with C++ Standard Template Library
#include <iostream>
#include <stack>
    // s.push(value)
    // s.top()
    // s.pop()
    // s.size()
    // s.empty()
    // s1.swap(s2)
        // swap 2 stacks with each other

using namespace std;

int main(void)
{
    // values of the stack
    stack<int> s;
    s.push(3);
    if (!s.empty())
    {
        // is peeking the top element
        cout << s.top()  << endl;
    }
    s.pop(); // no return values
    if(s.empty())
    {
        cout << "Stack is empty" << endl;
    }
    s.push(4);
    s.push(5);
    cout << "Number of elements in stack is " << s.size() << endl;
    return 0;
}
//----------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------
