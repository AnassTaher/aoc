#include <bits/stdc++.h>
#include <regex>


int get_ex1(std::vector<std::string> &input)
{
  std::regex reg("mul\\((\\d+),(\\d+)\\)");
	std::smatch m;
	int sum = 0;

	for (std::string line : input)
	{
		while (std::regex_search(line, m, reg))
		{
			int a = std::stoi(m[1].str());
			int b = std::stoi(m[2].str());
			sum += a * b;
			line = m.suffix().str(); // Move to the next match in the line
		}
	}

	return sum;
}

int get_ex2(std::vector<std::string> &input)
{
	std::regex reg(R"(mul\((\d+),(\d+)\)|do\(\)|don't\(\))");
	std::smatch m;
	int sum = 0;
	bool mul_enabled = true; // Initially, mul is enabled

	for (std::string line : input)
	{
		while (std::regex_search(line, m, reg))
		{
			if (m[0].str() == "do()")
			{
					mul_enabled = true; // Enable future mul instructions
			}
			else if (m[0].str() == "don't()")
			{
					mul_enabled = false; // Disable future mul instructions
			}
			else if (mul_enabled)
			{
					int a = std::stoi(m[1].str());
					int b = std::stoi(m[2].str());
					sum += a * b;
			}

			line = m.suffix().str(); // Move to the next match in the line
		}
	}
	
  return sum;
}