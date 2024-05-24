#ifndef SEARCH_H
#define SEARCH_H

class Search {
public:
    // impossible to create an object
    Search() = delete;
    Search(const Search&) = delete;
    Search& operator=(const Search&) = delete;
    static int Binsearch(int* array, int size, int aim);
};

#endif // SEARCH_H
