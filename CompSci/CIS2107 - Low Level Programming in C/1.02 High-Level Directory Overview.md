# Special Directories
Side Notes for: [[1 - Unix]]
## `/bin`
Binaries that are **essential** to the OS.

Things like `vim` and `ls` are contained here and are called upon when you use them.

## `/sbin`
Stores System binaries for the super user.

## `/libs`
Libraries: Shared code between binaries.

## `/usr`
-  `/usr/bin` - User installed binaries non-essential to the OS/System
-  `/usr/local/bin` - Binaries that are locally compiled but can be ran from anywhere

## Command `which` & `$PATH`
All binaries are mapped with a `$PATH$` var that allows Unix to call them from anywhere.

```unix
which [BINARY_NAME]
```
This will tell you where the *binary* lives
## `/home/[USER_NAME]`
A directory to hold the data per user.

## OS FILES
- `/BOOT` - Boot files
- `/DEV` - interface with hardware by treating drives as files
- `/VAR` - contains files that contain variables that change while the OS is in use. 
- `/TMP` - Stores files that wont persist on reboot