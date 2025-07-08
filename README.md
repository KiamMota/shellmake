# ShellMake: Shell Scripts preprocessor

**ShellMake** is a preprocessor of Shell scripts based on context of meta-comments in the Shell file. Witten in C for performance and minimal dependencies. It performs a linear scan of the input, includes or excludes blocks based on context, environment varables, and writes a plain shell script as output. ShellMake does not execute any logic, only filters text based on predefined rules on meta-comments.

> [!IMPORTANT]
> ShellMake is not available as a package. To use it, you must download the source code and compile it using `cmake`.

 Building shmake

To build shmake from source:

```sh
git clone https://github.com/KiamMota/shmake.git
cd shmake
mkdir build && cd build
cmake .. && make
