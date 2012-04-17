/**
 * Copyright (c) 2012 Anup Patel.
 * All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * @file cpu_defines.h
 * @author Anup Patel (anup@brainfault.org)
 * @brief common macros & defines for shared by all C & Assembly code
 */
#ifndef __CPU_DEFINES_H__
#define __CPU_DEFINES_H__

/* Maximum allowed VTLB entries */
#define CPU_VCPU_VTLB_LINE_MASK				0x00000000
#define CPU_VCPU_VTLB_LINE_SHIFT			0
#define CPU_VCPU_VTLB_LINE_COUNT			1
#define CPU_VCPU_VTLB_LINE_ENTRY_COUNT			128
#define CPU_VCPU_VTLB_ENTRY_COUNT			128

/* Coprocessor related macros & defines */
#define CPU_COPROC_COUNT				16

/* GPR related macros & defines */
#define CPU_GPR_COUNT 					13
#define CPU_FIQ_GPR_COUNT 				5

/* Interrupt or Exception related macros & defines */
#define CPU_IRQ_NR					8
#define CPU_IRQ_LOWVEC_BASE				0x00000000
#define CPU_IRQ_HIGHVEC_BASE				0xFFFF0000
#define CPU_RESET_IRQ					0
#define CPU_UNDEF_INST_IRQ				1
#define CPU_SOFT_IRQ					2
#define CPU_PREFETCH_ABORT_IRQ				3
#define CPU_DATA_ABORT_IRQ				4
#define CPU_HYP_TRAP_IRQ				5
#define CPU_EXTERNAL_IRQ				6
#define CPU_EXTERNAL_FIQ				7

/* CPSR related macors & defines */
#define CPSR_MODE_MASK					0x0000001f
#define CPSR_MODE_USER					0x00000010
#define CPSR_MODE_FIQ					0x00000011
#define CPSR_MODE_IRQ					0x00000012
#define CPSR_MODE_SUPERVISOR				0x00000013
#define CPSR_MODE_MONITOR				0x00000016
#define CPSR_MODE_ABORT					0x00000017
#define CPSR_MODE_HYPERVISOR				0x0000001a
#define CPSR_MODE_UNDEFINED				0x0000001b
#define CPSR_MODE_SYSTEM				0x0000001f
#define CPSR_THUMB_ENABLED				(1 << 5)
#define CPSR_FIQ_DISABLED				(1 << 6)
#define CPSR_IRQ_DISABLED				(1 << 7)
#define CPSR_ASYNC_ABORT_DISABLED			(1 << 8)
#define CPSR_BE_ENABLED					(1 << 9)
#define CPSR_IT2_MASK					0x0000FC00
#define CPSR_IT2_SHIFT					10
#define CPSR_GE_MASK					0x000F0000
#define CPSR_GE_SHIFT					16
#define CPSR_JAZZLE_ENABLED				(1 << 24)
#define CPSR_IT1_MASK					0x06000000
#define CPSR_IT1_SHIFT					25
#define CPSR_CUMMULATE_MASK				(1 << 27)
#define CPSR_CUMMULATE_SHIFT				27
#define CPSR_OVERFLOW_MASK				(1 << 28)
#define CPSR_OVERFLOW_SHIFT				28
#define CPSR_CARRY_MASK					(1 << 29)
#define CPSR_CARRY_SHIFT				29
#define CPSR_ZERO_MASK					(1 << 30)
#define CPSR_ZERO_SHIFT					30
#define CPSR_NEGATIVE_MASK				(1 << 31)
#define CPSR_NEGATIVE_SHIFT				31

#define CPSR_NZCV_MASK					(CPSR_NEGATIVE_MASK |\
							CPSR_ZERO_MASK |\
							CPSR_CARRY_MASK |\
							CPSR_OVERFLOW_MASK)
#define CPSR_IT_MASK					(CPSR_IT2_MASK |\
							CPSR_IT1_MASK)
#define CPSR_USERBITS_MASK				(CPSR_NZCV_MASK |\
							CPSR_CUMMULATE_MASK |\
							CPSR_GE_MASK |\
							CPSR_IT_MASK |\
							CPSR_THUMB_ENABLED)
#define CPSR_PRIVBITS_MASK				(~CPSR_USERBITS_MASK)
#define CPSR_ALLBITS_MASK				0xFFFFFFFF

/* SCTLR related macros & defines */
#define SCTLR_TE_MASK					0x40000000
#define SCTLR_AFE_MASK					0x20000000
#define SCTLR_TRE_MASK					0x10000000
#define SCTLR_NFI_MASK					0x08000000
#define SCTLR_EE_MASK					0x02000000
#define SCTLR_VE_MASK					0x01000000
#define SCTLR_U_MASK					0x00400000
#define SCTLR_FI_MASK					0x00200000
#define SCTLR_HA_MASK					0x00020000
#define SCTLR_RR_MASK					0x00004000
#define SCTLR_V_MASK					0x00002000
#define SCTLR_I_MASK					0x00001000
#define SCTLR_Z_MASK					0x00000800
#define SCTLR_SW_MASK					0x00000400
#define SCTLR_B_MASK					0x00000080
#define SCTLR_C_MASK					0x00000004
#define SCTLR_A_MASK					0x00000002
#define SCTLR_M_MASK					0x00000001

/* HCR */
#define HCR_INITVAL					0x00000000
#define HCR_TGE_MASK					0x08000000
#define HCR_TGE_SHIFT					27
#define HCR_TVM_MASK					0x04000000
#define HCR_TVM_SHIFT					26
#define HCR_TTLB_MASK					0x02000000
#define HCR_TTLB_SHIFT					25
#define HCR_TPU_MASK					0x01000000
#define HCR_TPU_SHIFT					24
#define HCR_TPC_MASK					0x00800000
#define HCR_TPC_SHIFT					23
#define HCR_TSW_MASK					0x00400000
#define HCR_TSW_SHIFT					22
#define HCR_TAC_MASK					0x00200000
#define HCR_TAC_SHIFT					21
#define HCR_TIDCP_MASK					0x00100000
#define HCR_TIDCP_SHIFT					20
#define HCR_TSC_MASK					0x00080000
#define HCR_TSC_SHIFT					19
#define HCR_TID3_MASK					0x00040000
#define HCR_TID3_SHIFT					18
#define HCR_TID2_MASK					0x00020000
#define HCR_TID2_SHIFT					17
#define HCR_TID1_MASK					0x00010000
#define HCR_TID1_SHIFT					16
#define HCR_TID0_MASK					0x00008000
#define HCR_TID0_SHIFT					15
#define HCR_TWE_MASK					0x00004000
#define HCR_TWE_SHIFT					14
#define HCR_TWI_MASK					0x00002000
#define HCR_TWI_SHIFT					13
#define HCR_DC_MASK					0x00001000
#define HCR_DC_SHIFT					12
#define HCR_BSU_MASK					0x00000C00
#define HCR_BSU_SHIFT					10
#define HCR_FB_MASK					0x00000200
#define HCR_FB_SHIFT					9
#define HCR_VA_MASK					0x00000100
#define HCR_VA_SHIFT					8
#define HCR_VI_MASK					0x00000080
#define HCR_VI_SHIFT					7
#define HCR_VF_MASK					0x00000040
#define HCR_VF_SHIFT					6
#define HCR_AMO_MASK					0x00000020
#define HCR_AMO_SHIFT					5
#define HCR_IMO_MASK					0x00000010
#define HCR_IMO_SHIFT					4
#define HCR_FMO_MASK					0x00000008
#define HCR_FMO_SHIFT					3
#define HCR_PTW_MASK					0x00000004
#define HCR_PTW_SHIFT					2
#define HCR_SWIO_MASK					0x00000002
#define HCR_SWIO_SHIFT					1
#define HCR_VM_MASK					0x00000001
#define HCR_VM_SHIFT					0

/* HCPTR */
#define HCPTR_INITVAL					0x00000000
#define HCPTR_TCPAC_MASK				0x80000000
#define HCPTR_TCPAC_SHIFT				31
#define HCPTR_TTA_MASK					0x00100000
#define HCPTR_TTA_SHIFT					20
#define HCPTR_TASE_MASK					0x00008000
#define HCPTR_TASE_SHIFT				15
#define HCPTR_TCP_MASK					0x00003FFF
#define HCPTR_TCP_SHIFT					0
#define HCPTR_TCP13_MASK				0x00002000
#define HCPTR_TCP13_SHIFT				13
#define HCPTR_TCP12_MASK				0x00001000
#define HCPTR_TCP12_SHIFT				12
#define HCPTR_TCP11_MASK				0x00000800
#define HCPTR_TCP11_SHIFT				11
#define HCPTR_TCP10_MASK				0x00000400
#define HCPTR_TCP10_SHIFT				10
#define HCPTR_TCP9_MASK					0x00000200
#define HCPTR_TCP9_SHIFT				9
#define HCPTR_TCP8_MASK					0x00000100
#define HCPTR_TCP8_SHIFT				8
#define HCPTR_TCP7_MASK					0x00000080
#define HCPTR_TCP7_SHIFT				7
#define HCPTR_TCP6_MASK					0x00000040
#define HCPTR_TCP6_SHIFT				6
#define HCPTR_TCP5_MASK					0x00000020
#define HCPTR_TCP5_SHIFT				5
#define HCPTR_TCP4_MASK					0x00000010
#define HCPTR_TCP4_SHIFT				4
#define HCPTR_TCP3_MASK					0x00000008
#define HCPTR_TCP3_SHIFT				3
#define HCPTR_TCP2_MASK					0x00000004
#define HCPTR_TCP2_SHIFT				2
#define HCPTR_TCP1_MASK					0x00000002
#define HCPTR_TCP1_SHIFT				1
#define HCPTR_TCP0_MASK					0x00000001
#define HCPTR_TCP0_SHIFT				0

/* HSTR */
#define HSTR_INITVAL					0x00000000
#define HSTR_TJDBX_MASK					0x00020000
#define HSTR_TJDBX_SHIFT				17
#define HSTR_TTEE_MASK					0x00010000
#define HSTR_TTEE_SHIFT					16
#define HSTR_T_MASK					0x0000BFEF
#define HSTR_T_SHIFT					0
#define HSTR_T15_MASK					0x00008000
#define HSTR_T15_SHIFT					15
#define HSTR_T13_MASK					0x00002000
#define HSTR_T13_SHIFT					13
#define HSTR_T12_MASK					0x00001000
#define HSTR_T12_SHIFT					12
#define HSTR_T11_MASK					0x00000800
#define HSTR_T11_SHIFT					11
#define HSTR_T10_MASK					0x00000400
#define HSTR_T10_SHIFT					10
#define HSTR_T9_MASK					0x00000200
#define HSTR_T9_SHIFT					9
#define HSTR_T8_MASK					0x00000100
#define HSTR_T8_SHIFT					8
#define HSTR_T7_MASK					0x00000080
#define HSTR_T7_SHIFT					7
#define HSTR_T6_MASK					0x00000040
#define HSTR_T6_SHIFT					6
#define HSTR_T5_MASK					0x00000020
#define HSTR_T5_SHIFT					5
#define HSTR_T3_MASK					0x00000008
#define HSTR_T3_SHIFT					3
#define HSTR_T2_MASK					0x00000004
#define HSTR_T2_SHIFT					2
#define HSTR_T1_MASK					0x00000002
#define HSTR_T1_SHIFT					1
#define HSTR_T0_MASK					0x00000001
#define HSTR_T0_SHIFT					0

/* HPFAR */
#define HPFAR_INITVAL					0x00000000
#define HPFAR_FIPA_MASK					0xFFFFFFF0
#define HPFAR_FIPA_SHIFT				4
#define HPFAR_FIPA_CORRECTION_SHIFT			12

/* HSR */
#define HSR_INITVAL					0x00000000
#define HSR_EC_MASK					0xFC000000
#define HSR_EC_SHIFT					26
#define HSR_IL_MASK					0x02000000
#define HSR_IL_SHIFT					25
#define HSR_ISS_MASK					0x01FFFFFF
#define HSR_ISS_SHIFT					0
#define HSR_EC_UNKNOWN					0x00
#define HSR_EC_TRAP_WFI_WFE				0x01
#define HSR_EC_TRAP_MCR_MRC_CP15			0x03
#define HSR_EC_TRAP_MCRR_MRRC_CP15			0x04
#define HSR_EC_TRAP_MCR_MRC_CP14			0x05
#define HSR_EC_TRAP_LDC_STC_CP14			0x06
#define HSR_EC_TRAP_CP0_TO_CP13				0x07
#define HSR_EC_TRAP_VMRS				0x08
#define HSR_EC_TRAP_JAZELLE				0x09
#define HSR_EC_TRAP_BXJ					0x0A
#define HSR_EC_TRAP_MRRC_CP14				0x0C
#define HSR_EC_TRAP_SVC					0x11
#define HSR_EC_TRAP_HVC					0x12
#define HSR_EC_TRAP_SMC					0x13
#define HSR_EC_TRAP_STAGE2_INST_ABORT			0x20
#define HSR_EC_TRAP_STAGE1_INST_ABORT			0x21
#define HSR_EC_TRAP_STAGE2_DATA_ABORT			0x24
#define HSR_EC_TRAP_STAGE1_DATA_ABORT			0x25

/* HTTBR */
#define HTTBR_INITVAL					0x0000000000000000ULL
#define HTTBR_BADDR_MASK				0x000000FFFFFFF000ULL
#define HTTBR_BADDR_SHIFT				12

/* HTCR */
#define HTCR_INITVAL					0x80800000
#define HTCR_IMP_MASK					0x40000000
#define HTCR_IMP_SHIFT					30
#define HTCR_SH0_MASK					0x00003000
#define HTCR_SH0_SHIFT					12
#define HTCR_ORGN0_MASK					0x00000C00
#define HTCR_ORGN0_SHIFT				10
#define HTCR_IRGN0_MASK					0x00000300
#define HTCR_IRGN0_SHIFT				8
#define HTCR_T0SZ_MASK					0x00000003
#define HTCR_T0SZ_SHIFT					0

/* VTTBR */
#define VTTBR_INITVAL					0x0000000000000000ULL
#define VTTBR_VMID_MASK					0x00FF000000000000ULL
#define VTTBR_VMID_SHIFT				48
#define VTTBR_BADDR_MASK				0x000000FFFFFFF000ULL
#define VTTBR_BADDR_SHIFT				12

/* VTCR */
#define VTCR_INITVAL					0x80000000
#define VTCR_SH0_MASK					0x00003000
#define VTCR_SH0_SHIFT					12
#define VTCR_ORGN0_MASK					0x00000C00
#define VTCR_ORGN0_SHIFT				10
#define VTCR_IRGN0_MASK					0x00000300
#define VTCR_IRGN0_SHIFT				8
#define VTCR_SL0_MASK					0x000000C0
#define VTCR_SL0_SHIFT					6
#define VTCR_S_MASK					0x00000010
#define VTCR_S_SHIFT					4
#define VTCR_T0SZ_MASK					0x00000003
#define VTCR_T0SZ_SHIFT					0

/* TTBL Generic */
#define TTBL_INITIAL_TABLE_COUNT			8
#define TTBL_TABLE_SIZE					0x00001000
#define TTBL_TABLE_SIZE_SHIFT				12
#define TTBL_TABLE_ENTCNT				512
#define TTBL_TABLE_ENTSZ				8
#define TTBL_STAGE1					1
#define TTBL_STAGE2					2
#define TTBL_FIRST_LEVEL				1
#define TTBL_LEVEL1					1
#define TTBL_LEVEL2					2
#define TTBL_LEVEL3					3
#define TTBL_LAST_LEVEL					3
/* L1 index Bit[39:30] */
#define TTBL_L1_INDEX_MASK				0x000000FFC0000000ULL
#define TTBL_L1_INDEX_SHIFT				30
#define TTBL_L1_BLOCK_SIZE				0x0000000040000000ULL
#define TTBL_L1_MAP_MASK				(~(TTBL_L1_BLOCK_SIZE - 1))
/* L2 index Bit[29:21] */
#define TTBL_L2_INDEX_MASK				0x000000003FE00000ULL
#define TTBL_L2_INDEX_SHIFT				21
#define TTBL_L2_BLOCK_SIZE				0x0000000000200000ULL
#define TTBL_L2_MAP_MASK				(~(TTBL_L2_BLOCK_SIZE - 1))
/* L3 index Bit[20:12] */
#define TTBL_L3_INDEX_MASK				0x00000000001FF000ULL
#define TTBL_L3_INDEX_SHIFT				12
#define TTBL_L3_BLOCK_SIZE				0x0000000000001000ULL
#define TTBL_L3_MAP_MASK				(~(TTBL_L3_BLOCK_SIZE - 1))
#define TTBL_UPPER_MASK					0xFFF0000000000000ULL
#define TTBL_UPPER_SHIFT				52
#define TTBL_OUTADDR_MASK				0x000000FFFFFFF000ULL
#define TTBL_OUTADDR_SHIFT				12
#define TTBL_AP_SRW_U					0x0
#define TTBL_AP_S_URW					0x1
#define TTBL_AP_SR_U					0x2
#define TTBL_AP_S_UR					0x3
#define TTBL_LOWER_MASK					0x0000000000000FFCULL
#define TTBL_LOWER_SHIFT				2
#define TTBL_TABLE_MASK					0x0000000000000002ULL
#define TTBL_TABLE_SHIFT				1
#define TTBL_VALID_MASK					0x0000000000000001ULL
#define TTBL_VALID_SHIFT				0

/* TTBL Stage1 Table Attributes */
#define TTBL_STAGE1_TABLE_NS_MASK			0x8000000000000000ULL
#define TTBL_STAGE1_TABLE_NS_SHIFT			63
#define TTBL_STAGE1_TABLE_AP_MASK			0x6000000000000000ULL
#define TTBL_STAGE1_TABLE_AP_SHIFT			61
#define TTBL_STAGE1_TABLE_XN_MASK			0x1000000000000000ULL
#define TTBL_STAGE1_TABLE_XN_SHIFT			60
#define TTBL_STAGE1_TABLE_PXN_MASK			0x0800000000000000ULL
#define TTBL_STAGE1_TABLE_PXN_SHIFT			59

/* TTBL Stage1 Block Upper Attributes */
#define TTBL_STAGE1_UPPER_XN_MASK			0x0040000000000000ULL
#define TTBL_STAGE1_UPPER_XN_SHIFT			54
#define TTBL_STAGE1_UPPER_PXN_MASK			0x0020000000000000ULL
#define TTBL_STAGE1_UPPER_PXN_SHIFT			53
#define TTBL_STAGE1_UPPER_CONT_MASK			0x0010000000000000ULL
#define TTBL_STAGE1_UPPER_CONT_SHIFT			52

/* TTBL Stage1 Block Lower Attributes */
#define TTBL_STAGE1_LOWER_NG_MASK			0x0000000000000800ULL
#define TTBL_STAGE1_LOWER_NG_SHIFT			11
#define TTBL_STAGE1_LOWER_AF_MASK			0x0000000000000400ULL
#define TTBL_STAGE1_LOWER_AF_SHIFT			10
#define TTBL_STAGE1_LOWER_SH_MASK			0x0000000000000300ULL
#define TTBL_STAGE1_LOWER_SH_SHIFT			8
#define TTBL_STAGE1_LOWER_AP_MASK			0x00000000000000C0ULL
#define TTBL_STAGE1_LOWER_AP_SHIFT			6
#define TTBL_STAGE1_LOWER_NS_MASK			0x0000000000000020ULL
#define TTBL_STAGE1_LOWER_NS_SHIFT			5
#define TTBL_STAGE1_LOWER_AINDEX_MASK			0x000000000000001CULL
#define TTBL_STAGE1_LOWER_AINDEX_SHIFT			2

/* TTBL Stage2 Block Upper Attributes */
#define TTBL_STAGE2_UPPER_MASK				0xFFF0000000000000ULL
#define TTBL_STAGE2_UPPER_SHIFT				52
#define TTBL_STAGE2_UPPER_XN_MASK			0x0040000000000000ULL
#define TTBL_STAGE2_UPPER_XN_SHIFT			54
#define TTBL_STAGE2_UPPER_CONT_MASK			0x0010000000000000ULL
#define TTBL_STAGE2_UPPER_CONT_SHIFT			52

/* TTBL Stage2 Block Lower Attributes */
#define TTBL_STAGE2_LOWER_MASK				0x0000000000000FFCULL
#define TTBL_STAGE2_LOWER_SHIFT				2
#define TTBL_STAGE2_LOWER_AF_MASK			0x0000000000000400ULL
#define TTBL_STAGE2_LOWER_AF_SHIFT			10
#define TTBL_STAGE2_LOWER_SH_MASK			0x0000000000000300ULL
#define TTBL_STAGE2_LOWER_SH_SHIFT			8
#define TTBL_STAGE2_LOWER_HAP_MASK			0x00000000000000C0ULL
#define TTBL_STAGE2_LOWER_HAP_SHIFT			6
#define TTBL_STAGE2_LOWER_MEMATTR_MASK			0x000000000000003CULL
#define TTBL_STAGE2_LOWER_MEMATTR_SHIFT			2

/* VPIDR */
#define VPIDR_INITVAL					0x00000000

/* VMPIDR */
#define VMPIDR_INITVAL					0x00000000

/* DBGVIDSR */
#define DBGVIDSR_INITVAL				0x00000000
#define DBGVIDSR_NS_MASK				0x80000000
#define DBGVIDSR_NS_SHIFT				31
#define DBGVIDSR_H_MASK					0x40000000
#define DBGVIDSR_H_SHIFT				30
#define DBGVIDSR_VMID_MASK				0x000000FF
#define DBGVIDSR_VMID_SHIFT				0

/* HSCTLR */
#define HSCTLR_INITVAL					0x30C50878
#define HSCTLR_TE_MASK					0x40000000
#define HSCTLR_TE_SHIFT					30
#define HSCTLR_EE_MASK					0x02000000
#define HSCTLR_EE_SHIFT					25
#define HSCTLR_FI_MASK					0x00200000
#define HSCTLR_FI_SHIFT					21
#define HSCTLR_WXN_MASK					0x00080000
#define HSCTLR_WXN_SHIFT				19
#define HSCTLR_I_MASK					0x00001000
#define HSCTLR_I_SHIFT					12
#define HSCTLR_C_MASK					0x00000004
#define HSCTLR_C_SHIFT					2
#define HSCTLR_A_MASK					0x00000002
#define HSCTLR_A_SHIFT					1
#define HSCTLR_M_MASK					0x00000001
#define HSCTLR_M_SHIFT					0

/* DBGBXVR */
#define DBGBXVR_INITVAL					0x00000000
#define DBGBXVR_VMID_MASK				0x000000FF
#define DBGBXVR_VMID_SHIFT				0

#endif
