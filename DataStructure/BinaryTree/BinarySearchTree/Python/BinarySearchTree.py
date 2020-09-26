# BinarySearchTree.py
from TreeData import TreeData
from BinaryTree import BinaryTree

class BinarySearchTree(BinaryTree):
	def __init__(self, order = 'asc'):
		super().__init__()
		self.order = order


	def InsertData(self, data) -> None:
		def __insert_asc(root: TreeData) -> None:
			if ( root.data > data ):
				if ( root.left ):
					__insert_asc( root.left )
				else:
					root.left = TreeData( data, root )
			else:
				if ( root.right ):
					__insert_asc( root.right )
				else:
					root.right = TreeData( data, root )

		def __insert_des(root: TreeData) -> None:
			if ( root.data < data ):
				if ( root.left ):
					__insert_des( root.left )
				else:
					root.left = TreeData( data, root )
			else:
				if ( root.right ):
					__insert_des( root.right )
				else:
					root.right = TreeData( data, root )


		if ( self.root is None ):
			self.root = TreeData( data )
		else:
			if (self.order == 'asc'):
				__insert_asc( self.root )
			else:
				__insert_des( self.root )


	def InsertData_return(self, data: int):
		def __insert_asc(root: TreeData, parent: TreeData) -> TreeData:
			if ( root is None ):
				return TreeData( data, parent )
			elif ( root.data > data ):
				root.left = __insert_asc( root.left, root )
			else:
				root.right = __insert_asc( root.right, root )

			return root

		def __insert_des(root: TreeData, parent: TreeData) -> TreeData:
			if ( root is None ):
				return TreeData( data, parent )
			elif ( root.data < data ):
				root.left = __insert_des( root.left, root )
			else:
				root.right = __insert_des( root.right, root )

			return root


		if (self.order == 'asc'):
			self.root = __insert_asc( self.root, None )
		else:
			self.root = __insert_des( self.root, None )


	def __leftMost(self, root):
		curr = root.right
		while curr.left:
			curr = curr.left
		return curr


	def __rightMost(self, root):
		curr = root.left
		while (curr.right):
			curr = curr.right
		return curr


	def DeleteNode(self, delete: TreeData, most = 'right'):
		'''
		case 1: Delete Node has Two Childs
		case 2: Delete Node has only one child
			2-1 Delete Node has left child
			2-2 Delete Node has right child
		case 3: Delete Node has no child
		'''

		# case 1
		if delete.left and delete.right:
			if most is 'right':
				change = self.__rightMost( delete )
			else:
				change = self.__leftMost( delete )

			delete.data = change.data
			self.DeleteNode( change )

		# case 2, 3
		else:
			# case 2-1
			if delete.left:
				onlyChild = delete.left				
			# case 2-2
			elif delete.right:
				onlyChild = delete.right
			# case 3
			else:
				onlyChild = None

			if self.root is delete:
				self.root = onlyChild
				parent = None
			else:
				parent = delete.parent
				if delete.isLeftChild():
					delete.parent.left = onlyChild
				else:
					delete.parent.right = onlyChild

			if onlyChild:
				onlyChild.parent = parent


	def DeleteData(self, data):
		deleteNode = self.SearchNode( data )
		if deleteNode:
			self.DeleteNode( deleteNode )


	def SearchNode(self, data):
		curr = self.root
		while( curr ):
			if ( curr.data == data ):
				return curr
			elif ( curr.data > data ):
				if ( self.order == 'asc' ):
					curr = curr.left
				else:
					curr = curr.right
			else:
				if ( self.order == 'asc' ):
					curr = curr.right
				else:
					curr = curr.left

		return None


def printline( message ):
	line = '=' * 10
	strs = [ line, message, line ]
	print( ' '.join( strs ) )

if ( __name__ == '__main__' ):
	datas = [ 1, 2, 3, 4, 5, 6 ]
	bst = BinarySearchTree()

	# Check InsertNode
	printline('Check InsertNode')
	for data in [ 3, 2, 4, 6, 1, 5 ]:
		bst.InsertData( data )
		# bst.InsertData_return( data )
	bst.PrintTree()
	bst.PrintTree('level')


	# Check Parent
	printline('Check Parent')	
	for data in datas:
		node = bst.SearchNode( data ).parent
		if node:
			print( 'data: {}, parent: {}'.format( data, node.data ) )


	# Check SearchNode
	printline('Check SearchNode')
	for data in datas:
		print( "data: {}, find: {}".format( data, bst.SearchNode( data ).data ) )

	node = bst.SearchNode( 10 )
	if node:
		print( node.data )
	else:
		print( 'No data' )

	# Check DeleteNode
	printline('Check DeleteNode')
	delete = int( input() )
	bst.DeleteData( delete )
	bst.PrintTree()
	bst.PrintTree('level')

	for data in datas:
		node = bst.SearchNode( data )
		if node:
			if node.parent:
				parentData = node.parent.data
			else:
				parentData = 'root'
			print( 'data: {}, parent: {}'.format( data, parentData) )
