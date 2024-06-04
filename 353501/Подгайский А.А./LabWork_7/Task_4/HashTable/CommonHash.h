#ifndef DB01089D_89B3_4363_A682_20C5E8AB0A2D
#define DB01089D_89B3_4363_A682_20C5E8AB0A2D
#include <cstdlib>

class ModuloHash{
    public:
    static size_t get (size_t x, size_t sz);
    static void init(){

    }
};

class UniversalHash{
    public:
    static const long PRIME = 37861;
    static long hash_a;
    static long hash_b;

public:
    static size_t get (long long x, size_t sz);
    static void init();
};


#endif /* DB01089D_89B3_4363_A682_20C5E8AB0A2D */
