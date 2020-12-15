#include "toolbar.hpp";
#include <iostream>
#include <SFML/Graphics.hpp>

bool penSelected = false;
bool brushSelected = false;
bool eraserSelected = false;
bool fillSelected = false;
bool circleSelected = false;
bool polygonSelected = false;

int toolbarMouseX, toolbarMouseY;

sf::Sprite sprt_icon_toolbar;
sf::RectangleShape btn_bg_penTool(sf::Vector2f(40.0f, 40.0f));
sf::RectangleShape btn_bg_brushTool(sf::Vector2f(40.0f, 40.0f));
sf::RectangleShape btn_bg_eraserTool(sf::Vector2f(40.0f, 40.0f));
sf::RectangleShape btn_bg_fillTool(sf::Vector2f(40.0f, 40.0f));
sf::RectangleShape btn_bg_circleTool(sf::Vector2f(40.0f, 40.0f));
sf::RectangleShape btn_bg_polygonTool(sf::Vector2f(40.0f, 40.0f));
sf::Texture icon_tools;

extern sf::RenderWindow toolbar(sf::VideoMode(120, 160), "Toolbar", sf::Style::Titlebar);


void init_toolbar()
{
	toolbar.setPosition(sf::Vector2i(100,100));

	icon_tools.loadFromFile("tool_icons.png");

	sprt_icon_toolbar.setPosition(0.0f, 0.0f);

	btn_bg_penTool.setPosition(0.0f, 0.0f);
	btn_bg_brushTool.setPosition(40.0f, 0.0f);
	btn_bg_eraserTool.setPosition(80.0f, 0.0f);
	btn_bg_fillTool.setPosition(0.0f, 40.0f);
	btn_bg_circleTool.setPosition(40.0f, 40.0f);
	btn_bg_polygonTool.setPosition(80.0f, 40.0f);

	sprt_icon_toolbar.setTexture(icon_tools);

	sprt_icon_toolbar.setScale(0.2f, 0.2f);

}

void toolbar_action()
{
	sf::Event evnt;

	//boardMouseX = sf::Mouse::getPosition(board).x;
	//boardMouseY = sf::Mouse::getPosition(board).y;
	toolbarMouseX = sf::Mouse::getPosition(toolbar).x;
	toolbarMouseY = sf::Mouse::getPosition(toolbar).y;

	while (toolbar.pollEvent(evnt))
	{
		if (evnt.type == sf::Event::MouseButtonPressed)
		{
			//pentool selection
			if (toolbarMouseX >= 0 && toolbarMouseX < 40 && toolbarMouseY >= 0 && toolbarMouseY < 40)
			{
				penSelected = penSelected ? 0 : 1;
				brushSelected = false;
				eraserSelected = false;
				fillSelected = false;
				circleSelected = false;
				polygonSelected = false;
			}
			//brushtool selection
			else if (toolbarMouseX >= 40 && toolbarMouseX < 80 && toolbarMouseY >= 0 && toolbarMouseY < 40)
			{
				brushSelected = brushSelected ? 0 : 1;
				penSelected = false;
				eraserSelected = false;
				fillSelected = false;
				circleSelected = false;
				polygonSelected = false;
			}
			//erasertool selection
			else if (toolbarMouseX >= 80 && toolbarMouseX < 120 && toolbarMouseY >= 0 && toolbarMouseY < 40)
			{
				eraserSelected = eraserSelected ? 0 : 1;
				penSelected = false;
				brushSelected = false;
				fillSelected = false;
				circleSelected = false;
				polygonSelected = false;
			}
			//filltool selection
			else if (toolbarMouseX >= 0 && toolbarMouseX < 40 && toolbarMouseY >= 40 && toolbarMouseY < 80)
			{
				fillSelected = fillSelected ? 0 : 1;
				penSelected = false;
				brushSelected = false;
				eraserSelected = false;
				circleSelected = false;
				polygonSelected = false;
			}
			//circletool selection
			else if (toolbarMouseX >= 40 && toolbarMouseX < 80 && toolbarMouseY >= 40 && toolbarMouseY < 80)
			{
				circleSelected = circleSelected ? 0 : 1;
				penSelected = false;
				brushSelected = false;
				eraserSelected = false;
				fillSelected = false;
				polygonSelected = false;
			}
			//polygontool selection
			else if (toolbarMouseX >= 80 && toolbarMouseX < 120 && toolbarMouseY >= 40 && toolbarMouseY < 80)
			{
				polygonSelected = polygonSelected ? 0 : 1;
				penSelected = false;
				brushSelected = false;
				eraserSelected = false;
				fillSelected = false;
				circleSelected = false;
			}
		}
	}

	//bg handling for penTool
	if (penSelected)
	{
		btn_bg_penTool.setFillColor(sf::Color(46, 46, 46));
	}
	else if (!penSelected && toolbarMouseX >= 0 && toolbarMouseX < 40 && toolbarMouseY >= 0 && toolbarMouseY < 40)
	{
		btn_bg_penTool.setFillColor(sf::Color(60, 60, 60));
	}
	else
	{
		btn_bg_penTool.setFillColor(sf::Color(70, 70, 70));
	}
	//bg handling for brushTool
	if (brushSelected)
	{
		btn_bg_brushTool.setFillColor(sf::Color(46, 46, 46));
	}
	else if (!brushSelected && toolbarMouseX >= 40 && toolbarMouseX < 80 && toolbarMouseY >= 0 && toolbarMouseY < 40)
	{
		btn_bg_brushTool.setFillColor(sf::Color(60, 60, 60));
	}
	else
	{
		btn_bg_brushTool.setFillColor(sf::Color(70, 70, 70));
	}
	//bg handling for eraserTool
	if (eraserSelected)
	{
		btn_bg_eraserTool.setFillColor(sf::Color(46, 46, 46));
	}
	else if (!eraserSelected && toolbarMouseX >= 80 && toolbarMouseX < 120 && toolbarMouseY >= 0 && toolbarMouseY < 40)
	{
		btn_bg_eraserTool.setFillColor(sf::Color(60, 60, 60));
	}
	else
	{
		btn_bg_eraserTool.setFillColor(sf::Color(70, 70, 70));
	}
	//bg handling for fillTool
	if (fillSelected)
	{
		btn_bg_fillTool.setFillColor(sf::Color(46, 46, 46));
	}
	else if (!fillSelected && toolbarMouseX >= 0 && toolbarMouseX < 40 && toolbarMouseY >= 40 && toolbarMouseY < 80)
	{
		btn_bg_fillTool.setFillColor(sf::Color(60, 60, 60));
	}
	else
	{
		btn_bg_fillTool.setFillColor(sf::Color(70, 70, 70));
	}
	//bg handling for circleTool
	if (circleSelected)
	{
		btn_bg_circleTool.setFillColor(sf::Color(46, 46, 46));
	}
	else if (!circleSelected && toolbarMouseX >= 40 && toolbarMouseX < 80 && toolbarMouseY >= 40 && toolbarMouseY < 80)
	{
		btn_bg_circleTool.setFillColor(sf::Color(60, 60, 60));
	}
	else
	{
		btn_bg_circleTool.setFillColor(sf::Color(70, 70, 70));
	}
	//bg handling for polygonTool
	if (polygonSelected)
	{
		btn_bg_polygonTool.setFillColor(sf::Color(46, 46, 46));
	}
	else if (!polygonSelected && toolbarMouseX >= 80 && toolbarMouseX < 120 && toolbarMouseY >= 40 && toolbarMouseY < 80)
	{
		btn_bg_polygonTool.setFillColor(sf::Color(60, 60, 60));
	}
	else
	{
		btn_bg_polygonTool.setFillColor(sf::Color(70, 70, 70));
	}

	toolbar.clear(sf::Color(70, 70, 70));

	toolbar.draw(btn_bg_penTool);
	toolbar.draw(btn_bg_brushTool);
	toolbar.draw(btn_bg_eraserTool);
	toolbar.draw(btn_bg_fillTool);
	toolbar.draw(btn_bg_circleTool);
	toolbar.draw(btn_bg_polygonTool);

	toolbar.draw(sprt_icon_toolbar);
	toolbar.display();
}