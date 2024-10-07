#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int append(Node** phead, int item) {
    Node* new_node = new Node();
    new_node->data = item;
    new_node->next = nullptr;
    
    if (*phead == nullptr) {
        *phead = new_node;
    } else {
        Node* ptr = *phead;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
    return item;
}

int insert_beg(Node** phead, int item) {
    Node* new_node = new Node();
    new_node->data = item;
    new_node->next = *phead;
    *phead = new_node;
    
    return item;
}

int insert_mid(Node** phead, int pos, int item) {
    Node* new_node = new Node();
    new_node->data = item;

    if (pos == 1) {
        new_node->next = *phead;
        *phead = new_node;
        return item;
    }

    Node* ptr = *phead;
    Node* prev = nullptr;

    int count = 1;
    while (count < pos && ptr != nullptr) {
        prev = ptr;
        ptr = ptr->next;
        count++;
    }

    if (ptr != nullptr || prev != nullptr) {
        new_node->next = prev->next;
        prev->next = new_node;
    } else {
        cout << "Position out of range" << endl;
    }

    return item;
}


void display(Node* ptr) {
    while (ptr != nullptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void del_beg(Node** phead) {
    if (*phead == nullptr) {
        cout << "Empty" << endl;
    } else {
        Node* ptr = *phead;
        *phead = ptr->next;
        cout << ptr->data << " is deleted" << endl;
        delete ptr;
    }
}

void del_mid(Node** phead, int key) {
    int count = 1;
    Node* ptr = *phead;
    Node* prev = *phead;

    if (*phead == nullptr) {
        cout << "Empty" << endl;
    } else {
        while (count != key && ptr != nullptr) {
            prev = ptr;
            ptr = ptr->next;
            count++;
        }
        if (ptr != nullptr) {
            prev->next = ptr->next;
            cout << ptr->data << " is deleted" << endl;
            delete ptr;
        } else {
            cout << "Position out of range" << endl;
        }
    }
}

void del_end(Node** phead) {
    if (*phead == nullptr) {
        cout << "Empty" << endl;
        return;
    }

    Node* ptr = *phead;
    Node* prev = nullptr;

    while (ptr->next != nullptr) {
        prev = ptr;
        ptr = ptr->next;
    }

    if (prev != nullptr) {
        prev->next = nullptr;
    } else {
        *phead = nullptr;
    }

    cout << ptr->data << " is deleted" << endl;
    delete ptr;
}

void reverse(Node* ptr) {
    if (ptr == nullptr) {
        return;
    }
    reverse(ptr->next);
    cout << ptr->data << " ";
}

int main() {
    Node* head = nullptr;
    while (true) {
        int x, y, z, a, key, r;
        int n, num, l, pos;
        cout << "\n1.Insert End 2.Insert Middle 3.Insert Begining 4.Delete Begining 5.Delete Middle 6.Delete End 7.Display 8.Reverse\n";
        
        cout << "Enter the choice: ";
        cin >> x;
        
        switch (x) {
            case 1:
                cout << "\nEnter the number to be insert: ";
                cin >> n;
                y = append(&head, n);
                cout << "\n" << y << " is inserted" << endl;
                break;
            case 2:
                cout << "\nEnter the number to be insert: ";
                cin >> l;
                cout << "\nEnter the pos: ";
                cin >> pos;
                a = insert_mid(&head, pos, l);
                cout << "\n" << a << " is inserted" << endl;
                break;
            case 3:
                cout << "\nEnter the number to be insert: ";
                cin >> num;
                z = insert_beg(&head, num);
                cout << "\n" << z << " is inserted" << endl;
                break;
            case 4:
                del_beg(&head);
                break;
            case 5:
                cout << "\nEnter the position: ";
                cin >> key;
                del_mid(&head, key);
                break;
            case 6:
                del_end(&head);
                break;
            case 7:
                display(head);
                break;
            case 8:
                reverse(head);
                cout << endl;
                break;
            default:
                cout << "Try again" << endl;
                break;
        }
    }
}
