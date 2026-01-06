
#include "PmergeMe.hpp"

int main(int ac, char **av)
{
        try
        {
                if (ac <= 2)
                        throw std::invalid_argument("Error: enter a sequence of number");
                pmergeInsertionVect(ac, av);
                pmergeInsertionDeque(ac, av);
        }
        catch(const std::exception& e)
        {
                std::cerr << e.what() << '\n';
        }
        return (0);
}
