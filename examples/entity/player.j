# package entity

create Object
(
	Player,

	int id;

	void (*setId)(MAIN_STRUCT  *, int);
)

public void function(playerId, int id)
{
	use player->id = id;
}

public Player * function(initPlayer, int id)
{
	new(Player)
	alloc(p, sizeof(Player))

	p->id = id;
	p->setId = getFnc(playerId);

	return p;
}
