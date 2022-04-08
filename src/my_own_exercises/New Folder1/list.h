#ifndef LIST_H
#define LIST_H 

#include <iostream>
using namespace std;

template <class T>
	class Node 
	{
	public:
		T data;
		Node<T>* nextNode;
		Node()
		{
			data = 0;
		}
		Node(T d)
		{
			data = d;
		}
		void setData(T d)
		{
			data = d;
		}
		T getData()
		{
			return data;
		}
		void setNextNode(Node<T>* n)
		{
			nextNode = n;
		}
		Node<T>* getNextNode()
		{
			return nextNode;
		}
	};	
template<class T>
	class Iterator
	{
	private:
		Node<T>* position;
	public:
		Iterator()
		{
			position = 0;
		}
		Iterator(Node<T>* p)
		{
			position = p;
		}
		Node<T>* getPosition()
		{
			return position;
		}
		void setPosition(Node<T>* p)
		{
			position = p;
		}
		T operator*()
		{
			return (*position).getData();
		}
		void operator++()
		{
			position = position->getNextNode();
		}
		/*Iterator operator++(int)
		{
			
			//Iterator temp = new Iterator();
			//temp = this;
			double temp;
			temp = this->position->getData();
			++position;
			//return temp;
		}*/
		bool operator==( Iterator b)
		{
			if(getPosition() == b.getPosition())
				return true;
			else
				return false;
		}
		bool operator!=( Iterator b)
		{
			if(getPosition() != b.getPosition())
				return true;
			else
				return false;
		}
	}; 
	
template<class T>
	class List 
	{
		Node<T>* firstNode;
		Node<T>* lastNode;
		int totalNodes;
	public:
		List()
		{
			firstNode = 0;
			lastNode = 0;
			totalNodes = 0;
		}
		~List()
		{
			delete firstNode;
			delete lastNode;
		}
		Node<T>* getFirstNode()
		{
			return firstNode;
		}
		Node<T>* getLastNode()
		{
			return lastNode;
		}
		void setFirstNode(Node<T>* n)
		{
			firstNode = n;
		}
		void setLastNode(Node<T>* n)
		{
			lastNode = n;
		}
		int getTotalNodes()
		{
			return totalNodes;
		}
		void setTotalNodes(int n)
		{
			totalNodes = n;
		}
		List(List& origList)
		{
			Iterator<T> iter = origList.begin();
			List newList;
			while(iter != origList.end())
			{
				T temp = iter.getPosition()->getData();
				newList.push_back(temp);
				++iter;
			}
			newList.setFirstNode(origList.getFirstNode());
			newList.setLastNode(origList.getLastNode());
			newList.setTotalNodes(origList.getTotalNodes());
		}
		List& operator=(List& b)
		{
			Iterator<T> iterDelete = begin();
			while(iterDelete != end())
			{
				delete iterDelete.getPosition();
				++iterDelete;
			}
			Iterator<T> iter = b.begin();
			while(iter != b.end())
			{
				T temp = iter.getPosition()->getData();
				push_back(temp);
				++iter;
			}
			setFirstNode(b.getFirstNode());
			setLastNode(b.getLastNode());
			setTotalNodes(b.getTotalNodes());
			return *this;
		}
		void push_back(const T& n)
		{
			Node<T>* newNode = new Node<T>(n);
			if(totalNodes == 0)
			{
				setFirstNode(newNode);
				setLastNode(newNode);
				newNode->setNextNode(0);
			}
			else
			{
				lastNode->setNextNode(newNode);
				setLastNode(newNode);
				newNode->setNextNode(0);
			}
			++totalNodes;
		}
		Iterator<T> begin()
		{
			Iterator<T> temp(firstNode);
			return temp;
		}
		Iterator<T> end()
		{
			Iterator<T> temp(0);
			return temp;
		}
		int size() const
		{
			return totalNodes;
		}
	};
#endif
