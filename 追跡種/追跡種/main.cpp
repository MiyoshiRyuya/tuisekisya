#include "DxLib.h"

typedef enum {
	eScene_Menu,    //メニュー画面
	eScene_Item,    //アイテム画面
	eScene_Save,    //セーブ画面
	eScene_Title,   //タイトル
	eScene_GemuEnd, //ゲーム終了
} eScene;

static int Scene = eScene_Menu;    //現在の画面(シーン)

//シーンを更新する
void UpdateScene() {
	DrawString(0, 20, "Mキーでメニュー画面になります。", GetColor(255, 255, 255));
	if (CheckHitKey(KEY_INPUT_M) != 0) 
	{
		Scene = eScene_Menu;
	}
}

//メニュー画面
void Menu() 
{
	DrawString(0, 0, "MENU", GetColor(255, 255, 255));
}

//アイテム画面
void Game() 
{
	DrawString(0, 0, "アイテム", GetColor(255, 255, 255));
}

//セーブ画面
void Save()
{
	DrawString(0, 0, "セーブ", GetColor(255, 255, 255));
}


//タイトルに戻る
void Taitle()
{
	DrawString(0, 0, "タイトルに戻る", GetColor(255, 255, 255));
}


//ゲーム終了
void GemuEnd()
{
	DrawString(0, 0, "ゲーム終了", GetColor(255, 255, 255));
}




int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //ウィンドウモード変更と初期化と裏画面設定

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) 
	{

		switch (Scene) //現在のシーンにあった処理をする
		{
		case eScene_Menu://現在のシーンがメニューなら
			Menu();//メニュー画面
			break;
		case eScene_Item://現在のシーンがアイテム画面なら
			Item();//Item画面
			break;
		case eScene_Save://現在のシーンがセーブ画面なら
			Save();//Save画面
			break
		case eScene_Title://現在のシーンがタイトル画面なら
			Title();//タイトル画面
			break;
		case eScene_GemuEnd://現在のシーンがアイテム画面なら
			GemuEnd();//ゲーム終了画面
			break;
		}
	}



		UpdateScene();//シーンを更新する

	}

	DxLib_End(); // DXライブラリ終了処理
	return 0;
}