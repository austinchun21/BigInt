#include "bigint.hpp"


// Default Constructor
BigInt::BigInt()
    : size_{0}
{
    // Nothing
}

BigInt::BigInt(int i)
    : size_{0}
{
    int val;
    std::string s = std::to_string(i);
    for(char& c: s){
        val = c - '0';
        data_.insert(data_.begin(), val);
        ++size_;
    }
}

// Constructor from string (read left-to-right, stops at any non-digit char)
BigInt::BigInt(const std::string s)
    : size_{0}
{
    int val;
    for(const char& c: s){
        if(isdigit(c)){
            val = c - '0';
            data_.insert(data_.begin(), val);
            ++size_;
        }
        else{ // If non-digit, stop reading string
            break;
        }
    }
}



BigInt::BigInt(const std::vector<int> vect)
    : data_(vect), size_(vect.size())
{
    // Nothing
}

size_t BigInt::size() const
{
    return size_;
}


BigInt BigInt::operator+(const BigInt& rhs) const
{
    size_t N = (size_ > rhs.size()) ? size_ : rhs.size();
    std::vector<int> result(N, 0);

    bool carry = false;

    auto it1 = data_.begin();
    auto it2 = rhs.data_.begin();

    // Continue looping through all of a single list, then until no more carry-over
    for(size_t i=0; i<N; ++i){
        // Sum digits from both vectors
        if(it1 != data_.end()){
            result[i] += *it1;
            ++it1;
        }
        if(it2 != rhs.data_.end()){
            result[i] += *it2;
            ++it2;
        }
        // Check carry-over
        if(result[i] > 9){
            carry = true;
            result[i] -= 10;
        }
        else{
            carry = false;
        }
        // Reached end of longest vector (and result vector)
        if(carry){
            if(i==N-1)
                result.push_back(1);
            else
                result[i+1] = 1;
        }
    }

    // Delete extra zeros
    // auto rit = result.rbegin();
    // while(rit!=result.begin() || *rit==0)

    for(auto rit=result.rbegin(); rit!=result.rend(); ++rit){
        if(*rit == 0){
            result.pop_back();
        }
        else{
            break;
        }
    }

    return BigInt(result);
    // return BigInt();
}


BigInt BigInt::operator*(const BigInt& rhs) const
{
    size_t M = size_;
    size_t N = rhs.size();

    std::vector<int> result(M+N,0);


    int val;

    for(size_t i=0; i<M; ++i){
        for(size_t j=0; j<N; ++j){
            val = data_[i] * rhs.data_[j];
            result[i+j] += val%10;
            result[i+j+1] += val/10;
            if(result[i+j]>9){
                result[i+j+1] += result[i+j]/10;
                result[i+j] = result[i+j]%10;
            }
        }
    }
    for(auto rit=result.rbegin(); rit!=result.rend(); ++rit){
        if(*rit == 0){
            result.pop_back();
        }
        else{
            break;
        }
    }
    return BigInt(result);
}


std::ostream& BigInt::print(std::ostream& out)
{
    for(auto it=data_.rbegin(); it!=data_.rend(); ++it){
        out << *it;
    }
    return out;
}