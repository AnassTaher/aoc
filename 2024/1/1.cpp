#include <bits/stdc++.h>

std::pair<std::vector<int>, std::vector<int>> get_cleaned_data(std::vector<std::string>& input)
{
  std::vector<int> list1, list2;

  for (const auto &line : input)
  {
    std::stringstream ss(line);
    int a, b;
    ss >> a >> b;
    list1.push_back(a);
    list2.push_back(b);
  }

  return {list1, list2};
}

int get_ex1(std::vector<std::string>& input)
{
  int total_distance = 0;
  auto [list1, list2] = get_cleaned_data(input);
  
  std::sort(list1.begin(), list1.end());
  std::sort(list2.begin(), list2.end());
  
  for (int i = 0; i < list1.size() && i < list2.size(); i++)
  {
    total_distance += std::abs(list2[i] - list1[i]);
  }

  return total_distance;
}

int get_ex2(std::vector<std::string>& input)
{
  int similarity_score = 0;
  auto [list1, list2] = get_cleaned_data(input);
  
  std::map<int, int> freq_map;
  for (const int& nbr : list2)
  {
    freq_map[nbr]++;
  }

  for (const int& nbr : list1)
  {
    if (std::find(list2.begin(), list2.end(), nbr) != list2.end())
    {
      similarity_score += freq_map[nbr] * nbr;
    }
  }

  return similarity_score;
}
