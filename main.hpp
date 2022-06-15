#ifndef MAIN_H

# define MAIN_H

# include <mpi.h>
# include <omp.h>
# include <ctime>
# include <thread>
# include <chrono>
# include <stdlib.h>
# include <iostream>
# include "Person.hpp"
# include "colors.h"

typedef void (*Function) (int **, Person *, int);

void			print_matrix(int **arr, int size, Person person);
void			loop(int **arr, int size, Person *persArr);
int				**allocate_matrix(int size);
MPI_Datatype	commit_type(void);
Person			*allocate_persons(int **arr, int size);


//# include "mlx_linux/mlx.h"

#endif