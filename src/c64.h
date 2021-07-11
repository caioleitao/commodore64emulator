//
// Created by Kyle on 7/10/21.
//

#ifndef COMMODORE64EMULATOR_C64_H
#define COMMODORE64EMULATOR_C64_H

#include <functional>

#include "cpu.h"
#include "memory.h"
#include "cia1.h"
#include "cia2.h"
#include "vic.h"
#include "sid.h"
#include "io.h"

#ifdef DEBUGGER_SUPPORT
#include "debugger.h"
#endif

class C64 {
private:
    Cpu *cpu_;
    Cia2 *cia1_;
    Cia2 *cia2_;
    Vic *vic_;
    Sid *sid_;
    IO *io_;
    std::function<bool()> callback_;
#ifdef DEBUGGER_SUPPORT
    Debugger *debugger_;
#endif
public:
    C64();
    ~C64();
    void start();
    void emscripten_loop();
    void callback(std::function<bool()> cb){callback_ = cb;};
    Cpu * cpu(){return cpu_;};
    Memory * memory(){return mem_;};
    IO * io(){return cpu_;};

    void test_cpu();
};

#endif

