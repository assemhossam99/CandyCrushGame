#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<time.h>

using namespace std;
using namespace sf;

void startMenu(RectangleShape &backGround, RenderWindow &window, Texture &bg,bool music)
{
	if (music)
	bg.loadFromFile("SS.jpg"); // upload the background
	else bg.loadFromFile("SSof.jpg");
	//--------adding the images to the textures----------
	backGround.setTexture(&bg);

	window.draw(backGround);
	window.display(); // draw and display the background
	
}

void level2(RectangleShape & B_G_L3, RenderWindow & window)
{
	Texture pic1, pic2, level3;
	RectangleShape rpic1(Vector2f(150.0f, 200.0f));
	RectangleShape rpic2(Vector2f(150.0f, 180.0f));
	level3.loadFromFile("level2background.jpg");
	B_G_L3.setTexture(&level3);
	pic1.loadFromFile("Edward.png");
	rpic1.setTexture(&pic1);
	pic2.loadFromFile("Eva.png");
	rpic2.setTexture(&pic2);
	window.clear();
	float a = -20, b = 900, c = 900;
	while (true)
	{
		if (a <= 20)
			rpic1.setPosition(a, 405);
		if (b >= 750)
			rpic2.setPosition(b, 430);

		else break;
		a += 0.05;
		b -= 0.075;
		window.draw(B_G_L3);
		window.draw(rpic1);
		window.draw(rpic2);
		window.display();
	}
}
void levels(RectangleShape &backGround2, RenderWindow &window, Texture &level)
{
	level.loadFromFile("LEVELS.jpg");
	backGround2.setTexture(&level);
	window.draw(backGround2);
	window.display();
}
void level3(RectangleShape & B_G_L3, RenderWindow & window)
{
	RectangleShape rpic1(Vector2f(150.0f, 150.0f));
	RectangleShape rpic2(Vector2f(150.0f, 150.0f));
	Texture level3, pic1, pic2;
	level3.loadFromFile("backgroundlev3.jpg");
	B_G_L3.setTexture(&level3);
	pic1.loadFromFile("angry-clipart-499.png");
	rpic1.setTexture(&pic1);
	pic2.loadFromFile("angry-bird-blacke-icon.png");
	rpic2.setTexture(&pic2);
			window.clear();
		float a=-20,b=900,c=900 ;
		while (true)
		{
			if (a <= 45)
				rpic1.setPosition(a, 480);
			if (b>=730)
			rpic2.setPosition(b, 470);
			
			else break;
			a += 0.05;
			b -= 0.075;
			window.draw(B_G_L3); 
			window.draw(rpic1);
			window.draw(rpic2);
			window.display();
		}

	
}
void level4(RectangleShape & B_G_L4, RenderWindow & window)
{
	RectangleShape rpic1(Vector2f(150.0f, 150.0f));
	RectangleShape rpic2(Vector2f(150.0f, 150.0f));
	Texture level4, pic1, pic2;
	level4.loadFromFile("sdsd.jpg");
	B_G_L4.setTexture(&level4);
	pic1.loadFromFile("vulture-vector-angry-6.png");
	rpic1.setTexture(&pic1);
	pic2.loadFromFile("source-clipart-movie-character-8.png");
	rpic2.setTexture(&pic2);
	window.clear();
	float a = -20, b = 900, c = 900;
	while (true)
	{
		if (a <= 0)
			rpic1.setPosition(a, 480);
		if (b >= 750)
			rpic2.setPosition(b, 470);

		else break;
		a += 0.03;
		b -= 0.075;
		window.draw(B_G_L4);
		window.draw(rpic1);
		window.draw(rpic2);
		window.display();
	}


}
void userNmae(RectangleShape &background3, RenderWindow &window, Texture &userName)
{
	userName.loadFromFile("name.jpg");
	background3.setTexture(&userName);
	window.draw(background3);
	window.display();
}
bool cheak = false;
void check(int cell[9][9])
{
	cheak = false;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			int t = cell[i][j];
			if ((j + 2) < 9 && cell[i][j] == cell[i][j + 1] && cell[i][j + 1] == cell[i][j + 2])
			{
				cheak = true;
				cell[i][j] = 'a' ;
				cell[i][j + 1] = 'a';
				cell[i][j + 2] = 'a';
				for (int cu = j + 3; cu < 9; cu++) {
					if (cell[i][cu] == t) {
						cell[i][cu] = 'a';
						

					}
					else {
						break;
					}
				}

			}
			if ((i + 2) < 9 && cell[i][j] == cell[i + 1][j] && cell[i + 1][j] == cell[i + 2][j])
			{
				cheak = true;
				cell[i][j] = 'a';
				cell[i + 1][j] = 'a';
				cell[i + 2][j] = 'a';
				
				for (int cu = i + 3; cu < 9; cu++) {
					if (cell[cu][j] == t) {
						cell[cu][j] = 'a';
					
					}
					else {
						break;
					}
				}

			}
		}
	}

}
void up0(int cell [9][9]) 
{
	
	int c, g, arr[9];
	for (int i = 0; i < 9; i++)
	{
		c = 0;
		g = 0;

		for (int j = 8; j >= 0; j--) 
			if (cell[j][i] != -3)
			{
				c++;
				arr[g] = cell[j][i];
				++g;
				cell[j][i] = -3;
			}
		for (int m = 0, h = 8; h >= 9 - c; --h, ++m)
		{
			cell[h][i] = arr[m];
		}



	}
}

void addCandiesSFML(int gameBoard[9][9], RenderWindow &window, RectangleShape &player1, RectangleShape &player2, RectangleShape &player3, Texture &tex1, Texture &tex2, Texture &tex3,int l)
{
	float x, y;
	if (l == 1)
	{
		x = -178.0;
		y = -130.0;
	}
	else if (l==2)
	{
		x = -180.0;
		y = -100.0;
	}
	else if (l == 3)
	{
		x = -203.0;
		y = -87.0;
	}
	else if (l == 4)
	{
		x = -178.0;
		y = -130.0;
	}
	else if (l == 5)
	{
		x = -178.0;
		y = -130.0;
	}
	//----uploading characters----
	tex1.loadFromFile("red.png");
	tex2.loadFromFile("yellow.png");
	tex3.loadFromFile("blue.png");

	player1.setTexture(&tex1);
	player2.setTexture(&tex2);
	player3.setTexture(&tex3);

	// -------shifting the origin point of the table----------
	player1.setOrigin(x , y );
	player2.setOrigin(x , y );
	player3.setOrigin(x , y );
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{

			if (gameBoard[i][j] == 0)
			{
				player1.setPosition(j * 60, i * 60); // setting the position of added item
				window.draw(player1);
				 //window.display(); // draw and display the first character
			}

			else if (gameBoard[i][j] == 1)
			{
				player2.setPosition(j * 60, i * 60); // setting the position of added item
				window.draw(player2);
				//window.display(); // draw and dsplay the second character
			}

			else if (gameBoard[i][j] == 2)
			{
				player3.setPosition(j * 60, i * 60); // setting the position of added item
				window.draw(player3);
				//window.display(); // draw and display the third character
			}

		}
	}
	window.display();
}


void addCandies(int arr[9][9]) // add candies randomly
{
	srand(time(NULL)); // cahnge order of candies every time
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			arr[i][j] = rand() % 3; // to add 3 candies
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}
void addCandiespart2(int arr[9][9]) // add candies randomly
{
	srand(time(NULL)); // cahnge order of candies every time
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{	if (arr[i][j]==-3)
			arr[i][j] = rand() % 3; // to add 3 candies
		
		}
	}
}
void matchVertical(int arr[9][9])
{
	int cntr = 0, temp;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] && (i + 2) < 9 && arr[i][j] > -1)
			{
				temp = arr[i][j];
				arr[i][j] = arr[i + 1][j] = arr[i + 2][j] = -3;
				for (int curr = i + 3; curr < 9; curr++)
				{
					if (arr[curr][j] == temp)
					{
						arr[curr][j] = -3;
					}
					else
						break;
				}
			}
		}
	}
}

void matchHorizontal(int arr[9][9])
{
	for (int i = 0; i < 9; i++)
	{
		int temp;
		for (int j = 0; j < 9; j++)
		{
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && (j + 2) < 9 && arr[i][j] > -1)
			{
				temp = arr[i][j];
				arr[i][j] = arr[i][j + 1] = arr[i][j + 2] = -3;
				for (int curr = j + 3; curr < 9; curr++)
				{
					if (arr[i][curr] == temp)
					{
						arr[i][curr] = -3;
					}
					else
						break;
				}
			}
		}
	}
}
int main()
{
	int gameBoard[9][9], n,l=0; // the game board of size 9 * 9
	bool inGame = false, inMenu = true, inLevels = false, inName = false,inlevel3=false,music=true;
	addCandies(gameBoard); // calling the function to add candies
	RenderWindow window(VideoMode(900, 700), "Angry Birds Crush", Style::Close | Style::Default ); // defining a window
	RectangleShape backGround(Vector2f(900.0f, 700.0f)); // create a shape to be a background
	RectangleShape player1(Vector2f(50.0f, 50.0f)); // create a shape
	RectangleShape player2(Vector2f(50.0f, 50.0f)); // create a shape
	RectangleShape player3(Vector2f(50.0f, 50.0f)); // create a shape
	RectangleShape backGround2(Vector2f(900.0f, 700.0f));
	RectangleShape backGround3(Vector2f(900.0f, 700.0f));
	RectangleShape backGroung_l3(Vector2f(900.0f, 700.0f));
	Texture level, userName;
	Texture tex1, tex2, tex3, bg,B_G_L3,B_G_L2; // create textures to add photos
	//addCandiesSFML(gameBoard, window, player1, player2, player3, tex1, tex2, tex3); // calling function
	startMenu(backGround, window, bg,music); // calling function
	SoundBuffer  soundmain;
	Sound S_M;

	if (!soundmain.loadFromFile("mainmusic (2).wav"));
	cout << "Can't find it " << endl;
	S_M.setBuffer(soundmain);
	SoundBuffer soundlev3;
	Sound slev3;
	if (!soundlev3.loadFromFile("level3music.wav"));
	cout << "cant find 2 " << endl;
	slev3.setBuffer(soundlev3);
	/////////////////////////////////////////////
	SoundBuffer soundlev2;
	Sound slev2;
	if (!soundlev2.loadFromFile("level2music.wav"));
	cout << "cant find 3 " << endl;
	slev3.setBuffer(soundlev2);
	if (music)
	S_M.play();

	while (window.isOpen())
	{
		Event evnt; // declaration of an event
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case Event::Closed:
				window.close(); //order to close the window
				break;
			}
			
	
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				Vector2i mousepos = Mouse::getPosition(window);
				cout << (float)mousepos.x << ' ' << (float)mousepos.y << endl;
				 if ((float)mousepos.x >= 801 && (float)mousepos.x <= 860 && (float)mousepos.y >= 35 && (float)mousepos.y <= 76 && inMenu == true )
				{
					if (music)
					{
						S_M.pause();
					music = false;

					}
					else
					{
						S_M.play();
						music = true;
					}
					startMenu(backGround, window, bg,music);

				}
				 else if ((float)mousepos.x >= 302 && (float)mousepos.x <= 598 && (float)mousepos.y >= 322 && (float)mousepos.y <= 380 && inMenu == true)
				{
					window.clear();
					levels(backGround2, window, level);
					inLevels = true;
					inMenu = false;
					inGame = false;
					inName = false;
					
					
				}

				else if ((float)mousepos.x >= 302 && (float)mousepos.x <= 598 && (float)mousepos.y >= 425 && (float)mousepos.y <= 486 && inMenu == true)
				{
					window.clear();
					levels(backGround2, window, level);
					inLevels = true;
					inMenu = false;
					inGame = false; 
					inName = false;
				}

				else if ((float)mousepos.x >= 300 && (float)mousepos.x <= 595 && (float)mousepos.y >= 268 && (float)mousepos.y <= 328 && inLevels == true)
				{
					window.clear();
					userNmae(backGround3, window, userName);
					inName = true;
					inLevels = false;
					inMenu = false;
					inGame = false;
					
				}

				else if ((float)mousepos.x >= 252 && (float)mousepos.x <= 685 && (float)mousepos.y >= 415 && (float)mousepos.y <= 499 && inName == true)
				{
					l = 1;
					window.clear();
					addCandiesSFML(gameBoard, window, player1, player2, player3, tex1, tex2, tex3,l);
					inGame = true;
					inMenu = false;
					inName = false;
					inLevels = false;
				}

				else if ((float)mousepos.x >= 30 && (float)mousepos.x <= 596 && (float)mousepos.y >= 356 && (float)mousepos.y <= 413 && inLevels == true)
				{
				window.clear();
				l = 2;
				S_M.stop(); 
				level2(backGroung_l3, window);
				addCandiesSFML(gameBoard, window, player1, player2, player3, tex1, tex2, tex3, l);
				   matchHorizontal(gameBoard);
					matchVertical(gameBoard);
					for (int i = 0; i < 9; ++i)
					{
						for (int j = 0; j < 9; ++j)
							cout << gameBoard[i][j] << " " ;
						cout << endl;
					}
					up0(gameBoard);
					for (int i = 0; i < 9; ++i)
					{
						for (int j = 0; j < 9; ++j)
							cout << gameBoard[i][j] << " ";
						cout << endl;
					}
					
				addCandiespart2(gameBoard);
				
				if (music)
				{
					slev3.play();
				}

				inLevels = false;
				inGame = true;
				inMenu = false;
				inName = false;
				}
				else if ((float)mousepos.x >= 302 && (float)mousepos.x <=   597 && (float)mousepos.y >= 440 && (float)mousepos.y <= 500 && inLevels == true)
				{	
					window.clear();
					l = 3;
						S_M.stop();
					level3(backGroung_l3, window);
					addCandiesSFML(gameBoard, window, player1, player2, player3, tex1, tex2, tex3,l);
					//matchHorizontal(gameBoard);
					//matchVertical(gameBoard);
					addCandiesSFML(gameBoard, window, player1, player2, player3, tex1, tex2, tex3, l);
					
					if (music)
					{
						slev3.play();
					}
					
					inLevels = false;
					inGame = true;
					inMenu = false;
					inName = false;
					
				}
				else if ((float)mousepos.x >= 300 && (float)mousepos.x <= 597 && (float)mousepos.y >= 526 && (float)mousepos.y <= 588 && inLevels == true)
				{
					l = 4;
					S_M.stop();
					level4(backGroung_l3, window);
					addCandiesSFML(gameBoard, window, player1, player2, player3, tex1, tex2, tex3,l);


					if (music)
					{
						slev3.play();
					}

					inLevels = false;
					inGame = true;
					inMenu = false;
					inName = false;


				}
				else if ((float)mousepos.x >= 15 && (float)mousepos.x <= 171 && (float)mousepos.y >= 19 && (float)mousepos.y <= 95 && inName == true)
				{
					window.clear();
					levels(backGround2, window, level);
					inLevels = true;
					inGame = false;
					inMenu = false;
					inName = false;
				}

				else if ((float)mousepos.x >= 15 && (float)mousepos.x <= 171 && (float)mousepos.y >= 19 && (float)mousepos.y <= 95 && inLevels == true)
				{
					window.clear();
					startMenu(backGround, window, bg,music);
					inLevels = false;
					inGame = false;
					inMenu = true;
					inName = false;
				}
				 if ((float)mousepos.x >= 3 && (float)mousepos.x <= 113 && (float)mousepos.y >= 274 && (float)mousepos.y <= 340 && inGame == true && l == 4)
				{
					 addCandies(gameBoard);
				slev3.stop();
				window.clear();
				levels(backGround2, window, level);
				if (music)
				S_M.play();
				inLevels = true;
				inGame = false;
				inMenu = false;
				inName = false;
				}
				 if ((float)mousepos.x >= 772 && (float)mousepos.x <= 890 && (float)mousepos.y >= 12 && (float)mousepos.y <= 67 && inGame == true && l == 3)
				{
					 addCandies(gameBoard);
				slev3.stop();
				window.clear();
				levels(backGround2, window, level);
				if (music)
					S_M.play();
				inLevels = true;
				inGame = false;
				inMenu = false;
				inName = false;
				}
				 if ((float)mousepos.x >= 755 && (float)mousepos.x <= 896 && (float)mousepos.y >= 3 && (float)mousepos.y <= 84 && inGame == true && l == 2)
				 {
					 addCandies(gameBoard);
					 slev3.stop();
					 window.clear();
					 levels(backGround2, window, level);
					 if (music)
						 S_M.play();
					 inLevels = true;
					 inGame = false;
					 inMenu = false;
					 inName = false;
				 }
			}
		
		}



	}

	return 0;
}