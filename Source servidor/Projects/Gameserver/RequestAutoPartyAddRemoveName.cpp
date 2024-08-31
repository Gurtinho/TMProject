#include "cServer.h"
#include "Basedef.h"
#include "SendFunc.h"
#include "GetFunc.h"
#include "CNPCGener.h"
#include <ctime>
#include <algorithm>
#include <sstream>

bool CUser::RequestAutoPartyAddRemoveName(PacketHeader* header)
{
	MSG_AUTOPARTY_ADDREMOVE_NAME* packet = reinterpret_cast<MSG_AUTOPARTY_ADDREMOVE_NAME*>(header);

	// add
	std::string name = packet->Nickname;
	auto nameIt = std::find(std::begin(AutoParty.Nicknames), std::end(AutoParty.Nicknames), name);

	if (packet->Mode == 0)
	{
		if (nameIt != std::end(AutoParty.Nicknames))
		{
			SendClientMessage(clientId, "Este usu�rio j� est� na lista");

			return true;
		}

		bool added = false;
		for (auto& names : AutoParty.Nicknames)
		{
			if (!names.empty())
				continue;

			names = name;
			added = true;
			break;
		}

		if (!added)
		{
			SendClientMessage(clientId, "N�o existe mais espa�o vago para isto");

			return true;
		}

		SendClientMessage(clientId, "Adicionado com sucesso");
	}
	// remove
	else if (packet->Mode == 1)
	{
		if (nameIt == std::end(AutoParty.Nicknames))
		{
			SendClientMessage(clientId, "Este usu�rio n�o est� na lista");

			return true;
		}

		(*nameIt) = "";
		SendClientMessage(clientId, "Removido com sucesso");
	}

	SendAutoPartyInfo(clientId);
	return true;
}