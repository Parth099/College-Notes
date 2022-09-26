# Lectures Part 1
## Network Forensics Part 1
**SSL/TLS Handshake**
1 - Handshake Protocol
2 - Record Protocol

## OSI Layers
Layers 1 - 4 manage communication controls e.g. error checking while layers 5 - 7 manage auth, encryption and making data human readable. 

## Ports
Logical assignment by the OS that serves as a communication endpoint.

### FTP
+ TCP with ports 20/21
+ provides the ability to relocate files over different computers
+ Can be secured with TLS/SSL on port 989/990

### SSH
+ Secure remote connection protocol
+ Port 22
+ secure alternative to telnet

### DHCP
+ Assigns IP addresses on port 67/68

### TFTP - Trivial FTP
+ Uses UDP and not TCP like FTP on Port 69

### POP - Post Office Protocol
+ A mail server protocol
	+ Simple Protocol:
		+ retrieve emails and delete them from Mail servers
+ TCP/110

### NTP
+ UDP/123
+ Sync Time

### NETBIOS
+ TCP/UDP
+ Ports 137-9
+ Used to connect windows machines

### IMAP3 - Internet Message Access Protocol v3
+ retrieve emails from server
	+ unlike POP it allows many operations
+ TCP/143

### SNMP - Simple Network Management Protocol
+ See name
+ TCP/UDP
+ 161/162
+ Can configure TRAPS to indicate sensitive actions on the network.

## Windows Register
Contains:
+ Time zone
+ Computer Name
+ File Systems
+ Wireless/Wired Network 
+ Local IP info
+ Network Shares and Offline Caching

