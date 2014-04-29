package com.zgz.it.study_java;

/**
 * 链表
 */
public class Link {
	class Node {
		private String data;
		private Node nextNode;
		
		Node(String data) {
			this.data = data;
			nextNode = null;
		}
		
		public void setData(String data) {
			this.data = data;
		}
		
		public void setNextNode(Node nextNode) {
			this.nextNode = nextNode;
		}
		
		public void add(Node node) {
			if (this.nextNode == null)
				this.nextNode = node;
			else
				this.nextNode.add(node);
		}
		
		public void delete(Node preNode, String data) {
			if (this.data.equals(data))
				preNode.nextNode = this.nextNode;
			else
				this.nextNode.delete(this, data);
		}

		public boolean contains(String data) {
			if (this.data.equals(data))
				return true;
			else
				if (this.nextNode == null)
					return false;
				else
					return this.nextNode.contains(data);
		}
		
		public void print() {
			System.out.print(this.data + "\t");
			if (this.nextNode != null) {
				this.nextNode.print();
			}
		}
	}
	
	private Node root = null;
	
	public void add(String data) {
		Node node = new Node(data);
		
		if (root == null) {
			root = new Node(data);
		} else {
			root.add(node);
		}
	}
	
	public void delete(String data) {
		if (root != null && root.contains(data))
			if (root.data.equals(data))
				root = root.nextNode;
			else
				root.nextNode.delete(root, data);
	}
	
	public void search(String data) {
		if (root != null && root.contains(data))
			System.out.println("在链表中找到 " + data);
		else
			System.out.println("在链表中没有找到 " + data);
	}

	public void print() {
		if (root != null) {
			root.print();
			System.out.println();
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Link link = new Link();
		
		link.add("A");
		link.add("B");
		link.add("C");
		link.add("D");
		link.add("E");

		link.print();
		
		link.search("A");
		link.search("B");
		link.search("C");
		link.search("D");
		link.search("E");
		link.search("F");
		link.search("G");
		
		link.delete("C");
		link.delete("A");
		link.delete("E");	
		link.delete("G");
		
		link.print();
	}

}
