#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>

int main() {

  AForm *contract = new ShrubberyCreationForm();
  AForm *testament = new ShrubberyCreationForm();
  try {
    Bureaucrat trump("Mr Trump", 15);
    std::cout << testament << std::endl;
    testament->beSigned(trump);
    trump.signForm(*testament);
    trump.executeForm(*testament);
  } catch (std::exception &e) {
    std::cerr << "=============exception==============" << std::endl;
    std::cout << "Error :::: " << e.what() << std::endl;
  }
  try {
    Bureaucrat miniTrump("Mr Mini Trump", 150);
    std::cout << contract << std::endl;
    contract->beSigned(miniTrump);
    // miniTrump.signForm(*contract);
    // miniTrump.executeForm(*contract);
  } catch (std::exception &e) {
    std::cerr << "=============exception==============" << std::endl;
    std::cout << "Error :::: " << e.what() << std::endl;
  }
  delete contract;
  delete testament;
  return 0;
}