#ifndef ID_H
#define ID_H


class Id
{
public:
    static long long getNewId();
    static void setId(long long);

private:
    Id();
    static long long index;
};


#endif // ID_H
