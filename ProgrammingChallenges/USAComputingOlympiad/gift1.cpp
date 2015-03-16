/*
PROG: gift1
LANG: C++
*/
// Note: You need the above in order to be able to submit to this USACO thing 

// Greedy Gift Givers 
// TODO: 
// easy, just store the names given in an array, 
// for each name, hash into a hash table with value 0
// then, for each new giver name, deduct the (initialvalue - initialvalue%numberofpeopletogive) 
// then, for each new receiver name, add the initialvalue/numberofpeopletogive
// after looping through all, go through name on array, 
// then get value from hash table and output line by line 
#include <fstream> 
#include <string> 
#include <iostream> 
using namespace std; 

int main()
{
    ofstream fout ("test.out");
    ifstream fin ("test.in");
    int a, b; 
    fin >> a >> b;
    fout << a+b << endl; 
    return 0;
}
