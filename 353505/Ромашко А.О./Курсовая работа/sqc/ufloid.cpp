// #include "ufloid.h"
// #include <iostream>
// #include <QVector>
// #include <limits>

// UFloid::UFloid() {

// }

// int INF = std::numeric_limits<int>::max();


// // Алгоритм Флойда-Уоршелла
// void UFloid::initializeNext(const QVector<QVector<int>>& graph, QVector<QVector<int>>& next) {
//     int n = graph.size();
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < n; ++j) {
//             if (graph[i][j] != INF && i != j) {
//                 next[i][j] = j;
//             }
//         }
//     }
// }

// void UFloid::floydWarshall(const QVector<QVector<int>>& graph, QVector<QVector<int>>& dist, QVector<QVector<int>>& next) {
//     int n = graph.size();
//     initializeNext(graph, next);

//     for (int k = 0; k < n; ++k) {
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
//                     dist[i][j] = dist[i][k] + next[k][j];
//                     next[i][j] = next[i][k];
//                 }
//             }
//         }
//     }
// }

// QVector<int> UFloid::getPath(const QVector<QVector<int>>& next, int i, int j) {
//     QVector<int> path;
//     if (next[i][j] == -1) return path;

//     path.push_back(i);
//     while (i != j) {
//         i = next[i][j];
//         path.push_back(i);
//     }
//     return path;
// }

// void UFloid::printDistances(const QVector<QVector<int>>& dist) {
//     int n = dist.size();
//     std::cout << "Матрица кратчайших расстояний:\n";
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < n; ++j) {
//             if (dist[i][j] == INF) {
//                 std::cout << "INF ";
//             } else {
//                 std::cout << dist[i][j] << " ";
//             }
//         }
//         std::cout << std::endl;
//     }
// }
#include "ufloid.h"
#include <iostream>
#include <QVector>
#include <limits>

UFloid::UFloid() {}

int INF = std::numeric_limits<int>::max();

// Инициализация матрицы next
void UFloid::initializeNext(const QVector<QVector<int>>& graph, QVector<QVector<int>>& next) {
    int n = graph.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][j] != INF && i != j) {
                next[i][j] = j;
            } else {
                next[i][j] = -1; // Путь не существует
            }
        }
    }
}

// Алгоритм Флойда-Уоршелла
void UFloid::floydWarshall(const QVector<QVector<int>>& graph, QVector<QVector<int>>& dist, QVector<QVector<int>>& next) {
    int n = graph.size();
    dist = graph; // Инициализируем dist матрицей смежности
    initializeNext(graph, next);

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}

QVector<int> UFloid::getPath( const QVector<QVector<int>>& next, int start, int end) {
    QVector<int> path;
    if (next[start][end] == INF) return path;

    int current = start;
    path.push_back(current);
    while (current != end) {
        current = next[current][end]; // Выбираем следующую вершину
        path.push_back(current);
    }
    return path;
}

// Печать матрицы расстояний
void UFloid::printDistances(const QVector<QVector<int>>& dist) {
    int n = dist.size();
    std::cout << "Матрица кратчайших расстояний:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INF) {
                std::cout << "INF ";
            } else {
                std::cout << dist[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}

