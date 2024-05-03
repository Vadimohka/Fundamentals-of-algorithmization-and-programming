
template<typename T1, typename T2>
struct Pair{
    T1 first;
    T2 second;

    Pair(T1 first_, T2 second_){
        first = first_;
        second = second_;
    }

    Pair() = default;

    bool operator==(const Pair<T1, T2> other){
        return this->first  == other.first &&
                this->second == other.second;
    }
};