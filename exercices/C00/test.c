while (bytesr != 0)
{
	bytesr = read(fd, buff, 1000000);
	buffsize += bytesr;
}

malloc = buffer(sizeof(char) * (buffsize + 1))