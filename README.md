# Lab 01 - Bookstore System

This lab introduces object-oriented programming in C++ by implementing a bookstore management system with books, users, orders, and shopping cart functionality.

## Files in this Directory
- `google_test/`: Directory containing Google Test files
- Implementation files: `*.cpp` with TODO comments for student completion
- Documentation: `*.md` files with requirements, diagrams, and presentations
- `bookstore.cpp`: Complete implementation of the Bookstore class, including Book, User, Order structures, and all operations.
- `bookstore_test.cpp`: Comprehensive Google Test suite covering all functionality.
- `design_diagrams.md`: System architecture and class diagrams.
- `presentation.md`: Lecture slides and key concepts.
- `requirements_document.md`: Detailed project requirements and specifications.

## Learning Objectives
- Understand C++ classes and objects
- Implement data structures (vectors, structs)
- Handle memory management and cleanup
- Write comprehensive unit tests with Google Test
- Practice error handling and edge cases

## System Overview
The Bookstore class manages:
- **Books**: ISBN, title, author, price, genre, description
- **Users**: ID, name, email, password, address
- **Orders**: Order ID, user, items, total amount, status
- **Cart**: Temporary storage for items before checkout

Key operations: add books, register users, search books, manage cart, process orders.

## Google Test Setup and Usage

### Prerequisites
- C++ compiler with C++17 support (g++ or clang++)
- Google Test framework installed

#### Installing Google Test on macOS:
```bash
# Install Homebrew (if not installed)
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Install CMake and Google Test
brew install cmake
brew install googletest
```

#### Installing Google Test on Windows:
1. Download CMake from https://cmake.org/download/
2. Download Google Test source: `git clone https://github.com/google/googletest.git`
3. Build and install:
   ```
   cd googletest
   mkdir build && cd build
   cmake -DCMAKE_INSTALL_PREFIX=C:\googletest ..
   cmake --build . --config Release
   cmake --build . --config Release --target install
   ```

#### Installing Google Test on Linux:
```bash
sudo apt-get update
sudo apt-get install libgtest-dev cmake
```

### Building with CMake
Navigate to this directory and run:

#### All platforms:
```bash
mkdir build
cd build
cmake ..
make
```

This will build both the test executable and the main program in the `build` directory.
```bash
g++ google_test/bookstore_test.cpp -std=c++17 -IC:\googletest\include -LC:\googletest\lib -lgtest -lgtest_main -o bookstore_test.exe
```

### Running the Tests
Execute the compiled binary:
```bash
./build/bookstore_test  # macOS/Linux
build/bookstore_test.exe  # Windows
```

### Expected Output
```
[==========] Running 10 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 10 tests from BookstoreTest
[ RUN      ] BookstoreTest.AddBook
[       OK ] BookstoreTest.AddBook (0 ms)
[ RUN      ] BookstoreTest.SearchBooks
[       OK ] BookstoreTest.SearchBooks (0 ms)
...
[==========] 10 tests from 10 test cases ran. (X ms total)
[  PASSED  ] 10 tests.
```

### Understanding the Test Cases
1. **AddBook**: Verifies books can be added to the bookstore inventory.
2. **SearchBooks**: Tests searching by title, author, or ISBN.
3. **AddToCart**: Checks adding items to cart and calculating totals.
4. **Checkout**: Validates order creation, total calculation, and cart clearing.
5. **RegisterUser**: Tests user registration (verified indirectly via checkout).
6. **EmptyCartCheckout**: Ensures checkout handles empty carts gracefully.
7. **MultipleItemsInCart**: Tests cart with multiple different books.
8. **SearchNoResults**: Verifies search returns empty for non-matching queries.
9. **OrderCalculateTotal**: Directly tests order total calculation method.
10. **MultipleOrders**: Checks handling sequential orders with different users.

### Running the Main Program
To see the bookstore in action:
```bash
./build/bookstore  # macOS/Linux
./build/bookstore.exe  # Windows
```

This demonstrates sample usage with predefined books and a mock order.

## Troubleshooting
- **Compilation errors**: Ensure C++17 is enabled (`-std=c++17`) and Google Test paths are correct.
- **Linker errors**: Verify Google Test libraries are installed and linked properly.
- **Test failures**: Check your implementation against the expected behavior in the tests.
- **Permission issues**: On macOS, you may need to adjust include/library paths based on Homebrew installation.

## Additional Resources
- [Google Test Documentation](https://google.github.io/googletest/)
- [C++ Reference](https://en.cppreference.com/)
- [Data Structures Tutorials](https://www.geeksforgeeks.org/data-structures/)

Happy coding! If tests pass, you've successfully implemented the bookstore system.

## Testing Your Implementation

**Important**: You must build your own test executable in the `google_test/` directory. There are no pre-compiled executables provided - this ensures you learn the compilation process.
Once you have implemented the TODO methods in `bookstore.cpp`, follow these steps to test your code:

### Step 1: Navigate to the root directory
```bash
cd ..
```

### Step 2: Build with CMake
```bash
mkdir build
cd build
cmake ..
make bookstore_test
```

### Step 3: Run the tests
```bash
g++ bookstore_test.cpp -std=c++17 -I/opt/homebrew/include -L/opt/homebrew/lib -lgtest -lgtest_main -lpthread -o bookstore_test
```

### Step 3: Run the tests
```bash
./bookstore_test
```

### Expected Output
You should see output like:
```
[==========] Running 10 tests from 1 test suite.
...
[  PASSED  ] 10 tests.
```

If all tests pass, your implementation is correct! If tests fail, check your code against the TODO requirements and test expectations.

### Troubleshooting
- **Compilation errors**: Ensure all TODO methods are implemented with correct signatures.
- **Test failures**: Review the failing test messages and debug your implementation.
- **Missing dependencies**: Make sure Google Test is installed as described in the prerequisites.
