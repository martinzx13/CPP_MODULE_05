#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <string>

//___________________________ Cannonical Form.

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("shrubbery creation", 145, 137), _target("") {
  std::cout << "Default ShrubberyCreationForm Constructor " << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("shrubbery creation", 145, 137), _target(target) {
  std::cout << MAGENTA << "shrubbery creation\n" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(
    const ShrubberyCreationForm &_other)
    : AForm(_other.getName(), _other.getGradeToSign(), _other.getGradeToExec()),
      _target(_other._target) {
  std::cout << MAGENTA << "Copy Constructor Shrubbery CreationForm\n"
            << RESET << std::endl;
}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &_other) {
  if (this != &_other)
    return *this;
  return *this;
}

std::string ShrubberyCreationForm::getTarget() const { return (_target); }

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
  if (this->getIsSigned() == false) {
    std::cout << "Contract Not Signed" << std::endl;
    return;
  }
  (executor.getGrade() <= this->getGradeToExec())
      ? createFile()
      : throw(GradeTooLowException());
}

void ShrubberyCreationForm::createFile() const {
  std::ofstream outfile(getTarget().append("__shrubbery").c_str());
  if (outfile.is_open() == false)
    return;

  outfile << "           e88o                 e88" << std::endl;
  outfile << "         ccee88oo             ee88ee88" << std::endl;
  outfile << "       ccee88oo                ccee8 8oo" << std::endl;
  outfile << "   C8O8O8Q8PoOb o8oo        o8oo C8O8O8Q8PoOb" << std::endl;
  outfile << " dOB69QO8PdUOpugoO9bD           dOB69QO8PdUOpugoO" << std::endl;
  outfile << "  CgggbU8OU qOp qOdoUOdcb     CgggbU8OU qOp qOdoUOd" << std::endl;
  outfile << "     6OuU /p u gcoUodpP     6OuU /p u gcoUodpP" << std::endl;
  outfile << "            88oo ccee88oo   C8O8O8Q8PoOb" << std::endl;
  outfile << "       ccee88oo ccee88oo   C8O 8O8Q8PoOb o8o" << std::endl;
  outfile << "       ccee88oo ccee88oo  C8O8O8Q8PoOb o8oo  " << std::endl;
  outfile << "    C8O8O8Q8PoOb o8oo     C8O8O8Q8PoOb o8oo" << std::endl;
  outfile << "  dOB69QO8PdUOpugoO9bD dOB69QO8PdUOpugoO9bD" << std::endl;
  outfile << "CgggbU8OU qOp qOdoUOdcb CgggbU8OU qOp qOdo" << std::endl;
  outfile << "    6OuU  /p u gcoUodpP 6Ou//gcoUodpP" << std::endl;
  outfile << "      \\\\//  /douUP \\\\///douUP" << std::endl;
  outfile << "        \\\\//// \\\\////|||||" << std::endl;
  outfile << "         |||/\\\\\\\\////|||||" << std::endl;
  outfile << "         |||\\/\\\\|||\\/|||||" << std::endl;
  outfile << "         |||||\\/\\\\||||||||" << std::endl;
  outfile << "         |||||||||||||||||" << std::endl;
  outfile << "         |||||||||||||||||" << std::endl;
  outfile << "   .....///////||||||||\\\\\\" << std::endl;

  outfile.close();
  std::cout << GREEN << "\nOutput File Create and close successfully " << RESET
            << std::endl;
}