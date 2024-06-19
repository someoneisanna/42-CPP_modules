/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:24:52 by ataboada          #+#    #+#             */
/*   Updated: 2024/06/19 13:31:13 by ataboada         ###   ########.fr       */
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
		std::cout << "\nDo you want to clear the console and continue? (y/n): ";
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
		Animal a;
		Animal b(a);
		Animal c = a;

		a.makeSound();
		b.makeSound();
		c.makeSound();
	}
	ask_for_input();

	// Second Test -------------------------------------------------------------
	{
		// Object Slicing
		Animal d = Animal();	// calls Animal Default Constructor
		Animal e = Dog();		// calls Animal Default Constructor and Dog Default Constructor (Object Slicing) - Dog part is sliced off (hence the Dog Destructor being called)
		Animal f = Cat();		// calls Animal Default Constructor and Cat Default Constructor (Object Slicing) - Cat part is sliced off (hence the Cat Destructor being called)

		std::cout << "Type for d: " << d.getType() << std::endl;
		std::cout << "Type for e: " << e.getType() << std::endl;
		std::cout << "Type for f: " << f.getType() << std::endl;

		std::cout << "Sound from d: ";
		d.makeSound();
		std::cout << "Sound from e: ";
		e.makeSound();
		std::cout << "Sound from f: ";
		f.makeSound();
	}
	ask_for_input();

	// Third Test --------------------------------------------------------------
	{
		// Polymorphism
		Animal *d = new Animal();	// calls Animal Default Constructor
		Animal *e = new Dog();		// calls Animal Default Constructor and Dog Default Constructor
		Animal *f = new Cat();		// calls Animal Default Constructor and Cat Default Constructor

		// here, differently than in the previous example, we create new Dog and Cat objects dinamically
		// so they are not sliced off. The pointers are of type Animal, but they point to Dog and Cat objects. 
		
		std::cout << "Type for d: " << d->getType() << std::endl;
		std::cout << "Type for e: " << e->getType() << std::endl;
		std::cout << "Type for f: " << f->getType() << std::endl;

		std::cout << "Sound from d: ";
		d->makeSound();
		std::cout << "Sound from e: ";
		e->makeSound();
		std::cout << "Sound from f: ";
		f->makeSound();
		
		delete d;
		delete e;
		delete f;
	}
	ask_for_input();
	
	// Fourth Test -------------------------------------------------------------
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

	// Fifth Test --------------------------------------------------------------
	{
		Animal *heap_i = new Dog();
		Animal *heap_j = new Cat();

		std::cout << "Type for heap_i: " << heap_i->getType() << std::endl;
		std::cout << "Type for heap_j: " << heap_j->getType() << std::endl;

		std::cout << "Sound from heap_i: ";
		heap_i->makeSound();
		std::cout << "Sound from heap_j: ";
		heap_j->makeSound();

		delete heap_i;
		delete heap_j;
	}
	ask_for_input();

	// Sixth Test - WrongClass -------------------------------------------------
	{
		WrongAnimal *k = new WrongAnimal();
		WrongAnimal *l = new WrongCat();

		std::cout << "Type for k: " << k->getType() << std::endl;
		std::cout << "Type for l: " << l->getType() << std::endl;

		std::cout << "Sound from k: ";
		k->makeSound();
		std::cout << "Sound from l: ";
		l->makeSound();

		delete k;
		delete l;

		// Here, we don't have polymorphism, because the makeSound() method is not
		// virtual in the WrongAnimal class. So, the makeSound() method from the
		// WrongAnimal class is called, even if the object is of type WrongCat.
	}
}
