#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
//___________________________ Cannonical Form.

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5), _target("Default") {
  std::cout << "Default PresidentialPardonForm Constructor " << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {
  std::cout << MAGENTA << "Creating : PresidentialPardonForm\n"
            << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &_other)
    : AForm(_other.getName(), _other.getGradeToSign(),
            _other.getGradeToExec()) {
  std::cout << MAGENTA << "Copy Constructor ShrubberyCreationForm\n"
            << RESET << std::endl;
}
PresidentialPardonForm::~PresidentialPardonForm() {}

//__________________________ Overload Operators

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &_other) {
  if (this != &_other)
    return (*this);
  return (*this);
}

//_________________________ Execution.

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
  if (getIsSigned() == false) {
    std::cout << "Contract Not Signed" << std::endl;
    return;
  }

  std::cout << "\n🙇  Some Pardoned noises ( >_< ) 🥁" << std::endl;

  (executor.getGrade() <= getGradeToExec())
      ? std::cout << GREEN << _target
                  << " has been pardoned by Zaphod Beeblebrox" << RESET
                  << std::endl
      : throw(GradeTooLowException());
}