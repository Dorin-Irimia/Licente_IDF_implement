/*******************************************************************************
 * COPYRIGHT (C) VITESCO TECHNOLOGIES
 * ALL RIGHTS RESERVED.
 *
 * The reproduction, transmission or use of this document or its
 * contents is not permitted without express written authority.
 * Offenders will be liable for damages. All rights, including rights
 * created by patent grant or registration of a utility model or design,
 * are reserved.
 ******************************************************************************/

#include "BSW/HAL/Com/com.h"

#include "BSW/MCAL/WIFI/wifi.h"
#include "ASW/Trunk/trunk.h"
static const char *TAG = "HAL COM";

 extern char *POI_slide ;
 extern uint8_t index_red = 0;
extern uint8_t index_blue = 0;
 // extern uint16_t var_Slide ;

extern char g_cGETBuffer[100];
extern char g_cPOSTBuffer[100];

extern bool g_bGETRequestInProcess;
extern bool g_bPOSTRequestInProcess;


/* Assign some default values to GET buffer */
COM_GET_struct g_GET_DataStructure =
{ .u8Temperature = 27, .u8Humidity = 50, .u8Comfort = 24, .bIsLocked = true,
		.bIsOccupied = false  };

/* Assign some default values to POST buffer */
COM_POST_struct g_POST_DataStructure =
{ .bButtonFan = false, .bButtonRun = false, .bButtonBlueExe = false, .bButtonRedExe = false,
 .bButtonLights = false,
		.bButtonLightsState = false, .bButtonFindMyCar = false,
		.bButtonHonk = false, .bButtonSecurity = false, .bButtonDoorLock = false,
		.u8UserTemperature = 27, .u16S1Val = 90, .u16S2Val = 90,
		.u16S3Val = 90, .u16S4Val = 90, .u16S5Val = 90, .u16S6Val = 90};



/*******************************************************************************
 *  Function name    : COM_vProcessGetRequest
 *
 *  Description      : Update the GET buffer
 *
 *  List of arguments: -
 *
 *  Return value     : -
 *
 ******************************************************************************/
void COM_vProcessGetRequest(void)
{
	if (g_bGETRequestInProcess)
	{
		char dataBuffer[6];

		sprintf(dataBuffer, "%d", g_GET_DataStructure.u8Temperature);
		/* First string to be copied to buffer */
		strcpy(g_cGETBuffer, dataBuffer);
		strcat(g_cGETBuffer, "\n");

		sprintf(dataBuffer, "%d", g_GET_DataStructure.u8Humidity);
		strcat(g_cGETBuffer, dataBuffer);
		strcat(g_cGETBuffer, "\n");

		sprintf(dataBuffer, "%d", g_GET_DataStructure.u8Comfort);
		strcat(g_cGETBuffer, dataBuffer);
		strcat(g_cGETBuffer, "\n");

		sprintf(dataBuffer, "%d", g_GET_DataStructure.u16PhotoRes);
		strcat(g_cGETBuffer, dataBuffer);
		strcat(g_cGETBuffer, "\n");
		


		if (g_GET_DataStructure.bIsLocked)
		{
			strcat(g_cGETBuffer, "locked\n");
		}
		else
		{
			strcat(g_cGETBuffer, "unlocked\n");
		}

		if (g_GET_DataStructure.bIsOccupied)
		{
			strcat(g_cGETBuffer, "occupied\n");
		}
		else
		{
			strcat(g_cGETBuffer, "unoccupied\n");
		}

		g_bGETRequestInProcess = false;
	}
}

/*******************************************************************************
 *  Function name    : COM_vProcessPostRequest
 *
 *  Description      : Process the POST buffer
 *
 *  List of arguments: -
 *
 *  Return value     : -
 *
 ******************************************************************************/
void COM_vProcessPostRequest(void)
{
	if (g_bPOSTRequestInProcess)
	{

		// Servo move comands

		if (strcmp(g_cPOSTBuffer, "button=S1_LEFT") == 0)
		{
			if(g_POST_DataStructure.u16S1Val > 0)
			g_POST_DataStructure.u16S1Val = g_POST_DataStructure.u16S1Val - 10;
		}
		else if (strcmp(g_cPOSTBuffer, "button=S1_RIGHT") == 0)
		{
			if(g_POST_DataStructure.u16S1Val < 180)
			g_POST_DataStructure.u16S1Val = g_POST_DataStructure.u16S1Val + 10;
		}

		else if (strcmp(g_cPOSTBuffer, "button=S2_LEFT") == 0)
		{
				if(g_POST_DataStructure.u16S2Val > 0)
			g_POST_DataStructure.u16S2Val = g_POST_DataStructure.u16S2Val - 10;

		}
		else if (strcmp(g_cPOSTBuffer, "button=S2_RIGHT") == 0)
		{
			if(g_POST_DataStructure.u16S2Val < 180)
			g_POST_DataStructure.u16S2Val = g_POST_DataStructure.u16S2Val + 10;
		}

		else if (strcmp(g_cPOSTBuffer, "button=S3_LEFT") == 0)
		{
			if(g_POST_DataStructure.u16S3Val > 0)
			g_POST_DataStructure.u16S3Val = g_POST_DataStructure.u16S3Val - 10;
			
		}
		else if (strcmp(g_cPOSTBuffer, "button=S3_RIGHT") == 0)
		{
			if(g_POST_DataStructure.u16S3Val < 180)
			g_POST_DataStructure.u16S3Val = g_POST_DataStructure.u16S3Val + 10;
		}

			else if (strcmp(g_cPOSTBuffer, "button=S4_LEFT") == 0)
		{
			if(g_POST_DataStructure.u16S4Val > 0)
			g_POST_DataStructure.u16S4Val = g_POST_DataStructure.u16S4Val - 10;
			
		}
		else if (strcmp(g_cPOSTBuffer, "button=S4_RIGHT") == 0)
		{
			if(g_POST_DataStructure.u16S4Val < 180)
			g_POST_DataStructure.u16S4Val = g_POST_DataStructure.u16S4Val + 10;
		}

			else if (strcmp(g_cPOSTBuffer, "button=S5_LEFT") == 0)
		{
			if(g_POST_DataStructure.u16S5Val > 0)
			g_POST_DataStructure.u16S5Val = g_POST_DataStructure.u16S5Val - 10;
			
		}
		else if (strcmp(g_cPOSTBuffer, "button=S5_RIGHT") == 0)
		{
			if(g_POST_DataStructure.u16S5Val < 180)
			g_POST_DataStructure.u16S5Val = g_POST_DataStructure.u16S5Val + 10;
		}

			else if (strcmp(g_cPOSTBuffer, "button=S6_LEFT") == 0)
		{
			if(g_POST_DataStructure.u16S6Val > 0)
			g_POST_DataStructure.u16S6Val = g_POST_DataStructure.u16S6Val - 10;
			
		}
		else if (strcmp(g_cPOSTBuffer, "button=S6_RIGHT") == 0)
		{
			if(g_POST_DataStructure.u16S6Val < 180)
			g_POST_DataStructure.u16S6Val = g_POST_DataStructure.u16S6Val + 10;
		}

		// save pozition for color

		else if (strcmp(g_cPOSTBuffer, "button=Save_red") == 0)
		{
			if(index_red < 99)
			{
				g_POST_DataStructure.u16StoragePozRed[index_red]= g_POST_DataStructure.u16S1Val;
				index_red++;
				g_POST_DataStructure.u16StoragePozRed[index_red]= g_POST_DataStructure.u16S2Val+1000;
				index_red++;
				g_POST_DataStructure.u16StoragePozRed[index_red]= g_POST_DataStructure.u16S3Val+2000;
				index_red++;  
				g_POST_DataStructure.u16StoragePozRed[index_red]= g_POST_DataStructure.u16S4Val+3000;
				index_red++;
				g_POST_DataStructure.u16StoragePozRed[index_red]= g_POST_DataStructure.u16S5Val+4000;
				index_red++;
				g_POST_DataStructure.u16StoragePozRed[index_red]= g_POST_DataStructure.u16S6Val+5000;
				index_red++;
			}
		}

		else if (strcmp(g_cPOSTBuffer, "button=Save_blue") == 0)
		{
			if(index_red < 99)
			{
				g_POST_DataStructure.u16StoragePozBlue[index_blue]= g_POST_DataStructure.u16S1Val;
				index_blue++;
				g_POST_DataStructure.u16StoragePozBlue[index_blue]= g_POST_DataStructure.u16S2Val+1000;
				index_blue++;
				g_POST_DataStructure.u16StoragePozBlue[index_blue]= g_POST_DataStructure.u16S3Val+2000;
				index_blue++;  
				g_POST_DataStructure.u16StoragePozBlue[index_blue]= g_POST_DataStructure.u16S4Val+3000;
				index_blue++;
				g_POST_DataStructure.u16StoragePozBlue[index_blue]= g_POST_DataStructure.u16S5Val+4000;
				index_blue++;
				g_POST_DataStructure.u16StoragePozBlue[index_blue]= g_POST_DataStructure.u16S6Val+5000;
				index_blue++;
			}
		}
		
		// clear storage movements

		else if (strcmp(g_cPOSTBuffer, "button=Clear_red") == 0)
		{
			 memset(g_POST_DataStructure.u16StoragePozRed,90,sizeof(g_POST_DataStructure.u16StoragePozRed));
		}
		else if (strcmp(g_cPOSTBuffer, "button=Clear_blue") == 0)
		{
			 memset(g_POST_DataStructure.u16StoragePozBlue,90,sizeof(g_POST_DataStructure.u16StoragePozBlue));
		}

		// run movement

		else if (strcmp(g_cPOSTBuffer, "button=Run") == 0)
		{
			g_POST_DataStructure.bButtonRun = true;
		}
		else if (strcmp(g_cPOSTBuffer, "button=Stop") == 0)
		{
			g_POST_DataStructure.bButtonRun = false;
		}

		// color execution
		else if (strcmp(g_cPOSTBuffer, "button=red exe") == 0)
		{
			g_POST_DataStructure.bButtonRedExe= true;
		}
			else if (strcmp(g_cPOSTBuffer, "button=blue exe") == 0) // de verificat daca merge cu spatiu sau trebuie + in nume .. blue+exe ..
		{
			g_POST_DataStructure.bButtonBlueExe= true; //dupa finalizarea functiei trebuie sa il punem pe false
		}

			// for lights commands

		else if (strcmp(g_cPOSTBuffer, "button=Lights auto") == 0)
		{
			g_POST_DataStructure.bButtonLightsState = true;
		}
		else if (strcmp(g_cPOSTBuffer, "button=Lights on") == 0)
		{
			g_POST_DataStructure.bButtonLights = true;
		}
		else if (strcmp(g_cPOSTBuffer, "button=Lights off") == 0)
		{
			g_POST_DataStructure.bButtonLights = false;
			g_POST_DataStructure.bButtonLightsState = false;
		}

		else if (strstr(g_cPOSTBuffer, "user-temp=") != NULL)
		{
			g_POST_DataStructure.u8UserTemperature = (g_cPOSTBuffer[10] - '0')
					* 10;
			g_POST_DataStructure.u8UserTemperature += g_cPOSTBuffer[11] - '0';
		}

			else if (strstr(g_cPOSTBuffer, "user-srv") != NULL)
		{
			POI_slide = strchr(g_cPOSTBuffer, '=');
		}	

		else
		{
			ESP_LOGI(TAG, "Not known");
		}

		g_bPOSTRequestInProcess = false;
	}
}

/*******************************************************************************
 *  Function name    : COM_vTaskProcessServer
 *
 *  Description      : Process POST/GET requests
 *
 *  List of arguments: -
 *
 *  Return value     : -
 *
 ******************************************************************************/
void COM_vTaskProcessServer(void)
{
	COM_vProcessGetRequest();
	COM_vProcessPostRequest();
}

	

