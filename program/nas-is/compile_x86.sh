clang -O3 is.c -c
clang -O3 is.o ../nas-common/c_print_results.c ../nas-common/c_timers.c ../nas-common/wtime.c -o bin/x86/is-no

clang -O3 is.c -S -emit-llvm  -Xclang -load -Xclang ../../build/indirect/LLVMPJT.so
clang -O3 is.ll -c
clang -O3 is.o ../nas-common/c_print_results.c ../nas-common/c_timers.c ../nas-common/wtime.c -o bin/x86/is-auto