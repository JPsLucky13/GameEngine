#include "Sprite.h"

namespace Engine {

	Sprite::Sprite(GameObject * object, const char * i_pFilename)
	{
		m_pObject = object;
		sprite = m_Renderer->CreateSprite(i_pFilename);

	}

	Sprite::~Sprite()
	{
	}





}

