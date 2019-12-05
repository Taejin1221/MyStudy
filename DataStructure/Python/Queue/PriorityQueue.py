class PriorityQueue():
	def __init__(self):
		self.queue = [ None, ]
		self.size = 1


	def push(self, data):
		self.queue.append(data)
		self.size = self.size + 1
		me = self.size - 1
		mom = me // 2
		while (me != 1 and self.queue[mom] > self.queue[me]):
			self.queue[mom], self.queue[me] = self.queue[me], self.queue[mom]
			me = mom
			mom = me // 2


	def pop(self):
		last = self.size - 1
		self.queue[1], self.queue[last] = self.queue[last], self.queue[1]

		self.size = self.size - 1

		def Heapify(me):
			leftChild = me * 2
			rightChild = me * 2 + 1

			smaller = None
		
			if (leftChild >= self.size):
				return
			elif (rightChild >= self.size):
				smaller = leftChild
			else:
				if (self.queue[leftChild] < self.queue[rightChild]):
					smaller = leftChild
				else:
					smaller = rightChild

			if (self.queue[smaller] < self.queue[me]):
				self.queue[smaller], self.queue[me] = self.queue[me], self.queue[smaller]
				Heapify(smaller)

		Heapify(1)

		return self.queue.pop()
		

	def isEmpty(self) -> 'bool':
		if self.size > 1: return False
		else: return True


	def PrintQueue(self):
		print(self.queue)
