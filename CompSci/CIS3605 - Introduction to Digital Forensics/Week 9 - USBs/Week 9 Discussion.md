# Week 9 Discussion
Currently there are *two* devices connected to my device. These are: 
1. Mouse
2. SSD with a Bootable Linux Sector
3. DVD r+ Player

We can focus on device (2) which is a single purpose storage extension. 

## Wireshark USB Capture
For this capture I had to disconnect my mouse, it kept generating interrupts a lot which made analysis annoying.

## OS Info
![3605_discussion_9_s4.png](/img/3605_discussion_9_s4.png)

This image displays the BUS number this device is on.

I was able to find that this storage unit uses `exFAT` as the file system. 

## `GET DESCRIPTOR Response DEVICE`
![3605_discussion_9_s1.png](/img/3605_discussion_9_s1.png)

The Vendor was correctly identified as well as the product ID. I know the PID is correct since it was listed on website when I bought it. 

## `GET CONFIGURATION`
![3605_discussion_9_s2.png](/img/3605_discussion_9_s2.png)

The first configuration packet shows that the device is not self powered. It also sends over the max power it can handle. 

![3605_discussion_9_s3.png](/img/3605_discussion_9_s3.png)
A descriptor tells us it is a storage device. 

There are also a lot of `SUPERSPEED ENDPOINT COMPANION DESCRIPTOR` but that is normal since this device is made to support high rate file transfers. 