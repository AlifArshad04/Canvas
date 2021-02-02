#include "global.hpp"
#include <string>
#include <sstream>
#include "Textbox.hpp"

bool open()
{
	bool heightSelected = false;
	bool widthSelected = false;
	bool closed = false;

	sf::RenderWindow open_prompt{ {720, 480}, "Welcome to Canvas" };
	open_prompt.setVerticalSyncEnabled(true);

	sf::Image icon;
	icon.loadFromFile("./Resources/img/canvasIcon.png");
	open_prompt.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	sf::Font font1;
	if (!font1.loadFromFile("./Resources/fonts/BeautifulPeoplePersonalUse.ttf"))
	{
		std::cout << "unable to load font\n";
	}
	sf::Font font2;
	if (!font2.loadFromFile("./Resources/fonts/arial.ttf"))
	{
		std::cout << "unable to load font\n";
	}

	sf::Sprite sprt_startMenu;
	sf::Texture tex_startMenu;
	tex_startMenu.loadFromFile("./Resources/img/start_prompt.png");
	sprt_startMenu.setPosition(0.0f, 0.0f);
	sprt_startMenu.setTexture(tex_startMenu);

	sf::RectangleShape btn_height(sf::Vector2f(150.0f, 30.0f));
	sf::RectangleShape btn_width(sf::Vector2f(150.0f, 30.0f));
	sf::RectangleShape btn_black(sf::Vector2f(46.0f, 46.0f));
	sf::RectangleShape btn_white(sf::Vector2f(46.0f, 46.0f));
	sf::RectangleShape btn_create(sf::Vector2f(100.0f, 30.0f));
	sf::RectangleShape btn_import(sf::Vector2f(150.0f, 30.0f));

	btn_height.setPosition(475.0f, 134.0f);
	btn_width.setPosition(475.0f, 205.0f);
	btn_black.setPosition(477.0f, 287.0f);
	btn_white.setPosition(527.0f, 287.0f);
	btn_create.setPosition(475.10f, 366.10f);
	btn_import.setPosition(475.10f, 423.10f);

	btn_height.setFillColor(sf::Color(42, 42, 42));
	btn_width.setFillColor(sf::Color(42, 42, 42));
	btn_black.setFillColor(sf::Color::Transparent);
	btn_white.setFillColor(sf::Color::Transparent);
	btn_create.setFillColor(sf::Color(42, 42, 42));
	btn_import.setFillColor(sf::Color(42, 42, 42));

	btn_create.setOutlineThickness(1.5);
	btn_create.setOutlineColor(sf::Color::Cyan);
	btn_import.setOutlineThickness(1.5);
	btn_import.setOutlineColor(sf::Color::Cyan);

	sf::Text txt_canvas("Canvas", font1, 120);
	txt_canvas.setStyle(sf::Text::Italic);
	txt_canvas.setPosition({ 30.0f, 200.0f });
	txt_canvas.setFillColor(sf::Color::White);

	sf::Text txt_imagination("Let Your Imagination Flow", font1, 60);
	txt_imagination.setStyle(sf::Text::Italic);
	txt_imagination.setPosition({ 58.0f, 18.0f });
	txt_imagination.setFillColor(sf::Color::White);

	sf::Text txt_create("Create New", font2, 15);
	txt_create.setPosition({ 486.0f, 372.0f });
	txt_create.setFillColor(sf::Color::White);

	sf::Text txt_import("Import from existing", font2, 15);
	txt_import.setPosition({ 481.0f, 429.0f });
	txt_import.setFillColor(sf::Color::White);

	Textbox txt_height(font2, { btn_height.getPosition().x + 8.0f, btn_height.getPosition().y + 6.0f }, 14, sf::Color::White, false);
	txt_height.setText(std::to_string(artBoardHeight));
	Textbox txt_width(font2, { btn_width.getPosition().x + 8.0f, btn_width.getPosition().y + 6.0f }, 14, sf::Color::White, false);
	txt_width.setText(std::to_string(artBoardWidth));

	sf::Vector2f pos_height = btn_height.getPosition();
	float sizeX_height = btn_height.getSize().x;
	float sizeY_height = btn_height.getSize().y;
	sf::Vector2f pos_width = btn_width.getPosition();
	float sizeX_width = btn_width.getSize().x;
	float sizeY_width = btn_width.getSize().y;
	sf::Vector2f pos_black = btn_black.getPosition();
	float sizeX_black = btn_black.getSize().x;
	float sizeY_black = btn_black.getSize().y;
	sf::Vector2f pos_white = btn_white.getPosition();
	float sizeX_white = btn_white.getSize().x;
	float sizeY_white = btn_white.getSize().y;
	sf::Vector2f pos_create = btn_create.getPosition();
	float sizeX_create = btn_create.getSize().x;
	float sizeY_create = btn_create.getSize().y;
	sf::Vector2f pos_import = btn_import.getPosition();
	float sizeX_import = btn_import.getSize().x;
	float sizeY_import = btn_import.getSize().y;

	while (open_prompt.isOpen())
	{
		int x = sf::Mouse::getPosition(open_prompt).x;
		int y = sf::Mouse::getPosition(open_prompt).y;

		sf::Event evnt;
		while (open_prompt.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed)
			{
				closed = true;
				open_prompt.close();
			}
			else if (evnt.type == sf::Event::MouseButtonPressed)
			{
				if (evnt.mouseButton.button == sf::Mouse::Left)
				{
					if (x >= pos_height.x && x <= pos_height.x + sizeX_height && y >= pos_height.y && y <= pos_height.y + sizeY_height)
					{
						heightSelected = true;
						widthSelected = false;
						txt_height.selected(true);
						txt_width.selected(false);
					}
					else if (x >= pos_width.x && x <= pos_width.x + sizeX_width && y >= pos_width.y && y <= pos_width.y + sizeY_width)
					{
						widthSelected = true;
						heightSelected = false;
						txt_height.selected(false);
						txt_width.selected(true);
					}
					else if (x >= pos_black.x && x <= pos_black.x + sizeX_black && y >= pos_black.y && y <= pos_black.y + sizeY_black)
					{
						bg_col = sf::Color::Black;
					}
					else if (x >= pos_white.x && x <= pos_white.x + sizeX_white && y >= pos_white.y && y <= pos_white.y + sizeY_white)
					{
						bg_col = sf::Color::White;
					}
					else if (x >= pos_create.x && x <= pos_create.x + sizeX_create && y >= pos_create.y && y <= pos_create.y + sizeY_create)
					{
						//create new
						artBoardHeight = std::stoi(txt_height.getText());
						artBoardWidth = std::stoi(txt_width.getText());
						open_prompt.close();
						return closed;
					}
					else if (x >= pos_import.x && x <= pos_import.x + sizeX_import && y >= pos_import.y && y <= pos_import.y + sizeY_import)
					{
						//import using windows

						open_prompt.close();
						return closed;
					}
					else
					{
						heightSelected = false;
						widthSelected = false;
						txt_height.selected(false);
						txt_width.selected(false);
					}
				}
			}
			else if (evnt.type == sf::Event::KeyPressed)
			{
				if (evnt.key.code == sf::Keyboard::Key::Return)
				{
					heightSelected = false;
					widthSelected = false;
					txt_height.selected(false);
					txt_width.selected(false);
				}
			}
			else if (evnt.type == sf::Event::TextEntered)
			{
				if (heightSelected)
				{
					txt_height.typedOn(evnt);
				}
				else if (widthSelected)
				{
					txt_width.typedOn(evnt);
				}
			}
		}

		if (heightSelected)
		{
			btn_height.setOutlineThickness(1.0);
			btn_height.setOutlineColor(sf::Color::Cyan);
		}
		else if (!heightSelected && x >= pos_height.x && x <= pos_height.x + sizeX_height && y >= pos_height.y && y <= pos_height.y + sizeY_height)
		{
			btn_height.setOutlineThickness(1.0);
			btn_height.setOutlineColor(sf::Color(0, 255, 255, 150));
		}
		else
		{
			btn_height.setOutlineThickness(0.0);
			btn_height.setOutlineColor(sf::Color::Cyan);
		}
		if (widthSelected)
		{
			btn_width.setOutlineThickness(1.0);
			btn_width.setOutlineColor(sf::Color::Cyan);
		}
		else if (!widthSelected && x >= pos_width.x && x <= pos_width.x + sizeX_width && y >= pos_width.y && y <= pos_width.y + sizeY_width)
		{
			btn_width.setOutlineThickness(1.0);
			btn_width.setOutlineColor(sf::Color(0, 255, 255, 150));
		}
		else
		{
			btn_width.setOutlineThickness(0.0);
			btn_width.setOutlineColor(sf::Color::Transparent);
		}
		if (x >= pos_create.x && x <= pos_create.x + sizeX_create && y >= pos_create.y && y <= pos_create.y + sizeY_create)
		{
			btn_create.setFillColor(sf::Color(50, 50, 50));
		}
		else
		{
			btn_create.setFillColor(sf::Color(70, 70, 70));
		}
		if (x >= pos_import.x && x <= pos_import.x + sizeX_import && y >= pos_import.y && y <= pos_import.y + sizeY_import)
		{
			btn_import.setFillColor(sf::Color(50, 50, 50));
		}
		else
		{
			btn_import.setFillColor(sf::Color(70, 70, 70));
		}

		if (bg_col == sf::Color::Black)
		{
			btn_black.setOutlineThickness(3.0);
			btn_black.setOutlineColor(sf::Color::Cyan);
		}
		else if (bg_col != sf::Color::Black && x >= pos_black.x && x <= pos_black.x + sizeX_black && y >= pos_black.y && y <= pos_black.y + sizeY_black)
		{
			btn_black.setOutlineThickness(3.0);
			btn_black.setOutlineColor(sf::Color(0, 255, 255, 150));
		}
		else
		{
			btn_black.setOutlineThickness(0.0);
			btn_black.setOutlineColor(sf::Color::Cyan);
		}
		if (bg_col == sf::Color::White)
		{
			btn_white.setOutlineThickness(3.0);
			btn_white.setOutlineColor(sf::Color::Cyan);
		}
		else if (bg_col != sf::Color::White && x >= pos_white.x && x <= pos_white.x + sizeX_white && y >= pos_white.y && y <= pos_white.y + sizeY_white)
		{
			btn_white.setOutlineThickness(3.0);
			btn_white.setOutlineColor(sf::Color(0, 255, 255, 150));
		}
		else
		{
			btn_white.setOutlineThickness(0.0);
			btn_white.setOutlineColor(sf::Color::Transparent);
		}

		open_prompt.clear(sf::Color(70, 70, 70));
		open_prompt.draw(sprt_startMenu);
		open_prompt.draw(btn_height);
		open_prompt.draw(btn_width);
		open_prompt.draw(btn_black);
		open_prompt.draw(btn_white);
		open_prompt.draw(btn_create);
		open_prompt.draw(btn_import);
		open_prompt.draw(txt_canvas);
		open_prompt.draw(txt_imagination);
		txt_height.drawTo(open_prompt);
		txt_width.drawTo(open_prompt);
		open_prompt.draw(txt_create);
		open_prompt.draw(txt_import);
		open_prompt.display();
	}
	return closed;
}