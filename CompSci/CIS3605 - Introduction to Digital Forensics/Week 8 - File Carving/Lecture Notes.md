# File Carving

Data carving is the process of extracting data from a larger set of data. File carving is part of file **recovery**. The file is recovered from the slack space and since the file is not *allocated*, it has no entry in the master-boot table. 

Review a tool called `scalpel`, a cmdline file indexer and carver.

## Master File Table
The MFT stores data about file data such as metadata. Files that are not deleted or fragmented show up here. 

## File Types
Use the command below to get more information on files
```bash
file -i [filename]
```

### Signatures
Located at the head of the file, it is used by the OS and Antivirus that determine what type of file it is. While someone can alter the file extension or the head, the file will not be able to be opened.

> ***Important***: Changing the ext of a file does **not** change the signature.

### Footer
A footer marks the end of a file (`EOF`). This can be done with various sequences. 