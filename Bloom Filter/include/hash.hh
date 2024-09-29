
#ifndef HASH
#define HASH

class StringHash
{
    static const int MOD = 1e9 + 9;

public:
    static int HashFunction(const string &key, const int seed) // take prime number as seed
    {
        long long hashValue = 0;
        long long p_pow = 1;

        for (size_t i = 0; i < key.length(); i++)
        {
            hashValue = (hashValue + (key[i] - 'a' + 1) * p_pow) % MOD;
            p_pow = (p_pow * seed) % MOD;
        }

        return static_cast<int>(hashValue);
    }
};

#endif