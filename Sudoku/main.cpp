#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <chrono>

int x = 0; int y = 0; int n = 1; int mistake = 1; int mt[4] = {0, 0, 0, 0};

std::string strm[3][9][9] = { { {"", "", "", "", "", "", "", "", ""}, {"", "", "", "", "", "", "", "", ""}, {"", "", "", "", "", "", "", "", ""}, {"", "", "", "", "", "", "", "", ""}, {"", "", "", "", "", "", "", "", ""}, {"", "", "", "", "", "", "", "", ""}, {"", "", "", "", "", "", "", "", ""}, {"", "", "", "", "", "", "", "", ""}, {"", "", "", "", "", "", "", "", ""} },
    { {"", "", "", "7", "5", "1", "8", "", ""}, { "2", "", "", "", "9", "3", "", "", ""}, { "7", "", "", "", "8", "2", "1", "9", "6"}, { "5", "1", "3", "2", "", "", "9", "", ""}, { "", "", "", "", "4", "", "6", "", "3"}, { "", "", "4", "1", "3", "", "", "", "7"}, { "9", "2", "", "5", "1", "", "3", "", ""}, { "", "", "", "", "6", "", "4", "", "9"}, { "", "", "7", "", "", "", "5", "", ""} },
    { {"", "", "8", "", "2", "", "", "1", "3"}, {"3", "", "", "", "", "", "6", "", ""}, {"", "9", "", "6", "", "", "2", "", "4"}, {"9", "", "", "", "7", "", "", "", ""}, {"8", "", "", "", "", "9", "", "", "6"}, {"4", "7", "", "2", "5", "", "", "", "1"}, {"2", "", "9", "", "6", "4", "5", "", ""}, {"", "", "", "1", "3", "", "", "7", ""}, {"", "3", "", "", "", "8", "", "", ""} } };

void CreateYourOwnSudoku() {
    std::cout << "{";
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 8; ++j) {
            std::cout << '"';
            std::cout << strm[n][i][j];
            std::cout << '"' << ", ";
        }
        std::cout << '"';
        std::cout << strm[n][i][8];
        std::cout << '"';
        std::cout << "}, {";
    }
}

void DrowStartPage(sf::Font& font, sf::RenderWindow& window1) {
    sf::Text text;
    text.setFont(font);
    text.setString("Enter the sudoku number: ");
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setPosition(100, 130);
    window1.draw(text);
    text.setFont(font);
    text.setString(std::to_string(n));
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setPosition(600, 130);
    window1.draw(text);
    text.setFont(font);
    text.setString("Do you need hints?");
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setPosition(100, 200);
    window1.draw(text);
    text.setFont(font);
    text.setString("Yes");
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text.setPosition(500, 200);
    window1.draw(text);
    text.setFont(font);
    text.setString("No");
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text.setPosition(670, 200);
    window1.draw(text);
    text.setFont(font);
    text.setString("Play");
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold);
    text.setPosition(430, 350);
    window1.draw(text);
}
void DrowButton(sf::RenderWindow& window1){
    sf::ConvexShape left_button(3);
    left_button.setPoint(0, sf::Vector2f(588, 140));
    left_button.setPoint(1, sf::Vector2f(588, 160));
    left_button.setPoint(2, sf::Vector2f(568, 150));
    left_button.setFillColor(sf::Color::Red);
    sf::ConvexShape right_button(3);
    right_button.setPoint(0, sf::Vector2f(625, 140));
    right_button.setPoint(1, sf::Vector2f(625, 160));
    right_button.setPoint(2, sf::Vector2f(645, 150));
    right_button.setFillColor(sf::Color::Red);
    window1.draw(left_button);
    window1.draw(right_button);
}
void DrowSudoku1(sf::Font& font, sf::RenderWindow& window1, sf::Image& img1) {
    DrowStartPage(font, window1);
    window1.display();
}
void Event1(sf::RenderWindow& window1, sf::Image& img1) {
    sf::Font font;
    if (!font.loadFromFile("D:/Proga/Calender/Raleway-Regular.ttf"));
    sf::Texture texture;
    texture.loadFromImage(img1);
    sf::Sprite sprite;
    sprite.setTexture(texture, true);
    while (window1.isOpen()) {
        sf::Event event;
        while (window1.pollEvent(event)) {
            if (event.type == sf::Event::Closed || 
               (event.mouseButton.y > 250)) window1.close();
            else if (event.type == sf::Event::MouseButtonPressed &&
                event.mouseButton.button == sf::Mouse::Left) {
                if (event.mouseButton.y < 170 && event.mouseButton.x > 610) ++n;
                else if (event.mouseButton.y < 170 && event.mouseButton.x > 565) --n;
                else if (event.mouseButton.y < 250 && event.mouseButton.x > 600) mistake = 0;
                else if (event.mouseButton.y < 250 && event.mouseButton.x < 600) mistake = 1;
            }
            else if (event.key.code == sf::Keyboard::Backspace) n = 1;
            else if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode < 128) n = event.text.unicode - 48;
            }
        }
        window1.clear();
        window1.draw(sprite);
        DrowButton(window1);
        DrowSudoku1(font, window1, img1);
    }
}

void Field(sf::RenderWindow& window, sf::Image& img) {
    int a = 150;
    for (int k = 0; k < 10; ++k) {
        for (int i = 275; i < 725; ++i) {
            img.setPixel(i, a, sf::Color::Black);
            img.setPixel(a + 125, i - 125, sf::Color::Black);
        }
        a += 50;
    }
    a = 150;
    for (int k = 0; k < 4; ++k) {
        for (int i = 275; i < 725; ++i) {
            img.setPixel(i, a - 1, sf::Color::Black);
            img.setPixel(i, a + 1, sf::Color::Black);
            img.setPixel(a + 124, i - 125, sf::Color::Black);
            img.setPixel(a + 126, i - 125, sf::Color::Black);
        }
        a += 150;
    }
}
void Numbers(sf::Font& font, sf::RenderWindow& window) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            sf::Text text;
            text.setFont(font);
            text.setString(strm[n][i][j]);
            text.setCharacterSize(50);
            text.setFillColor(sf::Color::Black);
            text.setStyle(sf::Text::Bold);
            text.setPosition(275 + 50 * i + 12, 138 + 50 * j);
            window.draw(text);
        }
    }
    sf::Text text;
    text.setFont(font);
    text.setString("Sudoku");
    text.setCharacterSize(70);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setPosition(360, 30);
    window.draw(text);
    text.setFont(font);
    text.setString("Your time:");
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setPosition(780, 40);
    window.draw(text);
    if (mistake > 0) {
        sf::Text text;
        text.setFont(font);
        text.setString("Your mistakes:");
        text.setCharacterSize(30);
        text.setFillColor(sf::Color::Black);
        text.setStyle(sf::Text::Bold);
        text.setPosition(760, 200);
        window.draw(text);
        text.setFont(font);
        text.setString(std::to_string(mistake - 1));
        text.setCharacterSize(30);
        text.setFillColor(sf::Color::Black);
        text.setStyle(sf::Text::Bold);
        text.setPosition(850, 240);
        window.draw(text);
    }
}
void Mistakes(sf::Font& font, sf::RenderWindow& window) {
    std::string ch = "";
    for (int i = 0; i < 9; ++i) {
        if (i == x);
        else if (strm[n][i][y] == strm[n][x][y] && strm[n][x][y] != "") {
            ch = "!";
            mt[0] = 1; break;
        }
        else mt[0] = 0; ch = "";
    }
    for (int i = 0; i < 9; ++i) {
        if (i == y);
        else if (strm[n][x][i] == strm[n][x][y] && strm[n][x][y] != "") {
            ch = "!"; mt[1] = 1; break;
        }
        else mt[1] = 0;
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (x / 3 * 3 + i == x && y / 3 * 3 + j == y);
            else if (strm[n][x / 3 * 3 + i][y / 3 * 3 + j] == strm[n][x][y] && strm[n][x][y] != "") {
                ch = "!"; mt[2] = 1; break;
            }
            else mt[2] = 0;
        }
    }
    sf::Text text;
    text.setFont(font);
    text.setString(ch);
    text.setCharacterSize(80);
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold);
    text.setPosition(790, 220);
    window.draw(text);
}
void DrowSudoku(sf::Font& font, sf::RenderWindow& window, sf::Image& img) {
    Numbers(font, window);
    if (mistake > 0) Mistakes(font, window);
    if (mt[3] == 0 && (mt[0] == 1 || mt[1] == 1 || mt[2] == 1)) {
        mt[3] = 1;
        ++mistake;
    }
    if (mt[0] == 0 && mt[1] == 0 && mt[2] == 0) mt[3] = 0;
    window.display();
}

void Event(sf::RenderWindow& window, sf::Image& img) {
    if (n > 2) n = 2;
    auto begin = std::chrono::high_resolution_clock::now();
    sf::Font font;
    if (!font.loadFromFile("D:/Proga/Sudoku/Raleway-Regular.ttf"));
    sf::Texture texture;
    texture.loadFromImage(img);
    sf::Sprite sprite;
    sprite.setTexture(texture, true);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            else if (event.type == sf::Event::MouseButtonPressed &&
                event.mouseButton.button == sf::Mouse::Left) {
                x = (event.mouseButton.x - 275) / 50;
                y = (event.mouseButton.y - 150) / 50;
            }
            else if (event.key.code == sf::Keyboard::Backspace) strm[n][x][y] = "";
            else if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode < 128) strm[n][x][y] = event.text.unicode; mt[3] = 0;
            }
        }
        window.clear();
        window.draw(sprite);
        auto end = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::seconds>(end - begin);
        std::string t = std::to_string((time.count()) / 60) + " : ";
        if ((time.count()) % 60 < 10) t += "0";
        t += std::to_string((time.count()) % 60);
        sf::Text text;
        text.setFont(font);
        text.setString(t);
        text.setCharacterSize(35);
        text.setFillColor(sf::Color::Black);
        text.setStyle(sf::Text::Bold);
        text.setPosition(820, 70);
        window.draw(text);
        DrowSudoku(font, window, img);
    }
}

int main()
{
    sf::RenderWindow window1(sf::VideoMode(1000, 700), "SFML");
    sf::Image img1;
    img1.create(1000, 700, sf::Color::White);
    Event1(window1, img1);

    sf::RenderWindow window(sf::VideoMode(1000, 700), "SFML works!");
    sf::Image img;
    img.create(1000, 700, sf::Color::White);
    Field(window, img);
    Event(window, img);

    if (n == 0) CreateYourOwnSudoku();
    
    return 0;
}