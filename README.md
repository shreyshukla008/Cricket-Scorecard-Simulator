# Cricket-Scorecard-Simulator
The provided C++ code is a cricket simulation program where two teams compete, and the user can input various actions for each ball bowled. The program tracks the score, wickets, and other statistics for both batting and bowling teams.

Here's a summary of the key features and components of the code:

1. **Header Inclusions:**
   - The program includes various C++ standard libraries such as iostream, vector, map, string, iterator, algorithm, math, and iomanip.

2. **Template Function for Printing Maps:**
   - Defines a template function to print a map in a tabular format.

3. **Classes:**
   - `bat_stat`, `bowling_stat`, and `player_stat` are classes for storing batting and bowling statistics.
   - The `player` class manages player details, and the `team` class inherits from it. It includes player data, such as jersey numbers, names, and player statistics.

4. **Main Function:**
   - The `main` function is the entry point of the program.
   - It initializes two teams (`t1` and `t2`) with player details.
   - The simulation involves bowlers bowling six balls in an over, and the user inputs actions for each ball.
   - The program tracks scores, wickets, run rates, and other statistics for both teams.

5. **Functions:**
   - `change_strike`: Changes the batting order to switch the striker.
   - `show_over`: Displays the actions of a particular over.
   - `display_operations`: Displays the key operations and their corresponding keys for user input.
   - `print_table`: Prints a tabular representation of player details.

6. **User Input Loop:**
   - The program uses a loop where users input actions for each ball bowled, such as runs scored, wides, no-balls, and wickets.
   - The simulation continues until a specified number of legal deliveries or wickets is reached.

7. **Output:**
   - The program displays a live scorecard after each ball, showing team scores, wickets, run rates, and individual player statistics.

8. **Error Handling:**
   - The code includes some basic error handling for division by zero and exception handling.


