#include "main.hpp"

void	move_up(int **arr, Person *person, int size);
void	move_down(int **arr, Person *person, int size);
void	move_right(int **arr, Person *person, int size);
void	move_left(int **arr, Person *person, int size);

void	loop(int **arr, int size, Person *persArr)
{
	int i = 0;
	Function funcs[4] = {&move_up, &move_down, &move_right, &move_left};
	while (persArr[0].health)
	{
		i++;
		srand(i);
		funcs[rand() % 4](arr, &persArr[0], size);
		//if (i % 10 == 0)
			print_matrix(arr, size, *persArr);
			// std::cout << " [" << persArr[0].health << " " << persArr[0].x << " " << persArr[0].y << "] ";
	}
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

void	move_up(int **arr, Person *person, int size)
{
	//int oldX = person->x, oldY = person->y;
	if (person->y > 0 && arr[person->y - 1][person->x] != 2)
	{
		arr[person->y][person->x] = 0;

		person->y -= 1;
		stats(arr, person);
		std::cout << "a";
	}
}
void	move_down(int **arr, Person *person, int size)
{
	if (person->y < size - 1 && arr[person->y + 1][person->x] != 2)
	{
		arr[person->y][person->x] = 0;

		person->y += 1;
		stats(arr, person);
		std::cout << "b";
	}
}
void	move_right(int **arr, Person *person, int size)
{
	if (person->x < size - 1 && arr[person->y][person->x + 1] != 2)
	{
		arr[person->y][person->x] = 0;
		person->x += 1;
		stats(arr, person);

		std::cout << "c";
	}

}
void	move_left(int **arr, Person *person, int size)
{
	if (person->x > 0 && arr[person->y][person->x - 1] != 2)
	{
		arr[person->y][person->x] = 0;

		person->x -= 1;
		stats(arr, person);
		std::cout << "d";
	}

}