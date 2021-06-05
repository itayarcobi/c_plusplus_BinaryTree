#pragma once
#include <iostream>
#include<bits/stdc++.h>
#include<unordered_map>
int mc_preorder=0;
int mc_inorder=0;
int mc_postorder=0;

namespace ariel{
template <typename T>
class BinaryTree{
struct Node {
		T val;
		//Node* godfather;
		Node* right_son;
		Node* left_son;

		Node(const T& v,
		 //Node* godfather,
		 Node* right_son,Node* left_son)
			: val(v), 
			//godfather(godfather),
			right_son(right_son),left_son(left_son){
            }
};
// fields
	//static inline int mc=0;
	Node* root;
	Node* node_addto;
	Node* copy_node;

public:	
BinaryTree()
:node_addto(nullptr),root(nullptr)
{
};
~BinaryTree(){
};

BinaryTree(const BinaryTree& other)
         {
		   this->root=Cpy(other.root);
			//std::cout<<copy_node->val<<std::endl;
         }
BinaryTree& operator=(const BinaryTree& other) {
			if(this==&other){
				return *this;
			}
		   this->root=Cpy(other.root);
		//    delete other.root;
			//std::cout<<copy_node->val<<std::endl;
    
             return *this;
        }
	
Node  * Cpy( Node* root ) { 

   if (root == NULL ) {

    return NULL;
   }

   Node *temp = new Node(root-> val,NULL,NULL);

   temp->left_son = Cpy( root -> left_son);   

   temp->right_son = Cpy(root -> right_son);  

   return temp;
}
BinaryTree (BinaryTree&& other)noexcept
         
    {
 		this->root=other.root;
		 other.root=nullptr;
       // cout << "Move Constructor for ";
        //      << *source.data << endl;
        // source.data = nullptr;
    }
 BinaryTree&  operator= ( BinaryTree&& other) noexcept{
			if(this==&other){
				return *this;
			}
		 this->root=other.root;
		 other.root=nullptr;
    
             return *this;
        }














	//-------------------------------------------------------------------
	// iterator related code:
	// inner class and methods that return instances of it)
	//-------------------------------------------------------------------
	 /////////////////////////////////////////////////////////// START OF CLASS ITERATOR//////////////////////////////////////////////////////////////////////////////
	class iterator_preorder {

	  private:
		Node* pointer_to_current_node;
		int pos;
		Node* pointer_to_root;
		int count;
	public:
		iterator_preorder(Node* ptr = nullptr,Node* root=nullptr)
			: pointer_to_current_node(ptr),pos(1),pointer_to_root(root),count(1)
		{	
			        preOrder(pointer_to_root);		
		}

		// Note that the method is const as this operator does not
		// allow changing of the iterator.
		// Note that it returns T& as it allows to change what it points to.
		// A const_iterator class will return const T&
		// and the method will still be const
		T& operator*() const {
			//return *pointer_to_current_node;
			return pointer_to_current_node->val;
		}

		T* operator->() const {
			return &(pointer_to_current_node->val);
		}

		// ++i;
		iterator_preorder& operator++() {
			count=1;
			pointer_to_current_node=nullptr;
			pos++;
			preOrder(pointer_to_root);
						return *this;
		
		}

		// i++;
		// Usually iterators are passed by value and not by const& as they are small.
		//const
		 iterator_preorder operator++(int) {
			iterator_preorder temp =*this;
			count=1;
			pointer_to_current_node=nullptr;
			pos++;
			preOrder(pointer_to_root);

			return temp;
		}

		bool operator==(const iterator_preorder& rhs) const {
			return pointer_to_current_node == rhs.pointer_to_current_node;
		}

		bool operator!=(const iterator_preorder& rhs) const {
			return pointer_to_current_node != rhs.pointer_to_current_node;
		}
		void preOrder(struct Node* node)
{
    if (node == NULL){
        return;
	}
    /* first print data of node */
   if(count==pos){
	//std::cout<<"counter is: "<<count<<" pos is: "<<pos<<" node val is: "<<node->val<<std::endl;
    pointer_to_current_node= node;
	}
	count++;
	if(count>pos){
		return;
	}
 
    /* then recur on left sutree */
    preOrder(node->left_son);
 
    /* now recur on right subtree */
    preOrder(node->right_son);
}
	};
	//////////////////////////////////////////////////////////////  // END OF CLASS ITERATOR///////////////////////////////////////////////////////////////////////////
class iterator_inorder {

	  private:
	      //std::stack<Node *> s;
		  //std::unordered_map<int,Node *> order;
		Node* pointer_to_current_node;
		int pos;
		Node* pointer_to_root;
		int count;

	public:

		iterator_inorder(Node* ptr = nullptr,Node* root=nullptr)
			: pointer_to_current_node(ptr),pos(1),pointer_to_root(root),count(1)
		{
			inOrder(pointer_to_root);

		}
		// Note that the method is const as this operator does not
		// allow changing of the iterator.
		// Note that it returns T& as it allows to change what it points to.
		// A const_iterator class will return const T&
		// and the method will still be const
		T& operator*() const {
			//return *pointer_to_current_node;
			return pointer_to_current_node->val;
		}

		T* operator->() const {
			return &(pointer_to_current_node->val);
		}

		// ++i;
		iterator_inorder& operator++() {
			count=1;
			pointer_to_current_node=nullptr;
			pos++;
			inOrder(pointer_to_root);
			
			return *this;
		}

		// i++;
		// Usually iterators are passed by value and not by const& as they are small.
				//const

		 iterator_inorder operator++(int) {
			iterator_inorder temp =*this;
			count=1;
			pointer_to_current_node=nullptr;
			pos++;
			inOrder(pointer_to_root);
			// count=1;
			 //pos++;
			// inOrder(pointer_to_root);
			return temp;
		}

		bool operator==(const iterator_inorder& rhs) const {
			return pointer_to_current_node == rhs.pointer_to_current_node;
		}

		bool operator!=(const iterator_inorder& rhs) const {
			return pointer_to_current_node != rhs.pointer_to_current_node;
		}
 void inOrder(struct Node* node)
{
    if (node == NULL){
        return ;
	}
    /* first recur on left child */
    inOrder(node->left_son);
 
    /* then print the data of node */

	//std::cout<<"counter is: "<<count<<" pos is: "<<pos<<" node val is: "<<node->val<<std::endl;
	if(count==pos){
	//std::cout<<"counter is: "<<count<<" pos is: "<<pos<<" node val is: "<<node->val<<std::endl;
    pointer_to_current_node= node;
	}
	count++;
	if(count>pos){
		return;
	}
    /* now recur on right child */
    inOrder(node->right_son);

}
	};  /////////////////////////////////////////////////////////// END OF CLASS ITERATOR//////////////////////////////////////////////////////////////////////////////
class iterator_postorder {

	  private:
		Node* pointer_to_current_node;
		int pos;
		Node* pointer_to_root;
		int count;
	
	public:

	iterator_postorder(Node* ptr = nullptr,Node* root=nullptr)
			: pointer_to_current_node(ptr),pos(1),pointer_to_root(root),count(1)
		{
			postOrder(pointer_to_root);

		}

		// Note that the method is const as this operator does not
		// allow changing of the iterator.
		// Note that it returns T& as it allows to change what it points to.
		// A const_iterator class will return const T&
		// and the method will still be const
		T& operator*() const {
			//return *pointer_to_current_node;
			return pointer_to_current_node->val;
			
		}

		T* operator->() const {
			return &(pointer_to_current_node->val);
		}

		// ++i;
		iterator_postorder& operator++() {
			count=1;
			pointer_to_current_node=nullptr;
			pos++;
			postOrder(pointer_to_root);
			
			return *this;
		}

		// i++;
		// Usually iterators are passed by value and not by const& as they are small.
				//const

		 iterator_postorder operator++(int) {
				iterator_postorder temp =*this;
			count=1;
			pointer_to_current_node=nullptr;
			pos++;
			postOrder(pointer_to_root);

			return temp;
		}

		bool operator==(const iterator_postorder& rhs) const {
			return pointer_to_current_node == rhs.pointer_to_current_node;
		}

		bool operator!=(const iterator_postorder& rhs) const {
			return pointer_to_current_node != rhs.pointer_to_current_node;
		}
void postOrder(struct Node* node)
{

    if (node == NULL){
        return;
	}
    // first recur on left subtree
    postOrder(node->left_son);
 
    // then recur on right subtree
    postOrder(node->right_son);

    // now deal with the node
	if(count==pos){
    pointer_to_current_node= node;
	}
	count++;
	// if(count>pos){
	// 	return;
	// }
}
 
 	};  // END OF CLASS ITERATOR
 /////////////////////////////////////////////////////////// END OF CLASS ITERATOR//////////////////////////////////////////////////////////////////////////////
BinaryTree& add_root(T root_val){

	Node* left_for_new =NULL;
	Node* right_for_new =NULL;

	if(this->root){

		this->root->val=root_val;
	}
	else{

  Node* R0 = new Node(root_val,right_for_new,left_for_new);
	this->root=R0;
	}
	// mc++;
	return *this;
}
BinaryTree& add_left(T father, T left_son_val){
	if (root==nullptr){
		throw "there's no root";
	}
	search_node(root,father);
	if(node_addto->val==father){
	
	Node* left_for_new =NULL;
	Node* right_for_new =NULL;
	if(node_addto->left_son){
		node_addto->left_son->val=left_son_val;
	}
	else{
		Node* new_left_son = new Node(left_son_val,right_for_new,left_for_new);
		node_addto->left_son=new_left_son;
	}
	}
	else{
			throw "cant find the father node";
	}
	
		return *this;

}
BinaryTree& add_right(T father, T right_son_val){
	if (root==nullptr){
		throw "there's no root";
	}
	search_node(root,father);
	if(node_addto->val==father){
	
	Node* left_for_new =NULL;
	Node* right_for_new =NULL;
	if(node_addto->right_son){
		node_addto->right_son->val=right_son_val;
	}
	else{
		Node* new_right_son = new Node(right_son_val,right_for_new,left_for_new);
		node_addto->right_son=new_right_son;
	}
	}
	else{	
		throw "cant find the father node";
	}
		return *this;

}
iterator_inorder begin(){

	return iterator_inorder{root,root};

}
iterator_inorder end(){			
	return iterator_inorder{nullptr};

}
iterator_preorder begin_preorder(){		
	 
	return iterator_preorder{root,root};

}
iterator_preorder end_preorder(){			
	return iterator_preorder{nullptr};

}
iterator_inorder begin_inorder(){		

	return iterator_inorder{root,root};

}
iterator_inorder end_inorder(){			
return iterator_inorder{nullptr};

}
iterator_postorder begin_postorder(){			

	return iterator_postorder{root,root};

}
iterator_postorder end_postorder(){			
	return iterator_postorder{nullptr};

}
 friend std::ostream& operator << (std::ostream& output, const BinaryTree& tree){
	 std::cout<<"in preorder: "<<std::endl;
	 printPreorder(tree.root);
	
	 return output;
  }


 
/* Given a binary tree, print its nodes in preorder*/
static void printPreorder(struct Node* node)
{
    if (node == NULL){
        return;
	}
    /* first print data of node */
    std::cout << node->val << " ";
 
    /* then recur on left sutree */
    printPreorder(node->left_son);
 
    /* now recur on right subtree */
    printPreorder(node->right_son);
}
 void search_node(struct Node* node,T val)
{
    if (node == NULL){
        return;
	}
    /* first recur on left child */
    search_node(node->left_son,val);
 
    /* then print the data of node */
	if(node->val==val){
    node_addto= node;
	}
    /* now recur on right child */
    search_node(node->right_son,val);
}
 void deep_copy(struct Node* node)
{
    if (node == NULL){
        return;
	}
    /* first recur on left child */
    deep_copy(node->left_son);
 
    /* then print the data of node */
	copy_node=node;
	
    /* now recur on right child */
    deep_copy(node->right_son);
}
};

};