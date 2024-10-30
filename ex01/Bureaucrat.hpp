#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <ostream>
#include "Form.hpp"
class Bureaucrat {
    private:
    const std::string _name;
    int _grade;

    public:
    
    //_______________ Constructors.
    Bureaucrat();
    Bureaucrat(std::string const &name, int const &grade);
    Bureaucrat(Bureaucrat const &_other);
    Bureaucrat &operator=(const Bureaucrat &_other);
    ~Bureaucrat();

    class GradeTooHighException : std::exception
    {
        public:
        virtual const char *what() const throw();
    };
    class GradeTooLowException : std::exception
    {
        public:
        virtual const char *what() const throw();
    };

    //______________ Getters ______.
    std::string const getName() const;
    int getGrade() const;

    // ____________ Setter ________.
    void setGrade(int const &grade);
    void signForm( Form &form);
    // ____________ modifiers______.
    void incrementGrade();
    void decreaseGrade();
};
std::ostream &operator<<(const Bureaucrat &bure, std::ostream &out);

#endif