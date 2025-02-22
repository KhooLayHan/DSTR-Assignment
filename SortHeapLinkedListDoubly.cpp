// #include "SortHeapLinkedList.h"

// namespace PerformanceEvaluation {
//     void SortHeapLinkedList::SortBy(LinkedList& linked_list) {
//         LinkedListNode* head = linked_list.GetHead();
//         HeapSort(head);
//         linked_list.SetHead(head);
//     }
    
//     // Applies heap sort
//     LinkedListNode* SortHeapLinkedList::HeapSort(LinkedListNode* head) {
//         if (!head || !head->m_Next) {
//             return head;
//         }
    
//         // Convert linked list to array
//         int length = 0;
//         LinkedListNode* temp = head;
//         while (temp) {
//             length++;
//             temp = temp->m_Next;
//         }
    
//         LinkedListNode** node_array = new LinkedListNode*[length];
    
//         temp = head;
//         for (size_t i = 0; i < length; i++) {
//             node_array[i] = temp;
//             temp = temp->m_Next;
//         }
    
//         // Perform heap sort on node_array based on dates
//         HeapSortArray(node_array, length);
    
//         // Reconstruct the linked list from the sorted array
//         for (size_t i = 0; i < length - 1; ++i) {
//             node_array[i]->m_Next = node_array[i + 1];
//         }
//         node_array[length - 1]->m_Next = nullptr;
    
//         LinkedListNode* new_head = node_array[0];
    
//         delete[] node_array;

//         return new_head;
//     }
    
//     // Convert to array
//     void SortHeapLinkedList::HeapSortArray(LinkedListNode** arr, size_t n) {
//         // Build Min Heap (ascending order)
//         for (size_t i = n / 2 - 1; i >= 0; i--) {
//             Heapify(arr, n, i);
//         }
    
//         // Extract elements from heap one by one
//         for (size_t i = n - 1; i > 0; i--) {
//             std::swap(arr[0], arr[i]);
//             Heapify(arr, i, 0);
//         }
//     }
    
//     // Min-heap for ascending order, ensures the smallest element is always at the top
//     void SortHeapLinkedList::Heapify(LinkedListNode** arr, int n, int i) {
//         int smallest = i;  // We need Min-Heap
//         int left = 2 * i + 1;
//         int right = 2 * i + 2;
    
//         DateUtility date_utility;
    
//         auto getDateKey = [&](LinkedListNode* node)  {
//             return date_utility.ParseDate(node->m_Data.m_Date);
//         };
    
//         // CompareAndSortDate(date_utility, arr[left]->m_Data.m_Date, arr[smallest]->m_Data.m_Date);

//         if (left < n && CompareAndSortDate(date_utility, arr[left]->m_Data.m_Date, arr[smallest]->m_Data.m_Date)) {
//             smallest = left;
//         }
    
//         if (right < n && CompareAndSortDate(date_utility, arr[right]->m_Data.m_Date, arr[smallest]->m_Data.m_Date)) {
//             smallest = right;
//         }
    
//         if (smallest != i) {
//             std::swap(arr[i], arr[smallest]);
//             Heapify(arr, n, smallest);
//         }
//     }
// } // namespace PerformanceEvaluation