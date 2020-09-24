# Stack.py
class Stack:
	def __init__(self):
		self.__stck = []
		self.__size = 0


	def push(self, data):
		self.__stck.append(data)
		self.__size = self.__size + 1


	def pop(self):
		if self.__stck:
			self.__size = self.__size - 1
			return self.__stck.pop()
		else:
			return -1
			

	def size(self):
		return self.__size


	def empty(self):
		if self.__stck:
			return 0
		else:
			return 1


	def top(self):
		if self.__stck:
			return self.__stck[-1]
		else:
			return -1