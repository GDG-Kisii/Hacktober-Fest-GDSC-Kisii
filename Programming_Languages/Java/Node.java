class Node{
    int data;
    Node left,right;
    Node(data){
        this.data=data;
        this.left =this.right = null;
    }

}
class BinaryTree
{
	// Root of Binary Tree
	Node root;

	// Constructors
	BinaryTree(int key)
	{
		root = new Node(key);
	}

	BinaryTree()
	{
		root = null;
	}

    //Tree Traversal[Preorder]
    public void preOrder(Node root,List<Integer> result){
        if (root == null){
            return;
        }
        res.add(root.data);
        //Recursive call
        preOrder(root.left);
        preOrder(root.right);
    }
	public static void main(String[] args)
	{
		BinaryTree tree = new BinaryTree();

		/*create root*/
		tree.root = new Node(1);
		tree.root.left = new Node(2);
		tree.root.right = new Node(3);
		tree.root.left.left = new Node(4);

        //List to store results
        List<Integer> result = new ArrayList<>();
        tree.preOrder(root,result);


        //Print results
        System.out.print(result)
}


//Contibuted by KmAlan