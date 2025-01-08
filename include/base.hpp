#include <algorithm>
#include <cstdint>
#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ostream &operator<<(ostream &os, const vector<int> &vec) {
  os << "[";
  for (size_t i = 0; i < vec.size(); ++i) {
    if (i > 0)
      os << ", ";
    os << vec[i];
  }
  os << "]";
  return os;
}

std::ostream &operator<<(std::ostream &os,
                         const std::vector<std::vector<int>> &vec) {
  os << "[\n";
  for (const auto &row : vec) {
    os << "  [ ";
    for (const auto &elem : row) {
      os << elem << " ";
    }
    os << "]\n";
  }
  os << "]";
  return os;
}

std::ostream &operator<<(std::ostream &os, const ListNode *list) {
  const ListNode *current = list;
  while (current != nullptr) {
    os << current->val;
    if (current->next != nullptr) {
      os << " -> ";
    }
    current = current->next;
  }
  return os;
}

ListNode *vectorToList(const vector<int> &vec) {
  ListNode dummy(0);
  ListNode *current = &dummy;
  for (int num : vec) {
    current->next = new ListNode(num);
    current = current->next;
  }
  return dummy.next;
}

vector<int> listToVector(ListNode *head) {
  vector<int> vec;
  while (head != nullptr) {
    vec.push_back(head->val);
    head = head->next;
  }
  return vec;
}

ostream &operator<<(ostream &os, ListNode *head) {
  vector<int> vec = listToVector(head);
  os << "[";
  for (size_t i = 0; i < vec.size(); ++i) {
    if (i > 0)
      os << ", ";
    os << vec[i];
  }
  os << "]";
  return os;
}