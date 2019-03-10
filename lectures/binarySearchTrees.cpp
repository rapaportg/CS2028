Binary Search Tree

    // is a data structure where each node is capable of pointing at 2 child nodes.


    // Root node - a node with no parent

    // leaf - a node with no children

    // A binary tree must have a unique path to each node.


    // A level refers the distance root. the root is level 0, its children are level 1, it grandchildren are level 2, etc...


    // The height is the maximum level

    // the max number of nodes in a level is 2^n, where n is the level.

    // the minimum number of levels is log2(N+1), where N is the number of nodes.


    // To get the benefit of a binary tree, which is improved search capabilities. the tree needs to be arranged meaningfully.
    // usually this is with the child on the left being smaller than the parent and the child on the right being larger.



class Node
{
    private:
        int data;
        Node *left = nullptr;
        Node *right = nullptr;
};


class Tree
{
    private:
        Node *root;
        int size;

    public:
        int find(int val)
        {
            Node *ptr = root;

            while (ptr != nullptr)
            {
                if (ptr->data > val)
                {
                    ptr = ptr->left;
                }
                else if (ptr->data < val)
                {
                    ptr = ptr->right;
                }
                else
                {
                    return ptr->data;
                }
            }
            throw NotFound;
        }

        void add(int inVal, Node *top)
        {
            Node *ptr = top;

            if (root == null)
            {
                root = new Node(inVal);
                return;
            }
            while ((inVal > ptr->data & ptr->right != nullptr) || (inVal <= ptr->data && ptr->left != nullptr))
            {
                if (intVal > ptr->data)
                {
                    ptr = ptr->right;
                }
                else
                {
                    ptr = ptr->left;
                }
            }
            if (inVal <= ptr->data)
            {
                ptr->left = new Node(inVal);
            }
            else
            {
                ptr->right = new Node(inVal);
            }

        }

        void print(Node *ptr)
        {
            if (ptr == nullptr)
            {
                return;
            }
            cout << ptr->data << endl;
            print(ptr->left);
            print(ptr->right);
        }

        Node *insert(Node *inVal, Node *current)
        {
            if (current == NULL)
            {
                current = inVal;
            }
            else
            {
                if (inVal->data > current->data)
                    current->right = insert(inVal,current->left);
                else
                    current->left = insert(inVal,current->right);
            }
            return head;
        }

        Node *findParentNode(int val, Node *ptr)
        {
            Node *tmp;
            if (ptr == nullptr)
            {
                return nullptr;
            }
            if (ptr->data == val)
            {
                return nullptr;
            }
            tmp = findParentNode(val, ptr->left);
            if (tmp->left->data == val)
                return tmp;

            tmp = findParentNode(val, ptr->right);
            if (tmp->right->data == val || tmp->left == val)
                return tmp;s

            return ptr;
        }

        int remove(int val)
        {
            int     ret;
            Node    *head;
            Node    *toDel;

            head = findParentNode(val, root);

            if (head->right->data == val)
            {
                toDel = head->right;
                head->right = nullptr;
            }

            if (head->left->data == val)
            {
                toDel = head->left;
                head->left = nullptr;
            }

            if (toDel->right != nullptr)
            {
                insert(toDel->right, head);
            }

            if (toDel->left != nullptr)
            {
                insert(head->right->left, head);
            }

            ret = toDel->data;

            delete toDel;

            return ret;
        }
}
