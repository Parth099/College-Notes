# Viruses, Threats, and Attacks
## Viruses

Virus: Any code that is created with the intention of causing harm. 

How it causes harm will define how it crosses the CIA(**Confidentiality, Integrity, and Availability**) triad. 

Threats: The possibility a system is vulnerable to a attack
Attack/exploit: the execution of a threat to a target

An advanced persistent threat (APT) is a broad term used to describe an attack campaign in which an intruder, or team of intruders, establishes an illicit, long-term presence on a network in order to mine highly - [imperva](https://www.imperva.com/learn/application-security/apt-advanced-persistent-threat/).

### CIA Triad

How a virus behaves is defined by the CIA pillars listed below. For example a DDoS attack opposes the *Availability* aspect. 

+ C - Confidentiality
+ I - Integrity
+ A - Availability

### Cyber Kill Chain - Attack Life Cycle
- defines the pre and post exploit steps an adversary must conduct to reach the objective

![Cyber_Kill_Chain_lockheed](/img/Cyber_Kill_Chain_lockheed.png)

- Recon
	- Information about potential targets
	- learn about types of attacks (attack vectors)
- Weaponize 
	- how can I use the information i know about company X to attack it
- Delivery
	- How will i deliver the weapon
- Exploit
	- When the code is run the attack gets access
- Install
	- When the adversary makes the access gained with the exploit permanent 

## Mitre Framework - Free
- non profit ORG

Knowledge base of adversarial attacks based on industry. When this framework you can learn about behaviors that may compromise networks. 

Matrix - [link](http://attack.mitre.org/#)

## Injection Attacks
+ Injections:
	+ Example: Using a valid form field to attempt to send code to be executed
+ Cross Side Scripting
	+ exploits web server response by injecting JS to the webpage 

## Password Attacks
+ Brute Force
+ Rainbow Tables
	+ collection of commonly used passwords with hash values
+ Birthday Attacks
	+ Frequency of hash collisions
+ Cryptanalysis Attacks
	+ finding weakness in encryption methods

## Attacks
+ ransomware
+ malware

## eMail Attacks
- Phishing
- Spoofing - manipulation of email headers
- Bombing - send excessive amounts of emails 

# Phishing TRIAGE Draft 9/12/22 
1. Who was targeted (recon)
2. What was the object used to inject (weapon)
3. Delivery was email (given)
4. Who clicked on the email (exploit )
	1. lets us know who was hit and allows us to know if any accounts with privilage were hit
5. Was there any installs or any events after clicking the image/link
6. Were any settings changed/user accounts breach (command and control)
7. What do *you* think was taken?