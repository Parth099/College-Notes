# Lecture on 2/17/22
## Presentations
### P1 - Lab 4 Issues
```unix
docker start -i [ID]
```
`-i` stands for interactive. We use docker start to run an image. The `ID` is required to start up the image. 

Escaping: The `[ID]` needs to only be as long as it needs to show uniqueness. 
Installing `ps`, `more` command for Fedora:
```unix 
yum install procps
yum install util-linux
```

#### chcon issues

#### Extra
See `$PATH` in bash
See Linux command paths

### P2 - Lab 4 Errors
```unix
docker exec [CONTAINER NAME] [COMMAND]
```
You can `exec` commands without having to go *into* a container. This way we can manage containers without having to create an active in-line. 

## Lecture - Virtualization

Learn Infrastructure as code.



