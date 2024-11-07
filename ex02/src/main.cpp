#include <iostream>

std::string buildStr(char **av)
{
    std::string str;
    int i = 2;

    while (av[i] && av[i + 1])
    {
        str += av[i];
        str += " ";
        i++;
    }
    str += av[i];
    return str;
}


void convertUp (std::string &str)
{
    size_t size = str.size();
    for (size_t i = 0; i < size; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
    }
}

void convertDown (std::string &str)
{
    size_t size = str.size();
    for (size_t i = 0; i < size; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
    }
}

int main (int ac, char **av)
{
    if (ac < 3)
    {
        std::cerr << "Wrong number of args" << std::endl; 
        return 0;
    }
    std::string convertType = av[1];
    std::string result;
    if (convertType == "up")
    {
        result = buildStr(av);
        convertUp(result);
    }
    else if (convertType == "down")
    {
        result = buildStr(av);
        convertDown(result);
    }
    else
    {
        std::cerr << "Wrong number of args" << std::endl;
        return 0;
    }
    std::cout << result << std::endl;
    return 1;
}