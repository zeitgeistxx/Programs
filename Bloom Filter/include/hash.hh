
#ifndef HASH
#define HASH

class StringHash
{
    static const int PRIME_CONST_1 = 17;
    static const int PRIME_CONST_2 = 31;
    static const int PRIME_CONST_3 = 53;
    static const int MOD = 1e9 + 9;

public:
    static int FirstHashFunction(const string &key)
    {
        long long hashValue = 0;
        long long p_pow = 1;

        for (size_t i = 0; i < key.length(); i++)
        {
            hashValue = (hashValue + (key[i] - 'a' + 1) * p_pow) % MOD;
            p_pow = (p_pow * PRIME_CONST_1) % MOD;
        }

        return static_cast<int>(hashValue);
    }

    static int SecondHashFunction(const string &key)
    {
        long long hashValue = 0;
        long long p_pow = 1;

        for (size_t i = 0; i < key.length(); i++)
        {
            hashValue = (hashValue + (key[i] - 'a' + 1) * p_pow) % MOD;
            p_pow = (p_pow * PRIME_CONST_2) % MOD;
        }

        return static_cast<int>(hashValue);
    }

    static int ThirdHashFunction(const string &key)
    {
        long long hashValue = 0;
        long long p_pow = 1;

        for (size_t i = 0; i < key.length(); i++)
        {
            hashValue = (hashValue + (key[i] - 'a' + 1) * p_pow) % MOD;
            p_pow = (p_pow * PRIME_CONST_3) % MOD;
        }

        return static_cast<int>(hashValue);
    }
};

#endif