/*
** EPITECH PROJECT, 2018
** connection
** File description:
** connection
*/

# ifndef SOCKET_HH
	# define SOCKET_HH

# include "clang.h"

OBJECT_CREATOR
(
	Socket,

	String ip;

	int id;
	int port;
	int connected_fd;

	struct sockaddr_in addr;

	bool connection;
)

public function(void, setIp, String ip)
{
	this->socket->ip = ip;
}

public function(void, setPort, int port)
{
	this->socket->port = port;
}

public function(void, setAddr, in_addr_t addr)
{
	this->socket->addr.sin_addr.s_addr = addr;
}

public function(void, initPreConnectionEvent)
{
	this->socket = malloc(sizeof(Socket));
	__(this->socket, 1, CRITICAL);
	this->socket->id = -1;
	this->socket->port = -1;
}

public function(void, preConnectionEvent)
{
	this->socket->id = socket(AF_INET, SOCK_STREAM, 0);
	_N_(this->socket->id, 6, CRITICAL);
	this->socket->addr = (struct sockaddr_in) {
		.sin_family = AF_INET,
		.sin_port = htons(this->socket->port)
	};
}

public function(void, destroyConnection)
{
	if (this->socket->id > 0)
		close(this->socket->id);
	free(this->socket);
}

public function(void, bindEvent)
{
	_N_(bind(
		this->socket->id,
		(struct sockaddr *)&this->socket->addr,
		sizeof(this->socket->addr)
	), 6, CRITICAL);
}

public function(void, listenEvent)
{
	_N_(listen(
		this->socket->id,
		SOMAXCONN
	), 6, CRITICAL);
}

public function(void, setSocketOption)
{
	int length = 1;

	_N_(setsockopt(
		this->socket->id,
		SOL_SOCKET,
		SO_REUSEADDR,
		&length,
		sizeof(length)
	), CRITICAL, 6);
}

public function(void, acceptEvent)
{
	socklen_t length = sizeof(struct sockaddr_in);
	this->socket->connected_fd = accept(
		this->socket->id,
		(struct sockaddr *)&this->socket->addr,
		&length
	);
	_N_(this->socket->connected_fd, 6, CRITICAL);

}

public function(void, connectionEvent)
{
	_N_(connect(
		this->socket->id,
		(struct sockaddr *)&this->socket->addr,
		sizeof(this->socket->addr)
	), 6, CRITICAL);
	this->socket->connection = true;
}

/*

	Had to do it fastly, don't got the time to create a dynamic
	variable to change (this->socket) in the temp created user's socket

*/

public function(int, passiveMode)
{
	int sock = 0;
	int port = 0;
	socklen_t _length;

	struct sockaddr_in in = (struct sockaddr_in)
	{
		.sin_family = AF_INET,
		.sin_port = 0,
		.sin_addr.s_addr = INADDR_ANY,
	};

	_N_
	(
		(sock = socket(AF_INET, SOCK_STREAM, 0)),
		CRITICAL,
		6
	);
	_N_(bind(sock, (struct sockaddr *)&in, sizeof(in)), CRITICAL, 6);
	_N_(listen(sock, 1), CRITICAL, 6);
	_length = sizeof(in);
	getsockname(sock, (struct sockaddr *)&in, &_length);
	port = ntohs(in.sin_port);
	return port;
}

# endif
