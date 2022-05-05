#ifndef BUILDER_H
#define BUILDER_H

template<class T>
class Builder
{
public:
    Builder() { reset(); }
    ~Builder() { delete product; }
    void reset() { product = new T(); }
    T *getResult() {
        T *result = product;
        reset();
        return result;
    };
protected:
    T *product;
};

#endif // BUILDER_H
