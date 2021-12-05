cd src
clang -O3 npj2epb.c -Xclang -load -Xclang ../../../build/indirect/LLVMPJT.so -c -S -emit-llvm 
clang -O3 npj2epb.ll -c 
clang -O3 npj2epb.o main.c generator.c genzipf.c perf_counters.c cpu_mapping.c parallel_radix_join.c -lpthread -lm -std=c99  -o bin/x86/hj2-auto

clang -O3 npj2epb.c -c 
clang -O3 npj2epb.o main.c generator.c genzipf.c perf_counters.c cpu_mapping.c parallel_radix_join.c -lpthread -lm -std=c99  -o bin/x86/hj2-no

clang -O3 npj2epbsw.c -DFETCHDIST=64 -DSTRIDE -c 
clang -O3 npj2epbsw.o main.c generator.c genzipf.c perf_counters.c cpu_mapping.c parallel_radix_join.c -lpthread -lm -std=c99  -o bin/x86/hj2-man

for i in 2 4 8 16 32 64 128 256
do
clang -O3 npj2epbsw.c -DFETCHDIST=$i -DSTRIDE -c 
clang -O3 npj2epbsw.o main.c generator.c genzipf.c perf_counters.c cpu_mapping.c parallel_radix_join.c -lpthread -lm -std=c99  -o bin/x86-offsets/hj2-offset-$i
done