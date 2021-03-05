sh c_compile.sh
sh ps_compile.sh
ARG=$1
./push_swap_program $ARG | ./checker_program $ARG