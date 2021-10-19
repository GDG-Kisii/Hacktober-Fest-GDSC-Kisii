class Node{
    constructor(data){
        this.data=data;
        this.left=null;
        this.right=null;
    }
}

//Instance of Node class

root = new Node(1);
root.left	 = Node(2);
root.right	 = Node(3);
root.left.left = Node(4);

//Tree traversal[preorder]
const preOrder = (root) => {
    if(root == null){
        return;
    }
    console.log(root.data);
    //Recursive call
    preOrder(root.left);
    preOrder(root.right);
}
//Execute the program copy to your browser console
 preOrder(root);



 //Contibuted by KmAlan