#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <cstdio>

int get_ex1(std::vector<std::string>& input);
int get_ex2(std::vector<std::string>& input);

std::vector<std::string> get_input(int day, std::string& file_type_name)
{
  std::string input_file_type_name = std::to_string(day) + "/" + file_type_name + "_" + std::to_string(day) + ".txt";
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
    std::cerr << "Call program as follows: ./out <day_number>\n";
    return EXIT_FAILURE;
  }
  
  int exercise_nbr = 0;
  int day = 0;

  if (argc >= 2)
  {
    day = atoi(argv[1]);
    std::cout << "Running program for Day " + std::to_string(day) << "\n";
  }

  if (argc >= 3)
  {
    exercise_nbr = atoi(argv[2]);
    std::cout << "Running exercise: " << exercise_nbr << "\n";
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
  std::cout << "\nProceeding with " + file_type_name + " input\n\n";



  std::vector<std::string> input = get_input(day, file_type_name);

  int res_1 = -1;
  int res_2 = -1;

  if (exercise_nbr == 0 || exercise_nbr == 1)
  {
    std::cout << "Running ex1\n";
    res_1 = get_ex1(input);
    std::cout << "Result ex1 = " << res_1 << "\n\n";
  }
  
  if (exercise_nbr == 0 || exercise_nbr == 2)
  {
    std::cout << "Running ex2\n";
    res_2 = get_ex2(input);
    std::cout << "Result ex2 = " << res_2 << "\n\n";
  }

  if (!res_1)
  {
    std::cerr << "Error: ex1 failed\n";
    return EXIT_FAILURE;
  }

  if (!res_2)
  {
    std::cerr << "Error: ex2 Failed\n";
    return EXIT_FAILURE;
  }
 
  std::cout << "GG\n";
  return EXIT_SUCCESS;
}

