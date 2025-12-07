#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ---- Product Class ----
class Product {
public:
    string name;
    float price;

    Product(string n, float p) : name(n), price(p) {}
};

// ---- Store Class ----
class Store {
private:
    vector<Product> items;

public:
    void addProduct(string name, float price) {
        items.push_back(Product(name, price));
    }

    void cheapestProduct() {
        if (items.empty()) {
            cout << "No products.\n";
            return;
        }

        Product cheap = items[0];
        for (const auto& p : items)
            if (p.price < cheap.price) cheap = p;

        cout << "Cheapest: " << cheap.name
             << " - $" << cheap.price << endl;
    }
};

// ---- Main ----
int main() {
    Store s;

    s.addProduct("Milk", 1.5);
    s.addProduct("Bread", 1.0);
    s.addProduct("Juice", 2.2);

    s.cheapestProduct();

    return 0;
}