#pragma once

#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <iostream>
#include <string>
#include <memory>

#include "Array.h"
#include "Dataset.h"
#include "LinkedList.h"
#include "DateUtility.h"

namespace PerformanceEvaluation
{

    // TODO: Can implement each of the various searching and sorting algorithms.

    /*
     * Sorting algorithms
     * 1. Merge Sort
     * 2. Quick Sort
     * 3. Heap Sort
     * ...
     **/

    /*
     * Searching algorithms
     * 1. Linear Search
     * 2. Binary Search
     **/

    class Algorithm
    {
    public:
        Algorithm(const Algorithm &) = delete;
        Algorithm &operator=(const Algorithm &) = delete;
        ~Algorithm() {} // Destructor

        static Array* QuickSort(Array& arr);
        static Array* MergeSort(Array& arr);
        static Array* HeapSort(Array& arr);

    private:
        Algorithm() {}

        static void _quickSortImpl(Dataset arr[], int low, int high);
        static int partition(Dataset arr[], int low, int high);
        static void mergeSortImpl(Dataset arr[], int left, int right);
        static void merge(Dataset arr[], int left, int mid, int right);
        static void heapSortImpl(Dataset arr[], int n);
        static void heapify(Dataset arr[], int n, int i);
    };

    // --- QuickSort Functions ---
    int Algorithm::partition(Dataset arr[], int low, int high)
    {
        constexpr auto CompareAndSortDate = [](const DateUtility &date_utility, const std::string &first_date, const std::string &second_date)
        {
            const auto &[left_day, left_month, left_year] = date_utility.ParseDate(first_date);
            const auto &[right_day, right_month, right_year] = date_utility.ParseDate(second_date);
            return std::tie(left_year, left_month, left_day) <= std::tie(right_year, right_month, right_day);
        };

        DateUtility date_utility;

        std::string pivotDate = arr[high].date;
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (CompareAndSortDate(date_utility, arr[j].date, pivotDate))
            {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    void Algorithm::_quickSortImpl(Dataset arr[], int low, int high)
    {
        if (low < high)
        {
            int pivotIndex = partition(arr, low, high);
            _quickSortImpl(arr, low, pivotIndex - 1);
            _quickSortImpl(arr, pivotIndex + 1, high);
        }
    }

    Array* Algorithm::QuickSort(Array& arr)
    {
        Array* sortedArray = new Array(arr);
        _quickSortImpl(sortedArray->data(), 0, sortedArray->getLength() - 1);
        return sortedArray;
    }

    // --- MergeSort Functions ---
    void Algorithm::merge(Dataset arr[], int left, int mid, int right)
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        Dataset* leftArr = new Dataset[n1];
        Dataset* rightArr = new Dataset[n2];

        for (int i = 0; i < n1; i++)
            leftArr[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            rightArr[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2)
        {
            if (leftArr[i].date <= rightArr[j].date)
                arr[k++] = leftArr[i++];
            else
                arr[k++] = rightArr[j++];
        }

        while (i < n1)
            arr[k++] = leftArr[i++];
        while (j < n2)
            arr[k++] = rightArr[j++];

        delete[] leftArr;
        delete[] rightArr;
    }

    void Algorithm::mergeSortImpl(Dataset arr[], int left, int right)
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2;
            mergeSortImpl(arr, left, mid);
            mergeSortImpl(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

    Array* Algorithm::MergeSort(Array& arr)
    {
        Array* sortedArray = new Array(arr);
        mergeSortImpl(sortedArray->data(), 0, sortedArray->getLength() - 1);
        return sortedArray;
    }

    // --- HeapSort Functions ---
    void Algorithm::heapify(Dataset arr[], int n, int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left].date > arr[largest].date)
            largest = left;

        if (right < n && arr[right].date > arr[largest].date)
            largest = right;

        if (largest != i)
        {
            std::swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    void Algorithm::heapSortImpl(Dataset arr[], int n)
    {
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);

        for (int i = n - 1; i > 0; i--)
        {
            std::swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }

    Array* Algorithm::HeapSort(Array& arr)
    {
        Array* sortedArray = new Array(arr);
        heapSortImpl(sortedArray->data(), sortedArray->getLength());
        return sortedArray;
    }

} // namespace PerformanceEvaluation

#endif
