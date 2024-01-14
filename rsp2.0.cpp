#include <iostream>
using namespace std;

//This function represents the menu//
void start_menu()
{
    cout << "Welcome to Rock, Paper, Scissors!" << endl;
    cout << endl;
    cout << "1 - Rock." << endl;
    cout << "2 - Paper." << endl;
    cout << "3 - Scissors." << endl;
    cout << "4 - Quit." << endl;
    cout << "Please make your selection" << endl;
}

//This function is the selection function//
int player_selection()
{
    int player_choice;
    cin >> player_choice;
    if (cin.fail())
    {
        cout << "Error: Not a valid input. " << endl;
        return 0;
    }
    else
    {
        cout << "You have selected " << player_choice << ". ";
    }

    return player_choice;
}

//This function determines the computer selectin//
int machine_selection()
{
    int machine_choice;
    machine_choice = rand() % 3 + 1;
    cout << "The machine has selected " << machine_choice << ". " << endl;
    return machine_choice;
}

//This function determines the victor//
int determine_victor(int player, int machine)
{
    int score_update;
    if (player != machine)
    {
        if ((player == 1 && machine == 2) || (player == 2 && machine == 3) || (player == 3 && machine == 1))
        {
            cout << "Machine scores 1 point. " << endl;
            score_update = 0;
        }
        else
        {
            cout << "You win! Player scores 1 point. " << endl;
            score_update = 1;
        }
    }
    else
    {
        cout << "Tie game! " << endl;
    }
    return(score_update);
}

//This function operates as a play again feature//

int play_again()
{
    cout << "Would you like to play again? T/F" << endl;
    bool play_again_choice;
    cin >> play_again_choice;

    if (cin.fail())
    {
        cout << "Error: Not a valid input." << endl;
        return 0;
    }
    else
    {
        return 1;
    }
}

//This function displays the score and the last round's choices//


//This function collects and displays a sumary of game data after a player presses 4 to quit//
//int game_summary()//



int main()
{
    int game_counter = 0;
    int player_score = 0;
    int machine_score = 0;

    while (true)
    {
        start_menu();
        int player_choice = player_selection();

        if (player_choice == 4)
        {
            cout << " Thank you for playing!" << endl;
            return 0;
        }

        else
        {
            int machine_choice = machine_selection();
            //determine_victor(player_choice, machine_choice);
            if (determine_victor(player_choice, machine_choice) == 0)
            {
                machine_score++;
                
            }
            else if(determine_victor(player_choice, machine_choice) == 1)
            {
                player_score++;
                
            }
            else
            {
                cout << endl;
            }

            game_counter++;
            cout << "Machine score: " << machine_score << endl;
            cout << "Player score: " << player_score << endl;
            cout << "Total games played: " << game_counter << endl;

        }

        cout << "Play again? [y/n]" << endl;
        char play_again = 'n';
        cin >> play_again;
        if (play_again == 'Y' || play_again == 'y')
        {
            continue;
        }
        else
        {
            cout << "Thank you for playing! " << endl;
            break;
        }
    }

    return 0;
}