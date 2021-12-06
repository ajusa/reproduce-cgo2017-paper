# Build pass
make -C build/

# Change directory
cd program/nas-is

# Compile optimized code
clang -O3 is.c -S -emit-llvm  -Xclang -load -Xclang ../../build/indirect/LLVMPJT.so
clang -O3 is.ll -c
clang -O3 is.o ../nas-common/c_print_results.c ../nas-common/c_timers.c ../nas-common/wtime.c -o bin/x86/is-auto

# Execute optimized code
cd bin/x86
./is-auto

# Change directory
cd ../..

# Compile unoptimized code
clang -O3 is.c -c
clang -O3 is.o ../nas-common/c_print_results.c ../nas-common/c_timers.c ../nas-common/wtime.c -o bin/x86/is-no

# Execute unoptimized code
cd bin/x86
./is-no