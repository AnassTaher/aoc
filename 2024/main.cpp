#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <cstdio>

bool get_ex1(std::vector<std::string>& input, bool debug);
bool get_ex2(std::vector<std::string>& input, bool debug);

std::vector<std::string> get_input(int day, std::string& file_type_name)
{
  std::string input_file_type_name = std::to_string(day) + "/" + file_type_name + ".txt";
  freopen(input_file_type_name.c_str(), "r", stdin);
  std::vector<std::string> input;
  std::string s = "";
  while(getline(std::cin, s))
  {
    input.push_back(s);
  }
  fclose(stdin);
  return input;
}

int main(int argc, char* argv[])
{

  if (argc < 2)
  {
    std::cerr << "Call program as follows: ./out <day_number>" << std::endl;
    return EXIT_FAILURE;
  }
  
  bool debug = false;
  int day = 0;

  if (argc >= 2)
  {
    day = atoi(argv[1]);
    std::cout << "Running program for Day " + std::to_string(day) << std::endl;
  }

  if (argc >= 3)
  {
    debug = atoi(argv[2]);
    std::cout << "Running program in debug mode" << std::endl;
  }

  std::cout << "Which input would you like to choose?\n"
               "\t1) Small input\n"
               "\t2) Full input\n";
  int choice = 0;
  std::string file_type_name = "small";
  std::cin >> choice;
  
  switch (choice)
  {
    case 1:
      file_type_name = "small";
      break;
    case 2:
      file_type_name = "full";
      break;
    default:
      break;
  }
  std::cout << "Proceeding with " + file_type_name + " input\n";



  std::vector<std::string> input = get_input(day, file_type_name);
  bool res_1 = get_ex1(input, debug);
  bool res_2 = get_ex2(input, debug);

  if (!res_1)
  {
    std::cerr << "Error: Ex1 failed" << std::endl;
    return EXIT_FAILURE;
  }

  if (!res_2)
  {
    std::cerr << "Error: Ex2 Failed" << std::endl;
    return EXIT_FAILURE;
  }
 
  std::cout << "GG" << std::endl;
  return EXIT_SUCCESS;
}

