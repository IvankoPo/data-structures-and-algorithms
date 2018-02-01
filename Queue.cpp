#include<iostream>

using namespace std;

struct Node 
{ 
    void* Data; 
    Node* next; 
};

struct Queue 
{ 
    Node *head, *tail; 
    Queue(): head(NULL), tail(NULL) {}; 
    void Enqueue(void* d) { 
        Node* p = new Node; 
        p->Data = d; 
        p->next = NULL; 
        if (head == NULL) { 
            head = tail = p; 
        } 
        else { 
            tail->next = p; 
            tail = p; 
        } 
    } 
    void Dequeue() { 
        Node* del = head; 
        head = head->next; 
        delete del; 
    }    
    void* font() { 
        return head->Data; 
    } 
    bool isEmpty() { 
        return head == NULL ? true : false; 
    } 
}; 
int main() 
{ 
    Queue q; 
    q.Enqueue((void*)"a"); 
    q.Enqueue((void*)"b"); 
    q.Enqueue((void*)"c"); 
    cout << (char*)q.font() << endl; 
    q.Dequeue(); 
    cout << (char*)q.font() << endl; 

    system("pause"); 
    return 0; 
}