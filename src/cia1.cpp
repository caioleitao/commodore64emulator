//
// Created by Kyle on 7/14/21.
//

#include "cia1.h"

Cia1::Cia1() {
    timer_a_latch_ = timer_b_latch_ = timer_a_counter_ = timer_b_counter_ = 0;
    timer_a_enabled_ = timer_b_enabled_ = timer_a_irq_enabled_ = timer_b_irq_enabled_ = false;
    timer_a_irq_triggered_ = timer_b_irq_triggered_ = false;
    timer_a_input_mode_ = timer_b_input_mode_ = kModeProcessor;
    timer_a_run_mode_ = timer_b_run_mode_ = kModeRestart;
    pra_ = prb_ = 0xff;
    prev_cpu_cycles_ = 0;
}

void Cia1::write_register(uint8_t r, uint8_t v) {
    switch (r) {
        case 0x0:
            pra_ = v;
            break;

        case 0x1:
            break;

        case 0x2:
            break;

        case 0x3:
            break;

        case 0x4:
            timer_a_latch_ &= 0x00ff;
            timer_a_latch_ |= v;
            break;

        case 0x5:
            timer_a_latch_ &= 0xff00;
            timer_a_latch_ |= v << 8;
            break;

        case 0x6:
            timer_b_latch_ &= 0xff00;
            timer_a_latch_ |= v;
            break;

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
            if(ISSET_BIT(v,0)) timer_a_irq_enabled_ = ISSET_BIT(v,7);
            if(ISSET_BIT(v,1)) timer_b_irq_enabled_ = ISSET_BIT(v,7);
            break;

        case 0xe:
            timer_a_enabled_ = ((v&(1<<0))!=0);
            timer_a_input_mode_ = (v&(1<<5)) >> 5;

            if((v&(1<<4))!=0)
                timer_a_counter_ = timer_a_latch_;
            break;

        case 0xf:
            timer_b_enabled_ = ((v&0x1)!=0);
            timer_b_input_mode_ = (v&(1<<5)) | (v&(1<<6)) >> 5;

            if((v&(1<<4))!=0)
                timer_b_counter_ = timer_b_latch_;
            break;
    }
}

uint8_t Cia1::read_register(uint8_t r) {
    uint8_t retval = 0;

    switch (r) {
        case 0x0:
            break;

        case 0x1:
            if (pra_ == 0xff) retval = 0xff;
            else if(pra_) {
                int col = 0;
                uint8_t v = ~pra_;
                while (v >>= 1)col++;
                retval = io_->keyboard_matrix_row(col);
            }
            break;

        case 0x2:
            break;

        case 0x3:
            break;

        case 0x4:
            retval = (uint8_t)(timer_a_counter_ & 0x00ff);
            break;

        case 0x5:
            retval = (uint8_t)((timer_a_counter_ & 0x00ff) >> 8);
            break;

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
            if (timer_a_irq_triggered_ || timer_b_irq_triggered_) {
                if (timer_a_irq_triggered_) retval |= (1 << 0);
                if (timer_b_irq_triggered_) retval |= (1 << 1);
            }
            break;

        case 0xe:
            break;

        case 0xf:
            break;
    }
    return retval;
}

void Cia1::reset_timer_a() {
    switch (timer_a_run_mode_) {
        case kModeRestart:
            timer_a_counter_ = timer_a_latch_;
            break;

        case kModeOneTime:
            timer_a_enabled_ = false;
            break;
    }
}

void Cia1::reset_timer_b() {
    switch (timer_b_run_mode_) {
        case kModeRestart:
            timer_b_counter_ = timer_b_latch_;
            break;
        case kModeOneTime:
            timer_b_enabled_ = false;
            break;
    }
}

bool Cia1::emulate() {
    if(timer_a_enabled_) {
        switch (timer_a_input_mode_) {
            case kModeProcessor:
                timer_a_counter_ -= cpu_->cycles() - prev_cpu_cycles_;
                if (timer_a_counter_ <= 0) {
                    if (timer_a_irq_enabled_) {
                        if (timer_a_irq_enabled_) {
                            timer_a_irq_triggered_ = true;
                            cpu_->irq();
                        }
                        reset_timer_a();
                    }
                    break;
                    case kModeCNT:
                        break;

                }
        }

        if(timer_b_enabled_) {
            switch (timer_b_input_enabled_) {
                case kModeProcessor:
                    timer_b_counter_ -= cpu_->cycles() - prev_cpu_cycles_;
                    if (timer_b_counter_ <= 0) {
                        if(timer_b_irq_enabled_) {
                            timer_b_irq_triggered_ = true;
                            cpu_->irq();
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

    }
    prev_cpu_cycles_ = cpu_->cycles();
    return true;
}