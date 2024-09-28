#include <iostream>
#include <vector>
using namespace std;

#include <hash.hh>

class CountingBloomFilter
{
    vector<int> counters;
    size_t size;

public:
    CountingBloomFilter(size_t size) : size(size), counters(size, 0)
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
        counters[hash_1(input)]++;
        counters[hash_2(input)]++;
        counters[hash_3(input)]++;
    }

    void displayCounts() const
    {
        for (size_t i = 0; i < size; ++i)
        {
            if (counters[i] != 0)
            {
                cout << "Index " << i << ": " << counters[i] << endl;
            }
        }
    }
};

int main()
{
    CountingBloomFilter filter(1000);

    filter.add("hello");
    filter.add("world");
    filter.displayCounts();
}
