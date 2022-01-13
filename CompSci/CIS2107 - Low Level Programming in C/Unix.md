# What is Unix?
Unix is an OS, sits between the hardware and user/apps. It provides high-level abstractions and services.  

Most of the server (70%) are Unix because its based on C (*fast*). 

Unix & Linux isn't the same. Linux's code base is different. Simply put, Unix is a CMD while Linux is a GUI based OS.

## Layers of a Unix System
![[layers.png]]

The shell gives a *user* & *apps* connections to the software/hardware. System calls are more advanced and are part of CIS3207.

## The File System
Unix has Files & directories (folder-like)
At the top there is only 1 folder: **root** (think tree)

*Bonus Question*: What is the difference between windows folders & Unix directories? #bonus

Note in a file path the *initial slash* "/" represents the root
Ex: **/** home/Desktop/cis2107

A path can refer to a directory or folder.
A file is a sequence of bytes.

Note: A directory **is** itself a file. 
*Everything* is a File in Unix. See (Chap 2.12)

They are accessed in a uniform way: 
- Consistent API : (read, write, open, close ...)
- consistent naming. 

File Absolute Path: File Path starting from the root ("/")
File Relative Path: path from the working directory
Ex : "./fileA/FileB" or "../FileC/FileD" or "../../FILE.css"

There is a short hand for home, each user has a home directory. You can shorthand this with *~*.


## Some Unix commands
### Notes
- Unix is case case-sensitive
- the prompts are displayed and run by the ***shell***. The shell is an interface between the user and Unix.
- You can create shell scripts yourself by programming them. 
- Two types of major shells
	- Bourne Shells
	- C shells

When you login in the bash shell will run and while you and logged in. 

## Shell Intro
A system program that allows a user to
- run shell functions
- other programs
- shell scripts

### Commands
```unix
% commandName [arg1] ... [argN]
```
The % is the prompt 
There are also options that are triggered by "-" or "--" (GNU Style)

_SHELL SLIDES_

The input to shell is keyboard while output is screen. These are the STDIN and STDOUT streams (see CP2.12). Both of them can be redirected from/to a file or other commends.

File redirection:
 - < input
 - > output
 - >> output append

Why is cal 9 1752 missing days?