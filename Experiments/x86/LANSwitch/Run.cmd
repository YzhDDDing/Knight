
mkdir "TCGHybridExe"
mkdir "TCGHybridExe\Fuzz"
mkdir "TCGHybridExe\STCG"
mkdir "TCGHybridExe\STCG\Temp"
mkdir "TCGHybridExe\STCG\TestCaseOutput"
mkdir "TestCases"

rd /s/q "TCGHybridExe\Fuzz\In"
mkdir "TCGHybridExe\Fuzz\In"
rd /s/q "TCGHybridExe\Fuzz\Out"
mkdir "TCGHybridExe\Fuzz\Out"
rd /s/q "TCGHybridExe\TestCaseOutputAll"
mkdir "TCGHybridExe\TestCaseOutputAll"
rd /s/q "TCGHybridExe\TempInputForSTCG"
mkdir "TCGHybridExe\TempInputForSTCG"

TCGHybridExe\TCGHybrid.exe -t 3600000

pause
