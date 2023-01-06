#include <iostream>


struct Node {
    int data;
    Node* next;
    Node* prev;
};

struct List {
    Node* first;
    Node* last;

    inline void init(List &list) {
        list.first = NULL;
        list.last = NULL; 
    }

    Node* create_node(int data = 0) {
        Node* temp;
        temp = new Node;
        temp -> data = data;
        temp -> next = NULL;
        temp -> prev = NULL;
        return temp;
    }


    void push_back(List &list, int data = 0) {
        if(list.first == NULL) {
            list.first = create_node(data);
            list.last = list.first;
        }
        else {
            Node* temp = create_node(data);
            temp -> prev = list.last;
            list.last -> next = temp;
            list.last = temp; 
        }
    }


    void print(List &list) {
        if (list.first ==NULL) {
            std::cout << "Empty list" << std::endl;
        }
        else {
            Node* it = list.first;
            while(it != NULL) {
                std::cout << it-> data << " ";
                it = it -> next;
            }
            std::cout << std::endl;
        }
    }

};

int main() {
    List list;
    list.init(list);
    int a = 1, b = 10, c = 10002;

    list.push_back(list, 5);
    list.push_back(list, b);
    list.push_back(list, c);
    list.print(list);

}
