/*
PROG: test
LANG: C++
*/
// Note: You need the above in order to be able to submit to this USACO thing 
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
