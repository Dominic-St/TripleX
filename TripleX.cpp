#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
     //Start of the Game (Welcome)
    std::cout << "\n\nWARNING: A anonymous user wants to access your PC!\n";
    std::cout << R"(
             ,----------------,              ,---------,
        ,-----------------------,          ,"        ,"|
      ,"                      ,"|        ,"        ,"  |
     +-----------------------+  |      ,"        ,"    |
     |  .-----------------.  |  |     +---------+      |
     |  |                 |  |  |     | -==----'|      |
     |  |  I LOVE DOS!    |  |  |     |         |      |
     |  |  Bad command or |  |  |/----|`---=    |      |
     |  |  C:\>_          |  |  |   ,/|==== ooo |      ;
     |  |                 |  |  |  // |(((( [33]|    ,"
     |  `-----------------'  |," .;'| |((((     |  ,"
     +-----------------------+  ;;  | |         |,"     
        /_)______________(_/  //'   | +---------+
   ___________________________/___  `,
  /  oooooooooooooooo  .o.  oooo /,   \,"-----------
 / ==ooooooooooooooo==.o.  ooo= //   ,`\--{)B     ,"
/_==__==========__==_ooo__ooo=_/'   /___________,"
`-----------------------------'  )" << '\n';

    std::cout << "You need to block him out...!\n";
    std::cout << "First you need to turn your antivirus level " << Difficulty;
    std::cout << " back on!\nEnter the correct code to continue...\n\n";
}

bool PlayGame(int Difficulty)         //bool = true or false value
{
    PrintIntroduction(Difficulty);

     //Declare 3 number code
    const int CodeA = rand()%Difficulty + Difficulty;
    const int CodeB = rand()%Difficulty + Difficulty;
    const int CodeC = rand()%Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeMulti = CodeA * CodeB * CodeC;

    //Print CodeSum and CodeMulti to the terminal
    std::cout << "\n\nThere are 3 numbers in the code...";
    std::cout << "\n\n- The code adds-up to: " << CodeSum;
    std::cout << "\n- The code multiplies to give: " << CodeMulti << std::endl;

    //Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessMulti = GuessA * GuessB * GuessC;

    //Check if PlayerGuess is correct
    if (GuessSum == CodeSum && GuessMulti == CodeMulti) 
    {
        std::cout << "\n*** Nice! You got it! Keep going! ***";
        return true;
    }
    else 
    {
        std::cout << "\n*** Damn not the right code..try again! ***";
        return false;
    }
}

int main()
{
    srand(time(NULL));  //create new random sequence based on time of day
    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) //Loop game till all lvl´s completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();   //Clears any errors
        std::cin.ignore();  //Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }
    
    std::cout << "\n*** Congrats! Your antivirus is back online and you stopped the hacker! ***\n";

    return 0;
}