//
// Created by Kyle on 7/10/21.
//

#include "cpu.h"
#include "util.h"
#include <sstream>

void Cpu::reset() {
    a_ = x_ = y_ = sp_ = 0;
    cf_ = zf_ = idf_ = dmf_ = bcf_ = of_ = nf_ = false;
    pc(mem_->read_word(Memory::kAddrResetVector));
    cycles_ = 6;
}
bool Cpu::emulate() {
    uint8_t inst = fetch_op();
    bool retval = true;

    switch (insn) {
        case 0x0: brk(); break;

        case 0x1: ora(load_byte(addr_indx()),6); break;

        case 0x5: ora((load_byte(addr_zero()), 3); break;

        case 0x6: asl_mem(addr_zero(), 5); break;

        case 0x8: php(); break;

        case 0x9: ora(fetch_op(),2); break;

        case 0xA: asl_a(); break;

        case 0xD: ora(load_bye(addr_abs()),4); break;

        case 0xE: asl_mem(addr_abs(),6); break;

        case 0x10: bpl(); break;

        case 0x11: ora(load_byte(addr_indy()),5); break;

        case 0x15: ora(load_byte(addr_zerox()),4); break;

        case 0x16: asl_mem(addr_zerox(), 6); break;

        case 0x18: clc(); break;

        case 0x19: ora(load_byte(addr_absy()),4); break;

        case 0x1D: ora(load_byte(addr_absx()),4); break;

        case 0x1E: asl_mem(addr_absx(),7); break;

        case 0x20: jsr(); break;

        case 0x21: _and(load_byte(addr_indx()),6); break;

        case 0x24: bit(addr_zero(),3); break;

        case 0x25: _and(load_byte(addr_zero()),3); break;

        case 0x26: rol_mem(addr_zero(),5); break;

        case 0x28: plp(); break;

        case 0x29: _and(fetch_op(),2); break;

        case 0x2A: rol_a(); break;

        case 0x2C: bit(addr_abs(),4); break;

        case 0x2D: _and(load_byte(addr_abs()),4); break;

        case 0x2E: rol_mem(addr_abs(),6); break;

        case 0x30: bmi(); break;

        case 0x31: _and(load_byte(addr_indy()),5); break;

        case 0x35: _and(load_byte(addr_zerox()),4); break;

        case 0x36: rol_mem(addr_zerox(),6); break;

        case 0x38: sec(); break;

        case 0x39: _and(load_byte(addr_absy()),4); break;

        case 0x3D: _and(load_byte(addr_absx()),4); break;

        case 0x3E: rol_mem(addr_absx(),7); break;

        case 0x40: rti(); break;

        case 0x41: eor(load_byte(addr_indx()),6); break;

        case 0x45: eor(load_byte(addr_zero()),3); break;

        case 0x46: lsr_mem(addr_zero(),5); break;

        case 0x48: pha(); break;

        case 0x49: eor(fetch_op(),2); break;

        case 0x50: bvc(); break;

        case 0x4C: jmp(); break;

        case 0x4D: eor(load_byte(addr_abs()),4); break;

        case 0x4A: lsr_a(); break;

        case 0x4E: lsr_mem(addr_abs(),6); break;

        case 0x51: eor(load_byte(addr_abs()),5); break;

        case 0x55: eor(load_byte(addr_zerox()),4); break;

        case 0x56: lsr_mem(addr_zerox(),6); break;

        case 0x58: cli(); break;

        case 0x59: eor(load_byte(addr_absy()),4); break;

        case 0x5D: eor(load_byte(addr_absx()),4); break;

        case 0x5E: lsr_mem(addr_absx(),7); break;

        case 0x60: rts(); break;

        case 0x61: adc(load_byte(addr_indx()),6); break;

        case 0x65: adc(load_byte(addr_zero()),3); break;

        case 0x66: ror_mem(addr_zero(),5); break;

        case 0x68: pla(); break;

        case 0x69: adc(fetch_op(),2); break;

        case 0x6A: ror_a(); break;

        case 0x6C: jmp_ind(); break;

        case 0x6D: adc(load_byte(addr_abs()),4); break;

        case 0x6E: ror_mem(addr_abs(),6); break;

        case 0x70: bvs(); break;

        case 0x71: adc(load_byte(addr_indy()),5);

        case 0x75: adc(load_byte(addr_zerox()),4); break;

        case 0x76: ror_mem(addr_zerox(),6); break;

        case 0x78: sei(); break;

        case 0x79: adc(load_byte(addr_absy()),4); break;

        case 0x7D: adc(load_byte(addr_absx()),4); break;

        case 0x7E: ror_mem(addr_absx(),7); break;

        case 0x81: sta(addr_indx(),6); break;

        case 0x84: sty(addr_zero(),3); break;

        case 0x85: sta(addr_zero(),3); break;

        case 0x86: stx(addr_zero(),3); break;

        case 0x88: dey(); break;

        case 0x8A: txa(); break;

        case 0x8C: sty(addr_abs(),4); break;

        case 0x8D: sta(addr_abs(),4); break;

        case 0x8E: stx(addr_abs(),4); break;

        case 0x90: bcc(); break;

        case 0x91: sta(addr_indy(),6); break;

        case 0x94: sty(addr_zerox(), 4); break;

        case 0x95: sta(addr_zerox(),4); break;

        case 0x96: stx(addr_zeroy(),4); break;

        case 0x98: tya(); break;

        case 0x99: sta(addr_absy(),5); break;

        case 0x9A: txs(); break;

        case 0x9D: sta(addr_absx(),5); break;

        case 0xA0: ldy(fetch_op(),2); break;

        case 0xA1: lda(load_byte(addr_indx()),6); break;

        case 0xA2: ldx(fetch_op(),2); break;

        case 0xA4: ldy(load_byte(addr_zero()),3); break;

        case 0xA5: lda(load_byte(addr_zero()),3); break;

        case 0xA6: ldx(load_byte(addr_zero()),3); break;

        case 0xA8: tay(); break;

        case 0xA9: lda(fetch_op(),2); break;

        case 0xAA: tax(); break;

        case 0xAC: ldy(load_byte(addr_abs()),4); break;

        case 0xAD: lda(load_byte(addr_abs()),4); break;

        case 0xAE: ldx(load_byte(addr_abs()),4); break;

        case 0xB0: bcs(); break;

        case 0xB1: lda(load_byte(addr_indy()),5); break;

        case 0xB4: ldy(load_byte(addr_zerox()),3); break;

        case 0xB5: lda(load_byte(addr_zerox()),3); break;

        case 0xB6: ldx(load_byte(addr_zeroy()),3); break;

        case 0xB8: clv(); break;

        case 0xB9: lda(load_byte(addr_zeroy()),4); break;

        case 0xBA: tsx(); break;

        case 0xBC: ldy(load_byte(addr_absx()),4); break;

        case 0xBD: lda(load_byte(addr_absx()),4); break;

        case 0xBE: ldx(load_byte(addr_absy()),4); break;

        case 0xC0: cpy(fetch_op(),2); break;

        case 0xC1: cmp(load_byte(addr_indx()),6); break;

        case 0xC4: cpy(load_byte(addr_zero()),3); break;

        case 0xC5: cmp(load_byte(addr_zero()),3); break;

        case 0xC6: dec(addr_zero(),5); break;

        case 0xC8: iny(); break;

        case 0xC9: cmp(fetch_op(),2); break;

        case 0xCA: dex(); break;

        case 0xCC: cpy(load_byte(addr_abs()),4); break;

        case 0xCD: cmp(load_byte(addr_abs()),4); break;

        case 0xCE: dec(addr_abs(),6); break;

        case 0xD0: bne(); break;

        case 0xD1: cmp(load_byte(addr_indy()),5); break;

        case 0xD5: cmp(load_byte(addr_zerox()),4); break;

        case 0xD6: dec(addr_zerox(),6); break;

        case 0xD8: cld(); break;

        case 0xD9: cmp(load_byte(addr_absy()),4); break;

        case 0xDD: cmp(load_byte(addr_absx()),4); break;

        case 0xDE: dec(addr_absx(),7); break;

        case 0xE0: cpx(fetch_op(),2); break;

        case 0xE1: sbc(load_byte(addr_indx()),6); break;

        case 0xE4: cpx(load_byte(addr_zero()),3); break;

        case 0xE5: sbc(load_byte(addr_zero()), 3); break;

        case 0xE6: inc(addr_zero(), 5); break;

        case 0xE8: inx(); break;

        case 0xE9: sbc(fetch_op(),2); break;

        case 0xEA: nop(); break;

        case 0xEC: cpx(load_byte(addr_abs()),4); break;

        case 0xED: sbc(load_byte(addr_abs()),4); break;

        case 0xEE: inc(addr_abs(),6); break;

        case 0xF0: beq(); break;

        case 0xF1: sbc(load_byte(addr_indy()),5); break;

        case 0xF5: sbc(load_byte(addr_zerox()),4); break;

        case 0xF6: inc(addr_zerox(),6); break;

        case 0xF8: sed(); break;

        case 0xF9: sbc(load_byte(addr_absy()),4); break;

        case 0xFD: sbc(load_byte(addr_absx()),4); break;

        case 0xFE: inc(addr_absx(),7); break;

        default: D("Unkown instruction: %X at %04x\n", insn,pc());
    }
    return retval;
}

uint8_t Cpu::load_byte(uint16_t addr) {
    return mem_->read_byte(addr);
}

void Cpu:push(uint8_t v) {
    uint16_t addr = Memory::kBaseAddrStack+sp_;
    mem_->write_byte(addr,v);
    sp_--;
}

uint8_t Cpu::pop() {
    uint16_t addr = ++sp_+Memory::kBaseAddrStack;
    return load_byte(addr);
}

uint8_t Cpu::fetch_op() {
    return load_byte(pc_++);
}

uint16_t Cpu::fetch_opw() {
    uint16_t retval = mem_->read_word(pc_);
    pc_+=2;
    return retval;
}

uint16_t Cpu::addr_zero() {
    uint16_t addr = fetch_op();
    return addr;
}

uint16_t Cpu::addr_zerox() {
    uint16_t addr = (fetch_op() + x()) & 0xff;
    return addr;
}

uint16_t Cpu::addr_zeroy() {
    uint16_t addr = (fetch_op() + y()) & 0xff;
    return addr;
}

uint16_t Cpu::addr_abs() {
    uint16_t addr = fetch_opw();
    return addr;
}

uint16_t Cpu::addr_absy() {
    uint16_t addr = fetch_opw() + y();
    return addr;
}

uint16_t Cpu::addr_absx() {
    uint16_t addr = fetch_opw() + x();
    return addr;
}

uint16_t Cpu::addr_indx() {
    uint16_t addr = mem_->read_word((addr_zero() + x()) & 0xff);
}

uint16_t Cpu::addr_indy() {
    uint16_t addr = mem_->read_word(addr_zero()) + y();
}







void Cpu::sta(uint16_t addr, uint8_t cycles) {
    mem_->write_byte(addr,a());
    tick(cycles);
}

void Cpu::stx(uint16_t addr, uint8_t cycles) {
    mem_->write_byte(addr,x());
    tick(cycles);
}

void Cpu::sty(uint16_t addr, uint8_t cycles) {
    mem_->write_byte(addr,y());
    tick(cycles);
}

void Cpu::txs() {
    sp(x());
    tick(2);
}


void Cpu::tsx() {
    x(sp());
    SET_ZF(x());
    SET_NF(x());
    tick(2);
}

void Cpu::lda(uint8_t v, uint8_t cycles) {
    a(v);
    SET_ZF(a());
    SET_NF(a());
    tick(cycles);
}

void Cpu::ldx(uint8_t v, uint8_t cycles) {
    x(v);
    SET_ZF(x());
    SET_NF(x());
    tick(cycles);
}

void Cpu::ldy(uint8_t v, uint8_t cycles) {
    y(v);
    SET_ZF(y());
    SET_NF(y());
    tick(cycles);
}

void Cpu::txa() {
    a(x());
    SET_ZF(a());
    SET_NF(a());
    tick(2);
}

void Cpu::tax() {
    x(a());
    SET_ZF(x());
    SET_NF(x());
    tick(2);
}

void Cpu::tay() {
    y(a());
    SET_ZF(y());
    SET_NF(y());
    tick(2);
}

void Cpu::tya() {
    a(y());
    SET_ZF(a());
    SET_NF(a());
    tick(2);
}

void Cpu::pha() {
    push(a());
    tick(3);
}

void Cpu::pla() {
    a(pop());
    SET_ZF(a());
    SET_NF(a());
    tick(4);
}







