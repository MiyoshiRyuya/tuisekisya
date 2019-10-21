#include "DxLib.h"

typedef enum {
	eScene_Menu,    //���j���[���
	eScene_Item,    //�A�C�e�����
	eScene_Save,    //�Z�[�u���
	eScene_Title,   //�^�C�g��
	eScene_GemuEnd, //�Q�[���I��
} eScene;

static int Scene = eScene_Menu;    //���݂̉��(�V�[��)

//�V�[�����X�V����
void UpdateScene() {
	DrawString(0, 20, "M�L�[�Ń��j���[��ʂɂȂ�܂��B", GetColor(255, 255, 255));
	if (CheckHitKey(KEY_INPUT_M) != 0) 
	{
		Scene = eScene_Menu;
	}
}

//���j���[���
void Menu() 
{
	DrawString(0, 0, "MENU", GetColor(255, 255, 255));
}

//�A�C�e�����
void Game() 
{
	DrawString(0, 0, "�A�C�e��", GetColor(255, 255, 255));
}

//�Z�[�u���
void Save()
{
	DrawString(0, 0, "�Z�[�u", GetColor(255, 255, 255));
}


//�^�C�g���ɖ߂�
void Taitle()
{
	DrawString(0, 0, "�^�C�g���ɖ߂�", GetColor(255, 255, 255));
}


//�Q�[���I��
void GemuEnd()
{
	DrawString(0, 0, "�Q�[���I��", GetColor(255, 255, 255));
}




int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) 
	{

		switch (Scene) //���݂̃V�[���ɂ���������������
		{
		case eScene_Menu://���݂̃V�[�������j���[�Ȃ�
			Menu();//���j���[���
			break;
		case eScene_Item://���݂̃V�[�����A�C�e����ʂȂ�
			Item();//Item���
			break;
		case eScene_Save://���݂̃V�[�����Z�[�u��ʂȂ�
			Save();//Save���
			break
		case eScene_Title://���݂̃V�[�����^�C�g����ʂȂ�
			Title();//�^�C�g�����
			break;
		case eScene_GemuEnd://���݂̃V�[�����A�C�e����ʂȂ�
			GemuEnd();//�Q�[���I�����
			break;
		}
	}



		UpdateScene();//�V�[�����X�V����

	}

	DxLib_End(); // DX���C�u�����I������
	return 0;
}