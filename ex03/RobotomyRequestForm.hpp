#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

// • RobotomyRequestForm: Required grades: sign 72, exec 45
// Makes some drilling noises. Then, informs that <target> has been robotomized
// successfully 50% of the time. Otherwise, informs that the robotomy failed.

class RobotomyRequestForm : public AForm{
    private:
    const std::string _target;

    public:
    //____________________ Canonical Form.
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &_other);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &_other);
    ~RobotomyRequestForm();
    //____________________ Getters.
    std::string getTarget() const;

    //____________________ execute.
    void execute(Bureaucrat const &executor) const;
};
std::ostream &operator<<(std::ostream &_out ,const RobotomyRequestForm &_form);

#endif