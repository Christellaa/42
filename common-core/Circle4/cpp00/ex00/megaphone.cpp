#include <cstdio>
#include <iostream>
#include <string>

int main(int ac, char **av) {
  size_t i;

  if (ac < 2) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (0);
  }
  std::string sentence;
  i = 1;
  while (av[i])
    sentence += av[i++];
  i = 0;
  while (i < sentence.length())
    putchar(toupper(sentence[i++]));
}
