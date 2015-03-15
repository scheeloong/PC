//
//----------------------------------------------------------------------------------------
/* //
Table of Contents

1.

// */
//----------------------------------------------------------------------------------------

#include <queue>
    // q.empty()
    // q.size()
    // q.push(value) // push to end(back) of queue
    // q.pop() // pop from front of queue
    // q.front() // returns reference to the front element
    // q.back() // returns reference to the back element (last element added

#include <string>
#include <iostream>


using namespace std;

int main(void)
{
    queue<string> q;
    string temp = "hahaha";
    string temp2 = "baba";
    q.push(temp);
    if(!q.empty())
    {
        cout << q.front() << endl;
        cout << q.back() << endl;
    }
    q.pop();
    if(q.empty())
    {
        cout << "queue is now empty" << endl;
    }

    q.push(temp);
    q.push(temp2);
    cout << "number of elements in queue is " << q.size() << endl;
    return 0;
}
//----------------------------------------------------------------------------------------
