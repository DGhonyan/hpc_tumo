export OMP_NUM_THREADS=${1:-1}
PROCS=${2:-1}

make && mpirun --quiet -n $PROCS --oversubscribe ./main $4 $5 $3