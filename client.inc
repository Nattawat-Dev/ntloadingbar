#include	<YSI_Coding\y_hooks>

new PlayerText:ntloadingbar[MAX_PLAYERS][3];


ntloading(playerid, bool:showloading)
{
	if(showloading == true)
	{
        PlayerTextDrawShow(playerid, ntloadingbar[playerid][0]);
        PlayerTextDrawShow(playerid, ntloadingbar[playerid][1]);
        PlayerTextDrawShow(playerid, ntloadingbar[playerid][2]);
    }
    else
    {
        PlayerTextDrawHide(playerid, ntloadingbar[playerid][0]);
        PlayerTextDrawHide(playerid, ntloadingbar[playerid][1]);
        PlayerTextDrawHide(playerid, ntloadingbar[playerid][2]);
        
    }
}

hook OnPlayerUpdate(playerid)
{
    new string[256];
    if(ntloadingstartfor[playerid] == 1)
    {
        
    startloading[playerid] ++;

    if(startloading[playerid] >= 100) Stopntloading(playerid);
    else if(startloading[playerid] == 10) PlayerTextDrawSetString(playerid, ntloadingbar[playerid][0], "ntloading:ntl10");
    else if(startloading[playerid] == 20) PlayerTextDrawSetString(playerid, ntloadingbar[playerid][0], "ntloading:ntl20");
    else if(startloading[playerid] == 30) PlayerTextDrawSetString(playerid, ntloadingbar[playerid][0], "ntloading:ntl30");
    else if(startloading[playerid] == 40) PlayerTextDrawSetString(playerid, ntloadingbar[playerid][0], "ntloading:ntl40");
    else if(startloading[playerid] == 50) PlayerTextDrawSetString(playerid, ntloadingbar[playerid][0], "ntloading:ntl50");
    else if(startloading[playerid] == 60) PlayerTextDrawSetString(playerid, ntloadingbar[playerid][0], "ntloading:ntl60");
    else if(startloading[playerid] == 70) PlayerTextDrawSetString(playerid, ntloadingbar[playerid][0], "ntloading:ntl70");
    else if(startloading[playerid] == 80) PlayerTextDrawSetString(playerid, ntloadingbar[playerid][0], "ntloading:ntl80");
    else if(startloading[playerid] == 90) PlayerTextDrawSetString(playerid, ntloadingbar[playerid][0], "ntloading:ntl90");
    else if(startloading[playerid] == 98) PlayerTextDrawSetString(playerid, ntloadingbar[playerid][0], "ntloading:ntl100");
    format(string, sizeof(string), "%0d", startloading[playerid]);
    PlayerTextDrawSetString(playerid, ntloadingbar[playerid][1], string);
    }
    else
    {
        Stopntloading(playerid);
    }
    return 1;
}
hook OnPlayerConnect(playerid)
{
    ntloadingbar[playerid][0] = CreatePlayerTextDraw(playerid, 300.000000, 350.000000, "ntloading:ntl0");
    PlayerTextDrawFont(playerid, ntloadingbar[playerid][0], 4);
    PlayerTextDrawLetterSize(playerid, ntloadingbar[playerid][0], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, ntloadingbar[playerid][0], 40.000000, 48.000000);
    PlayerTextDrawSetOutline(playerid, ntloadingbar[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, ntloadingbar[playerid][0], 0);
    PlayerTextDrawAlignment(playerid, ntloadingbar[playerid][0], 1);
    PlayerTextDrawColor(playerid, ntloadingbar[playerid][0], -1);
    PlayerTextDrawBackgroundColor(playerid, ntloadingbar[playerid][0], 255);
    PlayerTextDrawBoxColor(playerid, ntloadingbar[playerid][0], 50);
    PlayerTextDrawUseBox(playerid, ntloadingbar[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, ntloadingbar[playerid][0], 1);
    PlayerTextDrawSetSelectable(playerid, ntloadingbar[playerid][0], 0);

    ntloadingbar[playerid][1] = CreatePlayerTextDraw(playerid, 320.000000, 366.000000, "100");
    PlayerTextDrawFont(playerid, ntloadingbar[playerid][1], 3);
    PlayerTextDrawLetterSize(playerid, ntloadingbar[playerid][1], 0.266666, 1.050000);
    PlayerTextDrawTextSize(playerid, ntloadingbar[playerid][1], 400.000000, 129.000000);
    PlayerTextDrawSetOutline(playerid, ntloadingbar[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, ntloadingbar[playerid][1], 0);
    PlayerTextDrawAlignment(playerid, ntloadingbar[playerid][1], 2);
    PlayerTextDrawColor(playerid, ntloadingbar[playerid][1], -1);
    PlayerTextDrawBackgroundColor(playerid, ntloadingbar[playerid][1], 255);
    PlayerTextDrawBoxColor(playerid, ntloadingbar[playerid][1], 30);
    PlayerTextDrawUseBox(playerid, ntloadingbar[playerid][1], 0);
    PlayerTextDrawSetProportional(playerid, ntloadingbar[playerid][1], 1);
    PlayerTextDrawSetSelectable(playerid, ntloadingbar[playerid][1], 0);

    ntloadingbar[playerid][2] = CreatePlayerTextDraw(playerid, 320.000000, 375.000000, "LOADING");
    PlayerTextDrawFont(playerid, ntloadingbar[playerid][2], 1);
    PlayerTextDrawLetterSize(playerid, ntloadingbar[playerid][2], 0.108333, 0.700000);
    PlayerTextDrawTextSize(playerid, ntloadingbar[playerid][2], 400.000000, 129.000000);
    PlayerTextDrawSetOutline(playerid, ntloadingbar[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, ntloadingbar[playerid][2], 0);
    PlayerTextDrawAlignment(playerid, ntloadingbar[playerid][2], 2);
    PlayerTextDrawColor(playerid, ntloadingbar[playerid][2], -16776961);
    PlayerTextDrawBackgroundColor(playerid, ntloadingbar[playerid][2], 255);
    PlayerTextDrawBoxColor(playerid, ntloadingbar[playerid][2], 30);
    PlayerTextDrawUseBox(playerid, ntloadingbar[playerid][2], 0);
    PlayerTextDrawSetProportional(playerid, ntloadingbar[playerid][2], 1);
    PlayerTextDrawSetSelectable(playerid, ntloadingbar[playerid][2], 0);
    return 1;
}