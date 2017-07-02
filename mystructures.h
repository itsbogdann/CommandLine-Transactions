#ifndef MYSTRUCTURES
#define MYSTRUCTURES
using namespace std;
template<typename T>
class MyStack {
public:
	int size;
	T *stack;
	MyStack() {
		this->size = 0;
		this->stack = NULL;
	}
	MyStack(MyStack *second) {
		this->size = second->size;
		this->stack = second->stack;
	}
	~MyStack() {
		this->size = 0;
		delete[] this->stack;
	}
	void push(T element) {
		T *stackcopy = new T[size + 1];
		for (int i = 0; i < size; i++) {
			stackcopy[i] = stack[i];
		}
		delete[] stack;
		stack = stackcopy;
		stack[size] = element;
		size++;
	}
	T pop() {
		if (isEmpty()) {
			cout << "ERROR: Stack is empty!" << endl;
			//return NULL;
		}
		T *stackcopy = new T[size - 1];
		T last_element = stack[size - 1];
		size--;
		for (int i = 0; i < size; i++) {
			stackcopy[i] = stack[i];
		}
		delete[] stack;
		stack = stackcopy;
		return last_element;
	}
	T peek() {
		return stack[size - 1];
	}
	bool isEmpty() {
		if (size == 0) {
			return true;
		}
		return false;
	}
};
template <typename T = int>
struct NodeHash {        
    string key;
    T value;
    NodeHash *next;
};
template <typename T = int>
class LinkedList {
    public: NodeHash <T> *head; 
public:
    LinkedList() {
        head = NULL;
    }
    LinkedList(const LinkedList &asd) {
		head=asd.head;
//		*this=asd;
	}
	void operator=(const LinkedList &asd) {
		head = asd.head;
	}
    bool IsEmpty() {
		if(head == NULL) {
			return true;
		}
           
		return false;
    }
    
    void AddValue(T val) {
        NodeHash <T> *n = new NodeHash <T>;
        n->value = val;             
        n->next = head;        
        head = n;         
    }
    T PopValue() {
        if(IsEmpty()) {
            return 0;
        }
        else {
        
            NodeHash<T> *n = new NodeHash<T>;
            n = head;
            T popped_value = n->value;
            head = head->next;
            //delete n;
            return popped_value;
        }
    }
    void Show() {
        NodeHash <T> *p;
        int i=1;
        for (p = head; p!= NULL; p = p->next) {
            cout<<"Elementu "<<i++<<"are valoarea: "<<p->value<<endl;
        }
    }
	/*~LinkedList() {
        if(!IsEmpty()) {
                NodeHash<T> *q = head;
                
                while(head->next != NULL) {
                
                    q = head;
                    head = head->next;
                    delete q;
                }
            
                delete head;
            }
    }*/
};
template <typename T = int>
class HashTable {
    LinkedList <T> *list;
    int h_max;
    int HashFunction(string key) {//copyright more or less-luat din curs 6-
        int hkey = 0;
        for (int i = 0; i < key.length(); i++)
            hkey = (hkey * 37 + key[i]) % h_max;//cu 37 merge mai bine
        return hkey;
    }
public:
    HashTable(int h_max) {
        this->h_max = h_max;
        list = new LinkedList <T>[h_max];
    }
    ~HashTable() {
        delete [] list;
    }
    void InsertItem(string key, T value) {
        int index = HashFunction( key );
        list[index].AddValue(value);
    }
    void RemoveItem(string item_key) {
        int index = HashFunction(item_key);
    }
    LinkedList<T> GetItemByKey(string item_key) {
        int index = HashFunction( item_key );
        return list[index];
    }
    void PrintTable() {
        cout << "\n\n Hash Table: \n";
        for ( int i = 0; i < h_max; i++ ) {
            cout << "Bucket " << i + 1 << ": ";
            list[i].Show();
            cout<<endl;
        }
    }
};

#endif