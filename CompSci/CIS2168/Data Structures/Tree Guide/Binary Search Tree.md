# Binary Search Tree
The BST is one of the  '[[Trees]]'. The BST is used to organize data in a manner which is easy to search. The ADD/Remove operations are fast as well.

## The BST Property
A BST has 3 basic components: 
1. $T_L$ Left SubTree
2. $T_R$ Right SubTree
3. Root $R$. 

Notice that any subtree of a BST is also a BST.
The rule for an BST is that for all elements $T_L$, they are lesser than $R$ while all elements in $T_R$ are greater than $R$. BST cannot hold duplicate values.

## BST Operations
Find wont be covered since it is trivial: Search $R$ and then $T_L, T_R$ based on on the comparison with $R$. 
### BST Add Item
Addition is not very Complex for a BST. Recall a the BST Property. That will be used to insert into the Bin-Tree.

***Algorithm***:
**If** a null spot has been found then return a **new** node with the value of the Insertion Object.
**If** it is equal to the current root node's data, then return nothing. 
**Else** recursively call add on the right and left subtrees.

#### Add Java Code

```java
//addReturn is a class var
public boolean add(E item) {  
    root = add(root, item);  
 	return addReturn;  
}  
  
private BinaryTreeNode<E> add(BinaryTreeNode<E> subtree, E item){  
    if(subtree == null){  
        return new BinaryTreeNode<E>(item);  
 	}  
    //avoids null.compareTo  
 	int compResult = subtree.data.compareTo(item);  
 	if(compResult == 0){  
        addReturn = false;  
 	return subtree;  
 	}  
    else if(compResult > 0){  
        //tree item is larger than insertion point  
 	subtree.left = add(subtree.left, item);  
 	return subtree;  
 	}  
    else{  
        //tree item is not equal or larger or equal so split right.  
 	subtree.right = add(subtree.right, item);  
 	return subtree;  
 	}  
}
```

Now this works because no node is found by add(...) it returns a new ref to a **new** node. This cascades as the stack of calls collapses and the value is correctly inserted. This style of coding trees is essential for tree rotation.  

### BST remove
The Removal of a node is a bit complex:
The state of a target node for removal is in one of 3 states: 

1. Node to remove has 0 children
2. Node to remove has 1 child
3. Node to remove has 2 children (Complex)

#### Case 1: Leaf Node removal
This case is trivial since we can just mark the pointer on its parent to null.

#### Case 2: Node Has a *Singular* Child
For this case, the parent node will just move its reference from the current node to its child's child. This will not cause any violations of the BST Property. There only 4 possibles of this *Singular* Child scenario, each is easy to show that the BST Properly holds. 

#### Case 3: Node has 2 children
This case isn't a simple pointer swap. Here is an option that allows you to remove the double-child node.

We can replace the node with the largest element of its left subtree $E$ and deleted the replaced element since it is a leaf node. This is valid since this new element $E$ will he larger than every node below it. Also since its in the left Subtree its also smaller than its parent of the original Node. This simplifies the removal case then to Case 1 or Case 2. 

An alternate solution is to do the same with the leftmost element of the right-subtree.  
#### Removal Java Code
```java
public E delete(E item) {  
    root = delete(root, item);  
 	return deleteReturn;  
}
public BinaryTreeNode<E> delete(BinaryTreeNode<E> localRoot, E item){  
    if(localRoot == null){  
        deleteReturn = null;  
	return localRoot; //object not found  
 	}  
    int compRes = item.compareTo(localRoot.data);  
 	if(compRes < 0){  
        System.out.println("T: left");  
 	localRoot.left = delete(localRoot.left, item);  
 	return localRoot;  
 	}  
    else if(compRes > 0){  
        System.out.println("T: right");  
 	localRoot.right = delete(localRoot.right, item);  
 	return localRoot;  
 	}  
    else{  
        //node found;  
 		//if a node has 0 or 1 child the method is the same; //0 - leaf has nothing below //delete the node and set it to the node chain below. deleteReturn = localRoot.data;  
 		if(localRoot.left == null){  
            return localRoot.right;  
 		}  
        else if(localRoot.right == null){  
            return localRoot.left;  
 		}  
        else {  
            //there node has 2 children  
			 //2 case algorithm: //EXP: get largest element on the left subtree on that node for node replacement || smallest element on right tree 
			 //overwrite the data on the deletion node with replacement and then delete old replacement if(localRoot.left.right == null){  
			localRoot.data = localRoot.left.data;  
			localRoot.left = localRoot.left.left;  
			return localRoot;  
			}  
			localRoot.data = getMax(localRoot.left); //notice that since we know there exists 2 children we can go left  
			return localRoot;  
		}  
  
    }  
}
//gets the right most element of the left-subtree
public E getMax(BinaryTreeNode<E> BST){  
    if(BST == null){  
		return null;  
 	}  
    BinaryTreeNode<E> curr = BST;  
 	BinaryTreeNode<E> prev = curr;  
 	while(curr.right != null){  
        prev = curr;  
 		curr = curr.right;  
 	}  
    E data = curr.data;  
 	prev.right = null;  
 	return data;  
}
```
### Operational Runtime 
Runtime Table

|     __      | BST       | Bin-Tree |
| --------- | --------- | -------- |
| Searching | $\log{n}$ | $n$      |
| Adding    | $\log{n}$ | $n$      |
| Removing  | $\log{n}$ | $n$      |

Bin-tree Is assumed $O(n)$ due to the fact it can be a LinkedList in the worst case.