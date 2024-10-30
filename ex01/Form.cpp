#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iterator>

Form::Form()
    : _name("Default"), _isSigned(false), _gradeToSign(14), _gradeToExc(2) {
  std::cout << "Default Form Construction" << std::endl;
}

Form::Form(std::string const &name, const int &gradeSign, const int &gradeExec)
    : _name(name), _isSigned(false), _gradeToSign(gradeSign),
      _gradeToExc(gradeExec) {
  if (_gradeToSign < 1 || _gradeToExc < 1)
    throw(GradeTooHighException());
  if (_gradeToSign > 150 || _gradeToExc > 150)
    throw(GradeTooLowException());
  std::cout << "Contract Created 📜📑📄🧑‍⚖️" << std::endl;
}

//_______________________Exceptions.

const char *Form::GradeTooHighException::what() const throw() {
  return ("Grade to High");
}

const char *Form::GradeTooLowException::what() const throw() {
  return ("Grade to Low");
}

void Form::beSigned(const Bureaucrat &_Bur) {
  if (_Bur.getGrade() <= _gradeToSign)
    _isSigned = true;
  else
    throw(GradeTooLowException());
}

Form::~Form() {}

std::string Form::getName() const { return (_name); }
bool Form::getIsSigned() const { return (_isSigned); }
int Form::getGradeToSign() const { return (_gradeToSign); }
int Form::getGradeToExc() const { return (_gradeToExc); }

std::ostream &operator<<(std::ostream &out, const Form &_form) {
  out << BLUE << "📜 Form Information 📑\n"
      << RESET << GREEN << "Name : " << RESET << _form.getName() << YELLOW
      << "\nGrade to sign : " << RESET << _form.getGradeToSign() << BLUE
      << "\nGrade to Execute: " << RESET << _form.getGradeToExc() << MAGENTA
      << "\nStatus: " << (_form.getIsSigned() ? " Signed ✅" : " Not Signed 🚫")
      << CYAN << std::endl;
    return (out);
}