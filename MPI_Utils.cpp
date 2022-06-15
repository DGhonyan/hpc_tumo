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
