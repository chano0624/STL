#include<iostream>
using namespace std;

#include<vector>

template<typename T>
class Iterator
{
public:
	Iterator() : _ptr(nullptr)
	{

	}

	Iterator(T* ptr) : _ptr(ptr)
	{

	}

	Iterator& operator++()
	{
		_ptr++;
		return *this;
	}

	Iterator operator++(int)
	{
		Iterator temp = *this;
		_ptr++;
		return temp;
	}

	Iterator operator+(const int count)
	{
		Iterator temp = *this;
		temp._ptr += count;
		return temp;
	}
	bool operator==(const Iterator& right)
	{
		return _ptr == right._ptr;
	}

	bool operator!=(const Iterator& right)
	{
		return _ptr != right._ptr;
	}

	T& operator*()
	{
		return *_ptr;
	}
public:
	T* _ptr;

};

template<typename T>
class Vector
{
public:
	Vector() : _data(nullptr), _capacity(0), _size(0)
	{

	}

	~Vector()
	{
		if (_data != nullptr)
			delete[] _data;
	}

	void push_back(const T& val)
	{
		if (_size == _capacity)
		{
			int newCapacity = static_cast<int>(_capacity * 1.5);
			if (newCapacity == _capacity)
				++newCapacity;

			reserve(newCapacity);
		}
	
		_data[_size] = val;

		_size++;	
	}

	void reserve(int capacity)
	{
		_capacity = capacity;
		
		T* newData = new T[_capacity];

		for (int i = 0; i < _size; i++)
		
			newData[i] = _data[i];	

		if(_data != nullptr)
			delete[] _data;
		
		_data = newData;
	}

	T& operator[] (const int pos) { return _data[pos]; }

	int size() { return _size; }
	int capacity() { return _capacity; }

public:
	typedef Iterator<T> iterator;

	void clear() { _size = 0; }
	iterator begin() { return iterator (&_data[0]); }
	iterator end() { return begin() + _size; }
private:
	T* _data;
	int _capacity;
	int _size;
};
int main()
{
	Vector<int> v;

	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
		cout << v.size() << " " << v.capacity() << endl;
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	v.reserve(1000);
	cout << v.size() << " " << v.capacity() << endl;

	for (Vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{ 
		cout << (*it) << endl;
	}
}