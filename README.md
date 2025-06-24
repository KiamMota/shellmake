# shmake

**shmake** is a shell script preprocessor that reads specially marked comment blocks and generates output tailored to the current system environment. It supports conditions such as Linux distribution, allowing a single configuration file to serve multiple targets.

shmake is written in C for speed and minimal dependencies. It performs a linear scan of the input, includes or excludes blocks based on context, and writes a plain shell script as output. It does not execute any logic, only filters text based on predefined rules.

shmake is suitable for managing `.bashrc`, setup scripts, or multi-distro shell environments.

shmake is not available as a package. To use it, you must download the source code and compile it using `cmake`.

 Building shmake

To build shmake from source:

```sh
git clone https://github.com/KiamMota/shmake.git
cd shmake
mkdir build && cd build
cmake .. && make
