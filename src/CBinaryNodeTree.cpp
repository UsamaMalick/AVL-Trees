// =============================================================================
// File: CBinaryNodeTree.tpp
// =============================================================================
// Implementation file for the class CBinaryNodeTree.tpp
// =============================================================================

#include <iostream>



// ==== CBinaryNodeTree<ItemType>::CBinaryNodeTree =============================
//
// This is the default constructor for CBinaryNodeTree.  It sets the root to
// nullptr.
//
// Input:
//       void
//
// Output:
//       Nothing
//
// =============================================================================
CBinaryNodeTree<ItemType>::CBinaryNodeTree() {
    this->m_rootPtr = nullptr;
}




// ==== CBinaryNodeTree<ItemType>::CBinaryNodeTree =============================
//
// This is the type constructor for CBinaryNodeTree.  It allocates a space for a
// CBinaryNode and sets it equal to m_rootPtr.  The new node will have it's
// right and left child pointers set to nullptr.
//
// Input:
//       rootItem   [IN]    - A const reference ItemType.
//
// Output:
//       Nothing
//
// =============================================================================
CBinaryNodeTree<ItemType>::CBinaryNodeTree(const ItemType &rootItem) {
    this->m_rootPtr = rootItem;
}




// ==== CBinaryNodeTree<ItemType>::CBinaryNodeTree =============================
//
// This is the type constructor for CBinaryNodeTree.  It allocates a space for a
// CBinaryNode and sets it equal to m_rootPtr.  The new node will have it's
// right and left child pointers set to rightTreePtr and leftTreePtr,
// respectively.
//
// Input:
//       rootItem      [IN]    - A const ItemType reference to initialize the
//                                  new node.
//       leftTreePtr   [IN]    - A const CBinaryNode<ItemType> pointer that
//                                  points to the left child.
//       rightTreePtr  [IN]    - A const CBinaryNode<ItemType> pointer that
//                                  points to the right child.
//
// Output:
//       Nothing
//
// =============================================================================
CBinaryNodeTree<ItemType>::CBinaryNodeTree(const ItemType &rootItem,
    const CBinaryNodeTree<ItemType> *leftTreePtr,
    const CBinaryNodeTree<ItemType> *rightTreePtr) {
    this->m_rootPtr = rootItem;
    this->m_rootPtr->SetLeftChildPtr(leftTreePtr->GetRootPtr());
    this->m_rootPtr->SetRightChildPtr(rightTreePtr->GetRootPtr());
}




// ==== CBinaryNodeTree<ItemType>::CBinaryNodeTree =============================
//
// This is the copy constructor for CBinaryNodeTree. It creates a deep copy of
// "tree."
//
// Input:
//       tree   [IN]    - A const templated CBinaryNodeTree that will be copied.
//
// Output:
//       Nothing
//
// =============================================================================
CBinaryNodeTree<ItemType>::CBinaryNodeTree(const CBinaryNodeTree<ItemType> &tree) {
    CBinaryNodeTree<ItemType> *newCopy = new CBinaryNodeTree<ItemType>();
    newCopy->SetRootPtr(CopyTree(rhs->GetRootPtr()));
    return newCopy;
}




// ==== CBinaryNodeTree<ItemType>::~CBinaryNodeTree ============================
//
// This is the destructor for CBinaryNodeTree.  It will release all the nodes
// from the heap.
//
// Input:
//       void
//
// Output:
//       Nothing
//
// =============================================================================
virtual CBinaryNodeTree<ItemType>::~CBinaryNodeTree() {
    if (this->m_rootPtr != nullptr) {
        this->Clear();
    }
}




// ==== CBinaryNodeTree<ItemType>::IsEmpty =====================================
//
// This function checks if the tree is empty or not.
//
// Input:
//       void
//
// Output:
//       Returns true if the tree is empty, otherwise false.
//
// =============================================================================
virtual bool IsEmpty() const{
    if (this->GetRootPtr() == nullptr) {
        return true;
    }
    return false;
}




// ==== CBinaryNodeTree<ItemType>::GetHeight ===================================
//
// This function returns the height of the tree.  It calls the protected member
// function GetHeightHelper to get the height from the root of the tree.
//
// Input:
//       void
//
// Output:
//       Returns an integer for the height of the tree.
//
// =============================================================================
virtual int CBinaryNodeTree<ItemType>::GetHeight() const{
    int height = 0;
    if (this->GetRootPtr() != nullptr) {
        height = GetHeightHelper(this->GetRootPtr());
    }
    return height;
}




// ==== CBinaryNodeTree<ItemType>::GetNumberOfNodes ============================
//
// This function returns the number of nodes in the tree.  It calls the
// protected member function GetNumberOfNodesHelper to get the number of nodes
// from the root of the tree.
//
// Input:
//       void
//
// Output:
//       Returns an integer for the number of nodes in the tree.
//
// =============================================================================
virtual int CBinaryNodeTree<ItemType>::GetNumberOfNodes() const{
    unsigned int count = 0;
    if (this->GetRootPtr() != nullptr) {
        count = GetNumberOfNodesHelper(this->GetRootPtr());
    }
    return count;
}




// ==== CBinaryNodeTree<ItemType>::GetRootData =================================
//
// This function returns the data item in the root of the tree.
//
// Throws a PrecondViolatedExcept if the root of the tree is empty (nullptr).
//
// Input:
//       void
//
// Output:
//       Returns an ItemType, which is the item in the root of the tree.
//
// =============================================================================
virtual ItemType GetRootData() const throw(PrecondViolatedExcept){
    root = this->GetRootPtr();
    if (root != nullptr) {
        root->GetItem()
    }
    else {
        cout<<"Exception";
        // throw exception
    }
}




// ==== CBinaryNodeTree<ItemType>::SetRootData =================================
//
// This function sets the data item in the root of the tree.
//
// Input:
//       newData    [IN]    - A const ItemType reference that has the new data
//                              value.
//
// Output:
//       void
//
// =============================================================================
virtual void SetRootData(const ItemType &newData) {
    root = this->GetRootPtr();
    if (root != nullptr) {
        root->SetItem(newData)
    }
}





// ==== CBinaryNodeTree<ItemType>::Clear =======================================
//
// This function removes all nodes from the heap and sets the root pointer to
// nullptr.  To make things easier, this function can call the member function
// DestroyTree.
//
// Input:
//       void
//
// Output:
//       void
//
// =============================================================================
virtual void Clear(){
    this->DestroyTree(this->GetRootPtr());
}




// ==== CBinaryNodeTree<ItemType>::Contains ====================================
//
// This function checks if a particular entry exists in the tree.
//
// Input:
//       anEntry    [IN]    - A const ItemType reference to check of its
//                              existence.
//
// Output:
//       Returns true if the entry is already in the tree, false otherwise.
//
// =============================================================================
virtual bool IsEmpty() const{
    root = this->GetRootPtr();
    if (root == nullptr) {
        return true;
    }
    return false;
}




// ==== CBinaryNodeTree<ItemType>::PreorderTraverse ============================
//
// This function traverses in pre-order by calling the protected member function
// Preorder.
//
// Input:
//       void Visit(ItemType &item) [IN]    - The function used to display (or
//                                              process) a node.
//
// Output:
//       void
//
// =============================================================================
 virtual void CBinaryNodeTree<ItemType>::PreorderTraverse(void Visit(const ItemType &item)) const{
     if (this->GetRootPtr() != nullptr) {
        Preorder(Visit, this->GetRootPtr());
    }
 }




// ==== CBinaryNodeTree<ItemType>::InorderTraverse =============================
//
// This function traverses in in-order by calling the protected member function
// Inorder.
//
// Input:
//       void Visit(ItemType &item) [IN]    - The function used to display (or
//                                              process) a node.
// Output:
//       void
//
// =============================================================================
virtual void CBinaryNodeTree<ItemType>::InorderTraverse(void Visit(const ItemType &item)) const{
    if (this->GetRootPtr() != nullptr) {
        Inorder(Visit, this->GetRootPtr());
    }
}



// ==== CBinaryNodeTree<ItemType>::PostorderTraverse ===========================
//
// This function traverses in post-order by calling the protected member
// function Postorder.
//
// Input:
//       void Visit(ItemType &item) [IN]    - The function used to display (or
//                                              process) a node.
// Output:
//       void
//
// =============================================================================
virtual void CBinaryNodeTree<ItemType>::PostorderTraverse(void Visit(const ItemType &item)) const{
    if (this->GetRootPtr() != nullptr) {
        Postorder(Visit, this->GetRootPtr());
    }  
}



// ==== CBinaryNodeTree<ItemType>::LevelorderTraverse ==========================
//
// This function traverses in level-order by calling the protected member
// function Levelorder for each level to process.
//
// Input:
//       void Visit(ItemType &item) [IN]    - The function used to display (or
//                                              process) a node.
// Output:
//       void
//
// =============================================================================
virtual void CBinaryNodeTree<ItemType>::LevelorderTraverse(void Visit(const ItemType &item)) const{
    if (this->GetRootPtr() != nullptr) {
        int level = this->GetHeight();
        for (int i = 1; i <= level; i++)
            Levelorder(Visit, treePtr, i);
    }     
}




// ==== CBinaryNodeTree<ItemType>::operator= ==================================
//
// This function assigns the right-hand side CBinaryNodeTree to the left-hand
// side CBinaryNodeTree.  Make sure to protect against assignment to self!
//
// Input:
//       rhs    [IN]    - A const templated CBinaryNodeTree to copy from.
//
// Output:
//       A templated CBinaryNodeTree reference object (the left-hand side of the
//          tree.
//
// =============================================================================
CBinaryNodeTree<ItemType>& CBinaryNodeTree<ItemType>::operator=(const CBinaryNodeTree<ItemType> &rhs) {
    CBinaryNodeTree<ItemType> *newCopy = new CBinaryNodeTree<ItemType>();
    newCopy->SetRootPtr(rhs->GetRootPtr());
    return newCopy;
}




// ==== CBinaryNodeTree<ItemType>::GetRootPtr ==================================
//
// This function returns m_rootPtr
//
// Input:
//       Nothing
//
// Output:
//       A CBinaryNode<ItemType> templated pointer that is the address of the
//          root pointer.
//
// =============================================================================





// ==== CBinaryNodeTree<ItemType>::SetRootPtr ==================================
//
// This function sets m_rootPtr
//
// Input:
//       rootPtr    [IN]    - A CBinaryNode<ItemType> pointer.
// Output:
//       Nothing
//
// =============================================================================





// ==== CBinaryNodeTree<ItemType>::GetParentNode ===============================
//
// This function searches for the parent node of any node in the tree.
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to start the
//                              search of the parent node.
//      nodePtr     [IN]    - A templated CBinaryNode pointer to find the parent
//                              of.
//
// Output:
//       A CBinaryNode<ItemType> templated pointer that is the address of the
//          parent node pointer.
//
// =============================================================================





// ==== CBinaryNodeTree<ItemType>::GetHeightHelper =============================
//
// This function finds the height starting at subTreePtr (this could be root or
// any other node within the tree).
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to find the height
//                              from.
//
// Output:
//       An int that is the height from subTreePtr.
//
// =============================================================================
int CBinaryNodeTree<ItemType>::GetHeightHelper(CBinaryNode<ItemType> *subTreePtr) const;
{
    if (subTreePtr == nullptr)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = GetHeightHelper(subTreePtr->GetLeftChildPtr());
        int rheight = GetHeightHelper(subTreePtr->GetRightChildPtr());
 
        /* use the larger one */
        if (lheight > rheight)
        {
            return(lheight + 1);
        }
        else {
          return(rheight + 1);
        }
    }
}




// ==== CBinaryNodeTree<ItemType>::GetNumberOfNodesHelper ======================
//
// This function finds the number of nodes starting at subTreePtr (this could be
// root or any other node within the tree).
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to find the number
//                              of nodes from.
//
// Output:
//       An int that represents the number of nodes from subTreePtr.
//
// =============================================================================
int CBinaryNodeTree<ItemType>::GetNumberOfNodesHelper(CBinaryNode<ItemType> *subTreePtr) const{
    unsigned int count = 1;
    if (subTreePtr->GetLeftChildPtr() != nullptr) {
       count += binarytree_count(subTreePtr->GetLeftChildPtr());
    }
    if (subTreePtr->GetRightChildPtr() != nullptr) {
        count += binarytree_count(subTreePtr->GetRightChildPtr());
    }
    return count;
}




// ==== CBinaryNodeTree<ItemType>::FindMinNode =================================
//
// This function finds the minimum ItemType Node in the tree starting from
// subTreePtr. If there is no minimum ItemType Node found, the function returns
// nullptr.
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to find the
//                              minimum node from.
//
// Output:
//       A templated CBinaryNode<ItemType> pointer that points to the minimum
//          node.
//
// =============================================================================
CBinaryNode<ItemType>* CBinaryNodeTree<ItemType>::FindMinNode(CBinaryNode<ItemType> *subTreePtr) {
    // Base case
    if (subTreePtr == nullptr) {
        return new CBinaryNode<ItemType>(INT_MAX);
    }

    CBinaryNode<ItemType>* res = subTreePtr;
    CBinaryNode<ItemType>* lres = FindMinNode(subTreePtr->GetLeftChildPtr());
    CBinaryNode<ItemType>* rres = FindMinNode(subTreePtr->GetRightChildPtr());
    if (lres->GetItem() < res->GetItem())
        res = lres;
    if (rres->GetItem() < res->GetItem())
        res = rres;
    return res;
}





// ==== CBinaryNodeTree<ItemType>::FindMaxNode =================================
//
// This function finds the maximum ItemType Node in the tree starting from
// subTreePtr. If there is no maximum ItemType Node found, the function returns
// nullptr.
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to find the
//                              maximum node from.
//
// Output:
//       A templated CBinaryNode<ItemType> pointer that points to the maximum
//          node.
//
// =============================================================================
CBinaryNode<ItemType>* CBinaryNodeTree<ItemType>::FindMaxNode(CBinaryNode<ItemType> *subTreePtr) {
    // Base case
    if (subTreePtr == nullptr) {
        return new CBinaryNode<ItemType>(INT_MIN);
    }

    CBinaryNode<ItemType>* res = subTreePtr;
    CBinaryNode<ItemType>* lres = FindMaxNode(subTreePtr->GetLeftChildPtr());
    CBinaryNode<ItemType>* rres = FindMaxNode(subTreePtr->GetRightChildPtr());
    if (lres->GetItem() > res->GetItem())
        res = lres;
    if (rres->GetItem() > res->GetItem())
        res = rres;
    return res;
}




// ==== CBinaryNodeTree<ItemType>::CopyTree ====================================
//
// This function copies a tree using a deep copy.
//
// Input:
//      oldTreeRootPtr  [IN]    - A templated CBinaryNode pointer to copy from.
//
// Output:
//       A templated CBinaryNode<ItemType> pointer that points to the new root.
//
// =============================================================================
CBinaryNode<ItemType>* CBinaryNodeTree<ItemType>::CopyTree(const CBinaryNode<ItemType> *oldTreeRootPtr) {
	if(oldTreeRootPtr == nullptr) {
		return nullptr;
	}
    CBinaryNode<ItemType>* temp = new CBinaryNode<ItemType>;
    temp->SetItem(oldTreeRootPtr->GetItem());
    temp->SetLeftChildPtr(CopyTree(oldTreeRootPtr->GetLeftChildPtr()));
    temp->SetRightChildPtr(CopyTree(oldTreeRootPtr->GetRightChildPtr()));
    return temp;
}






// ==== CBinaryNodeTree<ItemType>::DestroyTree =================================
//
// This function destroys a tree.  In other words, it releases the memory from
// the heap.
//
// Input:
//       CBinaryNode<ItemType> *subTreePtr [IN/OUT] - The tree to destroy.
//
// Output:
//       void
//
// =============================================================================
void CBinaryNodeTree<ItemType>::DestroyTree(CBinaryNode<ItemType> *subTreePtr) {
    if (subTreePtr == nullptr) return; 
  
    /* first delete both subtrees */
    DestroyTree(subTreePtr->GetLeftChildPtr()); 
    DestroyTree(subTreePtr->GetRightChildPtr()); 

    delete subTreePtr;
}




// ==== CBinaryNodeTree<ItemType>::Preorder ====================================
//
// This function traverses the tree in pre-order.
//
// Input:
//      void Visit(ItemType &item) [IN]    - The function used to display (or
//                                              process) a node.
//      treePtr                    [IN]    - The tree to process.
//
// Output:
//       void
//
// =============================================================================
void CBinaryNodeTree<ItemType>::Preorder(void Visit(const ItemType &item), CBinaryNode<ItemType> *treePtr) const {
    if (treePtr == nullptr){
        return;
    }

    Visit(treePtr->GetItem());
    Preorder(treePtr->GetLeftChildPtr());
    Preorder(treePtr->GetRightChildPtr());
}




// ==== CBinaryNodeTree<ItemType>::Inorder ====================================
//
// This function traverses the tree in in-order.
//
// Input:
//      void Visit(ItemType &item) [IN]    - The function used to display (or
//                                              process) a node.
//      treePtr                    [IN]    - The tree to process.
//
// Output:
//       void
//
// =============================================================================
void CBinaryNodeTree<ItemType>::Inorder(void Visit(const ItemType &item), CBinaryNode<ItemType> *treePtr) const {
    if (treePtr == nullptr){
        return;
    }

    Inorder(treePtr->GetLeftChildPtr());
    Visit(treePtr->GetItem());
    Inorder(treePtr->GetRightChildPtr());
}



// ==== CBinaryNodeTree<ItemType>::Postorder ===================================
//
// This function traverses the tree in post-order.
//
// Input:
//      void Visit(ItemType &item) [IN]    - The function used to display (or
//                                              process) a node.
//      treePtr                    [IN]    - The tree to process.
//
// Output:
//       void
//
// =============================================================================
void CBinaryNodeTree<ItemType>::Postorder(void Visit(const ItemType &item), CBinaryNode<ItemType> *treePtr) const {
    if (treePtr == nullptr){
        return;
    }

    Postorder(treePtr->GetLeftChildPtr());
    Postorder(treePtr->GetRightChildPtr());
    Visit(treePtr->GetItem());
}




// ==== CBinaryNodeTree<ItemType>::Levelorder ==================================
//
// This function traverses the tree in level-order.
//
// Input:
//      void Visit(ItemType &item) [IN]    - The function used to display (or
//                                              process) a node.
//      treePtr                    [IN]    - The tree to process.
//              level                      [IN]    - The height of the tree (total
//                                              levels to process).
//
// Output:
//       void
// =============================================================================

//level is height of the tree
void CBinaryNodeTree<ItemType>::Levelorder(void Visit(const ItemType &item),CBinaryNode<ItemType> *treePtr, int level) const
{
    if (treePtr == nullptr)
        return;
    if (level == 1)
        Visit(treePtr->GetItem());
    else if (level > 1)
    {
        Levelorder(Visit, treePtr->GetLeftChildPtr(), level-1);
        Levelorder(Visit, treePtr->GetRightChildPtr(), level-1);
    }
}