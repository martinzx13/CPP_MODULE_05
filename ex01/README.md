# Form Management - C++ Bureaucracy Simulation

## 📄 Project Overview

Welcome to **Form Management**! Building on the **Bureaucrat** class, this project introduces a **Form** class, adding another layer of complexity to the bureaucratic system. In this exercise, forms have signing and execution requirements, meaning only bureaucrats of certain ranks can interact with them. This project reinforces concepts in object-oriented design, exception handling, and C++ class composition.

## 📂 Project Structure

The project consists of the following main files:

- **`Bureaucrat.hpp`** and **`Bureaucrat.cpp`**: Contains the `Bureaucrat` class with signing capabilities.
- **`Form.hpp`** and **`Form.cpp`**: Contains the `Form` class, defining forms with signing and execution grades.
- **`main.cpp`**: Tests interactions between `Bureaucrat` and `Form` classes, showcasing signing, grade validation, and exception handling.
- **`Makefile`**: Compiles the project, linking necessary files for successful builds.

## 🔑 Key Features

1. **Form Attributes**:

   - **Constant name**: Each form has a unique, unchangeable name.
   - **Sign Status**: A boolean that indicates whether the form has been signed.
   - **Required Grades**: The form has a signing grade and an execution grade, both constants, with `1` as the highest possible grade and `150` as the lowest.
2. **Exception Handling**:

   - `GradeTooHighException` and `GradeTooLowException` are thrown if form grades fall outside valid bounds.
   - **Custom Exception Classes**: Like in the previous exercise, the Form class includes `GradeTooHighException` and `GradeTooLowException` to ensure grade integrity during instantiation and operations.
3. **Interaction Between Classes**:

   - The `beSigned()` function in `Form` allows it to be signed by a `Bureaucrat` if their grade is high enough.
   - The `signForm()` function in `Bureaucrat` attempts to sign a form and outputs success or failure based on grade qualifications.
4. **Overloaded Operators**:

   - The `<<` operator is overloaded for both `Form` and `Bureaucrat` to provide readable output detailing form status and bureaucrat information.

## 🛠 Usage

### Compilation

To compile the project, use the Makefile:

```bash
make
```

### Running the Program

Execute the compiled program with:

```bash
./form_management
```

### Sample Code

The following example demonstrates typical usage of the `Form` and `Bureaucrat` classes:

```cpp
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat john("John Doe", 3);
        Form leaveRequest("Leave Request", 5, 10);

        std::cout << john << std::endl;
        std::cout << leaveRequest << std::endl;

        john.signForm(leaveRequest);  // Will attempt to sign based on John's grade
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}
```

### Expected Output

```plaintext
John Doe, bureaucrat grade 3.
Leave Request form, grade required to sign: 5, grade required to execute: 10, signed: No.
John Doe signed Leave Request
```

## 📝 Class Breakdown

### Bureaucrat

Updated from the previous project:

- **`signForm()`**: Attempts to sign a form, catching exceptions if the bureaucrat’s grade is insufficient.
- **Enhanced Error Output**: Provides detailed output on why a form couldn’t be signed.

### Form

The new `Form` class contains the following:

- **Attributes**:
  - `name`: Constant name set upon instantiation.
  - `isSigned`: Boolean flag indicating if the form has been signed.
  - `signGrade`: The minimum grade required to sign the form.
  - `execGrade`: The minimum grade required to execute the form.
- **Member Functions**:
  - `beSigned()`: Accepts a `Bureaucrat` and signs the form if their grade is sufficient.
  - `getName()`, `getSignGrade()`, `getExecGrade()`, `isSigned()`: Getter methods for accessing form details.
- **Operator Overloading**:
  - Overloads `<<` to output form information in a structured format.

## 🚩 Key Concepts

- **Exception Safety**: Extensive exception handling to manage invalid grades and access violations.
- **Encapsulation**: All attributes are private to promote encapsulation, providing access via controlled member functions.
- **Integration with Bureaucrat**: Demonstrates the `Bureaucrat`-`Form` relationship, reinforcing encapsulation and access control.

## 🎯 Learning Objectives

- **Advanced Class Design**: Using classes that interact through methods, reinforcing design patterns.
- **Error Handling**: Implement C++ exception handling to manage errors and provide detailed error descriptions.
- **Operator Overloading**: Enhance output readability through custom `<<` operators.

## 📜 License

This project is open-source under the MIT License.

---

This project serves as an excellent opportunity to reinforce object-oriented programming, exception handling, and complex class interactions in C++. Dive into the bureaucratic world of C++ programming!
