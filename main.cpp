#include "main.hpp"

static void	check_args(int argc, char **argv)
{
	if (argc < 4
		|| (atoi(argv[1]) == 0)
		|| (atoi(argv[2]) == 0)
		|| atoi(argv[1]) < 0 || atoi(argv[2]) < 0)
	{
		std::cout << RED << "Missing or invalid\
			argument for map length\n" << RESET;
		exit (EXIT_FAILURE);
	}
}

int main(int argc, char **argv)
{
	check_args(argc, argv);
	
	MPI_Init(&argc, &argv);

	int	rank;
	int	size;

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	MPI_Datatype MPI_PERSON = commit_type();

	double start = MPI_Wtime();

	int n = atoi(argv[1]);
	int m = atoi(argv[2]);

	int		**arr;
	Person	*person;
	if (rank == 0)
	{
		arr = allocate_matrix(n, m);
		person = allocate_persons(arr, n, m);
	}
	loop(arr, n, m, person, atoi(argv[3]));
	
	double end = MPI_Wtime();

	std::cout << GREEN << "\nTime took to execute: " << end - start << "s" << RESET << "\n";
	MPI_Finalize();
}

//std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	// print_matrix(arr, size);
	// Person *personArr = allocate_arr(atoi(argv[1]));
	// Person person;
	// if (rank == 0)
	// {
	// 	person.health = 2394;
	// 	MPI_Ssend(&person, 1, MPI_PERSON, 1, 1, MPI_COMM_WORLD);
	// 	// int MPI_Ssend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
	// }
	// else
	// {
	// 	std::cout << person.health << "\n";
	// 	MPI_Recv(&person, 1, MPI_PERSON, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	// 	std::cout << person.health << "\n";
	// }
