# Documentary Thoughts 
For: [[CIS4360]]
Link: [YouTube](https://www.youtube.com/watch?v=BE77h7dmoQU)

## Google-Amazon Rivalry
One of the major origins of Kubernetes is Google's competition with Amazon(AWS) over the Cloud (IaaS) market. As time went on people wanted higher levels of abstraction, this led to the importance of the cloud. The key part of this Amazon-Google rivalry was the fact that Amazon with AWS was so much **ahead** of Google. This led Google to sit and ponder how to "disrupt" the current Cloud market. The fact that Google was behind in the race is one of the key reasons for the existence of Kubernetes. 

## A key Unit of Kubernetes : *Docker*
During this time many developers lacked technologies that allowed them to scale their products. This was an unfair advantage that large companies her. Docker aimed to solve this issue *democratically*. It is my opinion that Kubernetes would not have existed without Docker since that is quite literally what it abstracts.  

## Promise Theory: Kubernetes
One of the aims of Kubernetes is the uptime of your *application*. Kubernetes essentially **promises** that your application will be active all the time by abstracting away the issues that come with keeping an app running all the time like machines breaking down. Kubernetes, in short, will take the stress of hosting apps off the developer so they can focus on what they need to do. 

---


## The Open-Source Nature of Kubernetes
Kubernetes is an Open-Source project because the team at Google wanted a project that would always be **evolving**. It is important to be Open-Source so people can look at the code and find new ways to improve it rather than just shipping out the product and having people use it the way it is intended. Moreover, this gave Kubernetes a sort of a larger team in a sense giving it more of a backing.

## Kubernetes \& Microservices
Kubernetes, Docker, and Microservices almost feel like they are made for each other. That of course the design of the three. Kubernetes as far as I know is perfect for Microservices. One of the main strengths of Microservices is the scalability of the design paradigm. This is what Kubernetes offers as its main service. We saw in the Labs that can a developer specify how many instances of a container they need running which is what Microservices is all about. Deployment is also a great feature on Kubernetes: we can add a new container instance (pod) and it will get picked up by a service assume we labeled everything correctly. Moreover, Kubernetes even manages to abstract away load balancing. This is perfect for Microservices since we want customers to have a smooth experience on our website. Lastly and most importantly, K8S performs uptime management for us. I cannot imagine the hoops someone would have to jump through to keep thousands of microservices up. While Microservices are scalable without Kubernetes, Kubernetes makes things a lot less complex for the developer.