#include "userbuilder.h"


UserBuilder::UserBuilder()
{

}

void UserBuilder::setId(long long value) {
    product->id = value;
}

void UserBuilder::setName(QString value) {
    product->name = value;
}

void UserBuilder::setPhoneNumber(QString value) {
    product->phoneNumber = value;
}

void UserBuilder::setEmail(QString value) {
    product->email = value;
}

void UserBuilder::setPassword(QString value) {
    product->password = value;
}

void UserBuilder::setPassportNumber(QString value) {
    product->passportNumber = value;
}

void UserBuilder::setRole(UserRole value) {
    product->role = value;
}
