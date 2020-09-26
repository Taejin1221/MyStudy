# ListNode.py
class Data:
	def __init__(self, data: int):
		self.value = data

	def PrintData(self, endline = '\n') -> None:
		print('[', self.value, '] ', sep = '', end = endline)

	def CompareData(self, opr: 'Data') -> int:
		return self.value - opr.value


class ListNode:
	def __init__(self, data: 'Data'):
		self.data = Data.Data(data)
		self.next = None


class SinglyList:
	def __init__(self):
		self.__head = None
		self.__tail = None
		self.len = 0

	def PrintList(self) -> None:
		curr = self.__head
		while (curr is not None):
			curr.data.PrintData(' ')
			print("->", end = ' ')
			curr = curr.next
		print('None')

	def InsertNodeFirst(self, data: 'Data') -> None:
		newNode = ListNode(data)
		self.len = self.len + 1

		if (self.__head is None):
			self.__head = self.__tail = newNode
		else:
			newNode.next = self.__head
			self.__head = newNode

	def InsertNodeLast(self, data: 'Data') -> None:
		newNode = ListNode(data)
		self.len = self.len + 1

		if (self.__head is None):
			self.__head = self.__tail = newNode
		else:
			self.__tail.next = newNode
			self.__tail = newNode

	def DeleteNodeFirst(self) -> None:
		pass

	def DeleteNodeLast(self) -> None:
		pass

	def MergeLists(self, list2: 'LinkedList'):
		pass

if (__name__ == '__main__'):
	list1 = SinglyList()
	option = 1
	while (option is not 0):
		option = int(input('option: '))
		data = int(input('input: '))

		if (option is 1): list1.InsertNodeFirst(data)
		elif (option is 2): list1.InsertNodeLast(data)

		list1.PrintList()
