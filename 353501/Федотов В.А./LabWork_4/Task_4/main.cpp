#include "vector.h"
#include "pair.h"
#include <cstddef>
#include <vector>
#include <iostream>

template<typename T>
void printVector( Vector<T>& vector){
    std::cout << "\n";
    for (size_t i = 0; i < vector.size(); ++i) {
        std::cout << vector[i] << " ";
    }
}

void test1(){
    Vector<std::string> strings;
    strings.reserve(8);
    strings.push_back("One");
    strings.push_back("Two");
    strings.push_back("Three");
    strings.push_back("Four");
    strings.push_back("Five");
    strings.push_back("Six");
    strings.push_back("Eight");
    strings.insert(strings.cend() - 1, "Seven");

    printVector(strings);
}

void test2(){
    Vector<int> nums1;
    Vector<int> nums2;
    
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(3);
    nums1.push_back(4);
    nums1.push_back(5);
    nums1.push_back(6);
    nums1.push_back(7);
    nums1.push_back(8);
    nums1.emplace(nums1.cbegin() + 2, 0);

    nums2.push_back(69);
    nums2.push_back(1337);
    nums2.push_back(228);

    printVector(nums1);
    printVector(nums2);

    nums1.swap(nums2);
    std::cout << "\n";

    nums1.push_back(420);

    printVector(nums1);
    printVector(nums2);
}

void test3(){
    Vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    printVector(nums);

    nums.assign(18, 0);
    printVector(nums);

    for (int i = 0; i < nums.size(); i++) {
        nums[i] = i;
    }
    printVector(nums);

    nums.erase(nums.begin() + 2, nums.begin() + 7);
    printVector(nums);
}

void test4() {
    Pair<Pair<int, int>, Pair<double, double>> pair ({2,5}, {5.5, 6.92});
    std::cout << pair.first.second << " " << pair.second.second;
}

void test5() {
    Vector<Pair< Vector<int>, Vector<Pair<int, double>> >> vector;

    Vector<int>v1;
    Vector<Pair<int, double>>v2;
    v1.push_back(25);
    v2.push_back({26, 23.3});
    v1.push_back(11);
    vector.push_back({ v1, v2 });

    // printVector(vector);
    std::cout << vector.at(0).first.at(0) << "\n";
    std::cout << vector.at(0).second.at(0).second;

}

int main() {
    std::cout << "\n\n-----Test 1-----\n";
    test1();
    std::cout << "\n\n-----Test 2-----\n";
    test2();
    std::cout << "\n\n-----Test 3-----\n";
    test3();
    std::cout << "\n\n-----Test 4-----\n";
    test4();
    std::cout << "\n\n-----Test 5-----\n";
    test5();

    std::cout << "\n";
    return 0;
}