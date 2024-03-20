/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:24:52 by ataboada          #+#    #+#             */
/*   Updated: 2024/03/20 16:30:14 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

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
		//AAnimal a; // This shouldn't compile because AAnimal is an abstract class and we can't create an instance of it.

		AAnimal *a = new Dog();
		AAnimal *b = new Cat();

		a->makeSound();
		b->makeSound();

		delete a;
		delete b;
	}
	ask_for_input();

	// Second Test -------------------------------------------------------------
	{
		AAnimal *a = new Dog();
		AAnimal *b(a);

		a->makeSound();
		b->makeSound();

		delete a;
	}
	ask_for_input();

	// Third Test --------------------------------------------------------------
	{
		Dog stack_g;
		Cat stack_h;

		std::cout << "Type for stack_g: " << stack_g.getType() << std::endl;
		std::cout << "Type for stack_h: " << stack_h.getType() << std::endl;

		std::cout << "Sound from stack_g: ";
		stack_g.makeSound();
		std::cout << "Sound from stack_h: ";
		stack_h.makeSound();
	}
	ask_for_input();

	// Fourth Test -------------------------------------------------------------
	{
		AAnimal *heap_i = new Dog();
		AAnimal *heap_j = new Cat();

		std::cout << "Type for heap_i: " << heap_i->getType() << std::endl;
		std::cout << "Type for heap_j: " << heap_j->getType() << std::endl;

		std::cout << "Sound from heap_i: ";
		heap_i->makeSound();
		std::cout << "Sound from heap_j: ";
		heap_j->makeSound();

		delete heap_i;
		delete heap_j;
	}
}
