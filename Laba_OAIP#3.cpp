#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <windows.h>
using namespace std;

struct Dish {
    string name;
    string type;
    double price;
};

// Разделение строки на части
vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Добавление блюда в файл
void addDish() {
    ofstream file("menu.txt", ios::app);
    if (!file.is_open()) {
        cerr << "Не удалось открыть файл menu.txt." << endl;
        return;
    }
    while (true) {
        string name, type;
        double price;

        cout << "Введите название блюда (или оставьте пустым для завершения): ";
        getline(cin, name);
        if (name.empty()) break;

        cout << "Введите тип блюда (Закуски, Основные блюда, Десерты, Напитки, Для детей): ";
        getline(cin, type);

        cout << "Введите цену блюда: ";
        cin >> price;
        cin.ignore();

        file << name << ";" << type << ";" << price << endl;
        cout << "Блюдо добавлено!" << endl;
    }
    file.close();
}

// Поиск блюда по названию
void searchDish() {
    ifstream file("menu.txt");
    if (!file.is_open()) {
        cerr << "Не удалось открыть файл menu.txt." << endl;
        return;
    }

    string searchName;
    cout << "Введите название блюда для поиска: ";
    getline(cin, searchName);

    string line;
    bool found = false;
    while (getline(file, line)) {
        vector<string> parts = split(line, ';');
        if (parts[0] == searchName) {
            cout << "Найдено блюдо: " << line << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Блюдо не найдено." << endl;
    }
    file.close();
}

// Чтение блюд из файла
vector<Dish> readDishes() {
    ifstream file("menu.txt");
    vector<Dish> dishes;
    if (!file.is_open()) {
        cerr << "Не удалось открыть файл menu.txt." << endl;
        return dishes;
    }

    string line;
    while (getline(file, line)) {
        vector<string> parts = split(line, ';');
        if (parts.size() == 3) {
            Dish dish = { parts[0], parts[1], stod(parts[2]) };
            dishes.push_back(dish);
        }
    }
    file.close();
    return dishes;
}

// Сортировка блюд
void sortDishes() {
    vector<Dish> dishes = readDishes();
    if (dishes.empty()) return;

    int choice;
    cout << "Сортировать по: 1 - Тип, 2 - Цена: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        sort(dishes.begin(), dishes.end(), [](const Dish& a, const Dish& b) {
            return a.type < b.type;
        });
    } else if (choice == 2) {
        sort(dishes.begin(), dishes.end(), [](const Dish& a, const Dish& b) {
            return a.price < b.price;
        });
    } else {
        cout << "Неверный выбор!" << endl;
        return;
    }

    cout << "Список блюд после сортировки:" << endl;
    for (const auto& dish : dishes) {
        cout << dish.name << "; " << dish.type << "; " << dish.price << endl;
    }
}

// Вывод блюд с ценой ниже заданной
void filterByPrice() {
    vector<Dish> dishes = readDishes();
    if (dishes.empty()) return;

    double maxPrice;
    cout << "Введите максимальную цену: ";
    cin >> maxPrice;
    cin.ignore();

    cout << "Блюда с ценой не выше " << maxPrice << ":" << endl;
    for (const auto& dish : dishes) {
        if (dish.price <= maxPrice) {
            cout << dish.name << "; " << dish.type << "; " << dish.price << endl;
        }
    }
}

// Главное меню
void menu() {
    while (true) {
        cout << "\nМеню:\n"
             << "1. Добавить блюдо\n"
             << "2. Поиск блюда\n"
             << "3. Сортировать блюда\n"
             << "4. Вывести блюда с ценой ниже заданной\n"
             << "5. Выход\n"
             << "Выберите опцию: ";
        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: addDish(); break;
            case 2: searchDish(); break;
            case 3: sortDishes(); break;
            case 4: filterByPrice(); break;
            case 5: return;
            default: cout << "Неверный выбор, попробуйте снова." << endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    menu();
    return 0;
}
