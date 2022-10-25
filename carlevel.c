#include "cprocessing.h"
#include <stdio.h>
#include "utils.h"
#include <math.h>
#include "mainmenu.h"

int car_select;

#define SPEED 5

struct shapes {
	float x;
	float y;
	float degree;
	float diameter;
};
typedef struct shapes enemy;
typedef struct shapes player;
	enemy enemy_arr[3];
	player player_setting;

void Car_Level_Init()
{
	car_select = 0;
	for (int i = 0; i < 3; ++i) {
		enemy_arr[i].x = 100;
		enemy_arr[i].y = 100 + 100*i;
		enemy_arr[i].diameter = 50.0f;
		enemy_arr[i].degree = 0;
	}
	player_setting.x = 200;
	player_setting.y = 200;
	player_setting.degree = 0;
	player_setting.diameter = 50.0f;
}

void Car_Level_Update()
{
	//CP_Color color_arr[3] = { CP_Color_Create(255, 0, 0, 255), CP_Color_Create(0, 255, 0, 255), CP_Color_Create(0, 0, 255, 255) };

	CP_Graphics_ClearBackground(CP_Color_Create(128, 128, 128, 255));

	//for (int i = 0; i < 3; i++)
	//{
		CP_Settings_Fill(CP_Color_Create(0, 0, 255, 255));
		CP_Graphics_DrawCircle(player_setting.x, player_setting.y, player_setting.diameter);
		CP_Graphics_DrawTriangleAdvanced(player_setting.x - 10, player_setting.y - 15, player_setting.x - 10, player_setting.y + 15, player_setting.x + 25, player_setting.y, player_setting.degree);
	//}

	//int car1 = IsCircleClicked(car_arr[0].x, car_arr[0].y, car_arr[0].diameter, CP_Input_GetMouseX(), CP_Input_GetMouseY());
	//int car2 = IsCircleClicked(car_arr[1].x, car_arr[1].y, car_arr[1].diameter, CP_Input_GetMouseX(), CP_Input_GetMouseY());
	//int car3 = IsCircleClicked(car_arr[2].x, car_arr[2].y, car_arr[2].diameter, CP_Input_GetMouseX(), CP_Input_GetMouseY());
	
	//if (CP_Input_MouseClicked()) {
	//	if (car1 == 1) {
	//		car_select = 0;
	//	}
	//	else if (car2 == 1) {
	//		car_select = 1;
	//	}
	//	else if (car3 == 1) {
	//		car_select = 2;
	//	}
	//}

	float mouse_x = CP_Input_GetMouseX();
	float mouse_y = CP_Input_GetMouseY();
	CP_Vector vector = AngleToVector(player_setting.degree);
	CP_Vector n_vector = NormalVector(vector);
	//CP_Vector vec_mouse = CP_Vector_Set(mouse_x - car_arr[car_select].x, mouse_y - car_arr[car_select].y);
	//float angle = CP_Vector_Angle(vec_mouse, vector);
	float angle = PointDirection(player_setting.x, player_setting.y, mouse_x, mouse_y);
	player_setting.degree = angle;


	if (CP_Input_KeyDown(KEY_D))
	{
		/*player_setting.x -= n_vector.x * SPEED;
		player_setting.y -= n_vector.y * SPEED;*/
		player_setting.x += SPEED;
	}
	
	if (CP_Input_KeyDown(KEY_A))
	{
		/*player_setting.x += n_vector.x * SPEED;
		player_setting.y += n_vector.y * SPEED;*/
		player_setting.x -= SPEED;
	}
	if (CP_Input_KeyDown(KEY_W))
	{
		/*player_setting.x += vector.x * SPEED;
		player_setting.y += vector.y * SPEED;*/
		player_setting.y -= SPEED;
	}
	if (CP_Input_KeyDown(KEY_S))
	{
		/*player_setting.x -= vector.x * SPEED;
		player_setting.y -= vector.y * SPEED;*/
		player_setting.y += SPEED;
	}

	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Graphics_DrawLine(250, 100, 250, 250);
}

void Car_Leve_Exit()
{

}
