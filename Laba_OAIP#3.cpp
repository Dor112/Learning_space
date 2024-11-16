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

// ���������� ������ �� �����
vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// ���������� ����� � ����
void addDish() {
    ofstream file("menu.txt", ios::app);
    if (!file.is_open()) {
        cerr << "�� ������� ������� ���� menu.txt." << endl;
        return;
    }
    while (true) {
        string name, type;
        double price;

        cout << "������� �������� ����� (��� �������� ������ ��� ����������): ";
        getline(cin, name);
        if (name.empty()) break;

        cout << "������� ��� ����� (�������, �������� �����, �������, �������, ��� �����): ";
        getline(cin, type);

        cout << "������� ���� �����: ";
        cin >> price;
        cin.ignore();

        file << name << ";" << type << ";" << price << endl;
        cout << "����� ���������!" << endl;
    }
    file.close();
}

// ����� ����� �� ��������
void searchDish() {
    ifstream file("menu.txt");
    if (!file.is_open()) {
        cerr << "�� ������� ������� ���� menu.txt." << endl;
        return;
    }

    string searchName;
    cout << "������� �������� ����� ��� ������: ";
    getline(cin, searchName);

    string line;
    bool found = false;
    while (getline(file, line)) {
        vector<string> parts = split(line, ';');
        if (parts[0] == searchName) {
            cout << "������� �����: " << line << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "����� �� �������." << endl;
    }
    file.close();
}

// ������ ���� �� �����
vector<Dish> readDishes() {
    ifstream file("menu.txt");
    vector<Dish> dishes;
    if (!file.is_open()) {
        cerr << "�� ������� ������� ���� menu.txt." << endl;
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

// ���������� ����
void sortDishes() {
    vector<Dish> dishes = readDishes();
    if (dishes.empty()) return;

    int choice;
    cout << "����������� ��: 1 - ���, 2 - ����: ";
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
        cout << "�������� �����!" << endl;
        return;
    }

    cout << "������ ���� ����� ����������:" << endl;
    for (const auto& dish : dishes) {
        cout << dish.name << "; " << dish.type << "; " << dish.price << endl;
    }
}

// ����� ���� � ����� ���� ��������
void filterByPrice() {
    vector<Dish> dishes = readDishes();
    if (dishes.empty()) return;

    double maxPrice;
    cout << "������� ������������ ����: ";
    cin >> maxPrice;
    cin.ignore();

    cout << "����� � ����� �� ���� " << maxPrice << ":" << endl;
    for (const auto& dish : dishes) {
        if (dish.price <= maxPrice) {
            cout << dish.name << "; " << dish.type << "; " << dish.price << endl;
        }
    }
}

// ������� ����
void menu() {
    while (true) {
        cout << "\n����:\n"
             << "1. �������� �����\n"
             << "2. ����� �����\n"
             << "3. ����������� �����\n"
             << "4. ������� ����� � ����� ���� ��������\n"
             << "5. �����\n"
             << "�������� �����: ";
        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: addDish(); break;
            case 2: searchDish(); break;
            case 3: sortDishes(); break;
            case 4: filterByPrice(); break;
            case 5: return;
            default: cout << "�������� �����, ���������� �����." << endl;
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
