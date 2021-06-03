//
// Created by Marvin on 03.06.2021.
//

#ifndef TIC_TAC_TOE_STATES_H
#define TIC_TAC_TOE_STATES_H

class States {
public:
    static int drawingState() {
        std::array<int, 9> bits{0, 2, 5, 6, 7, 1 + 9, 3 + 9, 4 + 9, 8 + 9};
        return Util::set_bits(bits);
    }

    static int losingState() { return Util::set_bits(std::array<int, 3>{9 + 0, 9 + 1, 9 + 2}); }

    static int winningState() { return Util::set_bits(std::array<int, 3>{0, 1, 2}); }
};

#endif //TIC_TAC_TOE_STATES_H
