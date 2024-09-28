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

    int hash_1(const string &str)
    {
        return StringHash::FirstHashFunction(str) % size;
    }

    int hash_2(const string &str)
    {
        return StringHash::SecondHashFunction(str) % size;
    }

    int hash_3(const string &str)
    {
        return StringHash::ThirdHashFunction(str) % size;
    }

    void add(const string &key)
    {
        counters[hash_1(key)]++;
        counters[hash_2(key)]++;
        counters[hash_3(key)]++;
    }

    void remove(const string &key)
    {
        int index_1 = hash_1(key);
        if (counters[index_1] > 0)
            counters[index_1]--;

        int index_2 = hash_2(key);
        if (counters[index_2] > 0)
            counters[index_2]--;

        int index_3 = hash_3(key);
        if (counters[index_3] > 0)
            counters[index_3]--;
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
    string input;

    while (true)
    {
        cout << "\n";
        cout << "1.INSERT" << endl;
        cout << "2.DELETE" << endl;
        cout << "3.SHOW" << endl;
        cout << "Choose an operation -> ";

        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter a string -> ";
            cin >> input;
            filter.add(input);
            break;

        case 2:
            cout << "Enter a string -> ";
            cin >> input;
            filter.remove(input);
            break;

        case 3:
            filter.displayCounts();
            break;

        default:
            cout << "Invalid Operation" << endl;
            exit(0);
        }
    }
}
