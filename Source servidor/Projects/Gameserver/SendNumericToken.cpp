#include "cServer.h"
#include "Basedef.h"
 
bool CUser::SendNumericToken(PacketHeader *Header)
{
	pFDE *p = (pFDE*)(Header);

	p->Header.ClientId = 0;
	
	TokenOk = true;

	Log(clientId, LOG_INGAME, "Enviou senha num�rica correta. %s", p->num);
	AddMessage((BYTE*)p, sizeof pFDE);

	strncpy_s(User.SecondPass, p->num, 6);
	return true;
} 