# Traversals of [[Trees]]
Written in Pythonic "Pseudo" Code
None is a `Null`
### Preorder

```python
def preorderTraversal(root):
	if(root != None):
		process(root.val)
		preorderTraversal(root.left) #recursive
		preorderTraversal(root.right)#recursive
```

### Inorder
```python
def inorderTraversal(root):
	if(root != None):
		inorderTraversal(root.left) #recursive
		process(root.val)
		inorderTraversal(root.right)#recursive
```

### Postorder
```python
def postorderTraversal(root):
	if(root != None):
		postorderTraversal(root.left) #recursive
		postorderTraversal(root.right)#recursive
		process(root.val)
```

We notice the the 3 basic Traversals only differ in which order the *process* root is called. 

Here is an example tree:
![[BintreeTravEx.svg]]

The three Traversals:
1. Preorder: F, B, A, D, C, E, G, I, H
2. Inorder:  A, B, C, D, E, F, G, H, I
3. Postorder: A, C, E, D, B, H, I, G, F.