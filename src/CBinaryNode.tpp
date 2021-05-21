

#include "CBinaryNode.h"

// ============================================================================
// File: CBinaryNode.tpp
// ============================================================================
// Implementation file for the class CBinaryNode
// ============================================================================



// ==== CBinaryNode<ItemType>::CBinaryNode =====================================
//
// This is the default constructor for CBinaryNode<ItemType>.  It initializes
// the left and right child pointer to nullptr and leave m_item as garbage.
//
// Input:
//       void
//
// Output:
//       Nothing
//
// =============================================================================
template<class ItemType>
CBinaryNode<ItemType>::CBinaryNode() {
    this->m_leftChildPtr = nullptr;
    this->m_rightChildPtr = nullptr;
}




// ==== CBinaryNode<ItemType>::CBinaryNode =====================================
//
// This is the type constructor for CBinaryNode<ItemType>.  It initializes
// m_item and sets the left and right child pointer to nullptr.
//
// Input:
//       item [IN]      - A const ItemType reference to initialize the new node.
//
// Output:
//       Nothing
//
// =============================================================================
template<class ItemType>
CBinaryNode<ItemType>::CBinaryNode(const ItemType &item) {
    this->m_item = item;
    this->m_leftChildPtr = nullptr;
    this->m_rightChildPtr = nullptr;
}




// ==== CBinaryNode<ItemType>::CBinaryNode =====================================
//
// This is the type constructor for CBinaryNode<ItemType>.  It initializes all
// the private data members with the supplied arguments.
//
// Input:
//       item           [IN]    - A const ItemType reference to initialize the
//                                  new node.
//       leftChildPtr   [IN]    - A CBinaryNode<ItemType> pointer that points to
//                                  the left child.
//       rightChildPtr  [IN]    - A CBinaryNode<ItemType> pointer that points to
//                                  the right child.
//
// Output:
//       Nothing
//
// =============================================================================
template<class ItemType>
CBinaryNode<ItemType>::CBinaryNode(const ItemType &item,
            CBinaryNode<ItemType> *leftChildPtr,
            CBinaryNode<ItemType> *rightChildPtr) {
    this->m_item = item;
    this->m_leftChildPtr = leftChildPtr;
    this->m_rightChildPtr = rightChildPtr;
}




// ==== CBinaryNode<ItemType>::SetItem =========================================
//
// This function assigns a value to m_item.
//
// Input:
//       item [IN]      - A const ItemType reference.
//
// Output:
//       void
//
// =============================================================================
template<class ItemType>
void CBinaryNode<ItemType>::SetItem(const ItemType &item) {
    this->m_item = item;
}




// ==== CBinaryNode<ItemType>::GetItem =========================================
//
// This function returns the value of m_item.
//
// Input:
//       void
//
// Output:
//       An ItemType.
//
// =============================================================================
template<class ItemType>
ItemType CBinaryNode<ItemType>::GetItem() const {
    return this->m_item;
}




// ==== CBinaryNode<ItemType>::IsLeaf ==========================================
//
// This function checks if the node is a leaf.
//
// Input:
//       void
//
// Output:
//       Returns true if the node is a leaf, false otherwise.
//
// =============================================================================
template<class ItemType>
bool CBinaryNode<ItemType>::IsLeaf() const {
    return this->m_leftChildPtr == nullptr && this->m_rightChildPtr == nullptr;
}




// ==== CBinaryNode<ItemType>::GetLeftChildPtr =================================
//
// This function returns the pointer to the left node.
//
// Input:
//       void
//
// Output:
//       Returns a CBinaryNode<ItemType> pointer.
//
// =============================================================================
template<class ItemType>
CBinaryNode<ItemType>* CBinaryNode<ItemType>::GetLeftChildPtr() const{
    return this->m_leftChildPtr;
}




// ==== CBinaryNode<ItemType>::GetRightChildPtr ================================
//
// This function returns the pointer to the right node.
//
// Input:
//       void
//
// Output:
//       Returns a CBinaryNode<ItemType> pointer.
//
// =============================================================================
template<class ItemType>
CBinaryNode<ItemType>* CBinaryNode<ItemType>::GetRightChildPtr() const {
    return this->m_rightChildPtr;
}




// ==== CBinaryNode<ItemType>::SetLeftChildPtr =================================
//
// This function assigns the poitner to the left node.
//
// Input:
//       leftChildPtr   [IN]    - A CBinaryNode<ItemType> pointer to the left
//                                  node.
//
// Output:
//       void
//
// =============================================================================
template<class ItemType>
void CBinaryNode<ItemType>::SetLeftChildPtr(CBinaryNode<ItemType> *leftChildPtr) {
    this->m_leftChildPtr = leftChildPtr;
}




// ==== CBinaryNode<ItemType>::SetRightChildPtr ================================
//
// This function assigns the poitner to the right node.
//
// Input:
//       rightChildPtr   [IN]    - A CBinaryNode<ItemType> pointer to the left
//                                  node.
//
// Output:
//       void
//
// =============================================================================
template<class ItemType>
void CBinaryNode<ItemType>::SetRightChildPtr(CBinaryNode<ItemType> *rightChildPtr) {
    this->m_rightChildPtr = rightChildPtr;
}