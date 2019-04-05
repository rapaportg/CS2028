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
                insert(toDel->left, head);
            }

            ret = toDel->data;

            delete toDel;

            return ret;
        }


        void rotateLeft(Node *parent, Node *child)
        {
            if (child == root)     // needs checking
            {
                root = child->right;
                child->right = root->left;
                root->left = child;
            }

            else if (parent->right == child)
            {
                parent->right = child->right;
                parent->right->left = child;
                child->right = null;
            }
            else
            {
                parent->left = child->right;
                child->right = child->right->left;
                parent->left->left = child;
            }
        }

        void rotateRight(Node *parent, Node *child)  // needs checking
        {
            if (child == root)
            {
                root = child->left;
                child->left = root->right;
                root->right = child;
            }
            else if (parent->left == child)
            {
                parent->left = child->left;
                child->left = child->left->right;
                parent->left->right = child;
            }
            else
            {
                parent->right = child->left;
                child->left = child->left->right;
                parent->right->right = child;
            }
        }

        int levels (Node *parent)
        {
            int RLevels = 0;
            int LLevels = 0;
            if (parent->left != nullptr)
            {
                LLevels = 1 + levels(parent->left);
            }
            if (parent->right != nullptr)
            {
                RLevels = 1 + levels(parent->right);
            }
            return (LLevels >= RLevels ? LLevels : RLevels); // return max(LLevels, RLevels)
        }


}



/*
// Scape goat tree = rather than rotating, it pulls all the nodes out of an unbalanced tree and adds them back in
//                   in order such that the subtree is perfectly balanced.
//
//      Logic for rebalancing:

            n = number of nodes

            q = upper bounds of nodes in tree q/2 <= n <= q

            height is always log<3/2>(q) <= log<3/2>(2n) <= (log<3/2>(n) + 2)


        whenever we insert a node(u) that violates the rules, the depth(u) > log<3/2> (q),
        we walk up the tree from u looking for the parent w that will be used to rebalance.

        Size(w.child) / size(w) > 2/3 where w.child is the path to  uand size(w) includes w in that value


// Red Black Trees - A self balancing binary search tree. Each node contains an additional data value (color)

    Note: Any Null pointer is Black

    Properties:

        -   Each node is either red of black

        -   Root is black

        -   All leaves are black (here a leaf is the Nil or Null)

        -   If a node is Red both childern are Black

        -   Every path from a node to the final Nil contains some number of Black nodes


    To Insert:

        -   Insert the new node

        -   Color the new node. This color is Red

        -   Restore the Red Black Properties.

            -   If the parent of the new node is black

                -   No Rotation is needed

            -   If the new nodes sibing is red, recolor the new node, the sibling, parent, parent's sibling, and Grand Parents.

            -   If the new node's sibling is black, rebalance is needed.


        Basically you cant have a Red child and a Black child.



*/