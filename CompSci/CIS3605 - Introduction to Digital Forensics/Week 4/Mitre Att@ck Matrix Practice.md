# Mitre Att@ck Matrix Practice
| Chosen Discovery Tactic | Link                                               | Related Sub-Tactic                                                       |
| ----------------------- | -------------------------------------------------- | ------------------------------------------------------------------------ |
| Network Sniffing        | [T1040](http://attack.mitre.org/techniques/T1040/) | [Adversary-in-the-Middle](http://attack.mitre.org/techniques/T1557/001/) |

Tool employed: *Wireshark*

While I did see other tools for packet sniffing and password sniffing I was hesitant to install them since all the download links were hosted on websites with lots of ads. 

## How Network/Packet sniffing is done
Mitre says that sniffing can be done physically. An adversary can place a physical device to scan open ports and observe the network traffic through that device. Otherwise an adversary can attempt phishing to install a packet sniffer. I am not sure how successful how this tactic will be. 

### Procedure
With Wireshark the capture process is quite easy. You can start a capture and all capture will be stored in `pcap` file. Now attempting to read the packet data is a more complex process. It will help to have a tool to automate packet processing as my laptop generated 1000s of packets in the few seconds I did a capture. I did this manually and I was very hard to establish patterns and seeing which packet was with which transmission. 

## Wireshark
Wireshark is able to read packets though the network adapter so it sees any ingress/egress traffic. 

I went to `stackoverflow` and Wireshark was able to pick that up:
![WS_MAMP_3605](/img/WS_MAMP_3605.png)

It contains very detailed information about my request and what machine I an from. The packets that reside below the HTTP request (packets lower on OSI model) can reveal more information like the hardware I am on. 

The `GET` request also included *encrypted* cookie information which could also be used for discovery. 

A packet can be used for discovery to deploy a `Adversary-in-the-Middle` attack where a APT group can spend some time learning about a company's online behaviors and use those learned behaviors to create phishing campaigns. They can also commit service resolution poisoning where a URL can be rerouted to a different page. With this, an adversary can steal login information by taking on the likeness of a reputable source.  

There are also other things packet sniffing can be used for. 

For one we can map out other devices in a domain with we see an ARP (Address Resolution Protocol) request:

![ARP_MAMP_3605](/img/ARP_MAMP_3605.png)

This many not be too useful since we wont receive physical address since most organizations will be operating in a private network but it helps to know the landscape nonetheless. 

More advanced tools then Wireshark may reveal more network configurations which can help lead more successful attacks. 

> I tried to login to sites like `tuportal` and `google` and read the passwords sent over but I was unable to. It is hard to know which packet contains the credentials and even harder to break the encryption.
 


