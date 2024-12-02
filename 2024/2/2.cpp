#include <bits/stdc++.h>

std::vector<int> get_cleaned_data(const std::string& line)
{
  std::stringstream ss(line);
  int nbr;
  std::vector<int> cleaned_data;
  while(ss >> nbr)
  {
    cleaned_data.push_back(nbr);
  }
 return cleaned_data;
}
  

int get_ex1(std::vector<std::string>& input)
{

  int number_of_safe_reports = 0;
  for(const std::string& line : input)
  {
      std::vector<int> data = get_cleaned_data(line);
      int prev = data[0];
      int ascending = data[0] - data[1] < 0;
      int curr_sum = 0; 
      bool is_safe = true;
      for(int i = 1; i < data.size(); i++)
      {
        if ((data[i] < prev && ascending) || (data[i] > prev && !ascending))
        {
          is_safe = false;
        }
        int diff = std::abs(data[i] - prev);
        if (diff == 0 || diff > 3)
        {
          is_safe = false;
        }
        prev = data[i];
      }
      number_of_safe_reports += is_safe;
  }
  return number_of_safe_reports;
}

bool is_safe_level(std::vector<int>& levels)
{
  int prev = levels[0];
  int ascending = levels[0] - levels[1] < 0;
  int curr_sum = 0; 
  bool is_safe = true;
  for(int i = 1; i < levels.size(); i++)
  {
    if ((levels[i] < prev && ascending) || (levels[i] > prev && !ascending))
    {
      is_safe = false;
    }
    int diff = std::abs(levels[i] - prev);
    if (diff == 0 || diff > 3)
    {
      is_safe = false;
    }
    prev = levels[i];
  }
  return is_safe;
} 

std::vector<int> create_new_subvector(std::vector<int>& data, int index_to_remove)
{
  std::vector<int> sub_vec;
 
  for(int i = 0; i < data.size(); i ++)
  {
    if(i != index_to_remove)
    {
      sub_vec.push_back(data[i]);
    }
  }
  return sub_vec;
}

int get_ex2(std::vector<std::string>& input)
{
  int number_of_safe_reports = 0;
  for(const std::string& line : input)
  {
    std::vector<int> data = get_cleaned_data(line);
    bool is_safe = false;
    for(int i = 0; i < data.size(); i++)
    {
      std::vector<int> sub_vec = create_new_subvector(data, i);
      if (is_safe_level(sub_vec))
      {
        is_safe = true;
      }
    }
    number_of_safe_reports += is_safe;
  }
  return number_of_safe_reports;
}
