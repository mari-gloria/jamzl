#include "cprocessing.h"
#include <stdio.h>
#include <math.h>
#define _USE_MATH_DEFINES

int IsAreaClicked(float area_center_x, float area_center_y, float area_width, float area_height, float click_x, float click_y)
{
	if (click_x > area_center_x && click_y > area_center_y && click_x < area_center_x + area_width && click_y < area_center_y + area_height) {
		return 1;
	}
	else
	{
		return 0;
	}
}

int IsCircleClicked(float circle_center_x, float circle_center_y, float diameter, float click_x, float click_y)
{
	float radius = diameter / 2;
	float vector_x = click_x - circle_center_x;
	float vector_y = click_y - circle_center_y;
	float distance = sqrt(pow(vector_x, 2) + pow(vector_y, 2));
	//float distance = CP_Math_Distance(circle_center_x, circle_center_y, click_x, click_y);
	if (distance<radius) {
		return 1;
	}
	else
	{
		return 0;
	}
	return 0;
}

CP_Vector AngleToVector(float radian_angle)
{	
	float x;
	float y;
	x = cos(CP_Math_Radians(radian_angle));
	y = sin(CP_Math_Radians(radian_angle));
    CP_Vector ret={x,y};
    return ret;
}

CP_Vector NormalVector(CP_Vector vector)
{
	float x = vector.x;
	float y = vector.y;
	CP_Vector n_vector = {y , -x};
	return n_vector;
}

//Returns an angle based on 2 points specified
float PointDirection(float x_origin, float y_origin, float x_pos, float y_pos)
{
	float deltaX = x_pos - x_origin;
	float deltaY = y_pos - y_origin;
	float theta_radians = atan2(deltaY, deltaX);
	return CP_Math_Degrees(theta_radians);
}