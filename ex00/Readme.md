# Bureaucrat - C++ Bureaucracy Simulation

## 📄 Project Overview

Welcome to the **Bureaucrat** project! This project is designed to simulate the fundamentals of a bureaucratic system within C++. The goal is to create a `Bureaucrat` class that models a government worker with a specific rank, encapsulated by a constant name and a grade. The grade ranks from **1 (highest)** to **150 (lowest)**, allowing you to manage and manipulate bureaucrats within their hierarchical structure using robust C++ exception handling.

## 📂 Project Structure

The project consists of the following main files:

- **`Bureaucrat.hpp`** and **`Bureaucrat.cpp`**: Contains the `Bureaucrat` class definition and implementation.
- **`main.cpp`**: Provides a sample program to create bureaucrats, adjust their grades, and test exception handling.
- **`Makefile`**: Compiles the project, linking all necessary files and providing convenient build commands.

## 🔑 Key Features

- **Immutable Name**: Each bureaucrat is assigned a name upon creation that cannot be changed.
- **Grade Management**: Bureaucrats have a grade that indicates their rank. Grades range from 1 (highest) to 150 (lowest).
- **Exception Handling**:
  - `GradeTooHighException`: Thrown if a grade goes above the allowed maximum.
  - `GradeTooLowException`: Thrown if a grade falls below the allowed minimum.
- **Streamlined Output**: Overloads the `<<` operator to provide readable output for each bureaucrat's details, e.g., `"John, bureaucrat grade 2."`

## 🛠 Usage

### Compilation

To compile the project, use the provided Makefile:

```bash
make
```

### Running the Program

```bash
./bureaucrat
```

### Sample Code

The following example demonstrates typical usage of the `Bureaucrat` class:

```cpp
#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat john("John Doe", 3);
        std::cout << john << std::endl;
        john.incrementGrade(); // Increments John's grade to 2
        std::cout << john << std::endl;
        john.incrementGrade(); // Increments John's grade to 1
        john.incrementGrade(); // Throws GradeTooHighException
    } catch (const Bureaucrat::GradeTooHighException &e) {
        std::cerr << "Caught exception: Grade too high!" << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &e) {
        std::cerr << "Caught exception: Grade too low!" << std::endl;
    }
}
```

### Expected Output

```plaintext
John Doe, bureaucrat grade 3.
John Doe, bureaucrat grade 2.
John Doe, bureaucrat grade 1.
Caught exception: Grade too high!
```

## 📝 Class Breakdown

### Bureaucrat

The `Bureaucrat` class represents a government employee with a fixed name and mutable grade. The grade indicates the employee's rank, with specific rules for grade management:

- **Constructors and Destructor**: Initializes the name and grade (validating the grade to avoid out-of-range values).
- **Getters**:
  - `getName()`: Returns the name.
  - `getGrade()`: Returns the grade.
- **Grade Modifiers**:
  - `incrementGrade()`: Increases grade by 1 (higher rank).
  - `decrementGrade()`: Decreases grade by 1 (lower rank).
- **Operator Overloading**:
  - Overloads `<<` to print details in the format: `<name>, bureaucrat grade <grade>.`

## 🚩 Key Concepts

- **Orthodox Canonical Form**: Includes a copy constructor, assignment operator, and destructor for solid C++ class design.
- **Custom Exception Classes**: Demonstrates the creation of custom exception types in C++ for specific error management.
- **Operator Overloading**: Provides an overloaded `<<` operator for efficient and readable object output.

## 🎯 Learning Objectives

This project is an excellent opportunity to reinforce:

- **Exception Handling**: Learn to catch and handle specific exceptions effectively.
- **Class Design in C++**: Understand the importance of encapsulation, class structure, and constructor chaining.
- **Streamlined Output**: Use operator overloading to enhance output functionality for complex types.

## 📜 License

This project is open-source under the MIT License.

---

By exploring the basics of exception handling, class inheritance, and encapsulation in C++, this project provides an excellent way to simulate a robust bureaucratic system!
