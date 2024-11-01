#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

// • PresidentialPardonForm: Required grades: sign 25, exec 5
// Informs that <target> has been pardoned by Zaphod Beeblebrox.

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
  std::string const _target;

public:
  //_________________________ Canonical Form.

  PresidentialPardonForm();
  PresidentialPardonForm(const std::string &target);
  PresidentialPardonForm(const PresidentialPardonForm &_other);
  ~PresidentialPardonForm();
  //_________________________ Overload Operator.

  PresidentialPardonForm &operator=(const PresidentialPardonForm &_other);

  //_________________________ Getter.
  std::string getTarget() const;

  //_________________________ Excecution.
  void execute(const Bureaucrat &excutor) const;
};

#endif