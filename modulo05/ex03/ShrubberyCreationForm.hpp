/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                           :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 14:13:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <fstream>
#define TREE "░░░░░░░░░████░░░██░░░░░░░░░░░░░░░░░░░░░░\n░░░░░░░███░░░███░█████░██████░░░░░░░░░░░\n░░░░░░░██░░░░░░░░░░░░███░░░░██░░░░░░░░░░\n░░░░░░████░░░░░░░░░░░░░░░░░█████░░░░░░░░\n░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░\n░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░\n░░░░░░░████░░░░░░░░░░░░░░░░░░█████░░░░░░\n░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n░░░░░░░░█░████░░░░░█░░░░██░░░███░░░░░░░░\n░░░░░░░░███░██░░░░░███████████░░░░░░░░░░\n░░░░░░░░░░░░█░░░░░░█░░░░░░░░░░░░░░░░░░░░\n░░░░░░░░░░░░█░░░░░░█░░░░░░░░░░░░░░░░░░░░\n░░░░░░░░░░░░█░░░░░░█░░░░░░░░░░░░░░░░░░░░\n░░░░░░░░░░░░█░░░░░░█░░░░░░░░░░░░░░░░░░░░\n░░░░░░░░░░░░█░░░░░░█░░░░░░░░░░░░░░░░░░░░\n░░░░░░░░░░░░█░░░░░░█░░░░░░░░░░░░░░░░░░░░\n░░░░░░░░░░░░█░░░░░░█░░░░░░░░░░░░░░░░░░░░\n░░░░░░░██████░░██░░██████░░░░░░░░░░░░░░░\n░░░░░███░░░░██░░██░░░░░░█████░░░░░░░░░░░\n░░░███░░░████░░░░████░░░░░░░█████░░░░░░░\n░░░░░░░███░░░░░░░░░░██░░░░░░░░░░░░░░░░░░\n░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░"
#define TARGET_NAME "random_doc"

class ShrubberyCreationForm : public Form
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const &rhs);

		std::string 	getTarget() const;
		
		void	execute(Bureaucrat const & executor) const;

	private:
		const std::string			_target;
		
		void	form_action() const;
		bool	execute_check(Bureaucrat const & executor) const;
};

#endif
