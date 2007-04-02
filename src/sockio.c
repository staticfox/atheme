/*
 * Copyright (c) 2005 William Pitcock <nenolod -at- nenolod.net>
 * Rights to this code are as documented in doc/LICENSE.
 *
 * Platform-independent Network I/O layer.
 *
 * $Id: sockio.c 8079 2007-04-02 17:37:39Z nenolod $
 */

#include "atheme.h"

int socket_read(socket_t sck, char *buf, size_t len)
{
	return read(sck, buf, len);
}

int socket_write(socket_t sck, char *buf, size_t len)
{
	return write(sck, buf, len);
}

int socket_close(socket_t sck)
{
	return close(sck);
}

int socket_geterror(void)
{
	return errno;
}

void socket_seterror(int eno)
{
	errno = eno;
}

char *socket_strerror(int eno)
{
	return (char *) strerror(eno);
}

int socket_setnonblocking(socket_t sck)
{
	int flags;

	flags = fcntl(sck, F_GETFL, 0);
	flags |= O_NONBLOCK;

	if (fcntl(sck, F_SETFL, flags))
		return -1;

	return 0;
}

/* vim:cinoptions=>s,e0,n0,f0,{0,}0,^0,=s,ps,t0,c3,+s,(2s,us,)20,*30,gs,hs
 * vim:ts=8
 * vim:sw=8
 * vim:noexpandtab
 */
