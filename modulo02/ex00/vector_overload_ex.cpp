/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:12:31 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/04 08:04:45 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

struct Vector
{
	float x;
	float y;
	 
	Vector(float x, float y)
		: x(x), y(y)
	{
		;
	}

	Vector add(Vector const &vector) const
	{
		return Vector(x + vector.x, y + vector.y);
	}

	Vector operator+(Vector const &vector) const
	{
		return Vector(x + vector.x, y + vector.y);
	}

	Vector multiply(Vector const &multiplier) const
	{
		return Vector(x * multiplier.x, y * multiplier.y);
	}

};

int main(void)
{
	Vector position(5, 9);
	Vector speed(3.0f, 5.0f);
	
	Vector c3 = position.add(speed);
	std::cout << c3.x << std::endl;

	Vector c4 = position + speed;
	std::cout << c3.x << std::endl;
	return (0);
}