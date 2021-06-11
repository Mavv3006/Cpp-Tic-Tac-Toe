//
// Created by Marvin on 30.05.2021.
//

#ifndef TIC_TAC_TOE_TICTACTOE_H
#define TIC_TAC_TOE_TICTACTOE_H


#include <vector>

class TicTacToe {
public:
    /**
     * the starting state of the game.
     */
    static const int start = 0;

    /**
     *
     * @param state is an integer representing the board
     * @param player is a player, player 'X' is coded as the number 0, player 'O' is coded
     * as 1
     * @return 1 if player has won the game, -1 if the game is lost for player, 0 if it's a
     * draw and 2 if the game has not yet been decided.
     */
    static int utility(int state, int player);

    /**
     * @param state the current state of the game
     * @return true if the game is over, false otherwise
     */
    static bool finished(int state);

    /**
     * Given a state and the player who is next to move, the function next_states(state, player)
     * computes an array of states that can be reached from state.
     *
     * @param state the current state of the game
     * @param player the player who is next to move
     * @return an array of states that can be reached from state
     */
    static std::vector<int> next_states(int state, int player);

    /**
     * Given a state that is represented as a number, the function empty(state) returns
     * an array of indexes of those cells such that neither player X nor O has placed a mark
     * in the cell. Note that there are 9 cells on the board. Each of these cells can hold
     * either an 'X' or an 'O'. If the i-th cell is marked with an 'X', then the i-th bit of
     * state is set. If instead the i-th cell is marked with an 'O', then the (9+i)-th bit
     * of state is set. If the i-th cell is not yet marked, then both the i-th bit and the
     * (9+i)-th bit are 0.
     *
     * @param state the current state of the game
     * @return the indexes of the cells which are not yet marked
     */
    static std::vector<int> empty(int state);

    /**
     * the function informs the user about the result of the game once the game is finished.
     *
     * @param state the current state of the game
     * @return the value of finished
     * @see finished
     */
    static bool final_msg(int state);
};


#endif //TIC_TAC_TOE_TICTACTOE_H
