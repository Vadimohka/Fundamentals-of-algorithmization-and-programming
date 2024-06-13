#include <vector>
#include <algorithm>
#include <QString>

const int INF = 1e9;

class BinaryHeap {
private:
    std::vector<int> maxHeap;
    std::vector<int> minHeap;

    void maxHeapifyUp(int index) {
        while (index > 0 && maxHeap[(index - 1) / 2] < maxHeap[index]) {
            std::swap(maxHeap[(index - 1) / 2], maxHeap[index]);
            index = (index - 1) / 2;
        }
    }

    void minHeapifyUp(int index) {
        while (index > 0 && minHeap[(index - 1) / 2] > minHeap[index]) {
            std::swap(minHeap[(index - 1) / 2], minHeap[index]);
            index = (index - 1) / 2;
        }
    }

    void maxHeapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < maxHeap.size() && maxHeap[leftChild] > maxHeap[largest]) {
            largest = leftChild;
        }
        if (rightChild < maxHeap.size() && maxHeap[rightChild] > maxHeap[largest]) {
            largest = rightChild;
        }

        if (largest != index) {
            std::swap(maxHeap[index], maxHeap[largest]);
            maxHeapifyDown(largest);
        }
    }

    void minHeapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;

        if (leftChild < minHeap.size() && minHeap[leftChild] < minHeap[smallest]) {
            smallest = leftChild;
        }
        if (rightChild < minHeap.size() && minHeap[rightChild] < minHeap[smallest]) {
            smallest = rightChild;
        }

        if (smallest != index) {
            std::swap(minHeap[index], minHeap[smallest]);
            minHeapifyDown(smallest);
        }
    }

public:
    void insert(int val) {
        maxHeap.push_back(val);
        minHeap.push_back(val);
        maxHeapifyUp(maxHeap.size() - 1);
        minHeapifyUp(minHeap.size() - 1);
    }

    int extractMax() {
        if (maxHeap.empty()) return -INF;
        int maxVal = maxHeap[0];
        std::swap(maxHeap[0], maxHeap[maxHeap.size() - 1]);
        maxHeap.pop_back();
        maxHeapifyDown(0);
        return maxVal;
    }

    int extractMin() {
        if (minHeap.empty()) return INF;
        int minVal = minHeap[0];
        std::swap(minHeap[0], minHeap[minHeap.size() - 1]);
        minHeap.pop_back();
        minHeapifyDown(0);
        return minVal;
    }

    int getMax() {
        if (maxHeap.empty()) return -INF;
        return maxHeap[0];
    }

    int getMin() {
        if (minHeap.empty()) return INF;
        return minHeap[0];
    }

    bool isEmpty() {
        return maxHeap.empty();
    }

    bool contains(int val) {
        return std::find(maxHeap.begin(), maxHeap.end(), val) != maxHeap.end() ||
               std::find(minHeap.begin(), minHeap.end(), val) != minHeap.end();
    }

    QString printMaxHeap() {
        QString str = "";
        for (int i=0; i<maxHeap.size(); i++) str+=QString::number(maxHeap[i]) + " ";
        return str;
    }

    QString printMinHeap() {
        QString str = "";
        for (int i=0; i<minHeap.size(); i++) str+=QString::number(minHeap[i]) + " ";
        return str;
    }
};
