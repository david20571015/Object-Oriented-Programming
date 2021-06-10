#include <graphics.h>

int menu()
{
	initwindow(1000, 530, "menu");

	readimagefile("back.jpg", 0, 0, 1000, 530);

	setfillstyle(1, 7);
	bar(420, 445, 580, 495);

	settextjustify(CENTER_TEXT, CENTER_TEXT);
	setbkcolor(7);
	settextstyle(3, HORIZ_DIR, 5);
	outtextxy(500, 480, "START");
	settextstyle(3, HORIZ_DIR, 10);
	outtextxy(500, 120, "Minecraft");

	while (1)
	{
		if (ismouseclick(WM_LBUTTONDOWN) && mousex() <= 580 && mousex() >= 420 && mousey() <= 495 && mousey() >= 445)
			break;
		else
			clearmouseclick(WM_LBUTTONDOWN);
	}

	setbkcolor(0);
	cleardevice();

	settextstyle(3, HORIZ_DIR, 5);
	outtextxy(500, 150, "Please input the world seed");
	bar(300, 235, 700, 295);
	outtextxy(500, 395, "Press 'ENTER' to create the world");

	int len = 0;
	char seed[10] = {'\0'}, s;
	setbkcolor(7);
	while (1)
	{
		outtextxy(500, 275, seed);
		s = getch();

		if ('0' <= s && '9' >= s && len <= 8)
			seed[len++] = s;

		if (s == 8 && len >= 0)
			seed[--len] = '\0';

		if (s == 13)
			break;

		bar(300, 235, 700, 295);
	}
	closegraph();

	int world_seed = 0;
	for (int i = 0; i < len; i++)
	{
		world_seed *= 10;
		world_seed += seed[i] - '0';
	}

	return world_seed;
}
