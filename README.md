# Knight

We propose an efficient code generator for data-intensive Simulink models via loop reshaping.

To use this work, you can follow these instructions. 

##### ParserForSimulink.exe

> Convert the Simulink model files (SLX) into customized IR (MIR)

- -help: help information
- -i: input file path of Simulink model file
- -o: output file path of MIR file

##### ILGenerator.exe

> Convert the MIR file into IL file which contains code information and can be utilized for optimization

- -help: help information
- -i: input file path of MIR file
- -o: output file path of IL file

##### ILOptimizer.exe

> Optimize the obtained IL file 

- -help: help information
- -i: input file path of IL file
- -o: output file path of optimized IL file

##### ILTranslator.exe

> Translate the IL file into embedded C code for deployment

- -help: help information
- -i: input file path of IL/Optimized IL file
- -o: output directory of the generated code
- -c: generate comment (default is true)