#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Car {
    string name;
    int year;
    double engine;
    double price;
public:
    Car(string n, int y, double e, double p)
        : name(n), year(y), engine(e), price(p) {}

    string getName() const { return name; }
    int getYear() const { return year; }
    double getEngine() const { return engine; }
    double getPrice() const { return price; }

    void printInfo() const {
        cout << "Name: " << name<< ", Year: " << year<< ", Vengine: " << engine<< " L, Price: " << price << " $$$" << endl;
    }
};

struct SortByPrice {
    bool operator()(const Car& a, const Car& b) const {
        return a.getPrice() < b.getPrice();
    }
};

struct SortByYear {
    bool operator()(const Car& a, const Car& b) const {
        return a.getYear() < b.getYear();
    }
};

struct FindByName {
    string name;
    FindByName(string n) : name(n) {}
    bool operator()(const Car& c) const {
        return c.getName() == name;
    }
};

int main() {
    vector<Car> cars;

    cars.push_back(Car("BMW X5", 2020, 3.0, 55000));
    cars.push_back(Car("Audi A6", 2018, 2.0, 35000));
    cars.push_back(Car("Toyota Camry", 2021, 2.5, 30000));

    cout << "--- All cars ---\n";
    for (auto it = cars.begin(); it != cars.end(); ++it) {
        it->printInfo();
    }

    sort(cars.begin(), cars.end(), SortByPrice());
    cout << "\n--- Sort by price ---\n";
    for (auto& c : cars) c.printInfo();

    sort(cars.begin(), cars.end(), SortByYear());
    cout << "\n--- Sort by years ---\n";
    for (auto& c : cars) c.printInfo();

    string searchName = "Audi A6";
    auto it = find_if(cars.begin(), cars.end(), FindByName(searchName));
    if (it != cars.end()) {
        cout << "\nCar found:\n";
        it->printInfo();
    } else {
        cout << "\n Error 404:Car " << searchName << " not found.\n";
    }

    string deleteName = "BMW X5";
    cars.erase(remove_if(cars.begin(), cars.end(), FindByName(deleteName)), cars.end());

    cout << "\n--- After delete "<<deleteName<<" ---\n";
    for (auto& c : cars) c.printInfo();

    return 0;
}
