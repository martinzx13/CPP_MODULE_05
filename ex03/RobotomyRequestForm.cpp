#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
//___________________________ Cannonical Form.

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("robotomy request", 72, 45), _target("Default") {
  std::cout << "Default RobotomyRequestForm Constructor " << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("robotomy request", 72, 45), _target(target) {
  std::cout << MAGENTA << "Creating : robotomy request\n"
            << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &_other)
    : AForm(_other.getName(), _other.getGradeToSign(),
            _other.getGradeToExec()) {
  std::cout << MAGENTA << "Copy Constructor ShrubberyCreationForm\n"
            << RESET << std::endl;
}
RobotomyRequestForm::~RobotomyRequestForm() {}

//__________________________ Overload Operators

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &_other) {
  if (this != &_other)
    return (*this);
  return (*this);
}

//_________________________ Execution.

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
  if (getIsSigned() == false) {
    std::cout << "Contract Not Signed" << std::endl;
    return;
  }

  std::cout << "🥁 🎲 🥁 🎲 Some drilling noises 🎲 🥁 🎲 🥁" << std::endl;

  (executor.getGrade() <= getGradeToExec())
      ? ((std::rand() % 2) ? std::cout
                                 << GREEN << _target
                                 << "🚡 has been robotomized successfully! 🤖"
                                 << RESET << std::endl
                           : std::cout << "Robotomized Failed")
      : throw(GradeTooLowException());
}