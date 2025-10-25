// main.cpp
#include "bookstore.h"

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