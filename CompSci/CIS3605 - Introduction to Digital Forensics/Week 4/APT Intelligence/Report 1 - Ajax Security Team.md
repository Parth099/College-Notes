| Link                                           | Name               | ID        |
| ---------------------------------------------- | ------------------ | --------- |
| [Link](https://attack.mitre.org/groups/G0130/) | Ajax Security Team | **G0130** |

> [Ajax Security Team](https://attack.mitre.org/groups/G0130) is a group that has been active since at least 2010 and believed to be operating out of Iran. By 2014 [Ajax Security Team](https://attack.mitre.org/groups/G0130) transitioned from website defacement operations to malware-based cyber espionage campaigns targeting the US defense industrial base and Iranian users of anti-censorship technologies. - [attack.mitre.org](https://attack.mitre.org/groups/G0130/)

## Technique Analysis
Ajax Security Team uses techniques that lure unknowing uses into committing harmful actions. 
For example they have employed:

### External Attempts 
1. Spearphishing Attachment (pretending to be a trusted entity)
2. Spearphishing via Service (spearphishing messages via third-party services like social media)
3.  Malicious File Execution (fake `.pptx`, `.docx`, $\dotso$)

### Password/Input Logging
1. Keylogger
2. Browser Session Storage (they took passwords from firefox password stores)

### Malware Transfer
1. Ingress Tool Transfer (installed a tool to transfer more malware after initial *exploit*)
	+	Ingress: incoming

## Mitigation against **Ajax Security Team**
### External Attempts
This is easier to solve than the other two categories. One method is *inform* company members about email scams and how to validate emails (check names, grammar, links, $\dotso$). We also discussed other mitigation methods during the phishing activity. One implemented solution was sending your own employees compromised emails to see if they will fall for scams and then training them. This lowers the cost for training in the long run by excluding already informed individuals. 

### Password/Input Logging
Getting keyboard state is a sensitive task. Given this information Keyloggers will likely require registry or driver changes which can be monitored. This falls under the `Moniter OS API` category.  

### Malware Transfer
Mitre recommends monitoring you network for constant transfers to detect a transfer by seeing transfer signatures and detecting attacks. However Mitre also warns that there are many ways to by pass this. Here are a few bypass methods I can think of:
1. throttling transfer speeds to your victim cannot see what is downloading malware
2. changing download signature to protect attacker identity

One possible solution is creating a list of **approved** applications to run and only allowing employees to run those programs. This way, if anything is installed, it cannot run.