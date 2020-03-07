# Queue.py
class Queue:
	def __init__(self):
		self.__queue = []
		self.__size = 0


	def push(self, data):
		self.__queue.append( data )
		self.__size += 1


	def pop(self):
		if self.__size:
			self.__size -= 1
			return self.__queue.pop(0)
		else:
			return -1


	def size(self):
		return self.__size


	def empty(self):
		if self.__size:
			return 0
		else:
			return 1


	def front(self):
		if self.__size:
			return self.__queue[0]
		else:
			return -1


	def back(self):
		if self.__size:
			return self.__queue[-1]
		else:
			return -1
