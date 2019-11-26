# RedBlackTree.py
class TreeNode():
	def __init__(self, val, nodeColor = 'R', parentNode = None, NILNode = None):
		self.val = val
		self.color = nodeColor # new Node is Red
		self.parent = parentNode
		self.left = self.right = NILNode

	def isLeftChild(self):
		return (self.parent) and (self.parent.left is self)

	def isRightChild(self):
		return (self.parent) and (self.parent.right is self)

NILNode = TreeNode(None, 'B')

class RBTree():
	def __init__(self):
		self.root = NILNode

	def InsertNode(self, val):
		def helper(curr, parentNode = None):
			# if curr is None
			if (curr is NILNode):
				# if current node is root
				if (curr is self.root):
					# root is black
					self.root = TreeNode(val, nodeColor = 'B', NILNode = NILNode)
				else:
					curr =  TreeNode(val, parentNode = parentNode, NILNode = NILNode)
					if (parentNode.val > curr.val):
						curr.parent.left = curr
					else:
						curr.parent.right = curr
					self.__Balancify(curr)
			else:
				if (curr.val > val):
					helper(curr.left, curr)
				else:
					helper(curr.right, curr)

		helper(self.root)

	def LeftRotate(self, target):
		rightChild = target.right
		target.right = rightChild.left
		rightChild.left.parent = target
		rightChild.left = target
		if (target is self.root):
			self.root = rightChild
		else:
			if (target.isLeftChild()):
				target.parent.left = rightChild
			else:
				target.parent.right = rightChild
		rightChild.parent = target.parent
		target.parent = rightChild

	def RightRotate(self, target):
		LeftChild = target.left
		target.left = LeftChild.right
		LeftChild.right.parent = target
		LeftChild.right = target
		if (target is self.root):
			self.root = LeftChild
		else:
			if (target.isLeftChild()):
				target.parent.left = LeftChild
			else:
				target.parent.right = LeftChild
		LeftChild.parent = target.parent
		target.parent = LeftChild

	def __Balancify(self, currNode):
		parentNode = currNode.parent
		grandNode = None
		siblingNode = None
		if (parentNode.parent is not None):
			grandNode = parentNode.parent
			if (parentNode.isLeftChild()):
				siblingNode = grandNode.right
			else:
				siblingNode = grandNode.left

		if (parentNode.color == 'R'):
			# Case1: sibling is red
			if (siblingNode.color is 'R'):
				parentNode.color = siblingNode.color = 'B'
				grandNode.color = 'R'
				if (grandNode is self.root):
					grandNode.color = 'B'
				else:
					self.__Balancify(grandNode)
			# Case2: sibling is black
			else:
				# if parent is left child of grand parent
				if (parentNode.isLeftChild()):
					# Case2-1: curr is right child
					if (currNode.isRightChild()):
						self.LeftRotate(parentNode)
						self.__Balancify(parentNode)
					# Case2-2: curr is left child
					else:
						self.RightRotate(grandNode)
						parentNode.color, grandNode.color = grandNode.color, parentNode.color
				# if parent is right child of grand parent									
				else:
					if (currNode.isLeftChild()):
						self.RightRotate(parentNode)
						self.__Balancify(parentNode)
					else:
						self.LeftRotate(grandNode)
						parentNode.color, grandNode.color = grandNode.color, parentNode.color


	def DeleteNode(self, val):
		pass

	def PrintTreeInorder(self, curr = 0):
		if (curr is 0):
			curr = self.root

		if (curr is not NILNode):
			self.PrintTreeInorder(curr.left)
			print("{0}[{1}]->".format(curr.val, curr.color), end = ' ')
			self.PrintTreeInorder(curr.right)

	def PrintTreeLevelOrder(self):
		rtrnList = []

		if (self.root is not None):
			queue = [ self.root ]

			while (queue):
				currLevels = []
				for _ in range(len(queue)):
					curr = queue[0]
					if (curr.left is not NILNode): queue.append(curr.left)
					if (curr.right is not NILNode): queue.append(curr.right)
					currLevels.append(curr.val)
					currLevels.append(curr.color)
					queue.pop(0)
				rtrnList.append(currLevels)

		level = 1
		for levels in rtrnList:
			print('level {}'.format(level), levels)
			level = level + 1


tree1 = RBTree()

inputList1 = [ x for x in range(10, 0, -1) ] # [ 4, 6, 7, 8, 2, 10 ] # [30, 10, 20, 50, 40, 5, 15, 7 ]
print('input value:', inputList1, end ='\n\n')
for inputVal in inputList1:
	tree1.InsertNode(inputVal)

print('Result(Inorder Treversal)')
tree1.PrintTreeInorder()
print('end\n')

print('Result(LevelOrder Traversal)')
tree1.PrintTreeLevelOrder()

