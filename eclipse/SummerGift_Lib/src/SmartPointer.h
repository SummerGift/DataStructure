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

    //拷贝构造函数，如果发生指针赋值，那么赋值之后让原来的指针指向NULL
    SmartPointer(const SmartPointer<T>& obj)
    {
    	m_pointer = obj.m_pointer;
    	//const_cast强制类型转换，去除一个对象的const属性
    	const_cast<SmartPointer<T>&>(obj).m_pointer = NULL;
    }

   //重载 = 操作符
    SmartPointer<T>& operator= (const SmartPointer<T>& obj)
    {
    	if (this != &obj)
    	{
    		//放掉 m_pointer 自身所指向的内存
    		delete m_pointer;
    		//指向所赋值的空间，然后让原指针指向NULL
    		m_pointer = obj.m_pointer;
    		const_cast<SmartPointer<T>&>(obj).m_pointer = NULL;
    	}

    	return *this;
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
