#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {

  Bureaucrat miniTrump("Mr Mini Trump", 100);
  Bureaucrat trump("Mr Trump", 15);
  AForm *testament = new ShrubberyCreationForm();
  AForm *contract = new ShrubberyCreationForm();
  try{
    std::cout << testament << std::endl;

  }


  testament->beSigned(trump);
  trump.signForm(*testament);
  trump.executeForm(*testament);
}