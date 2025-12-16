#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    map<string, vector<string>> data;

    auto load_data = [&](const string& filename) {
        ifstream fin(filename);
        string country, city;
        while (fin >> country >> city) {
            data[country].push_back(city);
        }
        fin.close();
    };

    auto save_data = [&](const string& filename) {
        ofstream fout(filename);
        for (auto& [country, cities] : data) {
            for (auto& city : cities) {
                fout << country << " " << city << "\n";
            }
        }
        fout.close();
    };

    auto get_cities = [&](const string& country) {
        if (data.count(country)) {
            cout << "Міста країни " << country << ": ";
            for (auto& city : data[country]) cout << city << " ";
            cout << "\n";
        } else cout << "Країна не знайдена\n";
    };

    auto add_country = [&](const string& country) {
        data[country];
    };

    auto add_city = [&](const string& country, const string& city) {
        data[country].push_back(city);
    };

    auto replace_city = [&](const string& country, const string& old_city, const string& new_city) {
        if (data.count(country)) {
            auto& cities = data[country];
            auto it = find(cities.begin(), cities.end(), old_city);
            if (it != cities.end()) *it = new_city;
        }
    };

    auto delete_city = [&](const string& country, const string& city) {
        if (data.count(country)) {
            auto& cities = data[country];
            cities.erase(remove(cities.begin(), cities.end(), city), cities.end());
        }
    };

    auto delete_country = [&](const string& country) {
        data.erase(country);
    };

    auto count_cities = [&](const string& country) {
        return data.count(country) ? data[country].size() : 0;
    };

    auto list_countries = [&]() {
        cout << "Список країн:\n";
        for (auto& [country, _] : data) cout << country << "\n";
    };

    add_country("Україна");
    add_city("Україна", "Київ");
    add_city("Україна", "Львів");
    add_city("Україна", "Одеса");

    add_country("Польща");
    add_city("Польща", "Варшава");
    add_city("Польща", "Краків");

    get_cities("Україна");
    replace_city("Польща", "Краків", "Гданськ");
    delete_city("Україна", "Львів");

    cout << "Кількість міст у Україні: " << count_cities("Україна") << "\n";

    list_countries();

    save_data("countries.txt");

    return 0;
}
