//
// Created by Kyle on 7/10/21.
//

#ifndef COMMODORE64EMULATOR_LOADER_H
#define COMMODORE64EMULATOR_LOADER_H

#include <fstream>
#include "c64.h"

class Loader {
private:
    bool booted_up_;
    C64 *c64_;
    Cpu *cpu_;
    Memory *mem_;
    std::ifstream is_;
    enum kFormat {
        kNone,
        kBasic,
        kRPG
    };
    kFormat format_;
    void load_basic();
    void load_prg();
    uint16_t read_short_le();
public:
    Loader(C64 *c64);
    void bas(const std::string &f);
    void prg(const std::string &f);
    bool emulate();

    static const uint16_t kBasicPrgStart = 0x0801;
    static const uint16_t KBasicTxtTab   = 0x002b;
    static const uint16_t kBasicVarTab   = 0x002d;
    static const uint16_t kBasicAryTab   = 0x0031;
};

#endif //COMMODORE64EMULATOR_LOADER_H
