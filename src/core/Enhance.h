#pragma once

class Enhance {
public:
    Enhance();

    // 获取武器等级
    int getWeaponLevel() const;

    // 使用积分升级武器
    bool upgradeWeapon(int points);

    // 获取武器弹道
    int getWeaponTrajectory() const;

    // 获取武器发射速度
    float getWeaponFireRate() const;

private:
    int weaponLevel;
    int weaponTrajectory;
    float weaponFireRate;

    // 更新武器属性
    void updateWeaponAttributes();
};
