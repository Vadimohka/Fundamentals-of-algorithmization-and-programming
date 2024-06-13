#include <iostream>
#include <cstring>

struct City {
    int population;
    double area;
    char category;
    bool isCapital;
    static const int maxNameLength = 50;
    static const int numFeatures = 3;
    char name[maxNameLength];
    int features[numFeatures];
};

int main() {
    City city1;
    city1.population = 1000000;
    city1.area = 2500.75;
    city1.category = 'A';
    city1.isCapital = true;
    std::strcpy(city1.name, "New York");
    city1.features[0] = 10;
    city1.features[1] = 20;
    city1.features[2] = 30;
    std::cout << city1.population << " | " << city1.area << " | " << city1.category << " | "
              << city1.isCapital << " | " << city1.name << " | " << city1.features[0] << " | "
              << city1.features[1] << " | " << city1.features[2] << std::endl;

    City city2;
    city2.population = 500000;
    city2.area = 1800.25;
    city2.category = 'B';
    city2.isCapital = false;
    std::strcpy(city2.name, "Los Angeles");
    city2.features[0] = 5;
    city2.features[1] = 10;
    city2.features[2] = 15;
    std::cout << city2.population << " | " << city2.area << " | " << city2.category << " | "
              << city2.isCapital << " | " << city2.name << " | " << city2.features[0] << " | "
              << city2.features[1] << " | " << city2.features[2] << std::endl;

    City city3;
    std::cout << "Enter population: ";
    std::cin >> city3.population;
    std::cout << "Enter area: ";
    std::cin >> city3.area;
    std::cout << "Enter category: ";
    std::cin >> city3.category;
    std::cout << "Is it a capital? (1 for true, 0 for false): ";
    std::cin >> city3.isCapital;
    std::cout << "Enter city name: ";
    std::cin.ignore();
    std::cin.getline(city3.name, City::maxNameLength);
    std::cout << "Enter features (3 integers separated by space): ";
    for (int i = 0; i < City::numFeatures; ++i) {
        std::cin >> city3.features[i];
    }
    std::cout << city3.population << " | " << city3.area << " | " << city3.category << " | "
              << city3.isCapital << " | " << city3.name << " | " << city3.features[0] << " | "
              << city3.features[1] << " | " << city3.features[2] << std::endl;

    City city4;
    City* cityPtr = &city4;
    cityPtr->population = 2000000;
    cityPtr->area = 3500.50;
    cityPtr->category = 'C';
    cityPtr->isCapital = true;
    std::strcpy(cityPtr->name, "Chicago");
    cityPtr->features[0] = 15;
    cityPtr->features[1] = 25;
    cityPtr->features[2] = 35;
    std::cout << cityPtr->population << " | " << cityPtr->area << " | " << cityPtr->category << " | "
              << cityPtr->isCapital << " | " << cityPtr->name << " | " << cityPtr->features[0] << " | "
              << cityPtr->features[1] << " | " << cityPtr->features[2] << std::endl;

    return 0;
}
