#include <iostream>
#include <string>
#include <memory>

#include "DLL.h"
#include "DateUtility.h"
#include "SimpleLogger.h"
#include "MergeSortDLL.h"

namespace PerformanceEvaluation
{
  void LinkedListDoubly::insertBegin(const Dataset &dataset)
  {
    LinkedListDoublyNode *node = new LinkedListDoublyNode(dataset);
    node->next = m_Head;

    if (m_Head != nullptr)
    {
      m_Head->prev = node;
    }
    m_Head = node;
    incrementLength();
  }

  void LinkedListDoubly::insertEnd(const Dataset &dataset)
  {
    LinkedListDoublyNode *node = new LinkedListDoublyNode(dataset);
    if (m_Head == nullptr)
    {
      m_Head = node;
      incrementLength();
      return;
    }

    LinkedListDoublyNode *temp = m_Head;
    while (temp->next != nullptr)
    {
      temp = temp->next;
    }

    temp->next = node;
    node->prev = temp;
    incrementLength();
  }

  void LinkedListDoubly::insertPosition(const Dataset &dataset, size_t position)
  {
    LinkedListDoublyNode *node = new LinkedListDoublyNode(dataset);

    if (position == 0)
    {
      insertBegin(dataset);
      return;
    }

    LinkedListDoublyNode *temp = m_Head;
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

  void LinkedListDoubly::displayFirst(int count) const
  {
    LinkedListDoublyNode *current = m_Head;
    int i = 0;

    while (current != nullptr && i < count)
    {
      std::cout << i + 1 << ". " << current->data.title << " (" << current->data.date << ")\n";
      current = current->next;
      i++;
    }

    if (i == 0)
      std::cout << "No records to display.\n";
  }

  void LinkedListDoubly::deleteNode(const Dataset &dataset)
  {
    if (m_Head == nullptr)
      return;

    if (m_Head->data == dataset)
    {
      LinkedListDoublyNode *temp = m_Head;
      m_Head = m_Head->next;

      if (m_Head != nullptr)
      {
        m_Head->prev = nullptr;
      }

      delete temp;
      decrementLength();
      return;
    }

    LinkedListDoublyNode *temp = m_Head;
    while (temp->next != nullptr && !(temp->next->data == dataset))
    {
      temp = temp->next;
    }

    if (temp->next == nullptr)
      return;

    LinkedListDoublyNode *node = temp->next;
    temp->next = temp->next->next;

    if (temp->next != nullptr)
    {
      temp->next->prev = temp;
    }

    delete node;
    decrementLength();
  }

  void LinkedListDoubly::deleteAll()
  {
    LinkedListDoublyNode *current = m_Head;
    while (current != nullptr)
    {
      LinkedListDoublyNode *temp = current;
      current = current->next;
      delete temp;
    }
    m_Head = nullptr;
  }

  size_t LinkedListDoubly::getLength() const
  {
    return m_Length;
  }

  LinkedListDoublyNode *LinkedListDoubly::getHead() const
  {
    return m_Head;
  }

  void LinkedListDoubly::setHead(LinkedListDoublyNode *new_head)
  {
    m_Head = new_head;
  }

  void LinkedListDoubly::incrementLength()
  {
    m_Length++;
  }

  void LinkedListDoubly::decrementLength()
  {
    if (m_Length > 0)
      m_Length--;
  }

  void LinkedListDoubly::isHeadEmpty() const
  {
    if (m_Head == nullptr)
      return;
  }

  void LinkedListDoubly::isHeadOrNextEmpty() const
  {
    if (m_Head == nullptr || m_Head->next == nullptr)
      return;
  }

  void LinkedListDoubly::sortMerge()
  {
    m_Head = MergeSortDLL::mergeSort(m_Head);
  }

} // namespace PerformanceEvaluation
