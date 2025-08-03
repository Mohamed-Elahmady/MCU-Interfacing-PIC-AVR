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
FINAL_IMAGE=${DISTDIR}/MCU_ATMEGA32_Drivers.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/MCU_ATMEGA32_Drivers.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=Codes/ECUAL/7SEG/app1.c Codes/ECUAL/BTN/app1.c Codes/ECUAL/Chr_Lcd/app1.c Codes/ECUAL/DC_Motor/app1.c Codes/ECUAL/Keypad/app1.c Codes/ECUAL/LED/app1.c Codes/ECUAL/Relay/app1.c Codes/MCAL/GPIO/app1.c APP_Layer/main.c ECUAL_Layer/7SEG/ecual_7seg.c ECUAL_Layer/BTN/ecual_btn.c ECUAL_Layer/Chr_Lcd/ecual_chr_lcd.c ECUAL_Layer/DC_Motor/ecual_dc_motor.c ECUAL_Layer/Keypad/ecual_keypad.c ECUAL_Layer/LED/ecual_led.c ECUAL_Layer/Relay/ecual_relay.c ECUAL_Layer/ECUAL_INIT.c MCAL_Layer/GPIO/hal_gpio.c MCAL_Layer/device_cfg.c MCAL_Layer/Interrupt/hal_ext_interrupt.c MCAL_Layer/Interrupt/hal_int_interrupt.c MCAL_Layer/Interrupt/hal_interrupt_mng.c Codes/MCAL/Interrupt/app1.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/Codes/ECUAL/7SEG/app1.o ${OBJECTDIR}/Codes/ECUAL/BTN/app1.o ${OBJECTDIR}/Codes/ECUAL/Chr_Lcd/app1.o ${OBJECTDIR}/Codes/ECUAL/DC_Motor/app1.o ${OBJECTDIR}/Codes/ECUAL/Keypad/app1.o ${OBJECTDIR}/Codes/ECUAL/LED/app1.o ${OBJECTDIR}/Codes/ECUAL/Relay/app1.o ${OBJECTDIR}/Codes/MCAL/GPIO/app1.o ${OBJECTDIR}/APP_Layer/main.o ${OBJECTDIR}/ECUAL_Layer/7SEG/ecual_7seg.o ${OBJECTDIR}/ECUAL_Layer/BTN/ecual_btn.o ${OBJECTDIR}/ECUAL_Layer/Chr_Lcd/ecual_chr_lcd.o ${OBJECTDIR}/ECUAL_Layer/DC_Motor/ecual_dc_motor.o ${OBJECTDIR}/ECUAL_Layer/Keypad/ecual_keypad.o ${OBJECTDIR}/ECUAL_Layer/LED/ecual_led.o ${OBJECTDIR}/ECUAL_Layer/Relay/ecual_relay.o ${OBJECTDIR}/ECUAL_Layer/ECUAL_INIT.o ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.o ${OBJECTDIR}/MCAL_Layer/device_cfg.o ${OBJECTDIR}/MCAL_Layer/Interrupt/hal_ext_interrupt.o ${OBJECTDIR}/MCAL_Layer/Interrupt/hal_int_interrupt.o ${OBJECTDIR}/MCAL_Layer/Interrupt/hal_interrupt_mng.o ${OBJECTDIR}/Codes/MCAL/Interrupt/app1.o
POSSIBLE_DEPFILES=${OBJECTDIR}/Codes/ECUAL/7SEG/app1.o.d ${OBJECTDIR}/Codes/ECUAL/BTN/app1.o.d ${OBJECTDIR}/Codes/ECUAL/Chr_Lcd/app1.o.d ${OBJECTDIR}/Codes/ECUAL/DC_Motor/app1.o.d ${OBJECTDIR}/Codes/ECUAL/Keypad/app1.o.d ${OBJECTDIR}/Codes/ECUAL/LED/app1.o.d ${OBJECTDIR}/Codes/ECUAL/Relay/app1.o.d ${OBJECTDIR}/Codes/MCAL/GPIO/app1.o.d ${OBJECTDIR}/APP_Layer/main.o.d ${OBJECTDIR}/ECUAL_Layer/7SEG/ecual_7seg.o.d ${OBJECTDIR}/ECUAL_Layer/BTN/ecual_btn.o.d ${OBJECTDIR}/ECUAL_Layer/Chr_Lcd/ecual_chr_lcd.o.d ${OBJECTDIR}/ECUAL_Layer/DC_Motor/ecual_dc_motor.o.d ${OBJECTDIR}/ECUAL_Layer/Keypad/ecual_keypad.o.d ${OBJECTDIR}/ECUAL_Layer/LED/ecual_led.o.d ${OBJECTDIR}/ECUAL_Layer/Relay/ecual_relay.o.d ${OBJECTDIR}/ECUAL_Layer/ECUAL_INIT.o.d ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.o.d ${OBJECTDIR}/MCAL_Layer/device_cfg.o.d ${OBJECTDIR}/MCAL_Layer/Interrupt/hal_ext_interrupt.o.d ${OBJECTDIR}/MCAL_Layer/Interrupt/hal_int_interrupt.o.d ${OBJECTDIR}/MCAL_Layer/Interrupt/hal_interrupt_mng.o.d ${OBJECTDIR}/Codes/MCAL/Interrupt/app1.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/Codes/ECUAL/7SEG/app1.o ${OBJECTDIR}/Codes/ECUAL/BTN/app1.o ${OBJECTDIR}/Codes/ECUAL/Chr_Lcd/app1.o ${OBJECTDIR}/Codes/ECUAL/DC_Motor/app1.o ${OBJECTDIR}/Codes/ECUAL/Keypad/app1.o ${OBJECTDIR}/Codes/ECUAL/LED/app1.o ${OBJECTDIR}/Codes/ECUAL/Relay/app1.o ${OBJECTDIR}/Codes/MCAL/GPIO/app1.o ${OBJECTDIR}/APP_Layer/main.o ${OBJECTDIR}/ECUAL_Layer/7SEG/ecual_7seg.o ${OBJECTDIR}/ECUAL_Layer/BTN/ecual_btn.o ${OBJECTDIR}/ECUAL_Layer/Chr_Lcd/ecual_chr_lcd.o ${OBJECTDIR}/ECUAL_Layer/DC_Motor/ecual_dc_motor.o ${OBJECTDIR}/ECUAL_Layer/Keypad/ecual_keypad.o ${OBJECTDIR}/ECUAL_Layer/LED/ecual_led.o ${OBJECTDIR}/ECUAL_Layer/Relay/ecual_relay.o ${OBJECTDIR}/ECUAL_Layer/ECUAL_INIT.o ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.o ${OBJECTDIR}/MCAL_Layer/device_cfg.o ${OBJECTDIR}/MCAL_Layer/Interrupt/hal_ext_interrupt.o ${OBJECTDIR}/MCAL_Layer/Interrupt/hal_int_interrupt.o ${OBJECTDIR}/MCAL_Layer/Interrupt/hal_interrupt_mng.o ${OBJECTDIR}/Codes/MCAL/Interrupt/app1.o

# Source Files
SOURCEFILES=Codes/ECUAL/7SEG/app1.c Codes/ECUAL/BTN/app1.c Codes/ECUAL/Chr_Lcd/app1.c Codes/ECUAL/DC_Motor/app1.c Codes/ECUAL/Keypad/app1.c Codes/ECUAL/LED/app1.c Codes/ECUAL/Relay/app1.c Codes/MCAL/GPIO/app1.c APP_Layer/main.c ECUAL_Layer/7SEG/ecual_7seg.c ECUAL_Layer/BTN/ecual_btn.c ECUAL_Layer/Chr_Lcd/ecual_chr_lcd.c ECUAL_Layer/DC_Motor/ecual_dc_motor.c ECUAL_Layer/Keypad/ecual_keypad.c ECUAL_Layer/LED/ecual_led.c ECUAL_Layer/Relay/ecual_relay.c ECUAL_Layer/ECUAL_INIT.c MCAL_Layer/GPIO/hal_gpio.c MCAL_Layer/device_cfg.c MCAL_Layer/Interrupt/hal_ext_interrupt.c MCAL_Layer/Interrupt/hal_int_interrupt.c MCAL_Layer/Interrupt/hal_interrupt_mng.c Codes/MCAL/Interrupt/app1.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/MCU_ATMEGA32_Drivers.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATmega32
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/Codes/ECUAL/7SEG/app1.o: Codes/ECUAL/7SEG/app1.c  .generated_files/flags/default/f50cae18214472964ccfca90478e9de3ae5acc40 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/Codes/ECUAL/7SEG" 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/7SEG/app1.o.d 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/7SEG/app1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/Codes/ECUAL/7SEG/app1.o.d" -MT "${OBJECTDIR}/Codes/ECUAL/7SEG/app1.o.d" -MT ${OBJECTDIR}/Codes/ECUAL/7SEG/app1.o -o ${OBJECTDIR}/Codes/ECUAL/7SEG/app1.o Codes/ECUAL/7SEG/app1.c 
	
${OBJECTDIR}/Codes/ECUAL/BTN/app1.o: Codes/ECUAL/BTN/app1.c  .generated_files/flags/default/3b905ec2a9571ba5b51ecc163e6defceb3477db9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/Codes/ECUAL/BTN" 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/BTN/app1.o.d 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/BTN/app1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/Codes/ECUAL/BTN/app1.o.d" -MT "${OBJECTDIR}/Codes/ECUAL/BTN/app1.o.d" -MT ${OBJECTDIR}/Codes/ECUAL/BTN/app1.o -o ${OBJECTDIR}/Codes/ECUAL/BTN/app1.o Codes/ECUAL/BTN/app1.c 
	
${OBJECTDIR}/Codes/ECUAL/Chr_Lcd/app1.o: Codes/ECUAL/Chr_Lcd/app1.c  .generated_files/flags/default/1d25e097d65619412d58f73d3f1c6ef164629ecf .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/Codes/ECUAL/Chr_Lcd" 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/Chr_Lcd/app1.o.d 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/Chr_Lcd/app1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/Codes/ECUAL/Chr_Lcd/app1.o.d" -MT "${OBJECTDIR}/Codes/ECUAL/Chr_Lcd/app1.o.d" -MT ${OBJECTDIR}/Codes/ECUAL/Chr_Lcd/app1.o -o ${OBJECTDIR}/Codes/ECUAL/Chr_Lcd/app1.o Codes/ECUAL/Chr_Lcd/app1.c 
	
${OBJECTDIR}/Codes/ECUAL/DC_Motor/app1.o: Codes/ECUAL/DC_Motor/app1.c  .generated_files/flags/default/c399f5b46f4ecab6dc12ed9355d72d15118a29dd .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/Codes/ECUAL/DC_Motor" 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/DC_Motor/app1.o.d 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/DC_Motor/app1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/Codes/ECUAL/DC_Motor/app1.o.d" -MT "${OBJECTDIR}/Codes/ECUAL/DC_Motor/app1.o.d" -MT ${OBJECTDIR}/Codes/ECUAL/DC_Motor/app1.o -o ${OBJECTDIR}/Codes/ECUAL/DC_Motor/app1.o Codes/ECUAL/DC_Motor/app1.c 
	
${OBJECTDIR}/Codes/ECUAL/Keypad/app1.o: Codes/ECUAL/Keypad/app1.c  .generated_files/flags/default/60a42cebd5904fa1f8debb8cb527c2ea0002028d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/Codes/ECUAL/Keypad" 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/Keypad/app1.o.d 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/Keypad/app1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/Codes/ECUAL/Keypad/app1.o.d" -MT "${OBJECTDIR}/Codes/ECUAL/Keypad/app1.o.d" -MT ${OBJECTDIR}/Codes/ECUAL/Keypad/app1.o -o ${OBJECTDIR}/Codes/ECUAL/Keypad/app1.o Codes/ECUAL/Keypad/app1.c 
	
${OBJECTDIR}/Codes/ECUAL/LED/app1.o: Codes/ECUAL/LED/app1.c  .generated_files/flags/default/67ff5e443e19216d1db3acba4105178a162158f6 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/Codes/ECUAL/LED" 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/LED/app1.o.d 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/LED/app1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/Codes/ECUAL/LED/app1.o.d" -MT "${OBJECTDIR}/Codes/ECUAL/LED/app1.o.d" -MT ${OBJECTDIR}/Codes/ECUAL/LED/app1.o -o ${OBJECTDIR}/Codes/ECUAL/LED/app1.o Codes/ECUAL/LED/app1.c 
	
${OBJECTDIR}/Codes/ECUAL/Relay/app1.o: Codes/ECUAL/Relay/app1.c  .generated_files/flags/default/421eb2d44d9cc38e44762554d3bcf069383d954f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/Codes/ECUAL/Relay" 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/Relay/app1.o.d 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/Relay/app1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/Codes/ECUAL/Relay/app1.o.d" -MT "${OBJECTDIR}/Codes/ECUAL/Relay/app1.o.d" -MT ${OBJECTDIR}/Codes/ECUAL/Relay/app1.o -o ${OBJECTDIR}/Codes/ECUAL/Relay/app1.o Codes/ECUAL/Relay/app1.c 
	
${OBJECTDIR}/Codes/MCAL/GPIO/app1.o: Codes/MCAL/GPIO/app1.c  .generated_files/flags/default/d9ce14ce18b96d4c0a30a5eb1dd062bc46f92725 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/Codes/MCAL/GPIO" 
	@${RM} ${OBJECTDIR}/Codes/MCAL/GPIO/app1.o.d 
	@${RM} ${OBJECTDIR}/Codes/MCAL/GPIO/app1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/Codes/MCAL/GPIO/app1.o.d" -MT "${OBJECTDIR}/Codes/MCAL/GPIO/app1.o.d" -MT ${OBJECTDIR}/Codes/MCAL/GPIO/app1.o -o ${OBJECTDIR}/Codes/MCAL/GPIO/app1.o Codes/MCAL/GPIO/app1.c 
	
${OBJECTDIR}/APP_Layer/main.o: APP_Layer/main.c  .generated_files/flags/default/9eb59cde2bcc36a2bd52a7d93a7cde9769e5f772 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/APP_Layer" 
	@${RM} ${OBJECTDIR}/APP_Layer/main.o.d 
	@${RM} ${OBJECTDIR}/APP_Layer/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/APP_Layer/main.o.d" -MT "${OBJECTDIR}/APP_Layer/main.o.d" -MT ${OBJECTDIR}/APP_Layer/main.o -o ${OBJECTDIR}/APP_Layer/main.o APP_Layer/main.c 
	
${OBJECTDIR}/ECUAL_Layer/7SEG/ecual_7seg.o: ECUAL_Layer/7SEG/ecual_7seg.c  .generated_files/flags/default/41b3113b6e6b0e8aa54e18a53639440dd787d862 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ECUAL_Layer/7SEG" 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/7SEG/ecual_7seg.o.d 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/7SEG/ecual_7seg.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/ECUAL_Layer/7SEG/ecual_7seg.o.d" -MT "${OBJECTDIR}/ECUAL_Layer/7SEG/ecual_7seg.o.d" -MT ${OBJECTDIR}/ECUAL_Layer/7SEG/ecual_7seg.o -o ${OBJECTDIR}/ECUAL_Layer/7SEG/ecual_7seg.o ECUAL_Layer/7SEG/ecual_7seg.c 
	
${OBJECTDIR}/ECUAL_Layer/BTN/ecual_btn.o: ECUAL_Layer/BTN/ecual_btn.c  .generated_files/flags/default/dd0f2595c17a8a7fbd2ab177793ed94bf588151f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ECUAL_Layer/BTN" 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/BTN/ecual_btn.o.d 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/BTN/ecual_btn.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/ECUAL_Layer/BTN/ecual_btn.o.d" -MT "${OBJECTDIR}/ECUAL_Layer/BTN/ecual_btn.o.d" -MT ${OBJECTDIR}/ECUAL_Layer/BTN/ecual_btn.o -o ${OBJECTDIR}/ECUAL_Layer/BTN/ecual_btn.o ECUAL_Layer/BTN/ecual_btn.c 
	
${OBJECTDIR}/ECUAL_Layer/Chr_Lcd/ecual_chr_lcd.o: ECUAL_Layer/Chr_Lcd/ecual_chr_lcd.c  .generated_files/flags/default/44536e85a6f9c2a8b1249004711d7c0896a3f852 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ECUAL_Layer/Chr_Lcd" 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/Chr_Lcd/ecual_chr_lcd.o.d 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/Chr_Lcd/ecual_chr_lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/ECUAL_Layer/Chr_Lcd/ecual_chr_lcd.o.d" -MT "${OBJECTDIR}/ECUAL_Layer/Chr_Lcd/ecual_chr_lcd.o.d" -MT ${OBJECTDIR}/ECUAL_Layer/Chr_Lcd/ecual_chr_lcd.o -o ${OBJECTDIR}/ECUAL_Layer/Chr_Lcd/ecual_chr_lcd.o ECUAL_Layer/Chr_Lcd/ecual_chr_lcd.c 
	
${OBJECTDIR}/ECUAL_Layer/DC_Motor/ecual_dc_motor.o: ECUAL_Layer/DC_Motor/ecual_dc_motor.c  .generated_files/flags/default/cb0e3611d03af940f624178e05b6ffc9a7795e8c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ECUAL_Layer/DC_Motor" 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/DC_Motor/ecual_dc_motor.o.d 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/DC_Motor/ecual_dc_motor.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/ECUAL_Layer/DC_Motor/ecual_dc_motor.o.d" -MT "${OBJECTDIR}/ECUAL_Layer/DC_Motor/ecual_dc_motor.o.d" -MT ${OBJECTDIR}/ECUAL_Layer/DC_Motor/ecual_dc_motor.o -o ${OBJECTDIR}/ECUAL_Layer/DC_Motor/ecual_dc_motor.o ECUAL_Layer/DC_Motor/ecual_dc_motor.c 
	
${OBJECTDIR}/ECUAL_Layer/Keypad/ecual_keypad.o: ECUAL_Layer/Keypad/ecual_keypad.c  .generated_files/flags/default/f91e1fd915e4c4123ad75bfd4b18b7e0d6c2a425 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ECUAL_Layer/Keypad" 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/Keypad/ecual_keypad.o.d 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/Keypad/ecual_keypad.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/ECUAL_Layer/Keypad/ecual_keypad.o.d" -MT "${OBJECTDIR}/ECUAL_Layer/Keypad/ecual_keypad.o.d" -MT ${OBJECTDIR}/ECUAL_Layer/Keypad/ecual_keypad.o -o ${OBJECTDIR}/ECUAL_Layer/Keypad/ecual_keypad.o ECUAL_Layer/Keypad/ecual_keypad.c 
	
${OBJECTDIR}/ECUAL_Layer/LED/ecual_led.o: ECUAL_Layer/LED/ecual_led.c  .generated_files/flags/default/69cdc673f05d01b6c49eb23c8bdfa91054a2db27 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ECUAL_Layer/LED" 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/LED/ecual_led.o.d 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/LED/ecual_led.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/ECUAL_Layer/LED/ecual_led.o.d" -MT "${OBJECTDIR}/ECUAL_Layer/LED/ecual_led.o.d" -MT ${OBJECTDIR}/ECUAL_Layer/LED/ecual_led.o -o ${OBJECTDIR}/ECUAL_Layer/LED/ecual_led.o ECUAL_Layer/LED/ecual_led.c 
	
${OBJECTDIR}/ECUAL_Layer/Relay/ecual_relay.o: ECUAL_Layer/Relay/ecual_relay.c  .generated_files/flags/default/ce34c81eab99a138904a2f1f1545df53e6d307d6 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ECUAL_Layer/Relay" 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/Relay/ecual_relay.o.d 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/Relay/ecual_relay.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/ECUAL_Layer/Relay/ecual_relay.o.d" -MT "${OBJECTDIR}/ECUAL_Layer/Relay/ecual_relay.o.d" -MT ${OBJECTDIR}/ECUAL_Layer/Relay/ecual_relay.o -o ${OBJECTDIR}/ECUAL_Layer/Relay/ecual_relay.o ECUAL_Layer/Relay/ecual_relay.c 
	
${OBJECTDIR}/ECUAL_Layer/ECUAL_INIT.o: ECUAL_Layer/ECUAL_INIT.c  .generated_files/flags/default/ee7598e8d4457be17fafd35c72f4e2ea0237fa8c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ECUAL_Layer" 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/ECUAL_INIT.o.d 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/ECUAL_INIT.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/ECUAL_Layer/ECUAL_INIT.o.d" -MT "${OBJECTDIR}/ECUAL_Layer/ECUAL_INIT.o.d" -MT ${OBJECTDIR}/ECUAL_Layer/ECUAL_INIT.o -o ${OBJECTDIR}/ECUAL_Layer/ECUAL_INIT.o ECUAL_Layer/ECUAL_INIT.c 
	
${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.o: MCAL_Layer/GPIO/hal_gpio.c  .generated_files/flags/default/3639617229792410c3bc41a0d4d32e5f4aee967d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.o.d" -MT "${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.o.d" -MT ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.o -o ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.o MCAL_Layer/GPIO/hal_gpio.c 
	
${OBJECTDIR}/MCAL_Layer/device_cfg.o: MCAL_Layer/device_cfg.c  .generated_files/flags/default/bd9599922df068aa19a7903dd5b9d51efa554b4e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/device_cfg.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/device_cfg.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/device_cfg.o.d" -MT "${OBJECTDIR}/MCAL_Layer/device_cfg.o.d" -MT ${OBJECTDIR}/MCAL_Layer/device_cfg.o -o ${OBJECTDIR}/MCAL_Layer/device_cfg.o MCAL_Layer/device_cfg.c 
	
${OBJECTDIR}/MCAL_Layer/Interrupt/hal_ext_interrupt.o: MCAL_Layer/Interrupt/hal_ext_interrupt.c  .generated_files/flags/default/2aaaf1a961eb2d69e54a3e12eb9c36afa88314dc .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/hal_ext_interrupt.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/hal_ext_interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/Interrupt/hal_ext_interrupt.o.d" -MT "${OBJECTDIR}/MCAL_Layer/Interrupt/hal_ext_interrupt.o.d" -MT ${OBJECTDIR}/MCAL_Layer/Interrupt/hal_ext_interrupt.o -o ${OBJECTDIR}/MCAL_Layer/Interrupt/hal_ext_interrupt.o MCAL_Layer/Interrupt/hal_ext_interrupt.c 
	
${OBJECTDIR}/MCAL_Layer/Interrupt/hal_int_interrupt.o: MCAL_Layer/Interrupt/hal_int_interrupt.c  .generated_files/flags/default/60ba81f8fbf7ae68e37f0deab5f886721ae8848f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/hal_int_interrupt.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/hal_int_interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/Interrupt/hal_int_interrupt.o.d" -MT "${OBJECTDIR}/MCAL_Layer/Interrupt/hal_int_interrupt.o.d" -MT ${OBJECTDIR}/MCAL_Layer/Interrupt/hal_int_interrupt.o -o ${OBJECTDIR}/MCAL_Layer/Interrupt/hal_int_interrupt.o MCAL_Layer/Interrupt/hal_int_interrupt.c 
	
${OBJECTDIR}/MCAL_Layer/Interrupt/hal_interrupt_mng.o: MCAL_Layer/Interrupt/hal_interrupt_mng.c  .generated_files/flags/default/c6b51d0c065a02cfeb9a3ed1252c62495482b572 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/hal_interrupt_mng.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/hal_interrupt_mng.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/Interrupt/hal_interrupt_mng.o.d" -MT "${OBJECTDIR}/MCAL_Layer/Interrupt/hal_interrupt_mng.o.d" -MT ${OBJECTDIR}/MCAL_Layer/Interrupt/hal_interrupt_mng.o -o ${OBJECTDIR}/MCAL_Layer/Interrupt/hal_interrupt_mng.o MCAL_Layer/Interrupt/hal_interrupt_mng.c 
	
${OBJECTDIR}/Codes/MCAL/Interrupt/app1.o: Codes/MCAL/Interrupt/app1.c  .generated_files/flags/default/9fec37fd3d8e1e058320ad6f67efca5d7ecde258 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/Codes/MCAL/Interrupt" 
	@${RM} ${OBJECTDIR}/Codes/MCAL/Interrupt/app1.o.d 
	@${RM} ${OBJECTDIR}/Codes/MCAL/Interrupt/app1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/Codes/MCAL/Interrupt/app1.o.d" -MT "${OBJECTDIR}/Codes/MCAL/Interrupt/app1.o.d" -MT ${OBJECTDIR}/Codes/MCAL/Interrupt/app1.o -o ${OBJECTDIR}/Codes/MCAL/Interrupt/app1.o Codes/MCAL/Interrupt/app1.c 
	
else
${OBJECTDIR}/Codes/ECUAL/7SEG/app1.o: Codes/ECUAL/7SEG/app1.c  .generated_files/flags/default/8240656e7ccbda6c2e75e7e13d0d59f75c906a1e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/Codes/ECUAL/7SEG" 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/7SEG/app1.o.d 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/7SEG/app1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/Codes/ECUAL/7SEG/app1.o.d" -MT "${OBJECTDIR}/Codes/ECUAL/7SEG/app1.o.d" -MT ${OBJECTDIR}/Codes/ECUAL/7SEG/app1.o -o ${OBJECTDIR}/Codes/ECUAL/7SEG/app1.o Codes/ECUAL/7SEG/app1.c 
	
${OBJECTDIR}/Codes/ECUAL/BTN/app1.o: Codes/ECUAL/BTN/app1.c  .generated_files/flags/default/38115782fc6f4c3e46c5c28b9b5e7e0630b77fda .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/Codes/ECUAL/BTN" 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/BTN/app1.o.d 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/BTN/app1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/Codes/ECUAL/BTN/app1.o.d" -MT "${OBJECTDIR}/Codes/ECUAL/BTN/app1.o.d" -MT ${OBJECTDIR}/Codes/ECUAL/BTN/app1.o -o ${OBJECTDIR}/Codes/ECUAL/BTN/app1.o Codes/ECUAL/BTN/app1.c 
	
${OBJECTDIR}/Codes/ECUAL/Chr_Lcd/app1.o: Codes/ECUAL/Chr_Lcd/app1.c  .generated_files/flags/default/a73640e68865dd8ecaef894926bf87949e48e5fc .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/Codes/ECUAL/Chr_Lcd" 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/Chr_Lcd/app1.o.d 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/Chr_Lcd/app1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/Codes/ECUAL/Chr_Lcd/app1.o.d" -MT "${OBJECTDIR}/Codes/ECUAL/Chr_Lcd/app1.o.d" -MT ${OBJECTDIR}/Codes/ECUAL/Chr_Lcd/app1.o -o ${OBJECTDIR}/Codes/ECUAL/Chr_Lcd/app1.o Codes/ECUAL/Chr_Lcd/app1.c 
	
${OBJECTDIR}/Codes/ECUAL/DC_Motor/app1.o: Codes/ECUAL/DC_Motor/app1.c  .generated_files/flags/default/3b708c92606f1ee681d1d381170b7e4afe760dc7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/Codes/ECUAL/DC_Motor" 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/DC_Motor/app1.o.d 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/DC_Motor/app1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/Codes/ECUAL/DC_Motor/app1.o.d" -MT "${OBJECTDIR}/Codes/ECUAL/DC_Motor/app1.o.d" -MT ${OBJECTDIR}/Codes/ECUAL/DC_Motor/app1.o -o ${OBJECTDIR}/Codes/ECUAL/DC_Motor/app1.o Codes/ECUAL/DC_Motor/app1.c 
	
${OBJECTDIR}/Codes/ECUAL/Keypad/app1.o: Codes/ECUAL/Keypad/app1.c  .generated_files/flags/default/2f63c823c502e6f76aa5e494eec3cd736682aaed .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/Codes/ECUAL/Keypad" 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/Keypad/app1.o.d 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/Keypad/app1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/Codes/ECUAL/Keypad/app1.o.d" -MT "${OBJECTDIR}/Codes/ECUAL/Keypad/app1.o.d" -MT ${OBJECTDIR}/Codes/ECUAL/Keypad/app1.o -o ${OBJECTDIR}/Codes/ECUAL/Keypad/app1.o Codes/ECUAL/Keypad/app1.c 
	
${OBJECTDIR}/Codes/ECUAL/LED/app1.o: Codes/ECUAL/LED/app1.c  .generated_files/flags/default/e049bcb73d6ab8b44b0b1d656009a5ac51f9d317 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/Codes/ECUAL/LED" 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/LED/app1.o.d 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/LED/app1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/Codes/ECUAL/LED/app1.o.d" -MT "${OBJECTDIR}/Codes/ECUAL/LED/app1.o.d" -MT ${OBJECTDIR}/Codes/ECUAL/LED/app1.o -o ${OBJECTDIR}/Codes/ECUAL/LED/app1.o Codes/ECUAL/LED/app1.c 
	
${OBJECTDIR}/Codes/ECUAL/Relay/app1.o: Codes/ECUAL/Relay/app1.c  .generated_files/flags/default/c43caf92579c3cac45bf9b570b77de00dff0f34b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/Codes/ECUAL/Relay" 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/Relay/app1.o.d 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/Relay/app1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/Codes/ECUAL/Relay/app1.o.d" -MT "${OBJECTDIR}/Codes/ECUAL/Relay/app1.o.d" -MT ${OBJECTDIR}/Codes/ECUAL/Relay/app1.o -o ${OBJECTDIR}/Codes/ECUAL/Relay/app1.o Codes/ECUAL/Relay/app1.c 
	
${OBJECTDIR}/Codes/MCAL/GPIO/app1.o: Codes/MCAL/GPIO/app1.c  .generated_files/flags/default/266fa179b07a78a4d32a9f9503cc7c9d6dd35e41 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/Codes/MCAL/GPIO" 
	@${RM} ${OBJECTDIR}/Codes/MCAL/GPIO/app1.o.d 
	@${RM} ${OBJECTDIR}/Codes/MCAL/GPIO/app1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/Codes/MCAL/GPIO/app1.o.d" -MT "${OBJECTDIR}/Codes/MCAL/GPIO/app1.o.d" -MT ${OBJECTDIR}/Codes/MCAL/GPIO/app1.o -o ${OBJECTDIR}/Codes/MCAL/GPIO/app1.o Codes/MCAL/GPIO/app1.c 
	
${OBJECTDIR}/APP_Layer/main.o: APP_Layer/main.c  .generated_files/flags/default/16278fab76bb8b7f4c9e9f03b290bcb71cf51ae4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/APP_Layer" 
	@${RM} ${OBJECTDIR}/APP_Layer/main.o.d 
	@${RM} ${OBJECTDIR}/APP_Layer/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/APP_Layer/main.o.d" -MT "${OBJECTDIR}/APP_Layer/main.o.d" -MT ${OBJECTDIR}/APP_Layer/main.o -o ${OBJECTDIR}/APP_Layer/main.o APP_Layer/main.c 
	
${OBJECTDIR}/ECUAL_Layer/7SEG/ecual_7seg.o: ECUAL_Layer/7SEG/ecual_7seg.c  .generated_files/flags/default/cdd2cb4075df161a93e90a5ba157c253562c6623 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ECUAL_Layer/7SEG" 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/7SEG/ecual_7seg.o.d 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/7SEG/ecual_7seg.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/ECUAL_Layer/7SEG/ecual_7seg.o.d" -MT "${OBJECTDIR}/ECUAL_Layer/7SEG/ecual_7seg.o.d" -MT ${OBJECTDIR}/ECUAL_Layer/7SEG/ecual_7seg.o -o ${OBJECTDIR}/ECUAL_Layer/7SEG/ecual_7seg.o ECUAL_Layer/7SEG/ecual_7seg.c 
	
${OBJECTDIR}/ECUAL_Layer/BTN/ecual_btn.o: ECUAL_Layer/BTN/ecual_btn.c  .generated_files/flags/default/64d37a42ff94946b89938ab3d63c9896cd057fb .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ECUAL_Layer/BTN" 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/BTN/ecual_btn.o.d 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/BTN/ecual_btn.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/ECUAL_Layer/BTN/ecual_btn.o.d" -MT "${OBJECTDIR}/ECUAL_Layer/BTN/ecual_btn.o.d" -MT ${OBJECTDIR}/ECUAL_Layer/BTN/ecual_btn.o -o ${OBJECTDIR}/ECUAL_Layer/BTN/ecual_btn.o ECUAL_Layer/BTN/ecual_btn.c 
	
${OBJECTDIR}/ECUAL_Layer/Chr_Lcd/ecual_chr_lcd.o: ECUAL_Layer/Chr_Lcd/ecual_chr_lcd.c  .generated_files/flags/default/264468fe4addbdc29e90a4fa00d5e2023a2e4600 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ECUAL_Layer/Chr_Lcd" 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/Chr_Lcd/ecual_chr_lcd.o.d 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/Chr_Lcd/ecual_chr_lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/ECUAL_Layer/Chr_Lcd/ecual_chr_lcd.o.d" -MT "${OBJECTDIR}/ECUAL_Layer/Chr_Lcd/ecual_chr_lcd.o.d" -MT ${OBJECTDIR}/ECUAL_Layer/Chr_Lcd/ecual_chr_lcd.o -o ${OBJECTDIR}/ECUAL_Layer/Chr_Lcd/ecual_chr_lcd.o ECUAL_Layer/Chr_Lcd/ecual_chr_lcd.c 
	
${OBJECTDIR}/ECUAL_Layer/DC_Motor/ecual_dc_motor.o: ECUAL_Layer/DC_Motor/ecual_dc_motor.c  .generated_files/flags/default/abc2f62784afef54cee00554dc555f7b9430d9f3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ECUAL_Layer/DC_Motor" 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/DC_Motor/ecual_dc_motor.o.d 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/DC_Motor/ecual_dc_motor.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/ECUAL_Layer/DC_Motor/ecual_dc_motor.o.d" -MT "${OBJECTDIR}/ECUAL_Layer/DC_Motor/ecual_dc_motor.o.d" -MT ${OBJECTDIR}/ECUAL_Layer/DC_Motor/ecual_dc_motor.o -o ${OBJECTDIR}/ECUAL_Layer/DC_Motor/ecual_dc_motor.o ECUAL_Layer/DC_Motor/ecual_dc_motor.c 
	
${OBJECTDIR}/ECUAL_Layer/Keypad/ecual_keypad.o: ECUAL_Layer/Keypad/ecual_keypad.c  .generated_files/flags/default/ecfbf92844c21283045f63ad26efb8e39a78ff98 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ECUAL_Layer/Keypad" 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/Keypad/ecual_keypad.o.d 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/Keypad/ecual_keypad.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/ECUAL_Layer/Keypad/ecual_keypad.o.d" -MT "${OBJECTDIR}/ECUAL_Layer/Keypad/ecual_keypad.o.d" -MT ${OBJECTDIR}/ECUAL_Layer/Keypad/ecual_keypad.o -o ${OBJECTDIR}/ECUAL_Layer/Keypad/ecual_keypad.o ECUAL_Layer/Keypad/ecual_keypad.c 
	
${OBJECTDIR}/ECUAL_Layer/LED/ecual_led.o: ECUAL_Layer/LED/ecual_led.c  .generated_files/flags/default/d55326d45e469b80c88cf7cc93eba3865a2e943e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ECUAL_Layer/LED" 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/LED/ecual_led.o.d 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/LED/ecual_led.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/ECUAL_Layer/LED/ecual_led.o.d" -MT "${OBJECTDIR}/ECUAL_Layer/LED/ecual_led.o.d" -MT ${OBJECTDIR}/ECUAL_Layer/LED/ecual_led.o -o ${OBJECTDIR}/ECUAL_Layer/LED/ecual_led.o ECUAL_Layer/LED/ecual_led.c 
	
${OBJECTDIR}/ECUAL_Layer/Relay/ecual_relay.o: ECUAL_Layer/Relay/ecual_relay.c  .generated_files/flags/default/d47e6866934887c630f45077a3d740afe262e8c0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ECUAL_Layer/Relay" 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/Relay/ecual_relay.o.d 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/Relay/ecual_relay.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/ECUAL_Layer/Relay/ecual_relay.o.d" -MT "${OBJECTDIR}/ECUAL_Layer/Relay/ecual_relay.o.d" -MT ${OBJECTDIR}/ECUAL_Layer/Relay/ecual_relay.o -o ${OBJECTDIR}/ECUAL_Layer/Relay/ecual_relay.o ECUAL_Layer/Relay/ecual_relay.c 
	
${OBJECTDIR}/ECUAL_Layer/ECUAL_INIT.o: ECUAL_Layer/ECUAL_INIT.c  .generated_files/flags/default/d12ff944f59fc7223a9360b80945d4a0e2f021b5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ECUAL_Layer" 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/ECUAL_INIT.o.d 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/ECUAL_INIT.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/ECUAL_Layer/ECUAL_INIT.o.d" -MT "${OBJECTDIR}/ECUAL_Layer/ECUAL_INIT.o.d" -MT ${OBJECTDIR}/ECUAL_Layer/ECUAL_INIT.o -o ${OBJECTDIR}/ECUAL_Layer/ECUAL_INIT.o ECUAL_Layer/ECUAL_INIT.c 
	
${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.o: MCAL_Layer/GPIO/hal_gpio.c  .generated_files/flags/default/6810db34198a642e3733f72cc13e3d57a3ae0116 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.o.d" -MT "${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.o.d" -MT ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.o -o ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.o MCAL_Layer/GPIO/hal_gpio.c 
	
${OBJECTDIR}/MCAL_Layer/device_cfg.o: MCAL_Layer/device_cfg.c  .generated_files/flags/default/8d87f5f5545f140c360b944cd88d22a6160e7c75 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/device_cfg.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/device_cfg.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/device_cfg.o.d" -MT "${OBJECTDIR}/MCAL_Layer/device_cfg.o.d" -MT ${OBJECTDIR}/MCAL_Layer/device_cfg.o -o ${OBJECTDIR}/MCAL_Layer/device_cfg.o MCAL_Layer/device_cfg.c 
	
${OBJECTDIR}/MCAL_Layer/Interrupt/hal_ext_interrupt.o: MCAL_Layer/Interrupt/hal_ext_interrupt.c  .generated_files/flags/default/83f18ca4895e66ba215d44e6df7ffc6ea2b0f2aa .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/hal_ext_interrupt.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/hal_ext_interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/Interrupt/hal_ext_interrupt.o.d" -MT "${OBJECTDIR}/MCAL_Layer/Interrupt/hal_ext_interrupt.o.d" -MT ${OBJECTDIR}/MCAL_Layer/Interrupt/hal_ext_interrupt.o -o ${OBJECTDIR}/MCAL_Layer/Interrupt/hal_ext_interrupt.o MCAL_Layer/Interrupt/hal_ext_interrupt.c 
	
${OBJECTDIR}/MCAL_Layer/Interrupt/hal_int_interrupt.o: MCAL_Layer/Interrupt/hal_int_interrupt.c  .generated_files/flags/default/43fb5df67cc43a8e130dc12919b3d7e6388a102e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/hal_int_interrupt.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/hal_int_interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/Interrupt/hal_int_interrupt.o.d" -MT "${OBJECTDIR}/MCAL_Layer/Interrupt/hal_int_interrupt.o.d" -MT ${OBJECTDIR}/MCAL_Layer/Interrupt/hal_int_interrupt.o -o ${OBJECTDIR}/MCAL_Layer/Interrupt/hal_int_interrupt.o MCAL_Layer/Interrupt/hal_int_interrupt.c 
	
${OBJECTDIR}/MCAL_Layer/Interrupt/hal_interrupt_mng.o: MCAL_Layer/Interrupt/hal_interrupt_mng.c  .generated_files/flags/default/eea2313e4285144a2cd3bb2dda6349540124f3a9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/hal_interrupt_mng.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/hal_interrupt_mng.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/Interrupt/hal_interrupt_mng.o.d" -MT "${OBJECTDIR}/MCAL_Layer/Interrupt/hal_interrupt_mng.o.d" -MT ${OBJECTDIR}/MCAL_Layer/Interrupt/hal_interrupt_mng.o -o ${OBJECTDIR}/MCAL_Layer/Interrupt/hal_interrupt_mng.o MCAL_Layer/Interrupt/hal_interrupt_mng.c 
	
${OBJECTDIR}/Codes/MCAL/Interrupt/app1.o: Codes/MCAL/Interrupt/app1.c  .generated_files/flags/default/c1a5469aa45818ecfc0eeba84f761b3f1ff828d5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/Codes/MCAL/Interrupt" 
	@${RM} ${OBJECTDIR}/Codes/MCAL/Interrupt/app1.o.d 
	@${RM} ${OBJECTDIR}/Codes/MCAL/Interrupt/app1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/Codes/MCAL/Interrupt/app1.o.d" -MT "${OBJECTDIR}/Codes/MCAL/Interrupt/app1.o.d" -MT ${OBJECTDIR}/Codes/MCAL/Interrupt/app1.o -o ${OBJECTDIR}/Codes/MCAL/Interrupt/app1.o Codes/MCAL/Interrupt/app1.c 
	
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
${DISTDIR}/MCU_ATMEGA32_Drivers.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/MCU_ATMEGA32_Drivers.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"   -gdwarf-2 -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -gdwarf-3 -mno-const-data-in-progmem     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/MCU_ATMEGA32_Drivers.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o ${DISTDIR}/MCU_ATMEGA32_Drivers.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group  -Wl,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1
	@${RM} ${DISTDIR}/MCU_ATMEGA32_Drivers.X.${IMAGE_TYPE}.hex 
	
	
else
${DISTDIR}/MCU_ATMEGA32_Drivers.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/MCU_ATMEGA32_Drivers.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -gdwarf-3 -mno-const-data-in-progmem     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/MCU_ATMEGA32_Drivers.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o ${DISTDIR}/MCU_ATMEGA32_Drivers.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}/avr-objcopy -O ihex "${DISTDIR}/MCU_ATMEGA32_Drivers.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "${DISTDIR}/MCU_ATMEGA32_Drivers.X.${IMAGE_TYPE}.hex"
	
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
