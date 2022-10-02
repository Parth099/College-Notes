# Activity Imaging, Wipe, and Hash
| Command | HASH-ALGO |
| ------- | --------- |
| `dc3dd` | `sha-256` | 

## Install
```bash session
sudo apt install dc3dd
```

## Workspace Generation:
```bash session
parth@parth-HP-Laptop-15-dy1xxx:~/Desktop/3605-wipe-hash$ ls
'Hard Drive B.001'

parth@parth-HP-Laptop-15-dy1xxx:~/Desktop/3605-wipe-hash$ du -h Hard\ Drive\ B.001 
505M	'Hard Drive B.001'

parth@parth-HP-Laptop-15-dy1xxx:~/Desktop/3605-wipe-hash$ mkdir ../3605-wipe-hash-out
```

1. Create workspace and a file (was used for a prev homework)
2. display size of said file
3. generate output folder to store dc3dd output(s)

### Mount
```bash session
parth@parth-HP-Laptop-15-dy1xxx:~$ sudo mount -o loop /home/parth/Desktop/3605-wipe-hash/Hard\ Drive\ B.001 /mnt/DRIVE-B_3605/
```

To image something it is requred to be mounted onto the system, this means we make the file accessable using the current filesystem as an **entry point**. It is like a mapping from our fs to the mounted image's fs.  

## Splitting Data
```bash session
parth@parth-HP-Laptop-15-dy1xxx:~$ sudo dc3dd if=/dev/loop6 hofs=/home/parth/Desktop/3605-wipe-hash-out/IMAGE.img.000 ofsz=67108864 hash=sha256 hlog=/home/parth/Desktop/3605-wipe-hash-out/hashlog.log

dc3dd 7.2.646 started at 2022-10-01 15:56:42 -0400
compiled options:
command line: dc3dd if=/dev/loop6 hofs=/home/parth/Desktop/3605-wipe-hash-out/IMAGE.img.000 ofsz=67108864 hash=sha256 hlog=/home/parth/Desktop/3605-wipe-hash-out/hashlog.log
device size: 1033216 sectors (probed),      529,006,592 bytes
sector size: 512 bytes (probed)
   529006592 bytes ( 504 M ) copied ( 100% ),   10 s, 50 M/s                  
   529006592 bytes ( 504 M ) hashed ( 100% ),    5 s, 105 M/s                 

input results for device `/dev/loop6':
   1033216 sectors in
   0 bad sectors replaced by zeros
   58ddc5466dc26c89d53c61365f0dde5dabae2bf36a698eac5c2e4ce91d51cb27 (sha256)
      92c1a1bbdd0306eba45d826d6762bf32676e89f5905dfa5edf9dcd66432688c1, sectors 0 - 131071
      ca576bb4b6b899a637720120e708a79748632d8d1bc66e702e4a5104c0469054, sectors 131072 - 262143
      17c6393384f78802f58323f8431901f33f6b1e3ac182f20c1a156ea5aef834a2, sectors 262144 - 393215
      e3931a7d8cb2d4d756782e172a578cedb8dcc6952752d85f7e44826e4c0036e9, sectors 393216 - 524287
      b8b7b0edb1386146f746c16199c83e92e841022b6cc9760954994eac9b3e35fc, sectors 524288 - 655359
      e8a4930f7a752fa062110c2ffa22eb0d251a0fccb2cfd058246ac74bb290e93f, sectors 655360 - 786431
      f09bf36b0b715a653a1e2b9352d85c0bc2ec1bab51d7c0f8a100200e099715d2, sectors 786432 - 917503
      5a62fcb3fdb7212e81953e6e54f33d5933a31138f760dce5666703be8218032b, sectors 917504 - 1033215

output results for files `/home/parth/Desktop/3605-wipe-hash-out/IMAGE.img.000':
   1033216 sectors out
   [ok] 58ddc5466dc26c89d53c61365f0dde5dabae2bf36a698eac5c2e4ce91d51cb27 (sha256)
      [ok] 92c1a1bbdd0306eba45d826d6762bf32676e89f5905dfa5edf9dcd66432688c1, sectors 0 - 131071, `/home/parth/Desktop/3605-wipe-hash-out/IMAGE.img.000'
      [ok] ca576bb4b6b899a637720120e708a79748632d8d1bc66e702e4a5104c0469054, sectors 131072 - 262143, `/home/parth/Desktop/3605-wipe-hash-out/IMAGE.img.001'
      [ok] 17c6393384f78802f58323f8431901f33f6b1e3ac182f20c1a156ea5aef834a2, sectors 262144 - 393215, `/home/parth/Desktop/3605-wipe-hash-out/IMAGE.img.002'
      [ok] e3931a7d8cb2d4d756782e172a578cedb8dcc6952752d85f7e44826e4c0036e9, sectors 393216 - 524287, `/home/parth/Desktop/3605-wipe-hash-out/IMAGE.img.003'
      [ok] b8b7b0edb1386146f746c16199c83e92e841022b6cc9760954994eac9b3e35fc, sectors 524288 - 655359, `/home/parth/Desktop/3605-wipe-hash-out/IMAGE.img.004'
      [ok] e8a4930f7a752fa062110c2ffa22eb0d251a0fccb2cfd058246ac74bb290e93f, sectors 655360 - 786431, `/home/parth/Desktop/3605-wipe-hash-out/IMAGE.img.005'
      [ok] f09bf36b0b715a653a1e2b9352d85c0bc2ec1bab51d7c0f8a100200e099715d2, sectors 786432 - 917503, `/home/parth/Desktop/3605-wipe-hash-out/IMAGE.img.006'
      [ok] 5a62fcb3fdb7212e81953e6e54f33d5933a31138f760dce5666703be8218032b, sectors 917504 - 1033215, `/home/parth/Desktop/3605-wipe-hash-out/IMAGE.img.007'

dc3dd completed at 2022-10-01 15:56:53 -0400

```

Options:
1. `hofs=/home/parth/Desktop/3605-wipe-hash-out/IMAGE.img.000`
	+	Represents the numbering scheme for the output files, **h**ofs represnts hashing
2. `ofsz=67108864`
	+	Split the orginal image into $64$ MB chunks.
3. `hash=sha256`
	+	hash algorithm: $\text{SHA 256}$
4. `hlog`
	+	saves hash data to our file at the path supplied

### `dc3dd` Output
```bash session
parth@parth-HP-Laptop-15-dy1xxx:~/Desktop/3605-wipe-hash-out$ ls -l

total 516612
-rw-rw-r-- 1 parth parth     3364 Oct  1 15:56 hashlog.log
-rw-r--r-- 1 root  root  67108864 Oct  1 15:56 IMAGE.img.000
-rw-r--r-- 1 root  root  67108864 Oct  1 15:56 IMAGE.img.001
-rw-r--r-- 1 root  root  67108864 Oct  1 15:56 IMAGE.img.002
-rw-r--r-- 1 root  root  67108864 Oct  1 15:56 IMAGE.img.003
-rw-r--r-- 1 root  root  67108864 Oct  1 15:56 IMAGE.img.004
-rw-r--r-- 1 root  root  67108864 Oct  1 15:56 IMAGE.img.005
-rw-r--r-- 1 root  root  67108864 Oct  1 15:56 IMAGE.img.006
-rw-r--r-- 1 root  root  59244544 Oct  1 15:56 IMAGE.img.007
```

## Validation
Used the `sha256sum` command to regenerate the *hash* of each file.

```bash session
parth@parth-HP-Laptop-15-dy1xxx:~$ sha256sum /home/parth/Desktop/3605-wipe-hash-out/IMAGE.img.*
92c1a1bbdd0306eba45d826d6762bf32676e89f5905dfa5edf9dcd66432688c1  /home/parth/Desktop/3605-wipe-hash-out/IMAGE.img.000
ca576bb4b6b899a637720120e708a79748632d8d1bc66e702e4a5104c0469054  /home/parth/Desktop/3605-wipe-hash-out/IMAGE.img.001
17c6393384f78802f58323f8431901f33f6b1e3ac182f20c1a156ea5aef834a2  /home/parth/Desktop/3605-wipe-hash-out/IMAGE.img.002
e3931a7d8cb2d4d756782e172a578cedb8dcc6952752d85f7e44826e4c0036e9  /home/parth/Desktop/3605-wipe-hash-out/IMAGE.img.003
b8b7b0edb1386146f746c16199c83e92e841022b6cc9760954994eac9b3e35fc  /home/parth/Desktop/3605-wipe-hash-out/IMAGE.img.004
e8a4930f7a752fa062110c2ffa22eb0d251a0fccb2cfd058246ac74bb290e93f  /home/parth/Desktop/3605-wipe-hash-out/IMAGE.img.005
f09bf36b0b715a653a1e2b9352d85c0bc2ec1bab51d7c0f8a100200e099715d2  /home/parth/Desktop/3605-wipe-hash-out/IMAGE.img.006
5a62fcb3fdb7212e81953e6e54f33d5933a31138f760dce5666703be8218032b  /home/parth/Desktop/3605-wipe-hash-out/IMAGE.img.007
```

Indeed they are the same. It is easy to tell since a small change in the input will cause a large change in the output hash. 