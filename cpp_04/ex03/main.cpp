/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:16:46 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/24 16:44:43 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

# define BOLD "\033[1m"
# define RESET "\033[0m"

void header()
{
	system("clear");
	std::cout << "*******************************************************************************" << std::endl;
	std::cout << "*                              INTERFACE & RECAP                              *" << std::endl;
	std::cout << "*******************************************************************************" << std::endl;
}

void ask_for_input()
{
	std::string input;
	while (input != "y" && input != "n")
	{
		std::cout << BOLD << "\nDo you want to continue? [y/n]:" << RESET << " ";
		std::cin >> input;
	}
	if (input == "n")
		exit(0);
	else
		header();
}

int main(void)
{
	header();

	// SUBJECT'S TEST ----------------------------------------------------------
	{
		IMateriaSource* src = new MateriaSource();

		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	ask_for_input();

	// TEST 2 ------------------------------------------------------------------
	{
		IMateriaSource* src = new MateriaSource();

		src->learnMateria(new Ice());
		src->learnMateria(NULL); // ERROR MESSAGE
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice()); // ERROR MESSAGE

		AMateria *a = src->createMateria("ice");
		AMateria *b = src->createMateria("cure");
		AMateria *c = src->createMateria("ice");
		AMateria *d = src->createMateria("cure");
		AMateria *e = src->createMateria("fire"); // ERROR MESSAGE

		ICharacter* c1 = new Character("jake");

		c1->use(0, *c1); // ERROR MESSAGE
		c1->unequip(0); // ERROR MESSAGE

		c1->equip(a);
		c1->equip(b);
		c1->equip(c);
		c1->equip(d);
		c1->equip(e); // ERROR MESSAGE

		ICharacter* c2 = new Character("mike");

		c1->use(0, *c2);
		c1->use(1, *c2);
		c1->use(2, *c2);
		c1->use(3, *c2);
		c1->use(4, *c2); // ERROR MESSAGE

		c1->unequip(0);
		c1->unequip(1);
		c1->unequip(2);
		c1->unequip(3);
		c1->unequip(4); // ERROR MESSAGE

		AMateria *f = src->createMateria("cure");

		c1->equip(f);

		delete src;
		delete c1;
		delete c2;
	}
	ask_for_input();

	// TEST 3 ------------------------------------------------------------------
	{
		IMateriaSource* src = new MateriaSource();

		src->learnMateria(new Cure());

		AMateria *a = src->createMateria("cure");

		ICharacter* c1 = new Character("jake");

		c1->equip(a);
		c1->use(0, *c1);
		c1->unequip(0);


		delete src;
		delete c1;
	}
}


