#include "vector.hh"

Vector::Vector(const Vector &v) : coords_{std::make_unique<value[]>(v.size_)}, size_{v.size_}
{
    for (int i = 0; i < v.size_; i++)
    {
        this->coords_[i] = v[i];
    }
}

Vector::Vector(std::initializer_list<value> l) : coords_{std::make_unique<value[]>(l.size())}, size_{l.size()}
{
    auto it = l.begin();

    for (int i = 0; i < l.size(); i++)
    {
        this->coords_[i] = *(it + i);
    }
}

Vector::Vector(size_t N) : coords_{std::make_unique<value[]>(N)}, size_{N}
{
    for (int i = 0; i < N; i++)
    {
        this->coords_[i] = 0;
    }
}

Vector &Vector::operator=(const Vector &v)
{
    if (this->size_ != v.size_)
    {
        this->coords_ = std::make_unique<value[]>(v.size_);
        this->size_ = v.size_;
    }

    for (int i = 0; i < v.size_; i++)
    {
        this->coords_[i] = v[i];
    }

    return *this;
}

size_t Vector::size() const
{
    return this->size_;
}

Vector &Vector::operator+=(const Vector &v)
{
    if (this->size_ != v.size_)
    {
        std::runtime_error(INCOMPATIBLE_SIZE_MSG);
    }

    for (int i = 0; i < v.size_; i++)
    {
        this->coords_[i] += v.coords_[i];
    }

    return *this;
}

Vector &Vector::operator-=(const Vector &v)
{
    if (this->size_ != v.size_)
    {
        std::runtime_error(INCOMPATIBLE_SIZE_MSG);
    }

    for (int i = 0; i < v.size_; i++)
    {
        this->coords_[i] -= v.coords_[i];
    }

    return *this;
}

Vector &Vector::operator+=(value k)
{
    for (int i = 0; i < this->size_; i++)
    {
        this->coords_[i] += k;
    }

    return *this;
}

Vector &Vector::operator*=(const value k)
{
    for (int i = 0; i < this->size_; i++)
    {
        this->coords_[i] *= k;
    }

    return *this;
}

Vector Vector::operator+(const Vector &v) const
{
    if (this->size_ != v.size_)
    {
        std::runtime_error(INCOMPATIBLE_SIZE_MSG);
    }

    auto newVec = Vector{};

    for (int i = 0; i < this->size_; i++)
    {
        newVec.coords_[i] = this->coords_[i] + v.coords_[i];
    }

    return newVec;
}

Vector Vector::operator+(value k) const
{
    auto newVec = Vector{};

    for (int i = 0; i < this->size_; i++)
    {
        newVec.coords_[i] = this->coords_[i] + k;
    }

    return newVec;
}

value Vector::operator*(const Vector &v) const
{
    value dotProduct = 0;

    for (int i = 0; i < this->size_; i++)
    {
        dotProduct += this->coords_[i] * v.coords_[i];
    }

    return dotProduct;
}

Vector Vector::operator*(value k) const
{
    auto newVec = Vector{};

    for (int i = 0; i < this->size_; i++)
    {
        newVec.coords_[i] = this->coords_[i] * k;
    }

    return newVec;
}

value &Vector::operator[](size_t idx)
{
    return this->coords_[idx];
}

value Vector::operator[](size_t idx) const
{
    return this->coords_[idx];
};

std::ostream &operator<<(std::ostream &os, const Vector &v)
{
    os << "{";

    for (int i = 0; i < v.size() - 1; i++)
    {
        os << v[i] << ',';
    }

    os << v[v.size() - 1] << "}";

    return os;
}

Vector operator+(const value &s, const Vector &v)
{
    auto newVec = Vector{};

    for (int i = 0; i < v.size(); i++)
    {
        newVec[i] = v[i] + s;
    }

    return newVec;
}

Vector operator*(const value &s, const Vector &v)
{
    auto newVec = Vector{};

    for (int i = 0; i < v.size(); i++)
    {
        newVec[i] = v[i] * s;
    }

    return newVec;
}