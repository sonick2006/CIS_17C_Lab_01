#include "pch.h"

// Include the student's implementation
// Path to where you bookstore.cpp file is located
#include ""

// Test cases

TEST(BookstoreTest, AddBook) {
    Bookstore store;
    Book b = { "123", "Test Book", "Author", 10.0, "Genre", "Desc" };
    store.addBook(b);
    auto results = store.searchBooks("Test Book");
    EXPECT_EQ(results.size(), 1);
    EXPECT_EQ(results[0].title, "Test Book");
}

TEST(BookstoreTest, SearchBooks) {
    Bookstore store;
    Book b1 = { "123", "C++ Book", "Author1", 10.0, "Genre", "Desc" };
    Book b2 = { "456", "Java Book", "Author2", 20.0, "Genre", "Desc" };
    store.addBook(b1);
    store.addBook(b2);

    auto results = store.searchBooks("C++");
    EXPECT_EQ(results.size(), 1);
    EXPECT_EQ(results[0].title, "C++ Book");

    results = store.searchBooks("Author2");
    EXPECT_EQ(results.size(), 1);
    EXPECT_EQ(results[0].author, "Author2");
}

TEST(BookstoreTest, AddToCart) {
    Bookstore store;
    Book b = { "123", "Book", "Author", 10.0, "Genre", "Desc" };
    store.addToCart(b, 2);
    EXPECT_DOUBLE_EQ(store.getCartTotal(), 20.0);
}

TEST(BookstoreTest, Checkout) {
    Bookstore store;
    User u = { "U1", "User", "email", "pass", "addr" };
    Book b = { "123", "Book", "Author", 10.0, "Genre", "Desc" };
    store.addToCart(b, 1);
    store.checkout(u);
    EXPECT_DOUBLE_EQ(store.getCartTotal(), 0.0);


}

TEST(BookstoreTest, RegisterUser) {
    Bookstore store;
    User u = { "U1", "John Doe", "john@example.com", "pass", "addr" };
    store.registerUser(u);
    Book b = { "123", "Book", "Author", 10.0, "Genre", "Desc" };
    store.addBook(b);
    store.addToCart(b, 1);
    store.checkout(u);
    EXPECT_DOUBLE_EQ(store.getCartTotal(), 0.0);
}

TEST(BookstoreTest, EmptyCartCheckout) {
    Bookstore store;
    User u = { "U1", "User", "email", "pass", "addr" };
    store.checkout(u);

}

TEST(BookstoreTest, MultipleItemsInCart) {
    Bookstore store;
    Book b1 = { "123", "Book1", "Author1", 10.0, "Genre", "Desc" };
    Book b2 = { "456", "Book2", "Author2", 20.0, "Genre", "Desc" };
    store.addToCart(b1, 2);
    store.addToCart(b2, 1);
    EXPECT_DOUBLE_EQ(store.getCartTotal(), 40.0);
}

TEST(BookstoreTest, SearchNoResults) {
    Bookstore store;
    Book b = { "123", "Book", "Author", 10.0, "Genre", "Desc" };
    store.addBook(b);
    auto results = store.searchBooks("Nonexistent");
    EXPECT_EQ(results.size(), 0);
}

TEST(BookstoreTest, OrderCalculateTotal) {
    Order order;
    Book b1 = { "123", "Book1", "Author1", 10.0, "Genre", "Desc" };
    Book b2 = { "456", "Book2", "Author2", 20.0, "Genre", "Desc" };
    OrderItem oi1 = { b1, 2, 10.0 };
    OrderItem oi2 = { b2, 1, 20.0 };
    order.items.push_back(oi1);
    order.items.push_back(oi2);
    order.calculateTotal();
    EXPECT_DOUBLE_EQ(order.totalAmount, 40.0);
}

TEST(BookstoreTest, MultipleOrders) {
    Bookstore store;
    User u1 = { "U1", "User1", "email1", "pass", "addr" };
    User u2 = { "U2", "User2", "email2", "pass", "addr" };
    Book b = { "123", "Book", "Author", 10.0, "Genre", "Desc" };
    store.addToCart(b, 1);
    store.checkout(u1);
    EXPECT_DOUBLE_EQ(store.getCartTotal(), 0.0);
    store.addToCart(b, 2);
    store.checkout(u2);
    EXPECT_DOUBLE_EQ(store.getCartTotal(), 0.0);

}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
