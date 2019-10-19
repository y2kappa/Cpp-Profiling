#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>
#include <iostream>

template<typename T>
class Vector {

public:

    class Iterator {
    public:
        Iterator(T* data): m_data(data) { }
        Iterator operator++() {++m_data; return *this;}
        bool operator!=(const Iterator& other) const { return m_data != other.m_data; }
        const T& operator*() const { return *m_data; }
        T& operator*() { return *m_data; }

    private:
        T* m_data;
    };

    Vector() :
        m_size(0),
        m_capacity(10),
        m_data(new T[10])
    {

    }

    Vector(unsigned int size) :
        m_size(size),
        m_capacity(size),
        m_data(new T[size])
    {

    }

    void push_back(const T& value)
    {
        if (m_capacity > m_size)
        {
            m_data[m_size] = value;
        }
        else
        {
            m_capacity = m_capacity * 2;
            T* new_data = new T[m_capacity];
            for (int i = 0; i < m_size; i++)
            {
                new_data[i] = m_data[i];
            }
            new_data[m_size] = value;

            delete [] m_data;
            m_data = new_data;
        }

        m_size += 1;

    }

    const T& get(unsigned int index)
    {
        if (index >= m_size)
        {
            throw std::out_of_range("out of bounds");
        }
        else
        {
            return m_data[index];
        }
    }

    const T& operator[](unsigned int index) { return get(index); }

    unsigned int size() const
    {
        return m_size;
    }

    Iterator begin() { return Iterator(m_data); }
    Iterator end() { return Iterator(m_data+m_size); }


private:
    unsigned int m_size;
    unsigned int m_capacity;
    T* m_data;
};


#endif