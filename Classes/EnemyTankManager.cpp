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

    for(int i=0;i<maxEnemyTankNum;i++)
    {
        //创建敌方坦克对象
        enemyTank = EnemyTank::create();
        //绑定精灵
        enemyTank->bindSprite(Sprite::create("QTank/enemy/canon11.png"));
        enemyTank->setScale(0.5);
        //enemyTank->setContentSize()
        enemyTank->reset();
        //enemyTank->setContentSize(Size(30,30));
        //log("EnemyTank %.2f %.2f" , enemyTank->getSprite()->getBoundingBox().size.width, enemyTank->getSprite()->getBoundingBox().size.height);

        //添加敌方坦克对象
        this->addChild(enemyTank->returnBulletManager());//添加子弹管理器
        this->addChild(enemyTank,10);
        
        //保存敌方坦克对象到列表
        enemyTankArr.pushBack(enemyTank);
    }
}
Vector<EnemyTank*> EnemyTankManager::returnEnemyTankManager()
{
    return this->enemyTankArr;
}