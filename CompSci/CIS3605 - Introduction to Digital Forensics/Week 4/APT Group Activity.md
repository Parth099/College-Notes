# APT Group Activity
## Why would anyone learn about APT groups?

Learning about APT groups allows organizations to stay protected on both sides of the Cyber Kill Chain. Knowledge about exploited vulnerabilities in the past allows a company to prepare a defense and knowing the 'Attack profile' of a persistent threat allows them to draft a offensive strategy to contain the threat.  

## How does it help you be a better Cyber analyst?
Assuming you are the Cyber analyst at a company, learning about APT groups allows you to 'predict' the future in terms on next possible steps an attacker can take based on where they are *now* in the system. Moreover knowing what type of company you are and who regularly attacks your type of company likely helps build better defense. 

## From the link above, pick one technique used and describe it
Tactic used: [Steal Web Session Cookie](https://attack.mitre.org/techniques/T1539/)

**Background info on cookies:**
Many browsers will use cookies for auth and to track users without a login. For example a company like amazon can utilize cookies to learn the shopping preferences of a user who **does not** have an account by installing a identifier cookie on their browser which is used to communicate with the amazon servers when that user requests a page (there are HTTP cookie header field). Cookies are key-value pair strings. 

Our APT stole cookies from local storage and likely used them to pass the auth on websites. They pretended to be valid authenticated users. They did so by copying the Chrome profile directories of existing users. 

### Detail
+ threat actor used multiple logins to move across the network
+ they decrypted the cookies/saved passwords by finding the encryption keys on the user machine
	+ these keys are located on some predefined path when a user uses Google Chrome
+ Office 365 users must solve a challenge to sign in. A solved challenge is valid for 24 hrs. 
	+ This Time-to-live for the validity is stored as cookie information and if stolen and used the hacker does not have to complete the challenge

## Traces/Evidence
The threat actor installed a chrome extension on the user machines to steal cookies and deleted it. This means chrome has a event log for this event (this evidence was found and processed).  This skill is **critical** for any Cyber analyst as there are many chrome extensions being published everyday and not every extension is beneficial. 

As for the "Credential hopping", that is a lot harder to track. The group used different accounts with varying level of privilege to commit their actions making their trail harder to decode. I am not sure how this would be detected. While it is clear the evidence would be logged somewhere stopping before it happens or while it is happening seems hard since they had access to _admin_ level accounts.

