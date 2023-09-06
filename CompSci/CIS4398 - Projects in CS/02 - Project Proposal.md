# Project Proposal

## Keywords

Name: ACC Coloring Book
Section: 02
Proposer: Parth Patel

Keywords:
+ Cloud Computing
+ AI Powered
+ Containers and Container Orchestration
+ Web Development
+ Accessible technology

## Project Abstract

AAC (augmentative and alternative communication) apps are alternative communication interfaces that allow non-verbal individuals to express themselves via TTS (text-to-speech).  Many of these tools are hard to use and it takes significant training to do so. Oftentimes, speech experts have to model actions[^1] on the AAC device to help their users learn the actions which can be uninteresting for learners. To solve this problem this proposal presents the idea of a 'AAC Coloring Book'. This app *gamifies* learning of an AAC tool by allowing users to produce speech through their device which will color targets on the screen. For instance, if the user uses their device to create a machine utterance of "brown dog", the app aims to transcribe this utterance and color the target (the dog) brown on the canvas. This gamification allows users to *want* to learn their AAC device rather than standard exercises and creates another training platform for AAC apps. The website aims to provide this experience as well as providing more advanced experiences such as multi-player coloring options and possibly eye-tracking-based painting. 

## High-Level Requirement

Foundationally, this app should transcribe any AAC/TTS device utterance and color any *relevant* targets on the canvas in the specified color. This *canvas* they are verbally painting will be able to be exported and saved on cloud storage[^2] and local storage. Each canvas they paint will award the user game points based on the image difficulty and category which will serve as a progression metric to show any admins the level of usage and command of their AAC device. Since it is often hard to keep track of new vocabulary, the app aims to integrate eye tracking where a user can stare at an object to reveal its name allowing them to learn its name and search for it in their AAC device. Since communicating with others is the primary goal of AAC devices, a multi-player system will exist where a set of players can work on painting the same canvas. 

## Conceptual Design

This AAC training will be powered by a web experience with both a front-end and a back-end. The frontend will be powered by NEXT.js which is a wrapper over react to create more secure and server-friendly websites. The backend will be powered by express.js which easily allows for route creation and is in the same language as the front end.

The backend will be hosted on AWS infrastructure. To ensure a cost-friendly plan either EKS (Elastic Kubernetes Service) or ASGs (Auto Scaling Groups) with VMs will be used to ensure only needed resources are running at one time. Also, the AWS suite offers tooling that may be useful down the line such as AWS Polly (TTS) or AWS Cognito (Authentication/Authorization). All static media will be stored in AWS S3 to allow controlled access to things like images and to create an authentication barrier for the admin trying to upload. 

Additional eye-tracking hardware/software may be needed if eye-to-target selection is implemented. 

## Background

This tool is novel in the sense that AAC tool learning is done personally with a Speech-Language Pathologist (SLP) involved[^3] due to its difficulty. The absence or lesser presence of a SLP is the primary differentiator for this tool, learning can continue without a language present or with minimal management of learning from the SLP after the initial tool demonstration. 

Competitors like Fluent AAC[^4] and AssistiveWare[^5] are focused on adding more symbols and expressions but do not create a platform for learning like *AAC Coloring Book*. 

## Required Resources

+ Eye Tracking Web Integration resources which will be determined during spring refinement and planning.
+ An AAC Device *or* app which can create utterances
+ AWS Credits / Budgets or a CIS AWS Account with shallow permissions. 


### Software Requirements
+ NEXT.js (React.js)
+ Express.js / node.js
+ Terraform (Infrastructure as Code Tool)
+ AWS Suite -- Services that will be used but are not limited to:
	+ AWS S3 (Object Storage)
	+ AWS Cognito (Authentication and Authorization)
	+ AWS Polly (TTS Service)
	+ AWS EC2 (Virtual Machines)
	+ AWS Networking Resources (VPC)
	+ Possible use of AWS Lambda (Serverless Functions) and AWS DynamoDB (NoSQL DB)
	+ Possible use of AWS Fargate or AWS EKS



[^1]: What is AAC Modeling? www.assistiveware.com/learn-aac/start-modeling
[^2]: Saved in two locations because users will NOT be allowed to upload SVGs. This is confusing to people who upload invalidly tagged SVGs and open the app to SVG injection vulnerability. 
[^3]: What are Speech-Language Pathologists and what do they do for AAC?: https://www.asha.org/public/speech/disorders/aac/
[^4]: Competitor - Fluent AAC: https://www.fluentaac.com/
[^5]: Competitor - AssistiveWare AAC: https://www.assistiveware.com/products

