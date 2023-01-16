# Final Email Assignment

I used an additional website to collect information: [mha.azurewebsites.net](https://mha.azurewebsites.net/)

## MetaData
### Basic Data
![[basic_meta_data.png]]

This data can also be found on the mail agent (outlook). The website we are supposed to use does not seem to parse the `to` attribute correctly possibly due to the newlines. 

### Message ID:

![[no_message_id.png]]

### Content Sender: *Outlook*
The content was sent from outlook as shown by the first hop. 

![[hop_1.png]]

Based on the *internal* hops, the email was routed using Outlook Servers.

#### Hops

![[t_hops.png]]

All hops occur on outlook servers. This would be more interesting if we started out on our own email server.  

### Content Types
There is a 
```
Content-Type: application/ms-tnef; name="winmail.dat"

Content-Transfer-Encoding: binary

```

Its an HTML email transfer as defined by the Content-Type attribute over the wire which happens to be in binary. 