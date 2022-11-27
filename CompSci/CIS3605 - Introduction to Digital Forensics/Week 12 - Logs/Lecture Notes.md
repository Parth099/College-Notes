# Logs

## Types of Logs - Linux
`root` directory for logs

1. `/var/log/syslog` or `/var/log/messages`
	+ Store global system activity data
2. `/var/log/auth` or `/var/log/secure`
	+ Store all security related events	
3. `/var/log/kern` - kernel events
4. `/var/log/cron` - cron logs

## Types of Logs - Windows
1. Application Logs
2. Security Logs
3. System Logs

> GUI TOOL: *Event Viewer*

Each of the logs above contain logs themselves:
+ Error Logs
+ Warning Logs
	+ Ex: Size Threshold on file sizes
+ Information Logs
+ Success/Failure Audits (security)
	+ Ex: Admin Account has been logon failed 2 times

Access logs is protected. Some are hidden. 

## Syslog Protocol 
1. Syslog Data Packet - Structured Event Data
2. Security Rule - Data evaluation that will trigger some event
3. Alert / Notifications

Syslog Packets are replayed via UDP (port 514). However Syslog requires TLS support so no packets are altered. 

![syslog_life](/img/syslog_life.png)

### Syslog Packet Structure
![sp_struct](/img/sp_struct.png)

The Facility is the source of the event (app/kernel)

The Severity code is the importance assigned to a threat/event. 

![severity_codes](/img/severity_codes.png)

There are also facility code that determine what generated the syslog message. 

![facility_codes](/img/facility_codes.png)