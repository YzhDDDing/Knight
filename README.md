# Knight


## Overview

Knight is an efficient code generator which can effectively optimizing loop semantics within the target Simulink model.

Basic idea: Knight precisely analyses the interactions between model blocks to identify state-dependent blocks, and then effectively optimizes the redundant calculations caused by state-dependent blocks.

## Requirements

- Simulink (Matlab R2022b)
- GCC (Version 11.3.0)
- Clang (Version 14.0.6)

The above versions of Simulink, GCC, and Clang are utilized in our evaluation. 

## Repository Structure

### Experiments

The evaluation results on x86 and ARM architectures. Each sub-folder named by "Model_Name" contains the generated code and compiled executable files among different compilers and optimization levels. 

For quick start and reproducing our evaluation results, you can simply run the following instructions.

```shell
	sh build.sh
	sh run.sh $execution_times$
```

### Model_IR

This folder contains the parsed IR (Intermediate Representation). For a target Simulink model, we first translate it into readable MIR, and then convert the MIR into IL for code generation. The IL files with suffix (\_ Optimized) is the IL files optimized by Knight.

### Models

This folder contains the benchmark Simulink models. Each of the model is collected from academic works and our industry partner (HUAWEI).

### Tools

The implementation of our tools. This folder contains different executable files (.exe) for different purpose. We will introduce how to use these files in detail in **Usage Section**.

## Usage

### Workflow of Toolsets

To generate efficient code, you should use the following executable files.

1. **ParserForSimulink.exe**

   > Convert the Simulink model files (SLX) into customized IR (MIR), which contains the detailed model information, such as inport, outport, etc.

   **Useful Flags:**

   - -help: help information
   - -i: input file path of target Simulink model
   - -o: output file path of the generated MIR file

   **Instruction Example:**

   ```shell
   ParserForSimulink.exe -i $Simulink_Model_Path$ -o $Output_MIR_File_Path$
   ```

2. **ILGenerator.exe**

   > Convert the MIR file into IL file, which contains simplified code information and can be used for redundancy elimination.

   **Useful Flags:**

   - -help: help information
   - -i: input file path of MIR file
   - -o: output file path of the generated IL file

   **Instruction Example:**

   ```shell
   ILGenerator.exe -i $MIR_File_Path$ -O $Output_IL_File_Path$
   ```

3. **ILOptimizer.exe**

   > Optimize the obtained IL file

   **Useful Flags:**

   - -help: help information
   - -i: input file path of IL file
   - -m: input file path of MIR file
   - -o: output file path of optimized IL file
   - -lp: loop reshaping (default is false)

   For enabling optimization of loop reshaping, you should use the following instructions.

   ```shell
   ILOptimizer.exe -i $IL_File_Path$ -m $MIR_File_Path$ -o $Output_File_Path$ -lp true
   ```

4. **ILTranslator.exe**

   > Translate the IL file into efficient embedded C code for deployment

   **Useful Flags:**

   - -help: help information
   - -i: input file path of IL file or optimized IL file
   - -o: output directory of the generated code
   - -l: the language of the generated  code
   - -c: generate comment (default is true)
   
   **Instruction Example:**
   
   ```shell
   ILTranslator.exe -i $IL_File_Path$ -o $Output_Code_Path$ -c -l c
   ```

In general, the building workflow is:

Simulink model -> ParserForSimulink.exe -> ILGenerator.exe -> ILOptimizer.exe -> ILTranslator.exe
