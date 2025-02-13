#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <windows.h>


using namespace std;

#define SetConsoleTextAttributeBlack "\033[0m"
#define SetConsoleTextAttributeGreen "\033[38;2;0;255;0m"
#define SetConsoleTextAttributeCyan "\033[38;2;0;255;255m"
#define SetConsoleTextAttributeBlue "\033[38;2;0;0;255m"
#define SetConsoleTextAttributeWhite "\033[38;2;255;255;255m"
#define SetConsoleTextAttributeYellow "\033[38;2;255;255;0m"
#define SetConsoleTextAttributeRed "\033[38;2;255;0;0m"


int main() {
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
  int menuChoice;
  int generateOption = 0;
  int gameSettingModify;
  int cardDesignTemplate = 0;
  int selectedCardDesign = 0;
  int counterforPlayers = 0;
  int gameModehard = 0;
  int stars;
  int errorHandlerModifier;

  displayBingoLogo();

  while (true) {
    displayMainMenuUi();
    cout << "What do you want to do?\nUser:/> ";
    while (!(cin >> menuChoice) || menuChoice < 0 || menuChoice > 7 || (cin.get() != '\n'))
    {

      displayMenuErrorHandling();

      cin.clear();
      cin.ignore(123, '\n');
    }
    switch (menuChoice)
    {
    case 1: {
      cin.clear();
      srand(time(0));
      short infinityLoop = 1;
      vector <int> numbers;
      vector<string> player;
      vector<vector<int>> displayCards(4);

      for (int i = 0; i < 4; i++)
      {
        displayCards[i] = createBingoCard();
      }
      string entredName;
      cin.clear();
      displayGuntingLineBreaker();
      do
      {
        cout << "Enter Player 4 Names Only, Type 'X' or 'Done' if finish:.-> ";
        getline(cin, entredName);
        player.push_back(entredName);
        counterforPlayers++;
      } while (counterforPlayers != 4 && entredName != "Done" && entredName != "X" && entredName != "done" && entredName != "x");

      do
      {

        int sorecererNumber;
        do {
          if (generateOption == 1) {
            cout << "Please Press 1 to Summon and Generate a Card:.-> ";
            while (!(cin >> errorHandlerModifier) || errorHandlerModifier != 1 || cin.get() != '\n')
            {
              displayKeyBoard1();
              cout << "You are Only Allowed to Press 1.-> ";

              cin.clear();
              cin.ignore(123, '\n');
            }

            sorecererNumber = numericalSorcerer();
          }
          if (generateOption == 0) {
            cout << "\n\n\nAutomatic Generation is -[ON]-\n-";

            sorecererNumber = numericalSorcerer();
          }
        } while (sorecererNumber == 2012);

        cout << "\nSorcerer Summon a number: " << sorecererNumber << '\n';

        for (int playersCard = 0; playersCard < 4; playersCard++)
        {
          for (int numberInsidePlayersCard = 0; numberInsidePlayersCard < 25; numberInsidePlayersCard++)
          {
            if (displayCards[playersCard][numberInsidePlayersCard] == sorecererNumber)
            {
              
              numbers.push_back(sorecererNumber);
              displayCards[playersCard][numberInsidePlayersCard] = 100;
            }
          }
        }
        for (int i = 0; i < 4; i++)
        {
          cout << "\nSorcerer Summon a number: "
               << "[" << sorecererNumber << "]" << '\n';
          cout << "\n"
               << "Player " << i + 1 << " Named " << player[i] << " Cards ";
          if (selectedCardDesign == 0) {
            showPlayerCard(displayCards[i]);
          }
          if (selectedCardDesign == 1) {
            showPlayerCardOption1(displayCards[i]);
          }
          if (selectedCardDesign == 2) {
            showPlayerCardOption2(displayCards[i]);
          }
          if (selectedCardDesign == 3) {
            showPlayerCardOption3(displayCards[i]);
          }
          if (selectedCardDesign == 4) {
            showPlayerCardOption4(displayCards[i]);
          }
        }
        if (gameModehard == 1) {
          if (checkBingoWinHard(displayCards[0])) {
            cout << "|=========================================|\n";
            cout << "|< Bingo "
                    "Player 1 "
                 << player[0] << " Wins the Game >\n";
            cout << "|=========================================|\n";
            displayWinningPattern(displayCards[0]);
            cout << endl;
            displayCrownWinner();
            showPlayerCard(displayCards[0]);
            cout << endl;
            cout << "Behold the wining Card-^\n";
            displayGuntingLineBreaker();
            cout << "\n";
            return 1;
            cout << "\nDo you want to back to the menu? ";
            while (!(cin >> menuChoice) || (menuChoice != 1 && menuChoice != 0) || cin.get() != '\n')
            {
              displayErrorHandlingBack();
              cin.clear();
              cin.ignore(123, '\n');
            }
          }
        }
        else if (checkBingoWin(displayCards[0])) {
          cout << endl;
          cout << "Bingo! "
                  "Player 1 " << player[0] << " Wins the Game         \n";
          displayWinningPattern(displayCards[0]);
          displayCrownWinner();
          showPlayerCard(displayCards[0]);
          cout << endl;
          displayGuntingLineBreaker();
          cout << "\n";
          cout << "\nDo you want to back to the menu? ";
          break;
        }
        if (gameModehard == 1) {
          if (checkBingoWinHard(displayCards[1])) {
            cout << "|=========================================|\n";
            cout << "|Bingo! "
                    "Player 2 "
                 << player[1] << " Wins the Game         |\n";
            cout << "|=========================================|\n";
            displayCrownWinner();
            showPlayerCard(displayCards[1]);
            displayWinningPattern(displayCards[1]);
            cout << endl;
            cout << "Behold the wining Card-^\n";
            displayGuntingLineBreaker();
            return 1;
            cout << "\nDo you want to bakck to the menu? ";
            while (!(cin >> menuChoice) || (menuChoice != 1 && menuChoice != 0) || cin.get() != '\n')
            {
              displayErrorHandlingBack();
              cin.clear();
              cin.ignore(123, '\n');
            }
          }
        }
        else if (checkBingoWin(displayCards[1])) {
          cout << endl;
          cout << "Bingo! "
                  "Player 2 "
               << player[1] << " Wins the Game\n";
          displayCrownWinner();
          showPlayerCard(displayCards[1]);
          displayWinningPattern(displayCards[1]);
            displayGuntingLineBreaker();
            cout << "\nDo you want to back to the menu? ";
            while (!(cin >> menuChoice) || (menuChoice != 1 && menuChoice != 0) || cin.get() != '\n')
            {
              displayKeyBoard1();
              displayErrorHandlingBack();
              cin.clear();
              cin.ignore(123, '\n');
            }
            break;
          }
        if (gameModehard == 1) {
          if (checkBingoWinHard(displayCards[2])) {
            cout << "|=========================================|\n";
            cout << "|Bingo "
                    "Player 3 "
                 << player[2] << " Wins the Game         |\n";
            cout << "|=========================================|\n";

            displayWinningPattern(displayCards[2]);
            cout << endl;
            displayCrownWinner();
            showPlayerCard(displayCards[2]);
            cout << endl;
            cout << "Behold the wining Card:-^\n";
            displayGuntingLineBreaker();
            cout << endl;
            return 1;
            cout << "\nDo you want to back to the menu? ";
            while (!(cin >> menuChoice) || (menuChoice != 1 && menuChoice != 0) || cin.get() != '\n')
            {
              displayErrorHandlingBack();
              cin.clear();
              cin.ignore(123, '\n');
            }
          }
        }
        else if (checkBingoWin(displayCards[2])) {
          cout << endl;
          cout << "Bingo "
                  "Player 3 "
               << player[2] << " Wins the Game\n";
          displayWinningPattern(displayCards[2]);
          displayCrownWinner();
          showPlayerCard(displayCards[2]);
          cout << endl;
          displayGuntingLineBreaker();

          cout << endl;
          cout << "\nDo you want to back to the menu? ";
          while (!(cin >> menuChoice) || (menuChoice != 1 && menuChoice != 0) || cin.get() != '\n')
          {
            displayKeyBoard1();
            displayErrorHandlingBack();

            cin.clear();
            cin.ignore(123, '\n');
          }
          break;
        }
        if (gameModehard == 1) {
          if (checkBingoWinHard(displayCards[3])) {
            cout << "|=========================================|\n";
            cout << "|Bingo "
                    "Player 4 "
                 << player[3] << " Wins the Game         |\n";
            cout << "|=========================================|\n";

            displayWinningPattern(displayCards[3]);
            cout << endl;
            displayCrownWinner();
            showPlayerCard(displayCards[3]);
            cout << "Behold the wining Card:-^\n";
            displayGuntingLineBreaker();
            cout << endl;
            cout << "\nDo you want to back to the menu? ";
            return 1;
            while (!(cin >> menuChoice) || (menuChoice != 1 && menuChoice != 0) || cin.get() != '\n')
            {
              displayKeyBoard1();
              displayErrorHandlingBack();
              cin.clear();
              cin.ignore(123, '\n');
            }
          }
        }
        else if (checkBingoWin(displayCards[3])) {
          cout << endl;
          cout << "Bingo "
                  "Player 4 "
               << player[3] << " Wins the Game\n";
          displayWinningPattern(displayCards[3]);
          displayCrownWinner();
          showPlayerCard(displayCards[3]);
          cout << endl;
          displayGuntingLineBreaker();
          cout << endl;
          cout << "\nDo you want to back to the menu? ";
          while (!(cin >> menuChoice) || (menuChoice != 1 && menuChoice != 0) || cin.get() != '\n')
          {
            displayKeyBoard1();
            displayErrorHandlingBack();
            cin.clear();
            cin.ignore(123, '\n');
          }
          break;
        }
      } while (infinityLoop == 1);
      cout << "Type 1 to confirm? ";
      while (!(cin >> menuChoice) || (menuChoice != 1) || cin.get() != '\n')
      {
        displayMenuErrorHandling();
        cin.clear();
        cin.ignore(123, '\n');
      }
      break;
    }

    case 2: {
      displayLearnHowToPlay();

      cout << "Press 1 to go back to the Main menu-> ";
      while (!(cin >> menuChoice) || (menuChoice != 1) || cin.get() != '\n')
      {
        displayKeyBoard1();
        displayErrorHandlingBack();

        cin.clear();
        cin.ignore(123, '\n');
      }

      break;
    }
    case 3: {
      displayGameSettingMenu();
      cout << "What do you want to modify? ";
      cin >> gameSettingModify;

      switch (gameSettingModify)
      {
      case 1:
        cout << "Turn On Manual Generation By Pressing [1]:.-> ";
        while (!(cin >> generateOption))
        {
          cout << "Press [1]:.-> ";
          cin.clear();
          cin.ignore(123, '\n');
        }
        cout << "Press 1 to Enable Go Back to The Menu: ";
        while (!(cin >> menuChoice) || menuChoice < 0 || menuChoice > 5 || (cin.get() != '\n'))
        {
          displayMenuErrorHandling();
          cin.clear();
          cin.ignore(123, '\n');
        }
        break;
      case 2:
        cout << "Do you want to Modify the Bingo Card Design? [Press 1]: ";
        while (!(cin >> cardDesignTemplate) || cardDesignTemplate != 1 || cin.get() != '\n')
        {
          displayErrorHandlingBack();
          cin.clear();
          cin.ignore(123, '\n');
        }
        switch (cardDesignTemplate)
        {
        case 1:
        {
          cout << "Look at the design template by pressing [1]:-.> ";
          while (!(cin >> errorHandlerModifier) || errorHandlerModifier != 1 || cin.get() != '\n')
          {
            cout << "You are Allowed to Press 1.-> ";
            cin.clear();
            cin.ignore(123, '\n');
          }
          displayPattern1();
          cout << "Please Press 1 Please:;-> ";
          while (!(cin >> errorHandlerModifier) || errorHandlerModifier != 1 || cin.get() != '\n')
          {
            cout << "You are Allowed to Press 1.-> ";

            cin.clear();
            cin.ignore(123, '\n');
          }
          cout << endl;
          displayPattern2();
          cout << "Please Press 1 to See More Display Pattern: ";
          while (!(cin >> errorHandlerModifier) || errorHandlerModifier != 1 || cin.get() != '\n')
          {
            cout << "You are Only Allowed to Press 1.-> ";

            cin.clear();
            cin.ignore(123, '\n');
          }
          cout << endl;
          displayPattern3();
          cout << "Please Press 1 to See More Display Pattern:.-> ";
          while (!(cin >> errorHandlerModifier) || errorHandlerModifier != 1 || cin.get() != '\n')
          {
            cout << "You are Only Allowed to Press 1.-> ";

            cin.clear();
            cin.ignore(123, '\n');
          }
          cout << endl;
          displayPattern4();
          cout << "Please Press 1 to See More Display Pattern:.-> ";
          while (!(cin >> errorHandlerModifier) || errorHandlerModifier != 1 || cin.get() != '\n')
          {
            cout << "You are Only Allowed to Press 1.-> ";

            cin.clear();
            cin.ignore(123, '\n');
          }
          cout << endl;
          cout << "What Design Do you Want to Select? ";
          while (!(cin >> selectedCardDesign) || selectedCardDesign > 5 || selectedCardDesign < 1 || cin.get() != '\n')
          {
            displayDesignErrorHandling();
          }
          cout << "Press 1 To go Back to the Main Menu.-> ";
          while (!(cin >> menuChoice) || menuChoice != 1 || (cin.get() != '\n'))
          {
            displayKeyBoard1();
            displayErrorHandlingBack();

            cin.clear();
            cin.ignore(123, '\n');
          }
         break;
        }

        default:
          break;
        }
        break;
      case 3:
        cout << "Press [1] to Change the Mode to Hard: ";
        while (!(cin >> gameModehard) || gameModehard != 1 || cin.get() != '\n')
        {
          cout << "Cannot Go Back Now Press [1]! ";
          displayKeyBoard1();
          cin.clear();
          cin.ignore(123, '\n');
        }
        cout << "Press 1 to Go Back to Main Menu.-> ";
        while (!(cin >> menuChoice) || menuChoice < 0 || menuChoice > 5 || (cin.get() != '\n'))
        {
          displayKeyBoard1();
          displayErrorHandlingBack();
          cin.clear();
          cin.ignore(123, '\n');
        }

      default:
        break;
      }

      break;
    }
    case 4: {
      displayCredit();
      cout << "Press 1 To go Back to the Main Menu.-> ";
      while (!(cin >> menuChoice) || menuChoice != 1 || (cin.get() != '\n'))
      {
        displayKeyBoard1();
        displayErrorHandlingBack();

        cin.clear();
        cin.ignore(123, '\n');
      }
      break;
    }
    case 5: {
      displayAbout();
      cout << "Press 1 To go Back to the Main Menu.-> ";
      while (!(cin >> menuChoice) || menuChoice != 1 || (cin.get() != '\n'))
      {
        displayKeyBoard1();
        displayErrorHandlingBack();

        cin.clear();
        cin.ignore(123, '\n');
      }
      break;
    }
    case 6: {
      displayRating();
      cout << "Press 1 To go Back to the Main Menu.-> ";
      while (!(cin >> menuChoice) || menuChoice != 1 || (cin.get() != '\n'))
      {
        displayKeyBoard1();
        displayErrorHandlingBack();

        cin.clear();
        cin.ignore(123, '\n');
      }
      break;
    }
    case 7: {
      displayGoodbyeExit();
      return 0;
    }
    default:
      break;
    }
  }
  return 0;
}
//------------------------------------------------------------------------------------------8<-------------------------------------------------------------------------------------------------------------------------------------------------------------
int numericalSorcerer() {
  return rand() % 75 + 1;
}

int bingoCardNumber(int minRange, int maxRange) {
  return minRange + rand() % (maxRange - minRange + 1);
}

vector<pair<int, int>> bingoRanges = {
    {1, 15},
    {16, 30},
    {31, 45},
    {46, 60},
    {61, 75},
};
vector<int> createBingoCard() {
  vector<int> card(25);

  for (int rows = 0; rows < 5; rows++)
  {
    for (int columns = 0; columns < 5; columns++)
    {
      int colMin = bingoRanges[columns].first;
      int colMax = bingoRanges[columns].second;

      do
      {
        int duplicatedNumber = 0;
        int cardnumber = bingoCardNumber(colMin, colMax);

        for (int numberInside : card)
        {
          if (numberInside == cardnumber)
          {
            duplicatedNumber = 1;
            card[rows * 5 + columns] = 0;
            break;
          }
        }
        if (duplicatedNumber == 0)
        {
          card[rows * 5 + columns] = cardnumber;
          break;
        }
      } while (card[rows * 5 + columns] == 0);
    }
  }
  card[12] = 100;
  return card;
  /*After rows = 0, columns = 1 (second iteration of the inner loop)
  -> -> -> -> -> ->

 | B   | I   | N   | G   | O   |
 |-----|-----|-----|-----|-----|
 |  2  | 18  |  .  |  .  |  .  |
 |  .  |  .  |  .  |  .  |  .  |
 |  .  |  .  |  .  |  .  |  .  |
 |  .  |  .  |  .  |  .  |  .  |
 |  .  |  .  |  .  |  .  |  .  |
 */
}
void showPlayerCard(vector<int> card) {
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

  cout << "\n.___________________________________.\n";
  cout << "|B\t I\t N\t G\t O  |\n";
  cout << "|___________________________________|";
  for (int i = 0; i < 25; i++)
  {

    if (i % 5 == 0)
    {
      cout << endl;
    }

    int uniqueNumber = card[i];
    if (uniqueNumber == 100)
    {
      cout << SetConsoleTextAttributeBlue;
      cout << "<|X|> \t";
      cout << SetConsoleTextAttributeBlack;
    }
    else
      cout << " " << card[i] << ""
           << " \t";
  }
  cout << "\n|__________________________________|" << SetConsoleTextAttributeBlack;
  cout
      << endl;
  cout << endl;
}
void showPlayerCardOption1(vector<int> card) {
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
  cout << "\n.___________________________________.\n";
  cout << "|B\t I\t N\t G\t O  |\n";
  cout << "|___________________________________|";
  for (int i = 0; i < 25; i++)
  {

    if (i % 5 == 0)
    {
      cout << endl;
    }

    int uniqueNumber = card[i];
    if (uniqueNumber == 100)
    {
      cout << SetConsoleTextAttributeGreen;
      cout << "-[X]-\t";
      cout << SetConsoleTextAttributeBlack;
    }
    else
      cout << "-[" << card[i] << "]-"
           << " \t";
  }
  cout << "\n|__________________________________|";
  cout << endl;
  cout << endl;
}
void showPlayerCardOption2(vector<int> card) {
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
  cout << "\n.___________________________________.\n";
  cout << "|" << SetConsoleTextAttributeYellow "B\t I\t N\t G\t O" << SetConsoleTextAttributeBlack "|\n";
  cout << "|___________________________________|";
  for (int i = 0; i < 25; i++)
  {

    if (i % 5 == 0)
    {
      cout << endl;
    }

    int uniqueNumber = card[i];
    if (uniqueNumber == 100)
    {
      cout << SetConsoleTextAttributeYellow;
      cout << "<X> \t";
      cout << SetConsoleTextAttributeBlack;
    }
    else
      cout << " " << card[i] << " "
           << "\t";
  }
  cout << "\n|__________________________________|";
  cout << endl;
  cout << endl;
}
void showPlayerCardOption3(vector<int> card) {
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
  cout << "\n.___________________________________.\n";
  cout << "|" << SetConsoleTextAttributeRed "B\t I\t N\t G\t O" << SetConsoleTextAttributeBlack "|\n";
  cout << "|___________________________________|";
  for (int i = 0; i < 25; i++)
  {

    if (i % 5 == 0)
    {
      cout << endl;
    }

    int uniqueNumber = card[i];
    if (uniqueNumber == 100)
    {
      cout << SetConsoleTextAttributeRed;
      cout << "\\X/ \t";
      cout << SetConsoleTextAttributeBlack;
    }
    else
      cout << "\\" << card[i] << "/"
           << " \t";
  }
  cout << "\n|__________________________________|";
  cout << endl;
  cout << endl;
}
void showPlayerCardOption4(vector<int> card) {
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
  cout << "\n.___________________________________.\n";
  cout << "|B\t I\t N\t G\t O  |\n";
  cout << "|___________________________________|";
  for (int i = 0; i < 25; i++)
  {

    if (i % 5 == 0)
    {
      cout << endl;
    }

    int uniqueNumber = card[i];
    if (uniqueNumber == 100)
    {
      cout << SetConsoleTextAttributeCyan;
      cout << "(X) \t";
      cout << SetConsoleTextAttributeBlack;
    }
    else
      cout << "(" << card[i] << ")"
           << " \t";
  }
  cout << "\n|__________________________________|";
  cout << endl;
  cout << endl;
}
bool checkBingoWinHard(const vector<int> card) {
/*
  B   I    N    G    O
|0| |1 | |2 | |3 | |4 |
|5| |6 | |7 | |8 | |9 |
|10||11| |12| |13| |14|
|15||16| |17| |18| |19|
|20||21| |22| |23| |24|
12 is the center
*/

  if ((card[0] == 100 && card[1] == 100 && card[2] == 100 && card[3] == 100 && card[4] == 100) &&
      (card[5] == 100 && card[6] == 100 && card[7] == 100 && card[8] == 100 && card[9] == 100) &&
      (card[10] == 100 && card[11] == 100 && card[12] == 100 && card[13] == 100 && card[14] == 100) &&
      (card[15] == 100 && card[16] == 100 && card[17] == 100 && card[18] == 100 && card[19] == 100) &&
      (card[20] == 100 && card[21] == 100 && card[22] == 100 && card[23] == 100 && card[24] == 100) &&
      (card[0] == 100 && card[5] == 100 && card[10] == 100 && card[15] == 100 && card[20] == 100) &&
      (card[1] == 100 && card[6] == 100 && card[11] == 100 && card[16] == 100 && card[21] == 100) &&
      (card[2] == 100 && card[7] == 100 && card[12] == 100 && card[17] == 100 && card[22] == 100) &&
      (card[3] == 100 && card[8] == 100 && card[13] == 100 && card[18] == 100 && card[23] == 100) &&
      (card[4] == 100 && card[9] == 100 && card[14] == 100 && card[19] == 100 && card[24] == 100) &&
      (card[0] == 100 && card[6] == 100 && card[12] == 100 && card[18] == 100 && card[24] == 100) &&
      (card[4] == 100 && card[8] == 100 && card[12] == 100 && card[16] == 100 && card[20] == 100))
  {
    return true;
  }

  return false;
}
bool checkBingoWin(const vector<int> card) {
/*
  B   I    N    G    O
|0| |1 | |2 | |3 | |4 |
|5| |6 | |7 | |8 | |9 |
|10||11| |12| |13| |14|
|15||16| |17| |18| |19|
|20||21| |22| |23| |24|
12 is the center
*/

  if ((card[0] == 100 && card[1] == 100 && card[2] == 100 && card[3] == 100 && card[4] == 100) ||
      (card[5] == 100 && card[6] == 100 && card[7] == 100 && card[8] == 100 && card[9] == 100) ||
      (card[10] == 100 && card[11] == 100 && card[12] == 100 && card[13] == 100 && card[14] == 100) ||
      (card[15] == 100 && card[16] == 100 && card[17] == 100 && card[18] == 100 && card[19] == 100) ||
      (card[20] == 100 && card[21] == 100 && card[22] == 100 && card[23] == 100 && card[24] == 100))
  {
    return true;
  }

  if ((card[0] == 100 && card[5] == 100 && card[10] == 100 && card[15] == 100 && card[20] == 100) ||
      (card[1] == 100 && card[6] == 100 && card[11] == 100 && card[16] == 100 && card[21] == 100) ||
      (card[2] == 100 && card[7] == 100 && card[12] == 100 && card[17] == 100 && card[22] == 100) ||
      (card[3] == 100 && card[8] == 100 && card[13] == 100 && card[18] == 100 && card[23] == 100) ||
      (card[4] == 100 && card[9] == 100 && card[14] == 100 && card[19] == 100 && card[24] == 100))
  {
    return true;
  }

  if ((card[0] == 100 && card[6] == 100 && card[12] == 100 && card[18] == 100 && card[24] == 100) ||
      (card[4] == 100 && card[8] == 100 && card[12] == 100 && card[16] == 100 && card[20] == 100))
  {
    return true;
  }

  return false;
}
void displayWinningPattern(const vector<int> card) {
  if ((card[0] == 100 && card[1] == 100 && card[2] == 100 && card[3] == 100 && card[4] == 100) &&
      (card[5] == 100 && card[6] == 100 && card[7] == 100 && card[8] == 100 && card[9] == 100) &&
      (card[10] == 100 && card[11] == 100 && card[12] == 100 && card[13] == 100 && card[14] == 100) &&
      (card[15] == 100 && card[16] == 100 && card[17] == 100 && card[18] == 100 && card[19] == 100) &&
      (card[20] == 100 && card[21] == 100 && card[22] == 100 && card[23] == 100 && card[24] == 100) &&
      (card[0] == 100 && card[5] == 100 && card[10] == 100 && card[15] == 100 && card[20] == 100) &&
      (card[1] == 100 && card[6] == 100 && card[11] == 100 && card[16] == 100 && card[21] == 100) &&
      (card[2] == 100 && card[7] == 100 && card[12] == 100 && card[17] == 100 && card[22] == 100) &&
      (card[3] == 100 && card[8] == 100 && card[13] == 100 && card[18] == 100 && card[23] == 100) &&
      (card[4] == 100 && card[9] == 100 && card[14] == 100 && card[19] == 100 && card[24] == 100) &&
      (card[0] == 100 && card[6] == 100 && card[12] == 100 && card[18] == 100 && card[24] == 100) &&
      (card[4] == 100 && card[8] == 100 && card[12] == 100 && card[16] == 100 && card[20] == 100))
  {
    cout << "Full House Alert! This Player Needs to Stop Playing Bingo and Start Playing Lotto :)";
    cout << endl;
    return;
  }
  if ((card[0] == 100 && card[5] == 100 && card[10] == 100 && card[15] == 100 && card[20] == 100) ||
      (card[1] == 100 && card[6] == 100 && card[11] == 100 && card[16] == 100 && card[21] == 100) ||
      (card[2] == 100 && card[7] == 100 && card[12] == 100 && card[17] == 100 && card[22] == 100) ||
      (card[3] == 100 && card[8] == 100 && card[13] == 100 && card[18] == 100 && card[23] == 100) ||
      (card[4] == 100 && card[9] == 100 && card[14] == 100 && card[19] == 100 && card[24] == 100))
  {
    cout << "The Winner Achieved a Vertical Pattern What a Luck!";
    cout << endl;
  }
  if ((card[0] == 100 && card[1] == 100 && card[2] == 100 && card[3] == 100 && card[4] == 100) ||
      (card[5] == 100 && card[6] == 100 && card[7] == 100 && card[8] == 100 && card[9] == 100) ||
      (card[10] == 100 && card[11] == 100 && card[12] == 100 && card[13] == 100 && card[14] == 100) ||
      (card[15] == 100 && card[16] == 100 && card[17] == 100 && card[18] == 100 && card[19] == 100) ||
      (card[20] == 100 && card[21] == 100 && card[22] == 100 && card[23] == 100 && card[24] == 100))
  {
    cout << "The Winner Achieved a Horizontal Pattern, Lucky one !";
    cout << endl;
  }

  if ((card[0] == 100 && card[6] == 100 && card[12] == 100 && card[18] == 100 && card[24] == 100) ||
      (card[4] == 100 && card[8] == 100 && card[12] == 100 && card[16] == 100 && card[20] == 100))
  {
    cout << "The Winner Achieved a Diagonal Pattern, A Madiagonal Win!";
    cout << endl;
  }
}
void displayBingoLogo() {
  cout << SetConsoleTextAttributeYellow;
  cout << "\n\n   .+------+     +------+     +------+     +------+     +------+    +------+     +------+." << endl;
  cout << " .' |      |    /|      |     |      |     |      |     |      |    |      |\\    |      | `." << endl;
  cout << "+   |  W   |   + |   E  |     +   L  +     +   C  +     +  O   +    |  M   | +   |  E   |   +" << endl;
  cout << "|   |      |   | |      |     |      |     |      |     |      |    |      | |   |      |   |" << endl;
  cout << "|  .+------+   | +------+     +------+     +------+     +------+    +------+ |   +------+.  |" << endl;
  cout << "|.'      .'    |/   B  /      |   I  |     |  N   |     |  G   |     \\  O   \\|    `.       `|" << endl;
  cout << "+------+'      +------+       +------+     +------+     +------+      +------+      `+------+\n\n";
  cout << SetConsoleTextAttributeBlack;
}
void displayMainMenuUi() {
  cout << SetConsoleTextAttributeGreen;
  cout << "\t\t\t      ___________________________________\n";
  cout << "\t\t\t     /\\                                  \\\n";
  cout << "\t\t\t     \\_|                                 |\n";
  cout << "\t\t\t       |              Menu               |\n";
  cout << "\t\t\t       |                                 |\n";
  cout << "\t\t\t       |-[1]->Start the Game             |\n";
  cout << "\t\t\t       |-[2]->Learn How to Play          |\n";
  cout << "\t\t\t       |-[3]->Game Settings              |\n";
  cout << "\t\t\t       |-[4]->Credits                    |\n";
  cout << "\t\t\t       |-[5]->About the Game             |\n";
  cout << "\t\t\t       |-[6]->Rate the Game              |\n";
  cout << "\t\t\t       |-[7]->Exit the Game              |\n";
  cout << "\t\t\t       |                                 |\n";
  cout << "\t\t\t       |   ______________________________|_\n";
  cout << "\t\t\t       \\__/________________________________/\n\n";
  cout << SetConsoleTextAttributeBlack;
}
