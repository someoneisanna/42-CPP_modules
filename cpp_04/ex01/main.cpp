/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:24:52 by ataboada          #+#    #+#             */
/*   Updated: 2024/03/20 16:24:05 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void	header(void)
{
	std::cout << "**************************************************************************" << std::endl;
	std::cout << "*                              POLYMORPHISM                              *" << std::endl;
	std::cout << "**************************************************************************" << std::endl;
}

void	ask_for_input(void)
{
	std::string input;
	while (input != "y" && input != "n")
	{
		std::cout << "Do you want to clear the console and continue? (y/n): ";
		std::cin >> input;
	}
	if (input == "n")
		exit(0);
	system("clear");
	header();
}

int main(void)
{
	system("clear");
	header();

	// First Test --------------------------------------------------------------
	{
		Animal *a[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
		for (int i = 0; i < 4; i++)
		{
			std::cout << "Animal " << i + 1 << " says: ";
			a[i]->makeSound();
		}
		for (int i = 0; i < 4; i++)
			delete a[i];
	}
	ask_for_input();

	// Second Test -------------------------------------------------------------
	{
		const Animal *b = new Dog();
		const Animal *c = new Cat();
		delete b;
		delete c;
	}
	ask_for_input();

	// Third Test --------------------------------------------------------------
	{
		Animal *d = new Dog();
		Animal *e(d);

		std::cout << "Animal d says: ";
		d->makeSound();
		std::cout << "Animal e says: ";
		e->makeSound();

		delete d;
	}
	ask_for_input();

	// Fourth Test -------------------------------------------------------------
	{
		Dog d1;
		{
			Dog d2 = d1;
			std::cout << "D2 brain address: " << d2.getBrain() << std::endl;
		}
		std::cout << "D1 brain address: " << d1.getBrain() << std::endl;
	}
	ask_for_input();

	// Fifth Test --------------------------------------------------------------
	{
		Dog d1;
		Dog d2 = d1;
		Dog d3(d1);

		std::cout << "D1 brain address: " << d1.getBrain() << std::endl;
		std::cout << "D2 brain address: " << d2.getBrain() << std::endl;
		std::cout << "D3 brain address: " << d3.getBrain() << std::endl;
	}
}
