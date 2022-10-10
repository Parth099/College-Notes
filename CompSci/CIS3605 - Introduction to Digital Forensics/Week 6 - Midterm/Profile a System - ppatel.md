# Profile a System Activity
## System Information Commands
### `uname` - Shows system information with options
```bash
parth@parth-HP-Laptop-15-dy1xxx:~$ uname
Linux
parth@parth-HP-Laptop-15-dy1xxx:~$ uname -v
#49~20.04.1-Ubuntu SMP Thu Aug 4 19:15:44 UTC 2022
parth@parth-HP-Laptop-15-dy1xxx:~$ uname -p
x86_64
parth@parth-HP-Laptop-15-dy1xxx:~$ uname -m
x86_64
parth@parth-HP-Laptop-15-dy1xxx:~$ uname -o
GNU/Linux
```

In order the commands represent:
1. Kernel version (-v)
2. Processor Information (-p)
3. Machine Type (-p)
4. OS Type (-p)

### `lshw` (list hardware)
```bash
parth@parth-HP-Laptop-15-dy1xxx:~$ sudo lshw -short
H/W path           Device          Class          Description
=============================================================
                                   system         HP Laptop 15-dy1xxx (7WR56UA#A
/0                                 bus            86C9
/0/0                               memory         64KiB BIOS
/0/12                              memory         8GiB System Memory
/0/12/0                            memory         8GiB SODIMM DDR4 Synchronous 2
/0/12/1                            memory         SODIMM [empty]
/0/1e                              memory         192KiB L1 cache
/0/1f                              memory         128KiB L1 cache
/0/20                              memory         2MiB L2 cache
/0/21                              memory         8MiB L3 cache
/0/22                              processor      Intel(R) Core(TM) i7-1065G7 CP
/0/100                             bridge         Intel Corporation
/0/100/2           /dev/fb0        display        Iris Plus Graphics G7
/0/100/4                           generic        Intel Corporation
/0/100/14                          bus            Ice Lake-LP USB 3.1 xHCI 
...
...
/0/8/0.0.0/1       /dev/sda1       volume         292GiB EXT4 volume
/0/8/0.0.0/2       /dev/sda2       volume         638GiB HPFS/NTFS partition
/1                                 power          HT03041XL
```

I have used `-short` to ensure this prints in a tabular format. Note `sudo` is required since this *may* be sensitive information. 

## Computer Identification
```bash
parth@parth-HP-Laptop-15-dy1xxx:~$ cat /etc/machine-id
b2401757e07b4b9f85576712b8164b00
```

> `/etc`: Contains system-wide configuration files and system databases.

Alternatively can also be identified by its unique network cards:
```bash
parth@parth-HP-Laptop-15-dy1xxx:~$ ifconfig -a | grep ether
        ether 02:42:2f:88:28:97  txqueuelen 0  (Ethernet)
        ether e8:6f:38:be:0f:4b  txqueuelen 1000  (Ethernet)
```

Used `grep | ether` so I would not have to past entire output. 

## Identify the File System's metadata
### `fs` - Type
```bash
parth@parth-HP-Laptop-15-dy1xxx:~$ blkid
/dev/sda1: UUID="c795c146-17fa-40ce-a4a2-4d4692de6b9e" TYPE="ext4" PARTUUID="b8f994f1-01"
```

`blkid` is used to display block device attributes in a `"key"="value"` format.

### Sector Sizing and Drives
```bash
Disk /dev/nvme0n1: 238.49 GiB, 256060514304 bytes, 500118192 sectors
Disk model: WDC PC SN520 SDAPNUW-256G-1006          
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes
Disklabel type: gpt
Disk identifier: 08E5FD2F-DC1D-4C98-95E9-BD3CE94B8494

Device          Start       End   Sectors   Size Type
/dev/nvme0n1p1   2048    534527    532480   260M EFI System
/dev/nvme0n1p2 534528    567295     32768    16M Microsoft reserved
/dev/nvme0n1p3 567296 500115455 499548160 238.2G Microsoft basic data


Disk /dev/sda: 931.53 GiB, 1000204886016 bytes, 1953525168 sectors
Disk model: PSSD T7         
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 33553920 bytes
Disklabel type: dos
Disk identifier: 0xb8f994f1
```

It seems that both of the drives I use are of sector size $512$ bytes.

### File Permissions
```bash
parth@parth-HP-Laptop-15-dy1xxx:~/Desktop/College-Notes/CompSci/CIS3605 - Introduction to Digital Forensics/Week 6 - Midterm$ ls -l
-rwxrw--w- 1 parth parth 4479 Oct  8 14:28 'Profile a System - ppatel.md'
```

This current file has the following permissions by group:

| Permission, Group | Users | Group | Others |
| ----------------- | ----- | ----- | ------ |
| Read              | Yes   | Yes   | Yes    |
| Write             | Yes   | Yes   | No     |
| Execute           | Yes   | No    | No     |

### Timestamps

![Timestamps](/img/Timestamps.png)

### Logging
The OS I am on **does** have logging system at:
```bash
/var/log/...
```

The log contained at `/var/log/syslog` outputs kernel data such as thread management and messaging. 

It can be viewed with:
```bash
sudo cat /var/log/syslog
```

There are also application level logs contained here such as `mongodb` logs and login attempt logs which are **not** human readable.

## System Profile
### Generating a system profile
I have done this assignment in a way where **minimal** GUI interaction is required. This is done to show that the process for generating a system profile can be automated (I assume it is this way in industry anyway).

A simple `python` or `c` script can execute commands and write them to a file. The python script and utilize the `os` module while the `c` procedure can use the `system()` call to execute commands and open a file descriptor to write results.  

### Data to include include in the chain of custody
The chain of custody should logically contain elements that **uniquely** identity a machine. Here are some of these elements:
1. Operating System, Kernel Version, and the processor architecture (`32bit` vs `64bit`)
2. CPU data
	+ Cache Sizes
	+ Clock Speed
	+ CPU Name and manufacturer 
3. System Data
	+ Ram Size
	+ Drive data: Connected Drives (this information should be hashed like how it is on the real Chain of custody document)
	+ file system type (HFS, FAT, exFAT, ...)
4. Machine Identifiers
	+ Machine Unique ID/Name
	+ Disk identifiers
	+ Mac Addresses of *all* network adapters

These attributes can help us distinguish between devices generally and therefore can help us *sort* and *distinguish* between related evidence items. 