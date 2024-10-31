#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <iostream>
#include <ostream>
class Bureaucrat;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"
#define UNDERLINE "\033[4m"

class Form {
private:
  const std::string _name;
  bool _isSigned;
  const int _gradeToSign;
  const int _gradeToExc;

public:
  //_____________constructor_____.
  Form();
  Form(const std::string &name, const int &gradeSign, const int &gardeExc);
  Form(const Form &_other);
  Form &operator=(const Form &_other);
  ~Form();
  
  //_____________ Exceptions.

  class GradeTooHighException : std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : std::exception {
  public:
    virtual const char *what() const throw();
  };

  void beSigned(const Bureaucrat &Bur);

  //_____________ Getters _______.
  std::string getName() const;
  bool getIsSigned() const;
  int getGradeToSign() const;
  int getGradeToExc() const;
};

std::ostream &operator<<(std::ostream &out, const Form &_form);

#endif