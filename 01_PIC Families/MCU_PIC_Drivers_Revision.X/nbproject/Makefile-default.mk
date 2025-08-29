#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/MCU_PIC_Drivers_Revision.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/MCU_PIC_Drivers_Revision.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=APPL/app.c ECUAL/7SEG/ecual_7seg.c ECUAL/BTN/ecual_btn.c ECUAL/Chr_lcd/ecual_chr_lcd.c ECUAL/DC_Motor/ecual_dc_motor.c ECUAL/Keypad/ecual_keypad.c ECUAL/LED/ecual_led.c ECUAL/Relay/ecual_relay.c MCAL/ADC/hal_adc.c MCAL/EEPROM/hal_eeprom.c MCAL/GPIO/hal_gpio.c MCAL/INTERRUPT/hal_ext_interrupt.c MCAL/INTERRUPT/hal_int_interrupt.c MCAL/INTERRUPT/hal_interrupt_mng.c MCAL/Timers/Timer0/hal_timer0.c MCAL/Timers/Timer1/hal_timer1.c MCAL/device_cfg.c MCAL/Timers/Timer2/hal_timer2.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/APPL/app.p1 ${OBJECTDIR}/ECUAL/7SEG/ecual_7seg.p1 ${OBJECTDIR}/ECUAL/BTN/ecual_btn.p1 ${OBJECTDIR}/ECUAL/Chr_lcd/ecual_chr_lcd.p1 ${OBJECTDIR}/ECUAL/DC_Motor/ecual_dc_motor.p1 ${OBJECTDIR}/ECUAL/Keypad/ecual_keypad.p1 ${OBJECTDIR}/ECUAL/LED/ecual_led.p1 ${OBJECTDIR}/ECUAL/Relay/ecual_relay.p1 ${OBJECTDIR}/MCAL/ADC/hal_adc.p1 ${OBJECTDIR}/MCAL/EEPROM/hal_eeprom.p1 ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1 ${OBJECTDIR}/MCAL/INTERRUPT/hal_ext_interrupt.p1 ${OBJECTDIR}/MCAL/INTERRUPT/hal_int_interrupt.p1 ${OBJECTDIR}/MCAL/INTERRUPT/hal_interrupt_mng.p1 ${OBJECTDIR}/MCAL/Timers/Timer0/hal_timer0.p1 ${OBJECTDIR}/MCAL/Timers/Timer1/hal_timer1.p1 ${OBJECTDIR}/MCAL/device_cfg.p1 ${OBJECTDIR}/MCAL/Timers/Timer2/hal_timer2.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/APPL/app.p1.d ${OBJECTDIR}/ECUAL/7SEG/ecual_7seg.p1.d ${OBJECTDIR}/ECUAL/BTN/ecual_btn.p1.d ${OBJECTDIR}/ECUAL/Chr_lcd/ecual_chr_lcd.p1.d ${OBJECTDIR}/ECUAL/DC_Motor/ecual_dc_motor.p1.d ${OBJECTDIR}/ECUAL/Keypad/ecual_keypad.p1.d ${OBJECTDIR}/ECUAL/LED/ecual_led.p1.d ${OBJECTDIR}/ECUAL/Relay/ecual_relay.p1.d ${OBJECTDIR}/MCAL/ADC/hal_adc.p1.d ${OBJECTDIR}/MCAL/EEPROM/hal_eeprom.p1.d ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1.d ${OBJECTDIR}/MCAL/INTERRUPT/hal_ext_interrupt.p1.d ${OBJECTDIR}/MCAL/INTERRUPT/hal_int_interrupt.p1.d ${OBJECTDIR}/MCAL/INTERRUPT/hal_interrupt_mng.p1.d ${OBJECTDIR}/MCAL/Timers/Timer0/hal_timer0.p1.d ${OBJECTDIR}/MCAL/Timers/Timer1/hal_timer1.p1.d ${OBJECTDIR}/MCAL/device_cfg.p1.d ${OBJECTDIR}/MCAL/Timers/Timer2/hal_timer2.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/APPL/app.p1 ${OBJECTDIR}/ECUAL/7SEG/ecual_7seg.p1 ${OBJECTDIR}/ECUAL/BTN/ecual_btn.p1 ${OBJECTDIR}/ECUAL/Chr_lcd/ecual_chr_lcd.p1 ${OBJECTDIR}/ECUAL/DC_Motor/ecual_dc_motor.p1 ${OBJECTDIR}/ECUAL/Keypad/ecual_keypad.p1 ${OBJECTDIR}/ECUAL/LED/ecual_led.p1 ${OBJECTDIR}/ECUAL/Relay/ecual_relay.p1 ${OBJECTDIR}/MCAL/ADC/hal_adc.p1 ${OBJECTDIR}/MCAL/EEPROM/hal_eeprom.p1 ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1 ${OBJECTDIR}/MCAL/INTERRUPT/hal_ext_interrupt.p1 ${OBJECTDIR}/MCAL/INTERRUPT/hal_int_interrupt.p1 ${OBJECTDIR}/MCAL/INTERRUPT/hal_interrupt_mng.p1 ${OBJECTDIR}/MCAL/Timers/Timer0/hal_timer0.p1 ${OBJECTDIR}/MCAL/Timers/Timer1/hal_timer1.p1 ${OBJECTDIR}/MCAL/device_cfg.p1 ${OBJECTDIR}/MCAL/Timers/Timer2/hal_timer2.p1

# Source Files
SOURCEFILES=APPL/app.c ECUAL/7SEG/ecual_7seg.c ECUAL/BTN/ecual_btn.c ECUAL/Chr_lcd/ecual_chr_lcd.c ECUAL/DC_Motor/ecual_dc_motor.c ECUAL/Keypad/ecual_keypad.c ECUAL/LED/ecual_led.c ECUAL/Relay/ecual_relay.c MCAL/ADC/hal_adc.c MCAL/EEPROM/hal_eeprom.c MCAL/GPIO/hal_gpio.c MCAL/INTERRUPT/hal_ext_interrupt.c MCAL/INTERRUPT/hal_int_interrupt.c MCAL/INTERRUPT/hal_interrupt_mng.c MCAL/Timers/Timer0/hal_timer0.c MCAL/Timers/Timer1/hal_timer1.c MCAL/device_cfg.c MCAL/Timers/Timer2/hal_timer2.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/MCU_PIC_Drivers_Revision.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F46K20
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/APPL/app.p1: APPL/app.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/APPL" 
	@${RM} ${OBJECTDIR}/APPL/app.p1.d 
	@${RM} ${OBJECTDIR}/APPL/app.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/APPL/app.p1 APPL/app.c 
	@-${MV} ${OBJECTDIR}/APPL/app.d ${OBJECTDIR}/APPL/app.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/APPL/app.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL/7SEG/ecual_7seg.p1: ECUAL/7SEG/ecual_7seg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL/7SEG" 
	@${RM} ${OBJECTDIR}/ECUAL/7SEG/ecual_7seg.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL/7SEG/ecual_7seg.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL/7SEG/ecual_7seg.p1 ECUAL/7SEG/ecual_7seg.c 
	@-${MV} ${OBJECTDIR}/ECUAL/7SEG/ecual_7seg.d ${OBJECTDIR}/ECUAL/7SEG/ecual_7seg.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL/7SEG/ecual_7seg.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL/BTN/ecual_btn.p1: ECUAL/BTN/ecual_btn.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL/BTN" 
	@${RM} ${OBJECTDIR}/ECUAL/BTN/ecual_btn.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL/BTN/ecual_btn.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL/BTN/ecual_btn.p1 ECUAL/BTN/ecual_btn.c 
	@-${MV} ${OBJECTDIR}/ECUAL/BTN/ecual_btn.d ${OBJECTDIR}/ECUAL/BTN/ecual_btn.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL/BTN/ecual_btn.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL/Chr_lcd/ecual_chr_lcd.p1: ECUAL/Chr_lcd/ecual_chr_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL/Chr_lcd" 
	@${RM} ${OBJECTDIR}/ECUAL/Chr_lcd/ecual_chr_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL/Chr_lcd/ecual_chr_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL/Chr_lcd/ecual_chr_lcd.p1 ECUAL/Chr_lcd/ecual_chr_lcd.c 
	@-${MV} ${OBJECTDIR}/ECUAL/Chr_lcd/ecual_chr_lcd.d ${OBJECTDIR}/ECUAL/Chr_lcd/ecual_chr_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL/Chr_lcd/ecual_chr_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL/DC_Motor/ecual_dc_motor.p1: ECUAL/DC_Motor/ecual_dc_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL/DC_Motor" 
	@${RM} ${OBJECTDIR}/ECUAL/DC_Motor/ecual_dc_motor.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL/DC_Motor/ecual_dc_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL/DC_Motor/ecual_dc_motor.p1 ECUAL/DC_Motor/ecual_dc_motor.c 
	@-${MV} ${OBJECTDIR}/ECUAL/DC_Motor/ecual_dc_motor.d ${OBJECTDIR}/ECUAL/DC_Motor/ecual_dc_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL/DC_Motor/ecual_dc_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL/Keypad/ecual_keypad.p1: ECUAL/Keypad/ecual_keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL/Keypad" 
	@${RM} ${OBJECTDIR}/ECUAL/Keypad/ecual_keypad.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL/Keypad/ecual_keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL/Keypad/ecual_keypad.p1 ECUAL/Keypad/ecual_keypad.c 
	@-${MV} ${OBJECTDIR}/ECUAL/Keypad/ecual_keypad.d ${OBJECTDIR}/ECUAL/Keypad/ecual_keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL/Keypad/ecual_keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL/LED/ecual_led.p1: ECUAL/LED/ecual_led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL/LED" 
	@${RM} ${OBJECTDIR}/ECUAL/LED/ecual_led.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL/LED/ecual_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL/LED/ecual_led.p1 ECUAL/LED/ecual_led.c 
	@-${MV} ${OBJECTDIR}/ECUAL/LED/ecual_led.d ${OBJECTDIR}/ECUAL/LED/ecual_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL/LED/ecual_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL/Relay/ecual_relay.p1: ECUAL/Relay/ecual_relay.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL/Relay" 
	@${RM} ${OBJECTDIR}/ECUAL/Relay/ecual_relay.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL/Relay/ecual_relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL/Relay/ecual_relay.p1 ECUAL/Relay/ecual_relay.c 
	@-${MV} ${OBJECTDIR}/ECUAL/Relay/ecual_relay.d ${OBJECTDIR}/ECUAL/Relay/ecual_relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL/Relay/ecual_relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/ADC/hal_adc.p1: MCAL/ADC/hal_adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/ADC" 
	@${RM} ${OBJECTDIR}/MCAL/ADC/hal_adc.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/ADC/hal_adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/ADC/hal_adc.p1 MCAL/ADC/hal_adc.c 
	@-${MV} ${OBJECTDIR}/MCAL/ADC/hal_adc.d ${OBJECTDIR}/MCAL/ADC/hal_adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/ADC/hal_adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/EEPROM/hal_eeprom.p1: MCAL/EEPROM/hal_eeprom.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL/EEPROM/hal_eeprom.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/EEPROM/hal_eeprom.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/EEPROM/hal_eeprom.p1 MCAL/EEPROM/hal_eeprom.c 
	@-${MV} ${OBJECTDIR}/MCAL/EEPROM/hal_eeprom.d ${OBJECTDIR}/MCAL/EEPROM/hal_eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/EEPROM/hal_eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1: MCAL/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1 MCAL/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL/GPIO/hal_gpio.d ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/INTERRUPT/hal_ext_interrupt.p1: MCAL/INTERRUPT/hal_ext_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/INTERRUPT" 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/hal_ext_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/hal_ext_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/INTERRUPT/hal_ext_interrupt.p1 MCAL/INTERRUPT/hal_ext_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL/INTERRUPT/hal_ext_interrupt.d ${OBJECTDIR}/MCAL/INTERRUPT/hal_ext_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/INTERRUPT/hal_ext_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/INTERRUPT/hal_int_interrupt.p1: MCAL/INTERRUPT/hal_int_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/INTERRUPT" 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/hal_int_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/hal_int_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/INTERRUPT/hal_int_interrupt.p1 MCAL/INTERRUPT/hal_int_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL/INTERRUPT/hal_int_interrupt.d ${OBJECTDIR}/MCAL/INTERRUPT/hal_int_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/INTERRUPT/hal_int_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/INTERRUPT/hal_interrupt_mng.p1: MCAL/INTERRUPT/hal_interrupt_mng.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/INTERRUPT" 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/hal_interrupt_mng.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/hal_interrupt_mng.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/INTERRUPT/hal_interrupt_mng.p1 MCAL/INTERRUPT/hal_interrupt_mng.c 
	@-${MV} ${OBJECTDIR}/MCAL/INTERRUPT/hal_interrupt_mng.d ${OBJECTDIR}/MCAL/INTERRUPT/hal_interrupt_mng.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/INTERRUPT/hal_interrupt_mng.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Timers/Timer0/hal_timer0.p1: MCAL/Timers/Timer0/hal_timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Timers/Timer0" 
	@${RM} ${OBJECTDIR}/MCAL/Timers/Timer0/hal_timer0.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Timers/Timer0/hal_timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Timers/Timer0/hal_timer0.p1 MCAL/Timers/Timer0/hal_timer0.c 
	@-${MV} ${OBJECTDIR}/MCAL/Timers/Timer0/hal_timer0.d ${OBJECTDIR}/MCAL/Timers/Timer0/hal_timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Timers/Timer0/hal_timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Timers/Timer1/hal_timer1.p1: MCAL/Timers/Timer1/hal_timer1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Timers/Timer1" 
	@${RM} ${OBJECTDIR}/MCAL/Timers/Timer1/hal_timer1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Timers/Timer1/hal_timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Timers/Timer1/hal_timer1.p1 MCAL/Timers/Timer1/hal_timer1.c 
	@-${MV} ${OBJECTDIR}/MCAL/Timers/Timer1/hal_timer1.d ${OBJECTDIR}/MCAL/Timers/Timer1/hal_timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Timers/Timer1/hal_timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/device_cfg.p1: MCAL/device_cfg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL" 
	@${RM} ${OBJECTDIR}/MCAL/device_cfg.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/device_cfg.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/device_cfg.p1 MCAL/device_cfg.c 
	@-${MV} ${OBJECTDIR}/MCAL/device_cfg.d ${OBJECTDIR}/MCAL/device_cfg.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/device_cfg.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Timers/Timer2/hal_timer2.p1: MCAL/Timers/Timer2/hal_timer2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Timers/Timer2" 
	@${RM} ${OBJECTDIR}/MCAL/Timers/Timer2/hal_timer2.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Timers/Timer2/hal_timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Timers/Timer2/hal_timer2.p1 MCAL/Timers/Timer2/hal_timer2.c 
	@-${MV} ${OBJECTDIR}/MCAL/Timers/Timer2/hal_timer2.d ${OBJECTDIR}/MCAL/Timers/Timer2/hal_timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Timers/Timer2/hal_timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/APPL/app.p1: APPL/app.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/APPL" 
	@${RM} ${OBJECTDIR}/APPL/app.p1.d 
	@${RM} ${OBJECTDIR}/APPL/app.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/APPL/app.p1 APPL/app.c 
	@-${MV} ${OBJECTDIR}/APPL/app.d ${OBJECTDIR}/APPL/app.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/APPL/app.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL/7SEG/ecual_7seg.p1: ECUAL/7SEG/ecual_7seg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL/7SEG" 
	@${RM} ${OBJECTDIR}/ECUAL/7SEG/ecual_7seg.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL/7SEG/ecual_7seg.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL/7SEG/ecual_7seg.p1 ECUAL/7SEG/ecual_7seg.c 
	@-${MV} ${OBJECTDIR}/ECUAL/7SEG/ecual_7seg.d ${OBJECTDIR}/ECUAL/7SEG/ecual_7seg.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL/7SEG/ecual_7seg.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL/BTN/ecual_btn.p1: ECUAL/BTN/ecual_btn.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL/BTN" 
	@${RM} ${OBJECTDIR}/ECUAL/BTN/ecual_btn.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL/BTN/ecual_btn.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL/BTN/ecual_btn.p1 ECUAL/BTN/ecual_btn.c 
	@-${MV} ${OBJECTDIR}/ECUAL/BTN/ecual_btn.d ${OBJECTDIR}/ECUAL/BTN/ecual_btn.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL/BTN/ecual_btn.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL/Chr_lcd/ecual_chr_lcd.p1: ECUAL/Chr_lcd/ecual_chr_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL/Chr_lcd" 
	@${RM} ${OBJECTDIR}/ECUAL/Chr_lcd/ecual_chr_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL/Chr_lcd/ecual_chr_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL/Chr_lcd/ecual_chr_lcd.p1 ECUAL/Chr_lcd/ecual_chr_lcd.c 
	@-${MV} ${OBJECTDIR}/ECUAL/Chr_lcd/ecual_chr_lcd.d ${OBJECTDIR}/ECUAL/Chr_lcd/ecual_chr_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL/Chr_lcd/ecual_chr_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL/DC_Motor/ecual_dc_motor.p1: ECUAL/DC_Motor/ecual_dc_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL/DC_Motor" 
	@${RM} ${OBJECTDIR}/ECUAL/DC_Motor/ecual_dc_motor.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL/DC_Motor/ecual_dc_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL/DC_Motor/ecual_dc_motor.p1 ECUAL/DC_Motor/ecual_dc_motor.c 
	@-${MV} ${OBJECTDIR}/ECUAL/DC_Motor/ecual_dc_motor.d ${OBJECTDIR}/ECUAL/DC_Motor/ecual_dc_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL/DC_Motor/ecual_dc_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL/Keypad/ecual_keypad.p1: ECUAL/Keypad/ecual_keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL/Keypad" 
	@${RM} ${OBJECTDIR}/ECUAL/Keypad/ecual_keypad.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL/Keypad/ecual_keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL/Keypad/ecual_keypad.p1 ECUAL/Keypad/ecual_keypad.c 
	@-${MV} ${OBJECTDIR}/ECUAL/Keypad/ecual_keypad.d ${OBJECTDIR}/ECUAL/Keypad/ecual_keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL/Keypad/ecual_keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL/LED/ecual_led.p1: ECUAL/LED/ecual_led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL/LED" 
	@${RM} ${OBJECTDIR}/ECUAL/LED/ecual_led.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL/LED/ecual_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL/LED/ecual_led.p1 ECUAL/LED/ecual_led.c 
	@-${MV} ${OBJECTDIR}/ECUAL/LED/ecual_led.d ${OBJECTDIR}/ECUAL/LED/ecual_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL/LED/ecual_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL/Relay/ecual_relay.p1: ECUAL/Relay/ecual_relay.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL/Relay" 
	@${RM} ${OBJECTDIR}/ECUAL/Relay/ecual_relay.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL/Relay/ecual_relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL/Relay/ecual_relay.p1 ECUAL/Relay/ecual_relay.c 
	@-${MV} ${OBJECTDIR}/ECUAL/Relay/ecual_relay.d ${OBJECTDIR}/ECUAL/Relay/ecual_relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL/Relay/ecual_relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/ADC/hal_adc.p1: MCAL/ADC/hal_adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/ADC" 
	@${RM} ${OBJECTDIR}/MCAL/ADC/hal_adc.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/ADC/hal_adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/ADC/hal_adc.p1 MCAL/ADC/hal_adc.c 
	@-${MV} ${OBJECTDIR}/MCAL/ADC/hal_adc.d ${OBJECTDIR}/MCAL/ADC/hal_adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/ADC/hal_adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/EEPROM/hal_eeprom.p1: MCAL/EEPROM/hal_eeprom.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL/EEPROM/hal_eeprom.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/EEPROM/hal_eeprom.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/EEPROM/hal_eeprom.p1 MCAL/EEPROM/hal_eeprom.c 
	@-${MV} ${OBJECTDIR}/MCAL/EEPROM/hal_eeprom.d ${OBJECTDIR}/MCAL/EEPROM/hal_eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/EEPROM/hal_eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1: MCAL/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1 MCAL/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL/GPIO/hal_gpio.d ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/INTERRUPT/hal_ext_interrupt.p1: MCAL/INTERRUPT/hal_ext_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/INTERRUPT" 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/hal_ext_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/hal_ext_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/INTERRUPT/hal_ext_interrupt.p1 MCAL/INTERRUPT/hal_ext_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL/INTERRUPT/hal_ext_interrupt.d ${OBJECTDIR}/MCAL/INTERRUPT/hal_ext_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/INTERRUPT/hal_ext_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/INTERRUPT/hal_int_interrupt.p1: MCAL/INTERRUPT/hal_int_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/INTERRUPT" 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/hal_int_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/hal_int_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/INTERRUPT/hal_int_interrupt.p1 MCAL/INTERRUPT/hal_int_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL/INTERRUPT/hal_int_interrupt.d ${OBJECTDIR}/MCAL/INTERRUPT/hal_int_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/INTERRUPT/hal_int_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/INTERRUPT/hal_interrupt_mng.p1: MCAL/INTERRUPT/hal_interrupt_mng.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/INTERRUPT" 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/hal_interrupt_mng.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/hal_interrupt_mng.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/INTERRUPT/hal_interrupt_mng.p1 MCAL/INTERRUPT/hal_interrupt_mng.c 
	@-${MV} ${OBJECTDIR}/MCAL/INTERRUPT/hal_interrupt_mng.d ${OBJECTDIR}/MCAL/INTERRUPT/hal_interrupt_mng.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/INTERRUPT/hal_interrupt_mng.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Timers/Timer0/hal_timer0.p1: MCAL/Timers/Timer0/hal_timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Timers/Timer0" 
	@${RM} ${OBJECTDIR}/MCAL/Timers/Timer0/hal_timer0.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Timers/Timer0/hal_timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Timers/Timer0/hal_timer0.p1 MCAL/Timers/Timer0/hal_timer0.c 
	@-${MV} ${OBJECTDIR}/MCAL/Timers/Timer0/hal_timer0.d ${OBJECTDIR}/MCAL/Timers/Timer0/hal_timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Timers/Timer0/hal_timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Timers/Timer1/hal_timer1.p1: MCAL/Timers/Timer1/hal_timer1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Timers/Timer1" 
	@${RM} ${OBJECTDIR}/MCAL/Timers/Timer1/hal_timer1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Timers/Timer1/hal_timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Timers/Timer1/hal_timer1.p1 MCAL/Timers/Timer1/hal_timer1.c 
	@-${MV} ${OBJECTDIR}/MCAL/Timers/Timer1/hal_timer1.d ${OBJECTDIR}/MCAL/Timers/Timer1/hal_timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Timers/Timer1/hal_timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/device_cfg.p1: MCAL/device_cfg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL" 
	@${RM} ${OBJECTDIR}/MCAL/device_cfg.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/device_cfg.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/device_cfg.p1 MCAL/device_cfg.c 
	@-${MV} ${OBJECTDIR}/MCAL/device_cfg.d ${OBJECTDIR}/MCAL/device_cfg.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/device_cfg.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Timers/Timer2/hal_timer2.p1: MCAL/Timers/Timer2/hal_timer2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Timers/Timer2" 
	@${RM} ${OBJECTDIR}/MCAL/Timers/Timer2/hal_timer2.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Timers/Timer2/hal_timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Timers/Timer2/hal_timer2.p1 MCAL/Timers/Timer2/hal_timer2.c 
	@-${MV} ${OBJECTDIR}/MCAL/Timers/Timer2/hal_timer2.d ${OBJECTDIR}/MCAL/Timers/Timer2/hal_timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Timers/Timer2/hal_timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/MCU_PIC_Drivers_Revision.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/MCU_PIC_Drivers_Revision.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/MCU_PIC_Drivers_Revision.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/MCU_PIC_Drivers_Revision.X.${IMAGE_TYPE}.hex 
	
	
else
${DISTDIR}/MCU_PIC_Drivers_Revision.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/MCU_PIC_Drivers_Revision.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/MCU_PIC_Drivers_Revision.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
