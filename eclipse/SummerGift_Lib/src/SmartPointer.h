#ifndef SMARTPOINTER_H_
#define SMARTPOINTER_H_

#include <iostream>

namespace SGLib
{


template <typename T>
class SmartPointer
{

protected:
	T* m_pointer;

public:
    SmartPointer(T* p = NULL)
    {
		m_pointer = p;
    }

	T* operator-> ()
	{
		return m_pointer;
	}

	T& operator* ()
	{
		return *m_pointer;
	}

	bool isNull()
	{
		return (m_pointer == NULL);
	}

	T* get()
	{
		return m_pointer;
	}

	~SmartPointer()
	{
		delete m_pointer;
	}

};

}

#endif /* SMARTPOINTER_H_ */
