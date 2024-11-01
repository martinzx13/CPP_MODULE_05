#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <exception>
#include <iostream>

int main() {

  Intern interno;
  AForm *presi = interno.makeForm(PRESIDENTIAL, "Kamala");
  AForm *shrube = interno.makeForm(SHRUBBERY, "three");
  AForm *robo = interno.makeForm(ROBOTOMY, "Terminator");
  try {

    Bureaucrat presiDent("Mr Face", 15);
    Bureaucrat presiDent1("Mr Face 1", 150);
    presiDent1.decreaseGrade();
    presiDent.signForm(*presi);
    presiDent.signForm(*shrube);
    presiDent.signForm(*robo);

    std::cout << *presi << std::endl;
    std::cout << *shrube << std::endl;
    std::cout << *robo << std::endl;

    presiDent.executeForm(*presi);
    presiDent.executeForm(*shrube);
    presiDent.executeForm(*robo);

    if (presi)
      delete presi;
    if (shrube)
      delete shrube;
    if (robo)
      delete robo;
  } catch (std::exception &e) {
    std::cerr << "Error :::: " << e.what() << std::endl;
    if (presi)
      delete presi;
    if (shrube)
      delete shrube;
    if (robo)
      delete robo;
  }

  return 0;
}