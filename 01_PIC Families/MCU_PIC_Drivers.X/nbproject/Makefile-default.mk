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
FINAL_IMAGE=${DISTDIR}/MCU_PIC_Drivers.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/MCU_PIC_Drivers.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=Codes/ECUAL/7SEG/app1.c Codes/ECUAL/7SEG/app2.c Codes/ECUAL/7SEG/app3.c Codes/ECUAL/7SEG/app4.c APP_Layer/app1.c Codes/ECUAL/CHR_LCD/app1.c Codes/ECUAL/Keypad/app1.c Codes/ECUAL/LED/app1.c Codes/ECUAL/Relay/app1.c Codes/MCAL/GPIO/app2.c Codes/MCAL/GPIO/app1.c Codes/MCAL/GPIO/app3.c APP_Layer/Main.c ECUAL_Layer/7SEG/ECUAL_7SEG.c ECUAL_Layer/BTN/ECUAL_BTN.c ECUAL_Layer/CHR_Lcd/GPIO_CHR_LCD.c ECUAL_Layer/DC_Motor/ECUAL_DC_MOTOR.c ECUAL_Layer/Keypad/ECUAL_KEYPAD.c ECUAL_Layer/LED/ECUAL_LED.c ECUAL_Layer/Relay/ECUAL_RELAY.c ECUAL_Layer/ECUAL_INIT.c MCAL_Layer/GPIO/HAL_GPIO.c MCAL_Layer/device_cfg.c Codes/ECUAL/CHR_LCD/app2.c Codes/ECUAL/CHR_LCD/app3.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/Codes/ECUAL/7SEG/app1.p1 ${OBJECTDIR}/Codes/ECUAL/7SEG/app2.p1 ${OBJECTDIR}/Codes/ECUAL/7SEG/app3.p1 ${OBJECTDIR}/Codes/ECUAL/7SEG/app4.p1 ${OBJECTDIR}/APP_Layer/app1.p1 ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app1.p1 ${OBJECTDIR}/Codes/ECUAL/Keypad/app1.p1 ${OBJECTDIR}/Codes/ECUAL/LED/app1.p1 ${OBJECTDIR}/Codes/ECUAL/Relay/app1.p1 ${OBJECTDIR}/Codes/MCAL/GPIO/app2.p1 ${OBJECTDIR}/Codes/MCAL/GPIO/app1.p1 ${OBJECTDIR}/Codes/MCAL/GPIO/app3.p1 ${OBJECTDIR}/APP_Layer/Main.p1 ${OBJECTDIR}/ECUAL_Layer/7SEG/ECUAL_7SEG.p1 ${OBJECTDIR}/ECUAL_Layer/BTN/ECUAL_BTN.p1 ${OBJECTDIR}/ECUAL_Layer/CHR_Lcd/GPIO_CHR_LCD.p1 ${OBJECTDIR}/ECUAL_Layer/DC_Motor/ECUAL_DC_MOTOR.p1 ${OBJECTDIR}/ECUAL_Layer/Keypad/ECUAL_KEYPAD.p1 ${OBJECTDIR}/ECUAL_Layer/LED/ECUAL_LED.p1 ${OBJECTDIR}/ECUAL_Layer/Relay/ECUAL_RELAY.p1 ${OBJECTDIR}/ECUAL_Layer/ECUAL_INIT.p1 ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1 ${OBJECTDIR}/MCAL_Layer/device_cfg.p1 ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app2.p1 ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app3.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/Codes/ECUAL/7SEG/app1.p1.d ${OBJECTDIR}/Codes/ECUAL/7SEG/app2.p1.d ${OBJECTDIR}/Codes/ECUAL/7SEG/app3.p1.d ${OBJECTDIR}/Codes/ECUAL/7SEG/app4.p1.d ${OBJECTDIR}/APP_Layer/app1.p1.d ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app1.p1.d ${OBJECTDIR}/Codes/ECUAL/Keypad/app1.p1.d ${OBJECTDIR}/Codes/ECUAL/LED/app1.p1.d ${OBJECTDIR}/Codes/ECUAL/Relay/app1.p1.d ${OBJECTDIR}/Codes/MCAL/GPIO/app2.p1.d ${OBJECTDIR}/Codes/MCAL/GPIO/app1.p1.d ${OBJECTDIR}/Codes/MCAL/GPIO/app3.p1.d ${OBJECTDIR}/APP_Layer/Main.p1.d ${OBJECTDIR}/ECUAL_Layer/7SEG/ECUAL_7SEG.p1.d ${OBJECTDIR}/ECUAL_Layer/BTN/ECUAL_BTN.p1.d ${OBJECTDIR}/ECUAL_Layer/CHR_Lcd/GPIO_CHR_LCD.p1.d ${OBJECTDIR}/ECUAL_Layer/DC_Motor/ECUAL_DC_MOTOR.p1.d ${OBJECTDIR}/ECUAL_Layer/Keypad/ECUAL_KEYPAD.p1.d ${OBJECTDIR}/ECUAL_Layer/LED/ECUAL_LED.p1.d ${OBJECTDIR}/ECUAL_Layer/Relay/ECUAL_RELAY.p1.d ${OBJECTDIR}/ECUAL_Layer/ECUAL_INIT.p1.d ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1.d ${OBJECTDIR}/MCAL_Layer/device_cfg.p1.d ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app2.p1.d ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app3.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/Codes/ECUAL/7SEG/app1.p1 ${OBJECTDIR}/Codes/ECUAL/7SEG/app2.p1 ${OBJECTDIR}/Codes/ECUAL/7SEG/app3.p1 ${OBJECTDIR}/Codes/ECUAL/7SEG/app4.p1 ${OBJECTDIR}/APP_Layer/app1.p1 ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app1.p1 ${OBJECTDIR}/Codes/ECUAL/Keypad/app1.p1 ${OBJECTDIR}/Codes/ECUAL/LED/app1.p1 ${OBJECTDIR}/Codes/ECUAL/Relay/app1.p1 ${OBJECTDIR}/Codes/MCAL/GPIO/app2.p1 ${OBJECTDIR}/Codes/MCAL/GPIO/app1.p1 ${OBJECTDIR}/Codes/MCAL/GPIO/app3.p1 ${OBJECTDIR}/APP_Layer/Main.p1 ${OBJECTDIR}/ECUAL_Layer/7SEG/ECUAL_7SEG.p1 ${OBJECTDIR}/ECUAL_Layer/BTN/ECUAL_BTN.p1 ${OBJECTDIR}/ECUAL_Layer/CHR_Lcd/GPIO_CHR_LCD.p1 ${OBJECTDIR}/ECUAL_Layer/DC_Motor/ECUAL_DC_MOTOR.p1 ${OBJECTDIR}/ECUAL_Layer/Keypad/ECUAL_KEYPAD.p1 ${OBJECTDIR}/ECUAL_Layer/LED/ECUAL_LED.p1 ${OBJECTDIR}/ECUAL_Layer/Relay/ECUAL_RELAY.p1 ${OBJECTDIR}/ECUAL_Layer/ECUAL_INIT.p1 ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1 ${OBJECTDIR}/MCAL_Layer/device_cfg.p1 ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app2.p1 ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app3.p1

# Source Files
SOURCEFILES=Codes/ECUAL/7SEG/app1.c Codes/ECUAL/7SEG/app2.c Codes/ECUAL/7SEG/app3.c Codes/ECUAL/7SEG/app4.c APP_Layer/app1.c Codes/ECUAL/CHR_LCD/app1.c Codes/ECUAL/Keypad/app1.c Codes/ECUAL/LED/app1.c Codes/ECUAL/Relay/app1.c Codes/MCAL/GPIO/app2.c Codes/MCAL/GPIO/app1.c Codes/MCAL/GPIO/app3.c APP_Layer/Main.c ECUAL_Layer/7SEG/ECUAL_7SEG.c ECUAL_Layer/BTN/ECUAL_BTN.c ECUAL_Layer/CHR_Lcd/GPIO_CHR_LCD.c ECUAL_Layer/DC_Motor/ECUAL_DC_MOTOR.c ECUAL_Layer/Keypad/ECUAL_KEYPAD.c ECUAL_Layer/LED/ECUAL_LED.c ECUAL_Layer/Relay/ECUAL_RELAY.c ECUAL_Layer/ECUAL_INIT.c MCAL_Layer/GPIO/HAL_GPIO.c MCAL_Layer/device_cfg.c Codes/ECUAL/CHR_LCD/app2.c Codes/ECUAL/CHR_LCD/app3.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/MCU_PIC_Drivers.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F46K20
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/Codes/ECUAL/7SEG/app1.p1: Codes/ECUAL/7SEG/app1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Codes/ECUAL/7SEG" 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/7SEG/app1.p1.d 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/7SEG/app1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Codes/ECUAL/7SEG/app1.p1 Codes/ECUAL/7SEG/app1.c 
	@-${MV} ${OBJECTDIR}/Codes/ECUAL/7SEG/app1.d ${OBJECTDIR}/Codes/ECUAL/7SEG/app1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Codes/ECUAL/7SEG/app1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Codes/ECUAL/7SEG/app2.p1: Codes/ECUAL/7SEG/app2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Codes/ECUAL/7SEG" 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/7SEG/app2.p1.d 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/7SEG/app2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Codes/ECUAL/7SEG/app2.p1 Codes/ECUAL/7SEG/app2.c 
	@-${MV} ${OBJECTDIR}/Codes/ECUAL/7SEG/app2.d ${OBJECTDIR}/Codes/ECUAL/7SEG/app2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Codes/ECUAL/7SEG/app2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Codes/ECUAL/7SEG/app3.p1: Codes/ECUAL/7SEG/app3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Codes/ECUAL/7SEG" 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/7SEG/app3.p1.d 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/7SEG/app3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Codes/ECUAL/7SEG/app3.p1 Codes/ECUAL/7SEG/app3.c 
	@-${MV} ${OBJECTDIR}/Codes/ECUAL/7SEG/app3.d ${OBJECTDIR}/Codes/ECUAL/7SEG/app3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Codes/ECUAL/7SEG/app3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Codes/ECUAL/7SEG/app4.p1: Codes/ECUAL/7SEG/app4.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Codes/ECUAL/7SEG" 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/7SEG/app4.p1.d 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/7SEG/app4.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Codes/ECUAL/7SEG/app4.p1 Codes/ECUAL/7SEG/app4.c 
	@-${MV} ${OBJECTDIR}/Codes/ECUAL/7SEG/app4.d ${OBJECTDIR}/Codes/ECUAL/7SEG/app4.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Codes/ECUAL/7SEG/app4.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/APP_Layer/app1.p1: APP_Layer/app1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/APP_Layer" 
	@${RM} ${OBJECTDIR}/APP_Layer/app1.p1.d 
	@${RM} ${OBJECTDIR}/APP_Layer/app1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/APP_Layer/app1.p1 APP_Layer/app1.c 
	@-${MV} ${OBJECTDIR}/APP_Layer/app1.d ${OBJECTDIR}/APP_Layer/app1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/APP_Layer/app1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app1.p1: Codes/ECUAL/CHR_LCD/app1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Codes/ECUAL/CHR_LCD" 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app1.p1.d 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app1.p1 Codes/ECUAL/CHR_LCD/app1.c 
	@-${MV} ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app1.d ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Codes/ECUAL/Keypad/app1.p1: Codes/ECUAL/Keypad/app1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Codes/ECUAL/Keypad" 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/Keypad/app1.p1.d 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/Keypad/app1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Codes/ECUAL/Keypad/app1.p1 Codes/ECUAL/Keypad/app1.c 
	@-${MV} ${OBJECTDIR}/Codes/ECUAL/Keypad/app1.d ${OBJECTDIR}/Codes/ECUAL/Keypad/app1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Codes/ECUAL/Keypad/app1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Codes/ECUAL/LED/app1.p1: Codes/ECUAL/LED/app1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Codes/ECUAL/LED" 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/LED/app1.p1.d 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/LED/app1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Codes/ECUAL/LED/app1.p1 Codes/ECUAL/LED/app1.c 
	@-${MV} ${OBJECTDIR}/Codes/ECUAL/LED/app1.d ${OBJECTDIR}/Codes/ECUAL/LED/app1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Codes/ECUAL/LED/app1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Codes/ECUAL/Relay/app1.p1: Codes/ECUAL/Relay/app1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Codes/ECUAL/Relay" 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/Relay/app1.p1.d 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/Relay/app1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Codes/ECUAL/Relay/app1.p1 Codes/ECUAL/Relay/app1.c 
	@-${MV} ${OBJECTDIR}/Codes/ECUAL/Relay/app1.d ${OBJECTDIR}/Codes/ECUAL/Relay/app1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Codes/ECUAL/Relay/app1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Codes/MCAL/GPIO/app2.p1: Codes/MCAL/GPIO/app2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Codes/MCAL/GPIO" 
	@${RM} ${OBJECTDIR}/Codes/MCAL/GPIO/app2.p1.d 
	@${RM} ${OBJECTDIR}/Codes/MCAL/GPIO/app2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Codes/MCAL/GPIO/app2.p1 Codes/MCAL/GPIO/app2.c 
	@-${MV} ${OBJECTDIR}/Codes/MCAL/GPIO/app2.d ${OBJECTDIR}/Codes/MCAL/GPIO/app2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Codes/MCAL/GPIO/app2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Codes/MCAL/GPIO/app1.p1: Codes/MCAL/GPIO/app1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Codes/MCAL/GPIO" 
	@${RM} ${OBJECTDIR}/Codes/MCAL/GPIO/app1.p1.d 
	@${RM} ${OBJECTDIR}/Codes/MCAL/GPIO/app1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Codes/MCAL/GPIO/app1.p1 Codes/MCAL/GPIO/app1.c 
	@-${MV} ${OBJECTDIR}/Codes/MCAL/GPIO/app1.d ${OBJECTDIR}/Codes/MCAL/GPIO/app1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Codes/MCAL/GPIO/app1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Codes/MCAL/GPIO/app3.p1: Codes/MCAL/GPIO/app3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Codes/MCAL/GPIO" 
	@${RM} ${OBJECTDIR}/Codes/MCAL/GPIO/app3.p1.d 
	@${RM} ${OBJECTDIR}/Codes/MCAL/GPIO/app3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Codes/MCAL/GPIO/app3.p1 Codes/MCAL/GPIO/app3.c 
	@-${MV} ${OBJECTDIR}/Codes/MCAL/GPIO/app3.d ${OBJECTDIR}/Codes/MCAL/GPIO/app3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Codes/MCAL/GPIO/app3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/APP_Layer/Main.p1: APP_Layer/Main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/APP_Layer" 
	@${RM} ${OBJECTDIR}/APP_Layer/Main.p1.d 
	@${RM} ${OBJECTDIR}/APP_Layer/Main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/APP_Layer/Main.p1 APP_Layer/Main.c 
	@-${MV} ${OBJECTDIR}/APP_Layer/Main.d ${OBJECTDIR}/APP_Layer/Main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/APP_Layer/Main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL_Layer/7SEG/ECUAL_7SEG.p1: ECUAL_Layer/7SEG/ECUAL_7SEG.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL_Layer/7SEG" 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/7SEG/ECUAL_7SEG.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/7SEG/ECUAL_7SEG.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL_Layer/7SEG/ECUAL_7SEG.p1 ECUAL_Layer/7SEG/ECUAL_7SEG.c 
	@-${MV} ${OBJECTDIR}/ECUAL_Layer/7SEG/ECUAL_7SEG.d ${OBJECTDIR}/ECUAL_Layer/7SEG/ECUAL_7SEG.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL_Layer/7SEG/ECUAL_7SEG.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL_Layer/BTN/ECUAL_BTN.p1: ECUAL_Layer/BTN/ECUAL_BTN.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL_Layer/BTN" 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/BTN/ECUAL_BTN.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/BTN/ECUAL_BTN.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL_Layer/BTN/ECUAL_BTN.p1 ECUAL_Layer/BTN/ECUAL_BTN.c 
	@-${MV} ${OBJECTDIR}/ECUAL_Layer/BTN/ECUAL_BTN.d ${OBJECTDIR}/ECUAL_Layer/BTN/ECUAL_BTN.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL_Layer/BTN/ECUAL_BTN.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL_Layer/CHR_Lcd/GPIO_CHR_LCD.p1: ECUAL_Layer/CHR_Lcd/GPIO_CHR_LCD.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL_Layer/CHR_Lcd" 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/CHR_Lcd/GPIO_CHR_LCD.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/CHR_Lcd/GPIO_CHR_LCD.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL_Layer/CHR_Lcd/GPIO_CHR_LCD.p1 ECUAL_Layer/CHR_Lcd/GPIO_CHR_LCD.c 
	@-${MV} ${OBJECTDIR}/ECUAL_Layer/CHR_Lcd/GPIO_CHR_LCD.d ${OBJECTDIR}/ECUAL_Layer/CHR_Lcd/GPIO_CHR_LCD.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL_Layer/CHR_Lcd/GPIO_CHR_LCD.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL_Layer/DC_Motor/ECUAL_DC_MOTOR.p1: ECUAL_Layer/DC_Motor/ECUAL_DC_MOTOR.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL_Layer/DC_Motor" 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/DC_Motor/ECUAL_DC_MOTOR.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/DC_Motor/ECUAL_DC_MOTOR.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL_Layer/DC_Motor/ECUAL_DC_MOTOR.p1 ECUAL_Layer/DC_Motor/ECUAL_DC_MOTOR.c 
	@-${MV} ${OBJECTDIR}/ECUAL_Layer/DC_Motor/ECUAL_DC_MOTOR.d ${OBJECTDIR}/ECUAL_Layer/DC_Motor/ECUAL_DC_MOTOR.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL_Layer/DC_Motor/ECUAL_DC_MOTOR.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL_Layer/Keypad/ECUAL_KEYPAD.p1: ECUAL_Layer/Keypad/ECUAL_KEYPAD.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL_Layer/Keypad" 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/Keypad/ECUAL_KEYPAD.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/Keypad/ECUAL_KEYPAD.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL_Layer/Keypad/ECUAL_KEYPAD.p1 ECUAL_Layer/Keypad/ECUAL_KEYPAD.c 
	@-${MV} ${OBJECTDIR}/ECUAL_Layer/Keypad/ECUAL_KEYPAD.d ${OBJECTDIR}/ECUAL_Layer/Keypad/ECUAL_KEYPAD.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL_Layer/Keypad/ECUAL_KEYPAD.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL_Layer/LED/ECUAL_LED.p1: ECUAL_Layer/LED/ECUAL_LED.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL_Layer/LED" 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/LED/ECUAL_LED.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/LED/ECUAL_LED.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL_Layer/LED/ECUAL_LED.p1 ECUAL_Layer/LED/ECUAL_LED.c 
	@-${MV} ${OBJECTDIR}/ECUAL_Layer/LED/ECUAL_LED.d ${OBJECTDIR}/ECUAL_Layer/LED/ECUAL_LED.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL_Layer/LED/ECUAL_LED.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL_Layer/Relay/ECUAL_RELAY.p1: ECUAL_Layer/Relay/ECUAL_RELAY.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL_Layer/Relay" 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/Relay/ECUAL_RELAY.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/Relay/ECUAL_RELAY.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL_Layer/Relay/ECUAL_RELAY.p1 ECUAL_Layer/Relay/ECUAL_RELAY.c 
	@-${MV} ${OBJECTDIR}/ECUAL_Layer/Relay/ECUAL_RELAY.d ${OBJECTDIR}/ECUAL_Layer/Relay/ECUAL_RELAY.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL_Layer/Relay/ECUAL_RELAY.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL_Layer/ECUAL_INIT.p1: ECUAL_Layer/ECUAL_INIT.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL_Layer" 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/ECUAL_INIT.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/ECUAL_INIT.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL_Layer/ECUAL_INIT.p1 ECUAL_Layer/ECUAL_INIT.c 
	@-${MV} ${OBJECTDIR}/ECUAL_Layer/ECUAL_INIT.d ${OBJECTDIR}/ECUAL_Layer/ECUAL_INIT.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL_Layer/ECUAL_INIT.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1: MCAL_Layer/GPIO/HAL_GPIO.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1 MCAL_Layer/GPIO/HAL_GPIO.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.d ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/device_cfg.p1: MCAL_Layer/device_cfg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/device_cfg.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/device_cfg.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/device_cfg.p1 MCAL_Layer/device_cfg.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/device_cfg.d ${OBJECTDIR}/MCAL_Layer/device_cfg.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/device_cfg.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app2.p1: Codes/ECUAL/CHR_LCD/app2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Codes/ECUAL/CHR_LCD" 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app2.p1.d 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app2.p1 Codes/ECUAL/CHR_LCD/app2.c 
	@-${MV} ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app2.d ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app3.p1: Codes/ECUAL/CHR_LCD/app3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Codes/ECUAL/CHR_LCD" 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app3.p1.d 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app3.p1 Codes/ECUAL/CHR_LCD/app3.c 
	@-${MV} ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app3.d ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/Codes/ECUAL/7SEG/app1.p1: Codes/ECUAL/7SEG/app1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Codes/ECUAL/7SEG" 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/7SEG/app1.p1.d 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/7SEG/app1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Codes/ECUAL/7SEG/app1.p1 Codes/ECUAL/7SEG/app1.c 
	@-${MV} ${OBJECTDIR}/Codes/ECUAL/7SEG/app1.d ${OBJECTDIR}/Codes/ECUAL/7SEG/app1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Codes/ECUAL/7SEG/app1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Codes/ECUAL/7SEG/app2.p1: Codes/ECUAL/7SEG/app2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Codes/ECUAL/7SEG" 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/7SEG/app2.p1.d 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/7SEG/app2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Codes/ECUAL/7SEG/app2.p1 Codes/ECUAL/7SEG/app2.c 
	@-${MV} ${OBJECTDIR}/Codes/ECUAL/7SEG/app2.d ${OBJECTDIR}/Codes/ECUAL/7SEG/app2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Codes/ECUAL/7SEG/app2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Codes/ECUAL/7SEG/app3.p1: Codes/ECUAL/7SEG/app3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Codes/ECUAL/7SEG" 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/7SEG/app3.p1.d 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/7SEG/app3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Codes/ECUAL/7SEG/app3.p1 Codes/ECUAL/7SEG/app3.c 
	@-${MV} ${OBJECTDIR}/Codes/ECUAL/7SEG/app3.d ${OBJECTDIR}/Codes/ECUAL/7SEG/app3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Codes/ECUAL/7SEG/app3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Codes/ECUAL/7SEG/app4.p1: Codes/ECUAL/7SEG/app4.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Codes/ECUAL/7SEG" 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/7SEG/app4.p1.d 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/7SEG/app4.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Codes/ECUAL/7SEG/app4.p1 Codes/ECUAL/7SEG/app4.c 
	@-${MV} ${OBJECTDIR}/Codes/ECUAL/7SEG/app4.d ${OBJECTDIR}/Codes/ECUAL/7SEG/app4.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Codes/ECUAL/7SEG/app4.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/APP_Layer/app1.p1: APP_Layer/app1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/APP_Layer" 
	@${RM} ${OBJECTDIR}/APP_Layer/app1.p1.d 
	@${RM} ${OBJECTDIR}/APP_Layer/app1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/APP_Layer/app1.p1 APP_Layer/app1.c 
	@-${MV} ${OBJECTDIR}/APP_Layer/app1.d ${OBJECTDIR}/APP_Layer/app1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/APP_Layer/app1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app1.p1: Codes/ECUAL/CHR_LCD/app1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Codes/ECUAL/CHR_LCD" 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app1.p1.d 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app1.p1 Codes/ECUAL/CHR_LCD/app1.c 
	@-${MV} ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app1.d ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Codes/ECUAL/Keypad/app1.p1: Codes/ECUAL/Keypad/app1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Codes/ECUAL/Keypad" 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/Keypad/app1.p1.d 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/Keypad/app1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Codes/ECUAL/Keypad/app1.p1 Codes/ECUAL/Keypad/app1.c 
	@-${MV} ${OBJECTDIR}/Codes/ECUAL/Keypad/app1.d ${OBJECTDIR}/Codes/ECUAL/Keypad/app1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Codes/ECUAL/Keypad/app1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Codes/ECUAL/LED/app1.p1: Codes/ECUAL/LED/app1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Codes/ECUAL/LED" 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/LED/app1.p1.d 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/LED/app1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Codes/ECUAL/LED/app1.p1 Codes/ECUAL/LED/app1.c 
	@-${MV} ${OBJECTDIR}/Codes/ECUAL/LED/app1.d ${OBJECTDIR}/Codes/ECUAL/LED/app1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Codes/ECUAL/LED/app1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Codes/ECUAL/Relay/app1.p1: Codes/ECUAL/Relay/app1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Codes/ECUAL/Relay" 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/Relay/app1.p1.d 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/Relay/app1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Codes/ECUAL/Relay/app1.p1 Codes/ECUAL/Relay/app1.c 
	@-${MV} ${OBJECTDIR}/Codes/ECUAL/Relay/app1.d ${OBJECTDIR}/Codes/ECUAL/Relay/app1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Codes/ECUAL/Relay/app1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Codes/MCAL/GPIO/app2.p1: Codes/MCAL/GPIO/app2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Codes/MCAL/GPIO" 
	@${RM} ${OBJECTDIR}/Codes/MCAL/GPIO/app2.p1.d 
	@${RM} ${OBJECTDIR}/Codes/MCAL/GPIO/app2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Codes/MCAL/GPIO/app2.p1 Codes/MCAL/GPIO/app2.c 
	@-${MV} ${OBJECTDIR}/Codes/MCAL/GPIO/app2.d ${OBJECTDIR}/Codes/MCAL/GPIO/app2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Codes/MCAL/GPIO/app2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Codes/MCAL/GPIO/app1.p1: Codes/MCAL/GPIO/app1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Codes/MCAL/GPIO" 
	@${RM} ${OBJECTDIR}/Codes/MCAL/GPIO/app1.p1.d 
	@${RM} ${OBJECTDIR}/Codes/MCAL/GPIO/app1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Codes/MCAL/GPIO/app1.p1 Codes/MCAL/GPIO/app1.c 
	@-${MV} ${OBJECTDIR}/Codes/MCAL/GPIO/app1.d ${OBJECTDIR}/Codes/MCAL/GPIO/app1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Codes/MCAL/GPIO/app1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Codes/MCAL/GPIO/app3.p1: Codes/MCAL/GPIO/app3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Codes/MCAL/GPIO" 
	@${RM} ${OBJECTDIR}/Codes/MCAL/GPIO/app3.p1.d 
	@${RM} ${OBJECTDIR}/Codes/MCAL/GPIO/app3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Codes/MCAL/GPIO/app3.p1 Codes/MCAL/GPIO/app3.c 
	@-${MV} ${OBJECTDIR}/Codes/MCAL/GPIO/app3.d ${OBJECTDIR}/Codes/MCAL/GPIO/app3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Codes/MCAL/GPIO/app3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/APP_Layer/Main.p1: APP_Layer/Main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/APP_Layer" 
	@${RM} ${OBJECTDIR}/APP_Layer/Main.p1.d 
	@${RM} ${OBJECTDIR}/APP_Layer/Main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/APP_Layer/Main.p1 APP_Layer/Main.c 
	@-${MV} ${OBJECTDIR}/APP_Layer/Main.d ${OBJECTDIR}/APP_Layer/Main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/APP_Layer/Main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL_Layer/7SEG/ECUAL_7SEG.p1: ECUAL_Layer/7SEG/ECUAL_7SEG.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL_Layer/7SEG" 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/7SEG/ECUAL_7SEG.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/7SEG/ECUAL_7SEG.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL_Layer/7SEG/ECUAL_7SEG.p1 ECUAL_Layer/7SEG/ECUAL_7SEG.c 
	@-${MV} ${OBJECTDIR}/ECUAL_Layer/7SEG/ECUAL_7SEG.d ${OBJECTDIR}/ECUAL_Layer/7SEG/ECUAL_7SEG.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL_Layer/7SEG/ECUAL_7SEG.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL_Layer/BTN/ECUAL_BTN.p1: ECUAL_Layer/BTN/ECUAL_BTN.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL_Layer/BTN" 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/BTN/ECUAL_BTN.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/BTN/ECUAL_BTN.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL_Layer/BTN/ECUAL_BTN.p1 ECUAL_Layer/BTN/ECUAL_BTN.c 
	@-${MV} ${OBJECTDIR}/ECUAL_Layer/BTN/ECUAL_BTN.d ${OBJECTDIR}/ECUAL_Layer/BTN/ECUAL_BTN.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL_Layer/BTN/ECUAL_BTN.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL_Layer/CHR_Lcd/GPIO_CHR_LCD.p1: ECUAL_Layer/CHR_Lcd/GPIO_CHR_LCD.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL_Layer/CHR_Lcd" 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/CHR_Lcd/GPIO_CHR_LCD.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/CHR_Lcd/GPIO_CHR_LCD.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL_Layer/CHR_Lcd/GPIO_CHR_LCD.p1 ECUAL_Layer/CHR_Lcd/GPIO_CHR_LCD.c 
	@-${MV} ${OBJECTDIR}/ECUAL_Layer/CHR_Lcd/GPIO_CHR_LCD.d ${OBJECTDIR}/ECUAL_Layer/CHR_Lcd/GPIO_CHR_LCD.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL_Layer/CHR_Lcd/GPIO_CHR_LCD.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL_Layer/DC_Motor/ECUAL_DC_MOTOR.p1: ECUAL_Layer/DC_Motor/ECUAL_DC_MOTOR.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL_Layer/DC_Motor" 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/DC_Motor/ECUAL_DC_MOTOR.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/DC_Motor/ECUAL_DC_MOTOR.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL_Layer/DC_Motor/ECUAL_DC_MOTOR.p1 ECUAL_Layer/DC_Motor/ECUAL_DC_MOTOR.c 
	@-${MV} ${OBJECTDIR}/ECUAL_Layer/DC_Motor/ECUAL_DC_MOTOR.d ${OBJECTDIR}/ECUAL_Layer/DC_Motor/ECUAL_DC_MOTOR.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL_Layer/DC_Motor/ECUAL_DC_MOTOR.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL_Layer/Keypad/ECUAL_KEYPAD.p1: ECUAL_Layer/Keypad/ECUAL_KEYPAD.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL_Layer/Keypad" 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/Keypad/ECUAL_KEYPAD.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/Keypad/ECUAL_KEYPAD.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL_Layer/Keypad/ECUAL_KEYPAD.p1 ECUAL_Layer/Keypad/ECUAL_KEYPAD.c 
	@-${MV} ${OBJECTDIR}/ECUAL_Layer/Keypad/ECUAL_KEYPAD.d ${OBJECTDIR}/ECUAL_Layer/Keypad/ECUAL_KEYPAD.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL_Layer/Keypad/ECUAL_KEYPAD.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL_Layer/LED/ECUAL_LED.p1: ECUAL_Layer/LED/ECUAL_LED.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL_Layer/LED" 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/LED/ECUAL_LED.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/LED/ECUAL_LED.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL_Layer/LED/ECUAL_LED.p1 ECUAL_Layer/LED/ECUAL_LED.c 
	@-${MV} ${OBJECTDIR}/ECUAL_Layer/LED/ECUAL_LED.d ${OBJECTDIR}/ECUAL_Layer/LED/ECUAL_LED.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL_Layer/LED/ECUAL_LED.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL_Layer/Relay/ECUAL_RELAY.p1: ECUAL_Layer/Relay/ECUAL_RELAY.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL_Layer/Relay" 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/Relay/ECUAL_RELAY.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/Relay/ECUAL_RELAY.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL_Layer/Relay/ECUAL_RELAY.p1 ECUAL_Layer/Relay/ECUAL_RELAY.c 
	@-${MV} ${OBJECTDIR}/ECUAL_Layer/Relay/ECUAL_RELAY.d ${OBJECTDIR}/ECUAL_Layer/Relay/ECUAL_RELAY.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL_Layer/Relay/ECUAL_RELAY.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL_Layer/ECUAL_INIT.p1: ECUAL_Layer/ECUAL_INIT.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL_Layer" 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/ECUAL_INIT.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/ECUAL_INIT.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL_Layer/ECUAL_INIT.p1 ECUAL_Layer/ECUAL_INIT.c 
	@-${MV} ${OBJECTDIR}/ECUAL_Layer/ECUAL_INIT.d ${OBJECTDIR}/ECUAL_Layer/ECUAL_INIT.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL_Layer/ECUAL_INIT.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1: MCAL_Layer/GPIO/HAL_GPIO.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1 MCAL_Layer/GPIO/HAL_GPIO.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.d ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/device_cfg.p1: MCAL_Layer/device_cfg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/device_cfg.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/device_cfg.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/device_cfg.p1 MCAL_Layer/device_cfg.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/device_cfg.d ${OBJECTDIR}/MCAL_Layer/device_cfg.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/device_cfg.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app2.p1: Codes/ECUAL/CHR_LCD/app2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Codes/ECUAL/CHR_LCD" 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app2.p1.d 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app2.p1 Codes/ECUAL/CHR_LCD/app2.c 
	@-${MV} ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app2.d ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app3.p1: Codes/ECUAL/CHR_LCD/app3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Codes/ECUAL/CHR_LCD" 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app3.p1.d 
	@${RM} ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app3.p1 Codes/ECUAL/CHR_LCD/app3.c 
	@-${MV} ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app3.d ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Codes/ECUAL/CHR_LCD/app3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
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
${DISTDIR}/MCU_PIC_Drivers.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/MCU_PIC_Drivers.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/MCU_PIC_Drivers.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/MCU_PIC_Drivers.X.${IMAGE_TYPE}.hex 
	
	
else
${DISTDIR}/MCU_PIC_Drivers.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/MCU_PIC_Drivers.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/MCU_PIC_Drivers.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
	
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
