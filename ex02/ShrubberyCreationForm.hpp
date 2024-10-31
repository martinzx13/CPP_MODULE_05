#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"


// ShrubberyCreationForm: Required grades: sign 145, exec 137
// Create a file <target>_shrubbery in the working directory, and writes ASCII trees
// inside it.

class ShrubberyCreationForm : public AForm {
    private:
    std::string const _target;

    public:
    //________________________ Cannonical

    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string const &tarjet);
    ShrubberyCreationForm(const ShrubberyCreationForm &_other);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &_other);

    // _______________________ Getter.
    std::string getTarget() const;

    // _______________________ Excecutor.
    void execute(const Bureaucrat & executor) const;
};

#endif