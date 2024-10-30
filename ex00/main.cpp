#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main() {

  // Grade to high.
  try {
    Bureaucrat president("Bure", 3);
    std::cout << GREEN << president << RESET << std::endl;
    president.incrementGrade();
    std::cout << GREEN << president << RESET << std::endl;
    president.incrementGrade();
    std::cout << GREEN << president << RESET << std::endl;
    president.incrementGrade();
    std::cout << GREEN << president << RESET << std::endl;

  } 
  catch (const Bureaucrat::GradeTooLowException &e) {
    std::cerr << RED << e.what() << RESET << std::endl;
  }
  catch (const Bureaucrat::GradeTooHighException &e)
  {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  // Grade to low
  try {
    Bureaucrat president("Bure", 148);
    std::cout << president << std::endl;
    president.decreaseGrade();
    std::cout << president << std::endl;
    president.decreaseGrade();
    std::cout << president << std::endl;
    president.decreaseGrade();
    std::cout << president << std::endl;

  } 
  catch (const Bureaucrat::GradeTooLowException &e) {
    std::cerr << RED << e.what() << RESET << std::endl;
  }
  catch (const Bureaucrat::GradeTooHighException &e)
  {
    std::cerr << RED << e.what() << RESET << std::endl;
  }
}