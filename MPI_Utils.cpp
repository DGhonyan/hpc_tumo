#include "main.hpp"

MPI_Datatype	commit_type(void)
{
	MPI_Datatype MPI_PERSON;
	int count = 4;
	int	lengths[] = {1, 1, 1, 1};
	MPI_Aint offsets[] = {
		offsetof(Person, x),
		offsetof(Person, y),
		offsetof(Person, health),
		offsetof(Person, mult),
	};
	MPI_Datatype types[] = {
		MPI_INT,
		MPI_INT,
		MPI_INT,
		MPI_INT,
	};
	MPI_Type_create_struct(count, lengths, offsets, types, &MPI_PERSON);
	MPI_Type_commit(&MPI_PERSON);
	return MPI_PERSON;
}

MPI_Datatype	vector(int size, int n, int m)
{
	int				vector_size = n / size + 2;
	MPI_Datatype	MPI_VECTOR;

	MPI_Type_vector(vector_size, m + 2, m + 2, MPI_INT, &MPI_VECTOR);
	MPI_Type_commit(&MPI_VECTOR);

	return (MPI_VECTOR);
}