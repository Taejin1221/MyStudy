# Data.py
class Data:
	def __init__(self, data: int):
		self.value = data

	def PrintData(self, endline = '\n') -> None:
		print('[', self.value, '] ', sep = '', end = endline)

	def CompareData(self, opr: 'Data') -> int:
		return self.value - opr.value