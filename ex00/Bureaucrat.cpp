#include "Bureaucrat.hpp"
#include <ostream>
#include <stdexcept>

Bureaucrat::Bureaucrat() : _name(""), _grade(150) {
  std::cout << "Default Constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int const &grade)
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

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &_other) {
  if (this != &_other) {
    this->_grade = _other._grade;
  }
  return (*this);
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return ("Grade To High for the Bureocrat ⚡");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return ("Grade To Low for the Bureocrat 🪫");
}

Bureaucrat::~Bureaucrat() {}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &_other) {
  out << _other.getName() << " bureaucrat grade " << _other.getGrade();
  return out;
}

std::string const Bureaucrat::getName() const { return (_name); }
int Bureaucrat::getGrade() const { return (_grade); }
void Bureaucrat::setGrade(int const &grade) { this->_grade = grade; }

void Bureaucrat::incrementGrade() {
  _grade--;
  if (_grade < 1)
    throw(GradeTooHighException());
}
void Bureaucrat::decreaseGrade() {
  _grade++;
  if (_grade > 150)
    throw(GradeTooLowException());
}