#include <fstream> 
#include <cstring>
#include <string> 
#include <iostream> 
using namespace std;

// note: Only solves the small input case 
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
        // Initialize to Richard 
        int person = 0; // 0 = Richard, 1 => Garbield 
        unsigned long long int X, R, C; 
        fin >> X >> R >> C; 
        if (X == 1)
        {
            person = 1; // will definitely be Gabriel
        }
		else
		{
			if( ((R*C) % (X*X) == 0)|| ((R*C) % (X*(X-1)) == 0))
				person = 1;
		}
		/*
        else if(X == 2)
        {
            if (((R*C)%2) == 0)
                person = 1; 
        }
        else if (X == 3)
        {    
            if ((((R*C)%6) == 0) || ((R*C) == 9))
                person = 1; 
        }
        else if (X == 4)
        {
            if (R*C == 12 || R*C == 16)
                person = 1; 
        }
		*/
        // Output solution 
        fout <<"Case #" << i+1 <<": ";
        if (person)
            fout << "GABRIEL";
        else
            fout <<"RICHARD"; 
        fout << endl; 

    }
    return 0; 
}
