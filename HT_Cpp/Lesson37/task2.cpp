#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Product {
private:
    std::string name;
    std::string category;
    double price;

public:
    Product(std::string n, std::string c, double p)
        : name(n), category(c), price(p) {}

    std::string getName() const { return name; }
    std::string getCategory() const { return category; }
    double getPrice() const { return price; }

    void printInfo() const {
        std::cout << "Name: " << name<< ", Category: " << category<< ", Price: " << price << " UAH" << std::endl;
    }
};

class ProductManager {
private:
    std::vector<Product> products;

public:
    void addProduct(const Product& product) {
        products.push_back(product);
    }

    void showAllProducts() const {
        std::cout << "\n--- Goods list ---\n";
        for (auto it = products.begin(); it != products.end(); ++it) {
            it->printInfo();
        }
    }

    void filterByCategory(const std::string& category) const {
        std::cout << "\n--- Goods in category: " << category << " ---\n";
        for (auto it = products.begin(); it != products.end(); ++it) {
            if (it->getCategory() == category) {
                it->printInfo();
            }
        }
    }

    void sortByPrice() {
        std::sort(products.begin(), products.end(),[](const Product& a, const Product& b) {return a.getPrice() < b.getPrice();});
    }
};

int main() {
    ProductManager manager;
    manager.addProduct(Product("Potato", "Grocery", 5));
    manager.addProduct(Product("Onion", "Grocery", 2));
    manager.addProduct(Product("Yogurt", "Dairy", 50));
    manager.addProduct(Product("Milk", "Dairy", 20));

    manager.showAllProducts();

    
    manager.filterByCategory("Dairy");

    
    manager.sortByPrice();
    std::cout << "\n--- Goods after sort ---\n";
    manager.showAllProducts();

    return 0;
}
