# Deployments
## Methods of Deployment
### Canary
We can release a new MS and send a small subset of users to this service and thus we can see what occurs and only effect a small subset of users.

### Dark Launching
We deploy a new functionality but we make it invisible to end-users. When testing is done and it is ready to be launched the new function is the visible to end-users.

This along with *canary* are **progressive** techniques. 
### Blue-Green
We can update a service overtime. K8S will create two deployments :

1. Blue : old version (current)
2. Green: New Version (updated)

As time goes on more and more deployments will be "green". This method of deployment is not instant and that is it's strength. 

The difference from Canary is that the 'green' comes out immediately. If something goes wrong in a 'green' MS we can convert it to a blue MS.  
