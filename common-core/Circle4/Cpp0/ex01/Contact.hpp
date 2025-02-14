#ifndef CONTACT_HPP
# define CONTACT_HPP
# include "includes.h"

class Contact
{
  public:
	// getters and setters
	void setFirstName() noexcept;
	void setLastName() noexcept;
	void setNickName() noexcept;
	void setPhone() noexcept;
	void setSecret() noexcept;

  private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _phone;
	std::string _secret;
};

#endif
