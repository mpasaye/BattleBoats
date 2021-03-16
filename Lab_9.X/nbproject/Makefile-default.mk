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
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Lab_9.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Lab_9.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
<<<<<<< HEAD
SOURCEFILES_QUOTED_IF_SPACED=Ascii.c BOARD.c CircularBuffer.c Field.c FieldOled.c FieldTest.c Negotiation.c Oled.c OledDriver.c Uart1.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/Ascii.o ${OBJECTDIR}/BOARD.o ${OBJECTDIR}/CircularBuffer.o ${OBJECTDIR}/Field.o ${OBJECTDIR}/FieldOled.o ${OBJECTDIR}/FieldTest.o ${OBJECTDIR}/Negotiation.o ${OBJECTDIR}/Oled.o ${OBJECTDIR}/OledDriver.o ${OBJECTDIR}/Uart1.o
POSSIBLE_DEPFILES=${OBJECTDIR}/Ascii.o.d ${OBJECTDIR}/BOARD.o.d ${OBJECTDIR}/CircularBuffer.o.d ${OBJECTDIR}/Field.o.d ${OBJECTDIR}/FieldOled.o.d ${OBJECTDIR}/FieldTest.o.d ${OBJECTDIR}/Negotiation.o.d ${OBJECTDIR}/Oled.o.d ${OBJECTDIR}/OledDriver.o.d ${OBJECTDIR}/Uart1.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/Ascii.o ${OBJECTDIR}/BOARD.o ${OBJECTDIR}/CircularBuffer.o ${OBJECTDIR}/Field.o ${OBJECTDIR}/FieldOled.o ${OBJECTDIR}/FieldTest.o ${OBJECTDIR}/Negotiation.o ${OBJECTDIR}/Oled.o ${OBJECTDIR}/OledDriver.o ${OBJECTDIR}/Uart1.o

# Source Files
SOURCEFILES=Ascii.c BOARD.c CircularBuffer.c Field.c FieldOled.c FieldTest.c Negotiation.c Oled.c OledDriver.c Uart1.c
=======
SOURCEFILES_QUOTED_IF_SPACED=Agent.c Ascii.c BOARD.c CircularBuffer.c Field.c FieldOled.c FieldTest.c Negotiation.c Oled.c OledDriver.c Uart1.c Message.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/Agent.o ${OBJECTDIR}/Ascii.o ${OBJECTDIR}/BOARD.o ${OBJECTDIR}/CircularBuffer.o ${OBJECTDIR}/Field.o ${OBJECTDIR}/FieldOled.o ${OBJECTDIR}/FieldTest.o ${OBJECTDIR}/Negotiation.o ${OBJECTDIR}/Oled.o ${OBJECTDIR}/OledDriver.o ${OBJECTDIR}/Uart1.o ${OBJECTDIR}/Message.o
POSSIBLE_DEPFILES=${OBJECTDIR}/Agent.o.d ${OBJECTDIR}/Ascii.o.d ${OBJECTDIR}/BOARD.o.d ${OBJECTDIR}/CircularBuffer.o.d ${OBJECTDIR}/Field.o.d ${OBJECTDIR}/FieldOled.o.d ${OBJECTDIR}/FieldTest.o.d ${OBJECTDIR}/Negotiation.o.d ${OBJECTDIR}/Oled.o.d ${OBJECTDIR}/OledDriver.o.d ${OBJECTDIR}/Uart1.o.d ${OBJECTDIR}/Message.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/Agent.o ${OBJECTDIR}/Ascii.o ${OBJECTDIR}/BOARD.o ${OBJECTDIR}/CircularBuffer.o ${OBJECTDIR}/Field.o ${OBJECTDIR}/FieldOled.o ${OBJECTDIR}/FieldTest.o ${OBJECTDIR}/Negotiation.o ${OBJECTDIR}/Oled.o ${OBJECTDIR}/OledDriver.o ${OBJECTDIR}/Uart1.o ${OBJECTDIR}/Message.o

# Source Files
SOURCEFILES=Agent.c Ascii.c BOARD.c CircularBuffer.c Field.c FieldOled.c FieldTest.c Negotiation.c Oled.c OledDriver.c Uart1.c Message.c
>>>>>>> 27200c9d248933ca97f081f5ca97f98fb050751a



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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Lab_9.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX320F128H
MP_LINKER_FILE_OPTION=
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
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
<<<<<<< HEAD
${OBJECTDIR}/Ascii.o: Ascii.c  .generated_files/8cefa792ffef4f2e80045e5f5d0d5f7f62331670.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
=======
${OBJECTDIR}/Agent.o: Agent.c  .generated_files/e9919d9ef86dd3ecb0ec56cd5d442dd8a3a9ea36.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Agent.o.d 
	@${RM} ${OBJECTDIR}/Agent.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MP -MMD -MF "${OBJECTDIR}/Agent.o.d" -o ${OBJECTDIR}/Agent.o Agent.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Ascii.o: Ascii.c  .generated_files/a4af538d193209f9bbc8bc0fa99f8d130888539c.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
>>>>>>> 27200c9d248933ca97f081f5ca97f98fb050751a
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Ascii.o.d 
	@${RM} ${OBJECTDIR}/Ascii.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MP -MMD -MF "${OBJECTDIR}/Ascii.o.d" -o ${OBJECTDIR}/Ascii.o Ascii.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/BOARD.o: BOARD.c  .generated_files/41472d04de89e4a2b8c87a56b4ddb164bc872626.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
=======
${OBJECTDIR}/BOARD.o: BOARD.c  .generated_files/3638ed2ed16af6c97612e688aa914b6f75d91bcc.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
>>>>>>> 27200c9d248933ca97f081f5ca97f98fb050751a
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/BOARD.o.d 
	@${RM} ${OBJECTDIR}/BOARD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MP -MMD -MF "${OBJECTDIR}/BOARD.o.d" -o ${OBJECTDIR}/BOARD.o BOARD.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/CircularBuffer.o: CircularBuffer.c  .generated_files/3fd580c454851db55ecce633cb6697e1cd4ccd3e.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
=======
${OBJECTDIR}/CircularBuffer.o: CircularBuffer.c  .generated_files/6caee646a3facc8a310765478bdee2a617ff4366.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
>>>>>>> 27200c9d248933ca97f081f5ca97f98fb050751a
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/CircularBuffer.o.d 
	@${RM} ${OBJECTDIR}/CircularBuffer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MP -MMD -MF "${OBJECTDIR}/CircularBuffer.o.d" -o ${OBJECTDIR}/CircularBuffer.o CircularBuffer.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/Field.o: Field.c  .generated_files/4ae272a1e897d85064e421ebeb4a8559cff921ee.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
=======
${OBJECTDIR}/Field.o: Field.c  .generated_files/d9bc5a8748f43f48799e04173d172c933f089f6f.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
>>>>>>> 27200c9d248933ca97f081f5ca97f98fb050751a
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Field.o.d 
	@${RM} ${OBJECTDIR}/Field.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MP -MMD -MF "${OBJECTDIR}/Field.o.d" -o ${OBJECTDIR}/Field.o Field.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/FieldOled.o: FieldOled.c  .generated_files/37e9b82d31506256bc35aeed614fbf781db3f896.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
=======
${OBJECTDIR}/FieldOled.o: FieldOled.c  .generated_files/be83a5f8780f44dc65d4200949b583924170f62f.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
>>>>>>> 27200c9d248933ca97f081f5ca97f98fb050751a
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/FieldOled.o.d 
	@${RM} ${OBJECTDIR}/FieldOled.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MP -MMD -MF "${OBJECTDIR}/FieldOled.o.d" -o ${OBJECTDIR}/FieldOled.o FieldOled.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
<<<<<<< HEAD
	
${OBJECTDIR}/FieldTest.o: FieldTest.c  .generated_files/dad85c25acce613be2f5d1d5f4d3263374d1e67d.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/FieldTest.o.d 
	@${RM} ${OBJECTDIR}/FieldTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MP -MMD -MF "${OBJECTDIR}/FieldTest.o.d" -o ${OBJECTDIR}/FieldTest.o FieldTest.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
=======
>>>>>>> 27200c9d248933ca97f081f5ca97f98fb050751a
	
${OBJECTDIR}/FieldTest.o: FieldTest.c  .generated_files/5b948ae9d63ccc05eca0107fcd40c06d8302071f.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/FieldTest.o.d 
	@${RM} ${OBJECTDIR}/FieldTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MP -MMD -MF "${OBJECTDIR}/FieldTest.o.d" -o ${OBJECTDIR}/FieldTest.o FieldTest.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Negotiation.o: Negotiation.c  .generated_files/4a5ced023bd38ba61073bec8138e97e542e6215f.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Negotiation.o.d 
	@${RM} ${OBJECTDIR}/Negotiation.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MP -MMD -MF "${OBJECTDIR}/Negotiation.o.d" -o ${OBJECTDIR}/Negotiation.o Negotiation.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/Oled.o: Oled.c  .generated_files/f27861b47afc050295f6a5e1f3533ef7e63ca02b.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
=======
${OBJECTDIR}/Oled.o: Oled.c  .generated_files/1872034472ce25e6ad1058d51fb7daa8ce2e00b7.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
>>>>>>> 27200c9d248933ca97f081f5ca97f98fb050751a
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Oled.o.d 
	@${RM} ${OBJECTDIR}/Oled.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MP -MMD -MF "${OBJECTDIR}/Oled.o.d" -o ${OBJECTDIR}/Oled.o Oled.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/OledDriver.o: OledDriver.c  .generated_files/e62161d4f5bf59bcd8afe6c9eac013076e05b2b4.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
=======
${OBJECTDIR}/OledDriver.o: OledDriver.c  .generated_files/d7f9f915e49b28dfe4abfbbd4f0a951fd5d4384b.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
>>>>>>> 27200c9d248933ca97f081f5ca97f98fb050751a
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/OledDriver.o.d 
	@${RM} ${OBJECTDIR}/OledDriver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MP -MMD -MF "${OBJECTDIR}/OledDriver.o.d" -o ${OBJECTDIR}/OledDriver.o OledDriver.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/Uart1.o: Uart1.c  .generated_files/99a483d12df45a038d4313fa5446798d691952a8.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
=======
${OBJECTDIR}/Uart1.o: Uart1.c  .generated_files/b10913b50da41ee69a1c7bf20e96e183fe02ece1.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
>>>>>>> 27200c9d248933ca97f081f5ca97f98fb050751a
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Uart1.o.d 
	@${RM} ${OBJECTDIR}/Uart1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MP -MMD -MF "${OBJECTDIR}/Uart1.o.d" -o ${OBJECTDIR}/Uart1.o Uart1.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Message.o: Message.c  .generated_files/8a80f8dfca62302353a8bda425fda9bcdbd3a480.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Message.o.d 
	@${RM} ${OBJECTDIR}/Message.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MP -MMD -MF "${OBJECTDIR}/Message.o.d" -o ${OBJECTDIR}/Message.o Message.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
<<<<<<< HEAD
${OBJECTDIR}/Ascii.o: Ascii.c  .generated_files/a59b0be1f86eed56e02f1225259b8c38a34d8a39.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
=======
${OBJECTDIR}/Agent.o: Agent.c  .generated_files/3013d5f7f6a2a0b1793f1ed9eb9da86be59082c5.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Agent.o.d 
	@${RM} ${OBJECTDIR}/Agent.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MP -MMD -MF "${OBJECTDIR}/Agent.o.d" -o ${OBJECTDIR}/Agent.o Agent.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Ascii.o: Ascii.c  .generated_files/9a38090ae4e25b7e420cbc2154977ec96ba3caae.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
>>>>>>> 27200c9d248933ca97f081f5ca97f98fb050751a
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Ascii.o.d 
	@${RM} ${OBJECTDIR}/Ascii.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MP -MMD -MF "${OBJECTDIR}/Ascii.o.d" -o ${OBJECTDIR}/Ascii.o Ascii.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/BOARD.o: BOARD.c  .generated_files/c517aa15921eaa0d8da122abaf2a6e7c3618635c.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/BOARD.o.d 
	@${RM} ${OBJECTDIR}/BOARD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MP -MMD -MF "${OBJECTDIR}/BOARD.o.d" -o ${OBJECTDIR}/BOARD.o BOARD.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/CircularBuffer.o: CircularBuffer.c  .generated_files/f963621e4b22a99001ce8511a429acad4b1bbb36.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/CircularBuffer.o.d 
	@${RM} ${OBJECTDIR}/CircularBuffer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MP -MMD -MF "${OBJECTDIR}/CircularBuffer.o.d" -o ${OBJECTDIR}/CircularBuffer.o CircularBuffer.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Field.o: Field.c  .generated_files/cb97cc787d9bc9b9a7b7cae010a337127a24ca7a.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Field.o.d 
	@${RM} ${OBJECTDIR}/Field.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MP -MMD -MF "${OBJECTDIR}/Field.o.d" -o ${OBJECTDIR}/Field.o Field.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/FieldOled.o: FieldOled.c  .generated_files/8aa3fcf38026c16dd2083b3ff416bd49abec0ad8.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/FieldOled.o.d 
	@${RM} ${OBJECTDIR}/FieldOled.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MP -MMD -MF "${OBJECTDIR}/FieldOled.o.d" -o ${OBJECTDIR}/FieldOled.o FieldOled.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/FieldTest.o: FieldTest.c  .generated_files/4b0ff8780c7e77ccdf2b750d456841e899f279b6.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
=======
${OBJECTDIR}/FieldTest.o: FieldTest.c  .generated_files/12494b8e222bbc91286c495a0c14da04f0cbff.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
>>>>>>> 27200c9d248933ca97f081f5ca97f98fb050751a
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/FieldTest.o.d 
	@${RM} ${OBJECTDIR}/FieldTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MP -MMD -MF "${OBJECTDIR}/FieldTest.o.d" -o ${OBJECTDIR}/FieldTest.o FieldTest.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/Negotiation.o: Negotiation.c  .generated_files/cda542b3b6f98b83b096fda46773c7265b864a02.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
=======
${OBJECTDIR}/Negotiation.o: Negotiation.c  .generated_files/8121c2fde2cc4cf39714094fa349b7cc79e62391.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
>>>>>>> 27200c9d248933ca97f081f5ca97f98fb050751a
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Negotiation.o.d 
	@${RM} ${OBJECTDIR}/Negotiation.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MP -MMD -MF "${OBJECTDIR}/Negotiation.o.d" -o ${OBJECTDIR}/Negotiation.o Negotiation.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/Oled.o: Oled.c  .generated_files/18b2111b71953cc0a55b3aba8e49782b694d29.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
=======
${OBJECTDIR}/Oled.o: Oled.c  .generated_files/4c27fd3368e451f4d8f0296d3218cc5eb77f7f27.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
>>>>>>> 27200c9d248933ca97f081f5ca97f98fb050751a
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Oled.o.d 
	@${RM} ${OBJECTDIR}/Oled.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MP -MMD -MF "${OBJECTDIR}/Oled.o.d" -o ${OBJECTDIR}/Oled.o Oled.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/OledDriver.o: OledDriver.c  .generated_files/30a194b7b4171c406bdb90631212eedf3d69f4cb.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/OledDriver.o.d 
	@${RM} ${OBJECTDIR}/OledDriver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MP -MMD -MF "${OBJECTDIR}/OledDriver.o.d" -o ${OBJECTDIR}/OledDriver.o OledDriver.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Uart1.o: Uart1.c  .generated_files/6c16478562d8bd47dc1334d73b82ab23731d8a42.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Uart1.o.d 
	@${RM} ${OBJECTDIR}/Uart1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MP -MMD -MF "${OBJECTDIR}/Uart1.o.d" -o ${OBJECTDIR}/Uart1.o Uart1.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Message.o: Message.c  .generated_files/2a3f33ce00520337f20761e945c52ea32d857c27.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Message.o.d 
	@${RM} ${OBJECTDIR}/Message.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Wall -MP -MMD -MF "${OBJECTDIR}/Message.o.d" -o ${OBJECTDIR}/Message.o Message.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
<<<<<<< HEAD
dist/${CND_CONF}/${IMAGE_TYPE}/Lab_9.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  Lab9SupportLib.a Agent_correct.o Message_correct.o  
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Lab_9.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    Lab9SupportLib.a Agent_correct.o Message_correct.o      -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_PK3=1,--defsym=_min_heap_size=200,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Lab_9.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  Lab9SupportLib.a Agent_correct.o Message_correct.o 
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Lab_9.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    Lab9SupportLib.a Agent_correct.o Message_correct.o      -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=200,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
=======
dist/${CND_CONF}/${IMAGE_TYPE}/Lab_9.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  Lab9SupportLib.a  
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Lab_9.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    Lab9SupportLib.a      -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_PK3=1,--defsym=_min_heap_size=200,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Lab_9.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  Lab9SupportLib.a 
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Lab_9.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    Lab9SupportLib.a      -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=200,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
>>>>>>> 27200c9d248933ca97f081f5ca97f98fb050751a
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Lab_9.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
