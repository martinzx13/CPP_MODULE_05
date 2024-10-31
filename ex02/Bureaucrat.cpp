#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(150) {
  std::cout << "Default Constructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int const &grade)
    : _name(name), _grade(grade) {
  if (grade > 150)
    throw(GradeTooLowException());
  if (grade < 1)
    throw(GradeTooHighException());
  std::cout << "Bureaucrat Constructor 👨‍💼" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &_other)
    : _name(_other._name), _grade(_other._grade) {
  std::cout << "Copy constructor called " << std::endl;
}
Bureaucrat::~Bureaucrat() {}

//________________________ Overload Operator

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &_other) {
  if (this != &_other) {
    this->_grade = _other._grade;
  }
  return (*this);
}
std::ostream &operator<<(std::ostream &out, const Bureaucrat &_other) {
  out << _other.getName() << " bureaucrat grade " << _other.getGrade();
  return out;
}

void Bureaucrat::signForm(const AForm &form) {

  form.getIsSigned() ? std::cout << _name << " signed ✅\n" << form.getName()
                     : std::cout << _name << " could not sign 🚫 " << form.getName()
                                 << "\nbecause " << "Grade to low 🪫" << std::endl;
}
//________________________ Getter.

std::string const Bureaucrat::getName() const { return (_name); }
int Bureaucrat::getGrade() const { return (_grade); }

// _______________________ Exception.
const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return ("Grade To High for the Bureocrat ⚡");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return ("Grade To Low for the Bureocrat 🪫");
}

// _______________________ Modifiers.
void Bureaucrat::increaseGrade() {
  _grade--;
  if (_grade < 1)
    throw(GradeTooHighException());
}
void Bureaucrat::decreaseGrade() {
  _grade++;
  if (_grade > 150)
    throw(GradeTooLowException());
}