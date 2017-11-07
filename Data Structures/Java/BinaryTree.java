class BinaryTree {
  class Node {
    int data;
    Node left, right;

    Node(int n) {
      this.data = n;
      this.left = null;
      this.right = null;
    }
  }

  Node root;
  BinaryTree() {
    this.root = null;
  }

  boolean empty() {
    return this.root == null;
  }

  void insert(int n) {
    if(this.empty())
      this.root = new Node(n);
    else
      this._insert(n, this.root);
  }

  private void _insert(int n, Node curr) {
    if(n < curr.data) {
      if(curr.left == null)
        curr.left = new Node(n);
      else
        this._insert(n, curr.left);
    }
    else {
      if(curr.right == null)
        curr.right = new Node(n);
      else
        this._insert(n, curr.right);
    }
  }

  void show() {
    if(this.root == null) {
      System.out.println(".");
      return;
    }
    System.out.print(this.root.data + " ");
    this._show(this.root.left);
    System.out.print(" ");
    this._show(this.root.right);
    System.out.println();
  }

  private void _show(Node curr) {
    if(curr == null) {
        System.out.print(".");
        return;
    }
    System.out.print("(" + curr.data +  " ");
    this._show(curr.left);
    System.out.print(" ");
    this._show(curr.right);
    System.out.print(")");
  }

  Node find(int n) {
    return this._find(n, this.root);
  }

  private Node _find(int n, Node curr) {
    if(curr == null || curr.data == n) return curr;
    return this._find(n, (n < curr.data) ? curr.left : curr.right);
  }


  public static void main(String[] args) {
    BinaryTree a = new BinaryTree();
    a.insert(5);
    a.insert(1);
    a.insert(2);
    a.insert(10);
    a.insert(7);
    a.insert(5);
    a.insert(12);
    a.insert(-1);
    a.insert(0);
    a.show();

    Node target = a.find(10);
    a._show(target);
  }
}
