# **Intern Form Creation - Module 05 Exercise**

## 📜 Project Overview

This exercise expands upon previous modules by introducing an **Intern** class that can autonomously handle form creation for the `Bureaucrat` class. Unlike `Bureaucrat`, the `Intern` has no name, grade, or unique characteristics—it exists solely to create forms as instructed. The intern's primary function, `makeForm`, dynamically creates different form types without relying on complex `if/else` or `switch` statements, requiring effective use of function pointers and clean design patterns.

## 📂 Project Structure

The project builds on previous exercises by adding:

- **`Intern.hpp` / `Intern.cpp`**: Defines the `Intern` class and its core `makeForm` function.
- **`AForm.hpp`**: Abstract base class for forms.
- **Specific Forms**: `ShrubberyCreationForm`, `RobotomyRequestForm`, and `PresidentialPardonForm` inherit from `AForm` and perform specialized actions.
- **Makefile**: Builds the complete project.
- **`main.cpp`**: Test file demonstrating intern-based form creation.

## 🔑 Key Features

### Intern Class

The `Intern` class is a lightweight helper with no attributes or special properties beyond the function `makeForm`.

- **`makeForm(const std::string &formName, const std::string &target)`**:
  - Takes in two parameters: `formName` (the name of the form type) and `target` (the target for the form).
  - Returns a pointer to a dynamically created form based on the `formName` input.
  - **Form Types Supported**:
    - `"shrubbery creation"` - Returns a `ShrubberyCreationForm`.
    - `"robotomy request"` - Returns a `RobotomyRequestForm`.
    - `"presidential pardon"` - Returns a `PresidentialPardonForm`.
  - If `formName` does not match any of the recognized forms, an error message is printed.
  - **No `if`/`else` Statements**: To keep `makeForm` concise, function pointers are used for form creation, preventing complex `if/else` structures and enabling easier addition of new form types.

### Using Function Pointers for Form Creation

To avoid complex `if/else` or `switch` statements, function pointers or an array of functions can be used for each form type. By mapping strings to corresponding functions, the `Intern` can call the correct form constructor dynamically.

## 🛠 Compilation and Execution

### Compilation

Use the Makefile to compile the project:

```bash
make
```

### Running the Program

Run the compiled program to see the intern in action:

```bash
./bureaucracy
```

## 🎯 Key Concepts

### Abstract Class and Polymorphism

- **Abstract Base Class (`AForm`)**: `AForm` serves as a base class for forms, with derived classes implementing specific form behaviors.
- **Polymorphism**: Interns create forms polymorphically, allowing `Bureaucrat` to work with any form without needing to know the exact type.

### Dynamic Form Creation

- **Function Pointers**: By leveraging function pointers, `makeForm` avoids using `if/else` statements to determine form types, improving readability and maintainability.
- **Error Handling**: If `formName` doesn’t match a known form, an error message is displayed, preventing invalid form creation.

### Exception Handling

- `makeForm` should integrate with try/catch blocks where necessary to gracefully handle invalid form requests.

## 📝 Testing and Validation

Tests should verify:

- Proper form creation for all valid form names.
- Error handling when an invalid form name is passed.
- Correct function pointer usage to ensure form creation without `if/else`.
- Successful form execution using `Bureaucrat`.

## 💡 Learning Outcomes

This exercise reinforces:

- **Dynamic Polymorphism**: Creating objects dynamically without knowing their exact types at compile time.
- **Clean Code Practices**: Reducing complex conditional structures by leveraging function pointers.
- **Error Handling and Exception Safety**: Ensuring robust error management in the face of unexpected input.
