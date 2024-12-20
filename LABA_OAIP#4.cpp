#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <windows.h>
using namespace std;


class MenuItem {
protected:
    string name;
    double price;
    string type;

public:
    MenuItem(const string& name, double price, const string& type)
        : name(name), price(price), type(type) {}

    virtual ~MenuItem() = default;

    virtual void displayInfo() const {
        cout << "Name: " << name << ", Price: " << price << ", Type: " << type << endl;
    }

    double getPrice() const { 
        return price;
    }
    const string& getName() const { 
        return name; 
    }
    void setPrice(double newPrice) { 
        price = newPrice; 
    }
};

template <typename T1, typename T2>
class Pair {
    T1 first;
    T2 second;

public:
    Pair(const T1& first, const T2& second) : first(first), second(second) {}

    void display() const {
        cout << "Pair: (" << first << ", " << second << ")" << endl;
    }
};

class Appetizer : public MenuItem {
public:
    Appetizer(const string& name, double price)
        : MenuItem(name, price, "Appetizer") {}

    void displayInfo() const override {
        cout << "Appetizer ";
        MenuItem::displayInfo();
    }
};

class MainCourse : public MenuItem {
public:
    MainCourse(const string& name, double price)
        : MenuItem(name, price, "Main Course") {}

    void displayInfo() const override {
        cout << "Main Course ";
        MenuItem::displayInfo();
    }
};

class Dessert : public MenuItem {
public:
    Dessert(const string& name, double price)
        : MenuItem(name, price, "Dessert") {}

    void displayInfo() const override {
        cout << "Dessert ";
        MenuItem::displayInfo();
    }
};

class MenuManager {
    vector<MenuItem*> menu;

public:
    ~MenuManager() {
        for (auto item : menu)
            delete item;
    }

    void addMenuItem(MenuItem* item) {
        menu.push_back(item);
    }

    void searchMenuItem(const string& name) const {
        for (const auto& item : menu) {
            if (item->getName() == name) {
                item->displayInfo();
                return;
            }
        }
        cout << "Item not found." << endl;
    }

    void sortMenuByPrice() {
        sort(menu.begin(), menu.end(), [](const MenuItem* a, const MenuItem* b) {
            return a->getPrice() < b->getPrice();
            });
        cout << "Menu sorted by price." << endl;
    }

    void displayMenu() const {
        for (const auto& item : menu)
            item->displayInfo();
    }

    void saveToFile(const string& filename) const {
        ofstream outFile(filename);
        if (!outFile) {
            cerr << "Error opening file." << endl;
            return;
        }

        for (const auto& item : menu) {
            outFile << item->getName() << "," << item->getPrice() << "," << item->getName() << "\n";
        }
        outFile.close();
        cout << "Menu saved to " << filename << endl;
    }

    void modifyMenuItemPrice(const string& name, double newPrice) {
        for (auto& item : menu) {
            if (item->getName() == name) {
                item->setPrice(newPrice);
                cout << "Price updated." << endl;
                return;
            }
        }
        cout << "Item not found." << endl;
    }
};

int main() {
    MenuManager manager;

    manager.addMenuItem(new Appetizer("Spring Rolls", 5.99));
    manager.addMenuItem(new MainCourse("Steak", 15.99));
    manager.addMenuItem(new Dessert("Ice Cream", 3.99));

    int choice;
    do {
        cout << "\n1. Add Item\n2. Search Item\n3. Sort by Price\n4. Display Menu\n5. Save to File\n6. Modify Price\n0. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name, type;
            double price;
            cout << "Enter name, type (Appetizer/MainCourse/Dessert), and price: ";
            cin >> name >> type >> price;
            if (type == "Appetizer")
                manager.addMenuItem(new Appetizer(name, price));
            else if (type == "MainCourse")
                manager.addMenuItem(new MainCourse(name, price));
            else if (type == "Dessert")
                manager.addMenuItem(new Dessert(name, price));
            else
                cout << "Invalid type." << endl;
            break;
        }
        case 2: {
            string name;
            cout << "Enter name: ";
            cin >> name;
            manager.searchMenuItem(name);
            break;
        }
        case 3:
            manager.sortMenuByPrice();
            break;
        case 4:
            manager.displayMenu();
            break;
        case 5:
            manager.saveToFile("output.txt");
            break;
        case 6: {
            string name;
            double price;
            cout << "Enter name and new price: ";
            cin >> name >> price;
            manager.modifyMenuItemPrice(name, price);
            break;
        }
        case 0:
            cout << "Exiting";
            for (int i = 0; i < 5; i++) {
                cout << ".";
                Sleep(500);
            }
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 0);

    return 0;
}