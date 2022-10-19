# Lecture Notes

> **USB**: Universal Serial Bus

**Host Controller Chip Set**:
![HCCS.png](/img/HCCS.png)

We can detect our controller type with:
```bash
parth@parth-HP-Laptop-15-dy1xxx:~$ lspci | grep "USB"
00:14.0 USB controller: Intel Corporation Ice Lake-LP USB 3.1 xHCI Host Controller (rev 30)
```

**Note**: A USB Hub is a device that  expands a single Universal Serial Bus (USB) port into several so that there are more ports available.

Each machine has hubs to curb compatibility issues. These hubs can be found with `lsusb`. 

### USB File Systems
There exists FS specific to USBs.
1. True Flash FS
2. Extreme FFS
3. JFFS
4. YAFFS

### USB Power
USBs are powered by themselves or from the connected BUS. 

### USB Packets
![USB_PACKET.png](/img/USB_PACKET.png)

USB Endpoints (ENDP)
1. Control Endpoints 
	+ commands and status operations
	+ Example commands: Host asking for USB Descriptors 
2. Interrupt Endpoints
	+ helps avoid busy waiting
3. Isochronous Endpoints
	+ When you need a min bandwidth
4. Bulk Endpoint
	+ Used for storage but have no latency guarantee

 ## Linux Commands
 ### `lsusb`
 + List USB Devices on machine
### Metadata
One option is to use the `-v` (verbose) on `lsusb` which will display identifiers for USB devices. 

Also we can use the VID and PID:
1. VID - Vendor ID
2. PID - Product ID

[USB.org](https://USB.org)  can be used validate VID/PID. 

