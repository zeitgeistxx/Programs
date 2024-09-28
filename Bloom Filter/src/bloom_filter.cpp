#include <iostream>
#include <vector>
using namespace std;

#include <hash.hh>

class BloomFilter
{
    vector<bool> bitArray;
    size_t size;

public:
    BloomFilter(size_t size) : size(size), bitArray(size, false)
    {
    }

    size_t hash_1(const string &str)
    {
        return StringHash::FirstHashFunction(str) % size;
    }

    size_t hash_2(const string &str)
    {
        return StringHash::SecondHashFunction(str) % size;
    }

    size_t hash_3(const string &str)
    {
        return StringHash::ThirdHashFunction(str) % size;
    }

    void add(const string &input)
    {
        bitArray[hash_1(input)] = true;
        bitArray[hash_2(input)] = true;
        bitArray[hash_3(input)] = true;
    }

    bool contains(const string &input)
    {
        return bitArray[hash_1(input)] && bitArray[hash_2(input)] && bitArray[hash_3(input)];
    }
};

int
main()
{
    BloomFilter bloomFilter(1000);

    bloomFilter.add("hello");

    cout << "Contains 'hello': " << (bloomFilter.contains("hello") ? "Yes" : "No") << endl;
    cout << "Contains 'world': " << (bloomFilter.contains("world") ? "Yes" : "No") << endl;
}
