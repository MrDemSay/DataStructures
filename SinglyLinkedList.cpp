#include <iostream>


struct Node {
    int data;
    Node* next;
};

struct List {
    Node* first;

    inline void init(List &list) {
        list.first = NULL; 
    }

    Node* create_node(int data = 0) {
        Node* temp;
        temp = new Node;
        temp -> data = data;
        temp -> next = NULL;
        return temp;
    }


    void push_back(List &list, int data = 0) {
        if (list.first == NULL) { 
            list.first = create_node(data); 
        }
        else {
            Node* temp = create_node(data);
            Node* it = list.first;
            while(it -> next != NULL) {
                it = it -> next;
            }
            it -> next = temp;
        }
    }


    void push_up(List &list, int data = 0) {
        if (list.first == NULL) {
            list.first = create_node(data);
        }
        else {
            Node* temp = create_node(data);
            temp -> next = list.first;
            list.first = temp;
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


    void delete_list(List &list) {
        if(list.first != NULL) {
            Node* it = list.first, *temp; //*temp - pointer of this elem (for delete)
            while(it -> next != NULL) {
                temp = it;
                it = it -> next;
                delete temp;
            }
            delete it;
            list.first = NULL;
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
    list.push_up(list, a);
    list.print(list);
    list.delete_list(list);
    list.print(list);
}
