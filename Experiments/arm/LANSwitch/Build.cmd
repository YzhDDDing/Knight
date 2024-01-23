
set ModelName=LANSwitch
set ModelIL=%ModelName%.xml
set ModelConfig=%ModelName%_Cfg.xml
set para_ca=3

mkdir "TestCases"
mkdir "TCGHybridExe\Fuzz"
mkdir "TCGHybridExe\STCG"
mkdir "TCGHybridExe\STCG\Temp"
mkdir "TCGHybridExe\STCG\TestCaseOutput"
mkdir "TCGHybridExe\TestCases"

rd /s/q "TCGHybridExe\Fuzz\In"
mkdir "TCGHybridExe\Fuzz\In"
rd /s/q "TCGHybridExe\Fuzz\Out"
mkdir "TCGHybridExe\Fuzz\Out"
rd /s/q "TCGHybridExe\TestCaseOutputAll"
mkdir "TCGHybridExe\TestCaseOutputAll"
rd /s/q "TCGHybridExe\TempInputForSTCG"
mkdir "TCGHybridExe\TempInputForSTCG"

mkdir outSTCG
mkdir outSTCG\Temp
C:\Users\yuzehong\Desktop\CodeGeneratorToolset\ILTranslator\ILTranslator.exe -i "%ModelIL%" -o "outSTCG" -config "%ModelConfig%" -c false -p false -v false -b true -l cbmc -g true -ca %para_ca%
C:\Users\yuzehong\Desktop\CodeGeneratorToolset\ILTranslator\ILTranslator.exe -i "%ModelIL%" -o "outSTCG" -config "%ModelConfig%" -c true -l tcg_state_search -ca %para_ca%
cd outSTCG
g++ -O2 *.cpp -Wl,--stack=104857600
cd ..
copy "outSTCG\a.exe" "TCGHybridExe\STCG\STCG.exe" /y
copy "outSTCG\main.c" "TCGHybridExe\STCG\main.c" /y

mkdir outFuzz
C:\Users\yuzehong\Desktop\CodeGeneratorToolset\ILTranslator\ILTranslator.exe -i "%ModelIL%" -o "outFuzz" -config "%ModelConfig%" -c false -l libfuzzer -id true -ic true
cd outFuzz
call Build.bat
cd TestCaseConverter
call Build.bat
cd ..
cd ..
copy "outFuzz\Fuzzer.exe" "TCGHybridExe\Fuzz\Fuzzer.exe" /y
copy "outFuzz\TestCaseConverter\Converter.exe" "TCGHybridExe\BinaryTestCaseConverter.exe" /y

mkdir outHybrid
C:\Users\yuzehong\Desktop\CodeGeneratorToolset\ILTranslator\ILTranslator.exe -i "%ModelIL%" -o "outHybrid" -c true -l tcg_hybrid
cd outHybrid
g++ -O2 *.cpp -Wl,--stack=104857600
cd ..
copy "outHybrid\a.exe" "TCGHybridExe\TCGHybrid.exe" /y

pause

REM cbmc.exe --gcc --arch i386 --cover cover --unwind 7 --xml-ui "out/main.c" > out/Temp/out.txt

REM -c "DomainDev_Cfg.xml"