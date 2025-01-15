#include "JToolScene.h"
#include "JObject.h"
#include "JTile.h"
#include "JTilemapRenderer.h"
#include "JResources.h"
#include "JTexture.h"
#include "JCamera.h"
#include "JRenderer.h"
#include "JInput.h"

JToolScene::JToolScene()
{
}

JToolScene::~JToolScene()
{
}

void JToolScene::Initialize()
{
	JGameObject* camera = object::Instantiate<JGameObject>(enums::eLayerType::Particle, Vector2(808.0f, 469.5f));
	JCamera* cameraComp = camera->AddComponent<JCamera>();
	JRenderer::mainCamera = cameraComp;

	JTile* tile = object::Instantiate<JTile>(eLayerType::Tile);
	JTilemapRenderer* tmr = tile->AddComponent<JTilemapRenderer>();
	tmr->SetTexture(JResources::Find<graphics::JTexture>(L"SpringFloor"));

	JScene::Initialize();
}

void JToolScene::Update()
{
	JScene::Update();
}

void JToolScene::LateUpdate()
{

	JScene::LateUpdate();
	if (JInput::GetKeyDown(eKeyCode::LButton))
	{
		Vector2 pos = JInput::GetMousePosition();

		int idxX = pos.x / JTilemapRenderer::TileSize.x;
		int idxY = pos.y / JTilemapRenderer::TileSize.y;

		JTile* tile = object::Instantiate<JTile>(eLayerType::Tile);
		JTilemapRenderer* tmr = tile->AddComponent<JTilemapRenderer>();
		tmr->SetTexture(JResources::Find<graphics::JTexture>(L"SpringFloor"));
		tmr->SetIndex(JTilemapRenderer::SelectedIndex);

		tile->SetPosition(idxX, idxY);
	}
}

void JToolScene::Render(HDC hdc)
{
	JScene::Render(hdc);

	for (size_t i = 0; i < 70; i++)
	{
		MoveToEx(hdc, JTilemapRenderer::TileSize.x * i, 0, NULL);
		LineTo(hdc, JTilemapRenderer::TileSize.x * i, 1000);
	}

	for (size_t i = 0; i < 50; i++)
	{
		MoveToEx(hdc, 0, JTilemapRenderer::TileSize.y * i, NULL);
		LineTo(hdc, 1900, JTilemapRenderer::TileSize.y * i);
	}
}

void JToolScene::OnEnter()
{
	JScene::OnEnter();
}

void JToolScene::OnExit()
{
	JScene::OnExit();
}

void JToolScene::Save()
{
}

void JToolScene::Load()
{
}


LRESULT CALLBACK WndTileProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONDOWN:
	{
		POINT mousePos = { };
		GetCursorPos(&mousePos);
		ScreenToClient(hWnd, &mousePos);

		JMath::Vector2 mousePosition;
		mousePosition.x = mousePos.x;
		mousePosition.y = mousePos.y;

		int idxX = mousePosition.x / JTilemapRenderer::OriginTileSize.x;
		int idxY = mousePosition.y / JTilemapRenderer::OriginTileSize.y;

		JTilemapRenderer::SelectedIndex = Vector2(idxX, idxY);
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		//Rectangle(hdc, 100, 100, 200, 200);
		graphics::JTexture* texture
			= JResources::Find<graphics::JTexture>(L"SpringFloor");

		TransparentBlt(hdc
			, 0, 0
			, texture->GetWidth()
			, texture->GetHeight()
			, texture->GetHdc()
			, 0, 0
			, texture->GetWidth()
			, texture->GetHeight()
			, RGB(255, 0, 255));

		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}