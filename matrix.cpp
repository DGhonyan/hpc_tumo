#include "main.hpp"

static int	persCount(int **arr, int n, int m)
{
	return (1);
	int count = 0;
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			if (arr[i][j] == 2)
				count++;
		}
	}
	return (count);
}

Person	*allocate_persons(int **arr, int n ,int m)
{
	int		k = 0;
	Person	*personArr = (Person *)malloc(sizeof (*personArr) * persCount(arr, n, m));

	if (!personArr)
		exit (EXIT_FAILURE);
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			if (arr[i][j] == 2)
			{
				Person person;
				personArr[k] = person;
				personArr[k].x = j;
				personArr[k].y = i;
				break ;
			}
		}
	}
	return (personArr);
}

void	print_matrix(int **arr, int n, int m, Person person)
{
	for (int i = 0; i < n + 2; i++)
	{
		for (int j = 0; j < m + 2; j++)
		{
			if (arr[i][j] == 1)
				std::cout << BMAGENTA << arr[i][j] << RESET << " ";
			else if (arr[i][j] == 2)
			{
				std::string color;
				if (person.health >= 100)
					color = BGREEN;
				else if (person.health >= 80 && person.health < 100)
					color = BYELLOW;
				else if (person.health >= 50 && person.health < 80)
					color = BCYAN;
				else if (person.health >= 25 && person.health < 50)
					color = BBLUE;
				else if (person.health >= 1 && person.health < 25)
					color = BRED;
				else
					color = RED;
				std::cout << color << arr[i][j] << RESET << " ";
			}
			else if ((i == 0 || i == n + 1) || (j == 0 || j == (m + 1)))
				std::cout << BBLACK << arr[i][j] << RESET << " ";
			else
				std::cout << arr[i][j] << " ";
		}
		std::cout << "\n";
	}
}


void	fill(int **arr, int n, int m)
{
	for (int i = 0; i < n + 2; i++)
	{
		for (int j = 0; j < m + 2; j++)
		{
			arr[i][j] = 0;
			if ((i > 0 && i < n + 1) && (j > 0 && j < m + 1))
				arr[i][j] = (i == j) || (j == ((m + 2) - 1 - i));
		}
	}
}


int	**allocate_matrix(int n, int m)
{
	int	**res = (int **)malloc(sizeof (*res) * (n + 2));
	int	*row = (int *)malloc(sizeof (*row) * (n + 2) * (m + 2));
	if (!res || !row)
	{
		perror("Malloc's dead");
		exit (EXIT_FAILURE);
	}
	int j = 0;
	for (int i = 0; i < n + 2; i++)
	{
		res[i] = &(row[i * (m + 2)]);
		res[i][j] = 0;
	}
	fill(res, n, m);
	//Person pers;
	//print_matrix(res, n, m, pers);
	return (res);
}

// int	**allocate_matrix(int n, int m)
// {
// 	int	**res = (int **)malloc(sizeof (*res) * (n));
// 	int	*row = (int *)calloc(sizeof (*row), (n) * (m));

// 	if (!res || !row)
// 		exit (EXIT_FAILURE);

// 	for (int i = 0; i < n; i++)
// 	{
// 		res[i] = &(row[i * (m)]);
// 		//res[i][j] = 0;
// 	}
// 	return (res);
// }


// void	print_matrix(int **arr, int n, int m, Person person)
// {
// 	for (int i = 0; i < n; i++)
// 	{
// 		for (int j = 0; j < m; j++)
// 		{
// 			if (arr[i][j] == 1)
// 				std::cout << BMAGENTA << arr[i][j] << RESET << " ";
// 			else if (arr[i][j] == 2)
// 			{
// 				std::string color;
// 				if (person.health >= 100)
// 					color = BGREEN;
// 				else if (person.health >= 80 && person.health < 100)
// 					color = BYELLOW;
// 				else if (person.health >= 50 && person.health < 80)
// 					color = BCYAN;
// 				else if (person.health >= 25 && person.health < 50)
// 					color = BBLUE;
// 				else if (person.health >= 1 && person.health < 25)
// 					color = BRED;
// 				else
// 					color = RED;
// 				std::cout << color << arr[i][j] << RESET << " ";
// 			}
// 			else if ((i == 0 || i == n + 1) || (j == 0 || j == (m + 1)))
// 				std::cout << BBLACK << arr[i][j] << RESET << " ";
// 			else
// 				std::cout << arr[i][j] << " ";
// 		}
// 		std::cout << "\n";
// 	}
// }
