################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Item.cpp \
../Row.cpp \
../Table.cpp \
../main.cpp 

OBJS += \
./Item.o \
./Row.o \
./Table.o \
./main.o 

CPP_DEPS += \
./Item.d \
./Row.d \
./Table.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -I"C:\Users\matth\ECLIPSE PROJECTS\jsoncpp\include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


