clang++ -O2 -fsanitize=fuzzer -Wl,/stack:104857600 LANSwitch.c LANSwitch_data.c main.c LibFuzzerUtility.c -o Fuzzer.exe
del Fuzzer.exp
del Fuzzer.lib
del Fuzzer.pdb
