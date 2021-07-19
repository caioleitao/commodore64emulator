//
// Created by Kyle on 7/14/21.
//

#include "cia2.h"

Cia2::Cia2() {
    timer_a_latch_ = timer_b_latch_ = timer_a_counter_ = timer_b_counter_ = 0;
    timer_a_enabled_ = timer_b_enabled_ = timer_a_irq_enabled_ = timer_b_irq_enabled_ = false;
    timer_a_irq_triggered_ = timer_b_irq_triggered_ = false;
    timer_a_input_mode_ = timer_b_input_mode_ = kModeProcessor;
    timer_a_run_mode_ = timer_b_run_mode_ = kModeRestart;
    pra_ = prb_ = 0xff;
    prev_cpu_cycles_ = 0;
}

void Cia2::write_register(uint8_t r, uint8_t v) {
    switch (r) {
        case 0x0:
            pra_ = v;
            break;

        case 0x1:
            prb_ = v;
            break;

        case 0x2:
            break;

        case 0x3:
            break;

        case 0x4:
            timer_a_latch_ &= 0xff00;
            timer_a_latch_ |= v;
            break;

        case 0x5:
            timer_a_latch_ &= 0x00ff;
            timer_a_latch_ |= v << 8;
            break;

        case 0x6:
            timer_b_latch_ &= 0xff00;
            timer_b_latch_ |= v;

        case 0x7:
            timer_b_latch_ &= 0x00ff;
            timer_b_latch_ |= v << 8;
            break;

        case 0x8:
            break;

        case 0x9:
            break;

        case 0xa:
            break;

        case 0xb:
            break;

        case 0xc:
            break;

        case 0xd:
            if(ISSET_BIT(v,8)) timer_a_irq_enabled_ = ISSET_BIT(v,7);
            if(ISSET_BIT(v,1)) timer_b_irq_enabled_ = ISSET_BIT(v,7);

            break;

        case 0xe:
            timer_a_enabled_ = ((v&(1<<0))!=0);
            timer_b_input_mode_ = (v&(1<<5)) >> 5;

            if((v&(1<<4))!=0)
                timer_b_counter_ = timer_b_latch_;
            break;
    }

}

uint8_t Cia2::read_register(uint8_t r) {
    uint8_t retval = 0;

    switch (r) {
        case 0x0:
            retval = pra_;
            break;

        case 0x1:
            retval = prb_;
            break;

        case 0x2:
            break;

        case 0x3:
            break;

        case 0x4:
            retval = (uint8_t)((timer_a_counter_ & 0xff00) >> 8);

        case 0x5:
            retval = (uint8_t)((timer_a_counter_ & 0xff00) >> 0);

        case 0x6:
            retval = (uint8_t)(timer_b_counter_ & 0x00ff);
            break;

        case 0x7:
            retval = (uint8_t)((timer_b_counter_ & 0xff00) >> 8);
            break;

        case 0x8:
            break;

        case 0x9:
            break;

        case 0xa:
            break;

        case 0xb:
            break;

        case 0xc:
            break;

        case 0xd:
            if(timer_a_irq_triggered_ || timer_b_irq_triggered_) {
                retval |= (1 << 7);
                if(timer_a_irq_triggered_) retval |= (1 << 0);
                if(timer_b_irq_triggered_) retval |= (1 << 1);
            }
            break;

        case 0xe:
            break;

        case 0xf:
            break;
    }
    return retval;
}

void Cia2::reset_timer_a() {
    switch (timer_a_run_mode_) {
        case kModeRestart:
            timer_a_counter_ = timer_a_latch_;
            break;

        case kModeOneTime:
            timer_a_enabled_ = false;
            break;
    }
}

void Cia2::reset_timer_b() {
    switch (timer_b_counter_) {
        case kModeRestart:
            timer_b_counter_ = timer_b_latch_;
            break;

        case kModeOneTime:
            timer_b_enabled_ = false;
            break;
    }
}

uint16_t Cia2::vic_base_address() {
    return ((~pra_&0x3) << 14);
}

bool Cia2::emulate() {
    if(timer_a_enabled_) {
        switch (timer_a_input_mode_) {
            case kModeProcessor:
                timer_a_counter_ -= cpu_->cycles() - prev_cpu_cycles_;

                if (timer_a_irq_enabled_) {
                    timer_a_irq_triggered_ = true;
                    cpu_->nmi();
                }
                reset_timer_a();
        }
        break;
        case kModeCNT:
            break;
    }
}

if(timer_b_enabled_) {
switch(timer_b_input_mode_) {
case kModeProcessor:
timer_b_counter_ -= cpu_->

cycles()

-
prev_cpu_cycles_;
if(timer_b_counter_ <= 0) {
if(timer_b_irq_enabled_) {
timer_b_irq_triggered_ = true;
cpu_->

nmi();

}

reset_timer_b();

}
break;
case kModeCNT:
break;
case kModeTimerA:
break;
case kModeTimerACNT:
break;
}
}
    prev_cpu_cycles_ = cpu_->cycles();
    return true;






