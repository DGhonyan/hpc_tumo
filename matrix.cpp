#include "main.hpp"

static int	persCount(int **arr, int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i][j] == 2)
				count++;
		}
	}
	return (count);
}

Person	*allocate_persons(int **arr, int size)
{
	int		k = 0;
	Person	*personArr = (Person *)malloc(sizeof (*personArr) * persCount(arr, size));

	if (!personArr)
		exit (EXIT_FAILURE);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i][j] == 2)
			{
				Person person;
				personArr[k] = person;
				personArr[k].x = j;
				personArr[k].y = i;
				k++;
			}
		}
	}
	std::cout << personArr[0].x << personArr[0].y;
	return (personArr);
}

void	print_matrix(int **arr, int size, Person person)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i][j] == 1)
				std::cout << MAGENTA << arr[i][j] << RESET << " ";
			// else if (arr[i][j] == 0)
			// 	std::cout << MAGENTA << arr[i][j] << RESET << " ";	
			else if (arr[i][j] == 2)
			{
				std::string color;
				if (person.health >= 100)
					color = GREEN;
				else if (person.health >= 80 && person.health < 100)
					color = YELLOW;
				else if (person.health >= 50 && person.health < 80)
					color = CYAN;
				else if (person.health >= 25 && person.health < 50)
					color = BLUE;
				else if (person.health >= 1 && person.health < 25)
					color = RED;
				else
					color = BLACK;
				std::cout << color << arr[i][j] << RESET << " ";
			}
			else
				std::cout << arr[i][j] << " ";
				
		}
		std::cout << "\n";
	}
}

int	**allocate_matrix(int size)
{
	int	**res = (int **)malloc(sizeof (*res) * size);
	if (!res)
		exit (EXIT_FAILURE);
	//int	*row = (int *)calloc(sizeof (*row), size);

	for (int i = 0; i < size; i++)
	{
		//res[i] = row;
		res[i] = (int *)calloc(sizeof (*res[i]), size);
		if (!res[i])
			exit (EXIT_FAILURE);
		res[i][i] = 1;
		res[i][size - i - 1] = 1;
	}
	res[size / 2][size / 2] = 2;
	//print_matrix(res, size);
	return (res);
}
