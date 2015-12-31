/*
	Copyright 2015 Kirollos

	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.
*/

#include "main.h"
#include "events.h"

namespace Events
{
	void RegisterEvents(PluginCallbacks* vccb)
	{
		vccb->OnPlayerConnect = Events::OnPlayerConnect;
		vccb->OnPlayerDisconnect = Events::OnPlayerDisconnect;
		vccb->OnPlayerSpawn = Events::OnPlayerSpawn;
		vccb->OnPlayerDeath = Events::OnPlayerDeath;
		vccb->OnPublicMessage = Events::OnMessage;
		vccb->OnCommandMessage = Events::OnCommand;
		VCMP_PF->printf("[RCON]: Events successfully registered!");
	}

	void OnPlayerConnect(int playerid)
	{
		char* pName = new char[100];
		pName[0] = 0;
		VCMP_PF->GetPlayerName(playerid, pName, 100);
		rcon->Broadcastex("[CONNECT] %s[%i] has connected!", pName, playerid);
		delete pName;
	}

	void OnPlayerDisconnect(int playerid, int nReason)
	{
		char* pName = new char[100];
		pName[0] = 0;
		VCMP_PF->GetPlayerName(playerid, pName, 100);
		rcon->Broadcastex("[DISCONNECT:%i] %s[%i] has disconnected!", nReason, pName, playerid);
		delete pName;
	}

	void OnPlayerSpawn(int playerid)
	{
		char* pName = new char[100];
		pName[0] = 0;
		VCMP_PF->GetPlayerName(playerid, pName, 100);
		rcon->Broadcastex("[SPAWN] %s[%i] has spawned!", pName, playerid);
		delete pName;
	}

	void OnPlayerDeath(int playerid, int killerid, int reason, int bodypart)
	{
		char* pName = new char[100];
		pName[0] = 0;
		VCMP_PF->GetPlayerName(playerid, pName, 100);
		char* kName = new char[100];
		kName[0] = 0;
		VCMP_PF->GetPlayerName(killerid, kName, 100);
		rcon->Broadcastex("[DEATH] %s[%i] has died, killer:%s[%i], reason:%i, bodypart:%i", pName, playerid, kName, killerid, reason, bodypart);
		delete pName;
		delete kName;
	}

	int OnMessage(int playerid, const char* message)
	{
		char* pName = new char[100];
		pName[0] = 0;
		VCMP_PF->GetPlayerName(playerid, pName, 100);
		rcon->Broadcastex("[CHAT] %s[%i]: %s", pName, playerid, message);
		delete pName;
		return 1;
	}

	int OnCommand(int playerid, const char* message)
	{
		char* pName = new char[100];
		pName[0] = 0;
		VCMP_PF->GetPlayerName(playerid, pName, 100);
		rcon->Broadcastex("[COMMAND] %s[%i]: /%s", pName, playerid, message);
		delete pName;
		return 1;
	}
}