class Node
{
    public:
        char data;
        Node *next = nullptr;
        Node *prev = nullptr;
        Node(char c)
        {
            data = c;
        }
};

class List
{
    private:
        Node *head;
        Node *curr;
        int length;

    public:

        void insert(char c) // unordered
        {
            length++;
            Node *tmp;
            Node *ptr = new Node(c);
            if (head == nullptr)
            {
                head = ptr;
            }
            else
            {
                tmp = head->next;
                while (tmp->next != nullptr)
                    tmp = tmp->next;
            }
            tmp = ptr;
        }

        void insertFront(char c)  // unordered
        {
            length++;
            Node *adder = new Node(c);
            if (head == nullptr)
            {
                head = adder;
            }
            else
            {
                adder->next = head;
                head = adder;
            }
        }

        void insertOrdered(char c)     // redo this
        {
            Node *adder = new Node(c);
            Node *tmp;
            length++;
            if (head == nullptr)
            {
                head = adder;
            }
            else
            {
                tmp = head;
                while(tmp->next != nullptr)
                {
                    if(tmp->next->data > adder->data){break;}
                    tmp = temp->next;
                }
                if (adder->data < head->data)
                {
                    adder->next = tmp;
                    head = adder;
                }
                else
                {
                    adder->next = tmp->next;
                    tmp->next = adder;
                }
            }
        }

        char remove(char c)
        {
            Node *tmp;
            Node *ptr;
            char ret;
            if (head == nullptr)
            {
                throw EmptyListException;
            }
            if (head->data == c)
            {
                tmp = head;
                head = head->next;
                ret = tmp->data;
                delete tmp;
                return ret;
            }
            ptr = head;
            while(ptr->next != nullptr
            {
                if (head->next->data == c)
                {
                    tmp = ptr->next;
                    ptr->next = tmp->next;
                    ret = tmp->data;
                    delete tmp;
                    return ret;
                }
                ptr = ptr->next;
            }
        }

        void makeEmpty()
        {
            Node *tmp;
            if (head->next != nullptr)
            {
                length--;
                tmp = head;
                head = head->next;
                delete tmp;
            }
            head->next = nullptr;
        }

        char getNext()
        {
            if (curr->next == nullptr)
                throw error; // define

            if (curr == nullptr)
                curr = head;

            curr = curr->next;
            return curr->data;
        }

};

class CircleLL  // circular link list
{
    private:
        Node *head;
        Node *curr;
        int length;


    public:

        void insertBack(char c) //REDO
        {
            length++;
            Node *tmp;
            Node *newNode = new Node(c);

            if (head == nullptr)
            {
                head = newNode;
            }

            else
            {
                tmp = head->next;
                while (tmp->next != nullptr)
                    tmp = tmp->next;
            }
            tmp = newNode;
            if (tmp->next == head)
            {
                newNode->next = head;
                temp->next = newNode;
            }
        }

        void insertFront(char c)// REDO
        {
            length++;
            Node *adder = new Node(c);
            if (head == nullptr)
            {
                head = adder;
            }
            else
            {
                adder->next = head;
                head = adder;
            }
        }

};

class DoubleLL
{
    private:
        Node *head;
        Node *curr;
        int length;

    public:
}


head->prev->next = newNOde;
newnode->prev = head->prev;
newnode->next = head;
head->prev = newnode;
head = newNode;