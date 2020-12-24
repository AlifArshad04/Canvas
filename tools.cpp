#include "global.hpp"

void brush_action(sf::RenderWindow& artBoard, sf::Event& evnt, float radius)
{
	mouseToggle(evnt);

	if (mousePressedDown)
	{
		if (last_Mouse_pos != sf::Mouse::getPosition(artBoard))
		{
			sf::Vector2i new_Mouse_pos = sf::Mouse::getPosition(artBoard);
			if (last_Mouse_pos.x != 0 && last_Mouse_pos.y != 0)
				brushConnect(new_Mouse_pos, last_Mouse_pos, radius);
			last_Mouse_pos = new_Mouse_pos;
			//std::cout << "X Y : " << vertices[lines_number][vertices[lines_number].getVertexCount() - 1].position.x << " " << vertices[lines_number][vertices[lines_number].getVertexCount() - 1].position.y << std::endl;
		}

		//curr_col = sf::Color::Color(rand() % 255, rand() % 255, rand() % 255);
	}

	//(*artBoard).display();
}

void pen_action(sf::RenderWindow& artBoard, sf::Event& evnt)
{
	mouseToggle(evnt);

	if (mousePressedDown)
	{
		if (last_Mouse_pos != sf::Mouse::getPosition(artBoard))
		{
			vertices[lines_number].append(sf::Vertex(sf::Vector2f(sf::Mouse::getPosition(artBoard)), curr_col));
			last_Mouse_pos = sf::Mouse::getPosition();
		}

		//curr_col = sf::Color::Color(rand() % 255, rand() % 255, rand() % 255);
	}

	//(*artBoard).display();
}

void colorPick_action(sf::Vector2i mouse_pos)
{
	int x, y;

	sf::RenderWindow colorPalette(sf::VideoMode(80, 40), "", sf::Style::None);
	sf::Texture tex_colorPalette;
	sf::Sprite spt_colorPalette;
	sf::Event evnt;

	tex_colorPalette.loadFromFile("ColorPalette.png");
	spt_colorPalette.setTexture(tex_colorPalette);

	colorPalette.setPosition(mouse_pos);

	while (colorPalette.isOpen())
	{
		x = sf::Mouse::getPosition(colorPalette).x;
		y = sf::Mouse::getPosition(colorPalette).y;

		if (x < 0 || y < 0 || x > 80 || y > 40)
		{
			colorPickSelected = false;
			colorPalette.close();
			break;
		}

		while (colorPalette.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::MouseButtonPressed)
			{
				if (evnt.mouseButton.button == sf::Mouse::Left)
				{
					if (x >= 0 && x < 20 && y >= 0 && y < 20)
					{
						curr_col = sf::Color::White;
					}
					else if (x >= 20 && x < 40 && y >= 0 && y < 20)
					{
						curr_col = sf::Color::Cyan;
					}
					else if (x >= 40 && x < 60 && y >= 0 && y < 20)
					{
						curr_col = sf::Color::Yellow;
					}
					else if (x >= 60 && x < 80 && y >= 0 && y < 20)
					{
						curr_col = sf::Color::Magenta;
					}
					else if (x >= 0 && x < 20 && y >= 20 && y < 40)
					{
						curr_col = sf::Color::Black;
					}
					else if (x >= 20 && x < 40 && y >= 20 && y < 40)
					{
						curr_col = sf::Color::Red;
					}
					else if (x >= 40 && x < 60 && y >= 20 && y < 40)
					{
						curr_col = sf::Color::Blue;
					}
					else if (x >= 60 && x < 80 && y >= 20 && y < 40)
					{
						curr_col = sf::Color::Green;
					}
					colorPickSelected = false;
					colorPalette.close();
				}
			}
		}
		colorPalette.clear(sf::Color::White);
		colorPalette.draw(spt_colorPalette);
		colorPalette.display();
	}
}

float brushSize_action(sf::Vector2i mouse_pos, float current)
{
	int x, y;
	float size = current;

	sf::RenderWindow sizePicker(sf::VideoMode(80, 30), "", sf::Style::None);
	sf::Texture tex_sizePicker;
	sf::Sprite spt_sizePicker;
	sf::Event evnt;

	tex_sizePicker.loadFromFile("size_icons.png");
	spt_sizePicker.setTexture(tex_sizePicker);

	sizePicker.setPosition(mouse_pos);

	while (sizePicker.isOpen())
	{
		x = sf::Mouse::getPosition(sizePicker).x;
		y = sf::Mouse::getPosition(sizePicker).y;

		if (x < 0 || y < 0 || x > 80 || y > 30)
		{
			sizePicker.close();
			break;
		}

		while (sizePicker.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::MouseButtonPressed)
			{
				if (evnt.mouseButton.button == sf::Mouse::Left)
				{
					if (x >= 0 && x < 26 && y >= 0 && y < 30)
					{
						size = 4.0;
					}
					else if (x >= 26 && x < 53 && y >= 0 && y < 30)
					{
						size = 8.0;
					}
					else if (x >= 53 && x < 80 && y >= 0 && y < 30)
					{
						size = 10.5;
					}
					sizePicker.close();
				}
			}
		}
		sizePicker.clear(sf::Color(50, 50, 50));
		sizePicker.draw(spt_sizePicker);
		sizePicker.display();
	}
	return size;
}