#include "cServer.h"
#include "Basedef.h"
 
bool CUser::ChangeServer(PacketHeader *Header)
{
	// N�o funciona
	p52A *p = (p52A*)(Header);

	SendOneMessage((BYTE*)p, sizeof p52A);

	CloseUser(clientId);
	return true;
}