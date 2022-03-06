#include <iostream>
struct IntArray {
private:
	int elements[20];
	int size = 0;
public:
	int getSize()const { return size; }
	int getElemFromIndex(int index);
	void add(int el);
	void removeFromIndex(int index);
};
int IntArray::getElemFromIndex(int index)
{
	if (index < 0 || index >= size)
	{
		std::cout << "ERROR" << std::endl;
		return -1;
	}
	return elements[index];
}
void IntArray::add(int el)
{
	elements[size] = el;
	size++;
}
void IntArray::removeFromIndex(int index)
{
	if (index < 0 || index >= size)
	{
		std::cout << "ERROR" << std::endl;
	}
	for (int i = index; i < size-1; i++)
	{
		elements[i] = elements[i + 1];
	}
	size--;
}
void addElemToArray(IntArray* array, int elem)
{
	array->add(elem);
}
int getArraySize(IntArray* array)
{
	return array->getSize();
}
int getArrayElem(IntArray* array, int elem)
{
	return array->getElemFromIndex(elem);
}
void removeElemFromArray(IntArray* array, int index)
{
	array->removeFromIndex(index);
}

int main()
{
	
	IntArray array; addElemToArray(&array, 4);
	array.add(5);
	for (int i = 0; i < array.getSize(); i++) {
		std::cout << getArrayElem(&array, i) << " ";
	}//трябва да изведе: “4 5 ”
	removeElemFromArray(&array, 0);
	std::cout<<getArraySize(&array)<<" "; //трябва да изведе 1
	std::cout<<getArrayElem(&array, 0); //трябва да изведе 5
	
}