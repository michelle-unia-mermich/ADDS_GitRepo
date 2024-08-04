# Practical 2

Questions
1. //! std::vector<std::string> weakerAgainst; override //Why must our child classes of Move have this 
2. question: in Move* MoveFactory::getMove(std::string moveType): do if else statement in this seems to break open-closed principle
3.  //!Rock(std::string name); //in class Rock: why must we have this when we can just set the name to "Rock" in the default constructor?
4. In Move.h, I think we MUST set std::vector<std::string> weakerAgainst; to static, since we want all Move objects to have access to this and we only want to set the static vector ONCE, not resetting the vector to empty each time a new object Move is created.
5. In Player.h : void setCurrentMove(Move* currentMove); //not sure if a getter function for currentMove is needed when the human enters the move via virtual makeMove() function, while the move of a computer does not change
6. We don't need MoveFactory moveFactory object in Player class because the only function MoveFactory class contains is a static function!
7. Player.h: we want the child classes to use the destructor of the parent class since the parent class is the one containig a dynamicn pointer. However, the parent class is an abstract class that needs a VIRTUAL destructor. Second, how to make the child classes use both what is written in the destructor of the parent class and also the child class?
8. In Move.h, the function isWeakAgainst() when having a tie or losing both return FALSE. So how do we take care of a tie? Take care of the tie in Referee class's refGame?
9. The WeakAgainst vector in Move class must take care of incompatible, compatible moves as well eg. what if entering Rock against Monkey? But I don't know how to make the array take care of this, so I take care of compatibility in referee's refGame. Howeer, refGame can only print out player1 pointer, player2 pointer or nullptr if a Tie - if incompatible, it also prints out nullptr which is a Tie? That is wrong. So we take care of compatibility in main? But we can't put it in main either since the users only type in their moves when function refGame of Referee is called once in main.
10. I haven't take care of when MoveFactory::getMove returns nullptr eg. the string entered is not valid
11. Linker error of static weakerAgainst vector position
12. Linker error of not having definitions for destructors of classes, forgot to include other .cpp files, for not calling constructor of parent class in the child classes
________________________________________________
Note: *in order not to violate open-closed principle*, we don't modify the Move parent class if we want to add more moves. We just add more child classes to the Move parent class.

1. Pratical 2 is just a modification of practical 1 (the game Rock, Paper, Scissors), in which this is the new rule: (">" is using "beat")

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
____________________________
# THINKING OF THE WEAKERAGAINST LIST FOR MOVE CLASS
* Monkey > Ninja /
* Monkey > Robot /
* Robot > Ninja / 
* Robot > Zombie /
* Ninja > Zombie /
* Ninja > Pirate /
* Zombie > Pirate /

* Zombie > Monkey
* Pirate > Robot
* Pirate > Monkey
* Paper > Rock

The array is {"Pirate", "Zombie", "Ninja", "Robot", "Monkey", "Paper", "Scissors", "Rock"} //from weak to strong
Exceptions to the rule of the array is
* Zombie > Monkey
* Pirate > Robot
* Pirate > Monkey
* Paper > Rock

#-------

# Definition for refGame if Referee::refGame also takes care of compatibility

Player* Referee::refGame(Player* player1, Player* player2)
{
    Move* move1= player1->makeMove();
    Move* move2= player2->makeMove();

    //only proceed if the two moves are compatible
    std::string array1[]={"Pirate", "Zombie", "Ninja", "Robot", "Monkey"};
    int size1 = sizeof(array1) / sizeof(array1[0]);
    std::string array2[]={ "Paper", "Scissors", "Rock"};
    int size2 = sizeof(array2) / sizeof(array2[0]);
    bool array1_move1=false;
    bool array2_move1=false;
    bool array1_move2=false;
    bool array2_move2=false;
    for(int i=0;i<size1;i++)
    {
        if (array1[i]==move1->getName())
        {
            array1_move1=true;
        }
        if (array1[i]==move2->getName())
        {
            array1_move2=true;
        }
    }
    for(int j=0;j<size2;j++)
    {
        if (array2[j]==move1->getName())
        {
            array2_move1=true;
        }
        if (array2[j]==move2->getName())
        {
            array2_move2=true;
        }
    }

    //only when the two moves are compatible
    if (((array1_move1==true)&&(array1_move2==true))||((array2_move1==true)&&(array2_move2==true)))
    {
        //---------------------------------------------
        if (move1->isWeakAgainst(move2))
        {
            //player1 wins
            return player1; 
        }
        else 
        {
            //there are two cases, either a tie or player 1 loses
            if (move1->getName()==move2->getName())
            {
                return nullptr; //it's a tie
            }
            else
            {
                return player2;
            }

            //or, can also check if move2->isWeakAgainst(move1): yes: winner is player2; no: it's a tie
        }
        //---------------------------------------------
    }
    else
    {
        //the moves are not compatible
        //behaviour is undefined, do not print out anything
        //must have return because the function is non-void
        return nullptr; //!THIS IS WRONG, if it's incompatible it prints out Tie
    }
    

}
