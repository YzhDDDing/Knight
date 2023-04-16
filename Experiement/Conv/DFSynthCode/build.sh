gcc *.c -O0 -static -o GCC_O0.exe
gcc *.c -O1 -static -o GCC_O1.exe
gcc *.c -O2 -static -o GCC_O2.exe
gcc *.c -O3 -static -o GCC_O3.exe

clang *.c -O0 -static -o CLANG_O0.exe
clang *.c -O1 -static -o CLANG_O1.exe
clang *.c -O2 -static -o CLANG_O2.exe
clang *.c -O3 -static -o CLANG_O3.exe
