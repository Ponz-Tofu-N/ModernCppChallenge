#include <vector>
#include <numeric>

#define TYPENAME_T template <typename T, unsigned int C, unsigned int R>

TYPENAME_T
class Array2d
{
private:
    class iterator
    {
    private:
        int pos;
        const Array2d<T, C, R> &ref;

        iterator &operator=(const iterator &);

    public:
        iterator(const int pos_, const Array2d<T, C, R> &root_) : pos(pos_), ref(root_) {}
        iterator(const Array2d<T, C, R> &root_) : pos(0), ref(root_) {}

        iterator &operator+(const int);
        iterator &operator++();
        iterator &operator-(const int);
        iterator &operator--();

        T operator*();

        friend Array2d<T, C, R>;
    };

    std::vector<std::vector<T>> array2d;

public:
    Array2d();
    Array2d(std::initializer_list<T>);
    Array2d(const std::vector<std::vector<T>> &);
    Array2d(const Array2d<T, C, R> &);
    Array2d(Array2d<T, C, R> &&);
    ~Array2d();

    T data(const unsigned int, const unsigned int);
    Array2d<T, C, R> &swap(Array2d<T, C, R> &);
    unsigned int size();
    iterator begin();
    iterator end();
    void output();

    bool operator==(const Array2d<T, C, R> &);
    Array2d<T, C, R> &operator=(Array2d<T, C, R> &&);
};

TYPENAME_T
Array2d<T, C, R>::Array2d()
    : array2d(std::vector<std::vector<T>>())
{
    array2d.reserve(C);
    for (auto &&arr : array2d)
    {
        arr.reserve(R);
    }
}

TYPENAME_T
Array2d<T, C, R>::~Array2d()
{
}

TYPENAME_T
Array2d<T, C, R>::Array2d(std::initializer_list<T> c)
    :array2d(c.begin(), c.end())
{
}

TYPENAME_T
Array2d<T, C, R>::Array2d(const std::vector<std::vector<T>> & init)
    :array2d(init)
{

}

TYPENAME_T
Array2d<T, C, R>::Array2d(const Array2d<T, C, R> &other)
    : array2d(other.array2d)
{
}

TYPENAME_T
T Array2d<T, C, R>::data(const unsigned int column, const unsigned int row)
{
    if (row < R && column < C)
        return array2d.at(column).at(row);

    return NULL;
}

TYPENAME_T
Array2d<T, C, R>::Array2d(Array2d<T, C, R> &&other)
    : array2d(other.array2d)
{
}

TYPENAME_T
Array2d<T, C, R> &Array2d<T, C, R>::swap(Array2d<T, C, R> &other)
{
    this->array2d.swap(other.array2d);
    return *this;
}

TYPENAME_T
unsigned int Array2d<T, C, R>::size()
{
    std::size_t size = 0;
    for (auto array : array2d)
    {
        size += array.size();
    }

    return size;
}

TYPENAME_T
void Array2d<T, C, R>::output()
{
    for (auto array : array2d)
    {
        for (auto element : array)
        {
            std::cout << element << " ";
        }

        std::cout << "\n";
    }
}

TYPENAME_T
bool Array2d<T, C, R>::operator==(const Array2d<T, C, R> &other)
{
    return std::equal(array2d.begin(), array2d.end(), other.array2d.begin(), other.array2d.end());
}

TYPENAME_T
Array2d<T, C, R> &Array2d<T, C, R>::operator=(Array2d<T, C, R> && other)
{
    *this->array2d = other.array2d;
}

/* iterator class implementation */
TYPENAME_T
typename Array2d<T, C, R>::iterator &Array2d<T, C, R>::iterator::operator+(const int length)
{
    if ((length + this->pos) < (C * R))
    {
        this->pos += length;
    }

    return *this;
}

TYPENAME_T
typename Array2d<T, C, R>::iterator &Array2d<T, C, R>::iterator::operator++()
{
    this->pos += 1;
    return *this;
}

TYPENAME_T
typename Array2d<T, C, R>::iterator &Array2d<T, C, R>::iterator::operator-(const int length)
{
    if ((this->pos - length) > 0)
    {
        this->pos -= length;
    }

    return *this;
}

TYPENAME_T
typename Array2d<T, C, R>::iterator &Array2d<T, C, R>::iterator::operator--()
{
    this->pos -= 1;
    return *this;
}

TYPENAME_T
T Array2d<T, C, R>::iterator::operator*()
{
    return this->ref.array2d[static_cast<int>(this->pos / R)][this->pos % R];
}

TYPENAME_T
typename Array2d<T, C, R>::iterator Array2d<T, C, R>::begin()
{
    return iterator(0, *this);
}

TYPENAME_T
typename Array2d<T, C, R>::iterator Array2d<T, C, R>::end()
{
    return iterator(C * R - 1, *this);
}

TYPENAME_T
typename Array2d<T, C, R>::iterator &Array2d<T, C, R>::iterator::operator=(const Array2d<T, C, R>::iterator &other)
{
    this->pos = other.pos;

    return *this;
}