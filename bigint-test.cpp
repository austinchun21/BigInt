#include "bigint.hpp"
#include <iostream>
#include <string>

using namespace std;

// Print the BigInt (technically in reverse order) as an decimal number
std::ostream& operator<<(std::ostream& out, BigInt& b){
    b.print(out);
    return out;
}

void testSmallAdd()
{
    cout << "- Small Addiition Test" << endl;
    string sa = "913453";
    string sb = "183457";

    int ia = stoi(sa);
    int ib = stoi(sb);
    int ic = ia+ib;
    string sc = to_string(ic);

    BigInt a (sa);
    BigInt b (sb);

    // Addition
    BigInt c = a+b;

    cout << "    Int Add:    " << sc << endl;
    cout << "    BigInt Add: " << c << endl;

    // cout << "a: " << a << endl;
    // cout << "b: " << b << endl;
    // cout << "c: " << c << endl;
}

void testBigAdd()
{
    cout << "- Big Addiition Test" << endl;

    BigInt a ("913456452443535263453");
    BigInt b ("183462345435645663457");
    // Addition
    BigInt c = a+b;

    cout << "    a:   " << a << endl;
    cout << "    b:   " << b << endl;
    cout << "    a+b: " << c << endl;
}

void testSmallMult()
{
    cout << "- Small Multiply Test" << endl;
    string sa = "123456";
    string sb = "978";

    int ia = stoi(sa);
    int ib = stoi(sb);
    int ic = ia*ib;
    string sc = to_string(ic);

    BigInt a (sa);
    BigInt b (sb);

    // Multiplication
    BigInt c = a*b;

    cout << "    Int Mult:    " << sc << endl;
    cout << "    BigInt Mult: " << c << endl;
}

void testBigMult()
{
    cout << "- Big Multiply Test" << endl;
    string sa = "912304273452134";
    string sb = "97861036156386";

    BigInt a (sa);
    BigInt b (sb);

    // Multiplication
    BigInt c = a*b;

    cout << "    a:   " << a << endl;
    cout << "    b:   " << b << endl;
    cout << "    a+b: " << c << endl;
}

int main()
{
    testSmallAdd();
    testBigAdd();

    testSmallMult();
    testBigMult();

    return 0;
}