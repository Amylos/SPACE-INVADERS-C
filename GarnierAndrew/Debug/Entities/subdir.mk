################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Entities/alien.c \
../Entities/rocket.c \
../Entities/ship.c 

OBJS += \
./Entities/alien.o \
./Entities/rocket.o \
./Entities/ship.o 

C_DEPS += \
./Entities/alien.d \
./Entities/rocket.d \
./Entities/ship.d 


# Each subdirectory must supply rules for building sources it contributes
Entities/%.o: ../Entities/%.c Entities/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"C:\Users\Garnier\Desktop\Programmation\C\DM_SPACE\GarnierAndrew\Entities" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


