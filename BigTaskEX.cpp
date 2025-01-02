#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <fstream>
#include <pqxx/pqxx>

class User {
public:
    virtual void createOrder() = 0;
    virtual void viewOrderStatus(int orderId) = 0;
    virtual void cancelOrder(int orderId) = 0;
    virtual ~User() = default;
};

class Admin : public User {
public:
    void createOrder() override {
        try {
            // Подключаемся к базе данных
            pqxx::connection C("dbname=your_db_name user=your_username password=your_password host=localhost port=5432");

            if (C.is_open()) {
                std::cout << "Connected to database: " << C.dbname() << std::endl;
            }
            else {
                std::cerr << "Can't open database" << std::endl;
            }

            // Создаем транзакцию
            pqxx::work W(C);

            // SQL-запрос для вставки данных в таблицу
            std::string query = "INSERT INTO your_table (column1, column2) VALUES ('value1', 'value2');";

            // Выполняем запрос
            W.exec(query);

            // Подтверждаем транзакцию
            W.commit();

            std::cout << "Record inserted successfully!" << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

    }
    
    void viewOrderStatus(int orderId) override {
        try {
            pqxx::connection C("dbname=your_db_name user=your_username password=your_password host=localhost port=5432");

            if (C.is_open()) {
                std::cout << "Connected to database: " << C.dbname() << std::endl;
            }
            else {
                std::cerr << "Can't open database" << std::endl;
                
            }

            pqxx::work W(C);

            // SQL-запрос
            std::string query = "SELECT * FROM your_table;";

            // Логирование запроса
            std::cout << "Executing query: " << query << std::endl;

            // Выполнение запроса
            pqxx::result R = W.exec(query);

            // Подтверждаем транзакцию (необходимо для операций, изменяющих данные)
            W.commit();

            // Вывод результата
            for (const auto& row : R) {
                std::cout << row[0].c_str() << std::endl;
            }

        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

       
    }
    
    void cancelOrder(int orderId) override {
        try {
            // Подключаемся к базе данных
            pqxx::connection C("dbname=your_db_name user=your_username password=your_password host=localhost port=5432");

            if (C.is_open()) {
                std::cout << "Connected to database: " << C.dbname() << std::endl;
            }
            else {
                std::cerr << "Can't open database" << std::endl;
                
            }

            // Создаем транзакцию
            pqxx::work W(C);

            // SQL-запрос для удаления строки
            std::string query = "DELETE FROM your_table WHERE your_column = 'value_to_delete';";

            // Выполняем запрос
            W.exec(query);

            // Подтверждаем транзакцию
            W.commit();

            std::cout << "Row deleted successfully!" << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

       
    }
    

    void addProduct() {
        try {
            // Подключаемся к базе данных
            pqxx::connection C("dbname=your_db_name user=your_username password=your_password host=localhost port=5432");

            if (C.is_open()) {
                std::cout << "Connected to database: " << C.dbname() << std::endl;
            }
            else {
                std::cerr << "Can't open database" << std::endl;
             
            }

            // Создаем транзакцию
            pqxx::work W(C);

            // SQL-запрос для добавления строки
            std::string query = "INSERT INTO your_table (column1, column2) VALUES ('value1', 'value2');";

            // Выполняем запрос
            W.exec(query);

            // Подтверждаем транзакцию
            W.commit();

            std::cout << "Row inserted successfully!" << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

       
    }
    
    void updateProduct() {
        try {
            // Подключаемся к базе данных
            pqxx::connection C("dbname=your_db_name user=your_username password=your_password host=localhost port=5432");

            if (C.is_open()) {
                std::cout << "Connected to database: " << C.dbname() << std::endl;
            }
            else {
                std::cerr << "Can't open database" << std::endl;
               
            }

            // Создаем транзакцию
            pqxx::work W(C);

            // SQL-запрос для обновления данных
            std::string query = "UPDATE your_table SET column1 = 'new_value1', column2 = 'new_value2' WHERE your_column = 'condition_value';";

            // Выполняем запрос
            W.exec(query);

            // Подтверждаем транзакцию
            W.commit();

            std::cout << "Row updated successfully!" << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

      
    }
    void deleteProduct() {
        try {
            // Подключаемся к базе данных
            pqxx::connection C("dbname=your_db_name user=your_username password=your_password host=localhost port=5432");

            if (C.is_open()) {
                std::cout << "Connected to database: " << C.dbname() << std::endl;
            }
            else {
                std::cerr << "Can't open database" << std::endl;

            }

            // Создаем транзакцию
            pqxx::work W(C);

            // SQL-запрос для удаления строки
            std::string query = "DELETE FROM your_table WHERE your_column = 'value_to_delete';";

            // Выполняем запрос
            W.exec(query);

            // Подтверждаем транзакцию
            W.commit();

            std::cout << "Row deleted successfully!" << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }


    }
    void viewAllOrders() {
        try {
            pqxx::connection C("dbname=your_db_name user=your_username password=your_password host=localhost port=5432");

            if (C.is_open()) {
                std::cout << "Connected to database: " << C.dbname() << std::endl;
            }
            else {
                std::cerr << "Can't open database" << std::endl;

            }

            pqxx::work W(C);

            // SQL-запрос
            std::string query = "SELECT * FROM your_table;";

            // Логирование запроса
            std::cout << "Executing query: " << query << std::endl;

            // Выполнение запроса
            pqxx::result R = W.exec(query);

            // Подтверждаем транзакцию (необходимо для операций, изменяющих данные)
            W.commit();

            // Вывод результата
            for (const auto& row : R) {
                std::cout << row[0].c_str() << std::endl;
            }

        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    void updateOrderStatus() {
        try {
            // Подключаемся к базе данных
            pqxx::connection C("dbname=your_db_name user=your_username password=your_password host=localhost port=5432");

            if (C.is_open()) {
                std::cout << "Connected to database: " << C.dbname() << std::endl;
            }
            else {
                std::cerr << "Can't open database" << std::endl;

            }

            // Создаем транзакцию
            pqxx::work W(C);

            // SQL-запрос для обновления данных
            std::string query = "UPDATE your_table SET column1 = 'new_value1', column2 = 'new_value2' WHERE your_column = 'condition_value';";

            // Выполняем запрос
            W.exec(query);

            // Подтверждаем транзакцию
            W.commit();

            std::cout << "Row updated successfully!" << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }


    
    }
};

class Manager : public User {
public:
    void createOrder() override {
        try {
            // Подключаемся к базе данных
            pqxx::connection C("dbname=your_db_name user=your_username password=your_password host=localhost port=5432");

            if (C.is_open()) {
                std::cout << "Connected to database: " << C.dbname() << std::endl;
            }
            else {
                std::cerr << "Can't open database" << std::endl;
            }

            // Создаем транзакцию
            pqxx::work W(C);

            // SQL-запрос для вставки данных в таблицу
            std::string query = "INSERT INTO your_table (column1, column2) VALUES ('value1', 'value2');";

            // Выполняем запрос
            W.exec(query);

            // Подтверждаем транзакцию
            W.commit();

            std::cout << "Record inserted successfully!" << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    void viewOrderStatus(int orderId) override {
        try {
            pqxx::connection C("dbname=your_db_name user=your_username password=your_password host=localhost port=5432");

            if (C.is_open()) {
                std::cout << "Connected to database: " << C.dbname() << std::endl;
            }
            else {
                std::cerr << "Can't open database" << std::endl;

            }

            pqxx::work W(C);

            // SQL-запрос
            std::string query = "SELECT * FROM your_table;";

            // Логирование запроса
            std::cout << "Executing query: " << query << std::endl;

            // Выполнение запроса
            pqxx::result R = W.exec(query);

            // Подтверждаем транзакцию (необходимо для операций, изменяющих данные)
            W.commit();

            // Вывод результата
            for (const auto& row : R) {
                std::cout << row[0].c_str() << std::endl;
            }

        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }


    }
    void cancelOrder(int orderId) override {
        try {
            // Подключаемся к базе данных
            pqxx::connection C("dbname=your_db_name user=your_username password=your_password host=localhost port=5432");

            if (C.is_open()) {
                std::cout << "Connected to database: " << C.dbname() << std::endl;
            }
            else {
                std::cerr << "Can't open database" << std::endl;

            }

            // Создаем транзакцию
            pqxx::work W(C);

            // SQL-запрос для удаления строки
            std::string query = "DELETE FROM your_table WHERE your_column = 'value_to_delete';";

            // Выполняем запрос
            W.exec(query);

            // Подтверждаем транзакцию
            W.commit();

            std::cout << "Row deleted successfully!" << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }

    void approveOrder() {
        try {
            // Подключаемся к базе данных
            pqxx::connection C("dbname=your_db_name user=your_username password=your_password host=localhost port=5432");

            if (C.is_open()) {
                std::cout << "Connected to database: " << C.dbname() << std::endl;
            }
            else {
                std::cerr << "Can't open database" << std::endl;
               
            }

            // Создаем транзакцию
            pqxx::work W(C);

            // Пример SQL-запроса для вставки данных
            std::string query = "INSERT INTO your_table (column1, column2) VALUES ('value1', 'value2');";

            // Выполняем запрос
            W.exec(query);

            // Подтверждаем транзакцию (фиксируем изменения)
            W.commit();

            std::cout << "Changes committed successfully!" << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

       
    }
    void updateStock() {
        try {
            // Подключаемся к базе данных
            pqxx::connection C("dbname=your_db_name user=your_username password=your_password host=localhost port=5432");

            if (C.is_open()) {
                std::cout << "Connected to database: " << C.dbname() << std::endl;
            }
            else {
                std::cerr << "Can't open database" << std::endl;
                
            }

            // Создаем транзакцию
            pqxx::work W(C);

            // SQL-запрос для обновления данных
            std::string query = "UPDATE your_table SET column1 = 'new_value1', column2 = 'new_value2' WHERE your_column = 'condition_value';";

            // Выполняем запрос
            W.exec(query);

            // Подтверждаем транзакцию
            W.commit();

            std::cout << "Row updated successfully!" << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        
    }

};

class Customer : public User {
public:
    void createOrder() override {
        try {
            // Подключаемся к базе данных
            pqxx::connection C("dbname=your_db_name user=your_username password=your_password host=localhost port=5432");

            if (C.is_open()) {
                std::cout << "Connected to database: " << C.dbname() << std::endl;
            }
            else {
                std::cerr << "Can't open database" << std::endl;
            }

            // Создаем транзакцию
            pqxx::work W(C);

            // SQL-запрос для вставки данных в таблицу
            std::string query = "INSERT INTO your_table (column1, column2) VALUES ('value1', 'value2');";

            // Выполняем запрос
            W.exec(query);

            // Подтверждаем транзакцию
            W.commit();

            std::cout << "Record inserted successfully!" << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    void viewOrderStatus(int orderId) override {
        try {
            pqxx::connection C("dbname=your_db_name user=your_username password=your_password host=localhost port=5432");

            if (C.is_open()) {
                std::cout << "Connected to database: " << C.dbname() << std::endl;
            }
            else {
                std::cerr << "Can't open database" << std::endl;

            }

            pqxx::work W(C);

            // SQL-запрос
            std::string query = "SELECT * FROM your_table;";

            // Логирование запроса
            std::cout << "Executing query: " << query << std::endl;

            // Выполнение запроса
            pqxx::result R = W.exec(query);

            // Подтверждаем транзакцию (необходимо для операций, изменяющих данные)
            W.commit();

            // Вывод результата
            for (const auto& row : R) {
                std::cout << row[0].c_str() << std::endl;
            }

        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    void cancelOrder(int orderId) override {
        try {
            // Подключаемся к базе данных
            pqxx::connection C("dbname=your_db_name user=your_username password=your_password host=localhost port=5432");

            if (C.is_open()) {
                std::cout << "Connected to database: " << C.dbname() << std::endl;
            }
            else {
                std::cerr << "Can't open database" << std::endl;

            }

            // Создаем транзакцию
            pqxx::work W(C);

            // SQL-запрос для удаления строки
            std::string query = "DELETE FROM your_table WHERE your_column = 'value_to_delete';";

            // Выполняем запрос
            W.exec(query);

            // Подтверждаем транзакцию
            W.commit();

            std::cout << "Row deleted successfully!" << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }

    void addToOrder() {
        try {
            // Подключаемся к базе данных
            pqxx::connection C("dbname=your_db_name user=your_username password=your_password host=localhost port=5432");

            if (C.is_open()) {
                std::cout << "Connected to database: " << C.dbname() << std::endl;
            }
            else {
                std::cerr << "Can't open database" << std::endl;
            }

            // Создаем транзакцию
            pqxx::work W(C);

            // SQL-запрос для вставки данных в таблицу
            std::string query = "INSERT INTO your_table (column1, column2) VALUES ('value1', 'value2');";

            // Выполняем запрос
            W.exec(query);

            // Подтверждаем транзакцию
            W.commit();

            std::cout << "Record inserted successfully!" << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    void removeFromOrder() {
        try {
            // Подключаемся к базе данных
            pqxx::connection C("dbname=your_db_name user=your_username password=your_password host=localhost port=5432");

            if (C.is_open()) {
                std::cout << "Connected to database: " << C.dbname() << std::endl;
            }
            else {
                std::cerr << "Can't open database" << std::endl;

            }

            // Создаем транзакцию
            pqxx::work W(C);

            // SQL-запрос для удаления строки
            std::string query = "DELETE FROM your_table WHERE your_column = 'value_to_delete';";

            // Выполняем запрос
            W.exec(query);

            // Подтверждаем транзакцию
            W.commit();

            std::cout << "Row deleted successfully!" << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    void makePayment() {
        std::cout << "Customer making payment...\n";
    }
};

class DatabaseConnection {
public:
    DatabaseConnection(const std::string& connStr) {
        try {
            conn = std::make_shared<pqxx::connection>(connStr);
            std::cout << "Connected to database.\n";
        }
        catch (const std::exception& e) {
            std::cerr << "Connection failed: " << e.what() << std::endl;
        }
    }

    void executeQuery(const std::string& query) {
        pqxx::work w(*conn);
        pqxx::result r = w.exec(query);
        std::cout << "Executed query: " << query << std::endl;
        for (const auto& row : r) {
            for (const auto& field : row) {
                std::cout << field.c_str() << " ";
            }
            std::cout << std::endl;
        }
    }

    void executeNonQuery(const std::string& query) {
        pqxx::work w(*conn);
        w.exec(query);
        w.commit();
        std::cout << "Executed non-query: " << query << std::endl;
    }

    

private:
    std::shared_ptr<pqxx::connection> conn;
};

void logAction(const std::string& action) {
    std::ofstream logFile("log.txt", std::ios::app);
    logFile << action << std::endl;
}

void showMainMenu() {
    std::cout << "Please choose your role:\n";
    std::cout << "1. Admin\n";
    std::cout << "2. Manager\n";
    std::cout << "3. Customer\n";
    std::cout << "4. Exit\n";

    int choice;
    std::cin >> choice;

    std::shared_ptr<User> user;

    switch (choice) {
    case 1:
        user = std::make_shared<Admin>();
        break;
    case 2:
        user = std::make_shared<Manager>();
        break;
    case 3:
        user = std::make_shared<Customer>();
        break;
    case 4:
        std::exit(0);
    default:
        std::cout << "Invalid choice\n";
        return;
    }

    // Show role-specific menu
    if (choice == 1) {
        // Admin menu
        std::cout << "Admin menu:\n";
        std::cout << "1. Add Product\n";
        std::cout << "2. View Orders\n";
        std::cout << "3. Update Order Status\n";
        std::cout << "4. Create Oreder\n";
        std::cout << "5. View Order Status\n";
        std::cout << "6. Cancel Order\n";
        std::cout << "7. Update Product\n";
        std::cout << "8. Delete Product\n";
        
        int action;
        std::cin >> action;
        if (action == 1) {
            std::dynamic_pointer_cast<Admin>(user)->addProduct();
        }
        else if (action == 2) {
            std::dynamic_pointer_cast<Admin>(user)->viewAllOrders();
        }
        else if (action == 3) {
            std::dynamic_pointer_cast<Admin>(user)->updateOrderStatus();
        }
        else if (action == 4) {
            std::dynamic_pointer_cast<Admin>(user)->createOrder();
        }
        else if (action == 5) {
            std::dynamic_pointer_cast<Admin>(user)->viewOrderStatus(1); //requires id
        }
        else if (action == 6) {
            std::dynamic_pointer_cast<Admin>(user)->cancelOrder(2); //requires id
        }
        else if (action == 7) {
            std::dynamic_pointer_cast<Admin>(user)->updateProduct();
        }
        else if (action == 8) {
            std::dynamic_pointer_cast<Admin>(user)->deleteProduct();
        }

    }
    else if (choice == 2) {
        // Manager menu
        std::cout << "Manager menu:\n";
        std::cout << "1. Approve Order\n";
        std::cout << "2. Update Stock\n";
        std::cout << "3. Create Order\n";
        std::cout << "4. View Order Status\n";
        std::cout << "5. Cancel Order\n";

        int action;
        std::cin >> action;
        if (action == 1) {
            std::dynamic_pointer_cast<Manager>(user)->approveOrder();
        }
        else if (action == 2) {
            std::dynamic_pointer_cast<Manager>(user)->updateStock();
        }
        else if (action == 3) {
            std::dynamic_pointer_cast<Admin>(user)->createOrder();
        }
        else if (action == 4) {
            std::dynamic_pointer_cast<Admin>(user)->viewOrderStatus(1); //requires id
        }
        else if (action == 5) {
            std::dynamic_pointer_cast<Admin>(user)->cancelOrder(2); //requires id
        }

    }
    else if (choice == 3) {
        // Customer menu
        std::cout << "Customer menu:\n";
        std::cout << "1. Create Order\n";
        std::cout << "2. View Order Status\n";
        std::cout << "3. Cancel Order\n";
        std::cout << "4. Add to Order\n";
        std::cout << "5. Remove from Oreder\n";
        std::cout << "6. Make payment\n";

        int action;
        std::cin >> action;
        if (action == 1) {
            std::dynamic_pointer_cast<Customer>(user)->createOrder();
        }
        else if (action == 2) {
            std::dynamic_pointer_cast<Customer>(user)->viewOrderStatus(1);
        }
        else if (action == 3) {
            std::dynamic_pointer_cast<Customer>(user)->cancelOrder(1);  // Example OrderId
        }
        else if (action == 4) {
            std::dynamic_pointer_cast<Customer>(user)->addToOrder();  // Example OrderId
        }
        else if (action == 5) {
            std::dynamic_pointer_cast<Customer>(user)->removeFromOrder();  // Example OrderId
        }
        else if (action == 6) {
            std::dynamic_pointer_cast<Customer>(user)->makePayment();  // Example OrderId
            std::dynamic_pointer_cast<Customer>(user)->makePayment();  // Example OrderId
        }
    }

    // Log action
    logAction("User performed an action.");
}

int main() {
    showMainMenu();
    return 0;
}
