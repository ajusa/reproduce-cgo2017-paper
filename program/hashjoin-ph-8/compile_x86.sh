cd src
clang -O3 npj8epb.c -Xclang -load -Xclang ../../../build/indirect/LLVMPJT.so -c -S -emit-llvm 
clang -O3 npj8epb.ll -c 
clang -O3 npj8epb.o main.c generator.c genzipf.c perf_counters.c cpu_mapping.c parallel_radix_join.c -lpthread -lm -std=c99  -o bin/x86/hj8-auto

clang -O3 npj8epb.c -c 
clang -O3 npj8epb.o main.c generator.c genzipf.c perf_counters.c cpu_mapping.c parallel_radix_join.c -lpthread -lm -std=c99  -o bin/x86/hj8-no

clang -O3 npj8epbsw.c -DNUMPREFETCHES=3 -DSTRIDE -c 
clang -O3 npj8epbsw.o main.c generator.c genzipf.c perf_counters.c cpu_mapping.c parallel_radix_join.c -lpthread -lm -std=c99  -o bin/x86/hj8-man

for i in 1 2 3 4
do
clang -O3 npj8epbsw.c -DNUMPREFETCHES=$i -DSTRIDE -c 
clang -O3 npj8epbsw.o main.c generator.c genzipf.c perf_counters.c cpu_mapping.c parallel_radix_join.c -lpthread -lm -std=c99  -o bin/x86-offsets/hj8-prefetches-$i
done
