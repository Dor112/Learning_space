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
    cout << "Введите количество заказанных блюд: ";
    cin >> orderCount;

    Order* orders = new Order[orderCount];
    double totalCost = 0.0;

    for (int i = 0; i < orderCount; i++) {
        cout << "Введите название блюда " << (i + 1) << ": ";
        cin.ignore();
        getline(cin, orders[i].Name);

        cout << "Введите количество порций блюда " << (i + 1) << ": ";
        cin >> orders[i].Count;

        cout << "Введите стоимость за порцию блюда " << (i + 1) << ": ";
        cin >> orders[i].Price;

        double orderCost = orders[i].Count * orders[i].Price;
        totalCost += orderCost;

        cout << "Общая стоимость заказа: " << formatCurrency(orderCost) << endl;
    }

    sortOrders(orders, orderCount);

    cout << endl << "Заказанные блюда:" << endl;
    for (int i = 0; i < orderCount; i++) {
        cout << (i + 1) << ". " << orders[i].Name << " - Количество: " << orders[i].Count << ", Стоимость за порцию: " << formatCurrency(orders[i].Price) << endl;
    }

    cout << "Общая сумма всех заказов: " << formatCurrency(totalCost) << endl;

    delete[] orders;

    return 0;
}
