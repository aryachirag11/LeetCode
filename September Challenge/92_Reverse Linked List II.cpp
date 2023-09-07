#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
private:
  ListNode *reverseLinked(ListNode *head)
  {
    ListNode *next = NULL;
    ListNode *prev = NULL;
    ListNode *current = head;
    while (current != NULL)
    {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
    return prev;
  }

public:
  ListNode *reverseBetween(ListNode *head, int left, int right)
  {
    ListNode *current = head;
    ListNode *prev = NULL;
    int cnt = 1;
    while (cnt != left)
    {
      prev = current;
      current = current->next;
      cnt++;
    }
    ListNode *start = current;
    while (cnt != right)
    {
      current = current->next;
      cnt++;
    }
    ListNode *rest = current->next;
    current->next = NULL;

    ListNode *newHead = reverseLinked(start);
    if (prev != NULL)
      prev->next = newHead;
    current = newHead;

    while (current->next != NULL)
    {
      current = current->next;
    }
    current->next = rest;
    if (left == 1)
      return newHead;
    else
      return head;
  }
};

int main()
{
  return 0;
}