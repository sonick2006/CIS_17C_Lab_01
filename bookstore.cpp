// bookstore.cpp
#include "bookstore.h"

void Order::calculateTotal() {
    totalAmount = 0;
    for (const auto& item : items) {
        totalAmount += item.price * item.quantity;
    }
}

void Bookstore::addBook(const Book& book) {
    books.push_back(book);
}

void Bookstore::registerUser(const User& user) {
    // Add the user to the users vector
    // Hint: look at the addBook method
}

std::vector<Book> Bookstore::searchBooks(const std::string& query) {
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

void Bookstore::addToCart(const Book& book, int qty) {
    // Add the book the cart vector ( as a pair )
    // Hint: look at the registerUser method, but instead
    // of adding one, there are two things to add.
}

double Bookstore::getCartTotal() {
    // Calculate the total price of the cart
}

void Bookstore::checkout(const User& user) {
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

void Bookstore::displayBooks() {
    for (const auto& book : books) {
        std::cout << "ISBN: " << book.isbn << ", Title: " << book.title 
                  << ", Author: " << book.author << ", Price: $" << book.price << std::endl;
    }
}

void Bookstore::displayOrders() {
    for (const auto& order : orders) {
        std::cout << "Order ID: " << order.orderId << ", User: " << order.user.name 
                  << ", Total: $" << order.totalAmount << ", Status: " << order.status << std::endl;
    }
}