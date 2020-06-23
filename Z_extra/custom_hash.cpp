/*
    -> Custom Hash for Unordered Map and Set
    -> ref: 1. https://codeforces.com/blog/entry/62393
            2. https://stackoverflow.com/questions/664014/what-integer-hash-function-are-good-that-accepts-an-integer-hash-key/12996028#12996028
*/

// for 64-bit nos.
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};



// for 32-bit nos.
struct custom_hash
{
    using in=uint32_t;
    static in hasher(in x)
    {
        x = ((x >> 16) ^ x) * 0x45d9f3b;
        x = ((x >> 16) ^ x) * 0x45d9f3b;
        x = (x >> 16) ^ x;
        return x;
    }

    size_t operator()(in x) const
    {
        static const in FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return hasher(x + FIXED_RANDOM);
    }
};
