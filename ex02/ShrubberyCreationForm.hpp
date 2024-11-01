#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <ostream>


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
    ~ShrubberyCreationForm();
    // _______________________ Getter.
    std::string getTarget() const;

    // _______________________ Excecutor.
    void createFile() const;
    void execute(const Bureaucrat & executor) const;
};

std::ostream &operator<<(std::ostream &_out ,const ShrubberyCreationForm &_form);

#endif