//----------------------------------------------------------------------------------------------------------------------------------
/*
Leave this here since harder version in actual folders
    1. Given an array of integers, every element appears twice except for one. Find that single one. T(n) = O(n), S(n) = O(1)
//---------------------------------

TODO: 
HARD DYNAMIC PROGRAMMING: Buy and sell stock at most k times. Max profit? T(n,k) = O(nk), S(n,k) = O(n,k)
Morris Traversal = Given a binary tree, return the inorder traversal of its nodes' values iteratively with constant space. T(n) = O(n), S(n) = O(1)
HARD: Product of array excluding itself without using division '/' operator
    [2,3,5,6] => [90,60,36,30] (Must can use constant space, excluding the O(n) space to store result)

25. Given an array of integers, every element appears thrice except for one. Find that single one. T(n) = O(n), S(n) = O(1)
//---------------------------------
Note: 
The difference with using LeetCode is you also practice:
    Asking questions about the problem. Can there be (-) index
    What exactly does reference indexing mean? 
ALWAYS: 
    Questions:  Clarify problem, check assumptions, int(limit? (-)? number of integers? can modify array?, repeated? )
        -
        -
        -
    Test Case: Give a simple test case that covers edge cases (so fewer numbers but covers enough), give the basic test case , n = 1
        - 
        -
        -
    Algorithms: Discuss the different methods to solve and complexity. 
        Sort(nlgn), ... 
        Heap().... 
        HashTable()... 
    Check algorithm by running input over it and finding error code. 
*/
//----------------------------------------------------------------------------------------------------------------------------------
// 1 Given an array of integers, every element appears twice except for one. Find that single one. T(n) = O(n), S(n) = O(1)
/*
Questions:
    Is there a limit to the number of integers given? No
    Can the integers be (-) ? Yes
    How large can the integers be? (use counting sort and then can do a pass with O(n) timing. 
        As large as can be represented in memory 
    Can the same number appear 2z times instead of twice? where z is an integer > 0	
        Yes
    Are the inputs sorted already? 
        No 
Test cases: 
    23253
    1
*/
//---------------------------------
/*
#include <iostream> 
#include <cstdlib> 
#include <cstdio> 
#include <vector>
#include <algorithm> 
using namespace std;

int returnSingle(vector<int>& nums)
{
    int single = 0; 
    for(int i = 0; i < nums.size(); i++)
    {
        single = single ^ nums[i];
    }
    return single; 
}
int main(void)
{
	vector<int> a(5,0); 
	a[0] = 2; 
	a[1] = 3; 
	a[2] = 2; 
	a[3] = 5; 
	a[4] = 3; 
	int result = returnSingle(a); 
	cout << result << endl;
	return 0;
}
// */
//----------------------------------------------------------------------------------------------------------------------------------
