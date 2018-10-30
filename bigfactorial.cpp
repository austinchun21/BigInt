/**
 * bigfactorial.cpp
 * 
 * Calculate large factorials
 */

#include "bigint.hpp"
#include <iostream>
#include <time.h>

using namespace std;

// Print the BigInt (technically in reverse order) as an decimal number
std::ostream& operator<<(std::ostream& out, BigInt& b){
    b.print(out);
    return out;
}

void bigFactorial(int n, vector<BigInt>& DP)
{
    for(int i=DP.size(); i<n+1; ++i){
        BigInt bi (i);
        DP.push_back( bi*DP[i-1] );
    }
    cout << "Ans: " << DP[n] << endl;
}


int main()
{
    clock_t t1, t2;

    vector<BigInt> DPtable = {1, 1}; // Initialize 0! and 1!
    cout << "Starting BigFactorial(). Input '-1' to exit program" << endl;
    while(1){
        int n;
        cout << "  What factorial would you like to calculate? (0-1000): ";
        cin >> n;
        t1 = clock();
        if(n == -1)
            break;
        if(n<0 || n>1000){
            cout << "    Invalid Input - Please Choose an integer between 0 and 1000";
        }

        bigFactorial(n, DPtable);
        t2 = clock();
        cout << "    Time: " << (double)(t2-t1) / CLOCKS_PER_SEC << endl;
    }

    return 0;
}


