// B+ Tree
    - a variant of B tree where each node stores multiple keys and multiple pointers to child nodes.
            Only leaves store pointers to actual data

    - Nodes (not leaves): Store K keys and K+1 pointers to nodes.

    - Leaves: store K keys and K pointers to records.


    Parent Value is included in the child leaf when transvering right.

    -   Each leaf node points at the next leaf node (looking like a link list).

    -   When the node is full:

            1. Add a new node to the right of the curent node.

            2. Move half the data to the new node.

            3. Copy the middle value to the parent of both nodes

            4. Split the parent if neccessary

// B Tree
    - exactly like a B+ tree except the data is stored in the nodes rather than the nodes. no duplication of data