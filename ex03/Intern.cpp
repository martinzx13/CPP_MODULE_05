#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>

Intern::Intern() {
  _forms[0] = PRESIDENTIAL;
  _forms[1] = ROBOTOMY;
  _forms[2] = SHRUBBERY;
}

Intern::Intern(const Intern &_other) {
  for (int i = 0; i < 3; i++)
    _forms[i] = _other._forms[i];
}
Intern &Intern::operator=(const Intern &_other) {
  if (this != &_other) {
    for (int i = 0; i < 3; i++)
      _forms[i] = _other._forms[i];
  }
  return *this;
}
Intern::~Intern(){}

AForm *Intern::presidentialPardon(const std::string &target) {
  return (new PresidentialPardonForm(target));
}

AForm *Intern::robotomyRequest(const std::string &target) {
  return (new RobotomyRequestForm(target));
}

AForm *Intern::shrubberyCreation(const std::string &target) {
  return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(const std::string &form, const std::string &target) {
  AForm *(Intern::*formCreators[3])(const std::string &) = {
      &Intern::presidentialPardon, &Intern::robotomyRequest,
      &Intern::shrubberyCreation};
  for (int i = 0; i < 3; i++) {
    if (_forms[i] == form)
      return (this->*formCreators[i])(target);
  }
  return NULL;
}