----
Para criar um novo NPCP, adicione o arquivo na pasta DataBase//Quests com a extens�o "*.c"

O NPC dever� estar com a merchant padr�o acima do n�vel 600. Para a quest 1, o n�vel deve ser 601, para a quest 10, o n�vel dever� ser 610.

///////////////

QUEST*    : Define o n�mero da quest. 
	        O par�metro vai logo ao lado
	        Limite atual: 15

Exemplo:
QUEST0 NAME Quest_Nome_Test

Parametros:

NAME	  : N�o sei porque fiz isso, ainda n�o tem serventia 
POSITION  : Mesma coisa, j� que � gerado no NPCGener, n�o faz sentido

CONDITION : Esta parte � a parte em que o NPC ir� solicitar 
            itens ou atributos do jogador
            Voc� deve definir um index para cada uma, por exemplo

QUEST0 CONDITION-0
            No caso acima, o index definido seria o 0. O limite de pedidos atualmente � 10

	    SPEECH               -> Quando o que voc� est� pedindo n�o � encontrado voc� pode enviar uma mensagem 
Exemplo:
QUEST0 CONDITION-0 ITEM 10 3330
QUEST0 CONDITION-0 SPEECH Voc�_precisa_de_10_trombetas.

        LEVEL "MIN" "MAX"    -> Voc� define o n�vel m�nimo e m�ximo para utilizar o NPC
        ITEM "AMOUNT" "ITEM" -> Pede um item em uma quantidade definida por voc�
        EVOLUTION "VALUE"    -> Necess�rio uma evolu��o para usar o NPC - 0 = all, 1 = mortal, 2 = arch, 3 = cele, 4 = sub, 5 = mortal + arch, 6 = arch + cele, 7 = arch+cele+sub, 8=cele+sub
		GOLD "VALUE"         -> Solicita uma quantia de gold no invent�rio do usu�rio
		CLASS "VALUE" 	     -> Para usar o NPC dever� ter a classe indicada. 1 = tk, 2 = fm, 3 = bm, 4 = ht
		EQITEM "SLOT" "ITEM" -> Necess�rio ter um item XX equipado no slot YY
	

REWARD    : Esta � a parte em que voc� d� as premia��es para o usu�rio.
            Voc� deve definir um index para cada uma, por exemplo:

QUEST0 REWARD-0

	No caso acima, o index definido seria o 0. O limite de entrega atualmente � 10

	SPEECH                -> Quando � entregue uma premia��o, voc� pode por mensagens pelo NPC. 
	                         Poder� aparecer mais de uma no NPC, uma para cada premia��o, mas vai floodar KK

	EXP "VALUE"						-> Entrega o valor de experi�ncia para o personagem.
	LEVEL "VALUE"					-> Entrega XX n�veis para o usu�rio, a experi�ncia aumenta junto.
	GOLD "VALUE"					-> Entrega gold para o personagem.
	EQUIP "SLOT" "ITEM"				-> Equipa um item no personagem (ef1, efv1 inclusos).
	TELEPORT "X" "Y"				-> Teleporta o usu�rio para as coordenadas citadas
	REMOVEGOLD "VALUE"				-> Remove uma quantia de gold do personagem
	REMOVEEXP "VALUE"				-> Remove uma quantia de exp do personagem
	DELETEITEM "SLOT" "AMOUNT" "ID" -> Deleta a quantia de itens do personagem. O index seria de 0~5, podendo remover at� 5 itens diferentes.
	EQDELETE "SLOT" "ITEM"			-> Exclui um item do equipamento do usu�rio, o ID do item tem que se o que estar� equipado no momento.