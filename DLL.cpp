#include <iostream>
#include <string>
#include <memory>

#include "DLL.h"
#include "DateUtility.h"
#include "SimpleLogger.h"
#include "MergeSortDLL.h"

namespace PerformanceEvaluation
{
  void LinkedList::insertBegin(const Dataset &dataset)
  {
    LinkedListNode *node = new LinkedListNode(dataset);
    node->next = m_Head;

    if (m_Head != nullptr)
    {
      m_Head->prev = node;
    }
    m_Head = node;
    incrementLength();
  }

  void LinkedList::insertEnd(const Dataset &dataset)
  {
    LinkedListNode *node = new LinkedListNode(dataset);
    if (m_Head == nullptr)
    {
      m_Head = node;
      incrementLength();
      return;
    }

    LinkedListNode *temp = m_Head;
    while (temp->next != nullptr)
    {
      temp = temp->next;
    }

    temp->next = node;
    node->prev = temp;
    incrementLength();
  }

  void LinkedList::insertPosition(const Dataset &dataset, size_t position)
  {
    LinkedListNode *node = new LinkedListNode(dataset);

    if (position == 0)
    {
      insertBegin(dataset);
      return;
    }

    LinkedListNode *temp = m_Head;
    for (size_t i = 0; temp != nullptr && i < position - 1; i++)
      temp = temp->next;

    if (temp == nullptr)
    {
      delete node;
      return;
    }

    node->next = temp->next;
    node->prev = temp;
    if (temp->next != nullptr)
    {
      temp->next->prev = node;
    }
    temp->next = node;
    incrementLength();
  }

  void LinkedList::deleteNode(const Dataset &dataset)
  {
    if (m_Head == nullptr)
      return;

    if (m_Head->data == dataset)
    {
      LinkedListNode *temp = m_Head;
      m_Head = m_Head->next;

      if (m_Head != nullptr)
      {
        m_Head->prev = nullptr;
      }

      delete temp;
      decrementLength();
      return;
    }

    LinkedListNode *temp = m_Head;
    while (temp->next != nullptr && !(temp->next->data == dataset))
    {
      temp = temp->next;
    }

    if (temp->next == nullptr)
      return;

    LinkedListNode *node = temp->next;
    temp->next = temp->next->next;

    if (temp->next != nullptr)
    {
      temp->next->prev = temp;
    }

    delete node;
    decrementLength();
  }

  void LinkedList::deleteAll()
  {
    LinkedListNode *current = m_Head;
    while (current != nullptr)
    {
      LinkedListNode *temp = current;
      current = current->next;
      delete temp;
    }
    m_Head = nullptr;
  }

  size_t LinkedList::getLength() const
  {
    return m_Length;
  }

  LinkedListNode* LinkedList::getHead() const
  {
    return m_Head;
  }

  void LinkedList::setHead(LinkedListNode* new_head)
  {
    m_Head = new_head;
  }

  void LinkedList::incrementLength()
  {
    m_Length++;
  }

  void LinkedList::decrementLength()
  {
    if (m_Length > 0)
      m_Length--;
  }

  void LinkedList::isHeadEmpty() const
  {
    if (m_Head == nullptr)
      return;
  }

  void LinkedList::isHeadOrNextEmpty() const
  {
    if (m_Head == nullptr || m_Head->next == nullptr)
      return;
  }

  void LinkedList::sortMerge()
{
    m_Head = MergeSortDLL::mergeSort(m_Head);
}

} // namespace PerformanceEvaluation
