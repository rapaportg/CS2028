#ifndef HASHNODE_H
#define HASHNODE_H

template<typename K, typename V>
class HashNode
{
    private:
        K           key;
        V           value;
        char        state;

    public:
        HashNode    *next;

        K           getKey();
        V           getVal();
        char        getState();
        void        setVal(V val);
        void        setState(char s);

        HashNode(K key, V value);
        HashNode(K key);
        HashNode();

};

#endif

template<typename K, typename V>
HashNode<K, V>::HashNode(K in_key, V in_val)
{
    key   = *in_key;
    value = *in_val;
    state = 'e';
    next  = nullptr;
}

template<typename K, typename V>
HashNode<K, V>::HashNode(K in_key)
{
    key   = in_key;
    state = 'e';
    next  = nullptr;
}

template<typename K, typename V>
HashNode<K, V>::HashNode()
{
    state = 'e';
    next  = nullptr;
}


template<typename K, typename V>
K   HashNode<K, V>::getKey()
{
    return key;
}

template<typename K, typename V>
V   HashNode<K, V>::getVal()
{
    return value;
}

template<typename K, typename V>
char HashNode<K,V>::getState()
{
    return state;
}

template<typename K, typename V>
void HashNode<K,V>::setVal(V val)
{
    value = val;
}

template<typename K, typename V>
void HashNode<K,V>::setState(char s)
{
    state = s;
}
