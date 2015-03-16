/*
PROG: ride
LANG: C++
*/
// Note: You need the above in order to be able to submit to this USACO thing 
#include <fstream> 
#include <string.h> 
#include <string> 
#include <iostream> 
using namespace std; 
int main()
{
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a, b; 
    fin >> a >> b;
    const char* c;
    const char* d; 
    c = a.c_str(); 
    d = b.c_str(); 
    int k = 1; 
    int l = 1; 
    for(int i = 0; i < strlen(c); i++)
    {
        k *= ( c[i] - 'A' + 1); 
      //  fout << " k is " << k << endl; 
    }
    for(int i = 0; i < strlen(d); i++)
    {
        l *= ( d[i] - 'A' + 1);
    //    fout << " l is " << l << endl; 
    }
    k = k%47; 
    l = l%47; 
   // fout << " k is " << k << " l is " << l << endl; 
    if(k == l)
    {
        fout <<"GO" << endl; 
    }
    else
        fout <<"STAY" <<endl; 
    return 0;
}
