/*
  PokeMini - Pokémon-Mini Emulator
  Copyright (C) 2009-2012  JustBurn

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// Note: Any write to MinxCPU.HL.B.I needs to be reflected into MinxCPU.N.B.I

#include "MinxCPU.h"

int MinxCPU_ExecCF(void)
{
	uint8_t I8A;
	uint16_t I16;

	// Read IR
	MinxCPU.IR = Fetch8();

	// Process instruction
	switch(MinxCPU.IR) {
		case 0x00: // ADD BA, BA
			MinxCPU.BA.W.L = ADD16(MinxCPU.BA.W.L, MinxCPU.BA.W.L);
			return 16;
		case 0x01: // ADD BA, HL
			MinxCPU.BA.W.L = ADD16(MinxCPU.BA.W.L, MinxCPU.HL.W.L);
			return 16;
		case 0x02: // ADD BA, IX
			MinxCPU.BA.W.L = ADD16(MinxCPU.BA.W.L, MinxCPU.X.W.L);
			return 16;
		case 0x03: // ADD BA, IY
			MinxCPU.BA.W.L = ADD16(MinxCPU.BA.W.L, MinxCPU.Y.W.L);
			return 16;

		case 0x04: // ADC BA, BA
			MinxCPU.BA.W.L = ADC16(MinxCPU.BA.W.L, MinxCPU.BA.W.L);
			return 16;
		case 0x05: // ADC BA, HL
			MinxCPU.BA.W.L = ADC16(MinxCPU.BA.W.L, MinxCPU.HL.W.L);
			return 16;
		case 0x06: // ADC BA, IX
			MinxCPU.BA.W.L = ADC16(MinxCPU.BA.W.L, MinxCPU.X.W.L);
			return 16;
		case 0x07: // ADC BA, IY
			MinxCPU.BA.W.L = ADC16(MinxCPU.BA.W.L, MinxCPU.Y.W.L);
			return 16;

		case 0x08: // SUB BA, BA
			MinxCPU.BA.W.L = SUB16(MinxCPU.BA.W.L, MinxCPU.BA.W.L);
			return 16;
		case 0x09: // SUB BA, HL
			MinxCPU.BA.W.L = SUB16(MinxCPU.BA.W.L, MinxCPU.HL.W.L);
			return 16;
		case 0x0A: // SUB BA, IX
			MinxCPU.BA.W.L = SUB16(MinxCPU.BA.W.L, MinxCPU.X.W.L);
			return 16;
		case 0x0B: // SUB BA, IY
			MinxCPU.BA.W.L = SUB16(MinxCPU.BA.W.L, MinxCPU.Y.W.L);
			return 16;

		case 0x0C: // SBC BA, BA
			MinxCPU.BA.W.L = SBC16(MinxCPU.BA.W.L, MinxCPU.BA.W.L);
			return 16;
		case 0x0D: // SBC BA, HL
			MinxCPU.BA.W.L = SBC16(MinxCPU.BA.W.L, MinxCPU.HL.W.L);
			return 16;
		case 0x0E: // SBC BA, IX
			MinxCPU.BA.W.L = SBC16(MinxCPU.BA.W.L, MinxCPU.X.W.L);
			return 16;
		case 0x0F: // SBC BA, IY
			MinxCPU.BA.W.L = SBC16(MinxCPU.BA.W.L, MinxCPU.Y.W.L);
			return 16;

		case 0x10: // *ADD BA, BA
			MinxCPU.BA.W.L = ADD16(MinxCPU.BA.W.L, MinxCPU.BA.W.L);
			return 16;
		case 0x11: // *ADD BA, HL
			MinxCPU.BA.W.L = ADD16(MinxCPU.BA.W.L, MinxCPU.HL.W.L);
			return 16;
		case 0x12: // *ADD BA, IX
			MinxCPU.BA.W.L = ADD16(MinxCPU.BA.W.L, MinxCPU.X.W.L);
			return 16;
		case 0x13: // *ADD BA, IY
			MinxCPU.BA.W.L = ADD16(MinxCPU.BA.W.L, MinxCPU.Y.W.L);
			return 16;

		case 0x14: // *ADC BA, BA
			MinxCPU.BA.W.L = ADC16(MinxCPU.BA.W.L, MinxCPU.BA.W.L);
			return 16;
		case 0x15: // *ADC BA, HL
			MinxCPU.BA.W.L = ADC16(MinxCPU.BA.W.L, MinxCPU.HL.W.L);
			return 16;
		case 0x16: // *ADC BA, IX
			MinxCPU.BA.W.L = ADC16(MinxCPU.BA.W.L, MinxCPU.X.W.L);
			return 16;
		case 0x17: // *ADC BA, IY
			MinxCPU.BA.W.L = ADC16(MinxCPU.BA.W.L, MinxCPU.Y.W.L);
			return 16;

		case 0x18: // CP BA, BA
			SUB16(MinxCPU.BA.W.L, MinxCPU.BA.W.L);
			return 16;
		case 0x19: // CP BA, HL
			SUB16(MinxCPU.BA.W.L, MinxCPU.HL.W.L);
			return 16;
		case 0x1A: // CP BA, IX
			SUB16(MinxCPU.BA.W.L, MinxCPU.X.W.L);
			return 16;
		case 0x1B: // CP BA, IY
			SUB16(MinxCPU.BA.W.L, MinxCPU.Y.W.L);
			return 16;

		case 0x1C: // *SBC BA, BA
			MinxCPU.BA.W.L = SBC16(MinxCPU.BA.W.L, MinxCPU.BA.W.L);
			return 16;
		case 0x1D: // *SBC BA, HL
			MinxCPU.BA.W.L = SBC16(MinxCPU.BA.W.L, MinxCPU.HL.W.L);
			return 16;
		case 0x1E: // *SBC BA, IX
			MinxCPU.BA.W.L = SBC16(MinxCPU.BA.W.L, MinxCPU.X.W.L);
			return 16;
		case 0x1F: // *SBC BA, IY
			MinxCPU.BA.W.L = SBC16(MinxCPU.BA.W.L, MinxCPU.Y.W.L);
			return 16;

		case 0x20: // ADD HL, BA
			MinxCPU.HL.W.L = ADD16(MinxCPU.HL.W.L, MinxCPU.BA.W.L);
			return 16;
		case 0x21: // ADD HL, HL
			MinxCPU.HL.W.L = ADD16(MinxCPU.HL.W.L, MinxCPU.HL.W.L);
			return 16;
		case 0x22: // ADD HL, IX
			MinxCPU.HL.W.L = ADD16(MinxCPU.HL.W.L, MinxCPU.X.W.L);
			return 16;
		case 0x23: // ADD HL, IY
			MinxCPU.HL.W.L = ADD16(MinxCPU.HL.W.L, MinxCPU.Y.W.L);
			return 16;

		case 0x24: // ADC HL, BA
			MinxCPU.HL.W.L = ADC16(MinxCPU.HL.W.L, MinxCPU.BA.W.L);
			return 16;
		case 0x25: // ADC HL, HL
			MinxCPU.HL.W.L = ADC16(MinxCPU.HL.W.L, MinxCPU.HL.W.L);
			return 16;
		case 0x26: // ADC HL, IX
			MinxCPU.HL.W.L = ADC16(MinxCPU.HL.W.L, MinxCPU.X.W.L);
			return 16;
		case 0x27: // ADC HL, IY
			MinxCPU.HL.W.L = ADC16(MinxCPU.HL.W.L, MinxCPU.Y.W.L);
			return 16;

		case 0x28: // SUB HL, BA
			MinxCPU.HL.W.L = SUB16(MinxCPU.HL.W.L, MinxCPU.BA.W.L);
			return 16;
		case 0x29: // SUB HL, HL
			MinxCPU.HL.W.L = SUB16(MinxCPU.HL.W.L, MinxCPU.HL.W.L);
			return 16;
		case 0x2A: // SUB HL, IX
			MinxCPU.HL.W.L = SUB16(MinxCPU.HL.W.L, MinxCPU.X.W.L);
			return 16;
		case 0x2B: // SUB HL, IY
			MinxCPU.HL.W.L = SUB16(MinxCPU.HL.W.L, MinxCPU.Y.W.L);
			return 16;

		case 0x2C: // SBC HL, BA
			MinxCPU.HL.W.L = SBC16(MinxCPU.HL.W.L, MinxCPU.BA.W.L);
			return 16;
		case 0x2D: // SBC HL, HL
			MinxCPU.HL.W.L = SBC16(MinxCPU.HL.W.L, MinxCPU.HL.W.L);
			return 16;
		case 0x2E: // SBC HL, IX
			MinxCPU.HL.W.L = SBC16(MinxCPU.HL.W.L, MinxCPU.X.W.L);
			return 16;
		case 0x2F: // SBC HL, IY
			MinxCPU.HL.W.L = SBC16(MinxCPU.HL.W.L, MinxCPU.Y.W.L);
			return 16;

		case 0x30: // *ADD HL, BA
			MinxCPU.HL.W.L = ADD16(MinxCPU.HL.W.L, MinxCPU.BA.W.L);
			return 16;
		case 0x31: // *ADD BA, HL
			MinxCPU.HL.W.L = ADD16(MinxCPU.HL.W.L, MinxCPU.HL.W.L);
			return 16;
		case 0x32: // *ADD BA, IX
			MinxCPU.HL.W.L = ADD16(MinxCPU.HL.W.L, MinxCPU.X.W.L);
			return 16;
		case 0x33: // *ADD BA, IY
			MinxCPU.HL.W.L = ADD16(MinxCPU.HL.W.L, MinxCPU.Y.W.L);
			return 16;

		case 0x34: // *ADC HL, BA
			MinxCPU.HL.W.L = ADC16(MinxCPU.HL.W.L, MinxCPU.BA.W.L);
			return 16;
		case 0x35: // *ADC HL, HL
			MinxCPU.HL.W.L = ADC16(MinxCPU.HL.W.L, MinxCPU.HL.W.L);
			return 16;
		case 0x36: // *ADC HL, IX
			MinxCPU.HL.W.L = ADC16(MinxCPU.HL.W.L, MinxCPU.X.W.L);
			return 16;
		case 0x37: // *ADC HL, IY
			MinxCPU.HL.W.L = ADC16(MinxCPU.HL.W.L, MinxCPU.Y.W.L);
			return 16;

		case 0x38: // CP HL, BA
			SUB16(MinxCPU.HL.W.L, MinxCPU.BA.W.L);
			return 16;
		case 0x39: // CP HL, HL
			SUB16(MinxCPU.HL.W.L, MinxCPU.HL.W.L);
			return 16;
		case 0x3A: // CP HL, IX
			SUB16(MinxCPU.HL.W.L, MinxCPU.X.W.L);
			return 16;
		case 0x3B: // CP HL, IY
			SUB16(MinxCPU.HL.W.L, MinxCPU.Y.W.L);
			return 16;

		case 0x3C: // *SBC BA, BA
			MinxCPU.BA.W.L = SBC16(MinxCPU.BA.W.L, MinxCPU.BA.W.L);
			return 16;
		case 0x3D: // *SBC BA, HL
			MinxCPU.BA.W.L = SBC16(MinxCPU.BA.W.L, MinxCPU.HL.W.L);
			return 16;
		case 0x3E: // *SBC BA, IX
			MinxCPU.BA.W.L = SBC16(MinxCPU.BA.W.L, MinxCPU.X.W.L);
			return 16;
		case 0x3F: // *SBC BA, IY
			MinxCPU.BA.W.L = SBC16(MinxCPU.BA.W.L, MinxCPU.Y.W.L);
			return 16;

		case 0x40: // ADD IX, BA
			MinxCPU.X.W.L = ADD16(MinxCPU.X.W.L, MinxCPU.BA.W.L);
			return 16;
		case 0x41: // ADD IX, HL
			MinxCPU.X.W.L = ADD16(MinxCPU.X.W.L, MinxCPU.HL.W.L);
			return 16;
		case 0x42: // ADD IY, BA
			MinxCPU.Y.W.L = ADD16(MinxCPU.Y.W.L, MinxCPU.BA.W.L);
			return 16;
		case 0x43: // ADD IY, HL
			MinxCPU.Y.W.L = ADD16(MinxCPU.Y.W.L, MinxCPU.HL.W.L);
			return 16;
		case 0x44: // ADD SP, BA
			MinxCPU.SP.W.L = ADD16(MinxCPU.SP.W.L, MinxCPU.BA.W.L);
			return 16;
		case 0x45: // ADD SP, HL
			MinxCPU.SP.W.L = ADD16(MinxCPU.SP.W.L, MinxCPU.HL.W.L);
			return 16;
		case 0x46: // CRASH
			MinxCPU_OnException(EXCEPTION_CRASH_INSTRUCTION, 0x46CF);
			return 16;
		case 0x47: // CRASH
			MinxCPU_OnException(EXCEPTION_CRASH_INSTRUCTION, 0x47CF);
			return 16;

		case 0x48: // SUB IX, BA
			MinxCPU.X.W.L = SUB16(MinxCPU.X.W.L, MinxCPU.BA.W.L);
			return 16;
		case 0x49: // SUB IX, HL
			MinxCPU.X.W.L = SUB16(MinxCPU.X.W.L, MinxCPU.HL.W.L);
			return 16;
		case 0x4A: // SUB IY, BA
			MinxCPU.Y.W.L = SUB16(MinxCPU.Y.W.L, MinxCPU.BA.W.L);
			return 16;
		case 0x4B: // SUB IY, HL
			MinxCPU.Y.W.L = SUB16(MinxCPU.Y.W.L, MinxCPU.HL.W.L);
			return 16;
		case 0x4C: // SUB SP, BA
			MinxCPU.SP.W.L = SUB16(MinxCPU.SP.W.L, MinxCPU.BA.W.L);
			return 16;
		case 0x4D: // SUB SP, HL
			MinxCPU.SP.W.L = SUB16(MinxCPU.SP.W.L, MinxCPU.HL.W.L);
			return 16;
		case 0x4E: // CRASH
			MinxCPU_OnException(EXCEPTION_CRASH_INSTRUCTION, 0x4ECF);
			return 16;
		case 0x4F: // CRASH
			MinxCPU_OnException(EXCEPTION_CRASH_INSTRUCTION, 0x4FCF);
			return 16;

		case 0x50: // *ADD IX, BA
			MinxCPU.X.W.L = ADD16(MinxCPU.X.W.L, MinxCPU.BA.W.L);
			return 16;
		case 0x51: // *ADD IX, HL
			MinxCPU.X.W.L = ADD16(MinxCPU.X.W.L, MinxCPU.HL.W.L);
			return 16;
		case 0x52: // *ADD IY, BA
			MinxCPU.Y.W.L = ADD16(MinxCPU.Y.W.L, MinxCPU.BA.W.L);
			return 16;
		case 0x53: // *ADD IY, HL
			MinxCPU.Y.W.L = ADD16(MinxCPU.Y.W.L, MinxCPU.HL.W.L);
			return 16;
		case 0x54: // *ADD SP, BA
			MinxCPU.SP.W.L = ADD16(MinxCPU.SP.W.L, MinxCPU.BA.W.L);
			return 16;
		case 0x55: // *ADD SP, HL
			MinxCPU.SP.W.L = ADD16(MinxCPU.SP.W.L, MinxCPU.HL.W.L);
			return 16;
		case 0x56: // CRASH
			MinxCPU_OnException(EXCEPTION_CRASH_INSTRUCTION, 0x56CF);
			return 16;
		case 0x57: // CRASH
			MinxCPU_OnException(EXCEPTION_CRASH_INSTRUCTION, 0x57CF);
			return 16;

		case 0x58: // *SUB IX, BA
			MinxCPU.X.W.L = SUB16(MinxCPU.X.W.L, MinxCPU.BA.W.L);
			return 16;
		case 0x59: // *SUB IX, HL
			MinxCPU.X.W.L = SUB16(MinxCPU.X.W.L, MinxCPU.HL.W.L);
			return 16;
		case 0x5A: // *SUB IY, BA
			MinxCPU.Y.W.L = SUB16(MinxCPU.Y.W.L, MinxCPU.BA.W.L);
			return 16;
		case 0x5B: // *SUB IY, HL
			MinxCPU.Y.W.L = SUB16(MinxCPU.Y.W.L, MinxCPU.HL.W.L);
			return 16;
		case 0x5C: // CP SP, BA
			SUB16(MinxCPU.SP.W.L, MinxCPU.BA.W.L);
			return 16;
		case 0x5D: // CP SP, HL
			SUB16(MinxCPU.SP.W.L, MinxCPU.HL.W.L);
			return 16;
		case 0x5E: // CRASH
			MinxCPU_OnException(EXCEPTION_CRASH_INSTRUCTION, 0x5ECF);
			return 16;
		case 0x5F: // CRASH
			MinxCPU_OnException(EXCEPTION_CRASH_INSTRUCTION, 0x5FCF);
			return 16;

		case 0x60: // ADC BA, #nnnn
			I16 = Fetch16();
			MinxCPU.BA.W.L = ADC16(MinxCPU.BA.W.L, I16);
			return 16;
		case 0x61: // ADC HL, #nnnn
			I16 = Fetch16();
			MinxCPU.HL.W.L = ADC16(MinxCPU.HL.W.L, I16);
			return 16;
		case 0x62: // SBC BA, #nnnn
			I16 = Fetch16();
			MinxCPU.BA.W.L = SBC16(MinxCPU.BA.W.L, I16);
			return 16;
		case 0x63: // SBC HL, #nnnn
			I16 = Fetch16();
			MinxCPU.HL.W.L = SBC16(MinxCPU.HL.W.L, I16);
			return 16;

		case 0x64: // UNSTABLE
			MinxCPU_OnException(EXCEPTION_UNSTABLE_INSTRUCTION, 0x64CF);
			return 16;
		case 0x65: // UNSTABLE
			MinxCPU_OnException(EXCEPTION_UNSTABLE_INSTRUCTION, 0x65CF);
			return 16;
		case 0x66: // UNSTABLE
			MinxCPU_OnException(EXCEPTION_UNSTABLE_INSTRUCTION, 0x66CF);
			return 16;
		case 0x67: // UNSTABLE
			MinxCPU_OnException(EXCEPTION_UNSTABLE_INSTRUCTION, 0x67CF);
			return 16;

		case 0x68: // ADD SP, #nnnn
			I16 = Fetch16();
			MinxCPU.SP.W.L = ADD16(MinxCPU.SP.W.L, I16);
			return 16;
		case 0x69: // UNSTABLE
			MinxCPU_OnException(EXCEPTION_UNSTABLE_INSTRUCTION, 0x69CF);
			return 16;

		case 0x6A: // SUB SP, #nnnn
			I16 = Fetch16();
			MinxCPU.SP.W.L = SUB16(MinxCPU.SP.W.L, I16);
			return 16;
		case 0x6B: // UNSTABLE
			MinxCPU_OnException(EXCEPTION_UNSTABLE_INSTRUCTION, 0x6BCF);
			return 16;

		case 0x6C: // CP SP, #nnnn
			I16 = Fetch16();
			SUB16(MinxCPU.SP.W.L, I16);
			return 16;
		case 0x6D: // UNSTABLE
			MinxCPU_OnException(EXCEPTION_UNSTABLE_INSTRUCTION, 0x6DCF);
			return 16;

		case 0x6E: // LD SP, #nnnn
			I16 = Fetch16();
			MinxCPU.SP.W.L = I16;
			return 16;
		case 0x6F: // UNSTABLE
			MinxCPU_OnException(EXCEPTION_UNSTABLE_INSTRUCTION, 0x6FCF);
			return 16;

		case 0x70: // LD BA, [SP+#ss]
			I8A = Fetch8();
			I16 = MinxCPU.SP.W.L + S8_TO_16(I8A);
			MinxCPU.BA.B.L = MinxCPU_OnRead(1, I16++);
			MinxCPU.BA.B.H = MinxCPU_OnRead(1, I16);
			return 24;
		case 0x71: // LD HL, [SP+#ss]
			I8A = Fetch8();
			I16 = MinxCPU.SP.W.L + S8_TO_16(I8A);
			MinxCPU.HL.B.L = MinxCPU_OnRead(1, I16++);
			MinxCPU.HL.B.H = MinxCPU_OnRead(1, I16);
			return 24;
		case 0x72: // LD IX, [SP+#ss]
			I8A = Fetch8();
			I16 = MinxCPU.SP.W.L + S8_TO_16(I8A);
			MinxCPU.X.B.L = MinxCPU_OnRead(1, I16++);
			MinxCPU.X.B.H = MinxCPU_OnRead(1, I16);
			return 24;
		case 0x73: // LD IY, [SP+#ss]
			I8A = Fetch8();
			I16 = MinxCPU.SP.W.L + S8_TO_16(I8A);
			MinxCPU.Y.B.L = MinxCPU_OnRead(1, I16++);
			MinxCPU.Y.B.H = MinxCPU_OnRead(1, I16);
			return 24;

		case 0x74: // LD [SP+#ss], BA
			I8A = Fetch8();
			I16 = MinxCPU.SP.W.L + S8_TO_16(I8A);
			MinxCPU_OnWrite(1, I16++, MinxCPU.BA.B.L);
			MinxCPU_OnWrite(1, I16, MinxCPU.BA.B.H);
			return 24;
		case 0x75: // LD [SP+#ss], HL
			I8A = Fetch8();
			I16 = MinxCPU.SP.W.L + S8_TO_16(I8A);
			MinxCPU_OnWrite(1, I16++, MinxCPU.HL.B.L);
			MinxCPU_OnWrite(1, I16, MinxCPU.HL.B.H);
			return 24;
		case 0x76: // LD [SP+#ss], IX
			I8A = Fetch8();
			I16 = MinxCPU.SP.W.L + S8_TO_16(I8A);
			MinxCPU_OnWrite(1, I16++, MinxCPU.X.B.L);
			MinxCPU_OnWrite(1, I16, MinxCPU.X.B.H);
			return 24;
		case 0x77: // LD [SP+#ss], IY
			I8A = Fetch8();
			I16 = MinxCPU.SP.W.L + S8_TO_16(I8A);
			MinxCPU_OnWrite(1, I16++, MinxCPU.Y.B.L);
			MinxCPU_OnWrite(1, I16, MinxCPU.Y.B.H);
			return 24;

		case 0x78: // LD SP, [#nnnn]
			I16 = Fetch16();
			MinxCPU.SP.B.L = MinxCPU_OnRead(1, (MinxCPU.HL.B.I << 16) | I16++);
			MinxCPU.SP.B.H = MinxCPU_OnRead(1, (MinxCPU.HL.B.I << 16) | I16);
			return 24;

		case 0x79: // ??? #nn
		case 0x7A: // ??? #nn
		case 0x7B: // ??? #nn
			return MinxCPU_ExecSPCF();

		case 0x7C: // LD [#nnnn], SP
			I16 = Fetch16();
			MinxCPU_OnWrite(1, (MinxCPU.HL.B.I << 16) | I16++, MinxCPU.SP.B.L);
			MinxCPU_OnWrite(1, (MinxCPU.HL.B.I << 16) | I16, MinxCPU.SP.B.H);
			return 24;

		case 0x7D: case 0x7E: case 0x7F: // ??? #nn
		case 0x80: case 0x81: case 0x82: case 0x83:
		case 0x84: case 0x85: case 0x86: case 0x87:
		case 0x88: case 0x89: case 0x8A: case 0x8B:
		case 0x8C: case 0x8D: case 0x8E: case 0x8F:
		case 0x90: case 0x91: case 0x92: case 0x93:
		case 0x94: case 0x95: case 0x96: case 0x97:
		case 0x98: case 0x99: case 0x9A: case 0x9B:
		case 0x9C: case 0x9D: case 0x9E: case 0x9F:
		case 0xA0: case 0xA1: case 0xA2: case 0xA3:
		case 0xA4: case 0xA5: case 0xA6: case 0xA7:
		case 0xA8: case 0xA9: case 0xAA: case 0xAB:
		case 0xAC: case 0xAD: case 0xAE: case 0xAF:
			return MinxCPU_ExecSPCF();

		case 0xB0: // PUSH A
			PUSH(MinxCPU.BA.B.L);
			return 12;
		case 0xB1: // PUSH B
			PUSH(MinxCPU.BA.B.H);
			return 12;
		case 0xB2: // PUSH L
			PUSH(MinxCPU.HL.B.L);
			return 12;
		case 0xB3: // PUSH H
			PUSH(MinxCPU.HL.B.H);
			return 12;

		case 0xB4: // POP A
			MinxCPU.BA.B.L = POP();
			return 12;
		case 0xB5: // POP B
			MinxCPU.BA.B.H = POP();
			return 12;
		case 0xB6: // POP L
			MinxCPU.HL.B.L = POP();
			return 12;
		case 0xB7: // POP H
			MinxCPU.HL.B.H = POP();
			return 12;
		case 0xB8: // PUSH ALL
			PUSH(MinxCPU.BA.B.H);
			PUSH(MinxCPU.BA.B.L);
			PUSH(MinxCPU.HL.B.H);
			PUSH(MinxCPU.HL.B.L);
			PUSH(MinxCPU.X.B.H);
			PUSH(MinxCPU.X.B.L);
			PUSH(MinxCPU.Y.B.H);
			PUSH(MinxCPU.Y.B.L);
			PUSH(MinxCPU.N.B.H);
			return 48;
		case 0xB9: // PUSH ALE
			PUSH(MinxCPU.BA.B.H);
			PUSH(MinxCPU.BA.B.L);
			PUSH(MinxCPU.HL.B.H);
			PUSH(MinxCPU.HL.B.L);
			PUSH(MinxCPU.X.B.H);
			PUSH(MinxCPU.X.B.L);
			PUSH(MinxCPU.Y.B.H);
			PUSH(MinxCPU.Y.B.L);
			PUSH(MinxCPU.N.B.H);
			PUSH(MinxCPU.HL.B.I);
			PUSH(MinxCPU.X.B.I);
			PUSH(MinxCPU.Y.B.I);
			return 60;

		case 0xBA: case 0xBB: // ??? #n
			return MinxCPU_ExecSPCF();

		case 0xBC: // POP ALL
			MinxCPU.N.B.H = POP();
			MinxCPU.Y.B.L = POP();
			MinxCPU.Y.B.H = POP();
			MinxCPU.X.B.L = POP();
			MinxCPU.X.B.H = POP();
			MinxCPU.HL.B.L = POP();
			MinxCPU.HL.B.H = POP();
			MinxCPU.BA.B.L = POP();
			MinxCPU.BA.B.H = POP();
			return 44;

		case 0xBD: // POP ALE
			MinxCPU.Y.B.I = POP();
			MinxCPU.X.B.I = POP();
			MinxCPU.HL.B.I = POP();
			MinxCPU.N.B.I = MinxCPU.HL.B.I;
			MinxCPU.N.B.H = POP();
			MinxCPU.Y.B.L = POP();
			MinxCPU.Y.B.H = POP();
			MinxCPU.X.B.L = POP();
			MinxCPU.X.B.H = POP();
			MinxCPU.HL.B.L = POP();
			MinxCPU.HL.B.H = POP();
			MinxCPU.BA.B.L = POP();
			MinxCPU.BA.B.H = POP();
			return 56;

		case 0xBE: case 0xBF: // ??? #n
			return MinxCPU_ExecSPCF();

		case 0xC0: // LD BA, [HL]
			I16 = MinxCPU.HL.W.L;
			MinxCPU.BA.B.L = MinxCPU_OnRead(1, (MinxCPU.HL.B.I << 16) | I16++);
			MinxCPU.BA.B.H = MinxCPU_OnRead(1, (MinxCPU.HL.B.I << 16) | I16);
			return 20;
		case 0xC1: // LD HL, [HL]
			I16 = MinxCPU.HL.W.L;
			MinxCPU.HL.B.L = MinxCPU_OnRead(1, (MinxCPU.HL.B.I << 16) | I16++);
			MinxCPU.HL.B.H = MinxCPU_OnRead(1, (MinxCPU.HL.B.I << 16) | I16);
			return 20;
		case 0xC2: // LD IX, [HL]
			I16 = MinxCPU.HL.W.L;
			MinxCPU.X.B.L = MinxCPU_OnRead(1, (MinxCPU.HL.B.I << 16) | I16++);
			MinxCPU.X.B.H = MinxCPU_OnRead(1, (MinxCPU.HL.B.I << 16) | I16);
			return 20;
		case 0xC3: // LD IY, [HL]
			I16 = MinxCPU.HL.W.L;
			MinxCPU.Y.B.L = MinxCPU_OnRead(1, (MinxCPU.HL.B.I << 16) | I16++);
			MinxCPU.Y.B.H = MinxCPU_OnRead(1, (MinxCPU.HL.B.I << 16) | I16);
			return 20;

		case 0xC4: // LD [HL], BA
			I16 = MinxCPU.HL.W.L;
			MinxCPU_OnWrite(1, (MinxCPU.HL.B.I << 16) | I16++, MinxCPU.BA.B.L);
			MinxCPU_OnWrite(1, (MinxCPU.HL.B.I << 16) | I16, MinxCPU.BA.B.H);
			return 20;
		case 0xC5: // LD [HL], HL
			I16 = MinxCPU.HL.W.L;
			MinxCPU_OnWrite(1, (MinxCPU.HL.B.I << 16) | I16++, MinxCPU.HL.B.L);
			MinxCPU_OnWrite(1, (MinxCPU.HL.B.I << 16) | I16, MinxCPU.HL.B.H);
			return 20;
		case 0xC6: // LD [HL], IX
			I16 = MinxCPU.HL.W.L;
			MinxCPU_OnWrite(1, (MinxCPU.HL.B.I << 16) | I16++, MinxCPU.X.B.L);
			MinxCPU_OnWrite(1, (MinxCPU.HL.B.I << 16) | I16, MinxCPU.X.B.H);
			return 20;
		case 0xC7: // LD [HL], IY
			I16 = MinxCPU.HL.W.L;
			MinxCPU_OnWrite(1, (MinxCPU.HL.B.I << 16) | I16++, MinxCPU.Y.B.L);
			MinxCPU_OnWrite(1, (MinxCPU.HL.B.I << 16) | I16, MinxCPU.Y.B.H);
			return 20;

		case 0xC8: case 0xC9: case 0xCA: case 0xCB: // LD B, V
		case 0xCC: case 0xCD: case 0xCE: case 0xCF:
			MinxCPU.BA.B.H = MinxCPU.PC.B.I;
			return 12;

		case 0xD0: // LD BA, [IX]
			I16 = MinxCPU.X.W.L;
			MinxCPU.BA.B.L = MinxCPU_OnRead(1, (MinxCPU.X.B.I << 16) | I16++);
			MinxCPU.BA.B.H = MinxCPU_OnRead(1, (MinxCPU.X.B.I << 16) | I16);
			return 20;
		case 0xD1: // LD HL, [IX]
			I16 = MinxCPU.X.W.L;
			MinxCPU.HL.B.L = MinxCPU_OnRead(1, (MinxCPU.X.B.I << 16) | I16++);
			MinxCPU.HL.B.H = MinxCPU_OnRead(1, (MinxCPU.X.B.I << 16) | I16);
			return 20;
		case 0xD2: // LD IX, [IX]
			I16 = MinxCPU.X.W.L;
			MinxCPU.X.B.L = MinxCPU_OnRead(1, (MinxCPU.X.B.I << 16) | I16++);
			MinxCPU.X.B.H = MinxCPU_OnRead(1, (MinxCPU.X.B.I << 16) | I16);
			return 20;
		case 0xD3: // LD IY, [IX]
			I16 = MinxCPU.X.W.L;
			MinxCPU.Y.B.L = MinxCPU_OnRead(1, (MinxCPU.X.B.I << 16) | I16++);
			MinxCPU.Y.B.H = MinxCPU_OnRead(1, (MinxCPU.X.B.I << 16) | I16);
			return 20;

		case 0xD4: // LD [IX], BA
			I16 = MinxCPU.X.W.L;
			MinxCPU_OnWrite(1, (MinxCPU.X.B.I << 16) | I16++, MinxCPU.BA.B.L);
			MinxCPU_OnWrite(1, (MinxCPU.X.B.I << 16) | I16, MinxCPU.BA.B.H);
			return 20;
		case 0xD5: // LD [IX], HL
			I16 = MinxCPU.X.W.L;
			MinxCPU_OnWrite(1, (MinxCPU.X.B.I << 16) | I16++, MinxCPU.HL.B.L);
			MinxCPU_OnWrite(1, (MinxCPU.X.B.I << 16) | I16, MinxCPU.HL.B.H);
			return 20;
		case 0xD6: // LD [IX], IX
			I16 = MinxCPU.X.W.L;
			MinxCPU_OnWrite(1, (MinxCPU.X.B.I << 16) | I16++, MinxCPU.X.B.L);
			MinxCPU_OnWrite(1, (MinxCPU.X.B.I << 16) | I16, MinxCPU.X.B.H);
			return 20;
		case 0xD7: // LD [IX], IY
			I16 = MinxCPU.X.W.L;
			MinxCPU_OnWrite(1, (MinxCPU.X.B.I << 16) | I16++, MinxCPU.Y.B.L);
			MinxCPU_OnWrite(1, (MinxCPU.X.B.I << 16) | I16, MinxCPU.Y.B.H);
			return 20;

		case 0xD8: // LD BA, [IY]
			I16 = MinxCPU.Y.W.L;
			MinxCPU.BA.B.L = MinxCPU_OnRead(1, (MinxCPU.Y.B.I << 16) | I16++);
			MinxCPU.BA.B.H = MinxCPU_OnRead(1, (MinxCPU.Y.B.I << 16) | I16);
			return 20;
		case 0xD9: // LD HL, [IY]
			I16 = MinxCPU.Y.W.L;
			MinxCPU.HL.B.L = MinxCPU_OnRead(1, (MinxCPU.Y.B.I << 16) | I16++);
			MinxCPU.HL.B.H = MinxCPU_OnRead(1, (MinxCPU.Y.B.I << 16) | I16);
			return 20;
		case 0xDA: // LD IX, [IY]
			I16 = MinxCPU.Y.W.L;
			MinxCPU.X.B.L = MinxCPU_OnRead(1, (MinxCPU.Y.B.I << 16) | I16++);
			MinxCPU.X.B.H = MinxCPU_OnRead(1, (MinxCPU.Y.B.I << 16) | I16);
			return 20;
		case 0xDB: // LD IY, [IY]
			I16 = MinxCPU.Y.W.L;
			MinxCPU.Y.B.L = MinxCPU_OnRead(1, (MinxCPU.Y.B.I << 16) | I16++);
			MinxCPU.Y.B.H = MinxCPU_OnRead(1, (MinxCPU.Y.B.I << 16) | I16);
			return 20;

		case 0xDC: // LD [IY], BA
			I16 = MinxCPU.Y.W.L;
			MinxCPU_OnWrite(1, (MinxCPU.Y.B.I << 16) | I16++, MinxCPU.BA.B.L);
			MinxCPU_OnWrite(1, (MinxCPU.Y.B.I << 16) | I16, MinxCPU.BA.B.H);
			return 20;
		case 0xDD: // LD [IY], HL
			I16 = MinxCPU.Y.W.L;
			MinxCPU_OnWrite(1, (MinxCPU.Y.B.I << 16) | I16++, MinxCPU.HL.B.L);
			MinxCPU_OnWrite(1, (MinxCPU.Y.B.I << 16) | I16, MinxCPU.HL.B.H);
			return 20;
		case 0xDE: // LD [IY], IX
			I16 = MinxCPU.Y.W.L;
			MinxCPU_OnWrite(1, (MinxCPU.Y.B.I << 16) | I16++, MinxCPU.X.B.L);
			MinxCPU_OnWrite(1, (MinxCPU.Y.B.I << 16) | I16, MinxCPU.X.B.H);
			return 20;
		case 0xDF: // LD [IY], IY
			I16 = MinxCPU.Y.W.L;
			MinxCPU_OnWrite(1, (MinxCPU.Y.B.I << 16) | I16++, MinxCPU.Y.B.L);
			MinxCPU_OnWrite(1, (MinxCPU.Y.B.I << 16) | I16, MinxCPU.Y.B.H);
			return 20;

		case 0xE0: // LD BA, BA
			return 8;
		case 0xE1: // LD BA, HL
			MinxCPU.BA.W.L = MinxCPU.HL.W.L;
			return 8;
		case 0xE2: // LD BA, IX
			MinxCPU.BA.W.L = MinxCPU.X.W.L;
			return 8;
		case 0xE3: // LD BA, IY
			MinxCPU.BA.W.L = MinxCPU.Y.W.L;
			return 8;

		case 0xE4: // LD HL, BA
			MinxCPU.HL.W.L = MinxCPU.BA.W.L;
			return 8;
		case 0xE5: // LD HL, HL
			return 8;
		case 0xE6: // LD HL, IX
			MinxCPU.HL.W.L = MinxCPU.X.W.L;
			return 8;
		case 0xE7: // LD HL, IY
			MinxCPU.HL.W.L = MinxCPU.Y.W.L;
			return 8;

		case 0xE8: // LD IX, BA
			MinxCPU.X.W.L = MinxCPU.BA.W.L;
			return 8;
		case 0xE9: // LD IX, HL
			MinxCPU.X.W.L = MinxCPU.HL.W.L;
			return 8;
		case 0xEA: // LD IX, IX
			return 8;
		case 0xEB: // LD IX, IY
			MinxCPU.X.W.L = MinxCPU.Y.W.L;
			return 8;

		case 0xEC: // LD IY, BA
			MinxCPU.Y.W.L = MinxCPU.BA.W.L;
			return 8;
		case 0xED: // LD IY, HL
			MinxCPU.Y.W.L = MinxCPU.HL.W.L;
			return 8;
		case 0xEE: // LD IY, IX
			MinxCPU.Y.W.L = MinxCPU.X.W.L;
			return 8;
		case 0xEF: // LD IY, IY
			return 8;

		case 0xF0: // LD SP, BA
			MinxCPU.SP.W.L = MinxCPU.BA.W.L;
			return 8;
		case 0xF1: // LD SP, HL
			MinxCPU.SP.W.L = MinxCPU.HL.W.L;
			return 8;
		case 0xF2: // LD SP, IX
			MinxCPU.SP.W.L = MinxCPU.X.W.L;
			return 8;
		case 0xF3: // LD SP, IY
			MinxCPU.SP.W.L = MinxCPU.Y.W.L;
			return 8;

		case 0xF4: // LD HL, SP
			MinxCPU.HL.W.L = MinxCPU.SP.W.L;
			return 8;
		case 0xF5: // LD HL, PC
			MinxCPU.HL.W.L = MinxCPU.PC.W.L;
			return 8;
		case 0xF6: // ??? IX
			MinxCPU.X.B.H = MinxCPU.PC.B.I;
			return 12;
		case 0xF7: // ??? IY
			MinxCPU.Y.B.H = MinxCPU.PC.B.I;
			return 12;

		case 0xF8: // LD BA, SP
			MinxCPU.BA.W.L = MinxCPU.SP.W.L;
			return 8;
		case 0xF9: // LD BA, PC
			MinxCPU.BA.W.L = MinxCPU.PC.W.L;
			return 8;

		case 0xFA: // LD IX, SP
			MinxCPU.X.W.L = MinxCPU.SP.W.L;
			return 8;

		case 0xFB: // NOTHING
		case 0xFC: // NOTHING
			return 12;
		case 0xFD: // LD A, E
			MinxCPU.BA.B.L = MinxCPU.E;
			return 12;

		case 0xFE: // LD IY, SP
			MinxCPU.Y.W.L = MinxCPU.SP.W.L;
			return 8;

		case 0xFF: // NOTHING
			return 64;

		default:
			MinxCPU_OnException(EXCEPTION_UNKNOWN_INSTRUCTION, (MinxCPU.IR << 8) + 0xCF);
			return 4;
	}
}
