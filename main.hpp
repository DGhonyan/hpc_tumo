#ifndef MAIN_H

# define MAIN_H

# include <mpi.h>
# include <omp.h>
# include <ctime>
# include <thread>
# include <chrono>
# include <stdlib.h>
# include <iostream>
# include <sys/types.h>
# include <sys/sysinfo.h>
# include "Person.hpp"
# include "colors.h"

typedef void (*Function) (int **, Person *, int, int);

void			print_matrix(int **arr, int n, int m, Person person);
void			loop(int **arr, int n, int m, Person *persArr, int iterations);
int				**allocate_matrix(int n, int m);
MPI_Datatype	commit_type(void);
Person			*allocate_persons(int **arr, int n, int m);

//# include "mlx_linux/mlx.h"

#endif