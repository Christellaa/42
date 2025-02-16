#ifndef CONTACT_HPP
#define CONTACT_HPP
#include "includes.h"

class Contact
{
  public:
    void setFirstName();
    void setLastName();
    void setNickName();
    void setPhone();
    void setSecret();

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickName() const;
    std::string getPhone() const;
    std::string getSecret() const;

  private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickName;
    std::string _phone;
    std::string _secret;
};

#endif
