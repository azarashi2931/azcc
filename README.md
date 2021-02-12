azcc: Azarashi2931's C Compiler
====

![x64 Linux CI](https://github.com/azarashi2931/azcc/workflows/x64%20Linux%20CI/badge.svg)
![x64 Cygwin CI](https://github.com/azarashi2931/azcc/workflows/x64%20Cygwin%20CI/badge.svg)
![license](https://img.shields.io/github/license/azarashi2931/azcc)

This is a toy C compiler, developed at seccamp2020.

## Enviroment
+ Linux on x86_64 CPU
+ Cygwin on x86_64 CPU

## Requirement
+ GNU C Compiler
  + For pre-processing, assembling, linking and running some tests.
+ GNU Make
  + For building and running tests.
+ POSIX like shell
  + For running some test shell scripts.

## How to Build and Test
+ `make`: build 1st generation azcc.
+ `make test1`: build and run tests for 1st generation azcc, which is built by gcc, clang, or such other C Compiler.
+ `make test2`: build and run tests for 2nd generation azcc, which is built by 1st generation azcc.
+ `make test3`: build and run tests for 3rd generation azcc, which is built by 2nd generation azcc.
+ `make test-all`: build and run tests for all generation azccs.
+ `make clean`: remove binaries.
+ `make all`: run `make clean` and `make test-all`.

## Usage
### Basic
Makefile outputs `bin/genX/azcc`(`X` is the generation of azcc).  
After running make command, you can do the following: 
```sh
$ cpp source.c > source.i
$ bin/genX/azcc source.i > source.s
$ gcc -o source.out source.s
```
or
```sh
$ cpp source.c | bin/gen1/azcc - | gcc -xassembly -o source.out -
```

### Advanced
You can cross-compile by adding `target` option.  
For example, when you want to compile Cygwin binary on Linux, like the following: 
```sh
$ cpp source.c > source.i
$ bin/genX/azcc source.i --targt=amd64-w64-windows-gnu > source.s
$ gcc -o source.out source.s
```
For a complete list of current supported platform, see [Enviroment](#Enviroment).

## Thanks
+ Rui Ueyama, instructor at seccamp2020
+ hikalium, instructor at seccamp2020
+ hsjoihs, tutor at seccamp2020, contributor of this project
+ sksat, tutor at seccamp2020, contributor of this project
+ Takana-Norimasa, classmate at seccamp2020
+ yanorei32, contributor of this project
+ and more classmates at seccamp2020

## Reference
+ https://www.sigbus.info/compilerbook
  + An online textbook for scratching c compiler, written by Rui Ueyama.
+ https://github.com/rui314/chibicc
  + A C compiler, developed by Rui Ueyama.
+ https://github.com/hsjoihs/c-compiler
  + A C compiler, developed by hsjoihs.
