# Kali Linux
Kali is a version of linux that contains over 600 tools related to security. Many of these tools are dangerous and may damage your system.  

> For the class I opted to install Kali in a VM inside windows 10

## File Integrity
Many sites will allow you to see if a file you downloaded is reputable. By supplying you with a hash file. You can compute the hash value of your file and compare it with the hash they provide to see if it has been tampered with. 

## Commands Practice
```unix
rahash [file path]

OUTPUT ->
Hash values for the file
```

```unix
file -s [file path]

OPTIONS ->
-s : tills the OS to read the file. It is non standard as reading something can have side effects.

OUTPUT ->
info about file @file path
```

```unix
fdisk -l

OPTIONS ->
-l : list

OUTPUT ->
info about current disk
```

```unix
dd if=[input file path] of=[output path]

ACTION ->
compies file from IF to OF bit by bit
```

```unix
mkfs [file path]

Makes a file system at said path
```