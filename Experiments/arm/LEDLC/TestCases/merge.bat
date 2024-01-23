@echo off
setlocal

REM 设置源文件夹和目标文件
set "source_folder=%~dp0"
set "output_file=%source_folder%\merged.bin"

REM 检查输出文件是否已存在，如果存在则删除
if exist "%output_file%" del "%output_file%"

REM 合并文件
for %%f in ("%source_folder%\*.bin") do (
    type "%%f" >> "%output_file%"
)

echo %output_file%
