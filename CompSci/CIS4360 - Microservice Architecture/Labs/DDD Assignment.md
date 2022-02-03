# Domain Driven Design Business Assignment
## Description
The company will be a gas energy distributor in the area. It signs contacts with people living in the area and then distributes gas to them. They are charge based on the gas used, this is handled by an accounting department. The company is extensive, it has a fleet of personnel to handle gas-related emergencies in people's homes and in the city as well as maintain company infrastructure. It also contains an CIS division to maintain their online services and provide customer-support. 

>**Summary**
>
>The point of this company is to appropriately distribute gas to business and residents of the city and tackle gas-related emergencies.

## Business Outline
The main domains in this business is the payment collection division, registering users division and gas-emergency/equipment installation/maintenance division 

### Flow
People will sign up for a gas inflow to their house which will be handled by the recruitment sub-team. The rest of the business cycle will be a circular loop. People use gas and will be billed by the accounting sub-team (reoccurring) while the equipment personal sub-team will receive orders to go to locations and complete procedures. 

## Business design
![[Bus_layout.png]]
The flow starts from a customer and whether or not they have signed up. Then they are billed by the Accounting Sub-team which when it comes time for billing ask the field team to look over gas-usage at their installed meter at their home. This fulfillment will allow accounting to send an accurate billing based on a customer's properties.

>*Note*: The number of properties is part of the set of documents a customer provides for service to property
## Sub-team Internal Design
We will analyze the Financial domain because it is more complex than the other two.

### Requirements
The Financial team requires their software
+ can handle $1:M$ relation for customers and properties
+ different areas of the city may have different pricing based on installed equipment (efficiency and distance). The software **must** reflect this.
+ We must be able to add new properties and new customers at anytime
+ Financial also handles employee payroll. Their new software must reflect this.
+ Financial requires that we keep a history off all their activites like
	- Billing Receipts
	- Employee Payroll History 
+ Design must be modular since Financial team may grow in responsibility
### Model
![[Subteam Diagram.png]]

### Model Details