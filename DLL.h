#pragma once  // Ensure the file is included only once

#ifndef DLL_H
#define DLL_H

#include <filesystem>
#include <fstream>
#include <memory>
#include <string>

#include "Array.h"
#include "Dataset.h"

namespace PerformanceEvaluation
{
  using FilePath = std::filesystem::path;

  struct LinkedListNode
  {
    Dataset data;
    LinkedListNode *next;
    LinkedListNode *prev;

    LinkedListNode(const Dataset &data) : data(data), next(nullptr), prev(nullptr) {}
  };

  class LinkedList
  {
  public:
    LinkedList() : m_Head(nullptr), m_Length(0) {}
    ~LinkedList();

    void insertBegin(const Dataset &dataset);
    void insertEnd(const Dataset &dataset);
    void insertPosition(const Dataset &dataset, size_t position);
    void deleteNode(const Dataset &dataset);
    void deleteAll();
    void displayAll() const;
    size_t getLength() const;
    LinkedListNode* getHead() const;
    void setHead(LinkedListNode* new_head);
    void sortMerge(); 

  private:
    LinkedListNode *m_Head;
    size_t m_Length;

    void incrementLength();
    void decrementLength();
    void isHeadEmpty() const;
    void isHeadOrNextEmpty() const;
  };

} // namespace PerformanceEvaluation

#endif // DLL_H