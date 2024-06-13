#include "hashtablewithnonegativenumbers.h"


void hashtablewithnonegativenumbers::removeNegativeKeys() {
    for (int key = -10; key < 0; ++key) {
        int index = hashFunction(key);
        while (!table[index].isEmpty()) {
            table[index].pop();
        }
    }
}
