#include <iostream>
#include <string>
#include <vector>
#include <utility>

struct Book {
    // Create a struct for Book that contains the isbn, title, author, price, genre, and description
};

struct User {
    // Create a struct for User that contains the userId, name, email, password, and address
};

struct OrderItem {
    // Create a struct for OrderItem that contains the book, quantity, and price
};

struct Order {
    std::string orderId;
    User user;
    std::vector<OrderItem> items;
    double totalAmount;
    std::string status; // pending, shipped, delivered
    std::string orderDate;

    void calculateTotal() {
        totalAmount = 0;
        for (const auto& item : items) {
            totalAmount += item.price * item.quantity;
        }
    }
};

class Bookstore {
private:
    std::vector<Book> books;
    std::vector<User> users;
    std::vector<Order> orders;
    int nextOrderId = 1;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void registerUser(const User& user) {
        // Add the user to the users vector
        // Hint: look at the addBook method
    }

    std::vector<Book> searchBooks(const std::string& query) {
        std::vector<Book> results;
        for (const auto& book : books) {
            if (book.title.find(query) != std::string::npos ||
                book.author.find(query) != std::string::npos ||
                book.isbn == query) {
                results.push_back(book);
            }
        }
        return results;
    }

    // Simulate cart as vector of pairs
    std::vector<std::pair<Book, int>> cart;

    void addToCart(const Book& book, int qty) {
        // Add the book the cart vector ( as a pair )
        // Hint: look at the registerUser method, but instead
        // of adding one, there are two things to add.
    }

    double getCartTotal() {
        // Calculate the total price of the cart
    }

    void checkout(const User& user) {
        if (cart.empty()) {
            std::cout << "Cart is empty!" << std::endl;
            return;
        }

        Order order;
        order.orderId = "ORD" + std::to_string(nextOrderId++);
        order.user = user;
        for (const auto& item : cart) {
            OrderItem oi;
            oi.book = item.first;
            oi.quantity = item.second;
            oi.price = item.first.price;
            order.items.push_back(oi);
        }
        order.calculateTotal();
        order.status = "pending";
        order.orderDate = "2023-10-01";
        orders.push_back(order);
        cart.clear();
        std::cout << "Order placed successfully! Order ID: " << order.orderId << std::endl;
        std::cout << "Total: $" << order.totalAmount << std::endl;
    }

    void displayBooks() {
        for (const auto& book : books) {
            std::cout << "ISBN: " << book.isbn << ", Title: " << book.title 
                      << ", Author: " << book.author << ", Price: $" << book.price << std::endl;
        }
    }

    void displayOrders() {
        for (const auto& order : orders) {
            std::cout << "Order ID: " << order.orderId << ", User: " << order.user.name 
                      << ", Total: $" << order.totalAmount << ", Status: " << order.status << std::endl;
        }
    }
};

int main() {
    Bookstore store;

    // Add sample books
    Book b1 = {"978-0-123456-78-9", "C++ Programming", "Bjarne Stroustrup", 49.99, "Programming", "Learn C++"};
    Book b2 = {"978-0-987654-32-1", "Data Structures", "Mark Allen Weiss", 59.99, "Computer Science", "Advanced data structures"};
    Book b3 = {"978-0-111111-11-1", "Design Patterns", "Gang of Four", 39.99, "Software Engineering", "Classic patterns"};

    store.addBook(b1);
    store.addBook(b2);
    store.addBook(b3);

    // Register user
    User u1 = {"U001", "John Doe", "john@example.com", "password123", "123 Main St"};

    store.registerUser(u1);

    // Display books
    std::cout << "Available Books:" << std::endl;
    store.displayBooks();
    std::cout << std::endl;

    // Search books
    std::cout << "Search results for 'C++':" << std::endl;
    auto results = store.searchBooks("C++");
    for (const auto& book : results) {
        std::cout << book.title << " by " << book.author << std::endl;
    }
    std::cout << std::endl;

    // Add to cart
    store.addToCart(b1, 1);
    store.addToCart(b3, 2);

    std::cout << "Cart Total: $" << store.getCartTotal() << std::endl;

    // Checkout
    store.checkout(u1);

    // Display orders
    std::cout << "\nOrders:" << std::endl;
    store.displayOrders();

    return 0;
}
