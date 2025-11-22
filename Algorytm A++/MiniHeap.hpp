//Github Link: https://github.com/BigWheel92/Min-Heap/tree/master
//Modified by tutekxd123(Piotr Marzec)

#pragma once
#include <assert.h>
#include <algorithm>
#include <unordered_set>

template <typename k, typename v, typename hash>
class MinHeap
{
	//each item in heap will be HeapItem (a <key, value> pair). Both key and value can be of the same datatype or different data type.
	// Key and value can be of a user-defined class as well. If key is of non-primitive datatype, then the > and < operators must be overloaded.
	struct HeapItem
	{
		k key;
		v value;
	};


private:

	HeapItem* arr;
	int capacity;
	int totalItems;
	std::unordered_map<v, int, hash> valueToIndex;

	void doubleCapacity()
	{
		if (this->arr == nullptr)
		{
			this->arr = new HeapItem[1];
			this->capacity = 1;
			this->lengthoperations += 2;
			return;
		}

		int newCapacity = capacity * 2;
		HeapItem* newArr = new HeapItem[newCapacity];
		this->lengthoperations += 2;
		for (int i = 0; i < this->totalItems; i++)
		{
			this->lengthoperations += 1;
			newArr[i] = this->arr[i];
		}

		// usuñ star¹ tablicê (delete[] bo to tablica)
		if (this->arr != nullptr) {
			delete[] this->arr;
			this->lengthoperations += 1;
		}

		this->capacity = newCapacity;
		this->arr = newArr;
		this->lengthoperations += 2;

		// ODTWORZ mapê valueToIndex dla nowych indeksów
		for (int i = 0; i < this->totalItems; ++i) {
			this->valueToIndex[this->arr[i].value] = i;
		}
	}

	void shiftUp(int index)
	{
		if (index < 1) {
			this->lengthoperations += 1;
			return;
		}


		int parent = (index - 1) / 2;

		if (this->arr[index].key < this->arr[parent].key)
		{
			swapItems(index, parent);
			//std::swap(this->arr[index], this->arr[parent]);
			shiftUp(parent);
		}
		this->lengthoperations += 1;
		return;
	}
	void swapItems(int index1, int index2) {
		if (index1 == index2) return;
		std::swap(this->arr[index1], this->arr[index2]);
		this->valueToIndex[this->arr[index1].value] = index1;
		this->valueToIndex[this->arr[index2].value] = index2;
		this->lengthoperations += 5;
	}
	void shiftDown(int index)
	{
		int minIndex = -1;
		int lChildIndex = index * 2 + 1;
		int rChildIndex = (index * 2) + 2;
		this->lengthoperations += 3;
		if (lChildIndex < totalItems)
		{
			this->lengthoperations += 1;
			if (arr[index].key > arr[lChildIndex].key)
			{
				this->lengthoperations += 1;
				minIndex = lChildIndex;
			}
		}

		if (rChildIndex < totalItems)
		{
			if (arr[(minIndex == -1 ? index : minIndex)].key > arr[rChildIndex].key)
			{
				minIndex = rChildIndex;
				this->lengthoperations += 1;
			}
		}

		if (minIndex == -1)
			return;

		//std::swap(arr[index], arr[minIndex]);
		swapItems(index, minIndex);
		shiftDown(minIndex);


	}

public:
	int lengthoperations = 0;
	std::unordered_set<v, hash> setsofitems;
	MinHeap()
	{
		this->arr = nullptr;
		this->capacity = 0;
		this->totalItems = 0;
	}

	MinHeap(int _capacity)
	{
		assert(_capacity >= 1);

		this->arr = new HeapItem[_capacity];
		this->capacity = _capacity;
		this->totalItems = 0;
	}

	void insert(k const key, v const value)
	{
		if (this->totalItems == this->capacity)
		{
			this->lengthoperations += 1;
			doubleCapacity();
		}

		this->setsofitems.insert(value);

		this->arr[totalItems].key = key;
		this->arr[totalItems].value = value;
		this->valueToIndex[value] = totalItems;
		this->lengthoperations += 4;
		shiftUp(totalItems);
		this->totalItems++;
		this->lengthoperations += 1; //shiftup sam liczy
		//iterative shift up
		//for (int i =this->totalItems; i >= 2 && (this->arr[i].key < this->arr[i / 2].key); i=i/ 2)
		//{
		//	swap(this->arr[i], this->arr[i / 2]);
		//}

	}



	void getMin(v& value)
	{
		assert(totalItems != 0);

		value = this->arr[0].value;
		this->lengthoperations += 2;
	}

	void deleteMin()
	{
		assert(totalItems != 0);
		auto removedValue = this->arr[0].value;
		swapItems(0, totalItems - 1);
		totalItems--;
		this->setsofitems.erase(removedValue);
		this->valueToIndex.erase(removedValue);

		this->lengthoperations += 7;
		if (totalItems > 0)
			shiftDown(0);
	}

	bool isEmpty()
	{
		this->lengthoperations += 1;//metoda moglaby byc const ale modyfikujemy operacje
		return (totalItems == 0);
	}

	//Update length trzeba
	void update(k const newKey, v const value) {

		auto it = this->valueToIndex.find(value); //O(1)?
		if (it == this->valueToIndex.end()) {
			this->lengthoperations +=2;
			return;
		}
		int index = it->second;
		k oldKey = arr[index].key;
		arr[index].key = newKey;
		//Sortujemy po key wiec ma to sens
		//Jezeli klucz zmalal? to przesuwamy w gore
		this->lengthoperations += 5;

		if (newKey < oldKey) {
			shiftUp(index);
		}
		// jeœli klucz wzorsl to przesuwamy w dol
		else if (newKey > oldKey) {
			shiftDown(index);
		}
		this->lengthoperations += 2;
	}

	void deleteAll()
	{
		if (this->arr != nullptr)
		{
			delete[]arr;
			arr = nullptr;
			this->capacity = 0;
			this->totalItems = 0;
			this->lengthoperations += 4;
		}
		this->lengthoperations += 1;

	}

	~MinHeap()
	{
		deleteAll();
	}
	bool contains(const v& value)  {
		this->lengthoperations += 1; //metoda moze byc const jezeli nie dodajemy operacji
		return this->setsofitems.contains(value);
	}
};