//
// Created by Kyle on 7/10/21.
//

#include "c64.h"
#include "util.h"

C64::C64() {
    cpu_ = new Cpu();
    mem_ = new Memory();
    cia1_ = new Cia1();
    cia2_ = new Cia2();
    vic_ = new Vic();
    sid_ = new Sid();
    io_ = new IO();

    cpu_->memory(mem_);
    cpu_->reset();

    vic_->memory(mem_);
    vic_->cpu(cpu_);
    vic_->io(io);

    cia1_->cpu(cpu_);
    cia1_->io(io_);

    cia2_->cpu(cpu_);

    io_->cpu(cpu_);

    mem_->vic(vic_);
    mem_->cia1(cia1_);
    mem_->cia2(cia2_);

#ifdef DEBUGGER_SUPPORT
    debugger_ = new Debugger();
    debugger_->memory(mem_);
    debugger_->cpu(cpu_);
#endif
}

C64::~C64() {
    delete cpu_;
    delete mem_;
    delete cia1_;
    delete cia2_;
    delete vic_;
    delete sid_;
    delete io_;

#ifdef DEBUGGER_SUPPORT
    delete debugger_;
#endif
}

void C64::start() {
    while (true) {
#ifdef DEBUGGER_SUPPORT
        if(!debugger_->emulate())
            break;
#endif
        if(!cia1_->emulate())
            break;
        if(!cia2_->emulate())
            break;
        if(!cpu_->emulate())
            break;
        if(!vic_->emulate())
            break;
        if(!io_->emulate())
            break;
        if(callback_ && !callback_())
            break;
    }
}

void C64::emscripten_loop() {
    unsigned int frame = vic_->frames();
    while(frame == vic_->frames()) {
        cia1_->emulate();
        cia2_->emulate();
        cpu_->emulate();
        vic_->emulate();
        io_->emulate();
        if(callback_) callback_();
    }
}

void C64::test_cpu() {
    uint16_t pc=0;
    mem_->write_byte(Memory::kAddrMemoryLayout, 0);

    mem_->load_ram("tests/6502_funcional_test.bin", 0x400);

    cpu_->pc(0x400);

    while(true) {
        if(pc == cpu_->pc()) {
            D("Infinite loop at %x\n",pc);
            break;
        } else if(cpu_->pc() == 0x3463) {
            D("test passed!\n");
            break;
        }
        pc = cpu_->pc();
        if(!cpu_->emulate())
            break;
    }
}