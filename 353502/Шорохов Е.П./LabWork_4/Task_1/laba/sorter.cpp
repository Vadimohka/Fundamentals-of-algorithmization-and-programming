#include "sorter.h"
#include <iostream>
//I am booored

Sorter::Sorter() = default;

void Sorter::HeapSort(int64_t *arr, int64_t size)
{
    for (int iter = size - 1;iter>=0;iter--)
    {
        int64_t curr_iter = iter;
        while (true)
        {
            int64_t left = 2*curr_iter+1, right = 2*curr_iter+2, maxValIter = curr_iter;

            if (left < size)
            {
                if (arr[maxValIter] < arr[left])
                {
                    maxValIter = left;
                }
            }

            if (right < size)
            {
                if (arr[maxValIter] < arr[right])
                {
                    maxValIter = right;
                }
            }

            if (maxValIter != curr_iter)
            {
                std::swap(arr[maxValIter], arr[curr_iter]);

                curr_iter = maxValIter;
            }
            else
            {
                break;
            }
        }
    }

    for (int iter = 0; iter < size; iter++)
    {
        std::swap(arr[0], arr[size - (iter + 1)]);

        int64_t curr_iter = 0;
        while (true)
        {
            int64_t left = 2*curr_iter+1, right = 2*curr_iter+2, maxValIter = curr_iter;

            if (left < size - (iter + 1))
            {
                if (arr[maxValIter] < arr[left])
                {
                    maxValIter = left;
                }
            }

            if (right < size - (iter + 1))
            {
                if (arr[maxValIter] < arr[right])
                {
                    maxValIter = right;
                }
            }

            if (maxValIter != curr_iter)
            {
                std::swap(arr[maxValIter], arr[curr_iter]);

                curr_iter = maxValIter;
            }
            else
            {
                break;
            }
        }
    }
}

void Sorter::QuickSort(int64_t *arr, int64_t size)
{
    if (size <= 1)
    {
        return;
    }

    int64_t left = 0, right = size - 1, middle = size / 2;

    while (left <= right)
    {
        while (arr[left] < arr[middle])
        {
            left++;
        }

        while (arr[right] > arr[middle])
        {
            right--;
        }

        if (left >= right)
        {
            break;
        }

        std::swap(arr[left++], arr[right--]);
    }

    QuickSort(arr, left);
    QuickSort(arr + left, size - left);
}

void Sorter::MergeSort(int64_t *arr, int64_t size)
{
    if (size <= 1)
    {
        return;
    }

    int64_t middle = size / 2;

    MergeSort(arr, middle);
    MergeSort(arr + middle, size - middle);

    int left = 0, right = middle, currPos = 0;

    int64_t* merged = new int64_t[size];

    while (currPos != size)
    {
        if (left < middle && right < size)
        {
            if (arr[left] < arr[right])
            {
                merged[currPos] = arr[left++];
            }
            else
            {
                merged[currPos] = arr[right++];
            }
        }
        else if (left < middle)
        {
            merged[currPos] = arr[left++];
        }
        else
        {
            merged[currPos] = arr[right++];
        }

        currPos++;
    }

    for (int iter = 0;iter<size;iter++)
    {
        arr[iter] = merged[iter];
    }

    delete[] merged;
}

void Sorter::InterpolationSort(int64_t *arr, int64_t size)
{
    for (int iter = 1; iter < size; iter++) {
        int key = arr[iter];
        int j = iter - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}
