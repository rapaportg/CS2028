#ifndef HASHKEY_H
#define HASHKEY_H

template<typename K>
struct HashKey
{
    unsigned long operator()(K &key) const
    {
        return reinterpret_cast<unsigned long>(key) % TABLE_SIZE;
    }
};

#endif