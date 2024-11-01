#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <exception>
#include <iostream>

class Bureaucrat {
private:
  std::string const _name;
  int _grade;

public:
  //_______________ Canonical Form.
  Bureaucrat();
  Bureaucrat(std::string const &name, int const &grade);
  Bureaucrat(const Bureaucrat &_other);
  Bureaucrat &operator=(Bureaucrat const &_otherBu);
  ~Bureaucrat();

  //_______________ Getters.
  std::string const getName() const;
  int getGrade() const;

  //_______________ increment Functions.
  void increaseGrade();
  void decreaseGrade();

  //_______________ Exceptions Class.
  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
  //_______________ Form functions.
  void signForm(AForm &_other);
  void executeForm(AForm const &form);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &_bury);

#endif