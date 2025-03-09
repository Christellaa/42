#include "Serializer.hpp"

int main()
{
    Data data = {13, 'm', 55.12, "Hello !"};
    std::cout << "Original data address: " << &data << std::endl;
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized: " << raw << std::endl;
    Data* deseralized = Serializer::deserialize(raw);
    std::cout << "Deserialized: " << deseralized << std::endl;
    std::cout << "Values: " << deseralized->i << ", " << deseralized->c << ", " << deseralized->f
              << ", " << deseralized->s << std::endl;
    // deserialized must give the original pointer
    if (deseralized == &data)
        std::cout << "Success: Pointers match" << std::endl;
    else
        std::cout << "Error: Pointers do not match" << std::endl;
}
