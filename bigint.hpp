#ifndef BIGINT_HPP_INCLUDED
#define BIGINT_HPP_INCLUDED 1

#include <bits/stdc++.h>
#include <time.h>

class BigInt{
public:
    // Default Constructor
    BigInt();
    
    BigInt(int i);

    BigInt(const std::string s);

    BigInt(const std::vector<int> vect);

    size_t size() const;

    // Add two BigInts
    BigInt operator+(const BigInt& rhs) const;

    // Multiply two BigInts
    BigInt operator*(const BigInt& rhs) const;

    std::ostream& print(std::ostream& out);

private:
    // Holds the digits of the integer (decimal)
    // data[0] = 1's, data[1] = 10's etc
    std::vector<int> data_;

    // Num digits in the integer (size of vector)
    size_t size_;
};



#endif // defined BIGINTSTRING_HPP_INCLUDED