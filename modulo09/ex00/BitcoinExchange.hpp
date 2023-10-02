/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:49 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/28 23:11:31 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define	BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <stdexcept>
#include <limits>

#define DATABASE "./CSVdatabase/data.csv"

typedef std::map<std::string, float>	myMap;
typedef myMap::iterator					mapIter;

/* CLASS DECLARATION. */
class BitcoinExchange
{
	
	
	public:
		BitcoinExchange();
		BitcoinExchange(std::string const & name, std::string const & database, std::string const & file);
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange & operator=(BitcoinExchange const &rhs);

		std::string const &	getName() const;
		void				setName(std::string const &name);

		myMap				buildMap(std::ifstream &file, char delimiter);
		void				printRates(myMap m);
		void				outputResult(std::string const & file);

		myMap							_rates;
		myMap							_fileData;

	private:
		std::string						_name;

		bool			parserDate(std::string const &date);
		bool			parserNumber(double value, double value2);
		double			findExchangeRate(std::string const &date);
		void			ilog(const std::string & name, const std::string & msg) const;

};

#endif
