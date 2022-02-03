# Domain Driven Design Business Assignment
## Description
The company will be a gas energy distributor in the area. It signs contracts with people living in the area and then distributes gas to them. They are charged based on the gas used, this is handled by the accounting department. The company is extensive, it has a fleet of personnel to handle gas-related emergencies in people's homes and the city. The same team maintains company infrastructure. It also contains a CIS division to maintain its online services and provide customer support. 

>**Summary**
>
>The point of this company is to appropriately distribute gas to businesses and residents of the city and tackle gas-related emergencies.

## Business Outline
The main domains in this business are the payment collection division, recruitment users division, and gas-emergency/equipment installation/maintenance division 

### Flow
People will sign up for a gas inflow to their house which will be handled by the recruitment sub-team. The rest of the business cycle will be a circular loop. People use gas and will be billed by the accounting sub-team (reoccurring) while the equipment personal sub-team will receive orders to go to locations and complete procedures. 

![[Bus_layout.png]]
## Business design
The flow starts from a customer and whether or not they have signed up. Then they are billed by the Accounting Sub-team which when it comes time for billing they ask the field team to look over gas usage at the installed meter in the customer's home. This fulfillment of this task from the Field unit will allow accounting to send an **accurate** billing based on a customer's properties.

>*Note*: The number of properties is part of the set of documents a customer provides for service to the Financial department
## Sub-team Internal Design
We will analyze the Financial domain because it is more complex than the other two.

### Requirements
The Financial team requires their software
+ can handle $1:M$ relation for customers and properties
+ different areas of the city may have different pricing based on installed equipment (efficiency and distance). The software **must** reflect this.
+ We must be able to add new properties and new customers at anytime
+ Financial also handles employee payroll. Their new software must reflect this.
+ Financial requires that we keep a history off all their activities like
	- Billing Receipts
	- Employee Payroll History 
+ Design must be modular since the Financial team may grow in responsibility
### Model
![[Subteam Diagram.png]]

### Model Details
Firstly notice the three endpoints. Each endpoint is a database exposure that serves to allow the **organization** to add new entities like customers. Like any good database, it can reject unauthorized requests.

Next is the core service of the Financial domain, the Bill Creation Service. The Bill creation Service will ask the field unit to *physically* check up on a customer's meter(s) and report back. This read/write of the gas meter reading has been handled by a separate service because we don't want bill printing to halt if meter reading stops. After this occurs the Billing service will fetch gas price data from a **separate** database and then send the bill to the customer based on their preferences (paper or electronic), which are stored in the customer database which can be only accessed by the Financial Dept as per Bounded Context.  

I added the Data Warehousing as a final touch because every good company keeps a *detailed* history of their transactions which is what a Data Warehouse is supposed to do: keep historical data. Moreover, this Data Warehouse is great to have as we can extract information if there is a data loss on the main databases. While we didn't discuss this in class I think that a Data Warehouse is a good addition because it follows the guidelines of DDD. It essentially draws for us the Transactional boundary of the business domain we are defining.

### Bounded Context Example
The customer is a **perfect** example of a bounded context here. A customer in this business is much like an overloaded method in java—There exist many functional definitions for this entity. A customer to our Financial group is their 
+ Preferences
+ Properties Signed on
+ Their address (due to Billing Specs)
+ Set of Billing Exemptions (Tax, Age, Income)

This differs from the view of customers to the Recruiting Domain since they are only worried about customer eligibility (Address). Recruiting has no regard for what customers prefer or what their exemptions are. 
