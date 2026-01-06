
# pragma once

# include <algorithm>
# include <iostream>
# include <sstream>
# include <fstream>
# include <map>
# include <exception>

class BitcoinExchange
{
	private:
		std::map<std::string, double> 	data;
		std::ifstream f_data;
    		std::ifstream f_input;
		std::string			strtrim( std::string &date );
		void				isValidMonth(std::string &month);
		std::string 			get_prev_value( std::string &key );

	public:
		BitcoinExchange( std::string &data, std::string &input );
		~BitcoinExchange();
		BitcoinExchange( const BitcoinExchange &obj) ;
		BitcoinExchange& 	operator=( const BitcoinExchange &obj );
		void			parseData( std::ifstream &file );
		void			parseInput( std::ifstream &file );
};
