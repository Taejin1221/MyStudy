// Queue.java
class Data {
	int data;
	Data next;

	Data( int data ) {
		this.data = data;
		this.next = null;
	}
}

public class Queue {
	private Data front, back;
	private int size;

	Queue() {
		this.front = null;
		this.back = null;
		this.size = 0;
	}

	public void push(int x) {
		Data newNode = new Data( x );
		if ( this.front == null ) {
			this.front = newNode;
			this.back = newNode;
		} else {
			this.back.next = newNode;
			this.back = this.back.next
		}

		this.size++;
	}

	public int pop() {
		Data rtrnNode;

		if ( this.back == null ) {
			return -1;
		} else {
			rtrnNode = this.front;
			this.front = this.front.next;
		}

		this.size--;
		return rtrnNode.data;
	}

	public int size() {
		return this.size;
	}

	public int empty() {
		if ( this.size == 0 )
			return 1;
		else
			return 0;
	}

	public int front() {
		if ( this.front == null )
			return -1;
		else
			return this.front.data;
	}

	public int back() {
		if ( this.back == null )
			return -1;
		else
			return this.back.data;
	}
}