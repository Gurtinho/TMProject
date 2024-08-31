#include "cServer.h"
#include "Basedef.h"

bool CUser::RequestCreateChar(PacketHeader *Header)
{
	p20F *p = (p20F*)Header;

	// Faz as checagens de seguran�a, somente ap�s isto
	// � feito as checagens de �ndice inv�lido

	if (p->ClassID < 0 || p->ClassID > 3)
		return false;

	if (p->SlotID < 0 || p->SlotID > 3)
		return false;

	// BUG Da pr�pria TMsrv
	// Checagem se o usu�rio est� logado
	// Caso n�o esteja, ele retorna falso pois n�o � poss�vel criar personagem ingame.
	if(Status != USER_SELCHAR)
		return false;

	// Null character
	p->Nick[12] = '\0';

	p->Header.PacketId = 0x802;

	AddMessageDB((BYTE*)Header, sizeof p20F);

	// Seta como quem est� criando um personagem
	Status = USER_CREWAIT;

	return true;
}