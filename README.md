## 
<h1><img src="https://raw.githubusercontent.com/ayogun/42-project-badges/refs/heads/main/covers/cover-cpp-bonus.png"</h1>

## Description
This project involves creating a robot hierarchy in C++ starting with the `ClapTrap` class, with basic attributes (name, hit points, energy, damage) and methods for attacking, repairing, and taking damage. The derived classes `ScavTrap`, `FragTrap`, and `DiamondTrap` add unique abilities, showcasing inheritance and composition in C++.

## Exercise 00
Objectives 🚀:
- Implement the foundational `ClapTrap` class.

Requirements:
- Create `ClapTrap` with attributes: `Name` (from constructor), `Hit Points` (10), `Energy Points` (10), and `Attack Damage` (0).
- Methods: `attack(const std::string& target)`, `takeDamage(unsigned int amount)`, and `beRepaired(unsigned int amount)`.

## Exercise 01
Objectives 🚀:
- Introduce a derived class `ScavTrap` with unique attributes and behaviors.

Requirements:
- Inherit `ClapTrap`, updating initial values to `Hit Points` (100), `Energy Points` (50), `Attack Damage` (20).
- Add `guardGate()` for Gate Keeper mode.

## Exercise 02
Objectives 🚀:
- Introduce a derived class `FragTrap` with unique attributes and behaviors.

Requirements:
- Inherit `ClapTrap`, updating initial values to `Hit Points` (100), `Energy Points` (100), `Attack Damage` (30).
- Add `guardGate()` for Gate Keeper mode.

## Exercise 03
Objectives 🚀:
- Create a hybrid `DiamondTrap` class combining `ScavTrap` and `FragTrap` traits.

Requirements:
- Inherit both `FragTrap` and `ScavTrap`, setting `Name`, `Hit Points`, `Energy Points`, and `Attack Damage` accordingly.
- Add a `whoAmI()` method to display `DiamondTrap’s` identity and `ClapTrap`-style name.
