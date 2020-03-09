# TreeData.py
class TreeData:
	def __init__(self, data: int, parent = None):
		self.data = data
		self.parent = parent
		self.left, self.right = None, None

	def isLeftChild(self):
		return (self.parent.left is self)

	def isRightChlid(self):
		return (self.parent.right is self)

	def PrintData(self, endline = '\n') -> None:
		print('[', self.data, '] ', sep = '', end = endline)
