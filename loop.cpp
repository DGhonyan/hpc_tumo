#include "main.hpp"

void	move_up(int **arr, Person *person, int n, int m);
void	move_down(int **arr, Person *person, int n, int m);
void	move_right(int **arr, Person *person, int n, int m);
void	move_left(int **arr, Person *person, int n, int m);
void	grass_mult(int **arr, int n, int m, int seed);

void	loop(int **arr, int n, int m, Person *persArr, int iterations)
{
	int i = 0;
	Function funcs[4] = {&move_up, &move_down, &move_right, &move_left};
	while (iterations--)
	{
		i++;
		struct sysinfo info;
		sysinfo(&info);
		int	th = 1000;
		unsigned int seed;
		if (persArr[0].health)
		{
			seed = i + ((int)MPI_Wtime() * th) + (info.totalram - info.freeram);
			srand(seed);
			funcs[rand() % 4](arr, &persArr[0], n, m);
		}
		// if (i % 20 == 0)
			print_matrix(arr, n, m, *persArr);
		if (i % 400 == 0 && !persArr[0].health)
			persArr[0].health = 100; 
		seed = i + ((int)MPI_Wtime() * th) + (info.totalram - info.freeram);
		if (i % 10 == 0)
			grass_mult(arr, n, m, seed);
	}
	if (i % 2 != 0)
		print_matrix(arr, n, m, *persArr);
}

void	grass_mult(int **arr, int n, int m, int seed)
{
	srand(seed);
	int i = 1 + (rand() % (n)), j = 1 + (rand() % m);
	if (arr[i][j] != 1 && arr[i][j] != 2)
		arr[i][j] = 1;
}

void	stats(int **arr, Person *person)
{
	if (arr[person->y][person->x] == 1)
	{
		person->health += 10;
		person->mult += 2;
	}
	else
	{
		person->health -= 2;
	}
	arr[person->y][person->x] = 2;
}

void	move_up(int **arr, Person *person, int n, int m)
{
	if (person->y > 1 && arr[person->y - 1][person->x] != 2)
	{
		arr[person->y][person->x] = 0;

		person->y -= 1;
		stats(arr, person);
		// std::cout << "UP\n";
	}
}
void	move_down(int **arr, Person *person, int n, int m)
{
	if (person->y < n&& arr[person->y + 1][person->x] != 2)
	{
		arr[person->y][person->x] = 0;

		person->y += 1;
		stats(arr, person);
		// std::cout << "DOWN\n";
	}
}
void	move_right(int **arr, Person *person, int n, int m)
{
	if (person->x < m&& arr[person->y][person->x + 1] != 2)
	{
		arr[person->y][person->x] = 0;
		person->x += 1;
		stats(arr, person);

		// std::cout << "RIGHT\n";
	}

}
void	move_left(int **arr, Person *person, int n, int m)
{
	if (person->x > 1 && arr[person->y][person->x - 1] != 2)
	{
		arr[person->y][person->x] = 0;

		person->x -= 1;
		stats(arr, person);
		// std::cout << "LEFT\n";
	}

}