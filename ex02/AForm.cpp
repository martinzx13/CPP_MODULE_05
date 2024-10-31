#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

#include <string>
//______________________ Canonnical Form.

AForm::AForm()
    : _name("Default"), _isSigned(false), _gradeToSign(10), _gradeToExec(1) {
  std::cout << "Default Form Construction" << std::endl;
}
AForm::AForm(const std::string &name, int const &signGrade, int const &excGrade)
    : _name(name), _isSigned(false), _gradeToSign(signGrade),
      _gradeToExec(excGrade) {
  (_gradeToExec > 150 || _gradeToExec > 150) ? throw(GradeTooLowException())
                                             : std::cout << "Contract";
  (_gradeToExec < 1 || _gradeToExec < 1)
      ? throw(GradeTooHighException())
      : std::cout << " Created 📜📑📄🧑‍⚖️" << std::endl;
}

AForm::AForm(AForm const &_other)
    : _name(_other._name), _gradeToSign(_other._gradeToSign),
      _gradeToExec(_other._gradeToExec) {
  { this->_isSigned = _other._isSigned; }
}

AForm &AForm::operator=(const AForm &_other) {
  if (this != &_other) {
    this->_isSigned = _other._isSigned;
  }
  return (*this);
}

AForm::~AForm() {}

//______________________ Getters.

std::string const AForm::getName() const { return (_name); }
int AForm::getGradeToExec() const { return (_gradeToExec); }
int AForm::getGradeToSign() const { return (_gradeToSign); }
bool AForm::getIsSigned() const { return (_isSigned); }

//______________________ Exceptions.

const char *AForm::GradeTooHighException::what() const throw() {
  return ("Grade to high");
}

const char *AForm::GradeTooLowException::what() const throw() {
  return ("Grade to low");
}

//_______________________ Operator

std::ostream &operator<<(std::ostream &out, const AForm *_form) {
  out << BLUE << "📜 Form Information 📑\n"
      << RESET << GREEN << "Name : " << RESET << _form->getName() << YELLOW
      << "\nGrade to sign : " << RESET << _form->getGradeToSign() << BLUE
      << "\nGrade to Execute: " << RESET << _form->getGradeToExec() << MAGENTA
      << "\nStatus: " << (_form->getIsSigned() ? " Signed ✅" : " Not Signed 🚫")
      << CYAN << std::endl;
  return (out);
}

void AForm::beSigned(const Bureaucrat &_Bur) {
  (_Bur.getGrade() <= _gradeToSign) ? (_isSigned = true)
                                    : throw(GradeTooLowException());
}

