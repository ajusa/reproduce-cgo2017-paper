# This script runs unoptimized and optimized code
# $ ./run.sh toy

# Build pass
make -C build/

# Compile and run unoptimized code
clang -o ${1} ${1}.c
echo -e "\n>> Performance of unoptimized code"
./${1}

# Compile and run optimized code
clang -emit-llvm ${1}.c -c -o ${1}.bc
opt -o ${1}.swpf.bc -O3 -load build/indirect/LLVMPJT.so < ${1}.bc > /dev/null
clang ${1}.swpf.bc -o ${1}_swpf
echo -e "\n>> Performance of optimized code"
./${1}_swpf