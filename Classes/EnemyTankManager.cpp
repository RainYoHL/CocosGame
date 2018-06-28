#include "EnemyTankManager.h"
#include "Player.h"  
#include "EnemyTank.h"

bool EnemyTankManager::init()
{
    createEnemyTank();          //创建敌方坦克缓存
    return true;
}

void EnemyTankManager::createEnemyTank()
{
    EnemyTank* enemyTank = NULL;
    Sprite* sprite = NULL;

    for(int i=0;i<maxEnemyTankNum;i++)
    {
    
        //创建敌方坦克对象
        enemyTank = EnemyTank::create();
        //绑定精灵
        enemyTank->bindSprite(Sprite::create("Q版坦克素材/enemy/canon17.png"));
        enemyTank->reset();

        //添加敌方坦克对象
        this->addChild(enemyTank,10);
        
        //保存敌方坦克对象到列表
        enemyTankArr.pushBack(enemyTank);
    }
}