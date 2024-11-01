#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <exception>

int main() {

  AForm *testament = new ShrubberyCreationForm("testament");
  AForm *testament1 = new RobotomyRequestForm("testament1");
  AForm *testament2 = new PresidentialPardonForm("Iron Man");

  AForm *contract = new ShrubberyCreationForm("contract");
  AForm *contract1 = new RobotomyRequestForm("contract1");
  AForm *contract2 = new PresidentialPardonForm("Iron Man");

  std::cerr << BLUE << "\n============= TEST 1 ==============\n"
            << RESET << std::endl;

  try {
    Bureaucrat trump("Mr Trump", 5);
    std::cout << *testament << std::endl;
    testament->beSigned(trump);
    trump.signForm(*testament);
    trump.executeForm(*testament);
    std::cout << *testament1 << std::endl;
    trump.signForm(*testament1);
    trump.executeForm(*testament1);
    std::cout << *testament2 << std::endl;
    trump.signForm(*testament2);
    trump.executeForm(*testament2);
  } catch (std::exception &e) {
    std::cerr << "=============exception==============" << std::endl;
    std::cout << "Error :::: " << e.what() << std::endl;
  }

  std::cerr << BLUE << "\n============= TEST 2 ==============\n"
            << RESET << std::endl;

  try {
    Bureaucrat miniTrump("Mr Mini Trump", 150);
    std::cout << *contract << std::endl;
    contract->beSigned(miniTrump);
    miniTrump.signForm(*contract);
    miniTrump.executeForm(*contract);
    std::cout << *contract1 << std::endl;
    contract->beSigned(miniTrump);
    miniTrump.signForm(*contract1);
    miniTrump.executeForm(*contract1);
  } catch (std::exception &e) {
    std::cerr << "=============exception==============" << std::endl;
    std::cout << RED << "Error :::: " << e.what() << RESET << std::endl;
  }

  std::cerr << BLUE << "\n============= TEST 3 ==============\n"
            << RESET << std::endl;
  try {
    Bureaucrat miniTrump("Mr Mini Trump", 150);
    std::cout << *contract1 << std::endl;
    contract1->beSigned(miniTrump);
    miniTrump.signForm(*contract1);
    miniTrump.executeForm(*contract1);
    std::cout << *contract1 << std::endl;
  } catch (std::exception &e) {
    std::cerr << "=============exception==============" << std::endl;
    std::cout << RED << "Error :::: " << e.what() << RESET << std::endl;
  }

  std::cerr << BLUE << "\n============= TEST 3 ==============\n"
            << RESET << std::endl;
  try {
    Bureaucrat miniTrump("Mr Mini Trump", 150);
    std::cout << *contract2 << std::endl;
    contract2->beSigned(miniTrump);
    miniTrump.signForm(*contract2);
    miniTrump.executeForm(*contract2);
    std::cout << *contract2 << std::endl;
  } catch (std::exception &e) {
    std::cerr << "=============exception==============" << std::endl;
    std::cout << RED << "Error :::: " << e.what() << RESET << std::endl;
  }

  delete contract;
  delete testament;
  return 0;
}