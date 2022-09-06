# Commands
## `Ping`
```
ping www.temple.edu
```

Displays network information like RTT, IP, Packet Loss% and etc. Also used to determine if a machine is up or test security. We can change things like the packet length and count used options provided by [ping](https://linux.die.net/man/8/ping).

## `whois`
```
whois [IP or domain]
```

Gives us information about ownership of a Domain/IP. It will query the `whois` database.

## `nslookup`
```
nslookup [-options] [name | -] [server] 
```

`nslookup` does have difference between Windows and Linux. It performs DNS queries. It can be used to fetch DNS replies from requesting a IP/Domain. 