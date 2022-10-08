//
//  main.c
//  FinalV.3
//
//  Created by dakotatokad and A.J. on 4/17/15.
//
// ====== DISABLE fpurge IF USING MSVS =======
// ========================================
//             VERSION 3.14
// ========================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>  // Declaration of Libraries
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 75
#define GAMESIZE 273
#define VOWEL 250
#define PUZZLESOLVED 2000
#define ROUNDS 2  // Set to RoundsWanted + 1 (Ex. For 5 rounds set to 6)
#define TRUE 1
#define FALSE 0
#define MAYBE 5
int RoundNumberTest;   // Global Variables
int PP = 0; // last player to leave off on
int k = 0;
char answer_guesses[SIZE];
int temp = 0;


typedef struct PLAYER {  // Definition of Linked List for Players
    char name[SIZE];
    int score;
    struct PLAYER *listp1;
} Player;

typedef struct GAME {   // Definition of Linked List of Game Parts
    char gameClue[SIZE];
    char gameSolution[SIZE];
    struct GAME *listp2;
} the_game;

void scan_func(the_game *pt, FILE *input);  // Declaration of all functions
void scan_player(Player *pt);
void print_CLUE(the_game *pt);
void print_SOLUTION(the_game *pt);
void print_players(Player *pt, int playercount);
void print_blank_solution(char blanks[], int length);
void clean_buffer();
void the_Disk(int *num);
void puzzle_generator(int *num);
void play_game(the_game *pt, Player *qt, Player *start);
void check(char answer_string[], char* answer_blanks, char guess, int *verification, int *Point_Per_Round);
void puzzle_verification(char answer_string[], char answer_blanks[], int length, int *verification, int vowel_check, char vowel, int *Point_Per_Round);
void find_puzzle(the_game *pt, int num, the_game *current2, the_game *headp2, Player *qt, Player *start);
void free_node(the_game **h, the_game **c, the_game *pt);
void end_game(Player *pt, int player_count);
void Gold();
void Money();

int main(void) {
    
    int i = 0, player_count = 0, puzzle_number = 0, tempcheck = 0;
    the_game *headp2 = NULL, *temp2 = NULL, *current2 = NULL;
    Player *headp1 = NULL, *temp1 = NULL, *current1 = NULL;
    FILE *input;
    time_t t;
    
    srand((unsigned)time(&t));
    
    input = fopen("Game_Files.txt", "r");  // Opens game file, reads for file.
    if (input == NULL)
        printf("Error.  Could Not Find File.\n");
    
    while (!feof(input)) {
        temp2 = (the_game*)malloc(sizeof(the_game));  // creation of memory
        scan_func(temp2, input);                      // initialization of element of list
        
        if (current2 == NULL)
            headp2 = temp2;                            // setting the head of the list
        
        else
            current2->listp2 = temp2;                   // else connecting to previous element
        
        i++;                                         // count number of elements added
        current2 = temp2;                              // updating the current element
        temp2->listp2 = NULL;                          // setting pointer to NULL
    }  // END OF WHILE TO READ FILE
    
    printf("============================\n");
    printf("Welcome to Fortuitous Disks!\n");
    printf(" The game where everthing's \n");
    printf("made up and the points don't\n");
    printf(" matter.  That's right, the \n");
    printf("points are like the plot to \n");
    printf("  'Mission Impossible 2'    \n");
    
    Gold();
    
    do {
        printf("Enter the amount of players,\n\tpress ENTER,\nand enter the players names: ");  // Reads in amount of players
        scanf("%d", &player_count);
        clean_buffer();
        if (abs(player_count) > 4)
            printf("\nPlease enter 1-4 players.  This isn't Monopoly.\n");
        else
            tempcheck = 1;
    } while (tempcheck != 1);
    
    i = 0;
    
    while (i < player_count) {
        temp1 = (Player*)malloc(sizeof(Player));  // creation of memory
        scan_player(temp1);                                          // initialization of element of list
        
        if (current1 == NULL)
            headp1 = temp1;                            // setting the head of the list
        
        else
            current1->listp1 = temp1;                   // else connecting to previous element
        
        i++;                                         // count number of elements added
        current1 = temp1;                              // updating the current element
        temp1->listp1 = NULL;                          // setting pointer to NULL
    }  // Reading in players loop
    current1->listp1 = headp1;
    
    printf("\n\nPlease Welcome: ");  // Displays Welcome Message
    print_players(headp1, player_count);
    printf("\nReady to play?\n");
    
    for (i = 1; i < ROUNDS; i++) {  // Counts the 5 rounds
        printf("\n=========\nRound %d!\n=========\n", i);
        RoundNumberTest = i;
        puzzle_generator(&puzzle_number);
        find_puzzle(headp2, puzzle_number, current2, headp2, headp1, headp1);
        if (i != ROUNDS - 1)
            end_game(headp1, player_count + MAYBE);  // if not the last round print just the players and the scores, do not display winner
    }
    
    end_game(headp1, player_count);  // Prints final scores./winner and ASCII art
    
    printf("\n");
    
    printf("\n\nContestants!  Thanks for playing!\n");
    return 0;
}

// SCAN FUNCTIONS
void scan_func(the_game *pt, FILE *input) {  // uses fgets to scan in the clues and solutions
    fgets(pt->gameClue, SIZE, input);
    fgets(pt->gameSolution, SIZE, input);
}
void scan_player(Player *pt) {  // scans in player names and sets the users score to 0
    scanf("%s", pt->name);
    pt->score = 0;
}

// PRINT FUNCTIONS
void print_CLUE(the_game *pt) {
    printf("%s\n", pt->gameClue);
}
void print_SOLUTION(the_game *pt) {
    printf("%s\n", pt->gameSolution);
}
void print_players(Player *pt, int playercount) {  // Prints list of players
    int i;
    if (pt == NULL)
        printf("There don't seem to be any players..\n");
    else {
        for (i = 0; i < playercount; i++) {
            printf("%s! ", pt->name);
            pt = pt->listp1;
        }
    }
}
void print_blank_solution(char blanks[], int length) {  // Prints blank solutions for puzzle
    int i;
    for (i = 0; i < length; i++) {
        if (blanks[i] == '_') {
            printf("( %c ) ", blanks[i]);
        }
        else
            printf("%c ", blanks[i]);
    }
}
void print_letters_guessed(char blanks[], int length) {  // prints the list of blank characters
    int i;
    printf("\n");
    for (i = 0; i < length; i++) {
        blanks[i] = toupper(blanks[i]);
        printf("%c ", blanks[i]);
    }
}
void end_game(Player *pt, int player_count) {  // Prints current scores of player or final score board
    int i = 1;
    int max = 0;
    char name[SIZE];
    printf("\n");
    printf("==============================================\n");
    
    if (player_count < 5) {  // if playercount is less than 5 print out the players and the scores and decide a winnter
        while (i < player_count + 1) {
            printf("Player %d: %-20s: %-7d Points!\n", i, pt->name, pt->score);
            if (pt->score > max) {
                max = pt->score;
                strcpy(name, pt->name);  // copies max score into the string name for printing winnter
            }
            
            pt = pt->listp1;
            i++;
        }
        printf("\n%20s WINS!\n", name);
        printf("==============================================\n");
        Money();
    }
    
    else {  // if the amount of players have modified MAYBE will print only the names and scores without displaying the winner
        while (i < player_count + 1 - MAYBE) {
            printf("Player %d: %-20s: %-7d Points!\n", i, pt->name, pt->score);
            if (pt->score > max) {
                max = pt->score;
                strcpy(name, pt->name);
            }
            
            pt = pt->listp1;
            i++;
        }
        
    }
    printf("\n");
}

// LINKED LIST GENERAL FUNCTIONS
void find_puzzle(the_game *pt, int num, the_game *current2, the_game *headp2, Player *qt, Player *start) {  // Finds puzzle from random puzzle generator, calls game function then sends node to be deleted
    int i = 0;
    while (pt != NULL && i <= num) {
        pt = pt->listp2;
        i++;
    }
    play_game(pt, qt, start);
    
    free_node(&headp2, &current2, pt);
}
void free_node(the_game **h, the_game **c, the_game *pt) {
    the_game *target;                    // Pointer to string to be deleted
    the_game **temp = h;                 // Pointer to the head of the list
    target = pt;
    
    if (target == NULL)
        printf("This entry does not exist.\n");
    else {
        while ((*temp) != target) {
            temp = &(*temp)->listp2;    // Locating address of previous element
        }
        if (target == *h)                // If first element must be deleted
            *h = target->listp2;        // make head point to the next element
        if (target == *c)                // if last element is to be deleted
            *c = *temp;                 // update the position of the last element
        
        *temp = target->listp2;         // skip element to be deleted
        free(target);                   // free the memory
    }
    
}

// GAME FUNCTIONS
void the_Disk(int *num) {  // "Spins" disk and displays results
    *num = ((rand() % 25));
    printf("\n");
    if (*num >= 10) {
        printf("  You spun a:\n");
        printf(" ____________  \n");
        printf(" \\          / \n");
        printf("  \\        / \n");
        printf("   \\  %2d  / \n", *num);
        printf("    \\    /  \n");
        printf("     \\  /  \n");
        printf("      \\/  \n");
    }
    else {
        printf("   You spun a:\n");
        printf(" _____________  \n");
        printf(" \\           / \n");
        printf("  \\         / \n");
        printf("   \\   %d   / \n", *num);
        printf("    \\     /  \n");
        printf("     \\   /  \n");
        printf("      \\ /  \n");
    }
    printf("Wow!  That's %d points for each correct letter!\n", *num * 100);
    
    
}
void puzzle_generator(int *num) {  // Generates random puzzle
    *num = ((rand() % GAMESIZE));
}
void play_game(the_game *pt, Player *qt, Player *start){
    char answer_string[SIZE] = { '\0' };
    char answer_blanks[SIZE] = { '_' };
    char guess_phrase[SIZE] = { '\0' };
    char options;
    int disk = 0;
    int round_Score = 0;
    int Point_Per_Round;
    int SOLVEPUZZLE = FALSE;
    int cheque = 0;
    int length = 0, i = 0, j, v;
    char vowel = '\0';
    int m = 0;
    int P; // in accordance with nodes up to PP
    
    strcpy(answer_string, pt->gameSolution);  // Copies gameSolution to string
    
    //    printf("Guessing: ");
       print_SOLUTION(pt);
    
    //printf("The Secret Puzzle Is:\n");
    clean_buffer();
    
    do {                                                                    // assigns answer_blanks "_" values if a character is present until '\0' character
        if (((answer_string[i] >= 32) && (answer_string[i] <= 64))) {
            answer_blanks[i] = answer_string[i];
        }
        else {
            answer_blanks[i] = '_';
        }
        i++;
    } while (answer_string[i] != '\0');
    length = strlen(answer_string) - 1;
    
    // print_blank_solution(answer_blanks, length);
    printf("\n");
    
    if (PP == 0) {   // if first player of game, do nothing
                     // Do nothing
    }
    
    else {
        for (P = 0; P <= PP + 3; P++)  // takes last player to finish puzzle and continues game from next player
            qt = qt->listp1;
    }
    
    round_Score = 0;  // presets round score
    
    do {							//Player must get the three options after every turn
        
        if (SOLVEPUZZLE == FALSE) {
            printf("-----------------------------");
            printf("\n%s's Total Score: %d\n", qt->name, qt->score);
            printf("\nYour clue is: ");
            print_CLUE(pt);
            printf("The puzle is:\n");
            print_blank_solution(answer_blanks, length);
            printf("\n");
            printf("+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*");
            printf("\n%s, Choose one of the three options:\n\"S\": SPIN THE DISK\n\"B\": BUY A VOWEL\n\"A\": GO ALL IN AND SOLVE THE PUZZLE!\n", qt->name);
            options = getchar();  // takes in one of the options from user
            clean_buffer();
            printf("+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*\n");
        }
        else if (SOLVEPUZZLE == MAYBE)  // autoselects buying a vowel
            options = 'B';
        
        else if (SOLVEPUZZLE == MAYBE + 10)  // autoselects spinning the disk
            options = 'S';
        
        else {
            options = 'A';  // autoselects solving the puzzle
        }
        
        vowel = '\0';  // resets the vowel character to null
        
        switch (options) {
            case 'S':
            case 's':
                printf("\nSpinning the disk!");
                the_Disk(&disk);
                if (disk == 0) {
                    printf("\nYou've gone bankrupt!\n");  // reset round score/ change player/ increase PP (player counter)/ change cheque to false
                    round_Score = 0;
                    qt = qt->listp1;
                    PP += 1;
                    cheque = FALSE;
                    SOLVEPUZZLE = FALSE;  // resets incase it comes off a re-spin
                }
                else if (disk == 13) {  // check if they lose points for getting 13
                    printf("\nBut I'm sorry!  13 Means Turn Lost!\n");
                    qt->score += round_Score;
                    qt = qt->listp1;
                    PP += 1;
                    cheque = FALSE;
                    round_Score = 0;
                    SOLVEPUZZLE = FALSE;
                }
                else {
                    printf("Once again your clue is: ");
                    print_CLUE(pt);
                    m = 1;
                    puzzle_verification(answer_string, answer_blanks, length, &cheque, m, vowel, &Point_Per_Round);  // checks if a letter is found and how many times
                    
                    if (cheque == FALSE) {  // If letter guessed no longer exists, add round_score to user score, change player, increase PP, reset roundscore
                        round_Score += (disk * 100) * Point_Per_Round;
                        printf("\n%s's round score: %d\n", qt->name, round_Score);
                        qt->score += round_Score;
                        qt = qt->listp1;
                        PP += 1;
                        SOLVEPUZZLE = FALSE;
                        round_Score = 0;
                    }
                    else if (cheque == MAYBE) {  // Set SOLVEPUZZLE to true to jump straight to solving puzzle, add roundscore to score, force loop
                        SOLVEPUZZLE = TRUE;
                        round_Score += (disk * 100) * Point_Per_Round;
                        printf("\n%s's round score: %d\n", qt->name, round_Score);
                        cheque = FALSE;
                        //round_Score = 0;
                    }
                    else if (cheque == (MAYBE + 5)) {  // Set SOLVEPUZZLE to maybe and jump straight to buying a vowel
                        SOLVEPUZZLE = MAYBE;
                        round_Score += (disk * 100) * Point_Per_Round;
                        printf("\n%s's round score: %d\n", qt->name, round_Score);
                        cheque = FALSE;
                    }
                    else if (cheque == MAYBE + 10) {  // Set SOLVEPUZZLE to maybe+10 to jump straight to respinning the disk and guessing
                        SOLVEPUZZLE = MAYBE + 10;
                        round_Score += (disk * 100) * Point_Per_Round;
                        printf("\n%s's round score: %d\n", qt->name, round_Score);
                        cheque = FALSE;
                    }
                    
                }
                break;
            case 'B':
            case 'b':
                if (round_Score < 250 && qt->score < 250) {  // if round score is less than 250 or bank is less than 250 can't buy vowel
                    printf("You don't have enough money to buy a vowel!\n");
                }
                else {
                    if(qt->score < 250)  // if not enough money in bank deduct from round points
                        round_Score -= 250;
                    else
                        qt->score -= 250;		// Points deducted from bank if money
                    
                    m = 2;
                    printf("\nPick a Vowel:  A, E, I, O, U: ");
                    vowel = getchar();
                    clean_buffer();
                    
                    for (v = 0; v < SIZE; v++) {  // Checks if vowel has already been guessed
                        vowel = toupper(vowel);
                        if (answer_blanks[v] == vowel) {
                            vowel = 'F';
                            break;
                        }
                    }
                    
                    switch (vowel) {  // makes sure the player chose a vowel
                        case 'A':
                        case 'a':
                            puzzle_verification(answer_string, answer_blanks, length, &cheque, m, vowel, &Point_Per_Round);
                            break;
                        case 'E':
                        case 'e':
                            puzzle_verification(answer_string, answer_blanks, length, &cheque, m, vowel, &Point_Per_Round);
                            break;
                        case 'I':
                        case 'i':
                            puzzle_verification(answer_string, answer_blanks, length, &cheque, m, vowel, &Point_Per_Round);
                            break;
                        case 'O':
                        case 'o':
                            puzzle_verification(answer_string, answer_blanks, length, &cheque, m, vowel, &Point_Per_Round);
                            break;
                        case 'U':
                        case 'u':
                            puzzle_verification(answer_string, answer_blanks, length, &cheque, m, vowel, &Point_Per_Round);
                            break;
                        case 'F':
                            printf("That vowel has already been guessed!\n");
                            cheque = TRUE;
                            break;
                        default:
                            printf("You should have picked a vowel.\n");
                    }
                    if (cheque == FALSE) {// If vowel doesn't exist reset roundscore, CP-IPP
                        qt->score += round_Score;
                        round_Score = 0;  //  resets for next players round
                        qt = qt->listp1;
                        PP += 1;
                    }
                    else {
                        cheque = FALSE;  // If vowel exitst force loop
                    }
                    printf("\n");
                }
                
                SOLVEPUZZLE = FALSE;  // resets solvepuzzle to go back through choices
                break;
            case 'A':
            case 'a':
                printf("Enter the puzzle!\n");
                fgets(guess_phrase, SIZE, stdin);
                for (j = 0; j < SIZE; j++)
                    guess_phrase[j] = toupper(guess_phrase[j]);
                clean_buffer();
                if (strcmp(answer_string, guess_phrase) == 0) {  // if guess is correct add 2000, add round score, CP-IPP, cheque = true exits round
                    printf("That is correct!  You get 2000 points!\n\n");
                    round_Score += 2000;
                    qt->score += round_Score;
                    qt = qt->listp1;
                    PP += 1;
                    cheque = TRUE;
                    round_Score = 0;
                    SOLVEPUZZLE = FALSE;
                }
                else {
                    printf("I'm sorry, that is incorrect!  You'll lose a turn for that, and I award you no points.\n\n");  // If wrong CP-IPP, reset roundscore, force loop
                    qt = qt->listp1;
                    PP += 1;
                    cheque = FALSE;
                    round_Score = 0;
                    SOLVEPUZZLE = FALSE;
                }
                break;
            default:
                printf("Don't get smart with me.\n");
                cheque = FALSE;
                SOLVEPUZZLE = FALSE;
        }
        
        
    } while (cheque == FALSE);  // loop will run as long as cheque is false, if true will exit loop back to main and start second round
    
    
    printf("\n============================\nWINNER WINNER CHICKEN DINNER\n============================\n\n");
    Gold();
    printf("\n");
    
    
}

// PUZZLE CHECKING FUNCTIONS
void puzzle_verification(char answer_string[], char answer_blanks[], int length, int *verification, int vowel_check, char vowel, int *Point_Per_Round) {
    char search, guess;
    int j, n = 0, stat = 0;
    int guess_length;
    char continues;
    int verifycheck = 0;
    int guessedCheck = FALSE;
    
    *Point_Per_Round = 0;
    
    if (RoundNumberTest == 1 && temp == 0) {  // If first round, ignore, and make temp the round number
        temp = RoundNumberTest;
    }
    else if (RoundNumberTest > temp){  // of next round reset answerguess string and k value
        k = 0;
        for (j = 0; j < SIZE; j++)
            answer_guesses[j] = '\0';
        temp = RoundNumberTest;
    }
    
    
    if (vowel != '\0') {  // if vowel character is assaigned  run through checking and printing vowels
        check(answer_string, answer_blanks, vowel, verification, Point_Per_Round);
        print_blank_solution(answer_blanks, length);
    }
    
    else {  // if guessing consonent run guessing letters instead
        
        guessedCheck = FALSE;  // preset guessedCheck for already guesse letters
        
        printf("\nEnter a letter Guess: ");
        search = getchar();
        clean_buffer();
        guess = tolower(search);
        
        if (search >= 48 && search <= 57){  // if a number return stat 0
            guessedCheck = TRUE;
            n = 1;
            stat = 0;
        }
        
        else{  // otherwise place search into answer guessed
            answer_guesses[k] = search;
            search = toupper(search);
            n = 0;
        }
        
        if (k != 0 && n != 1) {  // search through answerguesses string for character, if exists break and go to if statement
            for (j = 0; j <= k - 1; j++) {
                if (answer_guesses[j] == search) {
                    guessedCheck = TRUE;
                    stat = 1;
                    break;
                }
            }
        }
        
        
        
        if (guessedCheck == TRUE) {  // analyze stat for either preguessed letter or number, set verification to false
            if (stat == 1)
                printf("Someone has already guessed that letter!\n");
            if (stat == 0)
                printf("Sorry, but you cannot guess a number.\n");
            *verification = FALSE;  // goes make to the game and CP-IPP
        }
        
        else {  // if letter hasn't been guessed check if vowel
            k++;
            
            if (guess != 97 && guess != 101 && guess != 105 && guess != 111 && guess != 117){
                check(answer_string, answer_blanks, search, verification, Point_Per_Round);  // check if it exists, count # of times
                print_blank_solution(answer_blanks, length);  // print new blank solution (w/ guesses if applicatble)
                
                printf("\nLetters Guessed: ");  // print out answer_guesses string
                guess_length = strlen(answer_guesses) + 0;
                print_letters_guessed(answer_guesses, guess_length);
                printf("\n");
            }
            else
                printf("Sorry, but we do not have conformation to allow to pick a vowel.\n");
        }
        verifycheck = *verification;  // pass pointer value for use later if letter exists
        
        if (verifycheck == TRUE) {  // offer choice to continue guessing, pass the wheel, or solve the puzzle
            printf("Do you want to continue playing? (Y)es or (B)uy a vowel or (S)olve the Puzzle?\n");
            continues = getchar();
            clean_buffer();
            if (continues == 'Y' || continues == 'y') {
                *verification = MAYBE + 10;
            }
            else if (continues == 'B' || continues == 'b') {
                *verification = MAYBE + 5;  // goes to the game and CP-IPP
            }
            else if (continues == 'S' || continues == 's') {
                *verification = MAYBE;  // initiates the game to jump to solve puzzle
            }
            
            else {
                printf("I'm sorry I didn't understand that.  Returning to menu.\n");
                
                *verification = FALSE;
            }
        }
        
        
        
        printf("\n");
        
    }
}

void check(char answer_string[], char* answer_blanks, char guess, int *verification, int *Point_Per_Round) {
    char * found;
    char look;
    int i = 0, j = 0, location[SIZE] = { 0 }, total = 0;
    
    look = toupper(guess);	//Turns guess to uppercase if not yet one
    
    found = strchr(answer_string, look); //Finds first instance of guess letter
    
    while (found != NULL){
        location[i] = found - answer_string + 1;  //stores position of letter
        found = strchr(found + 1, look);	//Looks for next instance
        total++;   //Incriments total of times letter is found
        i++;	//Increments i to go to next element in location array
    }
    
    if (total == 0){    //When letter cannot be found
        printf("Oh I'm sorry but the letter %c is not part of the secret puzzle.\n\n", toupper(guess));
        *verification = FALSE;
    }
    
    else if (total != 0){		//Displays the number of times letter was found
        if (total == 1){
            printf("It looks like there is %d %c in the secret puzzle.\n\n", total, toupper(guess));
        }
        else if (total > 1){
            printf("It looks like there is %d %c in the secret puzzle.\n\n", total, toupper(guess));
        }
        *verification = TRUE;
    }
    
    for (i = 0; i < total; i++){	//Inserts correct letters into puzzle
        j = location[i] - 1;
        answer_blanks[j] = answer_string[j];
    }
    
    *Point_Per_Round += total;
    
    answer_blanks[strlen(answer_string)] = '\0'; //Due to problem when inserting last letter
    
    return;
    
}

// MISC FUNCTIONS
void clean_buffer() {
    fpurge(stdin); // cleans XCODE
    fflush(stdin); // cleans MSVS
}
void Gold() {
    printf("============================\n");
    printf(" _oOoOoOo_      _oOoOoOo_\n(oOoOoOoOo)    (oOoOoOoOo)\n )`\"\"\"\"\"`(      )`\"\"\"\"\"`(  \n/         \\    /         \\   \n| G O L D |    | G O L D |\n\\         /    \\         / \n`=========`    `=========` \n");
    printf("============================\n\n");
    return;
}
void Money() {
    
    printf("__________________________________________________\n");
    printf("|                                                |\n");
    printf("|)           $                     $            (|\n");
    printf("| )         $$$                   $$$          ( |\n");
    printf("|  )       $ $          o        $ $          (  |\n");
    printf("|   )      $ $                   $ $         (   |\n");
    printf("|    )      $$$    o    o   o     $$$       (    |\n");
    printf("|   )        $ $                   $ $       (   |\n");
    printf("|  )         $ $        o          $ $        (  |\n");
    printf("| )         $$$                   $$$          ( |\n");
    printf("|)           $                     $            (|\n");
    printf("|________________________________________________|\n");
}

// V3.3: Rewrote everything into linked lists formats
// V3.4: Fixed error on line 298-302 involving switching players, removed 324 due to error - needs to be fixed/modified
// V3.5: Implimented 352-353 for guessing vowels, Fixed looping players - added pointer start to play_Game players, added 371-372 to end guessing if puzzle is solved
// V3.6 Line 352 fixed vowels; Line 370 added buying vowels and Lines 287-317
// V3.7 Line 310 modified switch statement, Line 111 made list continuous, Line 171 added in endgame winner - may not be correct - check, Line 263 added loop to start round at next player,  Line 272 added in PP to advance player count, Function 144 modified print players to fix infinite loop, Line 169 fixed another infinate loops
// V3.8 Line 429 fixed issue with looping on false letters - added pointer, Line 407 fixed passing back point per round, line 432 added in spinner details to continue playing or spin again., Line 190 added seconday player print out to display current scores after each round, 423 make K a global variable for the answer_guesses string, line 441 made answer_guesses a global variable, modified 444 to end turn when vowel doesn't exists/exists,  possible fixed issues with scores, added lines 468 - 497 to account for continues to play for points to jumping out to solve puzzle, line 302 added printf to display current user/score, lines 289 - 296 modified player starter so it would start with first player entered,  small modifications to print out spacing/layouut, added in gold printout, Line 312 added vowel to null to reset character, Line 393 added else to continue guessing after finding a vowel, Line 450-458 resets answer guess string, Line 451 added Points to zero to try and fix inflated scores - may not have worked, added in spinner things
// V3.9 Lines 492 to 512 added check to stop used from re-entering letters, changed printout statements for amount of letters in puzzle Line 589, modified score keeping, Line 482 prevented guessed string from resetting after round 1, Line 180 added added function print_letters_guessed, if player guesses already called letter advances players,  changes fgets for character reads to getchar() in order to stop from entering more than 1 character,
// V3.10 Lines 416 added check to see if vowel has already been guessed, added intro section,
// V3.11 Line 520 temp initialized - causes error in MSVS if not, Line 160 initializes player scores to zero - displays large negative number in MSVS if not added
// V3.12 Added ability to buy a vowel mid round Line 360, Line 560 made search uppercase so that it looks through answer_guesses correctly, Line 423 added in secondary spin cycle for guessing letters, added in second clue hint to print when continuously guessing letters, moved print statement for "Wow thats __points" into function the_disk(), added SOLVEPUZZLE to FALSE in cheque==false to reset the spinner thingys from looping back to spinning Line 365, removed "i" verifications in puzzle_verifcation - no longer needed redundancy, Lengths long to int comparisons fixed - XOver problems between MSVS and XCode,
// V3.13 Line 391 to store player points before losing turn when spinning a 13, Line 577-607 edited to prevent guessing of a number
// V3.14 Line 551 Made temp a global variable to make resetting functions work after round 1,  Line 387/396 added in failsafes for SOLVEPUZZLE in disk == 13 and disk == 0 and switch default, deleted round score from 507 after winning the game - total scores displayed next, Line 357 reprints the game puzzle, Line 439 added secondary condition to check total score and round score since roundscore no longer assigns mid round, added secondary print out of puzzle above choices, changed "x's current round score" to "x's round score", removed 323/337 because of line 357, Line 444 take money from bank or current round score based on points, changed PP loop to correctly choose next player,

