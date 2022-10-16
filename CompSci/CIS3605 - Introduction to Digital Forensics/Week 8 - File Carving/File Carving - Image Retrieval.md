# File Carving - Image Retrieval
## Installation 
```bash
sudo apt install scalpel
```

I can confirm it was installed successfully by checking if the `scalpel.conf` exists.

```bash
parth@parth-HP-Laptop-15-dy1xxx:~$ ls /etc/scalpel/
scalpel.conf
```

## Selecting File Types
First I unlocked the file, it was read only so I changed the permissions via `chmod`:
```bash
parth@parth-HP-Laptop-15-dy1xxx:/etc/scalpel$ sudo chmod u=rwx,g=rwx,o=rwx ./scalpel.conf 
```

This command is the same as using `chmod 777 [filename]` but more readable. 

### Trial 1 - Images
I started with images and uncommented the following lines
```text
	jpg	y	5242880		\xff\xd8\xff???Exif		\xff\xd9	REVERSE
	jpg	y	5242880		\xff\xd8\xff???JFIF		\xff\xd9	REVERSE
	
  	png	y	20000000	\x50\x4e\x47?	\xff\xfc\xfd\xfe
```

Then ran scalpel on `StolenInformation.001` with this **edited** configuration file. 

```bash
parth@parth-HP-Laptop-15-dy1xxx:~/Desktop$ scalpel -c /etc/scalpel/scalpel.conf -o ./SI-out/images ./SI-in/StolenInformation.001 
Scalpel version 1.60
Written by Golden G. Richard III, based on Foremost 0.69.

Opening target "/home/parth/Desktop/SI-in/StolenInformation.001"

Image file pass 1/2.
./SI-in/StolenInformation.001: 100.0% |********************************************************************************************************************************************|  501.5 MB    00:00 ETAAllocating work queues...
Work queues allocation complete. Building carve lists...
Carve lists built.  Workload:
jpg with header "\xff\xd8\xff\x3f\x3f\x3f\x45\x78\x69\x66" and footer "\xff\xd9" --> 0 files
jpg with header "\xff\xd8\xff\x3f\x3f\x3f\x4a\x46\x49\x46" and footer "\xff\xd9" --> 37 files
png with header "\x50\x4e\x47\x3f" and footer "\xff\xfc\xfd\xfe" --> 0 files
Carving files from image.
Image file pass 2/2.
./SI-in/StolenInformation.001: 100.0% |********************************************************************************************************************************************|  501.5 MB    00:00 ETAProcessing of image file complete. Cleaning up...
Done.
Scalpel is done, files carved = 37, elapsed = 4 seconds.
```

While `jpg` yielded $37$ results which were outputted to a folder to be saved `png` files were not found.

### Trial 2 - Docs
```bash
parth@parth-HP-Laptop-15-dy1xxx:~/Desktop$ scalpel -c /etc/scalpel/scalpel.conf -o ./SI-out/docs/ ./SI-in/StolenInformation.001 
Scalpel version 1.60
Written by Golden G. Richard III, based on Foremost 0.69.

Opening target "/home/parth/Desktop/SI-in/StolenInformation.001"

Image file pass 1/2.
./SI-in/StolenInformation.001: 100.0% |********************************************************************************************************************************************|  501.5 MB    00:00 ETAAllocating work queues...
Work queues allocation complete. Building carve lists...
Carve lists built.  Workload:
doc with header "\xd0\xcf\x11\xe0\xa1\xb1\x1a\xe1\x00\x00" and footer "\xd0\xcf\x11\xe0\xa1\xb1\x1a\xe1\x00\x00" --> 8 files
doc with header "\xd0\xcf\x11\xe0\xa1\xb1" and footer "" --> 8 files
pst with header "\x21\x42\x4e\xa5\x6f\xb5\xa6" and footer "" --> 0 files
ost with header "\x21\x42\x44\x4e" and footer "" --> 0 files
dbx with header "\xcf\xad\x12\xfe\xc5\xfd\x74\x6f" and footer "" --> 0 files
idx with header "\x4a\x4d\x46\x39" and footer "" --> 0 files
mbx with header "\x4a\x4d\x46\x36" and footer "" --> 0 files
htm with header "\x3c\x68\x74\x6d\x6c" and footer "\x3c\x2f\x68\x74\x6d\x6c\x3e" --> 1 files
pdf with header "\x25\x50\x44\x46" and footer "\x25\x45\x4f\x46\x0d" --> 7 files
pdf with header "\x25\x50\x44\x46" and footer "\x25\x45\x4f\x46\x0a" --> 4 files
Carving files from image.
Image file pass 2/2.
./SI-in/StolenInformation.001: 100.0% |********************************************************************************************************************************************|  501.5 MB    00:00 ETAProcessing of image file complete. Cleaning up...
Done.
Scalpel is done, files carved = 28, elapsed = 5 seconds.
```

Scalpel was able to find:
+ $11$ PDF files
+ $1$ HTML File
+ $16$ MS-Word docs

The lines I uncommented can be found by looking at the "magic numbers" that the tool ran with. There were 10 headers I selected scalpel should look for. 

### Trial 3 - Video and Sound
```bash
parth@parth-HP-Laptop-15-dy1xxx:~/Desktop$ scalpel -c /etc/scalpel/scalpel.conf -o ./SI-out/audio-video/ ./SI-in/StolenInformation.001 
Scalpel version 1.60
Written by Golden G. Richard III, based on Foremost 0.69.

Opening target "/home/parth/Desktop/SI-in/StolenInformation.001"

Image file pass 1/2.
./SI-in/StolenInformation.001: 100.0% |********************************************************************************************************************************************|  501.5 MB    00:00 ETAAllocating work queues...
Work queues allocation complete. Building carve lists...
Carve lists built.  Workload:
avi with header "\x52\x49\x46\x46\x3f\x3f\x3f\x3f\x41\x56\x49" and footer "" --> 0 files
mov with header "\x3f\x3f\x3f\x3f\x6d\x6f\x6f\x76" and footer "" --> 0 files
mov with header "\x3f\x3f\x3f\x3f\x6d\x64\x61\x74" and footer "" --> 0 files
mov with header "\x3f\x3f\x3f\x3f\x77\x69\x64\x65\x76" and footer "" --> 0 files
mov with header "\x3f\x3f\x3f\x3f\x69\x64\x73\x63" and footer "" --> 0 files
mov with header "\x3f\x3f\x3f\x3f\x70\x63\x6b\x67" and footer "" --> 0 files
mpg with header "\x00\x00\x01\xba" and footer "\x00\x00\x01\xb9" --> 0 files
mpg with header "\x00\x00\x01\xb3" and footer "\x00\x00\x01\xb7" --> 0 files
fws with header "\x46\x57\x53" and footer "" --> 22 files
wav with header "\x52\x49\x46\x46\x3f\x3f\x3f\x3f\x57\x41\x56\x45" and footer "" --> 0 files
ra with header "\x2e\x72\x61\xfd" and footer "" --> 0 files
ra with header "\x2e\x52\x4d\x46" and footer "" --> 0 files
Carving files from image.
Image file pass 2/2.
./SI-in/StolenInformation.001: 100.0% |********************************************************************************************************************************************|  501.5 MB    00:00 ETAProcessing of image file complete. Cleaning up...
Done.
Scalpel is done, files carved = 22, elapsed = 7 seconds.
```

There were $22$ files relating to audio/video. All 22 were of type `fws` (Macromedia Flash).

## Results
Each of the extracted types (except `fws`) was able to be checked. I found that the tool correctly identified relevant files. 

### 4 Magic Numbers

| File Extension | Magic Number(*s*) - Header Information              | 
| -------------- | --------------------------------------------------- |
| `.doc`         | $\text{D0 CF 11 E0 A1 B1 1A E1, D0 CF 11 E0 A1 B1}$ |
| `.pdf`[^1]     | $\text{25 50 44 46}$                                |
| `jpg`[^2]      | $\text{FF D8 FF 3F 3F 3F 4A 46 49 46}$              |
| `.fws`         | $\text{46 57 53}$                                   |


[^1]: Footer (trailer) varies, this is why it has more than one entry. Also, If we convert hex to text: $\text{25 50 44 46}$ is `% P D F`
[^2]: This is just *one* signature. Other signatures did not produce any results. 
