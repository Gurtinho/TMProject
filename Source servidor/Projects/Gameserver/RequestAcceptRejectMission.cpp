#include "cServer.h"
#include "Basedef.h"
#include "SendFunc.h"
#include "GetFunc.h"
#include "UOD_EventManager.h"
#include "UOD_Mission.h"
#include <ctime>
#include <algorithm>
#include <sstream>

bool CUser::RequestAcceptRejectMission(PacketHeader* header)
{
	pMsgSignal* packet = reinterpret_cast<pMsgSignal*>(header);

	auto& daily = Mob[clientId].Mobs.DailyQuest;
	if(daily.QuestId == -1)
	{ 
		SendClientMessage(clientId, "Voc� n�o tem uma miss�o para aceitar ou recusar");

		Log(clientId, LOG_INGAME, "Tentou aceitar/recusar uma miss�o sem ter uma no momento");
		return true;
	}

	auto mission = static_cast<TOD_Mission*>(TOD_EventManager::GetInstance().GetEvent(TOD_EventType::Mission));
	if (packet->Value == 1)
	{
		daily.IsAccepted = true;

		SendClientMessage(clientId, "Voc� aceitou a miss�o. Voc� tem 6 horas para conclu�-la");
		Log(clientId, LOG_INGAME, "Aceitou a miss�o.");

		mission->SetLastUpdateMission(*this);
	}
	else
	{
		SendClientMessage(clientId, "Voc� rejeitou a miss�o");
		Log(clientId, LOG_INGAME, "Rejeitou a miss�o.");

		mission->Reset(*this);
	}

	SendMissionInfo(clientId);
	return true;
}