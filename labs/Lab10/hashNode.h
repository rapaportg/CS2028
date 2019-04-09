#ifndef HASHNODE_H
#define HASHNODE_H

template<typename K, typename V>
class HashNode
{
private:
	K					key;
	V					value;
	char				state;

public:
	HashNode<K,V>		*next;

	K					getKey();
	V					getVal();
	char				getState();
	void				setVal(V val);
	void				setState(char s);
	bool				operator ==(HashNode<K,V> &right);
	bool				operator >(HashNode<K, V> &right);
	bool				operator <(HashNode<K, V> &right);
	void				operator =(HashNode<K, V> *right);

	HashNode(const K key, const V value);
	HashNode(const K key);
	HashNode();

};

#endif


	template<typename K, typename V>
	HashNode<K, V>::HashNode(const K in_key, const V in_val)
	{
		key = in_key;
		value = in_val;
		state = 'e';
		next = nullptr;
	}

	template<typename K, typename V>
	HashNode<K, V>::HashNode(const K in_key)
	{
		key = in_key;
		state = 'e';
		next = nullptr;
	}

	template<typename K, typename V>
	HashNode<K, V>::HashNode()
	{
		state = 'e';
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
	char HashNode<K, V>::getState()
	{
		return state;
	}

	template<typename K, typename V>
	void HashNode<K, V>::setVal(V val)
	{
		value = val;
	}

	template<typename K, typename V>
	void HashNode<K, V>::setState(char s)
	{
		state = s;
	}

template<typename K, typename V>
bool HashNode<K,V>::operator ==(HashNode<K, V> &right)
{
	return (key == right.getKey());
}

template<typename K, typename V>
bool HashNode<K,V>::operator >(HashNode<K, V> &right)
{
	return (key > right.getKey());
}

template<typename K, typename V>
bool HashNode<K,V>::operator <(HashNode<K, V> &right)
{
	return (key < right.getKey());
}

template<typename K, typename V>
void HashNode<K, V>::operator =(HashNode<K, V> *right)
{
	key = right->getKey();
	value = right->getVal();
	state = right->getState();

	next = right->next;
}
