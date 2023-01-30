#include <iostream>
#include <vector>   
#include <algorithm> 

#define KAPREKARS_CONSTANT 6174

bool ascending_order(int i, int j) { return (i < j); }
bool descending_order(int i, int j) { return (i > j); }

int ascended = 0;
int descended = 0;

void split_digits(int number)
{
	ascended = 0;
	descended = 0;

	int temp = number;
	if (number < 100)
	{
		temp = number * 100;
	}
	if (number < 1000)
	{
		temp = number * 10;
	}

	std::vector<int> numbers;
	while (temp > 0) {
		int digit = temp % 10;
		numbers.push_back(digit);
		temp /= 10;
	}

	std::sort(numbers.begin(), numbers.end(), ascending_order);
	int asc_multiplier = 1000;
	// Ascending 
	for (int i = 0; i < numbers.size(); i++)
	{
		ascended += (numbers.at(i) * asc_multiplier);
		if (asc_multiplier <= 0)
		{
			return;
		}
		asc_multiplier /= 10;
	}


	std::sort(numbers.begin(), numbers.end(), descending_order);
	int desc_multiplier = 1000;

	for (int i = 0; i < numbers.size(); i++)
	{
		descended += (numbers.at(i) * desc_multiplier);
		if (desc_multiplier <= 0)
		{
			return;
		}
		desc_multiplier /= 10;
	}

	printf("%d - %d", descended, ascended);
}

int constant_steps = 1;

int calculate_kaprekars(int num)
{
	printf("%d => (", num);
	split_digits(num);
	int temp = descended - ascended;
	printf(") = %d\n", temp);
	if (temp == KAPREKARS_CONSTANT)
	{
		printf("Constant found %d, amount of steps: %d\n", temp, constant_steps);
		constant_steps = 1;
		return temp;
	}
	++constant_steps;
	calculate_kaprekars(temp);

}

int main()
{
	calculate_kaprekars(13);
	return 0;
}
