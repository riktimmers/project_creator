#include <sys/stat.h>
#include <sys/types.h>

#include <fstream>
#include <iostream>
#include <string>

#include "cmakelists_library.h"

int main(int argc, char *argv[]) {
  std::string project_name;

  if (argc <= 1) {
    std::cout << "Enter project name\n";
    exit(0);
  }

  project_name = argv[1];

  const std::string path = "./" + project_name;
  const std::string build_path = "./" + project_name + "/build";
  const std::string src_path = "./" + project_name + "/src";
  const std::string include_path = "./" + project_name + "/include";
  const std::string cmake_path = "./" + project_name + "/cmake";

  mkdir(path.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
  mkdir(build_path.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
  mkdir(src_path.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
  mkdir(include_path.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
  mkdir(cmake_path.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

  const std::string cmake_file = createCmakeLists(project_name);
  std::ofstream output_file(path + "/CMakeLists.txt");

  output_file << cmake_file;
  output_file.close();

  std::ofstream gitignore_file(path + "/.gitignore");
  gitignore_file << "build/\n";
  gitignore_file << ".cache/";
  gitignore_file.close();

  std::ofstream ignore_file(path + "/.ignore");
  ignore_file << "build/\n";
  ignore_file << ".cache/";
  ignore_file.close();

  const std::string cmake_in_file = createCmakeInFile(project_name);
  std::ofstream output_cmake_in_file(cmake_path + "/Config.cmake.in");

  output_cmake_in_file << cmake_in_file;
  output_cmake_in_file.close();
}
