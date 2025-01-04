#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <fstream>
#include <pqxx/pqxx>
#include <windows.h>
using namespace std;
using namespace pqxx;
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
            
            connection C("dbname=bigtaskdb user=postgres password=A27032006 host=localhost port=5432");

            if (C.is_open()) {
                cout << "Connected to database: " << C.dbname() << endl;
            }
            else {
                cerr << "Can't open database" << endl;
            }
            
            work W(C);
            int order_id;
            int user_id;
            string status;
            int total_price;
            string order_date;
            cout << "Enter order_id: ";
            cin >> order_id;
            cout << "Enter user_id: ";
            cin >> user_id;
            cout << "Enter status: ";
            cin >> status;
            cout << "Enter total_price: ";
            cin >> total_price;
            cout << "Enter order_date: ";
            cin >> order_date;
            
            string query = "INSERT INTO orders (order_id, user_id, status, total_price, order_date) VALUES (" +
                to_string(order_id) + ", " + to_string(user_id) + ", " + W.quote(status) + ", " + to_string(total_price) + ", " + W.quote(order_date) + ");";
            
            
            W.exec(query);

            
            W.commit();

            cout << "Record inserted successfully!" << endl;
        }
        catch (const exception& e) {
            cerr << e.what() << endl;
        }

    }
    
    void viewOrderStatus(int orderId) override {
        
        try {
            connection C("dbname=bigtaskdb user=postgres password=A27032006 host=localhost port=5432");

            if (C.is_open()) {
                cout << "Connected to database: " << C.dbname() << endl;
            }
            else {
                cerr << "Can't open database" << endl;
                
            }
            
            work W(C);
            int id;
            cout << "Enter id which status you want to see: ";
            cin >> id;
            string query = "SELECT * FROM orders WHERE order_id = " + to_string(id) +";";
        
            cout << "Executing query: " << query << endl;

            result result = W.exec(query);
            for (const auto& row : result) {
                cout << "order_id: " << row["order_id"].as<int>() << endl;
                cout << "user_id: " << row["user_id"].as<int>() << endl;
                cout << "status: " << row["status"].as<string>() << endl;
                cout << "total_price: " << row["total_price"].as<float>() << endl;
                cout << "order_date: " << row["order_date"].as<string>() << endl;
                
            }
            W.commit();

            

        }
        catch (const exception& e) {
            cerr << e.what() << endl;
        }

       
    }
    
    void cancelOrder(int orderId) override {
        int id;
        try {
            
            connection C("dbname=bigtaskdb user=postgres password=A27032006 host=localhost port=5432");

            if (C.is_open()) {
                cout << "Connected to database: " << C.dbname() << endl;
            }
            else {
                cerr << "Can't open database" << endl;
                
            }

            
            work W(C);
            cout << "Enter id which status you want to delete: ";
            cin >> id;
            
            string query = "DELETE FROM orders WHERE order_id =" + to_string(id) + ";";
            
        
            W.exec(query);

            
            W.commit();

            cout << "Row deleted successfully!" << endl;
        }
        catch (const exception& e) {
            cerr << e.what() << endl;
        }

       
    }
    

    void addProduct() {
        
        try {
            
            connection C("dbname=bigtaskdb user=postgres password=A27032006 host=localhost port=5432");

            if (C.is_open()) {
                cout << "Connected to database: " << C.dbname() << endl;
            }
            else {
                cerr << "Can't open database" << endl;
             
            }

            
            work W(C);
            int product_id;
            string name;
            int price;
            int stock_quantity;
            cout << "Enter product_id: ";
            cin >> product_id;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter price: ";
            cin >> price;
            cout << "Enter stock_quantity: ";
            cin >> stock_quantity;
           
            
            string query = "INSERT INTO products (product_id, name, price, stock_quantity ) VALUES (" +
                to_string(product_id) + ", " + W.quote(name) + ", "+ to_string(price) +", " + to_string(stock_quantity) + ");";
            
            
            W.exec(query);

            
            W.commit();

            cout << "Row inserted successfully!" << endl;
        }
        catch (const exception& e) {
            cerr << e.what() << endl;
        }

       
    }
    
    void updateProduct() {
        try {
            
            connection C("dbname=bigtaskdb user=postgres password=A27032006 host=localhost port=5432");

            if (C.is_open()) {
                cout << "Connected to database: " << C.dbname() << endl;
            }
            else {
                cerr << "Can't open database" << endl;
               
            }

            
            work W(C);
            int product_id;
            string name;
            int price;
            int stock_quantity;
            cout << "Enter product_id: ";
            cin >> product_id;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter price: ";
            cin >> price;
            cout << "Enter stock_quantity: ";
            cin >> stock_quantity;
            
            string query = "UPDATE products SET product_id =" + to_string(product_id) + "," + "name =" + W.quote(name) + ", price =" + to_string(price) + ", stock_quantity =" + to_string(stock_quantity) + " WHERE product_id =" + to_string(product_id)+ ";";


            W.exec(query);

            W.commit();

            cout << "Row updated successfully!" << endl;
        }
        catch (const exception& e) {
            cerr << e.what() << endl;
        }

      
    }
    void deleteProduct() {
        try {
            
            connection C("dbname=bigtaskdb user=postgres password=A27032006 host=localhost port=5432");

            if (C.is_open()) {
                cout << "Connected to database: " << C.dbname() << endl;
            }
            else {
                cerr << "Can't open database" << endl;

            }

            
            work W(C);
            int product_id;
            cout << "Enter id which status you want to delete: ";
            cin >> product_id;

            string query = "DELETE FROM products WHERE product_id =" + to_string(product_id) + ";";

            W.exec(query);

            W.commit();

            cout << "Row deleted successfully!" << endl;
        }
        catch (const exception& e) {
            cerr << e.what() << endl;
        }


    }
    void viewAllOrders() {
        try {
            connection C("dbname=bigtaskdb user=postgres password=A27032006 host=localhost port=5432");

            if (C.is_open()) {
                cout << "Connected to database: " << C.dbname() << endl;
            }
            else {
                cerr << "Can't open database" << endl;

            }

            work W(C);

            string query = "SELECT * FROM orders;";

            
            cout << "Executing query: " << query << endl;

            result result = W.exec(query);
            for (const auto& row : result) {
                cout << "order_id: " << row["order_id"].as<int>() << endl;
                cout << "user_id: " << row["user_id"].as<int>() << endl;
                cout << "status: " << row["status"].as<string>() << endl;
                cout << "total_price: " << row["total_price"].as<float>() << endl;
                cout << "order_date: " << row["order_date"].as<string>() << endl;
                cout << "" << endl;
            }
            W.commit();

        }
        catch (const exception& e) {
            cerr << e.what() << endl;
        }
    }
    void updateOrderStatus() {
        try {
            
            connection C("dbname=bigtaskdb user=postgres password=A27032006 host=localhost port=5432");

            if (C.is_open()) {
                cout << "Connected to database: " << C.dbname() << endl;
            }
            else {
                cerr << "Can't open database" << endl;

            }

            
            work W(C);
            int order_id;
            int order_id_to;
            int user_id;
            string status;
            int total_price;
            string order_date;
            cout << "Enter order_id which you want to change: ";
            cin >> order_id_to;
            cout << "Enter order_id: ";
            cin >> order_id;
            cout << "Enter user_id: ";
            cin >> user_id;
            cout << "Enter status: ";
            cin >> status;
            cout << "Enter total_price: ";
            cin >> total_price;
            cout << "Enter order_date: ";
            cin >> order_date;
            
            string query = "UPDATE orders SET order_id = "+ to_string(order_id) + ", user_id ="+ to_string(user_id) + ", status =" + W.quote(status) + ", total_price =" +to_string(total_price) + ", order_date =" + W.quote(order_date)+" WHERE order_id =" +to_string(order_id_to) +"; ";

            
            W.exec(query);

            
            W.commit();

            cout << "Row updated successfully!" << endl;
        }
        catch (const exception& e) {
            cerr << e.what() << endl;
        }


    
    }
};

class Manager : public User {
public:
    void createOrder() override {
        try {

            connection C("dbname=bigtaskdb user=postgres password=A27032006 host=localhost port=5432");

            if (C.is_open()) {
                cout << "Connected to database: " << C.dbname() << endl;
            }
            else {
                cerr << "Can't open database" << endl;
            }

            work W(C);
            int order_id;
            int user_id;
            string status;
            int total_price;
            string order_date;
            cout << "Enter order_id: ";
            cin >> order_id;
            cout << "Enter user_id: ";
            cin >> user_id;
            cout << "Enter status: ";
            cin >> status;
            cout << "Enter total_price: ";
            cin >> total_price;
            cout << "Enter order_date: ";
            cin >> order_date;

            string query = "INSERT INTO orders (order_id, user_id, status, total_price, order_date) VALUES (" +
                to_string(order_id) + ", " + to_string(user_id) + ", " + W.quote(status) + ", " + to_string(total_price) + ", " + W.quote(order_date) + ");";


            W.exec(query);


            W.commit();

            cout << "Record inserted successfully!" << endl;
        }
        catch (const exception& e) {
            cerr << e.what() << endl;
        }

    }
    void viewOrderStatus(int orderId) override {
        try {
            connection C("dbname=bigtaskdb user=postgres password=A27032006 host=localhost port=5432");

            if (C.is_open()) {
                cout << "Connected to database: " << C.dbname() << endl;
            }
            else {
                cerr << "Can't open database" << endl;

            }

            work W(C);
            int id;
            cout << "Enter id which status you want to see: ";
            cin >> id;
            string query = "SELECT * FROM orders WHERE order_id = " + to_string(id) + ";";

            cout << "Executing query: " << query << endl;

            result result = W.exec(query);
            for (const auto& row : result) {
                cout << "order_id: " << row["order_id"].as<int>() << endl;
                cout << "user_id: " << row["user_id"].as<int>() << endl;
                cout << "status: " << row["status"].as<string>() << endl;
                cout << "total_price: " << row["total_price"].as<float>() << endl;
                cout << "order_date: " << row["order_date"].as<string>() << endl;

            }
            W.commit();



        }
        catch (const exception& e) {
            cerr << e.what() << endl;
        }


    }
    void cancelOrder(int orderId) override {
        int id;
        try {

            connection C("dbname=bigtaskdb user=postgres password=A27032006 host=localhost port=5432");

            if (C.is_open()) {
                cout << "Connected to database: " << C.dbname() << endl;
            }
            else {
                cerr << "Can't open database" << endl;

            }


            work W(C);
            cout << "Enter id which status you want to cancel: ";
            cin >> id;
            string cancled = "canceled";

            string query = "UPDATE orders SET status =" + W.quote(cancled)+ "WHERE order_id = " + to_string(id) + "; ";
                 

            W.exec(query);


            W.commit();

            cout << "Row deleted successfully!" << endl;
        }
        catch (const exception& e) {
            cerr << e.what() << endl;
        }


    }

    void approveOrder() {
        int id;
        try {

            connection C("dbname=bigtaskdb user=postgres password=A27032006 host=localhost port=5432");

            if (C.is_open()) {
                cout << "Connected to database: " << C.dbname() << endl;
            }
            else {
                cerr << "Can't open database" << endl;

            }


            work W(C);
            cout << "Enter id which status you want to approve: ";
            cin >> id;
            string completed = "completed";

            string query = "UPDATE orders SET status =" + W.quote(completed) + "WHERE order_id = " + to_string(id) + "; ";


            W.exec(query);


            W.commit();

            cout << "Row deleted successfully!" << endl;
        }
        catch (const exception& e) {
            cerr << e.what() << endl;
        }
    }
    void updateStock() {
        try {
            
            connection C("dbname=bigtaskdb user=postgres password=A27032006 host=localhost port=5432");

            if (C.is_open()) {
                cout << "Connected to database: " << C.dbname() << endl;
            }
            else {
                cerr << "Can't open database" << endl;
                
            }

            
            work W(C);
            int product_id;
            cout << "Enter peoduct_id which you want to change: ";
            cin >> product_id;
            int stock_quantity;
            cout << "Enter the number of stock: ";
            cin >> stock_quantity;
            string query = "UPDATE products SET stock_quantity ="+ to_string(stock_quantity) + " WHERE product_id ="+ to_string(product_id) + ";";

            W.exec(query);

            W.commit();

            cout << "Row updated successfully!" << endl;
        }
        catch (const exception& e) {
            cerr << e.what() << endl;
        }

        
    }

};

class Customer : public User {
public:
    void createOrder() override {
        try {

            connection C("dbname=bigtaskdb user=postgres password=A27032006 host=localhost port=5432");

            if (C.is_open()) {
                cout << "Connected to database: " << C.dbname() << endl;
            }
            else {
                cerr << "Can't open database" << endl;
            }

            work W(C);
            int order_id;
            int user_id;
            string status;
            int total_price;
            string order_date;
            cout << "Enter order_id: ";
            cin >> order_id;
            cout << "Enter user_id: ";
            cin >> user_id;
            cout << "Enter status: ";
            cin >> status;
            cout << "Enter total_price: ";
            cin >> total_price;
            cout << "Enter order_date: ";
            cin >> order_date;

            string query = "INSERT INTO orders (order_id, user_id, status, total_price, order_date) VALUES (" +
                to_string(order_id) + ", " + to_string(user_id) + ", " + W.quote(status) + ", " + to_string(total_price) + ", " + W.quote(order_date) + ");";


            W.exec(query);


            W.commit();

            cout << "Record inserted successfully!" << endl;
        }
        catch (const exception& e) {
            cerr << e.what() << endl;
        }

    }
    void viewOrderStatus(int orderId) override {
        try {
            connection C("dbname=bigtaskdb user=postgres password=A27032006 host=localhost port=5432");

            if (C.is_open()) {
                cout << "Connected to database: " << C.dbname() << endl;
            }
            else {
                cerr << "Can't open database" << endl;

            }

            work W(C);
            int id;
            cout << "Enter id which status you want to see: ";
            cin >> id;
            string query = "SELECT * FROM orders WHERE order_id = " + to_string(id) + ";";

            cout << "Executing query: " << query << endl;

            result result = W.exec(query);
            for (const auto& row : result) {
                cout << "order_id: " << row["order_id"].as<int>() << endl;
                cout << "user_id: " << row["user_id"].as<int>() << endl;
                cout << "status: " << row["status"].as<string>() << endl;
                cout << "total_price: " << row["total_price"].as<float>() << endl;
                cout << "order_date: " << row["order_date"].as<string>() << endl;

            }
            W.commit();



        }
        catch (const exception& e) {
            cerr << e.what() << endl;
        }


    }
    void cancelOrder(int orderId) override {
        int id;
        try {

            connection C("dbname=bigtaskdb user=postgres password=A27032006 host=localhost port=5432");

            if (C.is_open()) {
                cout << "Connected to database: " << C.dbname() << endl;
            }
            else {
                cerr << "Can't open database" << endl;

            }


            work W(C);
            cout << "Enter id which status you want to cancel: ";
            cin >> id;
            string cancled = "canceled";

            string query = "UPDATE orders SET status =" + W.quote(cancled) + "WHERE order_id = " + to_string(id) + "; ";


            W.exec(query);


            W.commit();

            cout << "Row deleted successfully!" << endl;
        }
        catch (const exception& e) {
            cerr << e.what() << endl;
        }


    }

    void addToOrder(){
        try {

            connection C("dbname=bigtaskdb user=postgres password=A27032006 host=localhost port=5432");

            if (C.is_open()) {
                cout << "Connected to database: " << C.dbname() << endl;
            }
            else {
                cerr << "Can't open database" << endl;
            }

            work W(C);
            int order_id;
            int user_id;
            string status;
            int total_price;
            string order_date;
            cout << "Enter order_id: ";
            cin >> order_id;
            cout << "Enter user_id: ";
            cin >> user_id;
            cout << "Enter status: ";
            cin >> status;
            cout << "Enter total_price: ";
            cin >> total_price;
            cout << "Enter order_date: ";
            cin >> order_date;

            string query = "INSERT INTO orders (order_id, user_id, status, total_price, order_date) VALUES (" +
                to_string(order_id) + ", " + to_string(user_id) + ", " + W.quote(status) + ", " + to_string(total_price) + ", " + W.quote(order_date) + ");";


            W.exec(query);


            W.commit();

            cout << "Record inserted successfully!" << endl;
        }
        catch (const exception& e) {
            cerr << e.what() << endl;
        }

    }
    void removeFromOrder() {
        try {

            connection C("dbname=bigtaskdb user=postgres password=A27032006 host=localhost port=5432");

            if (C.is_open()) {
                cout << "Connected to database: " << C.dbname() << endl;
            }
            else {
                cerr << "Can't open database" << endl;

            }


            work W(C);
            int order_id;
            cout << "Enter id which order you want to delete: ";
            cin >> order_id;

            string query = "DELETE FROM orders WHERE order_id =" + to_string(order_id) + ";";

            W.exec(query);

            W.commit();

            cout << "Row deleted successfully!" << endl;
        }
        catch (const exception& e) {
            cerr << e.what() << endl;
        }


    }
    void makePayment() {
        cout << "Customer making payment...\n";
    }
};



void logAction(const string& action) {
    ofstream logFile("log.txt", ios::app);
    logFile << action << endl;
}

void showMainMenu() {

    cout << "Please choose your role:\n";
    cout << "1. Admin\n";
    cout << "2. Manager\n";
    cout << "3. Customer\n";
    cout << "4. Exit\n";

    int choice;
    cin >> choice;

    shared_ptr<User> user;

    switch (choice) {
    case 1:
        user = make_shared<Admin>();
        break;
    case 2:
        user = make_shared<Manager>();
        break;
    case 3:
        user = make_shared<Customer>();
        break;
    case 4:
        exit(0);
    default:
        cout << "Invalid choice\n";
        return;
    }

    // Show role-specific menu
    if (choice == 1) {
        // Admin menu
        cout << "Admin menu:\n";
        cout << "1. Add Product\n";
        cout << "2. View Orders\n";
        cout << "3. Update Order Status\n";
        cout << "4. Create Oreder\n";
        cout << "5. View Order Status\n";
        cout << "6. Cancel Order\n";
        cout << "7. Update Product\n";
        cout << "8. Delete Product\n";
        
        int action;
        cin >> action;
        if (action == 1) {
            dynamic_pointer_cast<Admin>(user)->addProduct();
        }
        else if (action == 2) {
            dynamic_pointer_cast<Admin>(user)->viewAllOrders();
        }
        else if (action == 3) {
            dynamic_pointer_cast<Admin>(user)->updateOrderStatus();
        }
        else if (action == 4) {
            dynamic_pointer_cast<Admin>(user)->createOrder();
        }
        else if (action == 5) {
            dynamic_pointer_cast<Admin>(user)->viewOrderStatus(1); //requires id
        }
        else if (action == 6) {
            dynamic_pointer_cast<Admin>(user)->cancelOrder(2); //requires id
        }
        else if (action == 7) {
            dynamic_pointer_cast<Admin>(user)->updateProduct();
        }
        else if (action == 8) {
            dynamic_pointer_cast<Admin>(user)->deleteProduct();
        }

    }
    else if (choice == 2) {
        // Manager menu
        cout << "Manager menu:\n";
        cout << "1. Approve Order\n";
        cout << "2. Update Stock\n";
        cout << "3. Create Order\n";
        cout << "4. View Order Status\n";
        cout << "5. Cancel Order\n";

        int action;
        cin >> action;
        if (action == 1) {
            dynamic_pointer_cast<Manager>(user)->approveOrder();
        }
        else if (action == 2) {
            dynamic_pointer_cast<Manager>(user)->updateStock();
        }
        else if (action == 3) {
            dynamic_pointer_cast<Manager>(user)->createOrder();
        }
        else if (action == 4) {
            dynamic_pointer_cast<Manager>(user)->viewOrderStatus(1); //requires id
        }
        else if (action == 5) {
            dynamic_pointer_cast<Manager>(user)->cancelOrder(2); //requires id
        }

    }
    else if (choice == 3) {
        // Customer menu
        cout << "Customer menu:\n";
        cout << "1. Create Order\n";
        cout << "2. View Order Status\n";
        cout << "3. Cancel Order\n";
        cout << "4. Add to Order\n";
        cout << "5. Remove from Oreder\n";
        cout << "6. Make payment\n";

        int action;
        cin >> action;
        if (action == 1) {
            dynamic_pointer_cast<Customer>(user)->createOrder();
        }
        else if (action == 2) {
            dynamic_pointer_cast<Customer>(user)->viewOrderStatus(1);
        }
        else if (action == 3) {
            dynamic_pointer_cast<Customer>(user)->cancelOrder(1);
        }
        else if (action == 4) {
            dynamic_pointer_cast<Customer>(user)->addToOrder(); 
            
        }
        else if (action == 5) {
            dynamic_pointer_cast<Customer>(user)->removeFromOrder();
        }
        else if (action == 6) {
            dynamic_pointer_cast<Customer>(user)->makePayment();
        }
    }

    // Log action
    logAction("User performed an action.");
}

int main() {
    setlocale(LC_ALL, "RU");
    while (true) {
        showMainMenu();
    }
    return 0;
}
