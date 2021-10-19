# Python program to introduce Binary Tree

# A class that represents an individual node in a
# Binary Tree
class Node:
	def __init__(self,data):
		self.left = None
		self.right = None
		self.data = data


# create root
root = Node(1)
root.left	 = Node(2)
root.right	 = Node(3)
root.left.left = Node(4)


#Traversal [PreOrder]

def preorder(root):
    if root == None:
        return
    
    print(root.key)
    #Recursive call
    preorder(root.left)
    preorder(root.right)


#Execute program 
preorder(root)

#Contributed by KmAlan