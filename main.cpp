#include "main.hpp"

static void	check_args(int argc, char **argv)
{
	if (argc < 2 || (argv[1][0] != '0' && atoi(argv[1]) == 0) || atoi(argv[1]) < 0)
	{
		std::cout << RED << "Missing or invalid\
			argument for map length\n" << RESET;
		exit (EXIT_FAILURE);
	}
}

int main(int argc, char **argv)
{
	double start = MPI_Wtime();
	check_args(argc, argv);
	int size = atoi(argv[1]);
	int	**arr = allocate_matrix(size);
	Person	*persArr = allocate_persons(arr, size);
	//std::cout << persArr[0].health << persArr[0].x;
	//std::cout << RAND_MAX;
	loop(arr, size, persArr);
	double end = MPI_Wtime();
}

//std::cout << GREEN << "Time took to execute: " << end - start << "s" <<RESET << std::endl;
//std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	// print_matrix(arr, size);
	// MPI_Init(&argc, &argv);

	// int	rank;
	// int	size;

	// MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	// MPI_Comm_size(MPI_COMM_WORLD, &size);

	// MPI_Datatype MPI_PERSON = commit_type();
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

	// MPI_Finalize();