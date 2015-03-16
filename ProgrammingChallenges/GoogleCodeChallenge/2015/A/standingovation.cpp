#include <fstream> 
#include <cstring>
#include <string> 
#include <iostream> 
using namespace std;

int main(int argc, char** argv)
{
    ofstream fout;
    ifstream fin; 
    fin.open(argv[1]);
    fout.open(argv[2]);
    int T; 
    fin >> T; 
    for (int i = 0; i < T; i++)
    {
        unsigned long long int Smax = 0; 
        fin >> Smax;
        string currString; 
        fin >> currString; 
        const char * st = currString.c_str(); 
        unsigned long long int count = 0; 
        unsigned long long int numNeeded = 0; 
        for(unsigned long long int j =0; j <= Smax; j++)
        {
            if(st[j] != '0')
            {
                if(count < j)
                {
                    numNeeded += j - count; 
                    count = j;
                    count += st[j] - '0'; 
                }
                else
                {
                    count += st[j] - '0'; 
                }
            }
                
        }
        fout <<"Case #" << i+1 <<": " << numNeeded << endl; 
    }
    return 0; 
}
