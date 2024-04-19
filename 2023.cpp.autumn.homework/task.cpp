#include <iostream>

struct Node
{
	int data;
	Node* next;
	Node(int data, Node* next = nullptr) : data(data), next(next) {}
	Node(const Node& node) : data(node.data), next(nullptr) {}
	~Node() { data = 0; next = nullptr; }
	friend std::ostream& operator<<(std::ostream& stream, Node*& node)
	{
		stream << node->data << " ";
		return stream;
	}
};

class LinkedList
{
public:
	LinkedList() : head(nullptr)
	{
	}
	~LinkedList()
	{
		dispose();
	}
	int Length();
	bool IsEmpty();
	void PushHead(int data);
	void Insert(int index, int data);
	void PushTail(int data);
	int PopHead();
	int Extract(int index);
	int PopTail();
	int Data(int index);
	void swap(int ia, int ib);
	void sort();
	friend std::ostream& operator<<(std::ostream& stream, const LinkedList& list);
private:
	void dispose();
	int PopData(Node* node);
	void InsertNode(int index, Node* node);
	Node* ExtractNode(int index);
	bool IndexValid(int index);
	Node* head;
};

int main(int argc, char* argv[])
{
	LinkedList list;
	std::cout << list << std::endl;
	list.PushHead(1);
	std::cout << list << std::endl;
	list.PushTail(3);
	std::cout << list << std::endl;
	list.Insert(1, 2);
	std::cout << list << std::endl;
	list.Insert(3, 4);
	std::cout << list << std::endl << std::endl;
	std::cout << list << std::endl;
	std::cout << list.PopHead() << " ";
	std::cout << list.Extract(1) << " ";
	std::cout << list.PopTail() << " ";
	std::cout << list.Extract(0) << std::endl;
	std::cout << list << std::endl << std::endl;

	list.PushHead(3); list.PushHead(4); list.PushHead(1); list.PushHead(2);
	list.PushHead(7); list.PushHead(5); list.PushHead(8); list.PushHead(6);
	std::cout << list << std::endl;
	list.sort();
	std::cout << list << std::endl;
	return EXIT_SUCCESS;
}

bool LinkedList::IndexValid(int index)
{
	return (0 <= index && index < Length());

}

int LinkedList::Length()
{
	int len = 0;
	Node* tmp = head;
	while (tmp != nullptr)
	{
		tmp = tmp->next;
		++len;
	}
	return len;
}

void LinkedList::dispose()
{
	while (head != nullptr)
	{
		Node* tmp = head;
		head = head->next;
		delete tmp;
	}
}

Node* LinkedList::ExtractNode(int index)
{
	if (!IndexValid(index))
	{
		return nullptr;
	}
	if (index == 0)
	{
		Node* tmp = head;
		head = head->next;
		return tmp;
	}
	Node* node = head;
	for (int i = 0; i < index - 1; ++i)
	{
		node = node->next;
	}
	Node* tmp = node->next;
	node->next = tmp->next;
	return tmp;
}

bool LinkedList::IsEmpty()
{
	return head = nullptr;
}

int LinkedList::PopData(Node* node)
{
	if (node == nullptr)
	{
		return 0;
	}
	int tmp = node->data;
	delete node;
	return tmp;
}

void LinkedList::InsertNode(int index, Node* node)
{
	if (head == nullptr)
	{
		node->next = head;
		head = node;
	}
	else
	{
		Node* prevnode = head;
		for (int i = 0; i < index - 1 && prevnode->next != nullptr; ++i)
		{
			prevnode = prevnode->next;
		}
		node->next = prevnode->next;
		prevnode->next = node;
	}
}

int LinkedList::Data(int index)
{
	if (!IndexValid(index))
	{
		return 0;
	}
	Node* node = head;
	for (int i = 0; i < index; ++i)
	{
		node = node->next;
	}
	if (node == nullptr)
	{
		return 0;
	}
	return node->data;

}

int LinkedList::PopTail()
{
	return PopData(ExtractNode(Length() - 1));
}

int LinkedList::Extract(int index)
{
	return PopData(ExtractNode(index));
}

int LinkedList::PopHead()
{
	return PopData(ExtractNode(0));
}

void LinkedList::PushTail(int data)
{
	Node* node = new Node(data);
	InsertNode(Length(), node);
}

void LinkedList::Insert(int index, int data)
{
	Node* node = new Node(data);
	InsertNode(index, node);
}

void LinkedList::PushHead(int data)
{
	Node* node = new Node(data);
	InsertNode(0, node);
}

void LinkedList::swap(int ia, int ib)
{
	if (ia == ib || !IndexValid(ia) || !IndexValid(ib))
	{
		return;
	}
	if (ia > ib)
	{
		std::swap(ia, ib);
	}
	Node* nodeA = ExtractNode(ia);
	Node* nodeB = ExtractNode(ib - 1);
	if (nodeA == nullptr || nodeB == nullptr)
	{
		return;
	}
	InsertNode(ia, nodeB);
	InsertNode(ib, nodeA);
}

void LinkedList::sort()
{
	for (int i = Length() - 1; i >= 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (Data(j) > Data(j + 1))
			{
				swap(j, j + 1);
			}
		}
	}
}

std::ostream& operator<<(std::ostream& stream, const LinkedList& list)
{
	Node* tmp = list.head;
	while (tmp != nullptr)
	{
		stream << tmp << " ";
		tmp = tmp->next;
	}
	return stream;
}

