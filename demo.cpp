#include <cstdlib>
#include <iostream>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cout << "Please input two arguments. (number of backend, number of frontend)" << std::endl;
        return 0;
    }
    else
    {
        int nb = std::stoi(argv[1]);
        if (nb <= 0)
        {
            std::cout << "number of backend should be greater than 0" << std::endl;
            return 0;
        }
        int nf = std::stoi(argv[2]);
        if (nf <= 0)
        {
            std::cout << "number of frontend should be greater than 0" << std::endl;
            return 0;
        }

        system("dbus-launch gnome-terminal -- \"./proxy\"");

        for (int i = 0; i < nb; i++)
            system("dbus-launch gnome-terminal -- \"./backend\"");
        for (int i = 0; i < nf; i++)
            system("dbus-launch gnome-terminal -- \"./frontend\"");
    }
}
