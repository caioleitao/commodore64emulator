//
// Created by Kyle on 7/14/21.
//

#include "loader.h"

Loader::Loader(C64 *c64) {
    c64_ = c64;
    io_  = c64_->io();
    cpu_ = c64_->cpu();
    mem_ = c64_->memory();
    booted_up_ = false;
    format_ = kNone;
}

uint16_t Loader::read_short_le() {
    char b;
    uint16_t v = 0;
    is_.get(b);
    v |= (b);
    is_.get(b);
    v |= b << 8;
    return v;
}

void Loader::bas(const std::string &f) {
    format_ = kBasic;
    is_.open(f,std::ios::in);
}

void Loader::load_basic() {
    char c;
    if(is_.is_open()) {
        while(is_.good()) {
            is_.get(c);
            io_->IO::type_character(c);
        }
    }
}

void Loader::prg(const std::string &f) {
    format_ = kPRG;
    is_.open(f,std::ios::in|std::ios::binary);
}

void Loader::load_prg() {
    char b;
    uint16_t pbuf, addr;
    pbuf = addr = read_short_le();
    if(is_.is_open()) {
        while(is_.good()) {
            is_.get(b);
            mem_->write_byte_no_io(pbuf++,b);
        }
        if(addr == kBasicPrgStart) {
            mem_->write_word_no_io(kBasicTxtTab,kBasicPrgStart);
            mem_->write_word_no_io(kBasicVarTab,pbuf);
            mem_->write_word_no_io(kBasicAryTab,pbuf);
            mem_->write_word_no_io(kBasicStrEnd,pbuf);

            for(char &c: std::string("RUN\n"))
                io_->IO::type_character(c);
        }
        else cpu_->pc(addr);
    }
}

bool Loader::emulate() {
    if(booted_up_) {
        switch (format_) {
            case kBasic:
                load_basic();
                break;
            case kPRG:
                load_prg();
                break;
            default:
                break;
        }
        return false;
    }
    else {
        if(cpu_->pc() == 0xa65c)
            booted_up_ = true;
    }
    return true;
}