template <typename T>
class Queue
{
public:
	Queue(int size);
	Queue(const Queue& other);
	~Queue();
	bool isFull() const;
	bool isEmpty() const;

	bool Enqueue(T item);
	T* Dequeue();
	void PrintAll() const;
	size_t SizeCount() const;
	size_t RemoveFront(size_t amount);
private:
	int Head;
	int Tail;
	int Size;
	T* Data;
};

template <typename T>
Queue<T>::Queue(int size)
{
	Head = Tail = 0;
	Size = size + 1;
	Data = new T[Size];
}
template <typename T>
Queue<T>::Queue(const Queue& other) : Size(other.Size), Head(other.Head), Tail(other.Tail) {
	this->Data = new T[Size];

	for (size_t i = 0; i < Size; i++) {
		this->Data[i] = other.Data[i];
	}
}
template <typename T>
Queue<T>::~Queue()
{
	delete[] Data;
}

template <typename T>
bool Queue<T>::isFull() const
{
	return (Head % Size == (Tail + 1) % Size);
}

template <typename T>
bool Queue<T>::isEmpty() const
{
	return Head == Tail;
}

template <typename T>
bool Queue<T>::Enqueue(T item)
{
	if (!isFull())
	{
		Data[Tail] = item;
		Tail = (Tail + 1) % Size;
		return true;
	}
	return false;
}

template <typename T>
T* Queue<T>::Dequeue()
{
	if (!isEmpty())
	{
		T item = Data[Head];
		Head = (Head + 1) % Size;
		return &item;
	}
	return nullptr;
}

template <typename T>
void Queue<T>::PrintAll() const {
	size_t current = Head;

	while (current != Tail) {
		std::cout << Data[current] << " ";
		current = (current + 1) % Size;
	}

	std::cout << std::endl;
}
template <typename T>
size_t Queue<T>::SizeCount() const
{
	size_t size = 0;
	size_t current = Head;

	while (current != Tail) {
		size++;
		current = (current + 1) % Size;
	}

	return size;
}
template <typename T>
size_t Queue<T>::RemoveFront(size_t amount)
{
	size_t count = 0;
	while (!isEmpty() && amount-- != 0)
	{
		Dequeue();
		count++;
	}
	return count;
}