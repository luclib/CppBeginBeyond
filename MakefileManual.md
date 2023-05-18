# Makefiles

**Makefiles** (or **makefiles**) are configuration files used to automate the build process of software programs running in **Unix-like** operating systems (e.g. **Linux**).

 They are used to specify the dependencies between source code files, object files, and executable files, and to define the commands that should be executed to build the program.

**Make** is the automation tool responsible for building these executable programs and libraries from the makefile; it uses the Linux **`make`** utility (i.e. console command) to generate the target programs directly from the terminal.

> In order words, **Make** functions as the *cook* whereas the *Makefile* is the *cookbook* containing the instructions and ingredient list for each recipe (i.e. the target program).

Makefiles are written in a specific format that defines targets, dependencies, and commands to be executed when a target is built. 

* When a Makefile is executed, the make utility reads the file and determines which targets need to be rebuilt based on their dependencies and modification times.
* It then executes the necessary commands to build the target, which may involve compiling source code files, linking **object files**, or running various scripts.

>**Note**
 The following guide uses **C++** as the programing language for its sample applications, and the **GNU make** set of build automation tools, including the **GCC compiler** selection for the C/C++ language. These are installed by default in *Debian-based* distributions.
>
>Other compiler sets like **LLVM** are available for other Linux distributions, while Visual Studio comes with it own C/C++ compiling tools such as **MSVC**, **Clang**, **CMake**, and **MSBuild** for building C/C++ application in *Windows*.

## The **`make`** process

The entire building process of Makefiles comprises three distincts steps:
1. **Preprocessing**
2. **Compilation**
3. **Linking**

Each of these processes is handled by a separate program in the GNU make tool set. For C++ programs, these are:
 * The **C Preprocessor** that provides the ability for the inclusion of C++ header files and executing preprocessor instructions marked by the `#` statements at top and bottom of the header files.
* The **GNU C++ Compiler** (**`g++`**) that processes compilation, assembly and linking of the target and its dependencies.
* The **GNU Linker** (**`ld`**) combines a number of object and archive files, relocates their data and resolves the symbol references marked by the `$()` in the target commands.

Each of these steps is important to keep in mind, especially when building complex `make` projects that contain separate directories for header files, source code files, and shared libraries.


## Makefile Syntax
A Makefile consists of a set of *rules* with the following syntax:
```Makefile
targets: prerequisites
  command
  command
  command
```
* The *targets* are file names separated by spaces. Generally, there is only one per rule.
* The *commands* are a series of steps typically used to make the target.
* The *prerequisites* are also file names, separated by spaces, that need to exist before the commands for the target can be run.
  These are also called *dependencies* and can be thought of as the arguments that the target needs to execute its commands.

All of the targets are to be run from the *command line*. 

### Single-directory projects

 The simplest target consists of compiling and building an executable file with a *single* command, but it can **only** take place in single-folder projects.
 
 In the following example, we are working with a single directory that contains a `main.cpp` file and a single Makefile:
```Makefile
main: main.cpp
    g++ -o main main.cpp
```
* `main` is the target of the build file; it is also the name of the command to be run in the command terminal.
* `g++` is the name of  the C++ compiler we are using to build and run the code.
* `-o` an argument that allows us to rename our executable file to `main`. 
If we choose not to append `-o` to our `make` command, then the compiler will name the file **`a.out`** by default.
* `main.cpp`: our dependency.


To run a Makefile, we need to open our terminal at the *root project directory* and then run `make`, followed by the name of the target.
```bash
make main
```

If more source files were added to our project directory that `main.cpp` depended on, we would simply append these to our target:
```cpp
main: main.cpp source1.cpp source2.cpp
    g++ -o main main.cpp
```

#### Headers and Source Files
Most, if not all, C++ programs will divide their classes into headers files and source files (see **C++ manual** for further details).
* **header file** (**`*.h`**) contain all of the class members and function prototypes (i.e. method declarations).
* **source file** (**`*.cpp`**) contains the function definitions or implementations.



### Object (`*.o`) Files
In a Makefile, `.o` files are **object files** that are produced by compiling source code files.

When compilling a C++ file, the compiler generates an object file containing the compiled code; that is, machine code that can be linked with other object files and libraries to create an executable program.

Output files in a Makefile can speed up the build process by only recompiling the source code files that have changed since the last build. This is because the compiler only needs to recompile the changed source files into new `.o` files, rather than recompiling all of the source files in the project.

Here's an example Makefile rule that uses .o files:

```Makefile
my_program: main.o my_functions.o
    g++ -o my_program main.o my_functions.o

main.o: main.cpp
    g++ -c -o main.o main.cpp

my_functions.o: my_functions.cpp
    g++ -c -o my_functions.o my_functions.cpp
```

* `my_program` target depends on the `main.o` and `my_functions.o` files, which are produced by compiling the `main.cpp` and `my_functions.cpp` source code files, respectively.
* The `-c `flag with g++ tells the compiler to compile the source code into an object file without linking.
* Only when the command to create `my_program` is envoked, will the compiler link the different output files together.

### Header (`.h`) files

To use header files in a Makefile, you need to specify the dependencies between source files and header files.

**For example**:

```Makefile
my_program: main.cpp my_functions.cpp my_header.h
    g++ -o my_program main.cpp my_functions.cpp
```

* The `my_program` rule specifies the dependencies between the source files `main.cpp`, `my_functions.cpp`, and the header file `my_header.h`.
* When any of these files change, make will rebuild the `my_program` target.

When compiling ***C++ source files*** that use header files in directories other than that of the main program, you need to include the header files using the `-I` flag with the directory path where the header files are located.

**For example**:

```Makefile
my_functions.o: my_functions.cpp my_header.h
    g++ -c -o my_functions.o my_functions.cpp -I/path/to/header/files
```

### Makefile Variables

Makefiles use variables as shorthands for shell commands and arguments that can be reused across serveral make commands.

#### CXX and CXXFLAGS

**`CXX`** and **`CXXFLAGS`** are the most common variables in a Makefile:

* **`CXX`** specifies the C++ compiler to use when building C++ source files.
* **`CXXFLAGS`** contains compile options to the C++ compiler, including debug options, optimization level, warning levels, or any other extra flags

For example, consider the following Makefile:

```Makefile
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic

main: main.o
    $(CXX) $(CXXFLAGS) -o main main.o

main.o: main.cpp
    $(CXX) $(CXXFLAGS) -c main.cpp

clean:
    rm -f main main.o
```

The `CXX` variable is set to `g++`: the GNU C++ compiler.

The `CXXFLAGS` variable feeds a set of compiler options —`-Wall`, `-Wextra`, and `-pedantic`— to enable extra warnings and pedantic checks:

* `-Wall` enables a set of common warnings that can help detect potential issues in your code, such as warning about unused variables or uninitialized variables, which can lead to bugs or performance issues.
* `-Wextra` enables additional warnings that are not included in -Wall. These warnings are often related to coding conventions and can help with writing more readable and maintainable code.
* `-pedantic` makes the compiler strictly follow the C++ standard and issue warnings for non-standard code. It can help write code that is more portable and less likely to break on different compilers or platforms.

> **NOTE**: It's generally a good practice to enable these options when compiling C++ code, as they can help catch potential issues and improve the quality of your code.
> **WARNING**: On the other hand, they can also produce a large number of warnings, especially for existing codebases.

#### CPPFLAGS

**`CPPFLAGS`** passes extra flags to the C **P**re**p**rocessor (not to be confused with **C** **P**lus**P**lus!) or any other programs that use the C++ preprocessor.

* The C++ preprocessor does not need to be explicity called as it will be called once the C++ compiler invokes it.
* The most common case of **`CPPFLAGS`** to include the compiler search path using the **`-I`** option

```Makefile
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic
CPPFLAGS = -I /path/to/header_files

main: main.o
    $(CXX) $(CXXFLAGS) $(CPPFLAGS) -o main main.o
```
**Note**:  `$(CXXFLAGS)` and `$(CPPFLAGS)` are **only useful** for the **compilation** phase; that is when Make is compiling the source files into object files. There is no need to add these in the executable target!

#### LDFLAGS

**`LDFLAGS`** pass extra flags to the GNU linker **`ld`**. Similar to **`CPPFLAGS`** except these flags are automatically passed to the linker when the compiler invokes it.

* The most common use is to specify directories where the libraries can be found by using the **`-L`** option.
* However, do **not** include the names of the libraries in the variable.

```Makefile
LDFLAGS = -L. # Search for libraries in the current directory
          -L/usr/foo # Search for libraries in /usr/foo

main.o: main.c
  gcc $(LDFLAGS) -c main.c
```

#### LDLIBS
**`LDLIBS`** contains space-separated list of **shared libraries** that are required by the linker to match all of the dependencies listed by the program.

Their file names are prefixed with **`lib`** and suffixed with **`.so`** or **`.so.1`** in the file explorer. 

**NOTE**: **`LDLIBS`** should be included **`after`** you have listed all your source files. Otherwise, the linker will not be able to link the symbols properly.
* You *must* preface a shared library with the flag **`-l`** before feeding it to the LDLIBS variable.
* Do **not** enter the prefix or the suffix of the file when appending it to the **`LDLIB`** flag in your Makefile


```Makefile
LDFLAGS = -L. # Search for libraries in the current directory
          -L/usr/foo # Search for libraries in /usr/foo

LDLIBS = -lm lfoo # Use libmb and libfoo

main.o: main.c
  gcc $(LDFLAGS) -c main.c $(LDLIBS)
```

>**Note**: When using the **`g++`** driver program, you need to add the option `-Wl,-rpath,/path/to/library/directory` after listing the library file names.

#### MAKEFLAGS

**`MAKEFLAGS`** are used in recursive invocations of **`make`** for projects that have modules or subsystems with their own `Makefile`.

* The top-level `Makefile` will then recursively call `make` for each od the modules.
* The `MAKEFLAGS` variable is automatically set up by `make` and contains all the flags and command line variables that you passed to the top-level `make`.

#### Automatic Variables

**Automatic variables** have values computed afresh for each rule that is executed, based on the target and the prerequisites of the rule.

* **`$@`** is the file name of the target of the rule.
* **`$<`** is the name of the first prerequisite (dependency).
* **`$^`** lists the names of all the prerequisites. 