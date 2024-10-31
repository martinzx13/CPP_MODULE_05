#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <iostream>
#include <ostream>
#include <string>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"

class Bureaucrat;

class AForm {
private:
  std::string const _name;
  bool _isSigned;
  const int _gradeToSign;
  const int _gradeToExec;

public:
  //___________ Canonical form;
  AForm();
  AForm(const std::string &name, int const &signGrade, const int &excGrade);
  AForm(AForm const &_otherForm);
  AForm &operator=(const AForm &_other);
  virtual ~AForm();

  //___________ Getters;
  std::string const getName() const;
  int getGradeToSign() const;
  int getGradeToExec() const;
  bool getIsSigned() const;

  //____________ Exceptions.
  class GradeTooLowException : std::exception {
  public:
    const char *what() const throw();
  };

  class GradeTooHighException : std::exception {
  public:
    const char *what() const throw();
  };

  class ContractFormNotSignedException : std::exception {
  public:
    const char *what() const throw();
  };
  // ___________ other
  void beSigned(const Bureaucrat &bury);
  virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &_form);
#endif