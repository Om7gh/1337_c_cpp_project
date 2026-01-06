
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string &dataFile, std::string &inputFile)
{
    f_data.open(dataFile.c_str());
    if (!f_data.is_open())
        throw std::runtime_error("Error: Data file does not exist");

    f_input.open(inputFile.c_str());
    if (!f_input.is_open())
        throw std::runtime_error("Error: Input file does not exist");

    parseData(f_data);
    parseInput(f_input);
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &obj)
{
    data = obj.data;
}

BitcoinExchange& 	BitcoinExchange::operator=( const BitcoinExchange &obj )
{
    if (this != &obj)
        data = obj.data;
    return *this;
}

std::string BitcoinExchange::strtrim(std::string &value)
{
    const long unsigned int start = value.find_first_not_of(" \t");
    if (start == std::string::npos)
        return value;
    const long unsigned int end = value.find_last_not_of(" \t");
    if (end == std::string::npos)
        return value;
    return value.substr(start, end - start + 1);
}

std::string BitcoinExchange::get_prev_value(std::string &key)
{
    std::map<std::string, double>::iterator it = data.lower_bound(key);
    if (it == data.begin())
        throw std::runtime_error("Error: No previous data found");
    if (it == data.end() || key != it->first)
        --it;
    std::ostringstream oss;
    oss << it->second;
    return oss.str();
}

void BitcoinExchange::parseData(std::ifstream &file)
{
    std::string line;
    std::getline(file, line);
    if (line.compare("date,exchange_rate"))
        throw std::runtime_error("Error: Invalid file startup");

    while (std::getline(file, line))
    {
        try
        {
            if (line.empty())
                continue;
            std::stringstream ss(line);
            std::string date_value;
            std::string amount_value;
            if (std::getline(ss, date_value, ',') && std::getline(ss, amount_value))
            {
                std::stringstream amountStream(amount_value);
                double amount;
                if (!(amountStream >> amount))
                    throw std::runtime_error("Error: Invalid bitcoin amount: " + amount_value);
                data[date_value] = amount;
            }
            else
                throw std::runtime_error("Error: Invalid line format: " + line);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}

void BitcoinExchange::isValidMonth(std::string &date)
{
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        throw std::runtime_error("Error: Invalid date format (expected YYYY-MM-DD)");

    int year, month, day;
    std::istringstream yearStream(date.substr(0, 4));
    if (!(yearStream >> year))
        throw std::runtime_error("Error: Invalid year in date");
    std::istringstream monthStream(date.substr(5, 2));
    if (!(monthStream >> month))
        throw std::runtime_error("Error: Invalid month in date");
    std::istringstream dayStream(date.substr(8, 2));
    if (!(dayStream >> day))
        throw std::runtime_error("Error: Invalid day in date");
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysInMonth[1] = 29;
    if (year < 2009)
        throw std::runtime_error("Error: Year is invalid for Bitcoin data (must be 2009 or later)");
    if (month < 1 || month > 12)
        throw std::runtime_error("Error: Invalid month (must be between 1 and 12)");
    if (day < 1 || day > daysInMonth[month - 1])
        throw std::runtime_error("Error: Invalid day for the given month");
}

void BitcoinExchange::parseInput(std::ifstream &file)
{
    std::string line;
    std::getline(file, line);
    if (line.compare("date | value"))
        throw std::runtime_error("Error: Invalid file startup");

    while (std::getline(file, line))
    {
        try
        {
            if (line.empty())
                continue;
            std::stringstream ss(line);
            std::string date_value;
            std::string amount_value;
            if (std::getline(ss, date_value, '|') && std::getline(ss, amount_value))
            {
                date_value = strtrim(date_value);
                amount_value = strtrim(amount_value);

                std::stringstream amountStream(amount_value);
                double amount;
                if (!(amountStream >> amount) || amount < 0 || amount > 1000)
                    throw std::runtime_error("Error: Invalid bitcoin amount: " + amount_value);
                if (!amountStream.eof())
                    throw std::runtime_error("Error: Invalid bitcoin amount: " + amount_value);

                isValidMonth(date_value);

               	std::string prev_value = get_prev_value(date_value);

		        std::stringstream ss(prev_value);
		        double prev_amount;
		        ss >> prev_amount;

		        if (ss.fail())
		            throw std::runtime_error("Error: Failed to convert previous value to double");

		        std::cout << date_value << " => " << amount << " * " << prev_value << " = "<< amount * prev_amount << std::endl;
            }
            else
                throw std::runtime_error("Error: Invalid line format: " + line);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}

BitcoinExchange::~BitcoinExchange( )
{
    if (f_data.is_open())
        f_data.close();
    if (f_input.is_open())
        f_input.close();
}
