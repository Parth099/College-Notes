# Chapter 2 - Key technical concepts

## Binary to Text

| Encoding | Supported Chars            |
| -------- | -------------------------- |
| ASCII    | 128, but only 94 printable |
| UNICODE  | 1000s                      |

Knowledge of the encoding type is important for removing files that have been deleted. We scan the disk free space to extract file headers and footers (if possible) and then copy over the file to analyze. 

While *file-extensions*help to determine the file type the file header is better to look at. 

## COMPUTING ENVIRONMENTS

1. Stand alone
	+ Easiest to investigate
2. Networked
	+ Harder to investigate as data can be found on *other* computers
3. Mainframe
	+ A mainframe centralizes all of the computing power into one location. All components are found in one location. 

### CLOUD COMPUTING

POV: You are the business are you need to outsource computing 

1. IaaS - Infrastructure as a Service (outsources hardware)
2. PaaS - Platform as a Service (outsources dev environment)
3. SaaS - Software as a service (outsources the building of the application)

Cloud Computing has increased the challenge of Digital Forensics. Recall that cloud computing has no bounds. A machine can be located in another city of another country. 

## Data Types

| Type of Data  | Description                                                                      |
| ------------- | -------------------------------------------------------------------------------- |
| Active Data   | Data we can see and the OS tracks. These files are viewable on the file explorer |
| Latent Data   | Partially deleted or overwritten files.                                                  |
| Archival Data | Backups are an example of this.                                                                                 |

## File Systems
Many different systems exist:
+	FAT
+	NFTS
+	HFPS+

**FS** - File System

| FS                              | Description                                                                                |
| ------------------------------- | ------------------------------------------------------------------------------------------ |
| FAT - File Allocation Table     | Oldest FS. Comes in flavors like FAT12, FAT16, FAT32 and etc. It is not used in modern OSs |
| NFTS - New Technology FS        | Newer and more capable/compatible than FAT.                                                |
| HFS+ (Hierarchical File System) | Used in Apple products                                                                     |

**Allocation** - If a *space* is being used or not.

### Data Persistence
The FS works like an index. Deleting a file is like removing its index but not actually deleting the index. A file may also be fragmented. 

## How magnetic hard drives store (HDD) data
Computers store data in sectors, the smallest container possible on a drive. Then a cluster is makeup of several sectors. Computers will save data in terms of clusters. If a file goes over the cluster limit it will write to the next cluster. 

### Possible Recovery Method
```text
paramaters:
	sector  size: 512 bytes
	cluster size: 4 sectors
```

Consider a file $E$ that has been saved. It is $2304$ bytes. This means it takes up **2** clusters. Say this is saved in clusters 10 and 11. Say we delete this file and download $F$ which is $768$ bytes. OS sees that cluster 10 is marked as empty and writes $F$ there. The first and second sectors are set to the bits of $F$ while the last 2 sectors still contain partial $E$. These can be recovered. The remaining unzeroed\* space is called `slack space`. 

\* - When a new file is placed in a sector, the remaining free **sector space** has all of its bits set to *0*. This **does not** apply to a cluster. Only relevant portions of a sector are zeroed.  