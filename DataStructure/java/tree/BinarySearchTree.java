package tree;

import java.Data

/**
 * Data를 사전순으로 정렬하여 출력하기 위한 이진 탐색트리 클래스.
 * @version 1.1
 * @author Taejin
 */

public class BinarySearchTree {
	/** Data 클래스 속성, Data 클래스는 abstract, 상속하여 사용바람. */
	private Data data;
	/** Left Node member of Tree */
	private BinarySearchTree left;
	/** Right Node member of Tree */
	private BinarySearchTree right;
	
	/**
	 * 트리 생성자
	 * @param data
	 */
	public BinarySearchTree(Data data) {
		this.data = data;
		this.left = null;
		this.right = null;
	}
	
	/**
	 * 트리 생성자
	 * @param data Instance of Data class
	 * @param str 이 생성자로 생성할 객체가 루트인경우 time이 이후에 겹칠 경우가 있어 decrement 해줌
	 * @see CharCount#main
	 */
	public BinarySearchTree(Data data, String str) {
		this(data);
		if (str.equals("root")) {
			this.data.DecrementTime();
		}
	}
	
	/**
	 * 만들어진 이진탐색트리 출력 (중위순회(inorder traversal))
	 */
	public void printTree() {
		if (this.left != null)
			this.left.printTree();
		System.out.println(this.data);
		if (this.right != null)
			this.right.printTree();
	}
	
	/**
	 * Node를 이진탐색트리에 맞게 Insert
	 * @param data 추가할 노드의 Data
	 */
	public void InsertNode(Data data) {
		int compare = this.data.compare(data);
		if (compare == 0) {
			this.data.IncrementTime();
		} else if (compare > 0) {
			if (this.left == null) // 만약 자신의 왼쪽 노드가 null일시 왼쪽 노드에 새노드 할당
				this.left = new BinarySearchTree(data);
			else
				this.left.InsertNode(data);
		} else {
			if (this.right == null) // 만약 자신의 오른쪽 노드가 null일시 오른쪽 노드에 새노드 할당
				this.right = new BinarySearchTree(data);
			else
				this.right.InsertNode(data);
		}
	}
}
