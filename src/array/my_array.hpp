#ifndef __MY_ARRAY_HPP__
#define __MY_ARRAY_HPP__

#include <cstddef>  // size_t
#include <stdexcept> // exceptions

namespace my_stl
{

template<class T, std::size_t N>
class my_array
{
    public:

    my_array();
    my_array(const T& value);
    ~my_array() noexcept;
    my_array(const my_array& other);
    my_array& operator=(const my_array& other);
    T& at(std::size_t pos);
    const T& at(std::size_t pos) const;
    T& operator[](std::size_t pos);
    const T& operator[](std::size_t pos) const;
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
    bool empty() const noexcept;
    size_t size() const noexcept;
    size_t max_size() const noexcept;
    void fill(const T& value);


    private:
    size_t m_size;
    size_t m_max_size;
    T *m_array;
};
/*****************************************************************************/
template <class T, std::size_t N>
my_array<T, N>::my_array() : m_size(0), m_max_size(N), m_array(new T[m_max_size])
{
    //empty
}
/*****************************************************************************/
template <class T, std::size_t N>
my_array<T, N>::my_array(const T &value) : m_size(0), m_max_size(N), m_array(new T[m_max_size])
{
    fill(value);
}
/*****************************************************************************/
template<class T, std::size_t N>
my_array<T, N>::~my_array() noexcept
{
    delete[] m_array;
}
/*****************************************************************************/
template <class T, std::size_t N>
my_array<T, N>::my_array(const my_array &other) : m_size(other.m_size), m_max_size(other.m_max_size), m_array(new T[m_max_size])
{
    for(std::size_t i = 0 ; i < m_size ; i++)
    {
        m_array[i] = other.m_array[i];
    }
}
template <class T, std::size_t N>
my_array<T, N>& my_array<T, N>::operator=(const my_array& other)
{
    if (this != &other)
    {
        delete[] m_array;

        m_array = new T[N];

        for (std::size_t i = 0; i < N; ++i)
        {
            m_array[i] = other.m_array[i];
        }

        m_size = other.m_size;
        m_max_size = other.m_max_size;
    }

    return *this;
}
/*****************************************************************************/
template <class T, std::size_t N>
T &my_array<T, N>::at(std::size_t pos)
{
    return m_array[pos];
    m_size = pos + 1;
}
/*****************************************************************************/
template <class T, std::size_t N>
const T &my_array<T, N>::at(std::size_t pos) const
{
    return m_array[pos];
}
/*****************************************************************************/
template <class T, std::size_t N>
 T &my_array<T, N>::operator[](std::size_t pos)
{
    if (0 < pos || pos >= m_size)
    {
        throw std::out_of_range("Index out of bounds");
    }
    m_size = pos + 1;
    return m_array[pos];
}
/*****************************************************************************/
template <class T, std::size_t N>
const T &my_array<T, N>::operator[](std::size_t pos) const
{
    if (0 < pos || pos >= m_size)
    {
        throw std::out_of_range("Index out of bounds");
    }
    return m_array[pos];
}
/*****************************************************************************/
template <class T, std::size_t N>
T &my_array<T, N>::front()
{
    if(empty())
    {
        throw std::out_of_range("Array is empty");
    }
    m_size = 1;
    return m_array[0];
}
/*****************************************************************************/
template <class T, std::size_t N>
const T &my_array<T, N>::front() const
{
    if(empty())
    {
        throw std::out_of_range("Array is empty");
    }
    return m_array[0];
}
/*****************************************************************************/
template <class T, std::size_t N>
T &my_array<T, N>::back()
{
    if(empty())
    {
        throw std::out_of_range("Array is empty");
    }
    return m_array[m_size - 1];
}
/*****************************************************************************/
template <class T, std::size_t N>
const T &my_array<T, N>::back() const
{
    if(empty())
    {
        throw std::out_of_range("Array is empty");
    }
    return m_array[m_size - 1];
}
/*****************************************************************************/
template <class T, std::size_t N>
bool my_array<T, N>::empty() const noexcept
{
    return m_size == 0;
}
/*****************************************************************************/
template <class T, std::size_t N>
size_t my_array<T, N>::size() const noexcept
{
    return m_size;
}
/*****************************************************************************/
template <class T, std::size_t N>
size_t my_array<T, N>::max_size() const noexcept
{
    return m_max_size;
}
/*****************************************************************************/
template <class T, std::size_t N>
void my_array<T, N>::fill(const T &value)
{
    for(size_t i = 0; i < m_max_size; i++)
    {
        m_array[i] = value;
    }
    m_size = m_max_size;
}
/*****************************************************************************/
} // my_stl

#endif /* __MY_ARRAY_HPP__ */

