 // ============================================================================
// File: CBST.tpp
// ============================================================================
// Implementation file for the class CBST
// ============================================================================
#include "CBST.h"
#include<iostream>
#include<queue>
using namespace std;



// ==== CBST<ItemType>::CBST ===================================================
//
// This is the default constructor for CBST<ItemType>. It sets the root to
// nullptr.
//
// Input:
//       void
//
// Output:
//       Nothing
//
// =============================================================================
template<class ItemType>
CBST<ItemType>::CBST(): CBinaryNodeTree<ItemType>() {}




// ==== CBST<ItemType>::CBST ===================================================
//
// This is the type constructor for CBST<ItemType>.  It allocates a space for a
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
 template<class ItemType>
CBST<ItemType>::CBST(const ItemType &rootItem): CBinaryNodeTree<ItemType>(rootItem) {}




// ==== CBST<ItemType>::CBST ===================================================
//
// This is the copy constructor for CBST<ItemType>. It creates a deep copy of
// "tree."
//
// Input:
//       tree   [IN]    - A const templated CBST that will be copied.
//
// Output:
//       Nothing
//
// =============================================================================
 template<class ItemType>
CBST<ItemType>::CBST(const CBST<ItemType> &tree) {
    this->SetRootPtr(this->CopyTree(tree.GetRootPtr()));
}




// ==== CBST<ItemType>::~CBST ==================================================
//
// This is the destructor for CBST<ItemType>.  It will release all the nodes
// from the heap.
//
// Input:
//       void
//
// Output:
//       Nothing
//
// =============================================================================
 template<class ItemType>
 CBST<ItemType>::~CBST() {
    if (this->GetRootPtr() != nullptr) {
        this->Clear();
    }
}




// ==== CBST<ItemType>::Add ====================================================
//
// This function adds an item to a tree.  Calls the PlaceNode function to add
// the node to the tree to make sure it is balanced using AVL.
//
// Input:
//       newEntry   [IN]    - A const ItemType reference to the new entry to be
//                              added to the tree.
//
// Output:
//       Returns true if successful, otherwise false.
//
// =============================================================================
template<class ItemType>
bool CBST<ItemType>::Add(const ItemType &newEntry){
    CBinaryNode<ItemType> *NewNode = new CBinaryNode<ItemType>(newEntry);

    CBinaryNode<ItemType> *root =  PlaceNode(this->GetRootPtr(), NewNode);

    if (root == nullptr){
        return false;
    }
    this->SetRootPtr(root);
    return true;
}

 

// ==== CBST<ItemType>::Remove =================================================
//
// This function removes an entry (a node), if it exists, from the tree.
//
// Input:
//       anEntry    [IN]    - A const ItemType reference to the new entry to be
//                              added to the tree.
//
// Output:
//       Returns true if successful, otherwise false.
//
// =============================================================================
 template<class ItemType>
 bool CBST<ItemType>::Remove(const ItemType &anEntry) {
    bool retFlag = false;
    this->RemoveValue(this->GetRootPtr(), anEntry, retFlag);
    return retFlag;
}




// ==== CBST<ItemType>::operator= ==============================================
//
// This function assigns the right-hand side CBST to the left-hand side CBST.
// Make sure to protect against assignment to self!
//
// Input:
//       rhs    [IN]    - A const templated CBST to copy from.
// Output:
//       A templated CBST reference object (the left-hand side of the tree.
//
// =============================================================================
 template<class ItemType>
CBST<ItemType>& CBST<ItemType>::operator=(const CBST<ItemType> &rhs) {
    CBST<ItemType> *newCopy = new CBST<ItemType>();
    newCopy->SetRootPtr(rhs->GetRootPtr());
    return newCopy;
}




// ==== CBST<ItemType>::PlaceNode ==============================================
//
// This function adds a node in the tree. It makes sure that the same node value
// is not added twice.  Furthermore, as soon as it adds a node, it makes sure
// the tree is still AVL balanced.
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to start the
//                              search of where to add the node.
//      nodePtr     [IN]    - A templated CBinaryNode pointer node that will be
//                              added to the tree.
// Output:
//       A CBinaryNode<ItemType> templated pointer that is the address of
//          the updated parent node pointer (after any shifts caused from AVL
//          balancing, parent node may need updating).
//
// =============================================================================
 template<class ItemType>
int CBST<ItemType>::difference(CBinaryNode<ItemType> *subTreePtr) {
    if (subTreePtr == nullptr) 
        return 0;
    int LeftHeight = CBinaryNodeTree<ItemType>::GetHeightHelper(subTreePtr->GetLeftChildPtr());
    int RightHeight = CBinaryNodeTree<ItemType>::GetHeightHelper(subTreePtr->GetRightChildPtr());
    int bal_factor = LeftHeight - RightHeight;
    return bal_factor;
}

 template<class ItemType>
CBinaryNode<ItemType>* CBST<ItemType>::PlaceNode(CBinaryNode<ItemType> *subTreePtr,CBinaryNode<ItemType> *newNode){
    if (subTreePtr == nullptr){
        return newNode;
    }

     if (newNode->GetItem() < subTreePtr->GetItem())
         subTreePtr->SetLeftChildPtr(PlaceNode(subTreePtr->GetLeftChildPtr(), newNode));
     else if (newNode->GetItem() > subTreePtr->GetItem())
         subTreePtr->SetRightChildPtr(PlaceNode(subTreePtr->GetRightChildPtr(), newNode));
     else // Equal keys are not allowed in BST
         return nullptr;

    int bal_factor = difference(subTreePtr);

//    if (bal_factor > 1) {
//      if (difference(subTreePtr->GetLeftChildPtr()) > 0)
//        subTreePtr = LeftRotate(subTreePtr);
//      else
//        subTreePtr = LeftRightRotate(subTreePtr);
//   } else if (bal_factor < -1) {
//      if (difference(subTreePtr->GetRightChildPtr()) > 0)
//        subTreePtr = RightLeftRotate(subTreePtr);
//      else
//        subTreePtr = RightRotate(subTreePtr);
//   }

     // Left Left Case
     if (bal_factor > 1 && newNode->GetItem() < subTreePtr->GetLeftChildPtr()->GetItem())
         return RightRotate(subTreePtr);

     // Right Right Case
     if (bal_factor < -1 && newNode->GetItem() > subTreePtr->GetRightChildPtr()->GetItem())
         return LeftRotate(subTreePtr);

     // Left Right Case
     if (bal_factor > 1 && newNode->GetItem() > subTreePtr->GetLeftChildPtr()->GetItem())
     {
         return LeftRightRotate(subTreePtr);
     }

     // Right Left Case
     if (bal_factor < -1 && newNode->GetItem() < subTreePtr->GetRightChildPtr()->GetItem())
     {
         return RightLeftRotate(subTreePtr);
     }

   return subTreePtr;

}




// ==== CBST<ItemType>::LeftRotate =============================================
//
// This function rotates the nodes to the left.
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to start the
//                              rotation.
// Output:
//       An updated CBinaryNode<ItemType> templated pointer that is the new
//          "subTreePtr" after the rotation.
//
// =============================================================================
 template<class ItemType>
CBinaryNode<ItemType>* CBST<ItemType>::LeftRotate(CBinaryNode<ItemType> *subTreePtr) {
    CBinaryNode<ItemType> *y = subTreePtr->GetRightChildPtr();
    CBinaryNode<ItemType> *T2 = y->GetLeftChildPtr();
 
    // Perform rotation
    y->SetLeftChildPtr(subTreePtr);
    subTreePtr->SetRightChildPtr(T2);
    return y;
}




// ==== CBST<ItemType>::RightRotate ============================================
//
// This function rotates the nodes to the right.
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to start the
//                              rotation.
// Output:
//       An updated CBinaryNode<ItemType> templated pointer that is the new
//          "subTreePtr" after the rotation.
//
// =============================================================================
 template<class ItemType>
CBinaryNode<ItemType>* CBST<ItemType>::RightRotate(CBinaryNode<ItemType> *subTreePtr) {
    CBinaryNode<ItemType> *x = subTreePtr->GetLeftChildPtr();
    CBinaryNode<ItemType> *T2 = x->GetRightChildPtr();
 
    // Perform rotation
    x->SetRightChildPtr(subTreePtr);
    subTreePtr->SetLeftChildPtr(T2);

    return x;
}




// ==== CBST<ItemType>::LeftRightRotate ========================================
//
// This function rotates the nodes to the left and then right.  In other words,
// it rotates the left child of subTreePtr to the left and then rotates
// subTreePtr to the right.
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to start the
//                              rotation.
// Output:
//       An updated CBinaryNode<ItemType> templated pointer that is the new
//          "subTreePtr" after the rotation.
//
// =============================================================================
 template<class ItemType>
CBinaryNode<ItemType>* CBST<ItemType>:: LeftRightRotate(CBinaryNode<ItemType> *subTreePtr) {
    CBinaryNode<ItemType> *a = subTreePtr->GetLeftChildPtr();
    CBinaryNode<ItemType> *b = this->LeftRotate(a);

    subTreePtr->SetLeftChildPtr(b);
    CBinaryNode<ItemType> *c = this->RightRotate(subTreePtr);

    return c;
}



// ==== CBST<ItemType>::RightLeftRotate ========================================
//
// This function rotates the nodes to the right and then left.  In other words,
// it rotates the right child of subTreePtr to the right and then rotates
// subTreePtr to the left.
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to start the
//                              rotation.
// Output:
//       An updated CBinaryNode<ItemType> templated pointer that is the new
//          "subTreePtr" after the rotation.
//
// =============================================================================
 template<class ItemType>
CBinaryNode<ItemType>* CBST<ItemType>:: RightLeftRotate(CBinaryNode<ItemType> *subTreePtr) {
    CBinaryNode<ItemType> *a = subTreePtr->GetRightChildPtr();
    CBinaryNode<ItemType> *b = this->RightRotate(a);

    subTreePtr->SetRightChildPtr(b);
    CBinaryNode<ItemType> *c = this->LeftRotate(subTreePtr);

    return c;
}




// ==== CBST<ItemType>::RemoveValue ============================================
//
// This function removes a value from the tree.  It also keeps the tree AVL
// balanced after each removal.
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to start the
//                              search of the node to remove.
//      target      [IN]    - A const ItemType value that we want to remove from
//                              the tree.
//      success     [OUT]   - A bool value that is marked true if sucessful,
//                              false otherwise.
//
// Output:
//       An updated CBinaryNode<ItemType> templated pointer that is the new
//          "subTreePtr" after the removal.
//
// =============================================================================
 template<class ItemType>
 CBinaryNode<ItemType>* CBST<ItemType>::RemoveValue(CBinaryNode<ItemType> *subTreePtr, const ItemType &target, bool &success) {
    
    if (subTreePtr == nullptr) 
        return subTreePtr; 
  
    if ( subTreePtr->GetItem() > target)
        subTreePtr->SetLeftChildPtr(RemoveValue(subTreePtr->GetLeftChildPtr(), target, success)); 
  
    else if( subTreePtr->GetItem() < target)
        subTreePtr->SetRightChildPtr(RemoveValue(subTreePtr->GetRightChildPtr(), target, success)); 
    else
    { 
        if( (subTreePtr->GetLeftChildPtr() == nullptr) ||
            (subTreePtr->GetRightChildPtr() == nullptr) ) 
        { 
            CBinaryNode<ItemType> *temp = subTreePtr->GetLeftChildPtr() ? 
                                            subTreePtr->GetLeftChildPtr() : 
                                            subTreePtr->GetRightChildPtr(); 
            if (temp == nullptr) 
            { 
                temp = subTreePtr; 
                subTreePtr = nullptr; 
            } 
            else
                *subTreePtr = *temp; 
        } 
        else
        { 
            CBinaryNode<ItemType> *temp = this->FindMinNode(subTreePtr->GetRightChildPtr()); 
            subTreePtr->SetItem(temp->GetItem()); 
            subTreePtr->SetRightChildPtr(RemoveValue(subTreePtr->GetRightChildPtr(), temp->GetItem(), success));
        } 
    } 

    int bal_factor = difference(subTreePtr);

    if (bal_factor > 1) {
      if (difference(subTreePtr->GetLeftChildPtr()) > 0)
        subTreePtr = LeftRotate(subTreePtr);
      else
        subTreePtr = LeftRightRotate(subTreePtr);
    } else if (bal_factor < -1) {
      if (difference(subTreePtr->GetRightChildPtr()) > 0)
        subTreePtr = RightLeftRotate(subTreePtr);
      else
        subTreePtr = RightRotate(subTreePtr);
    }

    // Left Left Case
    if (bal_factor > 1 && difference(subTreePtr->GetLeftChildPtr()) >= 0) 
        return RightRotate(subTreePtr);
  
    // Left Right Case 
    if (bal_factor > 1 && difference(subTreePtr->GetLeftChildPtr()) < 0) 
    {  
        return LeftRightRotate(subTreePtr);
    } 
  
    // Right Right Case 
    if (bal_factor < -1 && difference(subTreePtr->GetRightChildPtr()) <= 0) 
        return LeftRotate(subTreePtr); 
  
    // Right Left Case 
    if (bal_factor < -1 && difference(subTreePtr->GetRightChildPtr()) > 0) 
    { 
        return RightLeftRotate(subTreePtr); 
    }

    return subTreePtr;
}


// ==== CBST<ItemType>::FindNode ====================================
//
// This function finds a target node if it exists.
//
// Input:
//      treePtr     [IN]    - A templated CBinaryNode pointer to start the
//                              search of the node to find
//      target      [IN]    - A const ItemType value that we want to find from
//                              the tree.
//      success     [OUT]   - A bool value that is marked true if sucessful,
//                              false otherwise.
//
// Output:
//       An CBinaryNode<ItemType> templated pointer of the node found.  If not
//          found, a nullptr is returned.
//
// =============================================================================
 template<class ItemType>
 CBinaryNode<ItemType>* CBST<ItemType>::FindNode(CBinaryNode<ItemType> *treePtr,const ItemType &target, bool &success) const{
    if (treePtr == nullptr) {
        success = false;
        return nullptr;
    } else if (treePtr->GetItem() == target) {
        success = true;
        return treePtr;
    } else if (treePtr->GetItem() == target) {
        success = true;
        return treePtr;
    }

    CBinaryNode<ItemType> *lRetPtr = FindNode(treePtr->GetLeftChildPtr(), target, success);
    CBinaryNode<ItemType> *rRetPtr = FindNode(treePtr->GetRightChildPtr(), target, success);

    return lRetPtr != nullptr ? lRetPtr : rRetPtr;
}