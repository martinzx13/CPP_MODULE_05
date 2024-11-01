# Bureaucratic Forms - Advanced C++ Form Management

## 📜 Project Overview

Welcome to **Advanced Form Management**! This exercise builds on the `Bureaucrat` and `AForm` classes to introduce complex form actions with additional form types. This project emphasizes abstract classes, inheritance, polymorphism, and advanced exception handling in C++. Each form type has unique requirements and behavior, allowing you to explore deeper functionality within object-oriented programming.

## 📂 Project Structure

The main files for this project include:

- **`Bureaucrat.hpp` / `Bureaucrat.cpp`**: Updated `Bureaucrat` class that can now execute forms.
- **`AForm.hpp` / `AForm.cpp`**: Abstract `AForm` base class for form management.
- **`ShrubberyCreationForm.hpp` / `ShrubberyCreationForm.cpp`**: Creates ASCII trees in a file.
- **`RobotomyRequestForm.hpp` / `RobotomyRequestForm.cpp`**: Randomly “robotomizes” a target.
- **`PresidentialPardonForm.hpp` / `PresidentialPardonForm.cpp`**: Issues a presidential pardon.
- **`Makefile`**: Builds the project.
- **`main.cpp`**: Test file demonstrating `Bureaucrat` and `AForm` interactions.

## 🔑 Key Features

### Abstract Base Class: `AForm`

- **`AForm`** is an abstract class with attributes and methods common to all forms.
- **Attributes**:
  - **Name**: A constant, unchangeable name for each form.
  - **Signed Status**: Boolean indicating whether the form is signed.
  - **Grades**: Constants for `signGrade` and `execGrade`, determining the minimum grade needed for signing and executing the form.
- **Exceptions**:
  - `GradeTooHighException` and `GradeTooLowException` to handle out-of-range grades.
- **New Member Functionality**:
  - **`execute(Bureaucrat const & executor) const`**: An abstract function that derived classes must override to define their specific actions. This function checks if the form is signed and if the bureaucrat has the necessary grade to execute.

### Derived Classes with Custom Actions

Each derived class defines a unique action when executed, leveraging polymorphism via the `execute` function.

1. **ShrubberyCreationForm**:
   - **Grades**: 145 to sign, 137 to execute.
   - **Action**: Creates an ASCII tree in a file named `<target>_shrubbery`.
2. **RobotomyRequestForm**:
   - **Grades**: 72 to sign, 45 to execute.
   - **Action**: Randomly either succeeds or fails to "robotomize" the target, with 50% success.
3. **PresidentialPardonForm**:
   - **Grades**: 25 to sign, 5 to execute.
   - **Action**: Informs that the target has been pardoned by Zaphod Beeblebrox.

### `Bureaucrat` Class Updates

- The `Bureaucrat` class gains an **`executeForm(AForm const & form)`** method to attempt to execute a form.
  - **Successful Execution**: Outputs "`<bureaucrat>` executed `<form>`".
  - **Execution Failure**: Provides a descriptive error message if execution fails due to form requirements.

### Operator Overloading

The `<<` operator is overloaded for both `AForm` and `Bureaucrat` to provide clear, detailed output for debugging and testing.

## 🛠 Usage

### Compilation

Compile the project using the Makefile:

```bash
make
```

### Running the Program

Execute the compiled program with:

```bash
./advanced_forms
```


## 🎯 Key Concepts

### Abstract Classes and Polymorphism

- **Abstract Class (`AForm`)**: `AForm` serves as a base class with a pure virtual `execute` method, ensuring derived classes must implement this method.
- **Polymorphism**: Derived classes (`ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm`) customize `execute` behavior, allowing the `Bureaucrat` to execute different forms polymorphically.

### Exception Handling

- Extensive use of custom exceptions (`GradeTooHighException`, `GradeTooLowException`) ensures proper validation of grades for signing and execution.
- Exception handling in `Bureaucrat` and `AForm` enforces that only qualified bureaucrats can execute or sign forms.

### Encapsulation and Access Control

- All form attributes remain **private** within `AForm`, with derived classes and external classes accessing them through public getters.
- **Constructor Validation**: Ensures that forms are always created with valid grades, preventing invalid forms.

## 📜 Project Requirements

- **Abstract Base Class**: `AForm` must be abstract.
- **Concrete Derived Classes**: Implement `ShrubberyCreationForm`, `RobotomyRequestForm`, and `PresidentialPardonForm` with unique actions.
- **Execution Validation**: `execute` method should verify signing status and required grade.
- **Bureaucrat `executeForm` Method**: Allows bureaucrats to attempt form execution and handle outcomes.

## 📝 Testing and Error Handling

The project includes tests for:

- Valid and invalid grade values for signing and execution.
- Each derived form's unique action.
- Exception handling when executing forms without proper permissions.
- Output validation for successful and unsuccessful executions.

## 🔑 Learning Outcomes

- **Advanced Polymorphism**: Implement abstract classes and inheritance to achieve different form actions.
- **Exception Safety**: Robust error handling and validation for form interactions.
- **Object-Oriented Design**: Real-world inspired bureaucracy simulation using C++ classes and polymorphism.
