#include <iostream>
#include "ArrayOperations.h"

int ArrayOperations::BinSearch(int *arr, int n, int digit) {
    std::cout << "here " << '\n';
    for(int i = 0; i < n; i ++)
        std::cout << arr[i] << " ";
    std::cout << '\n';
    int l = 0, r = n - 1;
    while(l <= r)
    {
        int m = (l + r) / 2;
        if(arr[m] == digit)
            return m;
        if(arr[m] < digit)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

float ArrayOperations::HeapSort(int *arr, int n, std::vector<std::vector<int> >& steps) {
    auto start = clock();

    for(int i = n / 2 - 1; i >= 0; i --)
    {
        Heapify(arr, n, i, steps, n);
        for(int j = 0; j < n; j ++)
        {
            std::cout << arr[j] << " ";
        }
        std::cout << '\n';
    }


    for(int i = n - 1; i >= 0; i --)
    {
        std::swap(arr[i], arr[0]);
        Heapify(arr, i, 0, steps, n);
        for(int j = 0; j < n; j ++)
        {
            std::cout << arr[j] << " ";
        }
        std::cout << '\n';
    }
    std::vector<int> add;
    for(int i = 0; i < n; i ++)
    {
        add.push_back(arr[i]);
    }
    steps.push_back(add);
    auto finish = clock();
    return ((float)(finish - start) / CLOCKS_PER_SEC);
}

void ArrayOperations::Heapify(int *arr, int n, int i, std::vector<std::vector<int> >& steps, int global_n) {
    int mx = i;

    int l = i * 2 + 1, r = i * 2 + 2;

    if(l < n && arr[l] > arr[i])
        mx = l;
    if(r < n && arr[r] > arr[mx])
        mx = r;

    if(mx == i)
        return;
    std::swap(arr[i], arr[mx]);
    std::vector<int> add;
    for(int ii = 0; ii < global_n; ii ++)
    {
        add.push_back(arr[ii]);
    }
    if(steps.size() == 0)
    {
        steps.push_back(add);
    }
    else
    {
        if(steps.back() != add)
            steps.push_back(add);
    }
    Heapify(arr, n, mx, steps, global_n);

}

void ArrayOperations::StringToArray(QString s, int* arr, int n) {
    if(s.isEmpty())
        throw "empty";
    int cur_position = 0;
    s = s + ' ';
    long long cur_value = 0;
    bool sign = 0;
    for(int i = 0; i < s.size(); i ++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            cur_value = cur_value * 10 + s[i].digitValue();
            if(cur_value > 2147483647)
            {
                throw "Incorrect value";
            }
            continue;
        }
        if(s[i] == ' ')
        {
            if(i == 0)
                throw "incorrect";
            if(cur_position >= n)
                throw "Incorrect size";
            if(sign)
                cur_value *= -1;
            arr[cur_position] = cur_value;
            cur_position ++;
            cur_value = 0;
            sign = 0;
            continue;
        }
        if(s[i] == '-')
        {
            if(i == 0 || s[i - 1] == ' ')
            {
                sign = 1;
                continue;
            }
            else
            {
                throw "invalid minus";
            }
        }
        throw "invalid symbol";
    }

    if(cur_position < n)
        throw "not full";

}

float ArrayOperations::MergeSort(int *arr, int n, std::vector<std::vector<int> >& steps) {
    auto start = clock();

    DoMergeSort(arr, 0, n - 1, steps, n);

    auto finish = clock();
    return ((float)(finish - start) / CLOCKS_PER_SEC);
}

void ArrayOperations::DoMergeSort(int *arr, int l, int r, std::vector<std::vector<int> >& steps, int n) {

    if(r <= l)
        return;
    int m = (l + r) / 2;
    DoMergeSort(arr, l, m, steps, n);
    DoMergeSort(arr, m + 1, r, steps, n);
    DoMerge(arr, l, r, steps, n);
}

void ArrayOperations::DoMerge(int* arr, int l, int r, std::vector<std::vector<int> >& steps, int n) {
    int m = (l + r) / 2;
    int* a = new int[m - l + 1];
    int* b = new int[r - m];

    for(int i = l; i <= m; i ++)
        a[i - l] = arr[i];

    for(int i = m + 1; i <= r; i ++)
    {
        b[i - m - 1] = arr[i];
    }

    int i = 0, j = 0, sz1 = m - l + 1, sz2 = r - m;
    int k = l;
    while(i < sz1 && j < sz2)
    {
        if(a[i] < b[j])
        {
            arr[k] = a[i];
            i ++;
            k ++;
        }
        else
        {
            arr[k] = b[j];
            j ++;
            k ++;
        }
        std::vector<int> add;
        for(int ii = 0; ii < n; ii ++)
        {
            add.push_back(arr[ii]);
        }
        if(steps.size() == 0)
        {
            steps.push_back(add);
        }
        else
        {
            if(steps.back() != add)
                steps.push_back(add);
        }
    }
    while(i < sz1)
    {
        arr[k] = a[i];
        i ++;
        k ++;
        std::vector<int> add;
        for(int ii = 0; ii < n; ii ++)
        {
            add.push_back(arr[ii]);
        }
        if(steps.size() == 0)
        {
            steps.push_back(add);
        }
        else
        {
            if(steps.back() != add)
                steps.push_back(add);
        }
    }
    while(j < sz2)
    {
        arr[k] = b[j];
        j ++;
        k ++;
        std::vector<int> add;
        for(int ii = 0; ii < n; ii ++)
        {
            add.push_back(arr[ii]);
        }
        if(steps.size() == 0)
        {
            steps.push_back(add);
        }
        else
        {
            if(steps.back() != add)
                steps.push_back(add);
        }
    }
    delete[] a;
    delete[] b;
}

float ArrayOperations::QuickSort(int *arr, int n, std::vector<std::vector<int> >& steps) {
    auto start = clock();
    srand(time(0));
    DoQuickSort(arr, 0, n - 1, steps, n);

    auto finish = clock();
    return ((float)(finish - start) / CLOCKS_PER_SEC);
}

void ArrayOperations::DoQuickSort(int *arr, int l, int r, std::vector<std::vector<int> >& steps, int n) {
    if(l >= r)
        return;
    int q = l + rand()%(r-l + 1);
    int p = Partition(arr, l, r, arr[q], steps, n);
    if(arr[l]==arr[r]){
        return ;
    }
    DoQuickSort(arr, l, p, steps, n);
    DoQuickSort(arr, p + 1, r, steps, n);
}

int ArrayOperations::Partition(int *arr, int l, int r, int part, std::vector<std::vector<int> >& steps, int n) {
    if(l > r)
        return l - 1;
    int st = l;
    int small = l, equal = l, big = l;
    while (l <= r) {
        if(arr[l] < part)
        {
            int k = arr[l];
            arr[big] = arr[equal];
            arr[equal] = arr[small];
            arr[small] = k;
            big ++;
            equal ++;
            small ++;
            l ++;
        }
        else if (arr[l] == part)
        {
            int k = arr[l];
            arr[big] = arr[equal];
            arr[equal] = k;
            big ++;
            equal ++;
            l ++;
        }
        else
        {
            arr[big] = arr[l];
            big ++;
            l ++;
        }
        std::vector<int> add;
        bool t = 0;
        for(int i = 0; i < n; i ++)
        {
            add.push_back(arr[i]);
            if(steps.size() == 0)
                continue;
            if(arr[i] != steps[steps.size() - 1][i])
                t = 1;
        }
        if(steps.size() == 0)
            t = 1;
        //std::cout << "old\n";
        if(t)
        {
            steps.push_back(add);
        }
    }
    return small - 1;
}

void ArrayOperations::DoInterpolarSort(int *arr, int n, std::vector<int> &a, std::vector<std::vector<int>> &steps, int start_position) {
    int st = 0;
    int sz = a.size();
    int mn = a[0], mx = a[0];
    for(int i = 1; i < sz; i ++)
    {
        mn = std::min(mn, a[i]);
        mx = std::max(mx, a[i]);
    }
    if(mn == mx)
        return;
    std::vector<std::vector<int> > bucket(sz);
    int interpolation = 0;
    for(int i = 0; i < sz; i ++)
    {
        interpolation = (int)(((double)(a[i] - mn) / (mx - mn)) * (sz - 1));
        bucket[interpolation].push_back(a[i]);
    }
    int cur = 0;
    st = 0;
    for(int i = 0; i < sz; i ++)
    {
        if(bucket[i].size() > 1)
        {
            DoInterpolarSort(arr, n, bucket[i], steps, start_position + cur);
        }
        cur += bucket[i].size();
        std::vector<int> add;
        for(int j = 0; j < bucket[i].size(); j ++)
        {
            a[st] = bucket[i][j];
            arr[st + start_position] = bucket[i][j];
            st ++;
            add.clear();
            for(int k = 0; k < n; k ++)
                add.push_back(arr[k]);
            steps.push_back(add);
        }

    }
}

float ArrayOperations::InterpolarSort(int* arr, int n, std::vector<std::vector<int>> &steps) {
    auto start = clock();

    std::vector<int> a;
    for(int i = 0; i < n; i ++)
    {
        a.push_back(arr[i]);
    }
    DoInterpolarSort(arr, n, a, steps, 0);
    std::cout << "ok " << '\n';
    for(int i = 0; i < n; i ++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
    for(auto x : steps)
    {
        for(auto y : x)
        {
            std::cout << y << " ";
        }
        std::cout << '\n';
    }
    auto finish = clock();
    return ((float)(finish - start) / CLOCKS_PER_SEC);
}

int ArrayOperations::binpow(int digit, int powder, int mod) {
    if(powder == 0)
        return 1;
    if(powder == 1)
    {
        return digit;
    }
    int a = binpow(digit, powder / 2, mod);
    if(powder % 2)
    {
        return ((a * a) % mod * digit) % mod;
    }
    else
    {
        return (a * a) % mod;
    }
}
