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

#define DATABASE "./CSVdatabase/data.csv"

#include <stdexcept>

/* CLASS DECLARATION. */
class BitcoinExchange
{
	typedef std::map<std::string, float>	myMap;
	typedef myMap::iterator					mapIter;
	
	public:
		BitcoinExchange();
		BitcoinExchange(std::string const & name, std::string const & database, std::string const & file);
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange & operator=(BitcoinExchange const &rhs);

		std::string const &	getName() const;
		void				setName(std::string const &name);

		void				buildRates();
		void				printRates();

	private:
		std::string						_name;
		std::ifstream					_database;
		std::ifstream					_file;
		myMap							_rates;
		

		void	ilog(const std::string & name, const std::string & msg) const;

};

#endif
