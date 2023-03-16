#include "ASW/Write_Movements/write_movement.h"

static const char *TAG = "ASW WRITE MOVEMENT";

void autorun(void)
{
	
		uint8_t var=0;
    if(g_POST_DataStructure.bButtonRedExe)
    {
		while(var < index_Red)
		{
			if(g_POST_DataStructure.u16StoragePoz[var]<200)
			{
				g_POST_DataStructure.u16S1Val =	g_POST_DataStructure.u16StoragePozRed[var];
				var++;
			}
			if(200 < g_POST_DataStructure.u16StoragePozRed[var] && g_POST_DataStructure.u16StoragePozRed[var] < 1200)
			{
				g_POST_DataStructure.u16S2Val =	g_POST_DataStructure.u16StoragePozRed[var]-1000;
				var++;
			}
			if(1200 < g_POST_DataStructure.u16StoragePozRed[var] && g_POST_DataStructure.u16StoragePozRed[var] < 2200)
			{
				g_POST_DataStructure.u16S3Val =	g_POST_DataStructure.u16StoragePozRed[var]-2000;
				var++;
			}
			if(2200 < g_POST_DataStructure.u16StoragePozRed[var] && g_POST_DataStructure.u16StoragePozRed[var] < 3200)
			{
				g_POST_DataStructure.u16S4Val =	g_POST_DataStructure.u16StoragePozRed[var]-3000;
				var++;
			}
			if(3200 < g_POST_DataStructure.u16StoragePozRed[var] && g_POST_DataStructure.u16StoragePozRed[var] < 4200)
			{
				g_POST_DataStructure.u16S5Val =	g_POST_DataStructure.u16StoragePoz[var]-4000;
				var++;
			}
			if(4200 < g_POST_DataStructure.u16StoragePoz[var])
			{
				g_POST_DataStructure.u16S6Val =	g_POST_DataStructure.u16StoragePoz[var]-5000;
				var++;
			}
        }
        g_POST_DataStructure.bButtonRedExe = false;
        Run_struct.bObjectStatus = false;
    }

     if(g_POST_DataStructure.bButtonBlueExe)
    {
		while(var < index_Red)
		{
			if(g_POST_DataStructure.u16StoragePoz[var]<200)
			{
				g_POST_DataStructure.u16S1Val =	g_POST_DataStructure.u16StoragePozRed[var];
				var++;
			}
			if(200 < g_POST_DataStructure.u16StoragePozRed[var] && g_POST_DataStructure.u16StoragePozRed[var] < 1200)
			{
				g_POST_DataStructure.u16S2Val =	g_POST_DataStructure.u16StoragePozRed[var]-1000;
				var++;
			}
			if(1200 < g_POST_DataStructure.u16StoragePozRed[var] && g_POST_DataStructure.u16StoragePozRed[var] < 2200)
			{
				g_POST_DataStructure.u16S3Val =	g_POST_DataStructure.u16StoragePozRed[var]-2000;
				var++;
			}
			if(2200 < g_POST_DataStructure.u16StoragePozRed[var] && g_POST_DataStructure.u16StoragePozRed[var] < 3200)
			{
				g_POST_DataStructure.u16S4Val =	g_POST_DataStructure.u16StoragePozRed[var]-3000;
				var++;
			}
			if(3200 < g_POST_DataStructure.u16StoragePozRed[var] && g_POST_DataStructure.u16StoragePozRed[var] < 4200)
			{
				g_POST_DataStructure.u16S5Val =	g_POST_DataStructure.u16StoragePoz[var]-4000;
				var++;
			}
			if(4200 < g_POST_DataStructure.u16StoragePoz[var])
			{
				g_POST_DataStructure.u16S6Val =	g_POST_DataStructure.u16StoragePoz[var]-5000;
				var++;
			}
        }

        g_POST_DataStructure.bButtonBlueExe = false;
        Run_struct.bObjectStatus = false;
    }
		  	
}
	