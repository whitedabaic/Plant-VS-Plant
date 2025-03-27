#include "Util.h"
#include "Atlas.h"
#include "scene.h"
#include "MenuScene.h"
#include "GameScene.h"
#include "SelectorScene.h"
#include "SceneManager.h"

#include <graphics.h>

#pragma comment(lib, "Winmm.lib")

//所需 图片/图集 变量的定义:
//1.主菜单背景 图片
IMAGE imgMenuBackground; // 主菜单背景图片

//2.选角界面的资源 图片
IMAGE imgVS; // VS 艺术字图片
IMAGE img1P; // 1P 文本图片
IMAGE img2P; // 2P 文本图片

IMAGE img1PDesc; // 1P 键位描述图片
IMAGE img2PDesc; // 2P 键位描述图片

IMAGE imgGravestoneLeft; // 朝向左的墓碑图片
IMAGE imgGravestoneRight; // 朝向右的墓碑图片

IMAGE imgSelectorTip; // 选角界面提示文本图片
IMAGE imgSelectorBackground; // 选角界面背景图片

IMAGE img1PSelectorBtnIdleLeft; // 1P 向左选择按钮默认状态图片
IMAGE img1PSelectorBtnIdleRight; // 1P 向右选择按钮默认状态图片
IMAGE img1PSelectorBtnDownLeft; // 1P 向左选择按钮按下状态图片
IMAGE img1PSelectorBtnDownRight; // 1P 向右选择按钮按下状态图片

IMAGE img2PSelectorBtnIdleLeft; // 2P 向左选择按钮默认状态图片
IMAGE img2PSelectorBtnIdleRight; // 2P 向右选择按钮默认状态图片
IMAGE img2PSelectorBtnDownLeft; // 2P 向左选择按钮按下状态图片
IMAGE img2PSelectorBtnDownRight; // 2P 向右选择按钮按下状态图片

IMAGE imgPeashooterSelectorBackgroundLeft; // 选角界面朝向左的婉逗射手背景图片
IMAGE imgPeashooterSelectorBackgroundRight; // 选角界面朝向右的婉逗射手背景图片

IMAGE imgSunflowerSelectorBackgroundLeft; // 选角界面朝向左的龙日葵背景图片
IMAGE imgSunflowerSelectorBackgroundRight; // 选角界面朝向右的龙日葵背景图片

//3.游戏界面的资源 图片
IMAGE imgSky; // 天空图片
IMAGE imgHills; // 山脉图片
IMAGE imgPlatformLarge; //大型平台图片
IMAGE imgPlatformSmall; //小型平台图片

IMAGE img1PCursor; // 1P 指示光标图片
IMAGE img2PCursor; // 2P 指示光标图片

//4.游戏(战斗)界面角色的的资源 图集
Atlas atlasPeashooterIdleLeft; // 婉逗射手朝向左的默认动画图集
Atlas atlasPeashooterIdleRight; // 婉逗射手朝向右的默认动画图集
Atlas atlasPeashooterRunLeft; // 婉逗射手朝向左的跑步动画图集
Atlas atlasPeashooterRunRight; // 婉逗射手朝向右的跑步动画图集
Atlas atlasPeashooterAttackExLeft; // 婉逗射手朝向左的攻击动画图集
Atlas atlasPeashooterAttackExRight; // 婉逗射手朝向右的攻击动画图集
Atlas atlasPeashooterDieLeft; // 婉逗射手朝向左的死亡动画图集
Atlas atlasPeashooterDieRight; // 婉逗射手朝向右的死亡动画图集

Atlas atlasSunflowerIdleLeft; // 龙日葵朝向左的默认动画图集
Atlas atlasSunflowerIdleRight; // 龙日葵朝向右的默认动画图集
Atlas atlasSunflowerRunLeft; // 龙日葵朝向左的跑步动画图集
Atlas atlasSunflowerRunRight; // 龙日葵朝向右的跑步动画图集
Atlas atlasSunflowerAttackExLeft; // 龙日葵朝向左的攻击动画图集
Atlas atlasSunflowerAttackExRight; // 龙日葵朝向右的攻击动画图集
Atlas atlasSunflowerDieLeft; // 龙日葵朝向左的死亡动画图集
Atlas atlasSunflowerDieRight; // 龙日葵朝向右的死亡动画图集

//5.游戏(战斗)界面其他的资源 图集
IMAGE imgPea; // 豌豆图片

Atlas atlasPeaBreak; // 豌豆破碎动画图集
Atlas atlasSun; // 日光动画图集
Atlas atlasSunExplode; // 日光爆炸动画图集
Atlas atlasSunEx; // 特殊日光动画图集
Atlas atlasSunExExplode; // 特殊日光爆炸动画图集
Atlas atlasSunText; // “日” 文本动画图集

Atlas atlasRunEffect; // 奔跑特效动画图集
Atlas atlasJumpEffect; // 跳跃特效动画图集
Atlas atlasLandEffect; // 落地特效动画图集

//6.游戏结束界面的资源 图集
IMAGE img1PWinner; // 1P 获胜文本图片
IMAGE img2PWinner; // 2P 获胜文本图片
IMAGE imgWinnerBar; // 获胜玩家背景文本图片

IMAGE imgAvatarPeashooter; // 婉逗射手头像图片
IMAGE imgAvatarSunflower; // 龙日葵头像图片

Scene* menuScene = nullptr;
Scene* gameScene = nullptr;
Scene* selectorScene = nullptr;

SceneManager sceneManager;

void FlipAtlas(Atlas& src, Atlas& dst)
{
	dst.clear();
	for (int i = 0; i < src.getSize(); i++)
	{
		IMAGE imgFlipped;
		FlipImage(src.GetImage(i), &imgFlipped);
		dst.addImage(imgFlipped);
	}
}

void LoadGameResources()
{
	AddFontResourceEx(__T("resources/IPix.ttf"), FR_PRIVATE, NULL);

	loadimage(&imgMenuBackground, __T("resources/menu_background.png"));

	loadimage(&imgVS, _T("resources/vs.png"));
	loadimage(&img1P, _T("resources/1P.png")); loadimage(&img2P, _T("resources/2P.png"));
	loadimage(&img1PDesc, _T("resources/1P_desc.png")); loadimage(&img2PDesc, _T("resources/2P_desc.png"));
	loadimage(&imgGravestoneRight, _T("resources/gravestone.png"));
	FlipImage(&imgGravestoneRight, &imgGravestoneLeft);
	loadimage(&imgSelectorTip, _T("resources/selector_tip.png"));
	loadimage(&imgSelectorBackground, _T("resources/selector_background.png"));
	loadimage(&img1PSelectorBtnIdleRight, _T("resources/1p_selector_btn_idle.png"));
	FlipImage(&img1PSelectorBtnIdleRight, &img1PSelectorBtnIdleLeft);
	loadimage(&img1PSelectorBtnDownRight, _T("resources/1p_selector_btn_down.png"));
	FlipImage(&img1PSelectorBtnDownRight, &img1PSelectorBtnDownLeft);
	loadimage(&imgPeashooterSelectorBackgroundRight, _T("resources/peashooter_selector_background.png"));
	FlipImage(&imgPeashooterSelectorBackgroundRight, &imgPeashooterSelectorBackgroundLeft);
	loadimage(&imgSunflowerSelectorBackgroundRight, _T("resources/sunflower_selector_background.png"));
	FlipImage(&imgSunflowerSelectorBackgroundRight, &imgSunflowerSelectorBackgroundLeft);

	loadimage(&imgSky, _T("resources/sky.png"));
	loadimage(&imgHills, _T("resources/hills.png"));
	loadimage(&imgPlatformLarge, _T("resources/platform_large.png"));
	loadimage(&imgPlatformSmall, _T("resources/platform_small.png"));

	loadimage(&img1PCursor, _T("resources/1P_cursor.png"));
	loadimage(&img2PCursor, _T("resources/2P_cursor.png"));

	atlasPeashooterIdleRight.LoadFromFile(_T("resources/peashooter_idle_%d.png"), 9);
	FlipAtlas(atlasPeashooterIdleRight, atlasPeashooterIdleLeft);
	atlasPeashooterRunRight.LoadFromFile(_T("resources/peashooter_run_%d.png"), 5);
	FlipAtlas(atlasPeashooterRunRight, atlasPeashooterRunLeft);
	atlasPeashooterAttackExRight.LoadFromFile(_T("resources/peashooter_attack_ex_%d.png"), 3);
	FlipAtlas(atlasPeashooterAttackExRight, atlasPeashooterAttackExLeft);
	atlasPeashooterDieRight.LoadFromFile(_T("resources/peashooter_die_%d.png"), 4);
	FlipAtlas(atlasPeashooterDieRight, atlasPeashooterDieLeft);

	atlasSunflowerIdleRight.LoadFromFile(_T("resources/sunflower_idle_%d.png"), 8);
	FlipAtlas(atlasSunflowerIdleRight, atlasSunflowerIdleLeft);
	atlasSunflowerRunRight.LoadFromFile(_T("resources/sunflower_run_%d.png"), 5);
	FlipAtlas(atlasSunflowerRunRight, atlasSunflowerRunLeft);

	atlasSunflowerAttackExRight.LoadFromFile(_T("resources/sunflower_attack_ex_%d.png"), 9);
	FlipAtlas(atlasSunflowerAttackExRight, atlasSunflowerAttackExLeft);
	atlasSunflowerDieRight.LoadFromFile(_T("resources/sunflower_die_%d.png"), 2);
	FlipAtlas(atlasSunflowerDieRight, atlasSunflowerDieLeft);

	loadimage(&imgPea, _T("resources/pea.png"));
	atlasPeaBreak.LoadFromFile(_T("resources/pea_break_%d. png"), 3);
	atlasSun.LoadFromFile(_T("resources/sun_%d.png"), 5);

	atlasSunExplode.LoadFromFile(_T("resources/sun_explode_%d.png"), 5);
	atlasSunEx.LoadFromFile(_T("resources/sun_ex_%d.png"), 5);
	atlasSunExExplode.LoadFromFile(_T("resources/sun_ex_explode_%d.png"), 5);
	atlasSunText.LoadFromFile(_T("resources/sun_text_%d.png"), 6);

	atlasRunEffect.LoadFromFile(_T("resources/run_effect_%d.png"), 4);
	atlasJumpEffect.LoadFromFile(_T("resources/jump_effect_%d.png"), 5);
	atlasLandEffect.LoadFromFile(_T("resources/land_effect_%d.png"), 2);

	loadimage(&img1PWinner, _T("resources/1P_winner.png"));
	loadimage(&img2PWinner, _T("resources/2P_winner.png"));
	loadimage(&imgWinnerBar, _T("resources/winnner_bar.png"));

	loadimage(&imgAvatarPeashooter, _T("resources/avatar_peashooter.png"));
	loadimage(&imgAvatarSunflower, _T("resources/avatar_sunflower.png"));

	mciSendString(_T("open resources/bgm_game.mp3 alias bgmGame"), NULL, 0, NULL);
	mciSendString(_T("open resources/bgm_menu.mp3 alias bgmMenu"), NULL, 0, NULL);
	mciSendString(_T("open resources/pea_break1.mp3 alias peaBreak1"), NULL, 0, NULL);
	mciSendString(_T("open resources/pea_break2.mp3 alias peaBreak2"), NULL, 0, NULL);
	mciSendString(_T("open resources/pea_break_3.mp3 alias peaBreak3"), NULL, 0, NULL);
	mciSendString(_T("open resources/pea_shoot1.mp3 alias peaShoot1"), NULL, 8, NULL);
	mciSendString(_T("open resources/pea_shoot2.mp3 alias peaShoot2"), NULL, 0, NULL);
	mciSendString(_T("open resources/pea_shoot_ex.mp3 alias peaShootEx"), NULL, 0, NULL);
}

int main()
{
	ExMessage msg;
	const int FPS = 60;
	bool running = true;

	LoadGameResources();

	initgraph(1280, 720, EW_SHOWCONSOLE);

	BeginBatchDraw();

	menuScene = new MenuScene();
	gameScene = new GameScene();
	selectorScene = new SelectorScene();

	sceneManager.SetCurrentScene(menuScene);

	while (running)
	{
		DWORD frameStartTime = GetTickCount();

		while (peekmessage(&msg))
		{
			sceneManager.OnInput(msg);
		}

		static DWORD lastTickTime = GetTickCount();
		DWORD currentTickTime = GetTickCount();
		DWORD deltaTick = currentTickTime - lastTickTime;
		sceneManager.OnUpdate(deltaTick);
		lastTickTime = currentTickTime;

		cleardevice();
		sceneManager.OnDraw();
		FlushBatchDraw();

		DWORD frameEndTime = GetTickCount();
		DWORD frameDeltaTime = frameEndTime - frameStartTime;
		if (frameDeltaTime < 1000 / FPS)
			Sleep(1000 / FPS - frameDeltaTime);
		Sleep(1000 / FPS);
	}

	EndBatchDraw();

	return 0;
}