#include "mergesort.h"

MergeSort::MergeSort() {}

void MergeSort::Merge(PicturedArray &PictureArray, int low, int mid, int high)
{
    QVector<std::pair<int, QColor>> array = PictureArray.getArray();
    QVector<std::pair<int, QColor>> aux = PictureArray.getAux();

    int k = low, i = low, j = mid + 1;

    // пока есть элементы в левом и правом рядах
    while (i <= mid && j <= high)
    {
        if (array[i].first <= array[j].first) {
            aux[k++] = array[i++];
        }
        else {
            aux[k++] = array[j++];
        }
    }

    // копируем оставшиеся элементы
    while (i <= mid) {
        aux[k++] = array[i++];
    }

    // Вторую половину копировать не нужно (поскольку остальные элементы
    // уже находятся на своем правильном месте во вспомогательном массиве)

    // копируем обратно в исходный массив, чтобы отразить порядок сортировки
    for (int i = low; i <= high; i++) {
        array[i] = aux[i];

        PictureArray.updateArray();
        QEventLoop loop;
        QTimer::singleShot(30, &loop, &QEventLoop::quit);
        loop.exec();
    }
}

void MergeSort::mergesort(PicturedArray &PictureArray, int low, int high)
{
    // базовый вариант
    if (high <= low) {        // если размер прогона <= 1
        return;
    }

    // найти середину
    int mid = (low + ((high - low) >> 1));

    // рекурсивно разделяем прогоны на две половины до тех пор, пока размер прогона не станет <= 1,
    // затем объединяем их и возвращаемся вверх по цепочке вызовов

    mergesort(PictureArray, low, mid);          // разделить/объединить левую половину

    mergesort(PictureArray, mid + 1, high);     // разделить/объединить правую половину

    Merge(PictureArray, low, mid, high);        // объединить два полупрогона.
}

void MergeSort::mergeSortForTime(PicturedArray &PictureArray, int low, int high)
{
    if (high <= low) {
        return;
    }

    int mid = (low + ((high - low) >> 1));

    mergeSortForTime(PictureArray, low, mid);

    mergeSortForTime(PictureArray, mid + 1, high);

    mergeForTime(PictureArray, low, mid, high);
}

void MergeSort::mergeForTime(PicturedArray &PictureArray, int low, int mid, int high)
{

}

long long MergeSort::timeMergeSort(PicturedArray &PictureArray)
{
    QVector<std::pair<int, QColor>> array = PictureArray.getArray();
    QVector<std::pair<int, QColor>> aux = PictureArray.getAux();

    QVector<std::pair<int, QColor>> copyOfArray, copyOfAux;


    copyOfArray.resize(array.size());
    copyOfAux.resize(array.size());

    for(int i = 0; i < array.size(); i++)
    {
        copyOfArray[i] = array[i];
        copyOfAux[i] = array[i];
    }

    clock_t t0 = clock();

    mergeSortForTime(PictureArray, 0, copyOfArray.size() - 1);

    clock_t result = clock() - t0;

    long long time_of_sort = (double)result / CLOCKS_PER_SEC * 1000000.0;

    return time_of_sort;
}
