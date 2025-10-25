// header.h
#ifndef HEADER_H
#define HEADER_H

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

    void calculateTotal();
};

class Bookstore {
private:
    std::vector<Book> books;
    std::vector<User> users;
    std::vector<Order> orders;
    int nextOrderId = 1;

public:
    void addBook(const Book& book);

    void registerUser(const User& user);

    std::vector<Book> searchBooks(const std::string& query);

    // Simulate cart as vector of pairs
    std::vector<std::pair<Book, int>> cart;

    void addToCart(const Book& book, int qty);

    double getCartTotal();

    void checkout(const User& user);

    void displayBooks();

    void displayOrders();
};

#endif // HEADER_H