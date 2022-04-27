/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 04:23:57 by guilmira          #+#    #+#             */
/*   Updated: 2022/04/27 20:29:43 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
#define KAREN_HPP

#include <iostream>
#include <string>
#include <vector>

#define M1 "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!."
#define M2 "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!"
#define M3 "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month."
#define M4 "This is unacceptable, I want to speak to the manager now."

#define O1 "DEBUG"
#define O2 "INFO"
#define O3 "WARNING"
#define O4 "ERROR"

class Karen
{
	public:
		Karen();
		~Karen();

		void complain(std::string level);
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
};

#endif