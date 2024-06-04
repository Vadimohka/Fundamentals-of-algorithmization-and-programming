template<typename F, typename S>

class Pair
{
public:
    Pair(F fir, S sec) : first(fir), second(sec){};
    F first;
    S second;
};

