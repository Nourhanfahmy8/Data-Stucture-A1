#include <iostream>
#include <fstream>
#include <sstream>
using namespace std ;
class Node {
    public:
    int data ;
    Node* next ;
    Node(){
        this->data = 0;
        this->next = nullptr ;
    };
    Node(int val){
        this->data = val ;
        this->next = nullptr ;
    };
};
class SortedLinkedList {
    private :
    Node* head ;
    int count ;
    public :
    SortedLinkedList(){
        count = 0 ;
        head = NULL ;
    };
    void insert (int val){
        Node* new_node = new Node(val);
        if (head == nullptr || head->data > val) {
            new_node->next = head;
            head = new_node;
            count++;
            return;
        }
        Node* last = head;
        while (last->next != nullptr && last->next->data < val) {
            last = last->next;
        }
        new_node->next = last->next;
        last->next = new_node;
        count++;
    };
    void remove (int index){
        if (index < 0 || index >= count-1){
        return ;
        }
        Node* last = head ;
        if (index == 0){
            Node* tmp = head ;
            head = head->next ;
            delete tmp ;
            count-- ;
        }
        else {
        for (int i = 0; i < index-1 ; i++){
            last = last->next ;
        }
        Node* tmp = last->next;
        last->next = tmp->next ;
        delete tmp ;
        count--;
        }
    };
    friend ostream& operator<<(ostream& os , const SortedLinkedList& list){
        Node* last = list.head;
        os << '[' ;
        while (last != NULL){
            if (last->next == NULL){
                os<<last->data;
                break;
            }
            os<<last->data<<", ";
            last = last->next;
        }
        os <<']';
        return os;
    };
    int operator [](int index){
        if (index < 0 || index >= count-1){
        throw out_of_range("Index out of bounds");    
        }
        Node* last = head ;
        for (int i = 1 ; i < index ; i++){
            last = last->next;
        }
        return last->data ;
    };
    ~SortedLinkedList(){
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
    };
};
void processFile(const string& filename, SortedLinkedList& list) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file!\n";
        return;
    }
    string line;
    if (getline(file, line)) {
        stringstream ss(line);
        int num;
        while (ss >> num) {
            list.insert(num);
        }
    }
    cout << "Sorted Linked List : " << list <<endl;
    if (getline(file, line)) {
        int index;
        stringstream ss(line);
        while (ss >> index) {
            list.remove(index);
        }
    }
    cout << "Sorted Linked List after remove the element/s : " << list <<endl;
    file.close();
}
int main (){
    SortedLinkedList L ;
    processFile("file.txt" , L);
    
}
