#include <iostream>
#include <string>
#include "argh.h"
#include "csv.h"
#include "date.h"

using namespace date;
using namespace std::chrono;

int main(int, char *argv[]) {
  argh::parser cmdl(argv);

  if (cmdl[{ "-h", "--help" }]) {
    std::cout << "How do test the code:" << std::endl;
    std::cout << "Try the test CSV by running: './main -i 'datasets/testdata.csv'." << std::endl;
  }

  if (cmdl[{"-i", "--input-file"}]) {
    std::string FileName{argv[2]};
    std::cout << FileName << std::endl;
    
    io::CSVReader<4> in(FileName);
    in.read_header(io::ignore_extra_column, "day", "year", "month", "measurement");
    int d; int y; int m; double measurement;
    while(in.read_row(d, y, m, measurement)){
      auto date = year{y}/m/d;
      auto WeekDay = weekday{date};
      //std::cout << day << " " << year<< " " << month<< " " << measurement << std::endl;
      std::cout << date << " " << WeekDay << " " << measurement << std::endl;
    } 
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
