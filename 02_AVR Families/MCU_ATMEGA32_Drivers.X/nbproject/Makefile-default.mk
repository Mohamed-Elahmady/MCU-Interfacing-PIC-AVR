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
SOURCEFILES_QUOTED_IF_SPACED=Codes/GPIO/app1.c APP_Layer/main.c ECUAL_Layer/LED/ecual_led.c MCAL_Layer/GPIO/hal_gpio.c MCAL_Layer/device_cfg.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/Codes/GPIO/app1.o ${OBJECTDIR}/APP_Layer/main.o ${OBJECTDIR}/ECUAL_Layer/LED/ecual_led.o ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.o ${OBJECTDIR}/MCAL_Layer/device_cfg.o
POSSIBLE_DEPFILES=${OBJECTDIR}/Codes/GPIO/app1.o.d ${OBJECTDIR}/APP_Layer/main.o.d ${OBJECTDIR}/ECUAL_Layer/LED/ecual_led.o.d ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.o.d ${OBJECTDIR}/MCAL_Layer/device_cfg.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/Codes/GPIO/app1.o ${OBJECTDIR}/APP_Layer/main.o ${OBJECTDIR}/ECUAL_Layer/LED/ecual_led.o ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.o ${OBJECTDIR}/MCAL_Layer/device_cfg.o

# Source Files
SOURCEFILES=Codes/GPIO/app1.c APP_Layer/main.c ECUAL_Layer/LED/ecual_led.c MCAL_Layer/GPIO/hal_gpio.c MCAL_Layer/device_cfg.c



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
${OBJECTDIR}/Codes/GPIO/app1.o: Codes/GPIO/app1.c  .generated_files/flags/default/607cc667f716fed4c298c20b0e04f5e75308f272 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/Codes/GPIO" 
	@${RM} ${OBJECTDIR}/Codes/GPIO/app1.o.d 
	@${RM} ${OBJECTDIR}/Codes/GPIO/app1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/Codes/GPIO/app1.o.d" -MT "${OBJECTDIR}/Codes/GPIO/app1.o.d" -MT ${OBJECTDIR}/Codes/GPIO/app1.o -o ${OBJECTDIR}/Codes/GPIO/app1.o Codes/GPIO/app1.c 
	
${OBJECTDIR}/APP_Layer/main.o: APP_Layer/main.c  .generated_files/flags/default/9eb59cde2bcc36a2bd52a7d93a7cde9769e5f772 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/APP_Layer" 
	@${RM} ${OBJECTDIR}/APP_Layer/main.o.d 
	@${RM} ${OBJECTDIR}/APP_Layer/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/APP_Layer/main.o.d" -MT "${OBJECTDIR}/APP_Layer/main.o.d" -MT ${OBJECTDIR}/APP_Layer/main.o -o ${OBJECTDIR}/APP_Layer/main.o APP_Layer/main.c 
	
${OBJECTDIR}/ECUAL_Layer/LED/ecual_led.o: ECUAL_Layer/LED/ecual_led.c  .generated_files/flags/default/69cdc673f05d01b6c49eb23c8bdfa91054a2db27 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ECUAL_Layer/LED" 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/LED/ecual_led.o.d 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/LED/ecual_led.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/ECUAL_Layer/LED/ecual_led.o.d" -MT "${OBJECTDIR}/ECUAL_Layer/LED/ecual_led.o.d" -MT ${OBJECTDIR}/ECUAL_Layer/LED/ecual_led.o -o ${OBJECTDIR}/ECUAL_Layer/LED/ecual_led.o ECUAL_Layer/LED/ecual_led.c 
	
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
	
else
${OBJECTDIR}/Codes/GPIO/app1.o: Codes/GPIO/app1.c  .generated_files/flags/default/13b7e194bef298b6aa77c64dd3d15ee310513f8e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/Codes/GPIO" 
	@${RM} ${OBJECTDIR}/Codes/GPIO/app1.o.d 
	@${RM} ${OBJECTDIR}/Codes/GPIO/app1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/Codes/GPIO/app1.o.d" -MT "${OBJECTDIR}/Codes/GPIO/app1.o.d" -MT ${OBJECTDIR}/Codes/GPIO/app1.o -o ${OBJECTDIR}/Codes/GPIO/app1.o Codes/GPIO/app1.c 
	
${OBJECTDIR}/APP_Layer/main.o: APP_Layer/main.c  .generated_files/flags/default/16278fab76bb8b7f4c9e9f03b290bcb71cf51ae4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/APP_Layer" 
	@${RM} ${OBJECTDIR}/APP_Layer/main.o.d 
	@${RM} ${OBJECTDIR}/APP_Layer/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/APP_Layer/main.o.d" -MT "${OBJECTDIR}/APP_Layer/main.o.d" -MT ${OBJECTDIR}/APP_Layer/main.o -o ${OBJECTDIR}/APP_Layer/main.o APP_Layer/main.c 
	
${OBJECTDIR}/ECUAL_Layer/LED/ecual_led.o: ECUAL_Layer/LED/ecual_led.c  .generated_files/flags/default/d55326d45e469b80c88cf7cc93eba3865a2e943e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ECUAL_Layer/LED" 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/LED/ecual_led.o.d 
	@${RM} ${OBJECTDIR}/ECUAL_Layer/LED/ecual_led.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/ECUAL_Layer/LED/ecual_led.o.d" -MT "${OBJECTDIR}/ECUAL_Layer/LED/ecual_led.o.d" -MT ${OBJECTDIR}/ECUAL_Layer/LED/ecual_led.o -o ${OBJECTDIR}/ECUAL_Layer/LED/ecual_led.o ECUAL_Layer/LED/ecual_led.c 
	
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
