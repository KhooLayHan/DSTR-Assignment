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

  struct LinkedListDoublyNode
  {
    Dataset data;
    LinkedListDoublyNode *next;
    LinkedListDoublyNode *prev;

    LinkedListDoublyNode(const Dataset &data) : data(data), next(nullptr), prev(nullptr) {}
  };

  class LinkedListDoubly
  {
  public:
  LinkedListDoubly() : m_Head(nullptr), m_Length(0) {}
    ~LinkedListDoubly() {};

    void insertBegin(const Dataset &dataset);
    void insertEnd(const Dataset &dataset);
    void insertPosition(const Dataset &dataset, size_t position);
    void deleteNode(const Dataset &dataset);
    void deleteAll();
    void displayAll() const;
    void displayFirst(int count) const;
    size_t getLength() const;
    LinkedListDoublyNode* getHead() const;
    void setHead(LinkedListDoublyNode* new_head);
    void sortMerge(); 

  private:
  LinkedListDoublyNode *m_Head;
    size_t m_Length;

    void incrementLength();
    void decrementLength();
    void isHeadEmpty() const;
    void isHeadOrNextEmpty() const;
  };

} // namespace PerformanceEvaluation

#endif // DLL_H
