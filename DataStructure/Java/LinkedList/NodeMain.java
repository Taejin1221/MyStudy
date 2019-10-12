package execute;

import singledlist.SingledNode;

public class NodeMain {

	public static void main(String[] args) {
		SingledNode head = null;
		
		SingledNode node1 = new SingledNode(1);
		SingledNode node2 = new SingledNode(2);
		SingledNode node3 = new SingledNode(3);
		
		node2.next = node3;
		node1.next = node2;
		head = node1;
		
		head.printList();
	}

}
