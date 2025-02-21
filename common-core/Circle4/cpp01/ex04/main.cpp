#include "includes.h"

bool check_file(std::string& file)
{
    struct stat file_stat;
    if (stat(file.c_str(), &file_stat) == -1)
    {
        if (errno == ENOENT)
            std::cerr << "Error: File does not exist." << std::endl;
        else if (errno == EACCES)
            std::cerr << "Error: Permission denied." << std::endl;
        else
            std::cerr << "Error: Cannot stat file. Errno: " << errno << std::endl;
        return false;
    }
    if (!S_ISREG(file_stat.st_mode))
    {
        std::cerr << "Error: Not a regular file." << std::endl;
        return false;
    }
    return true;
}

bool open_file(std::ifstream& file, std::string& filename)
{
    try
    {
        file.exceptions(std::ios::failbit | std::ios::badbit);
        file.open(filename.c_str());
        file.exceptions(std::ios::goodbit);
    }
    catch (const std::ios_base::failure& e)
    {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        return false;
    }
    return true;
}

bool open_file(std::ofstream& file, std::string& filename)
{
    try
    {
        file.exceptions(std::ios::failbit | std::ios::badbit);
        file.open(filename.c_str());
    }
    catch (const std::ios_base::failure& e)
    {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        return false;
    }
    return true;
}

void replaceStrings(std::ofstream& output, std::string s1, std::string s2, std::string line)
{
    size_t pos;

    if (s1.empty())
    {
        output << line;
        return;
    }
    pos = line.find(s1);
    while (pos != std::string::npos)
    {
        output << line.substr(0, pos);
        output << s2;
        line = line.substr(pos + s1.length());
        pos  = line.find(s1);
    }
    output << line;
}

int main(int ac, char** av)
{
    if (ac != 4)
    {
        std::cout << "Usage: " << av[0] << " <filename> <string to replace> <string replacing>"
                  << std::endl;
        return 1;
    }
    std::string filename    = av[1];
    std::string fileReplace = filename + ".replace";
    std::string s1          = av[2];
    std::string s2          = av[3];
    if (!check_file(filename))
        return 1;
    std::ifstream input;
    if (!open_file(input, filename))
        return 1;
    std::ofstream output;
    if (!open_file(output, fileReplace))
        return 1;
    std::string line;
    while (std::getline(input, line))
        replaceStrings(output, s1, s2, line + '\n');
}
