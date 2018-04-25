package lab09;

import java.util.List;

public class BinarySearchTree {
	
	public class Node{
		private int key;
		private Node left;
		private Node right;
		
		public Node(int i){
			key = i;
			left = null;
			right = null;
		}
		
		Node root = new Node(0);
		//	
		
		public Node insertKey(Node root, int key){
			if(root == null){
				
			}
			
			
			return root;
		}
		
		public void insert(int i){
			root = insertKey(root, 1);
		}
		public Integer find(int i){
			
		}
		public List<Integer> getElems(){
			
		}
	}
	
}
