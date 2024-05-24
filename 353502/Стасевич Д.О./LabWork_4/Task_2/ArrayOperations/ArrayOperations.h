//
// Created by darina on 5/8/24.
//

#ifndef TASK1_ARRAYOPERATIONS_H
#define TASK1_ARRAYOPERATIONS_H

#include <ctime>
#include <algorithm>
#include <QString>
#include <vector>

class ArrayOperations {
public:
    static int BinSearch(int* arr, int n, int digit);
    static float HeapSort(int* arr, int n, std::vector<std::vector<int> >& steps);
    static float MergeSort(int* arr, int n, std::vector<std::vector<int> >& steps);
    static float QuickSort(int* arr, int n, std::vector<std::vector<int> >& steps);
    static float InterpolarSort(int* arr, int n, std::vector<std::vector<int> >& steps);
    static void StringToArray(QString s, int* arr, int n);
    static int binpow(int digit, int powder, int mod);

private:
    static void Heapify(int* arr, int n, int i, std::vector<std::vector<int> >& steps, int global_n);
    static void DoMergeSort(int* arr, int l, int r, std::vector<std::vector<int> >& steps, int n);
    static void DoQuickSort(int* arr, int l, int r, std::vector<std::vector<int> >& steps, int n);
    static void DoMerge(int* arr, int l, int r, std::vector<std::vector<int> >& steps, int n);
    static int Partition(int* arr, int l, int r, int part, std::vector<std::vector<int> >& steps, int n);
    static void DoInterpolarSort(int *arr, int n, std::vector<int> &a, std::vector<std::vector<int>> &steps, int start_position);
};


#endif //TASK1_ARRAYOPERATIONS_H
