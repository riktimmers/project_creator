#include <string> 
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <fstream>
#include "cmakelists.h"

int main(int argc, char *argv[]) {
  std::string project_name;

  if (argc <= 1) {
    std::cout << "Enter project name\n";
    exit(0);
  }

  project_name = argv[1];

  std::string path = "./" + project_name;
  std::string build_path = "./" + project_name + "/build";
  std::string src_path = "./" + project_name + "/src";
  std::string include_path = "./" + project_name + "/include";

  mkdir(path.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
  mkdir(build_path.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
  mkdir(src_path.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
  mkdir(include_path.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
  
  std::string cmake_file = createCmakeLists(project_name);
  std::ofstream output_file(path + "/CMakeLists.txt");

  output_file << cmake_file;
  output_file.close();

  std::ofstream gitignore_file(path + "/.gitignore");
  gitignore_file << "build/";
  gitignore_file.close();
}
