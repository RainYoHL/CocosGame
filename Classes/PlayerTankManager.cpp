#include "PlayerTankManager.h"
#include "time.h"

bool PlayerTankManager::init()
{
    srand((int)time(0));
    return true;
}

PlayerTankManager::PlayerTankManager()
{

}

PlayerTankManager::~PlayerTankManager()
{

}

void PlayerTankManager::addNewPlayer()
{
    auto player = Player::create();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    player->bindSprite(Sprite::create("QTank/plane1.png"));

    player->setPosition(CCRANDOM_0_1()*400,100);

    player->setPlayerScale(0.15);
    player->setPlayerPos(player->getPosition());
    this->addChild(player);

    //添加子弹管理器
    this->addChild(player->returnBulletManager());
    this->myPlayer.pushBack(player);
}

void PlayerTankManager::recvKey(EventKeyboard::KeyCode keyCode , bool isMove , int playerIndex)
{
    int index = 0;
    for (auto player : myPlayer)
    {
        if (index == playerIndex)
        {
            player->actionPlayer(keyCode,isMove);
            break;
        }
        index++;
    }
}

Vector<Player*> PlayerTankManager::returnPlayerTankManager()
{
    return this->myPlayer;
}