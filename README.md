

# Neo C

**Install compilator**
```bash
 make install
```
**Compiling**
```bash
 clang_compile <name>
```
If no name entered -> a.out

**Object Definition**
```ruby
# package main

default Object is Test

future(Player)

create Object
(
	Test,

	Unknown unknown;
	Player * player;
)
```
**Import File**
```ruby
import file player
```
**In file entity/player.j**
```ruby
# package entity

create Object
(
	Player,

	int id;
	void (*setId)(MAIN_STRUCT *, int);
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
```
**Allocating Main Object**
```ruby
private Test * function(init)
{
	new(Test)
	alloc(_test, sizeof(Test))

	_test->unknown = setUnknown("hello", "world");
	_test->player = call(initPlayer, 90);
	return _test;
}
```
**Main function with new coding styles**
```ruby
import main(int, { call(init) })

default(int)
{
	Unknown unknown = use unknown;
	$get(char, test1, alpha)
	$get(char, test2, beta)

	$>"%s %s" test1, test2

	use player->setId(this, 9);

	int id = use player->id;

	$>"Player id : %d" id

	free(use player);

	return 0;
}
```
