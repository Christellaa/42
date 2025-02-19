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

    std::string const& getFirstName() const;
    std::string const& getLastName() const;
    std::string const& getNickName() const;
    std::string const& getPhone() const;
    std::string const& getSecret() const;

  private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickName;
    std::string _phone;
    std::string _secret;
};

bool areFieldsFilled(const Contact& contact);

#endif
