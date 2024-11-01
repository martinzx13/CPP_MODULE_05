#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>

int main() {

  // User can not sign.
  std::cout << "\n_________Test One _________\n" << std::endl;
  try {
    Bureaucrat secretary("Miss_leigy", 80);
    Form testamento("testamenth", 45, 2);
    std::cout << testamento << std::endl;
    secretary.signForm(testamento);
    testamento.beSigned(secretary);
    std::cout << "\n" << testamento << std::endl;
  } catch (std::exception &e) {
    std::cout << RED << "Error : " << RESET << e.what() << std::endl;
  }

  // // User can sign
  std::cout << "\n_________Test Two _________\n" << std::endl;

  try {
    Bureaucrat secretary1("Miss_leigy_1", 10);
    Form testamento("testamenth", 45, 2);
    std::cout << "\n" << testamento << std::endl;
    testamento.beSigned(secretary1);
    secretary1.signForm(testamento);
    std::cout << "\n\n" << testamento << std::endl;
  } catch (std::exception &e) {
    std::cout << "Error : " << e.what() << std::endl;
  }
}