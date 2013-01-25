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

#define SCRIPTNAME		"ResScript.txt"		//�ű���
#define GAMEICON		"dust.ico"			//ͼ����
#define LOGNAME			"hgeRPG.log"		//LOG�ļ���
#define TITLE			"RPGTest"			//������

const hgeRect Sence_Rect(256+OFF_SET, 32+OFF_SET, 768-OFF_SET, 544-OFF_SET);

#include "Global.h"






