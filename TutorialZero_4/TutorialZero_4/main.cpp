#include "Util.h"
#include "Atlas.h"
#include "scene.h"
#include "MenuScene.h"
#include "GameScene.h"
#include "SelectorScene.h"
#include "SceneManager.h"

#include <graphics.h>

#pragma comment(lib, "Winmm.lib")

//���� ͼƬ/ͼ�� �����Ķ���:
//1.���˵����� ͼƬ
IMAGE imgMenuBackground; // ���˵�����ͼƬ

//2.ѡ�ǽ������Դ ͼƬ
IMAGE imgVS; // VS ������ͼƬ
IMAGE img1P; // 1P �ı�ͼƬ
IMAGE img2P; // 2P �ı�ͼƬ

IMAGE img1PDesc; // 1P ��λ����ͼƬ
IMAGE img2PDesc; // 2P ��λ����ͼƬ

IMAGE imgGravestoneLeft; // �������Ĺ��ͼƬ
IMAGE imgGravestoneRight; // �����ҵ�Ĺ��ͼƬ

IMAGE imgSelectorTip; // ѡ�ǽ�����ʾ�ı�ͼƬ
IMAGE imgSelectorBackground; // ѡ�ǽ��汳��ͼƬ

IMAGE img1PSelectorBtnIdleLeft; // 1P ����ѡ��ťĬ��״̬ͼƬ
IMAGE img1PSelectorBtnIdleRight; // 1P ����ѡ��ťĬ��״̬ͼƬ
IMAGE img1PSelectorBtnDownLeft; // 1P ����ѡ��ť����״̬ͼƬ
IMAGE img1PSelectorBtnDownRight; // 1P ����ѡ��ť����״̬ͼƬ

IMAGE img2PSelectorBtnIdleLeft; // 2P ����ѡ��ťĬ��״̬ͼƬ
IMAGE img2PSelectorBtnIdleRight; // 2P ����ѡ��ťĬ��״̬ͼƬ
IMAGE img2PSelectorBtnDownLeft; // 2P ����ѡ��ť����״̬ͼƬ
IMAGE img2PSelectorBtnDownRight; // 2P ����ѡ��ť����״̬ͼƬ

IMAGE imgPeashooterSelectorBackgroundLeft; // ѡ�ǽ��泯����������ֱ���ͼƬ
IMAGE imgPeashooterSelectorBackgroundRight; // ѡ�ǽ��泯���ҵ������ֱ���ͼƬ

IMAGE imgSunflowerSelectorBackgroundLeft; // ѡ�ǽ��泯��������տ�����ͼƬ
IMAGE imgSunflowerSelectorBackgroundRight; // ѡ�ǽ��泯���ҵ����տ�����ͼƬ

//3.��Ϸ�������Դ ͼƬ
IMAGE imgSky; // ���ͼƬ
IMAGE imgHills; // ɽ��ͼƬ
IMAGE imgPlatformLarge; //����ƽ̨ͼƬ
IMAGE imgPlatformSmall; //С��ƽ̨ͼƬ

IMAGE img1PCursor; // 1P ָʾ���ͼƬ
IMAGE img2PCursor; // 2P ָʾ���ͼƬ

//4.��Ϸ(ս��)�����ɫ�ĵ���Դ ͼ��
Atlas atlasPeashooterIdleLeft; // �����ֳ������Ĭ�϶���ͼ��
Atlas atlasPeashooterIdleRight; // �����ֳ����ҵ�Ĭ�϶���ͼ��
Atlas atlasPeashooterRunLeft; // �����ֳ�������ܲ�����ͼ��
Atlas atlasPeashooterRunRight; // �����ֳ����ҵ��ܲ�����ͼ��
Atlas atlasPeashooterAttackExLeft; // �����ֳ�����Ĺ�������ͼ��
Atlas atlasPeashooterAttackExRight; // �����ֳ����ҵĹ�������ͼ��
Atlas atlasPeashooterDieLeft; // �����ֳ��������������ͼ��
Atlas atlasPeashooterDieRight; // �����ֳ����ҵ���������ͼ��

Atlas atlasSunflowerIdleLeft; // ���տ��������Ĭ�϶���ͼ��
Atlas atlasSunflowerIdleRight; // ���տ������ҵ�Ĭ�϶���ͼ��
Atlas atlasSunflowerRunLeft; // ���տ���������ܲ�����ͼ��
Atlas atlasSunflowerRunRight; // ���տ������ҵ��ܲ�����ͼ��
Atlas atlasSunflowerAttackExLeft; // ���տ�������Ĺ�������ͼ��
Atlas atlasSunflowerAttackExRight; // ���տ������ҵĹ�������ͼ��
Atlas atlasSunflowerDieLeft; // ���տ����������������ͼ��
Atlas atlasSunflowerDieRight; // ���տ������ҵ���������ͼ��

//5.��Ϸ(ս��)������������Դ ͼ��
IMAGE imgPea; // �㶹ͼƬ

Atlas atlasPeaBreak; // �㶹���鶯��ͼ��
Atlas atlasSun; // �չ⶯��ͼ��
Atlas atlasSunExplode; // �չⱬը����ͼ��
Atlas atlasSunEx; // �����չ⶯��ͼ��
Atlas atlasSunExExplode; // �����չⱬը����ͼ��
Atlas atlasSunText; // ���ա� �ı�����ͼ��

Atlas atlasRunEffect; // ������Ч����ͼ��
Atlas atlasJumpEffect; // ��Ծ��Ч����ͼ��
Atlas atlasLandEffect; // �����Ч����ͼ��

//6.��Ϸ�����������Դ ͼ��
IMAGE img1PWinner; // 1P ��ʤ�ı�ͼƬ
IMAGE img2PWinner; // 2P ��ʤ�ı�ͼƬ
IMAGE imgWinnerBar; // ��ʤ��ұ����ı�ͼƬ

IMAGE imgAvatarPeashooter; // ������ͷ��ͼƬ
IMAGE imgAvatarSunflower; // ���տ�ͷ��ͼƬ

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