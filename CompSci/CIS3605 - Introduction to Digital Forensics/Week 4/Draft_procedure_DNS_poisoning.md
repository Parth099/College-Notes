# DNS Poisoning
## A brief description
DNS Poisoning is when a threat actor exploits vulnerabilities in the DNS protocol and uses it to route users to a website *they* control. With this they can perform DDoS attacks by not allowing customers or companies to access  websites they need to get to. Moreover they can perform a man-in-the-middle attack where they can mock a website's likeness and steal information from unknowing users. 

For example someone can poison an DNS server to route all urls of a banking app to a URL a they **control**. Since both websites look the same an unknowing victim will input their user information and they information will be stolen. 

The reason this is possible is because DNS is **insecure**, it utilizes UDP which has no error correction nor any proof of ownership. 

## Incident Trigger 
Here are some incidents related to *DNS Poisoning*:
1. Same site on different networks looks different or is up/down
2. Much like phishing the man-in-the-middle site may not look well polished
3. url changes when the site is loaded

##  Triage
If a falsified site is reported an investigator can look over the certificate of the website. If non is present then it is clear evidence of some tempering. An expert can also view the DNS cache of the *infected* computer and see if the DNS records are legitimate. An initial analysis can be completed with the `whois` command on the suspicious DNS record's IP.  

Moreover an investigator can check if this was an *isolated* incident by cleaning internal DNS caches 

## Detection 
The first step in detection is finding illegitimate DNS records. This means that one of the chains the DNS resolution process is infected. If a company owns their DNS servers they can check records to see if there are any records they did not place. If they do not they can see if the owner of the nameserver can help with the task. 

Detection can also be achieved via monitoring the server.  
## Location of evidence
1. Caches of infected computers
2. Packet capture of a DNS request 
	+ This can show if an attacker is responding to DNS queries to impersonate DNS queries
3. False records in the server records
4. Records of an influx of DNS queries and replies
	+ May be an attempt of taking over a DNS server	
## Tools & Commands
> The commands are windows based
### `ipconfig /displaydns`
This will display the current DNS cache of the machine which can be used to locate falsified retrieved records. Per DNS record a TTL will be shown will may help with an investigation. 

### `whois`
Displays the ownership of a URL. If there are redirects this can be used to rule out false positives.

### `nslookup`
This command is the trivial case to check for a DNS poisoning attack.

## Mitigation
According to [mitre](http://attack.mitre.org/techniques/T1584/002/) there is no mitigation since a lot of companies do not have **full** access to their DNS servers. Potential mitigation is owning your own DNS server to perform regular authenticity checks.

## Eradication
Subsequent to a poisoning attack an company could repopulate their DNS records whilst removing any false records. Each machine owned by the company will need to have their DNS cache emptied to no longer used to the cached record for the site they were trying to access. 