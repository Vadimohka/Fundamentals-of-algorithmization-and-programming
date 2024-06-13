#include "gamewindow.h"

GameWindow::GameWindow() {
    srand(static_cast<unsigned>(time(0)));

    font = std::make_unique<sf::Font>();
    if (!font->loadFromFile("D:\\COURSEWORK\\BuckshotRoulette\\fonts\\EpilepsySansBold.ttf")) {
        std::cout << "Error while loading font!" << std::endl;
    }
    textRound = std::make_unique<sf::Text>();
    textRound->setFont(*font);

    textReload = std::make_unique<sf::Text>();
    textReload->setFont(*font);

    statusText = std::make_unique<sf::Text>();
    statusText->setFont(*font);
    statusText->setPosition(100, 300);
    statusText->setCharacterSize(25);

    livesText = std::make_unique<sf::Text>();
    livesText->setFont(*font);
    livesText->setPosition(1000, 300);
    livesText->setCharacterSize(25);

    backgroundTexture = std::make_unique<sf::Texture>();
    if (!backgroundTexture->loadFromFile("D:\\COURSEWORK\\BuckshotRoulette\\images\\table.png")) {
        std::cout << "Error while loading table!" << std::endl;
        return;
    }
    background = std::make_unique<sf::Sprite>();
    background->setTexture(*backgroundTexture);

    dealerTexture = std::make_unique<sf::Texture>();
    if (!dealerTexture->loadFromFile("D:\\COURSEWORK\\BuckshotRoulette\\images\\dealer.png")) {
        std::cout << "Error while loading dealer!" << std::endl;
        return;
    }
    dealer = std::make_unique<sf::Sprite>();
    dealer->setTexture(*dealerTexture);
    dealer->setPosition(1000, 100);

    gun1Texture = std::make_unique<sf::Texture>();
    if (!gun1Texture->loadFromFile("D:\\COURSEWORK\\BuckshotRoulette\\images\\tohim.png")) {
        std::cout << "Error while loading dealer!" << std::endl;
        return;
    }
    gun1 = std::make_unique<sf::Sprite>();
    gun1->setTexture(*gun1Texture);
    gun1->setPosition(900, 100);

    nu = std::make_unique<Button>("D:\\COURSEWORK\\BuckshotRoulette\\images\\nu.png");
    nu->setCenterPosition();
    nu->move(200, 350);
    u = std::make_unique<Button>("D:\\COURSEWORK\\BuckshotRoulette\\images\\you.png");
    u->setCenterPosition();
    u->move(-200, 350);
    menu = std::make_unique<Button>("D:\\COURSEWORK\\BuckshotRoulette\\images\\menu.png");
    menu->setPosition(1700, 20);
    textRound->setString("");
    textReload->setString("");
    statusText->setString("");
    livesText->setString("");
    chamber = loadChamber();

    playerHints = generateHints(2);
    computerHints = generateHints(2);
}
bool GameWindow::inMenu() {
    if (imenu) {
        return true;
    }
    else return false;
}

void GameWindow::quickSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int i = left, j = right;
    bool pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] > pivot) i++;
        while (arr[j] < pivot) j--;
        if (i <= j) {
            std::swap(left, right);
            i++;
            j--;
        }
    }

    if (left < j) quickSort(arr, left, j);
    if (i < right) quickSort(arr, i, right);
}

void GameWindow::draw(sf::RenderWindow* window) {
    sf::Vector2u windowSize = window->getSize();
    sf::Vector2u textureSize = backgroundTexture->getSize();
    background->setScale(static_cast<float>(windowSize.x) / textureSize.x, static_cast<float>(windowSize.y) / textureSize.y);
    window->draw(*background);
    window->draw(*dealer);
    u->draw(window);
    nu->draw(window);
    menu->draw(window);
    
    textRound->setFillColor(sf::Color::White);
    textRound->setPosition(100, 100);
    textRound->setCharacterSize(54);
    window->draw(*textRound);
    window->draw(*textReload);
    window->draw(*statusText);
    window->draw(*livesText);

    dealerY += 0.04f * dealerDirection;
    if (dealerY >= 120.0f || dealerY <= 90.0f) {
        dealerDirection *= -1.0f;
    }
    dealer->setPosition(650, dealerY);
    for (const auto& hintButton : hintButtons) {
        hintButton->draw(window);
    }
}

void GameWindow::anim1(sf::RenderWindow* window) {
    window->draw(*gun1);
    dealerY += 0.04f * dealerDirection;
    if (dealerY >= 120.0f || dealerY <= 90.0f) {
        dealerDirection *= -1.0f;
    }
    dealer->setPosition(650, dealerY);
    window->display();
}
void GameWindow::drawH(sf::RenderWindow* window) {
   /* for (const auto& hintButton : hintButtons) {
        hintButton->draw(window);
    }*/
}
std::vector<Hint> GameWindow::generateHints(int round) {
    std::vector<Hint> hints;
    int hintCount = (round == 2) ? 4 : (round == 3) ? 8 : 0;
    for (int i = 0; i < hintCount; ++i) {
        hints.push_back(getRandomHint());
    }
    return hints;
}

bool GameWindow::binarySearchHint( std::vector<int>& hints,  int& targetHint, int left, int right) {
    if (left > right) {
        return false;
    }

    int mid = left + (right - left) / 2;

    if (hints[mid] == targetHint) {
        return true;
    }
    else if (hints[mid] < targetHint) {
        return binarySearchHint(hints, targetHint, mid + 1, right);
    }
    else {
        return binarySearchHint(hints, targetHint, left, mid - 1);
    }
}

void GameWindow::createHintButtons(const std::vector<Hint>& playerHints) {
    hintButtons.clear();
    int numButtons = static_cast<int>(playerHints.size());
    int buttonSize = 100; 
    int windowWidth = 800;  
    int windowHeight = 800;  

    for (size_t i = 0; i < playerHints.size(); ++i) {
        std::string imagePath;
        switch (playerHints[i].type) {
        case MAGNIFIER:
            imagePath = "D:\\COURSEWORK\\BuckshotRoulette\\images\\lupaa.png";
            break;
        case CIGARETTES:
            imagePath = "D:\\COURSEWORK\\BuckshotRoulette\\images\\cigarettes.png";
            break;
        case HANDCUFFS:
            imagePath = "D:\\COURSEWORK\\BuckshotRoulette\\images\\handcuffs.png";
            break;
        case KNIFE:
            imagePath = "D:\\COURSEWORK\\BuckshotRoulette\\images\\nozh.png";
            break;
        case BEER:
            imagePath = "D:\\COURSEWORK\\BuckshotRoulette\\images\\tekilaa.png";
            break;
        case INVERTER:
            imagePath = "D:\\COURSEWORK\\BuckshotRoulette\\images\\minimize.png";
            break;
        case ADRENALINE:
            imagePath = "D:\\COURSEWORK\\BuckshotRoulette\\images\\minimize.png";
            break;
        }
        auto hintButton = std::make_unique<Button>(imagePath);
        
        quickSort(hintsBtns, );
        if (i < numButtons / 4) {
            // Top left
            hintButton->setPosition(300, 800 + i * buttonSize);
        }
        else if (i < numButtons / 2) {
            // Top right
            hintButton->setPosition(windowWidth - buttonSize - 100, 750);
        }
        else if (i < 3 * numButtons / 4) {
            // Bottom right
            hintButton->setPosition(windowWidth - buttonSize - 100, windowHeight - buttonSize - 10 - (i - numButtons / 2) * buttonSize);
        }
        else {
            // Bottom left
            hintButton->setPosition(350, windowHeight - buttonSize - 10 - (i - 3 * numButtons / 4) * buttonSize);
        }

        hintButtons.push_back(std::move(hintButton));
    }
}
Hint GameWindow::getRandomHint() {
    Hint hint;
    int type = rand() % 7;
    switch (type) {
    case MAGNIFIER:
        hint.type = MAGNIFIER;
        hint.name = "Magnifier";
        break;
    case CIGARETTES:
        hint.type = CIGARETTES;
        hint.name = "Cigarettes";
        break;
    case HANDCUFFS:
        hint.type = HANDCUFFS;
        hint.name = "Handcuffs";
        break;
    case KNIFE:
        hint.type = KNIFE;
        hint.name = "Knife";
        break;
    case BEER:
        hint.type = BEER;
        hint.name = "Beer";
        break;
    case INVERTER:
        hint.type = INVERTER;
        hint.name = "Inverter";
        break;
    case ADRENALINE:
        hint.type = ADRENALINE;
        hint.name = "Adrenaline";
        break;
    }
    return hint;
}

void GameWindow::russianRoulette(sf::Event* event, sf::RenderWindow* window) {
    if (round <= 3) {
        if (!chamber.empty()) {
            int playerLives = getInitialLives(round);
            int computerLives = getInitialLives(round);
            nextRound(window);
            int liveRounds = std::count(chamber.begin(), chamber.end(), true);
            int blankRounds = chamber.size() - liveRounds;
            reloadText(window, liveRounds, blankRounds);
            if (playerLives > 0 && computerLives > 0) {
                if (isPlayer) {
                    playerTurn(playerLives, computerLives, event, window, playerHints, computerHints);
                }
                else {
                    computerTurn(chamber, playerLives, computerLives, window);
                }
            }
        }
        else {
            chamber = loadChamber();
            round++;
        }
    }
}

void GameWindow::buckshotRoulette(sf::Event* event, sf::RenderWindow* window) {
    if (menu->isClicked(event, window)) {
        imenu = true;
    }
    if (round <= 3) {
        if (!chamber.empty()) {
            if (round == 2) {
                createHintButtons(playerHints);
                drawH(window);
            }
            if (round == 3) {
                r = 3;
                createHintButtons(playerHints);
                drawH(window);
            }
            int playerLives = getInitialLives(round);
            int computerLives = getInitialLives(round);
            lives(window, playerLives, computerLives);
            nextRound(window);
            int liveRounds = std::count(chamber.begin(), chamber.end(), true);
            int blankRounds = chamber.size() - liveRounds;
            reloadText(window, liveRounds, blankRounds);
            if (playerLives > 0 && computerLives > 0) {
                if (isPlayer) {
                    playerTurn(playerLives, computerLives, event, window, playerHints, computerHints);
                }
                else {
                    computerTurn(chamber, playerLives, computerLives, window);
                }
            }
        }
        else {
            chamber = loadChamber();
            round++;
        }
    }
}

void GameWindow::lives(sf::RenderWindow* window, int pl, int dl) {
    livesText->setString("your lives: " + std::to_string(pl)+"\ndealer lives: " + std::to_string(dl));
    livesText->setFillColor(sf::Color::White);
    livesText->setPosition(1500, 100);
    livesText->setCharacterSize(54);
    window->draw(*livesText);
    window->display();
}
void GameWindow::nextRound(sf::RenderWindow* window) {
    textRound->setString("round " + std::to_string(round) );
    textRound->setFillColor(sf::Color::White);
    textRound->setPosition(100, 100);
    textRound->setCharacterSize(54);
    window->draw(*textRound);
    window->display();
}
void GameWindow::reloadText(sf::RenderWindow* window, int live, int blank) {
    textReload->setString("The shotgun is reloaded with " + std::to_string(live) + " live and " + std::to_string(blank) + " blank");
    textReload->setFillColor(sf::Color::White);
    textReload->setPosition(700, 300);
    textReload->setCharacterSize(24);
    window->draw(*textReload);
    window->display();
}

int GameWindow::getInitialLives(int round) {
    switch (round) {
    case 1: return 2;
    case 2: return 4;
    case 3: return 5;
    default: return 2;
    }
}

std::vector<bool> GameWindow::loadChamber() {
    int totalBullets = rand() % 6 + 3; // Between 3 and 8
    int liveBullets = rand() % (totalBullets - 1) + 1; // At least 1 live round
    std::vector<bool> chamber(totalBullets, false);
    for (int i = 0; i < liveBullets; ++i) {
        chamber[i] = true; // True represents a live bullet
    }
    std::random_shuffle(chamber.begin(), chamber.end());
    return chamber;
}

bool GameWindow::useHint(Hint hint, std::vector<bool>& chamber, int& lives, int& opponentLives, std::vector<Hint>& hints, std::vector<Hint>& opponentHints) {
    switch (hint.type) {
    case MAGNIFIER:
        statusText->setString("Hint used : " + hint.name + ".The current bullet is " + (chamber.back() ? "LIVE" : "BLANK") + ".");
        std::cout << "Hint used: " << hint.name << ". The current bullet is " << (chamber.back() ? "LIVE" : "BLANK") << ".\n";
        break;
    case CIGARETTES:
        statusText->setString("Hint used: " + hint.name + ". You gain 1 life.");
        std::cout << "Hint used: " << hint.name << ". You gain 1 life.\n";
        lives++;
        break;
    case HANDCUFFS:
        statusText->setString("Hint used: " + hint.name + ". Opponent skips turn.");
        std::cout << "Hint used: " << hint.name << ". Opponent skips turn.\n";
        return true; // Skip opponent's turn
    case KNIFE:
        statusText->setString("Hint used: " + hint.name + ". Damage from next shot is doubled if it's a live round.");
        std::cout << "Hint used: " << hint.name << ". Damage from next shot is doubled if it's a live round.\n";
        if (chamber.back()) {
            opponentLives -= 2; // Double damage
            statusText->setString("It's a LIVE round. Opponent loses 2 lives.");
            std::cout << "It's a LIVE round. Opponent loses 2 lives.\n";
        }
        else {
            statusText->setString("It's a BLANK round. No effect.");
            std::cout << "It's a BLANK round. No effect.\n";
        }
        chamber.pop_back();
        break;
    case BEER:
        statusText->setString("Hint used: " + hint.name + ". Current bullet is removed.");
        std::cout << "Hint used: " << hint.name << ". Current bullet is removed.\n";
        chamber.pop_back();
        break;
    case INVERTER:
        statusText->setString("Hint used: " + hint.name + ". Current bullet is inverted.");
        std::cout << "Hint used: " << hint.name << ". Current bullet is inverted.\n";
        if (!chamber.empty()) {
            chamber.back() = !chamber.back();
        }
        break;
    case ADRENALINE:
        if (!opponentHints.empty()) {
            Hint stolenHint = opponentHints.back();
            opponentHints.pop_back();
            statusText->setString("Hint used: " + hint.name + ". Stolen and used opponent's hint: " + stolenHint.name + ".");
            std::cout << "Hint used: " << hint.name << ". Stolen and used opponent's hint: " << stolenHint.name << ".\n";
            useHint(stolenHint, chamber, lives, opponentLives, hints, opponentHints);
        }
        else {
            statusText->setString("Hint used: " + hint.name + ". No hints to steal from opponent.");
            std::cout << "Hint used: " << hint.name << ". No hints to steal from opponent.\n";
        }
        break;
    default:
        std::cerr << "Unknown hint type.\n";
        break;
    }
    return false;
}

void GameWindow::playerTurn(int& playerLives, int& computerLives, sf::Event* event, sf::Window* window, std::vector<Hint>& playerHints, std::vector<Hint>& computerHints) {
    if (!playerHints.empty()) {
        for (size_t i = 0; i < hintButtons.size(); ++i) {
            if (hintButtons[i]->isClicked(event, window)) {
                Hint chosenHint = playerHints[i];
                playerHints.erase(playerHints.begin() + i);
                hintButtons.erase(hintButtons.begin() + i); // Remove the button as well
                bool turnAgain = useHint(chosenHint, chamber, playerLives, computerLives, playerHints, computerHints);
                if (turnAgain) {
                    isPlayer = true; // Player gets another turn
                }
            }
        }
    }
        if (u->isClicked(event, window)) {
            bool bullet = chamber.back();
            chamber.pop_back();
            if (bullet) {
                --playerLives;
                isPlayer = false;
            }
            else {
                isPlayer = true;
            }
        }
        else if (nu->isClicked(event, window)) {
            bool bullet = chamber.back();
            chamber.pop_back();
            if (bullet) {
                --computerLives;
                isPlayer = false;
            }
            else {
                isPlayer = false;
            }
        }
    
}

void GameWindow::computerTurn(std::vector<bool>& chamber, int& playerLives, int& computerLives, sf::Window* window) {
    int choice = rand() % 2 + 1;
    if (choice == 1) {
        bool bullet = chamber.back();
        chamber.pop_back();
        if (bullet) {
            --computerLives;
            isPlayer = true;
        }
        else {
            isPlayer = false;
        }
    }
    else if (choice == 2) {
        bool bullet = chamber.back();
        chamber.pop_back();
        if (bullet) {
            --playerLives;
            isPlayer = true;
        }
        else {
            isPlayer = true;
        }
    }
}