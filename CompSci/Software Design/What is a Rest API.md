# Explanation 
## Eli5 From [Reddit](https://www.reddit.com/r/explainlikeimfive/comments/rypnmj/eli5_what_is_a_rest_api/hrrd0l8/?context=3)

REST is not itself an API but more so a guide on how to build APIs.

First and foremost a core principal of RE**S**T is that it must be ***s*tateless**. This means that an API call should only worry about who is calling it **now**. At no point should a call effect ones after it. 

The reason why is that it prevents coupling since it requires the knowledge from previous calls to make the current one successful. Also, notice that out of order commands will not be taken well. 

Another critical idea of **RE**ST is *re*presentation. To represent this idea we must explore the opposite of REST: RPC.

### RPC
RPC stands for Remote Procedure Call. An RPC API is a list of *actions*. You choose the action and provide what it needs to act on. However, this is backwards in REST where you provide an HTML Method (Verb) on an object and have the API take an action.
