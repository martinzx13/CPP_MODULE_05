#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <ostream>

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

class Bureaucrat {
private:
  const std::string _name;
  int _grade;

public:
  //______________Cannonical Form.
  Bureaucrat();
  Bureaucrat(std::string const &name, int const &grade);
  Bureaucrat(const Bureaucrat &_other);
  Bureaucrat &operator=(Bureaucrat const &_other);
  ~Bureaucrat();

  // _____________ Exceptions ___.
  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  //______________ Getter________.

  std::string const getName() const;
  int getGrade() const;

  //______________ Setter________.
  void setGrade(int const &grade);

  // _____________ Modifications_.
  void incrementGrade();
  void decreaseGrade();
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &_other);
#endif