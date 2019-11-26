# RedBlackTree.py
class TreeNode():
	def __init__(self, val, nodeColor = 'R', parentNode = None):
		self.val = val
		self.color = nodeColor # new Node is Red
		self.parent = parentNode
		self.left = self.right = None

	def isLeftChild(self):
		return (self.parent) and (self.parent.left is self)

	def isRightChild(self):
		return (self.parent) and (self.parent.right is self)

	def LeftRotate(self):
		rightChild = self.right
		self.right = rightChild.left
		rightChild.left.parent = self
		rightChild.left = self
		if (self.isLeftChild()):
			self.parent.left = rightChild
		else:
			self.parent.right = rightChild
		rightChild.parent = self.parent
		self.parent = rightChild

	def RightRotate(self):
		LeftChild = self.left
		self.left = LeftChild.right
		LeftChild.right.parent = self
		LeftChild.right = self
		if (self.isLeftChild()):
			self.parent.left = LeftChild
		else:
			self.parent.right = LeftChild
		LeftChild.parent = self.parent
		self.parent = LeftChild


class RBTree():
	def __init__(self):
		self.root = None

	def InsertNode(self, val):
		def helper(curr, parentNode = None):
			# if curr is None
			if (not curr):
				# if current node is root
				if (curr is self.root):
					# root is black
					curr = TreeNode(val, nodeColor = 'B')
				else:
					curr =  TreeNode(val, parentNode = parentNode)
					self.__Balancify(curr)
			else:
				if (curr.val > val):
					curr.left = helper(curr.left, curr)
				else:
					curr.right = helper(curr.right, curr)

			return curr

		self.root = helper(self.root)

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

			# if parent is left child of grand parent
			if (parentNode.isLeftChild()):
				# Case2: sibling is black
				else:
					# Case2-1: curr is right child
					if (curr.isRightChild()):
						pass
					# Case2-2: curr is left child
					else:
						pass

			# if parent is right child of grand parent									
			else:
				pass

	def DeleteNode(self, val):
		pass

	def PrintTreeInorder(self, curr = 0):
		if (curr is 0):
			curr = self.root

		if (curr):
			self.PrintTreeInorder(curr.left)
			print("{0}[{1}]->".format(curr.val, curr.color), end = ' ')
			self.PrintTreeInorder(curr.right)

	def PrintTreeLevelOrder(self) -> List[List[int]]:
		rtrnList = []

		if (self.root is not None):
			queue = [ self.root ]

			while (queue):
				currLevels = []
				for _ in range(len(queue)):
					curr = queue[0]
					if (curr.left): queue.append(curr.left)
					if (curr.right): queue.append(curr.right)
					currLevels.append(curr.val)
					queue.pop(0)
				rtrnList.append(currLevels)

		print(rtrnList)

tree1 = RBTree()

tree1.InsertNode(3)
tree1.InsertNode(2)
tree1.InsertNode(1)
tree1.InsertNode(4)
tree1.InsertNode(5)

tree1.PrintTreeInorder()
tree1.PrintTreeLevelOrder()
print('')