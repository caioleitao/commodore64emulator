//
// Created by Kyle on 7/11/21.
//

#ifndef COMMODORE64EMULATOR_CIA1_H
#define COMMODORE64EMULATOR_CIA1_H

#include "io.h"
#include "cpu.h"

class Cia1 {
private:
    Cpu *cpu_;
    IO *io_;
    int16_t timer_a_latch_;
    int16_t timer_b_latch_;
    int16_t timer_a_counter_;
    int16_t timer_b_counter_;
    bool timer_a_enabled_;
    bool timer_b_enabled_;
    bool timer_a_irq_enabled;
    bool timer_b_irq_enabled;
    bool timer_a_irq_triggered;
    bool timer_b_irq_triggered;
    uint8_t timer_a_run_mode_;
    uint8_t timer_b_run_mode_;
    uint8_t timer_a_input_mode_;
    uint8_t timer_b_input_mode_;
    unsigned int prev_cpu_cycles_;
    uint8_t pra_,prb_;
public:
    Cia1();
    void cpu(Cpu *v){cpu_ = v;};
    void io(IO *v){io_ = v;};
    void write_register(uint8_t r, uint8_t v);
    uint8_t read_register(uint8_t r);
    void reset_timer_a();
    void reset_timer_b();
    bool emulate();

    enum kInputMode {
        kModeProcessor,
        kModeCNT,
        kModeTimerA,
        kModeTimerACNT
    };

    enum kRunMode {
        kModeRestart,
        kModeOneTime
    };
};

#endif //COMMODORE64EMULATOR_CIA1_H
