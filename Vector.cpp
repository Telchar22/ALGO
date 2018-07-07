#include<iostream>

using namespace std;


template <class T>
class KajVec
{
public:

	KajVec() : size(2), elements(0)
	{
		arr = new T[size];
	}
	~KajVec()
	{
		delete[] arr;
	}

private:
	T *arr;
	int size;
	int elements;

public:
	int currentElements()const
	{
		return elements;
	}
	T& operator[](const int i)
	{
		return arr[i];
	}
	const T& operator[](const int i) const
	{
		return arr[i];
	}
	void pushback(const T& value)
	{
		resize();
		arr[elements] = value;
		++elements;
	}
	void pop()
	{
		if (elements > 0)
		{
			--elements;
		}
	}
	void insert(const T& value, const int index)
	{
		resize();
		if (elements > 0 && elements > index)
		{
			for (int j = elements; j > index; --j)
			{
				arr[j] = arr[j - 1];
			}
		}
		++elements;
		arr[index] = value;
	}

private:
	void resize()
	{
		if (elements + 1 <= size) return;
		size *= 2;
		int*arr2 = new int[size];
		for (int i = 0; i < elements; i++)
		{
			arr2[i] = arr[i];
		}
		delete[] arr;
		arr = arr2;
	}
};



int main() {

	
	return 0;
}