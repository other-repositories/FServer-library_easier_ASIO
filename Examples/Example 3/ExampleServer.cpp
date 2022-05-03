﻿#include "FServer.h"

struct Pocket
{
};

int main()
{
	
	Server <Pocket> sv("192.168.0.200", 80);

	sv.start();

	sv.set_path_download("/home/artem/test/");
	
	while (true)
	{
		int n = -1;
			while (n == -1) {
				n = sv.get_http_connect();
				Sleep(100);
			}

		sv << HTTP{ "test.html",n };

	}
	sv.stop();

	
}
