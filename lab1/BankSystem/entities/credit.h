#ifndef CREDIT_H
#define CREDIT_H


class Credit
{
public:
    Credit();

    void calc();

    long long id;
    long long owner;
    double finance;
    double stake;
    int term;

};

#endif // CREDIT_H
