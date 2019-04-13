#ifndef HASHNODE_H
#define HASHNODE_H

template<typename V>
class HashNode
{
private:
	int				key;
	V				value;
	char			state;

public:
	HashNode<V>		*next;
	HashNode<V>		*down = nullptr;

	int				getKey();
	V				getVal();
	char			getState();
	void			setVal(V val);
	void			setState(char s);
	bool			operator ==(HashNode<V> &right);
	bool			operator >(HashNode<V> &right);
	bool			operator <(HashNode<V> &right);
	void			operator =(HashNode<V> *right);

	HashNode(int key, V value);
	HashNode(V in_val);
	HashNode();

};

#endif


template<typename V>
HashNode<V>::HashNode(int in_key, V in_val)
{
	key = in_key;
	value = in_val;
	state = 'e';
	next = nullptr;
}

template<typename V>
HashNode<V>::HashNode(V in_val)
{
	value = in_val;
	state = 'e';
	next = nullptr;
}

template<typename V>
HashNode<V>::HashNode()
{
	state = 'e';
	next = nullptr;
}

template<typename V>
int   HashNode<V>::getKey()
{
	return key;
}

template<typename V>
V   HashNode<V>::getVal()
{
	return value;
}

template<typename V>
char HashNode<V>::getState()
{
	return state;
}

template<typename V>
void HashNode<V>::setVal(V val)
{
	state = 'f';
	value = val;
}

template<typename V>
void HashNode<V>::setState(char s)
{
	state = s;
}

template<typename V>
bool HashNode<V>::operator ==(HashNode<V> &right)
{
	return (key == right.getKey());
}

template<typename V>
bool HashNode<V>::operator >(HashNode<V> &right)
{
	return (key > right.getKey());
}

template<typename V>
bool HashNode<V>::operator <(HashNode<V> &right)
{
	return (key < right.getKey());
}

template<typename V>
void HashNode<V>::operator =(HashNode<V> *right)
{
	key = right->getKey();
	value = right->getVal();
	state = right->getState();

	next = right->next;
}