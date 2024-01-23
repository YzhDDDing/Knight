runCount="1"
if [ "$1" ]; then
    runCount=$1
fi

echo "\n GCC_O2"
./GCC_O2.exe $runCount
./GCC_O2.exe $runCount
./GCC_O2.exe $runCount
echo "\n GCC_O3"
./GCC_O3.exe $runCount
./GCC_O3.exe $runCount
./GCC_O3.exe $runCount

echo "\n CLANG_O2"
./CLANG_O2.exe $runCount
./CLANG_O2.exe $runCount
./CLANG_O2.exe $runCount
echo "\n CLANG_O3"
./CLANG_O3.exe $runCount
./CLANG_O3.exe $runCount
./CLANG_O3.exe $runCount
