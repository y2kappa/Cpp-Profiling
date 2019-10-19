#ifndef VECTOR_H
#define VECTOR_H

template<typename T>
class Vector
{

public:
    Vector();

    push_back(const T &value);

    size_t size() const noexcept;

    const T& get(const size_t& index) const;
    T& get(const size_t& index);

private:
    T* m_data;
    size_t m_size;
    size_t m_capacity;
};

#endif