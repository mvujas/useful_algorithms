public class PriorityQueue {
	private static class Node {
		int value;
		Node left, right;
		Node(int val_) {
			value = val_;
			left = null;
			right = null;
		}
	}

	private Node root;
	PriorityQueue() {
		root = null;
	}

	public void push(int data) {
		if(empty())
			root = new Node(data);
		else 
			add(root, data);
	}

	private void add(Node current, int data) {
		if(current.value > data) {
			if(current.left == null)
				current.left = new Node(data);
			else
				add(current.left, data);
		}
		else {
			if(current.right == null)
				current.right = new Node(data);
			else
				add(current.right, data);
		}
	}

	public boolean empty() {
		return root == null;
	}

	public int pop() {
		int result;
		if(empty())
			throw new NullPointerException();
		else if(root.left == null) {
			result = root.value;
			root = root.right;
		}
		else if(root.left.left == null) {
			result = root.left.value;
			root.left = root.left.right;
		}
		else
			result = pop_(root.left);
		return result;
	}

	private int pop_(Node current) {
		int result;
		if(current.left.left == null) {
			result = current.left.value;
			current.left = current.left.right;
		}
		else
			result = pop_(current.left);
		return result;
	}

	public static void main(String[] args) {
		PriorityQueue pq = new PriorityQueue();

		int[] niz = {0, 10, 15, 22, 13, 24, 52, 36, 87, 92, -115, -1, -12, 1};
		for(int el: niz)
			pq.push(el);

		while(!pq.empty())
			System.out.println(pq.pop());
	}
}