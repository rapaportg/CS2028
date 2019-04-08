#ifndef HASHNODE_H
#define HASHNODE_H

template<typename K, typename V>
class HashNode
{
    private:
        K           key;
        V           value;

    public:
        HashNode    *next;

        HashNode(const K &key, const V &value);
        K       getKey();
        V       getVal();
        void    setVal(V val);

};

#endif

template<typename K, typename V>
HashNode<K, V>::HashNode(const K &in_key, const V &in_val)
{
    key = *in_key;
    value = *in_val;
    next = nullptr;
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
void HashNode<K, V>::setVal(V val)
{
    value = val;
}