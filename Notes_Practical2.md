# Practical 2

1. Pratical 2 is just a modification of practical 1 (the game Rock, Paper, Scissors), in which this is the new rule: (">" is using "beat")

Zombie Ninja || Robot Monkey Pirate

Pirate Monkey Zombie Pirate

* Monkey > Ninja
* Monkey > Robot
* Robot > Ninja
* Robot > Zombie
* Pirate > Robot
* Pirate > Monkey
* Ninja > Zombie

* Ninja > Pirate

* Zombie > Pirate
* Zombie > Monkey

2. In Practical 1, if you apply SOLID and ADT principles correctly, you should make it easier to modify to accomodate the changes in practical 2 in the new game with 5 moves

To extend your referee to handle these new options, a natural tendency might be to just add more if/then statements to your refGame() function; but as discussed in lecture 3 and in this week's workshop, this violates SOLID design principles and therefore is NOT an acceptable solution for this practical.

Applying your knowledge of SOLID, modify your refGame() so that it complies with SOLID principles. **Your refGame() should be able to work without modification for any types of moves you might decide to add in the future**.  It should also continue to support the Rock, Paper and Scissor options.  Consider how you can use Polymorphism to achieve this.



## Notes afer asking the instructor
1. See again the class diagram that is in my phone. Move class should have child classes (change private to protected) - every submove should be set as a child class: Rock, Scissors, Paper, Monkey
2. How to do the beat function: it should be a weakAgainst function in the Move class because it belongs to the Move class - this functionality does not belong to the Referee class. See this function definition in my phone.
3. How many files we have to include: all the files listed in myuni, as well as MoveFactory, as well as all the child classes of Move class
4. Why is the "MoveFactory" class necessary? First, the functionality to convert a string to Move* pointer is not a functionality of the Human class. Second, it makes it easier to check whether the move's string entered is valid or not: in the MoveFactory class, just check the string with other acceptable names - if it is acceptable, return a Move* pointer; and if it is not, return a nullptr. Then, no need to add a vector static data member in the Move class. Third, it makes it easy if we want to add a new class MoveImprove, then this can convert a string to a MoveImprove* pointer. Also, if we want to include a new class HumanImprove besides Human class, we don't have to write code to convert string to a Move* pointer again in the HumanImprove class. Fourth, the purpose of the function is to make a string of a move playable - a string is not playable, but a pointer to a Move class is playable. 