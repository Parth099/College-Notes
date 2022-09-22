| Github Link                                                                | 
| -------------------------------------------------------------------------- |
| [github-project-1](https://github.com/CIS-3207-F22/project-1-f22-Parth099) |

# Week 1
For week one I worked on investigating `/proc`. I make a mistake here and did a lot of week two work for week **1**. I finished the `.c` file that prints details about `/proc/cpuinfo` and `/proc/meminfo`. The way I made these parsers is they read the `proc` file until a keyword like `CPU` is hit and only print those lines. This allows us to see how many CPUs are on a system as well as learn the sizes of their caches. I employed the same approach for week 2. 

Additionally I also implemented the builtin argument line parser. I tested it with a debug log and it seems to be able to handle input well including malformed input\*. I also got a head start on the `makefile` here. I defined a elementary make file to compile this program.

\* - Missing flags, inputting flags that don't exist, not putting in any args for `-p`.

# Week 2
## Parser Creation
Week 2 is where I worked on the core of the project: the parsers for the `/proc/[PID]/[FILENAME]` files. I made a parser for:
+ `/proc/[PID]/stat`
+ `/proc/[PID]/status`
+ `/proc/[PID]/statm`
+ `/proc/[PID]/cmdline`

The parser for `/proc/[PID]/status` is unique as it takes in an input of `char* key` and attempts to find that key inside of the `status` file. If it does find the key it will trim the white space characters off both of the sides and return the value that the key matches to. This parser is **not** used in the `MYps.c` program but it may serve to be useful in *Week 3*.

The parsers for `/proc/[PID]/stat` and `/proc/[PID]/statm` are alike because they copy the entire content of the respective files into an array of strings. I would have been completed to convert the strings into numbers if we were committing operations but we are only *displaying* the output so there is no need for extraneous computation. Moreover the `stat` file contains some strings at the start of the file that **cannot** be converted to an integer. It was not difficult to create a parser for these files since the length of their contents were known and the fact that each entry was delimited by a space. 

Unlike the parsers for the two files above, the length of the `/proc/[PID]/cmdline` is **unknown**. This forced me to use a dynamically sized array to hold the contents of `cmdline`. The process at a high level is simple:
```c
1. Read cmdline data into buffer (buffer now has \0 in a lot of places)
2. Read and write to an index i in an array of strings until you encounter a \0
3. Shift the write position to index i+1 in the array of strings
4. Jump past the \0
5. If the array is full double the size via realloc()
6. repeat 1 - 5 until buffer reads an EOF
7. At the end of the array of strings place a NULL pointer to mark end of string array
```

## Code Splitting and `makefile`
I split the code I had in one file into several header files with the following demarcations:
1. `parsers.h` - see name
2. `get_pid_list.h` - gets the list of valid PIDs\*
3. `proc_paths.h` - opens a read only `/proc` files and swallows errors

\* - This file currently reports **ALL** process and not the ones **only created** by the current user. This functionality is not yet added and will be added in the main `MYps.c` program to maintain the reusability of that program. 

Each of these files are complied down to object code and the the make process runs a command to link them together to make `MYps.c` functional as most of the code is defined in external `.c` files and declared in `.h` files. 

> This is a `.md` file with styling which is why It will look different from the same file on git hub.  