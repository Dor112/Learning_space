#include <iostream>
#include <iomanip>
#include <windows.h>
#include <string>
#include <sstream>

using namespace std;

struct Order {
    string Name;
    int Count;
    double Price;
};

void sortOrders(Order* orders, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (orders[j].Name > orders[j + 1].Name) {
                swap(orders[j], orders[j + 1]);
            }
        }
    }
}

string formatCurrency(double value) {
    ostringstream out;
    out.precision(2);
    out << fixed << value;
    return out.str();
}

int main() {
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int orderCount;
    cout << "������� ���������� ���������� ����: ";
    cin >> orderCount;

    Order* orders = new Order[orderCount];
    double totalCost = 0.0;

    for (int i = 0; i < orderCount; i++) {
        cout << "������� �������� ����� " << (i + 1) << ": ";
        cin.ignore();
        getline(cin, orders[i].Name);

        cout << "������� ���������� ������ ����� " << (i + 1) << ": ";
        cin >> orders[i].Count;

        cout << "������� ��������� �� ������ ����� " << (i + 1) << ": ";
        cin >> orders[i].Price;

        double orderCost = orders[i].Count * orders[i].Price;
        totalCost += orderCost;

        cout << "����� ��������� ������: " << formatCurrency(orderCost) << endl;
    }

    sortOrders(orders, orderCount);

    cout << endl << "���������� �����:" << endl;
    for (int i = 0; i < orderCount; i++) {
        cout << (i + 1) << ". " << orders[i].Name << " - ����������: " << orders[i].Count << ", ��������� �� ������: " << formatCurrency(orders[i].Price) << endl;
    }

    cout << "����� ����� ���� �������: " << formatCurrency(totalCost) << endl;

    delete[] orders;

    return 0;
}