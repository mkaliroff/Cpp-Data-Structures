#ifndef __MY_QUEUE_HPP__
#define __MY_QUEUE_HPP__

#include <cstddef>  // size_t
#include <stdexcept> // exceptions

namespace my_stl
{

template<class T>
class my_queue
{
    public:

    my_queue();
    ~my_queue() noexcept;
    my_queue(const my_queue& other);
    my_queue& operator=(const my_queue& other);

    T& front();
    const T& front() const;
    T& back();
    const T& back() const;

    bool empty() const noexcept;
    size_t size() const noexcept;

    void push(const T& value);
    T pop();

    private:
    size_t m_size;
};


} // my_stl

#endif /* __MY_QUEUE_HPP__ */

