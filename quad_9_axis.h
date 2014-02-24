

#ifndef QUAD_9_AXIS_H
#define QUAD_9_AXIS_H

#include "quad_common.h"
#include "inc/hw_i2c.h"
#include "driverlib/i2c.h"
#include "driverlib/uart.h"

#define MAGNETO_MIN_VAL	-1200	// (micro Teslas)
#define MAGNETO_MAX_VAL	 1200	
#define ACCEL_MIN_VAL	-4		// (g == 9.81 m/s^2)
#define ACCEL_MAX_VAL	 4		
#define GYRO_MIN_VAL	-500	// (degrees / sec)
#define GYRO_MAX_VAL	 500	

#define FS_SEL_1				// For setting the range of the Gyroscope
#define AFS_SEL_1				// For setting the range of the Accelerometer

typedef struct NineAxisRawReadings {
	int16_t gyro_x;
	int16_t gyro_y;
	int16_t gyro_z;
	int16_t accel_x;
	int16_t accel_y;
	int16_t accel_z;
	int16_t magneto_x;
	int16_t magneto_y;
	int16_t magneto_z;
} NineAxisRaw;

typedef struct NineAxisUI32Readings {
	uint32_t gyro_x;
	uint32_t gyro_y;
	uint32_t gyro_z;
	uint32_t accel_x;
	uint32_t accel_y;
	uint32_t accel_z;
	uint32_t magneto_x;
	uint32_t magneto_y;
	uint32_t magneto_z;
} NineAxisUI32;

typedef struct NineAxisFloatReadings {
	float gyro_x;
	float gyro_y;
	float gyro_z;
	float accel_x;
	float accel_y;
	float accel_z;
	float magneto_x;
	float magneto_y;
	float magneto_z;
} NineAxisFloat;

// Kalman Filter Structs
	// Previous
	// Current

// Euler Angle Orientation Struct
	// Roll Angle
	// Pitch Angle
	// Yaw Angle
	// Current
	// Desired
	// Compensation

void quad_9_axis_init();
void quad_9_axis_read_raw_data();
void quad_9_axis_get_float_datat();
void quad_9_axis_get_uint32_data();
void quad_9_axis_get_euler_angles();

void quad_9_axis_kalman_filter();
void quad_9_axis_calc_compensation();

#endif //QUAD_9_AXIS_H