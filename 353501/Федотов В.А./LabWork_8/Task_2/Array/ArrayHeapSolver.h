#pragma once

#include "ArrayMaxHeap.h"

#include <QTextEdit>
#include <QString>

class ArrayHeapSolver : public ArrayMaxHeap {
public:
    ArrayHeapSolver() : ArrayMaxHeap() {}

    void printHeap(QTextEdit* textEdit) {
        if (isEmpty()) {
            textEdit->clear();
            return;
        }

        QString heapText;
        int levels = getHeapLevels();
        int levelSize = 1;
        int levelCount = 0;
        int indentation = levels - 1;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < indentation; j++) {
                heapText += "  ";
            }

            heapText += QString::number(heap[i]);
            levelCount++;

            if (levelCount == levelSize) {
                heapText += "\n";
                levelSize *= 2;
                levelCount = 0;
                indentation--;
            } else {
                heapText += "  ";
            }
        }

        textEdit->setPlainText(heapText);
    }

private:
    int getHeapLevels() {
        int levels = 0;
        int nodes = 0;

        while (nodes < size) {
            nodes += static_cast<int>(std::pow(2, levels));
            levels++;
        }

        return levels;
    }
};