#pragma once
#include "..\\JEngin_SOURCE\\JScene.h"
#include "JTile.h"

class JToolScene : public JScene
{
public:
	JToolScene();
	~JToolScene();

	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hdc) override;

	void OnEnter() override;
	void OnExit()  override;

	void Save();
	void Load();

private:
	std::vector<JTile*> mTiles;
};
LRESULT CALLBACK WndTileProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);