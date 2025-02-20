#pragma once

#include <string>

#include "Dataset.h"

namespace PerformanceEvaluation
{
  /*
   * Structure for a node in the doubly linked list.
   * Each node contains:
   * - `m_Data`: The actual dataset (news article details)
   * - `m_Next`: Pointer to the next node in the list
   * - `m_Prev`: Pointer to the previous node in the list
   */
  struct LinkedListDoublyNode
  {
    Dataset m_Data;         
    LinkedListDoublyNode *m_Next; 
    LinkedListDoublyNode *m_Prev; 

    // Constructor initializes a new node with data and sets pointers to null
    LinkedListDoublyNode(const Dataset &data) : m_Data(data), m_Next(nullptr), m_Prev(nullptr) {}
  };

  /*
   * Class representing a doubly linked list for storing datasets (news articles).
   * Supports insertion, deletion, and traversal of nodes.
   */
  class LinkedList
  {
  public:
    // Constructor initializes an empty linked list
    LinkedList() : m_Head(nullptr), m_Length(0) {}

    // Destructor deletes all nodes in the list to free memory
    ~LinkedList();

    // Insert a new node at the beginning of the list
    void insertBegin(const Dataset &dataset);

    // Insert a new node at the end of the list
    void insertEnd(const Dataset &dataset);

    // Insert a new node at a specific position in the list
    void insertPosition(const Dataset &dataset, size_t position);

    // Delete a specific node by matching dataset
    void deleteNode(const Dataset &dataset);

    // Delete all nodes in the list
    void deleteAll();

    // Display all nodes in the list
    void displayAll() const;

    // Get the total number of nodes in the list
    size_t getLength() const;

  private:
    LinkedListDoublyNode *m_Head; // Pointer to the first node in the list
    size_t m_Length;        // Stores the number of nodes in the list

    // Increase the length counter when a node is added
    void incrementLength();

    // Decrease the length counter when a node is removed
    void decrementLength();

    // Check if the list is empty (used in display functions)
    void isHeadEmpty() const;
  };

} // namespace PerformanceEvaluation