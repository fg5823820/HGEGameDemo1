#pragma once

#include <stdio.h>
#include <math.h>
#include <vector>
#include <hge.h>
#include <hgesprite.h>
#include <hgerect.h>
#include "hgeresource.h"
#include <hgegui.h>
//#include <hgecollision.h>


#define SCREEN_WIDTH	1024
#define SCREEN_HEIGHT	576
#define NONE			-1

#define OFF_SET	45

#define SCRIPTNAME		"ResScript.txt"		//脚本名
#define GAMEICON		"dust.ico"			//图标名
#define LOGNAME			"hgeRPG.log"		//LOG文件名
#define TITLE			"RPGTest"			//窗口名

const hgeRect Sence_Rect(256+OFF_SET, 32+OFF_SET, 768-OFF_SET, 544-OFF_SET);

#include "Global.h"






