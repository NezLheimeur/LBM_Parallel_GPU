#include <cstdlib>
#include <string>
#include <iostream>
#include <chrono>

#include "lbm/LBMSolver.h" 

// TODO : uncomment when building with OpenACC
#include "utils/openacc_utils.h"

int main(int argc, char* argv[])
{

  // read parameter file and initialize parameter
  // parse parameters from input file
  std::string input_file = argc>1 ? std::string(argv[1]) : "flowAroundCylinder.ini";

  // TODO : uncomment the last two lines when activating OpenACC
  // print OpenACC version / info
   print_openacc_version();
   init_openacc();
   

  typedef std::chrono::high_resolution_clock Time;

  ConfigMap configMap(input_file);

  // test: create a LBMParams object
  LBMParams params = LBMParams();
  params.setup(configMap);

  // print parameters on screen
  params.print();
  
  auto start =Time::now();

  LBMSolver* solver = new LBMSolver(params);

  solver->run();

  auto end =Time::now();

  double diff = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();

  std::cout << "Elapsed time : " << diff << std::endl;

  delete solver;

  return EXIT_SUCCESS;
}
