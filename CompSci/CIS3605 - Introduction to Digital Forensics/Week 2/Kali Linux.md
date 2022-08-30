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

## Kali Linux Structure

![kali_rings](/img/kali_rings.png)

The Kernel separates the core of the OS from the user space with rings. The kernel will manage hardware, processes, users, fs and etc. 

In linux, software is distributed as packages and installed via package management system (`agt-get`\*). The `agt-get` will fetch versions of a software and install/update them if needed. Note, update command will sync the installed package to the remote repo of the package.

\* - Advanced Packaging Tool - one of the package management systems.

Meta-Package: "Package of Packages", Our Kali installation has many meta packages. 

### File Systems
The way the the data is stored on the physical media. Common linux defaults are Ext2, Ext3, and Ext4.

![linux_fs_1](/img/linux_fs_1.png)

### Processes
```unix
ps aux - shows running processes
```

### Rights and Permissions

**User Categories**:
1. Owner - 'u'
2. Group - 'g'
3. Others - 'o'

**Permissions**:
1. Reading 'r'
2. Writing 'w'
3. Executing 'x'

```
Chown [filename] - changes ownership
Chgrp [filename] - changes group
Chmod [filename] - changes permissions listed above
```

## Commands Practice
### ping
ICMP - Internet Control Message Protocol
Command  - `ping`

```
ping [ip] [bytes-len]
```

When we ping another computer it sends an ICMP packet. 

![ICMP-packet-structure.png](/img/ICMP-packet-structure.png)

We can determine the type of an ICMP Packet via its `Type & Code`.

### nslookup
Gives the IP of a host but can also determine the IP of a domain along with other website data like certs and ownership. If you call `nslookup` with no params the command is ran in interactive mode. 

### whois
Runs a search in the `whois database` to determine ownership. 

### nmap
+ FInd live host on network
+ Scan ports
+ Ping Sweeps
+ OS + Version Detection

This is a security concern.

### Telnet
Accessing remote computers via TCP. SSH is a more secure version of telnet. You can telnet to a computer via a viable IP.

### curl ('see' url)
Displays some stats about a url. We can use special syntax to see multiple variations of a url.  

### wget
You can download files via `wget` by knowing their PDF. This can be a security flaw in a network as well. 