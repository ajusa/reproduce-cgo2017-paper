# Build pass
make -C build/

# Change directory
cd program/hashjoin-ph-2/src

# Compile optimized code
clang -O3 npj2epb.c -Xclang -load -Xclang ../../../build/indirect/LLVMPJT.so -c -S -emit-llvm 
clang -O3 npj2epb.ll -c 
clang -O3 npj2epb.o main.c generator.c genzipf.c perf_counters.c cpu_mapping.c parallel_radix_join.c -lpthread -lm -std=c99  -o bin/x86/hj2-auto

# Execute optimized code
cd bin/x86
./hj2-auto

# Change directory
cd ../..

# Compile unoptimized code
clang -O3 npj2epb.c -c 
clang -O3 npj2epb.o main.c generator.c genzipf.c perf_counters.c cpu_mapping.c parallel_radix_join.c -lpthread -lm -std=c99  -o bin/x86/hj2-no

# Execute unoptimized code
cd bin/x86
./hj2-no