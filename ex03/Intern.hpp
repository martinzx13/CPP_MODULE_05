#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define PRESIDENTIAL "presidential pardon"
#define ROBOTOMY "robotomy request"
#define SHRUBBERY "shrubbery creation"

class Intern {

private:
  std::string _forms[3];

public:
  // ___________________ Cannonical Form.

  Intern();
  Intern(const Intern &_other);
  Intern &operator=(const Intern &_other);
  ~Intern();

  //_____________________ execute.
  AForm *makeForm(const std::string &formName, const std::string &target);
  AForm *presidentialPardon(std::string const &target);
  AForm *robotomyRequest(std::string const &target);
  AForm *shrubberyCreation(std::string const &target);
};
#endif