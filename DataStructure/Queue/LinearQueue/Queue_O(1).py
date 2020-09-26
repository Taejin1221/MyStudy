# Queue_O(1).py
class Data:
	def __init__(self, data):
		self.data = data
		self.next = None


class Queue:
	def __init__(self):
		self.front = None
		self.back = None
		self.size = 0


	def Enqueue(self, data):
		newNode = Data( data )
		self.size += 1

		if self.back:
			self.back.next = newNode
			self.back = self.back.next
		else:
			self.front = newNode
			self.back = newNode


	def Dequeue(self):
		if self.front:
			rtrnNode = self.front
			self.front = self.front.next
			self.size -= 1
		else:
			return -1

		return rtrnNode.data


	def Size(self):
		return self.size


	def Emtpy(self):
		if self.size:
			return 0
		else:
			return 1


	def Front(self):
		if self.front:
			return self.front.data
		else:
			return -1


	def Back(self):
		if self.back:
			return self.back.data
		else:
			return -1
