# BinaryTree.py
class BinaryTree:
	def __init__(self):
		self.root = None


	def PreorderTraversal(self):
		datas = []
		def helper(root):
			if (root is None):
				return
			else:
				datas.append(root.data)
				helper(root.left)
				helper(root.right)

		helper(self.root)
		return datas


	def InorderTraversal(self):
		datas = []
		def helper(root):
			if (root is None):
				return
			else:
				helper(root.left)
				datas.append(root.data)
				helper(root.right)

		helper(self.root)
		return datas


	def PostorderTraversal(self):
		datas = []
		def helper(root):
			if (root is None):
				return
			else:
				helper(root.left)
				helper(root.right)
				datas.append(root.data)

		helper(self.root)
		return datas


	def LevelorderTraversal(self):
		datas = []

		q = [ self.root ]
		while ( q ):
			curr = q.pop(0)
			datas.append( curr.data )

			if ( curr.left ):
				q.append( curr.left )
			if ( curr.right ):
				q.append( curr.right )

		return datas


	def PrintTree(self, order = 'in'):
		if ( order is 'in' ):
			datas = self.InorderTraversal()			
		elif ( order is 'pre' ):
			datas = self.PreorderTraversal()
		elif ( order is 'post' ):
			datas = self.PostorderTraversal()
		elif ( order is 'level' ):
			datas = self.LevelorderTraversal()

		print( order + 'order: ' + str( datas ) )
