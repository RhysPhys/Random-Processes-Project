#include <iostream>

// BST struct without a parent pointer
struct BST{
	int data;
	struct BST* left;
	struct BST* right;
	struct BST* parent;
};


struct BST* newNode(int x){
	BST* temp = new BST;
	temp->left = nullptr;
	temp->right = nullptr;
	temp->parent = nullptr;
	temp->data=x;
}

// Search for the BST
struct BST* search( BST* root,int x){

	if( root->data == x){
		return root;
	}

	if (root->data > x){
		return search(root->left,x);
	}else{
		return search(root->right,x);
	}

}

//Assuming we don't have an element already
struct BST* insert(BST* root, int x)
{	

	if(root == nullptr){
	BST* temp = newNode(x);
	return temp;
	}

	 // if given key is less than the root node, recur for left subtree
    if (x < root->data ){
    	if(root->left )
        root->left = insert(root->left, x);

        return root;
    }
 
    // if given key is more than the root node, recur for right subtree
    else{
        root->right = insert(root->right, x);
        return root;
    }
}
  
//inorder traverse
void traverse_in_order( BST* root)
{
	if(root != nullptr){
		traverse_in_order(root->left);
		std::cout<<root->data;
		traverse_in_order(root->right);
	}
}

//Pre order
void traverse_pre_order( BST* root)
{
	if(root != nullptr){
		std::cout<<root->data;
		traverse_pre_order(root->left);
		traverse_pre_order(root->right);
	}
}


//Post order
void traverse_post_order( BST* root)
{
	if(root != nullptr){
		traverse_post_order(root->left);
		traverse_post_order(root->right);
		std::cout<<root->data;
	}
}


struct BST* lastElementLeftSubtree (BST* root){
	if(root->left ==nullptr){
		return root;
	}
	return lastElementLeftSubtree( root->left);
}

struct BST* only_child (BST* root){
	if(root->left != nullptr && root->right == nullptr){
		return root->left;
	}else if(root->left == nullptr && root->right != nullptr) {
		return root->right;
	}
}

struct BST* search_sucessor( BST* root){
 
if(root->right->left != nullptr){
	return lastElementLeftSubtree(root->right);
}else{
	return root->right;
}

}



// apperantly this is hard, depending on how many child the root has it is different
void deletes( BST* root, int x)
{
	BST* NodeToDelete = search(root, x);
	if(root->left == nullptr && root->right == nullptr) {
		//delete NodeToDelete;
		NodeToDelete = nullptr;
	}else if(root->left == nullptr || root->right == nullptr){
		BST* NodeTSwap = search_sucessor(NodeToDelete);	
		NodeToDelete = NodeTSwap;
		delete NodeToDelete;
	}else{
		BST* temp = lastElementLeftSubtree(NodeToDelete);
		NodeToDelete->data = temp->data;
		temp= nullptr;
		delete temp;
		//temp->data= NULL;
	}
}

int main(){

//Declare a couple of test variables
BST* root = newNode(20);
BST* right = newNode(21);
BST* left = newNode(19);




// Assign some values to it
root->left = left;
root->right= right;


//test whether the two pointers match up
BST* test = search(root,19);


//Inserting new Nodes
BST* first = insert(root,3);
BST* second =  insert(root,123);
BST* third =  insert(root,13);
BST* f =  insert(root,14);
BST* g =  insert(root,12);

traverse_in_order(root);
std::cout<<""<<std::endl;
traverse_pre_order(root);
std::cout<<"d"<<std::endl;
traverse_post_order(root);
//BST* leftmost = lastElementLeftSubtree(root);


BST* gg =  insert(root,123);
gg->left == nullptr;
if(gg->left == nullptr){
	std::cout<<"yes"<<std::endl;
}else{
	std::cout<<"no"<<std::endl;
}
std::cout<<gg->left<<std::endl;

deletes(root,123);
std::cout<<""<<std::endl;
traverse_in_order(root);

deletes(root,14);
std::cout<<""<<std::endl;
traverse_in_order(root);


}