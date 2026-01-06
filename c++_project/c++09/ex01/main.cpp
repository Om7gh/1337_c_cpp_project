 
 #include "RPN.hpp"


 int main(int ac, char **av)
 {
        try
        {
                if (ac != 2)
                        throw std::invalid_argument("Error: enter a sequence of number to run the program");
                std::string input = av[1];
                int output = RPN( input );
                std::cout << output << std::endl;
        }
        catch(const std::exception& e)
        {
                std::cerr << e.what() << '\n';
        }
        
        return 0;
 }
