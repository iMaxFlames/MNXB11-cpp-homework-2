#include <iostream>
#include <string>
#include "argh.h"

int main(int, char *argv[]) {
  argh::parser cmdl(argv);

  if (cmdl[{ "-h", "--help" }]) {
    std::cout << "CLI in use is argh!, below is the following HTTPS/ for the github repository:" << std::endl;
    std::cout << "https://github.com/adishavit/argh.git" << std::endl;
  }

  if (cmdl[{"-i", "--input-file"}]) {
    std::string FileName{argv[2]};
    // std::cout << FileName << std::endl;
  }

  // std::cout << "I am just a code template, you need to implement the "
  //              "functionality you want to use yourself!"
  //           << std::endl;

  // std::cout << "We were passed " << argc
  //           << " command line arguments, the first of which was " << argv[0]
  //           << std::endl;
  // std::cout << "With a good CLI library, we could use the command line "
  //              "arguments to make a useful program."
  //           << std::endl;
  return 0;
}
