# Week 9 Activity
First I navigated to
```text
Application and Services Logs > Microsoft > Windows > DriverFrameworks-UserMode > Operational
```
Then I enabled logging on the Operational file.

## Plugging in my USB
![week_9_industry_s1](/img/week_9_industry_s1.png)

Here is the initial look of the `Event Viewer`.

Before I inserted the SSD the log was empty, thus I can conclude the first entry at `10-20-2022 @11:18:14` is when I inserted the drive. 

The 2003 entry states:
```text
The UMDF Host Process ({3b9ddded-f521-4ec0-b67b-c00140528161}) 
has been asked to load drivers for device 
SWD\WPDBUSENUM\{869FDFC9-807D-11EC-8239-FE122FFA2CBD}#000000493E100000.
```

The serial number is `#000000493E100000`. This shows up on each event log that is related to this device.  


## Disconnection

Disconnection from a machine generates events of id `2100` and `2102`.

![week_9_industry_s2](/img/week_9_industry_s2.png)

## Creating Custom View for Event:Disconnection and Event:Connection
Created a view where it would record events with id:
1. `2003`
2. `2102`

![week_9_industry_s3](/img/week_9_industry_s3.png)

This custom view shows that I plugged in my SSD twice in the span of 7 minutes. 

### Alternate View: Group By `Event ID` column

![week_9_industry_s4](/img/week_9_industry_s4.png)